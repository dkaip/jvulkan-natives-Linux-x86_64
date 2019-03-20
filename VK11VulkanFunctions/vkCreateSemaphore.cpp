#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateSemaphore
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkSemaphoreCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSemaphore;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateSemaphore
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkSemaphoreCreateInfoObject, jobject jAlternateAllocator, jobject jVkSemaphore)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    jclass vkSemaphoreCreateInfoClass = env->GetObjectClass(jVkSemaphoreCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    int sTypeValue = hwjvi::getSTypeAsInt(env, jVkSemaphoreCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jmethodID methodId = env->GetMethodID(vkSemaphoreCreateInfoClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jlong pNext = env->CallLongMethod(jVkSemaphoreCreateInfoObject, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    methodId = env->GetMethodID(vkSemaphoreCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkSemaphoreCreateInfoObject, methodId);
    VkSemaphoreCreateFlags flags = hwjvi::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSemaphoreCreateFlagBits");

    VkSemaphoreCreateInfo vkSemaphoreCreateInfo = {};
    vkSemaphoreCreateInfo.sType = (VkStructureType)sTypeValue;
    vkSemaphoreCreateInfo.pNext = (void *)pNext;
    vkSemaphoreCreateInfo.flags = flags;

    VkSemaphore_T *semaphoreHandle = nullptr;
    int result = vkCreateSemaphore(logicalDeviceHandle, &vkSemaphoreCreateInfo, allocatorCallbacks, &semaphoreHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkSemaphore, semaphoreHandle);

    return hwjvi::createVkResult(env, result);
}

