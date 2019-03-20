#include <iostream>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfaceSupportKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;ILcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;[Z)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfaceSupportKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jint queueFamilyIndex, jobject jVkSurfaceKHR, jbooleanArray jIsSupportedBoolean)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)hwjvi::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)hwjvi::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkBool32 isSupported;
    int result = vkGetPhysicalDeviceSurfaceSupportKHR(physicalDeviceHandle, queueFamilyIndex, surfaceHandle, &isSupported);

    jsize arrayLength = env->GetArrayLength(jIsSupportedBoolean);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (arrayLength < queueFamilyIndex + 1)
    {
        cout << "ERROR:The boolean array input is too small.  Index is " << queueFamilyIndex << " array size is " << arrayLength << "." << endl;
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

//    cout << "Queue Family Index:" << queueFamilyIndex << " isSupported:" << isSupported << endl;

    jboolean *array = env->GetBooleanArrayElements(jIsSupportedBoolean, 0);
    array[queueFamilyIndex] = isSupported;
    env->ReleaseBooleanArrayElements(jIsSupportedBoolean, array, 0);

    return hwjvi::createVkResult(env, result);
}

