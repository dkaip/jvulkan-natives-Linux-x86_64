#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateFence
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkFenceCreateInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkFence;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateFence
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkFenceCreateInfoObject, jobject jAlternateAllocator, jobject jVkFence)
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

    jclass vkFenceCreateInfoClass = env->GetObjectClass(jVkFenceCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    int sTypeValue = hwjvi::getSTypeAsInt(env, jVkFenceCreateInfoObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jmethodID methodId = env->GetMethodID(vkFenceCreateInfoClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jlong pNext = env->CallLongMethod(jVkFenceCreateInfoObject, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    methodId = env->GetMethodID(vkFenceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkFenceCreateInfoObject, methodId);
    VkFenceCreateFlags flags = hwjvi::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSemaphoreCreateFlagBits");

    VkFenceCreateInfo vkFenceCreateInfo = {};
    vkFenceCreateInfo.sType = (VkStructureType)sTypeValue;
    vkFenceCreateInfo.pNext = (void *)pNext;
    vkFenceCreateInfo.flags = flags;

    VkFence_T *fenceHandle = nullptr;
    int result = vkCreateFence(logicalDeviceHandle, &vkFenceCreateInfo, allocatorCallbacks, &fenceHandle);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVkFence, fenceHandle);

    return hwjvi::createVkResult(env, result);
}

