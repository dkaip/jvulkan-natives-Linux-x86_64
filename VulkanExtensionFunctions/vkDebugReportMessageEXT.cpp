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
 * vkDebugReportMessageEXT.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkDebugReportMessageEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkInstance;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugReportObjectTypeEXT;JJILjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkDebugReportMessageEXT
  (JNIEnv *env,
		  jobject,
		  jobject jVkInstance,
		  jobject jFlags,
		  jobject jVkDebugReportObjectTypeEXTObject,
		  jlong object,
		  jlong location,
		  jint messageCode,
		  jstring jLayerPrefix,
		  jstring jMessage)
{
	VkInstance_T *instanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkInstance handle");
        return;
    }

    VkDebugReportFlagsEXT flags = (VkDebugReportFlagsEXT)jvulkan::getEnumSetValue(
            env,
			jFlags,
            "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugReportFlagBitsEXT");

    jclass vkDebugReportObjectTypeEXTEnumClass = env->GetObjectClass(jVkDebugReportObjectTypeEXTObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class for jVkDebugReportObjectTypeEXTObject");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkDebugReportObjectTypeEXTEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for valueOf");
        return;
    }

    VkDebugReportObjectTypeEXT objectTypeEnumValue = (VkDebugReportObjectTypeEXT)env->CallIntMethod(jVkDebugReportObjectTypeEXTObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod");
        return;
    }

    const char *layerPrefixString = env->GetStringUTFChars(jLayerPrefix, 0);
    const char *messageString = env->GetStringUTFChars(jMessage, 0);

    vkDebugReportMessageEXT(
    		instanceHandle,
			flags,
			objectTypeEnumValue,
			object,
			location,
			messageCode,
			layerPrefixString,
			messageString);

    env->ReleaseStringUTFChars(jLayerPrefix, layerPrefixString);
    env->ReleaseStringUTFChars(jMessage, messageString);

}
