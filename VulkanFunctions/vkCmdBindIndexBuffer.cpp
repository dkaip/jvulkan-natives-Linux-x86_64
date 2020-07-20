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
#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdBindIndexBuffer
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;JLcom/CIMthetics/jvulkan/VulkanCore/Enums/VkIndexType;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBindIndexBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkBuffer, jlong jOffset, jobject jVkIndexTypeObject)
{
    VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *vkBufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass indexTypeObjectEnumClass = env->GetObjectClass(jVkIndexTypeObject);

    jmethodID valueOfMethodId = env->GetMethodID(indexTypeObjectEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkIndexType indexTypeEnumValue = (VkIndexType)env->CallIntMethod(jVkIndexTypeObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdBindIndexBuffer(
            vkCommandBufferHandle,
            vkBufferHandle,
            jOffset,
            indexTypeEnumValue);
}
