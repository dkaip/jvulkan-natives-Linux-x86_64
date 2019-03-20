#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindDescriptorSets
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineBindPoint;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPipelineLayout;ILjava/util/Collection;[I)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBindDescriptorSets
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkPipelineBindPoint, jobject jVkPipelineLayout, jint jFirstSet, jobject jVkDescriptorSetCollectionObject, jintArray jDynamicOffsets)
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

    VkPipelineBindPoint vkPipelineBindPointEnumValue = (VkPipelineBindPoint)env->CallIntMethod(jVkPipelineBindPoint, valueOfMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////
    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)hwjvi::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
        return;
    }

    std::vector<void *> memoryToFree(5);
    int numberOfVkDescriptorSets = 0;
    VkDescriptorSet *vkDescriptorSets = nullptr;

    hwjvi::getVkDescriptorSetCollection(
            env,
            jVkDescriptorSetCollectionObject,
            &vkDescriptorSets,
            &numberOfVkDescriptorSets,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return;
    }

    int numberOfDynamicOffsets = 0;
    int *dynamicOffsetsArray = nullptr;
    if (jDynamicOffsets != nullptr)
    {
        numberOfDynamicOffsets = env->GetArrayLength(jDynamicOffsets);

        dynamicOffsetsArray = (int *)calloc(numberOfDynamicOffsets, sizeof(int));
        memoryToFree.push_back(dynamicOffsetsArray);

        env->GetIntArrayRegion(jDynamicOffsets, 0, numberOfDynamicOffsets, dynamicOffsetsArray);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }


    vkCmdBindDescriptorSets(
            commandBufferHandle,
            vkPipelineBindPointEnumValue,
            pipelineLayoutHandle,
            jFirstSet,
            numberOfVkDescriptorSets,
            vkDescriptorSets,
            numberOfDynamicOffsets,
            (uint32_t *)dynamicOffsetsArray);

    hwjvi::freeMemory(&memoryToFree);
}

