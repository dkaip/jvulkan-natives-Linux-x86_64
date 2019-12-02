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
#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkAllocateDescriptorSets
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VkDescriptorSetAllocateInfo;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkAllocateDescriptorSets
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDescriptorSetAllocateInfo, jobject jVkDescriptorSetCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDevice handle");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkDescriptorSetAllocateInfo vkDescriptorSetAllocateInfo = {};
    jvulkan::getVkDescriptorSetAllocateInfo(
            env,
            jVkDescriptorSetAllocateInfo,
            &vkDescriptorSetAllocateInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getVkDescriptorSetAllocateInfo");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<VkDescriptorSet> descriptorSets(vkDescriptorSetAllocateInfo.descriptorSetCount);

    VkResult result = vkAllocateDescriptorSets(
            logicalDeviceHandle,
            &vkDescriptorSetAllocateInfo,
            descriptorSets.data());

    jvulkan::freeMemory(&memoryToFree);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "Error calling vkAllocateDescriptorSets. Error code is:%d", result);
    	return jvulkan::createVkResult(env, result);
    }


    jclass vkDescriptorSetCollectionClass = env->GetObjectClass(jVkDescriptorSetCollection);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find class for jVkDescriptorSetCollection");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(vkDescriptorSetCollectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id add.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for (const auto& descriptorSet : descriptorSets)
    {
    	jobject jDescriptorSetHandle = jvulkan::createVulkanHandle(
    			env,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDescriptorSet",
				descriptorSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        bool addResult = env->CallBooleanMethod(jVkDescriptorSetCollection, addMethodId, jDescriptorSetHandle);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        if (addResult == false)
        {
        	LOGERROR(env, "%s", "Error jDescriptorSetHandle element did not get added to jVkDescriptorSetCollection.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    return jvulkan::createVkResult(env, result);
}
