#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetDeviceQueue
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;IILcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkQueue;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetDeviceQueue
  (JNIEnv *env, jobject, jobject jVkDevice, jint queueFamilyIndex, jint queueIndex, jobject jVkQueue)
{
    VkDevice_T *vkDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkQueue vkQueue;
//    cout  << logicalDeviceHandle << " " << queueFamilyIndex << " " << queueIndex << " " << vkQueue << endl;
    vkGetDeviceQueue(vkDeviceHandle, queueFamilyIndex, queueIndex, &vkQueue);
    if (env->ExceptionOccurred())
    {
        return;
    }

//    cout  << logicalDeviceHandle << " " << queueFamilyIndex << " " << queueIndex << " " << vkQueue << endl;

    /*
     * Now transfer the VkQueue data to Java
     */
    hwjvi::setHandleValue(env, jVkQueue, vkQueue);
}

