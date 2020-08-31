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
 * Method:    vkCmdSetCoarseSampleOrderNV
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkCoarseSampleOrderTypeNV;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdSetCoarseSampleOrderNV
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkCoarseSampleOrderTypeNVObject, jobject jVkCoarseSampleOrderCustomNVCollectionObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    jclass vkCoarseSampleOrderTypeNVClass = env->GetObjectClass(jVkCoarseSampleOrderTypeNVObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetObjectClass for jVkCoarseSampleOrderTypeNVObject.");
        return;
    }

    jmethodID valueOfMethodId = env->GetMethodID(vkCoarseSampleOrderTypeNVClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    VkCoarseSampleOrderTypeNV vkCoarseSampleOrderTypeNV = (VkCoarseSampleOrderTypeNV)env->CallIntMethod(jVkCoarseSampleOrderTypeNVObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkCoarseSampleOrderCustomNVs = 0;
    VkCoarseSampleOrderCustomNV *vkCoarseSampleOrderCustomNVs = nullptr;

    jvulkan::getVkCoarseSampleOrderCustomNVCollection(
            env,
			jVkCoarseSampleOrderCustomNVCollectionObject,
            &vkCoarseSampleOrderCustomNVs,
            &numberOfVkCoarseSampleOrderCustomNVs,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkCoarseSampleOrderCustomNVCollection.");
        return;
    }

    vkCmdSetCoarseSampleOrderNV(
    		commandBufferHandle,
			vkCoarseSampleOrderTypeNV,
			numberOfVkCoarseSampleOrderCustomNVs,
			vkCoarseSampleOrderCustomNVs);

    jvulkan::freeMemory(&memoryToFree);
}
