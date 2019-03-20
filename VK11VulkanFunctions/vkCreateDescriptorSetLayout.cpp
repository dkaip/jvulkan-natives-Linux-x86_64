#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateDescriptorSetLayout
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkDescriptorSetLayoutCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDescriptorSetLayout;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateDescriptorSetLayout
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDescriptorSetLayoutCreateInfo, jobject jAlternateAllocator, jobject jVkDescriptorSetLayout)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    std::vector<void *> memoryToFree(5);
    VkDescriptorSetLayoutCreateInfo vkDescriptorSetLayoutCreateInfo = {};

    hwjvi::getVkDescriptorSetLayoutCreateInfo(
            env,
            jVkDescriptorSetLayoutCreateInfo,
            &vkDescriptorSetLayoutCreateInfo,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDescriptorSetLayout_T *vkDescriptorSetLayout = nullptr;

    int result = vkCreateDescriptorSetLayout(
            logicalDeviceHandle,
            &vkDescriptorSetLayoutCreateInfo,
            allocatorCallbacks,
            &vkDescriptorSetLayout);


    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkDescriptorSetLayout, vkDescriptorSetLayout);

    return hwjvi::createVkResult(env, result);
}
