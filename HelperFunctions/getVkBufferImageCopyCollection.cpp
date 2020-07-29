/*
 * Copyright 2019-2020 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferImageCopy(
            JNIEnv *env,
            const jobject jVkBufferImageCopyObject,
            VkBufferImageCopy *vkBufferImageCopy,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferImageCopyClass = env->GetObjectClass(jVkBufferImageCopyObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkBufferImageCopyClass, "getBufferOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong bufferOffset = env->CallLongMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferImageCopyClass, "getBufferRowLength", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint bufferRowLength = env->CallIntMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferImageCopyClass, "getBufferImageHeight", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint bufferImageHeight = env->CallIntMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferImageCopyClass, "getImageSubresource", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkImageSubresourceLayers;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageSubresourceLayersObject = env->CallObjectMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkImageSubresourceLayers(
                env,
                jVkImageSubresourceLayersObject,
                &(vkBufferImageCopy->imageSubresource),
                memoryToFree);



        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferImageCopyClass, "getImageOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkOffset3D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkOffset3DObject = env->CallObjectMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkOffset3D(
                env,
                jVkOffset3DObject,
                &(vkBufferImageCopy->imageOffset),
                memoryToFree);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferImageCopyClass, "getImageExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkExtent3DObject = env->CallObjectMethod(jVkBufferImageCopyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        getVkExtent3D(
                env,
                jVkExtent3DObject,
                &(vkBufferImageCopy->imageExtent),
                memoryToFree);

        vkBufferImageCopy->bufferOffset = bufferOffset;
        vkBufferImageCopy->bufferRowLength = bufferRowLength;
        vkBufferImageCopy->bufferImageHeight = bufferImageHeight;
    }

    void getVkBufferImageCopyCollection(
            JNIEnv *env,
            const jobject jVkBufferImageCopyCollectionObject,
            VkBufferImageCopy **vkBufferImageCopies,
            int *numberOfVkBufferImageCopies,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferImageCopyCollectionClass = env->GetObjectClass(jVkBufferImageCopyCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkBufferImageCopyCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkBufferImageCopyCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkBufferImageCopies = numberOfElements;
        *vkBufferImageCopies = (VkBufferImageCopy *)calloc(numberOfElements, sizeof(VkBufferImageCopy));
        memoryToFree->push_back(*vkBufferImageCopies);

        jmethodID iteratorMethodId = env->GetMethodID(vkBufferImageCopyCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkBufferImageCopyCollectionObject, iteratorMethodId);
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

            jobject jVkBufferImageCopyObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkBufferImageCopy(
                    env,
                    jVkBufferImageCopyObject,
                    &((*vkBufferImageCopies)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
