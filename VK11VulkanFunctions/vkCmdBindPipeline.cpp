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

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindPipeline
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineBindPoint;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPipeline;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBindPipeline
  (JNIEnv *env , jobject, jobject jVkCommandBuffer, jobject jVkPipelineBindPoint, jobject jVkPipeline)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkPipelineBindPointEnumClass = env->GetObjectClass(jVkPipelineBindPoint);

    jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    enum VkPipelineBindPoint vkPipelineBindPointEnumValue = (enum VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPoint, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkPipeline_T *pipelineHandle = (VkPipeline_T *)hwjvi::getHandleValue(env, jVkPipeline);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdBindPipeline(commandBufferHandle, vkPipelineBindPointEnumValue, pipelineHandle);
}

