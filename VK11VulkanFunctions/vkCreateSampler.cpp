#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateSampler
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkSamplerCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSampler;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateSampler
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSamplerCreateInfoObject, jobject jAlternateAllocator, jobject jVkSampler)
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
    VkSamplerCreateInfo vkSamplerCreateInfo = {};

    hwjvi::getVkSamplerCreateInfo(env, jVkSamplerCreateInfoObject, &vkSamplerCreateInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    VkSampler_T *samplerHandle = nullptr;
    int result = vkCreateSampler(logicalDeviceHandle, &vkSamplerCreateInfo, allocatorCallbacks, &samplerHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    hwjvi::freeMemory(&memoryToFree);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkSampler, samplerHandle);

    return hwjvi::createVkResult(env, result);
}

