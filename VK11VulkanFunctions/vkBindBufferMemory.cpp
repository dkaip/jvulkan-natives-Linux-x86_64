#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkBindBufferMemory
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDeviceMemory;J)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkBindBufferMemory
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBuffer, jobject jVkDeviceMemory, jlong jMemoryOffset)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)hwjvi::getHandleValue(env, jVkDeviceMemory);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkBindBufferMemory(
            logicalDeviceHandle,
            bufferHandle,
            deviceMemoryHandle,
            (VkDeviceSize)jMemoryOffset);

    return hwjvi::createVkResult(env, result);
}
