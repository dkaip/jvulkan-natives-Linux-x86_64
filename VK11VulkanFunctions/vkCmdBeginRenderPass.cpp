#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBeginRenderPass
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkRenderPassBeginInfo;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSubpassContents;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBeginRenderPass
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkRenderPassBeginInfo, jobject jVkSubpassContents)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    VkRenderPassBeginInfo vkRenderPassBeginInfo = {};

    hwjvi::getVkRenderPassBeginInfo(env, jVkRenderPassBeginInfo, &vkRenderPassBeginInfo, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass subpassContentsEnumClass = env->GetObjectClass(jVkSubpassContents);

    jmethodID valueOfMethodId = env->GetMethodID(subpassContentsEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jint subpassContentsEnumValue = env->CallIntMethod(jVkSubpassContents, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdBeginRenderPass(commandBufferHandle, &vkRenderPassBeginInfo, (enum VkSubpassContents)subpassContentsEnumValue);

    hwjvi::freeMemory(&memoryToFree);
}

