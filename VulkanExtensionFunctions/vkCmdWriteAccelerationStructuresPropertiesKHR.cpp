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
 * vkCmdWriteAccelerationStructuresPropertiesKHR.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdWriteAccelerationStructuresPropertiesKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Ljava/util/Collection;Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkQueryType;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueryPool;I)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdWriteAccelerationStructuresPropertiesKHR
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkAccelerationStructureKHRCollectionObject, jobject jVkQueryTypeObject, jobject jVkQueryPoolObject, jint jQueryPoolIndex)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkAccelerationStructureKHRs = 0;
    VkAccelerationStructureKHR *vkAccelerationStructureKHRs = nullptr;

    jvulkan::getVkAccelerationStructureKHRCollection(
            env,
			jVkAccelerationStructureKHRCollectionObject,
            &vkAccelerationStructureKHRs,
            &numberOfVkAccelerationStructureKHRs,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkAccelerationStructureKHRCollection.");
        return;
    }

    jclass vkQueryTypeEnumClass = env->GetObjectClass(jVkQueryTypeObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jVkQueryTypeObject.");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkQueryTypeEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkQueryType vkQueryType = (VkQueryType)env->CallIntMethod(jVkQueryTypeObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    VkQueryPool_T *queryPoolHandle = (VkQueryPool_T *)jvulkan::getHandleValue(env, jVkQueryPoolObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve jVkQueryPoolObject handle");
        return;
    }

	uint32_t firstQuery = (uint32_t)jQueryPoolIndex;

	vkCmdWriteAccelerationStructuresPropertiesKHR(
			commandBufferHandle,
			numberOfVkAccelerationStructureKHRs,
			vkAccelerationStructureKHRs,
			vkQueryType,
			queryPoolHandle,
			firstQuery);

    jvulkan::freeMemory(&memoryToFree);
}
