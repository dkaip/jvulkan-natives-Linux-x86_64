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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdBindShadingRateImageNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkImageView;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkImageLayout;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdBindShadingRateImageNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkImageView, jobject jVkImageLayoutObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkImageView_T *imageViewHandle = (VkImageView_T *)jvulkan::getHandleValue(env, jVkImageView);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkImageView handle");
        return;
    }

    jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jVkImageLayoutObject.");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkImageLayout imageLayout = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    vkCmdBindShadingRateImageNV(
    		commandBufferHandle,
			imageViewHandle,
			imageLayout);
}
