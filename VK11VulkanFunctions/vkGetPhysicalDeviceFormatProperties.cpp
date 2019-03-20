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

