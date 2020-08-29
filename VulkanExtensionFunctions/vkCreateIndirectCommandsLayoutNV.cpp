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
 * vkCreateIndirectCommandsLayoutNV.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateIndirectCommandsLayoutNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkIndirectCommandsLayoutCreateInfoNV;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkIndirectCommandsLayoutNV;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateIndirectCommandsLayoutNV
  (JNIEnv *env, jobject, jobject, jobject, jobject, jobject)
{
	LOGERROR(env, "%s", "Not implemented yet.");
    return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
}
