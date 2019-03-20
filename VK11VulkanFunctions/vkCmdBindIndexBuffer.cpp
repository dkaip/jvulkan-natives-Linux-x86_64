#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindIndexBuffer
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkBuffer;JLcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkIndexType;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBindIndexBuffer
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkBuffer, jlong jOffset, jobject jVkIndexTypeObject)
{
    VkCommandBuffer_T *vkCommandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *vkBufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass indexTypeObjectEnumClass = env->GetObjectClass(jVkIndexTypeObject);

    jmethodID valueOfMethodId = env->GetMethodID(indexTypeObjectEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkIndexType indexTypeEnumValue = (VkIndexType)env->CallIntMethod(jVkIndexTypeObject, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdBindIndexBuffer(
            vkCommandBufferHandle,
            vkBufferHandle,
            jOffset,
            indexTypeEnumValue);
}
