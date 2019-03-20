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
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkUpdateDescriptorSets
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDevice;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkUpdateDescriptorSets
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkWriteDescriptorSetCollectionObject, jobject jVkCopyDescriptorSetCollectionObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkWriteDescriptorSets = 0;
    VkWriteDescriptorSet *vkWriteDescriptorSets = nullptr;

    if (jVkWriteDescriptorSetCollectionObject != nullptr)
    {
        jvulkan::getVkWriteDescriptorSetCollection(
                env,
                jVkWriteDescriptorSetCollectionObject,
                &vkWriteDescriptorSets,
                &numberOfVkWriteDescriptorSets,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    int numberOfVkCopyDescriptorSets = 0;
    VkCopyDescriptorSet *vkCopyDescriptorSets = nullptr;

    if (jVkCopyDescriptorSetCollectionObject != nullptr)
    {
        jvulkan::getVkCopyDescriptorSetCollection(
                env,
                jVkCopyDescriptorSetCollectionObject,
                &vkCopyDescriptorSets,
                &numberOfVkCopyDescriptorSets,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkUpdateDescriptorSets(
            logicalDeviceHandle,
            numberOfVkWriteDescriptorSets,
            vkWriteDescriptorSets,
            numberOfVkCopyDescriptorSets,
            vkCopyDescriptorSets);

    jvulkan::freeMemory(&memoryToFree);
}

