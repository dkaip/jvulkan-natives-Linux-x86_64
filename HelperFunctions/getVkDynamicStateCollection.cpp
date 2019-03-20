#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDynamicStateCollection(
            JNIEnv *env,
            const jobject jVkDynamicStateCollectionObject,
            VkDynamicState **vkDynamicStates,
            int *numberOfVkDynamicStates,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDynamicStateCollectionClass = env->GetObjectClass(jVkDynamicStateCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDynamicStateCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDynamicStateCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDynamicStates = numberOfElements;
        *vkDynamicStates = (VkDynamicState *)calloc(numberOfElements, sizeof(VkDynamicState));
        memoryToFree->push_back(*vkDynamicStates);

        jmethodID iteratorMethodId = env->GetMethodID(vkDynamicStateCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkDynamicStateCollectionClass, iteratorMethodId);
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

        jclass vkDynamicStateClass;
        jmethodID valueOfMethodId;
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

            jobject jVkDynamicStateObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (i == 0)
            {
                vkDynamicStateClass = env->GetObjectClass(jVkDynamicStateObject);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                valueOfMethodId = env->GetMethodID(vkDynamicStateClass, "valueOf", "()I");
                if (env->ExceptionOccurred())
                {
                    return;
                }
            }

            (*vkDynamicStates)[i] = (VkDynamicState)env->CallIntMethod(jVkDynamicStateObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
