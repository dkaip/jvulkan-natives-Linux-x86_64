#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetSwapchainImagesKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSwapchainKHR;Ljava/util/Collection;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetSwapchainImagesKHR
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSwapchainKHR, jobject jswapchainImageCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkSwapchainKHR_T *swapchainHandle = (VkSwapchainKHR_T *)hwjvi::getHandleValue(env, jVkSwapchainKHR);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    uint32_t numberOfImages = 0;

    int result = vkGetSwapchainImagesKHR(logicalDeviceHandle, swapchainHandle, &numberOfImages, nullptr);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, result);
    }

    VkImage_T **swapchainImageHandles = (VkImage_T **)calloc(numberOfImages, sizeof(VkImage *));

    result = vkGetSwapchainImagesKHR(logicalDeviceHandle, swapchainHandle, &numberOfImages, swapchainImageHandles);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, result);
    }

    jclass collectionClass = env->GetObjectClass(jswapchainImageCollection);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    for (uint32_t i = 0; i < numberOfImages; i++)
    {
        jobject vkImageHandle = hwjvi::createHandle(env, "com/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage", swapchainImageHandles[i]);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jboolean addResult = env->CallBooleanMethod(jswapchainImageCollection, addMethodId, vkImageHandle);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        if (addResult == false)
        {
            cerr << "Warning did not add VkImage to output collection." << endl;
        }
    }

    free(swapchainImageHandles);
    return hwjvi::createVkResult(env, result);
}

