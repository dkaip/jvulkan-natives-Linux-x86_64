#include <iostream>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceCapabilitiesKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkSurfaceCapabilitiesKHR;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfaceCapabilitiesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkSurfaceCapabilitiesKHR)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceKHRHandle = (VkSurfaceKHR_T *)hwjvi::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (jVkSurfaceCapabilitiesKHR == nullptr)
    {
        cout << "ERROR: jVkSurfaceCapabilitiesKHR must be created before calling vkGetPhysicalDeviceSurfaceCapabilitiesKHR." << endl;
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceCapabilitiesKHR surfaceCapabilities = {};

    VkResult result = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDeviceHandle, surfaceKHRHandle, &surfaceCapabilities);
    if (result != VK_SUCCESS)
    {
        return hwjvi::createVkResult(env, result);
    }

    jclass surfaceCapabilitiesClass = env->GetObjectClass(jVkSurfaceCapabilitiesKHR);
    ////////////////////////////////////////////////////////////////////////////

    jmethodID methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMinImageCount", "(I)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.minImageCount);

    ////////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageCount", "(I)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.maxImageCount);

    ////////////////////////////////////////////////////////////////////////////

    jclass extent2DClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D");
    jmethodID extent2DConstructor = env->GetMethodID(extent2DClass, "<init>", "(II)V");

    jobject extent2DObject = env->NewObject(
            extent2DClass,
            extent2DConstructor,
            surfaceCapabilities.currentExtent.width,
            surfaceCapabilities.currentExtent.height);

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setCurrentImageExtent", "(Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D;)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);

    ////////////////////////////////////////////////////////////////////////////

    extent2DObject = env->NewObject(
            extent2DClass,
            extent2DConstructor,
            surfaceCapabilities.minImageExtent.width,
            surfaceCapabilities.minImageExtent.height);

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMinImageExtent", "(Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D;)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);

    ////////////////////////////////////////////////////////////////////////////

    extent2DObject = env->NewObject(
            extent2DClass,
            extent2DConstructor,
            surfaceCapabilities.maxImageExtent.width,
            surfaceCapabilities.maxImageExtent.height);

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageExtent", "(Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D;)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, extent2DObject);

    ////////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setMaxImageArrayLayers", "(I)V");

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, surfaceCapabilities.maxImageArrayLayers);

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedTransforms", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject supportedTransformsEnumSet = hwjvi::getVkSurfaceTransformFlagsKHRAsEnumSet(env, surfaceCapabilities.supportedTransforms);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (supportedTransformsEnumSet == nullptr)
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedTransformsEnumSet);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ///////////////////////////////////////////////////////////////////////////

    jclass vkSurfaceTransformFlagBitsKHRClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR");
    if (env->ExceptionOccurred())
    {
        cout << "vkGetPhysicalDeviceSurfaceCapabilitiesKHR: could not find class " << "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR" << endl;
        return nullptr;
    }

    methodId = env->GetStaticMethodID(vkSurfaceTransformFlagBitsKHRClass, "fromValue", "(I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
    if (env->ExceptionOccurred())
    {
        cout << "vkGetPhysicalDeviceSurfaceCapabilitiesKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;" << endl;
        return nullptr;
    }

    jobject jCurrentTransformEnum = env->CallStaticObjectMethod(vkSurfaceTransformFlagBitsKHRClass, methodId, surfaceCapabilities.currentTransform);

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setCurrentTransform", "(Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;)V");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, jCurrentTransformEnum);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedCompositeAlpha", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject supportedCompositeAlphaEnumSet = hwjvi::getVkCompositeAlphaFlagsKHRAsEnumSet(env, surfaceCapabilities.supportedCompositeAlpha);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (supportedCompositeAlphaEnumSet == nullptr)
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedCompositeAlphaEnumSet);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ///////////////////////////////////////////////////////////////////////////

    methodId = env->GetMethodID(surfaceCapabilitiesClass, "setSupportedUsageFlags", "(Ljava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject supportedImageUsageFlagsEnumSet = hwjvi::getVkImageUsageFlagsAsEnumSet(env, surfaceCapabilities.supportedUsageFlags);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (supportedImageUsageFlagsEnumSet == nullptr)
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    env->CallVoidMethod(jVkSurfaceCapabilitiesKHR, methodId, supportedImageUsageFlagsEnumSet);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    return hwjvi::createVkResult(env, result);
}

