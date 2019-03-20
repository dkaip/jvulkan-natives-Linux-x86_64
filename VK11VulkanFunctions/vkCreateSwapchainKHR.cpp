#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateSwapchainKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkSwapchainCreateInfoKHR;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSwapchainKHR;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateSwapchainKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainCreateInfoKHR, jobject jAlternateAllocator, jobject jVkSwapchainKHR)
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

    VkSwapchainCreateInfoKHR vkSwapchainCreateInfoKHR = {};
    std::vector<void *> memoryToFree(5);

    hwjvi::getSwapchainCreateInfoKHR(env, jVkSwapchainCreateInfoKHR, &vkSwapchainCreateInfoKHR, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSwapchainKHR swapchainHandle = nullptr;
    int result = vkCreateSwapchainKHR(logicalDeviceHandle, &vkSwapchainCreateInfoKHR, allocatorCallbacks, &swapchainHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkSwapchainKHR, swapchainHandle);

    return hwjvi::createVkResult(env, result);
}

