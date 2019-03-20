#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkMapMemory
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDeviceMemory;JJLjava/util/EnumSet;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/MappedMemoryPointer;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkMapMemory
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDeviceMemory, jlong jOffset, jlong jSize, jobject jVkMemoryMapFlags, jobject jVoidPointer)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDeviceMemory_T *deviceMemoryHandle = (VkDeviceMemory_T *)hwjvi::getHandleValue(env, jVkDeviceMemory);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkMemoryMapFlags flags = 0;
    if (jVkMemoryMapFlags != nullptr)
    {
        flags = hwjvi::getEnumSetValue(
                env,
                jVkMemoryMapFlags,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkMemoryMapFlagBits");
    }

    void *dataPointer = nullptr;
    int result = vkMapMemory(
            logicalDeviceHandle,
            deviceMemoryHandle,
            (VkDeviceSize)jOffset,
            (VkDeviceSize)jSize,
            flags,
            &dataPointer);

    /*
     * Now transfer the VkDevice data to Java
     */
    hwjvi::setHandleValue(env, jVoidPointer, dataPointer);

    return hwjvi::createVkResult(env, result);
}
