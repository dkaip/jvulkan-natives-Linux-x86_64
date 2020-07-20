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

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceSupportKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;ILcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/BooleanReturnValue;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceSurfaceSupportKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint queueFamilyIndex, jobject jVkSurfaceKHR, jobject jIsSupportedBoolean)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)jvulkan::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkBool32 isSupported;
    int result = vkGetPhysicalDeviceSurfaceSupportKHR(physicalDeviceHandle, queueFamilyIndex, surfaceHandle, &isSupported);

//    jsize arrayLength = env->GetArrayLength(jIsSupportedBoolean);
//    if (env->ExceptionOccurred())
//    {
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
//    if (arrayLength < queueFamilyIndex + 1)
//    {
//        cout << "ERROR:The boolean array input is too small.  Index is " << queueFamilyIndex << " array size is " << arrayLength << "." << endl;
//        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
//    }
//
    jvulkan::setBooleanReturnValue(env, jIsSupportedBoolean, (jboolean)isSupported);

//    cout << "Queue Family Index:" << queueFamilyIndex << " isSupported:" << isSupported << endl;

//    jboolean *array = env->GetBooleanArrayElements(jIsSupportedBoolean, 0);
//    array[queueFamilyIndex] = isSupported;
//    env->ReleaseBooleanArrayElements(jIsSupportedBoolean, array, 0);
//
    return jvulkan::createVkResult(env, result);
}

