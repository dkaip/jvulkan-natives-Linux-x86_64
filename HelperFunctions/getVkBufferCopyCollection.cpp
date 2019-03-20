#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkBufferCopyCollection(
            JNIEnv *env,
            const jobject jVkBufferCopyCollectionObject,
            VkBufferCopy **vkBufferCopies,
            int *numberOfVkBufferCopies,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferCopyCollectionClass = env->GetObjectClass(jVkBufferCopyCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferCopyCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferCopyCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBufferCopies = numberOfElements;
        *vkBufferCopies = (VkBufferCopy *)calloc(numberOfElements, sizeof(VkBufferCopy));
        memoryToFree->push_back(*vkBufferCopies);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferCopyCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferCopyCollectionObject, iteratorMethodId);
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

        jclass vkBufferCopyClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkBufferCopy");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID srcOffsetMethodId = env->GetMethodID(vkBufferCopyClass, "getSrcOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID dstOffsetMethodId = env->GetMethodID(vkBufferCopyClass, "getDstOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID sizeMethodId = env->GetMethodID(vkBufferCopyClass, "getSize", "()J");
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

            jobject jVkBufferCopyObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jlong srcOffSet = env->CallLongMethod(jVkBufferCopyObject, srcOffsetMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jlong dstOffSet = env->CallLongMethod(jVkBufferCopyObject, dstOffsetMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jlong size = env->CallLongMethod(jVkBufferCopyObject, sizeMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }


            (*vkBufferCopies)[i].srcOffset = srcOffSet;
            (*vkBufferCopies)[i].dstOffset = dstOffSet;
            (*vkBufferCopies)[i].size      = size;

            i++;
        } while(true);
    }
}
