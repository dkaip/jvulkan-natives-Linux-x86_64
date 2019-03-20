#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkBindImageMemory
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDeviceMemory;J)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkBindImageMemory
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImage, jobject jVkDeviceMemory, jlong jmemoryOffset)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkImage_T *imageHandle = (VkImage_T *)hwjvi::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)hwjvi::getHandleValue(env, jVkDeviceMemory);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkBindImageMemory(
            logicalDeviceHandle,
            imageHandle,
            deviceMemoryHandle,
            jmemoryOffset);

    return hwjvi::createVkResult(env, result);
}
