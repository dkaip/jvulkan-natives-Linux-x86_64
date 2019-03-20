#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdCopyBuffer
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdCopyBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jSrcVkBuffer, jobject jDstVkBuffer, jobject jVkBufferCopyCollectionObject)
{
    VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *srcBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jSrcVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *dstBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jDstVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBufferCopies = 0;
    VkBufferCopy *vkBufferCopies = nullptr;

    if (jVkBufferCopyCollectionObject != nullptr)
    {
        hwjvi::getVkBufferCopyCollection(
                env,
                jVkBufferCopyCollectionObject,
                &vkBufferCopies,
                &numberOfVkBufferCopies,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkCmdCopyBuffer(vkCommandBufferHandle, srcBufferHandle, dstBufferHandle, numberOfVkBufferCopies, vkBufferCopies);

    hwjvi::freeMemory(&memoryToFree);
}
