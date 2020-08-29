/*
 * Copyright 2020 Douglas Kaip
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
 * vkCmdSetCullModeEXT.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdSetCullModeEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Ljava/util/EnumSet;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdSetCullModeEXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkCullModeFlags)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkCullModeFlags flags = (VkCullModeFlags)jvulkan::getEnumSetValue(
            env,
			jVkCullModeFlags,
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkCullModeFlagBits");
    if (env->ExceptionOccurred())
    {
  	  LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return;
    }

    vkCmdSetCullModeEXT(commandBufferHandle, flags);
}
