#include <iostream>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateRenderPass2KHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkRenderPassCreateInfo2KHR;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkRenderPass;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateRenderPass2KHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkRenderPassCreateInfo2KHR, jobject jAlternateAllocator, jobject jVkRenderPass)
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



    VkRenderPassCreateInfo2KHR vkRenderPassCreateInfo2KHR = {};
    std::vector<void *> memoryToFree(10);

    hwjvi::getVkRenderPassCreateInfo2KHR(env, jVkRenderPassCreateInfo2KHR, &vkRenderPassCreateInfo2KHR, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }



    VkRenderPass renderPassHandle = nullptr;
    int result = vkCreateRenderPass2KHR(logicalDeviceHandle, &vkRenderPassCreateInfo2KHR, allocatorCallbacks, &renderPassHandle);


    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkRenderPass, renderPassHandle);

    return hwjvi::createVkResult(env, result);
}

