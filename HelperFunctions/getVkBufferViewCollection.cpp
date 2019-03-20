#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkBufferViewCollection(
            JNIEnv *env,
            const jobject jVkBufferViewCollectionObject,
            VkBufferView **vkBufferViews,
            int *numberOfVkBufferViews,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferViewCollectionClass = env->GetObjectClass(jVkBufferViewCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferViewCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferViewCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBufferViews = numberOfElements;
        *vkBufferViews = (VkBufferView *)calloc(numberOfElements, sizeof(VkBufferView *));
        memoryToFree->push_back(*vkBufferViews);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferViewCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferViewCollectionObject, iteratorMethodId);
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

            jobject jVkBufferViewHandleObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkBufferView_T *vkBufferViewrHandle = (VkBufferView_T *)hwjvi::getHandleValue(env, jVkBufferViewHandleObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkBufferViews)[i] = vkBufferViewrHandle;

            i++;
        } while(true);
    }
}
