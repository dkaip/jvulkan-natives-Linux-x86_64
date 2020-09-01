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
 * vkGetPerformanceParameterINTEL.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPerformanceParameterINTEL
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPerformanceParameterTypeINTEL;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkPerformanceValueINTEL;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPerformanceParameterINTEL
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPerformanceParameterTypeINTEL, jobject jVkPerformanceValueINTEL)
{
	VkDevice_T *deviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "getHandleValue failed for jVkDevice");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass vkPerformanceParameterTypeINTELEnumClass = env->GetObjectClass(jVkPerformanceParameterTypeINTEL);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jVkPerformanceParameterTypeINTEL.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPerformanceParameterTypeINTEL parameter = (VkPerformanceParameterTypeINTEL)env->CallIntMethod(jVkPerformanceParameterTypeINTEL, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPerformanceValueINTEL vkPerformanceValueINTEL = {};

    VkResult result = vkGetPerformanceParameterINTEL(
    		deviceHandle,
			parameter,
			&vkPerformanceValueINTEL);

    jclass VkPerformanceValueINTELClass = env->GetObjectClass(jVkPerformanceValueINTEL);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jVkPerformanceValueINTEL.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = nullptr;

    if (vkPerformanceValueINTEL.type == VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL)
    {
        methodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "setIntData", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for setIntData.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        env->CallVoidMethod(jVkPerformanceValueINTEL, methodId, (jint)vkPerformanceValueINTEL.data.value32);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }
    else if (vkPerformanceValueINTEL.type == VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL)
    {
        methodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "setLongData", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for setLongData.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        env->CallVoidMethod(jVkPerformanceValueINTEL, methodId, (jlong)vkPerformanceValueINTEL.data.value64);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }
    else if (vkPerformanceValueINTEL.type == VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL)
    {
        methodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "setFloatData", "(F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for setFloatData.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        env->CallVoidMethod(jVkPerformanceValueINTEL, methodId, vkPerformanceValueINTEL.data.valueFloat);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }
    else if (vkPerformanceValueINTEL.type == VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL)
    {
        methodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "setBooleanData", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for setBooleanData.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        env->CallVoidMethod(jVkPerformanceValueINTEL, methodId, (jboolean)vkPerformanceValueINTEL.data.valueBool);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallVoidMethod.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }
    else if (vkPerformanceValueINTEL.type == VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL)
    {
        methodId = env->GetMethodID(vkPerformanceParameterTypeINTELEnumClass, "setStringData", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for setStringData.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

		jstring stringData = env->NewStringUTF(vkPerformanceValueINTEL.data.valueString);

		env->CallVoidMethod(jVkPerformanceValueINTEL, methodId, stringData);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed trying execute to get methodId of stringData");
			return nullptr;
		}

		env->DeleteLocalRef(stringData);
    }
    else
    {
    	LOGERROR(env, "Invalid type of %d in type field.", vkPerformanceValueINTEL.type);
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return jvulkan::createVkResult(env, result);
}
