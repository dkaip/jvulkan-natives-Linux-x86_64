#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkImageViewCollection(
            JNIEnv *env,
            const jobject jVkImageViewCollectionObject,
            VkImageView **vkImageViews,
            int *numberOfVkImageViews,
            std::vector<void *> *memoryToFree)
    {
        if (jVkImageViewCollectionObject == nullptr)
        {
            return;
        }

        jclass vkjVkImageViewCollectionClass = env->GetObjectClass(jVkImageViewCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkjVkImageViewCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkImageViewCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkImageViews = numberOfElements;
        *vkImageViews = (VkImageView *)calloc(numberOfElements, sizeof(VkImageView));
        memoryToFree->push_back(*vkImageViews);

        jmethodID iteratorMethodId = env->GetMethodID(vkjVkImageViewCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkImageViewCollectionObject, iteratorMethodId);
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

            jobject jVkImageViewObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkImageView_T *imageViewHandle = (VkImageView_T *)hwjvi::getHandleValue(env, jVkImageViewObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*vkImageViews)[i] = imageViewHandle;

            i++;
        } while(true);
    }
}
