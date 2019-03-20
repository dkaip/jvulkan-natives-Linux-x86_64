#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkRect2DCollection(
            JNIEnv *env,
            const jobject jVkRect2DCollectionObject,
            VkRect2D **vkRect2Ds,
            int *numberOfVkRect2Ds,
            std::vector<void *> *memoryToFree)
    {
        if (jVkRect2DCollectionObject == nullptr)
        {
            return;
        }

        jclass vkRect2DCollectionClass = env->GetObjectClass(jVkRect2DCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkRect2DCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkRect2DCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkRect2Ds = numberOfElements;
        *vkRect2Ds = (VkRect2D *)calloc(numberOfElements, sizeof(VkRect2D));
        memoryToFree->push_back(*vkRect2Ds);

        jmethodID iteratorMethodId = env->GetMethodID(vkRect2DCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkRect2DCollectionObject, iteratorMethodId);
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

            jobject jVkRect2DsObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkRect2D(
                    env,
                    jVkRect2DsObject,
                    &(*vkRect2Ds)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }
}
