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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdCopyAccelerationStructureNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkAccelerationStructureKHR;Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkCopyAccelerationStructureModeKHR;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdCopyAccelerationStructureNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jCopyDestinationObject, jobject jCopySourceObject, jobject jModeObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkAccelerationStructureKHR_T *destinationHandle = (VkAccelerationStructureKHR_T *)jvulkan::getHandleValue(env, jCopyDestinationObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jCopyDestinationObject handle");
        return;
    }

    VkAccelerationStructureKHR_T *sourceHandle = (VkAccelerationStructureKHR_T *)jvulkan::getHandleValue(env, jCopySourceObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jCopySourceObject handle");
        return;
    }

    jclass vkCopyAccelerationStructureModeKHREnumClass = env->GetObjectClass(jModeObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jModeObject.");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkCopyAccelerationStructureModeKHREnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkCopyAccelerationStructureModeKHR vkCopyAccelerationStructureModeKHR = (VkCopyAccelerationStructureModeKHR)env->CallIntMethod(jModeObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }


    vkCmdCopyAccelerationStructureNV(
    		commandBufferHandle,
			destinationHandle,
			sourceHandle,
			vkCopyAccelerationStructureModeKHR);
}
