/*
 * Copyright 2019 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>

using namespace std;

//#include <vulkan/vulkan.h>
//#include <vulkan/vulkan_core.h>
//#include <vulkan/vulkan_wayland.h>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceWaylandPresentationSupportKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;ILcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlDisplay;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceWaylandPresentationSupportKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint queueFamilyIndex, jobject jWlDisplay)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return false;
    }

    struct wl_display *wlDisplayHandle = (struct wl_display *)jvulkan::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
        return false;
    }

    return vkGetPhysicalDeviceWaylandPresentationSupportKHR(vkPhysicalDeviceHandle, queueFamilyIndex, wlDisplayHandle);
}

