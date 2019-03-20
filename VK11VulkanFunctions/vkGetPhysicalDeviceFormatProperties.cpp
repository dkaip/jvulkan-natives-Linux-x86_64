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

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceFormatProperties
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormat;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkFormatProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceFormatProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkFormat, jobject jVkFormatProperties)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkFormatEnumClass = env->GetObjectClass(jVkFormat);

    jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormat, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkFormatProperties vkFormatProperties = {};
    vkGetPhysicalDeviceFormatProperties(physicalDeviceHandle, vkFormatEnumValue, &vkFormatProperties);

    jobject jLinearTilingFeatures = hwjvi::getVkFormatFeatureFlagsEnumSet(env, vkFormatProperties.linearTilingFeatures);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject jOptimalTilingFeatures = hwjvi::getVkFormatFeatureFlagsEnumSet(env, vkFormatProperties.optimalTilingFeatures);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject jBufferFeatures = hwjvi::getVkFormatFeatureFlagsEnumSet(env, vkFormatProperties.bufferFeatures);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass vkFormatPropertiesClass = env->GetObjectClass(jVkFormatProperties);

    jmethodID methodId = env->GetMethodID(vkFormatPropertiesClass, "setLinearTilingFeatures", "(Ljava/util/EnumSet;)V");

    env->CallVoidMethod(jVkFormatProperties, methodId, jLinearTilingFeatures);

    methodId = env->GetMethodID(vkFormatPropertiesClass, "setOptimalTilingFeatures", "(Ljava/util/EnumSet;)V");

    env->CallVoidMethod(jVkFormatProperties, methodId, jOptimalTilingFeatures);

    methodId = env->GetMethodID(vkFormatPropertiesClass, "setBufferFeatures", "(Ljava/util/EnumSet;)V");

    env->CallVoidMethod(jVkFormatProperties, methodId, jBufferFeatures);
}

