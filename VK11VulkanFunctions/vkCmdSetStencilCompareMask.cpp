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
/*
 * vkCmdSetStencilCompareMask.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdSetStencilCompareMask
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;Ljava/util/EnumSet;I)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdSetStencilCompareMask
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkStencilFaceFlags, jint compareMask)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkStencilFaceFlags faceMask = (VkStencilFaceFlags)jvulkan::getEnumSetValue(
            env,
			jVkStencilFaceFlags,
            "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkStencilFaceFlagBits");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return;
    }

    vkCmdSetStencilCompareMask(
    		commandBufferHandle,
			faceMask,
			compareMask);
}
