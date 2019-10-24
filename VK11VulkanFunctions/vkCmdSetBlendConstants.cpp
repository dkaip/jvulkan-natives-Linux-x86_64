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
 * vkCmdSetBlendConstants.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdSetBlendConstants
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkCommandBuffer;[F)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCmdSetBlendConstants
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jfloatArray jBlendConstants)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    float *blendConstantsArray = nullptr;
    jsize arrayLength = 0;
	arrayLength = env->GetArrayLength(jBlendConstants);

	blendConstantsArray = (float *)calloc(arrayLength, sizeof(float));

	env->GetFloatArrayRegion(jBlendConstants, 0, arrayLength, blendConstantsArray);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling GetFloatArrayRegion");
		return;
	}

	vkCmdSetBlendConstants(
			commandBufferHandle,
			blendConstantsArray);

	free(blendConstantsArray);
}
