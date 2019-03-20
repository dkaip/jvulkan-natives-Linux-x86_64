#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreatePipelineLayout
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkPipelineLayoutCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPipelineLayout;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreatePipelineLayout
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkPipelineLayoutCreateInfo, jobject jAlternateAllocator, jobject jVkPipelineLayout)
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

    VkPipelineLayoutCreateInfo vkPipelineLayoutCreateInfo = {};
    std::vector<void *> memoryToFree(5);

    hwjvi::getVkPipelineLayoutCreateInfo(env, jVkPipelineLayoutCreateInfo, &vkPipelineLayoutCreateInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkPipelineLayout_T *vkPipelineLayout = nullptr;
    int result = vkCreatePipelineLayout(logicalDeviceHandle, &vkPipelineLayoutCreateInfo, allocatorCallbacks, &vkPipelineLayout);
    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkPipelineLayout, vkPipelineLayout);

    return hwjvi::createVkResult(env, result);
}
