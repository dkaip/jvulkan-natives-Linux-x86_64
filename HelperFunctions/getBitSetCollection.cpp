#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getBitSetCollection(
            JNIEnv *env,
            const jobject jBitSetCollectionObject,
            uint32_t **outputBitMasks,
            int *numberOfOutputBitMasks,
            std::vector<void *> *memoryToFree)
    {
        if (jBitSetCollectionObject == nullptr)
        {
            return;
        }

        jclass bitSetCollectionClass = env->GetObjectClass(jBitSetCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(bitSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jBitSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfOutputBitMasks = numberOfElements;
        *outputBitMasks = (uint32_t *)calloc(numberOfElements, sizeof(uint32_t));
        memoryToFree->push_back(*outputBitMasks);

        jmethodID iteratorMethodId = env->GetMethodID(bitSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jBitSetCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass bitSetClass = env->FindClass("Ljava/util/BitSet");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID lengthMethodId = env->GetMethodID(bitSetClass, "length", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID getMethodId = env->GetMethodID(bitSetClass, "get", "(I)Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jBitSetObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jint jBitSetLength = env->CallIntMethod(jBitSetObject, lengthMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            uint32_t bitSetLength = (uint32_t)std::min(jBitSetLength, 32);

            (*outputBitMasks)[i] = 0;

            for (uint32_t i = 0; i < bitSetLength; i++)
            {
                jboolean isSet = env->CallBooleanMethod(jBitSetObject, getMethodId, i);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                if (isSet == true)
                {
                    (*outputBitMasks)[i] |= 1 << i;
                }
            }

            i++;
        } while(true);
    }
}
