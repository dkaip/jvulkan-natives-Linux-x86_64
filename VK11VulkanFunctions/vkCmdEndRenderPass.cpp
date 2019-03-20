#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdEndRenderPass
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdEndRenderPass
  (JNIEnv *env, jobject, jobject jVkCommandBuffer)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdEndRenderPass(commandBufferHandle);
}

