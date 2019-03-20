#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceSurfacePresentModesKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;Ljava/util/Collection;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceSurfacePresentModesKHR
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkSurfaceKHR, jobject jVkPresentModeKHRCollection)
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

    if (jVkPresentModeKHRCollection == nullptr)
    {
        cout << "ERROR: jVkPresentModeKHRCollection must be created before calling kGetPhysicalDeviceSurfacePresentModesKHR." << endl;
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    unsigned int numberOfPresentationModes = 0;

    VkResult result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, nullptr);
    if (result != VK_SUCCESS)
    {
        return hwjvi::createVkResult(env, result);
    }

    if (numberOfPresentationModes == 0)
    {
        return hwjvi::createVkResult(env, result);
    }

    std::vector<VkPresentModeKHR> presentationModes(numberOfPresentationModes);

    result = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDeviceHandle, surfaceKHRHandle, &numberOfPresentationModes, presentationModes.data());
    if (result != VK_SUCCESS)
    {
        return hwjvi::createVkResult(env, result);
    }

    jclass collectionClass = env->GetObjectClass(jVkPresentModeKHRCollection);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = nullptr;

    for (const auto& presentationMode : presentationModes)
    {
        ///////////////////////////////////////////////////////////////////////////

        jclass vkPresentModeKHRClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPresentModeKHR");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfacePresentModesKHR: could not find class " << "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPresentModeKHR" << endl;
            return nullptr;
        }

        methodId = env->GetStaticMethodID(vkPresentModeKHRClass, "fromValue", "(I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPresentModeKHR;");
        if (env->ExceptionOccurred())
        {
            cout << "vkGetPhysicalDeviceSurfacePresentModesKHR: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPresentModeKHR;" << endl;
            return nullptr;
        }

        jobject formatEnum = env->CallStaticObjectMethod(vkPresentModeKHRClass, methodId, presentationMode);

        bool successfulAdd = false;
        successfulAdd = env->CallBooleanMethod(jVkPresentModeKHRCollection, addMethodId, formatEnum);
        if (successfulAdd == false)
        {
            cout << "ERROR:vkGetPhysicalDeviceSurfacePresentModesKHR the new VkSurfaceFormatKHR element was not added to jVkSurfaceFormatKHRCollection" << endl;
        }
    }

    return hwjvi::createVkResult(env, result);
}

