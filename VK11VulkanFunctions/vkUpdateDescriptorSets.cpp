#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkUpdateDescriptorSets
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Ljava/util/Collection;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkUpdateDescriptorSets
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkWriteDescriptorSetCollectionObject, jobject jVkCopyDescriptorSetCollectionObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkWriteDescriptorSets = 0;
    VkWriteDescriptorSet *vkWriteDescriptorSets = nullptr;

    if (jVkWriteDescriptorSetCollectionObject != nullptr)
    {
        hwjvi::getVkWriteDescriptorSetCollection(
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
        hwjvi::getVkCopyDescriptorSetCollection(
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

    hwjvi::freeMemory(&memoryToFree);
}

