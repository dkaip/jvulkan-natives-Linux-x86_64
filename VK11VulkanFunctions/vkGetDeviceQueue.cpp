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

