#include <iostream>

using namespace std;

//#include <vulkan/vulkan.h>
//#include <vulkan/vulkan_core.h>
//#include <vulkan/vulkan_wayland.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceWaylandPresentationSupportKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;ILcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlDisplay;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceWaylandPresentationSupportKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint queueFamilyIndex, jobject jWlDisplay)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return false;
    }

    struct wl_display *wlDisplayHandle = (struct wl_display *)hwjvi::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
        return false;
    }

    return vkGetPhysicalDeviceWaylandPresentationSupportKHR(vkPhysicalDeviceHandle, queueFamilyIndex, wlDisplayHandle);
}

