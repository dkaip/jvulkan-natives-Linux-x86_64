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
 * vkGetPrivateDataEXT.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPrivateDataEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkObjectType;JLcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkPrivateDataSlotEXT;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/LongReturnValue;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPrivateDataEXT
  (JNIEnv *env , jobject, jobject jVkDevice, jobject jVkObjectTypeObject, jlong jObjectHandle, jobject jVkPrivateDataSlotEXTObject, jobject jDataReturnValueObject)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle.");
        return;
    }

	jclass vkObjectTypeEnumClass = env->GetObjectClass(jVkObjectTypeObject);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find class for jVkObjectTypeObject");
		return;
	}

	jmethodID valueOfMethodId = env->GetMethodID(vkObjectTypeEnumClass, "valueOf", "()I");
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Could not find method id for valueOf.");
		return;
	}

	VkObjectType vkObjectTypetEnumValue = (VkObjectType)env->CallIntMethod(jVkObjectTypeObject, valueOfMethodId);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling CallIntMethod");
		return;
	}

	uint64_t objectHandle = (uint64_t)jObjectHandle;

	VkPrivateDataSlotEXT_T *privateDataSlotHandle = (VkPrivateDataSlotEXT_T *)jvulkan::getHandleValue(env, jVkPrivateDataSlotEXTObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkPrivateDataSlotEXTObject handle.");
        return;
    }

    uint64_t data = 0;
    vkGetPrivateDataEXT(
    		deviceHandle,
			vkObjectTypetEnumValue,
			objectHandle,
			privateDataSlotHandle,
			&data);

    jvulkan::setLongReturnValue(env, jDataReturnValueObject, data);
}
