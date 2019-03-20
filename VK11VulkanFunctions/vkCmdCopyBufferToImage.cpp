#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdCopyBufferToImage
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdCopyBufferToImage
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkBuffer, jobject jVkImage, jobject jVkImageLayoutObject, jobject jVkBufferImageCopyCollectionObject)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkImage_T *imageHandle = (VkImage_T *)hwjvi::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);

    jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkImageLayout vkImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkBufferImageCopies = 0;
    VkBufferImageCopy *vkBufferImageCopies = nullptr;

    if (jVkBufferImageCopyCollectionObject != nullptr)
    {
        hwjvi::getVkBufferImageCopyCollection(
                env,
                jVkBufferImageCopyCollectionObject,
                &vkBufferImageCopies,
                &numberOfVkBufferImageCopies,
                &memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkCmdCopyBufferToImage(
            commandBufferHandle,
            bufferHandle,
            imageHandle,
            vkImageLayoutEnumValue,
            numberOfVkBufferImageCopies,
            vkBufferImageCopies);

    hwjvi::freeMemory(&memoryToFree);
}
