/*
 * Copyright 2019-2020 Douglas Kaip
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

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetDeviceQueue
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;IILcom/CIMthetics/jvulkan/VulkanCore/Handles/VkQueue;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetDeviceQueue
  (JNIEnv *env, jobject, jobject jVkDevice, jint queueFamilyIndex, jint queueIndex, jobject jVkQueue)
{
    VkDevice_T *vkDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
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
    jvulkan::setHandleValue(env, jVkQueue, vkQueue);
}

