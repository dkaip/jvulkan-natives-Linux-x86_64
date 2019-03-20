#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkBeginCommandBuffer
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkCommandBufferBeginInfo;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkBeginCommandBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkCommandBufferBeginInfo)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkCommandBufferBeginInfo vkCommandBufferBeginInfo = {};

    hwjvi::getVkCommandBufferBeginInfo(env, jVkCommandBufferBeginInfo, &vkCommandBufferBeginInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkResult result = vkBeginCommandBuffer(commandBufferHandle, &vkCommandBufferBeginInfo);

    hwjvi::freeMemory(&memoryToFree);

    return hwjvi::createVkResult(env, result);
}

