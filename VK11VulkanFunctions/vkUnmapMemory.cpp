#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkUnmapMemory
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDeviceMemory;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkUnmapMemory
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceMemory)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)hwjvi::getHandleValue(env, jVkDeviceMemory);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkUnmapMemory(logicalDeviceHandle, deviceMemoryHandle);
}
