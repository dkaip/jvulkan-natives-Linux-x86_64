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
 * vkCmdSetStencilOpEXT.cpp
 *
 *  Created on: Aug 29, 2020
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdSetStencilOpEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkStencilOp;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkStencilOp;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkStencilOp;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkCompareOp;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdSetStencilOpEXT
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkStencilFaceFlags, jobject jFailOpObject, jobject jPassOpObject, jobject jDepthFailOpObject, jobject jCompareOpObject)
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
            "com/CIMthetics/jvulkan/VulkanCore/Enums/VkStencilFaceFlagBits");
    if (env->ExceptionOccurred())
    {
  	  LOGERROR(env, "%s", "Error calling getEnumSetValue");
        return;
    }

    jclass vkStencilOpEnumClass = env->GetObjectClass(jFailOpObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jFailOpObject.");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkStencilOp failOp = (VkStencilOp)env->CallIntMethod(jFailOpObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    VkStencilOp passOp = (VkStencilOp)env->CallIntMethod(jPassOpObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    VkStencilOp depthFailOp = (VkStencilOp)env->CallIntMethod(jDepthFailOpObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    jclass vkCompareOpEnumClass = env->GetObjectClass(jCompareOpObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jCompareOpObject.");
        return;
    }

    valueOfMethodId = env->GetMethodID(vkCompareOpEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkCompareOp compareOp = (VkCompareOp)env->CallIntMethod(jCompareOpObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    vkCmdSetStencilOpEXT(
    		commandBufferHandle,
			faceMask,
			failOp,
			passOp,
			depthFailOp,
			compareOp);
}
