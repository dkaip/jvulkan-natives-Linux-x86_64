#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkSemaphoreCollection(
            JNIEnv *env,
            const jobject jVkSemaphoreCollectionObject,
            VkSemaphore **vkSemaphores,
            int *numberOfVkSemaphores,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSemaphoreCollectionClass = env->GetObjectClass(jVkSemaphoreCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSemaphoreCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSemaphoreCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSemaphores = numberOfElements;
        *vkSemaphores = (VkSemaphore *)calloc(numberOfElements, sizeof(VkSemaphore *));
        memoryToFree->push_back(*vkSemaphores);

        jmethodID iteratorMethodId = env->GetMethodID(vkSemaphoreCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSemaphoreCollectionObject, iteratorMethodId);
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

            jobject jVkSemaphoreHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkSemaphore_T *vkSemaphoreHandle = (VkSemaphore_T *)hwjvi::getHandleValue(env, jVkSemaphoreHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkSemaphores)[i] = vkSemaphoreHandle;

            i++;
        } while(true);
    }
}
