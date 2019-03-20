#include <iostream>

using namespace std;

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindPipeline
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineBindPoint;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPipeline;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBindPipeline
  (JNIEnv *env , jobject, jobject jVkCommandBuffer, jobject jVkPipelineBindPoint, jobject jVkPipeline)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    jclass vkPipelineBindPointEnumClass = env->GetObjectClass(jVkPipelineBindPoint);

    jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    enum VkPipelineBindPoint vkPipelineBindPointEnumValue = (enum VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPoint, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkPipeline_T *pipelineHandle = (VkPipeline_T *)hwjvi::getHandleValue(env, jVkPipeline);
    if (env->ExceptionOccurred())
    {
        return;
    }

    vkCmdBindPipeline(commandBufferHandle, vkPipelineBindPointEnumValue, pipelineHandle);
}

