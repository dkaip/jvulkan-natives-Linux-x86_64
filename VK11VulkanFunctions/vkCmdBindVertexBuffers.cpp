/*
 * Copyright 2019 Douglas Kaip
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
using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindVertexBuffers
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;ILjava/util/Collection;[J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdBindVertexBuffers
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint jFirstBinding, jobject jVkBufferCollectionObject, jlongArray jOffsetsArray)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    jclass collectionClass = env->GetObjectClass(jVkBufferCollectionObject);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find class for jVkBufferCollectionObject");
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for iterator.");
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jVkBufferCollectionObject, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling CallObjectMethod");
        return;
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find class for iteratorObject");
        return;
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for hasNext.");
        return;
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for next.");
        return;
    }

    jmethodID methodId = env->GetMethodID(collectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Could not find method id for size.");
        return;
    }

    jsize collectionSize = env->CallIntMethod(jVkBufferCollectionObject, methodId);
    if (env->ExceptionOccurred())
    {
		LOGERROR(env, "%s", "Error calling CallIntMethod");
        return;
    }

    int bindingCount = collectionSize;
    if (collectionSize == 0)
    {
		LOGWARN(env, "%s", "collectionSize is zero.");
        return;
    }

    VkBuffer_T  **arrayOfPointers = (VkBuffer_T **)calloc(collectionSize, sizeof(VkBuffer_T *));
    if (*arrayOfPointers == nullptr)
    {
		LOGERROR(env, "Could not allocate %d bytes of memory for arrayOfPointers.", collectionSize * sizeof(VkBuffer_T *));
        return;
    }

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject jVkFenceObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallObjectMethod");
            break;
        }

        VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkFenceObject);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling getHandleValue");
    		return;
        }

        arrayOfPointers[i++] = bufferHandle;

    } while (i < collectionSize);

    long *offsetsArray = nullptr;
    jsize arrayLength = 0;
    if (jOffsetsArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jOffsetsArray);

        offsetsArray = (long *)calloc(arrayLength, sizeof(long));
        if (offsetsArray == nullptr)
        {
    		LOGERROR(env, "Could not allocate %d bytes of memory for arrayOfPointers.", arrayLength * sizeof(long));
            return;
        }

        env->GetLongArrayRegion(jOffsetsArray, 0, arrayLength, offsetsArray);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
            return;
        }
    }

    vkCmdBindVertexBuffers(
            commandBufferHandle,
            jFirstBinding,
            bindingCount,
            (VkBuffer_T * const *)arrayOfPointers,
            (unsigned long int *)offsetsArray);

    free(arrayOfPointers);
    free(offsetsArray);
}

