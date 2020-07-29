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
/*
 * vkCmdNextSubpass.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdNextSubpass
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassContents;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdNextSubpass
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkSubpassContentsEnum)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

	jclass vkSubpassContentsEnumClass = env->GetObjectClass(jVkSubpassContentsEnum);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class for jVkSubpassContentsEnum");
		return;
	}


	jmethodID valueOfMethodId = env->GetMethodID(vkSubpassContentsEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id valueOf");
		return;
	}

	VkSubpassContents vkSubpassContentsEnumValue = (VkSubpassContents)env->CallIntMethod(jVkSubpassContentsEnum, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

	vkCmdNextSubpass(
			commandBufferHandle,
			vkSubpassContentsEnumValue);
}
