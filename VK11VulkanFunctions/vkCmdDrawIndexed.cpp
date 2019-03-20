#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdDrawIndexed
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;IIIII)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdDrawIndexed
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint jIndexCount, jint jInstanceCount, jint jFirstIndex, jint jVertexOffset, jint jFirstInstance)
{
    VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdDrawIndexed(
            vkCommandBufferHandle,
            jIndexCount,
            jInstanceCount,
            jFirstIndex,
            jVertexOffset,
            jFirstInstance);
}
