#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateDevice
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkDeviceCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateDevice
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkDeviceCreateInfo, jobject jAlternateAllocator, jobject jVkDevice)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
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

    jclass vkDeviceCreateInfoClass = env->GetObjectClass(jVkDeviceCreateInfo);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getQueueCreateInfos", "()Ljava/util/Collection;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject jVkDeviceQueueCreateInfoObjects = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass collectionClass = env->FindClass("java/util/Collection");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    methodId = env->GetMethodID(collectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint deviceQueueCreateInfoObjectsSize = env->CallIntMethod(jVkDeviceQueueCreateInfoObjects, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceQueueCreateInfo queueCreateInfos[deviceQueueCreateInfoObjectsSize] = {};

    std::vector<void *> memoryToFree(30);

    hwjvi::getQueueCreateInfo(env,
            collectionClass,
            jVkDeviceQueueCreateInfoObjects,
            queueCreateInfos,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceCreateInfo deviceCreateInfo = {};

    hwjvi::getDeviceCreateInfo(env, jVkDeviceCreateInfo, &deviceCreateInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    deviceCreateInfo.pQueueCreateInfos = queueCreateInfos;
    deviceCreateInfo.queueCreateInfoCount = deviceQueueCreateInfoObjectsSize;

    VkDevice vkDevice;
    VkResult result = vkCreateDevice(physicalDeviceHandle, &deviceCreateInfo, allocatorCallbacks, &vkDevice);

    hwjvi::freeMemory(&memoryToFree);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkDevice, vkDevice);

    return hwjvi::createVkResult(env, result);
}

