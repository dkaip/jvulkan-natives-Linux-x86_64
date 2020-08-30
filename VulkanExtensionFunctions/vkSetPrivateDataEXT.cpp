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
 * vkSetPrivateDataEXT.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkSetPrivateDataEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType;JLcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkPrivateDataSlotEXT;J)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkSetPrivateDataEXT
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkObjectTypeObject, jlong jObjectHandle, jobject jVkPrivateDataSlotEXTObject, jlong jData)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	jclass vkObjectTypeEnumClass = env->GetObjectClass(jVkObjectTypeObject);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class for jVkObjectTypeObject");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	jmethodID valueOfMethodId = env->GetMethodID(vkObjectTypeEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id for valueOf.");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	VkObjectType vkObjectTypetEnumValue = (VkObjectType)env->CallIntMethod(jVkObjectTypeObject, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
	}

	uint64_t objectHandle = (uint64_t)jObjectHandle;

	VkPrivateDataSlotEXT_T *privateDataSlotHandle = (VkPrivateDataSlotEXT_T *)jvulkan::getHandleValue(env, jVkPrivateDataSlotEXTObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkPrivateDataSlotEXTObject handle.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

	uint64_t data = (uint64_t)jData;

	VkResult result = vkSetPrivateDataEXT(
			deviceHandle,
			vkObjectTypetEnumValue,
			objectHandle,
			privateDataSlotHandle,
			data);

    return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
}
