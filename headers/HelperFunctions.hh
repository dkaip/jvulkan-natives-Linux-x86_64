/*
 * Copyright 2019 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * StructureHelperFunctions.hh
 *
 *  Created on: Jul 13, 2018
 *      Author: Douglas Kaip
 */

#include <vector>
#include <jni.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_wayland.h>

#ifndef STRUCTUREHELPERFUNCTIONS_HH_
#define STRUCTUREHELPERFUNCTIONS_HH_

namespace jvulkan
{
//    void getVkInstanceCreateInfo(
//            JNIEnv *env,
//            const jobject jInstanceCreateInfo,
//            VkInstanceCreateInfo *instanceCreateInfo,
//            VkApplicationInfo *applicationInfo,
//            std::vector<void *> *memoryToFree);
//
    void getAllocatorCallbacks(
            JNIEnv *env,
            const jobject jAlternateAllocator,
            VkAllocationCallbacks *allocatorCallbacks);

    void getVkDeviceCreateInfo(
            JNIEnv *env,
            const jobject jVkDeviceCreateInfo,
            VkDeviceCreateInfo *deviceCreateInfo,
            std::vector<void *> *memoryToFree);

    int getSTypeAsInt(
            JNIEnv *env,
            const jobject vulkanStructureObject);

    int32_t getEnumSetValue(
            JNIEnv *env,
            const jobject enumSetObject,
            const char *enumClassName);

    void freeMemory(std::vector<void *> *memoryToFree);
    //    void cleanupArrayOfPointersToStrings(char *** stringArrayResult, int numberOfStrings);

    void *getHandleValue(JNIEnv *env, jobject jHandle);

    void setHandleValue(JNIEnv *env, jobject jHandle, void *value);

    void setIntReturnValue(JNIEnv *env, jobject jReturnValue, jint value);

    jobject createVulkanHandle(JNIEnv *env, const char *className, void *value);

    jobject createVkResult(JNIEnv *env, jint value);

    jobject getVkImageUsageFlagsAsEnumSet(JNIEnv *env, VkImageUsageFlags usageFlags);

    jobject getVkCompositeAlphaFlagsKHRAsEnumSet(JNIEnv *env, VkCompositeAlphaFlagsKHR alphaFlags);

    jobject getVkSurfaceTransformFlagsKHRAsEnumSet(JNIEnv *env, VkSurfaceTransformFlagsKHR transformFlags);

    void getVkDeviceQueueCreateInfo(
            JNIEnv *env,
            const jobject jVkQueueCreateInfoCollection,
            VkDeviceQueueCreateInfo queueCreateInfo[],
            std::vector<void *> *memoryToFree);

    void getVkDeviceQueueCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkDeviceQueueCreateInfoCollectionObject,
			VkDeviceQueueCreateInfo **vkDeviceQueueCreateInfos,
            int *numberOfVkDeviceQueueCreateInfos,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceFeatures(
            JNIEnv *env,
            const jobject jgetVkPhysicalDeviceFeaturesObject,
			VkPhysicalDeviceFeatures *vkPhysicalDeviceFeatures,
            std::vector<void *> *memoryToFree);

    void getSwapchainCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkSwapchainCreateInfoKHR,
            VkSwapchainCreateInfoKHR *swapchainCreateInfo,
            std::vector<void *> *memoryToFree);

    void getImageViewCreateInfo(
        JNIEnv *env,
        const jobject jVkImageViewCreateInfo,
        VkImageViewCreateInfo *imageViewCreateInfo,
        std::vector<void *> *memoryToFree);

    void getRenderPassCreateInfo(
        JNIEnv *env,
        const jobject jVkRenderPassCreateInfo,
        VkRenderPassCreateInfo *renderPassCreateInfo,
        std::vector<void *> *memoryToFree);

    void getVkAttachmentDescriptions(
            JNIEnv *env,
            const jobject jVkAttachmentDescriptionCollectionObject,
            VkAttachmentDescription **renderPassCreateInfo,
            int *numberOfAttachments,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDescriptions(
            JNIEnv *env,
            const jobject jVkSubpassDescriptionCollectionObject,
            VkSubpassDescription **subpassDescriptions,
            int *numberOfDescriptions,
            std::vector<void *> *memoryToFree);

    void getVkAttachmentReference(
            JNIEnv *env,
            const jobject jVkAttachmentReferenceObject,
            VkAttachmentReference *attachmentReference);

    void getCollectionOfVkSubpassDependency(
            JNIEnv *env,
            const jobject jVkSubpassDependencyCollectionObject,
            VkSubpassDependency **subpassDependencies,
            int *numberOfSubpassDependencies,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDependency(
            JNIEnv *env,
            const jobject jVkSubpassDependencyObject,
            VkSubpassDependency *subpassDependency);

    void getVkShaderModuleCreateInfo(
        JNIEnv *env,
        const jobject jVkShaderModuleCreateInfoObject,
        VkShaderModuleCreateInfo *shaderModuleCreateInfo,
        std::vector<void *> *memoryToFree);

    void getVkPipelineLayoutCreateInfo(
        JNIEnv *env,
        const jobject jVkPipelineLayoutCreateInfoObject,
        VkPipelineLayoutCreateInfo *vkPipelineLayoutCreateInfo,
        std::vector<void *> *memoryToFree);

    void getCollectionOfVkDescriptorSetLayout(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutCollectionObject,
            VkDescriptorSetLayout ***descriptorSetLayouts,
            int *numberOfDescriptorSetLayouts,
            std::vector<void *> *memoryToFree);

    void getCollectionOfVkPushConstantRange(
            JNIEnv *env,
            const jobject jVkPushConstantRangeCollectionObject,
            VkPushConstantRange **pushConstantRanges[],
            int *numberOfPushConstantRanges,
            std::vector<void *> *memoryToFree);

    void getVkPushConstantRange(
            JNIEnv *env,
            const jobject VkPushConstantRangeObject,
            VkPushConstantRange *pushConstantRange);

    void getVkGraphicsPipelineCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkGraphicsPipelineCreateInfoCollectionObject,
            VkGraphicsPipelineCreateInfo **graphicsPipelineCreateInfos,
            int *numberOfCreateInfos,
            std::vector<void *> *memoryToFree);

    void getVkGraphicsPipelineCreateInfo(
            JNIEnv *env,
            jobject jVkGraphicsPipelineCreateInfo,
            VkGraphicsPipelineCreateInfo *vkGraphicsPipelineCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineShaderStageCreateInfoCollection(
            JNIEnv *env,
            jobject jVkPipelineShaderStageCreateInfo,
            VkPipelineShaderStageCreateInfo **vkPipelineShaderStageCreateInfo,
            int *numberOfPipelineShaderStages,
            std::vector<void *> *memoryToFree);

    void getVkPipelineShaderStageCreateInfo(
            JNIEnv *env,
            const jobject jVkPipelineShaderStageCreateInfoObject,
            VkPipelineShaderStageCreateInfo *vkPipelineShaderStageCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkSpecializationInfo(
            JNIEnv *env,
            const jobject jVkSpecializationInfoInfoObject,
            VkSpecializationInfo *vkSpecializationInfo,
            std::vector<void *> *memoryToFree);

    void getVkSpecializationMapEntry(
            JNIEnv *env,
            const jobject jVkSpecializationMapEntryObject,
            VkSpecializationMapEntry *vkSpecializationMapEntry,
            std::vector<void *> *memoryToFree);

    void getVkSpecializationMapEntryCollection(
            JNIEnv *env,
            const jobject jVkSpecializationMapEntryCollectionObject,
            VkSpecializationMapEntry **vkSpecializationMapEntries,
            int *numberOfVkSpecializationMapEntries,
            std::vector<void *> *memoryToFree);

    void getVkPipelineVertexInputStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineVertexInputStateCreateInfoObject,
            VkPipelineVertexInputStateCreateInfo *vkPipelineVertexInputStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkVertexInputBindingDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionCollectionObject,
            VkVertexInputBindingDescription **vkVertexInputBindingDescriptions,
            int *numberOfVkVertexInputBindingDescriptions,
            std::vector<void *> *memoryToFree);

    void getVkVertexInputBindingDescription(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionObject,
            VkVertexInputBindingDescription *vkVertexInputBindingDescription,
            std::vector<void *> *memoryToFree);

    void getVkVertexInputAttributeDescription(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionObject,
            VkVertexInputAttributeDescription *vkVertexInputAttributeDescription,
            std::vector<void *> *memoryToFree);

    void getVkVertexInputAttributeDescriptionCollection(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionCollectionObject,
            VkVertexInputAttributeDescription **vkVertexInputAttributeDescription,
            int *numberOfVkVertexInputAttributeDescriptions,
            std::vector<void *> *memoryToFree);

    void getVkPipelineInputAssemblyStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineInputAssemblyStateCreateInfoObject,
            VkPipelineInputAssemblyStateCreateInfo *vkPipelineInputAssemblyStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineTessellationStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineTessellationStateCreateInfoObject,
            VkPipelineTessellationStateCreateInfo *vkPipelineTessellationStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineViewportStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineViewportStateCreateInfoObject,
            VkPipelineViewportStateCreateInfo *vkPipelineViewportStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkViewport(
            JNIEnv *env,
            jobject jVkViewportObject,
            VkViewport *vkViewport,
            std::vector<void *> *memoryToFree);

    void getVkOffset2D(
            JNIEnv *env,
            jobject jVkOffset2DObject,
            VkOffset2D *vkOffset2D,
            std::vector<void *> *memoryToFree);

    void getVkOffset3D(
            JNIEnv *env,
            jobject jVkOffset3DObject,
            VkOffset3D *vkOffset3D,
            std::vector<void *> *memoryToFree);

    void getVkExtent2D(
            JNIEnv *env,
            jobject jVkExtent2DObject,
            VkExtent2D *vkExtent2D,
            std::vector<void *> *memoryToFree);

    void getVkExtent3D(
            JNIEnv *env,
            jobject jVkExtent3DObject,
            VkExtent3D *vkExtent3D,
            std::vector<void *> *memoryToFree);

    void getVkRect2D(
            JNIEnv *env,
            jobject jVkRect2DObject,
            VkRect2D *vkRect2D,
            std::vector<void *> *memoryToFree);

    void getVkRect2DCollection(
            JNIEnv *env,
            const jobject jVkRect2DCollectionObject,
            VkRect2D **vkRect2Ds,
            int *numberOfVkRect2Ds,
            std::vector<void *> *memoryToFree);

    void getVkPipelineRasterizationStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineRasterizationStateCreateInfoInfoObject,
            VkPipelineRasterizationStateCreateInfo *vkPipelineRasterizationStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineMultisampleStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineMultisampleStateCreateInfoObject,
            VkPipelineMultisampleStateCreateInfo *vkPipelineMultisampleStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineDepthStencilStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineDepthStencilStateCreateInfoObject,
            VkPipelineDepthStencilStateCreateInfo *vkPipelineDepthStencilStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkStencilOpState(
            JNIEnv *env,
            jobject jVkStencilOpStateObject,
            VkStencilOpState *vkStencilOpState,
            std::vector<void *> *memoryToFree);

    void getVkPipelineColorBlendStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineColorBlendStateCreateInfo,
            VkPipelineColorBlendStateCreateInfo *vkPipelineColorBlendStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkPipelineColorBlendAttachmentState(
            JNIEnv *env,
            const jobject jVkPipelineColorBlendAttachmentStateObject,
            VkPipelineColorBlendAttachmentState *vkPipelineColorBlendAttachmentState,
            std::vector<void *> *memoryToFree);

    void getVkPipelineColorBlendAttachmentStateCollection(
            JNIEnv *env,
            const jobject jVkPipelineColorBlendAttachmentStateCollectionObject,
            VkPipelineColorBlendAttachmentState **vkPipelineColorBlendAttachmentStates,
            int *numberOfVkPipelineColorBlendAttachmentStates,
            std::vector<void *> *memoryToFree);

    void getVkPipelineDynamicStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineDynamicStateCreateInfoObject,
            VkPipelineDynamicStateCreateInfo *vkPipelineDynamicStateCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkDynamicStateCollection(
            JNIEnv *env,
            const jobject jVkDynamicStateCollectionObject,
            VkDynamicState **vkDynamicStates,
            int *numberOfVkDynamicStates,
            std::vector<void *> *memoryToFree);

    void getVkFramebufferCreateInfo(
            JNIEnv *env,
            jobject jVkFramebufferCreateInfoObject,
            VkFramebufferCreateInfo *vkFramebufferCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkImageViewCollection(
            JNIEnv *env,
            const jobject jVkImageViewCollectionObject,
            VkImageView **vkImageViews,
            int *numberOfVkImageViews,
            std::vector<void *> *memoryToFree);

    void getVkCommandPoolCreateInfo(
            JNIEnv *env,
            jobject jVkCommandPoolCreateInfoObject,
            VkCommandPoolCreateInfo *vkCommandPoolCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkCommandBufferAllocateInfo(
            JNIEnv *env,
            jobject jVkCommandBufferAllocateInfoObject,
            VkCommandBufferAllocateInfo *vkCommandBufferAllocateInfo,
            std::vector<void *> *memoryToFree);

    void getVkCommandBufferBeginInfo(
            JNIEnv *env,
            jobject jVkCommandBufferBeginInfoObject,
            VkCommandBufferBeginInfo *vkCommandBufferBeginInfo,
            std::vector<void *> *memoryToFree);

    void getVkCommandBufferInheritanceInfo(
            JNIEnv *env,
            jobject jVkCommandBufferInheritanceInfo,
            VkCommandBufferInheritanceInfo *vkCommandBufferInheritanceInfo,
            std::vector<void *> *memoryToFree);

    void getVkRenderPassBeginInfo(
            JNIEnv *env,
            jobject jVkRenderPassBeginInfoObject,
            VkRenderPassBeginInfo *vkRenderPassBeginInfo,
            std::vector<void *> *memoryToFree);

    void getVkRect2D(
            JNIEnv *env,
            jobject jVkRect2DObject,
            VkRect2D *vkRect2D,
            std::vector<void *> *memoryToFree);

    void getVkClearValue(
            JNIEnv *env,
            jobject jVkClearValueObject,
            VkClearValue *vkClearValue,
            std::vector<void *> *memoryToFree);

    void getVkClearValueCollection(
            JNIEnv *env,
            const jobject VkClearValueCollectionObject,
            VkClearValue **vkClearValues,
            int *numberOfClearValues,
            std::vector<void *> *memoryToFree);

    void getVkSubmitInfo(
            JNIEnv *env,
            jobject jVkSubmitInfoObject,
            VkSubmitInfo *vkSubmitInfo,
            std::vector<void *> *memoryToFree);

    void getVkSubmitInfoCollection(
            JNIEnv *env,
            const jobject jVkSubmitInfoCollectionObject,
            VkSubmitInfo **vkSubmitInfos,
            int *numberOfVkSubmitInfos,
            std::vector<void *> *memoryToFree);

    void getVkSemaphoreCollection(
            JNIEnv *env,
            const jobject jVkSemaphoreCollectionObject,
            VkSemaphore **vkSemaphores,
            int *numberOfVkSemaphores,
            std::vector<void *> *memoryToFree);

    void getVkCommandBufferCollection(
            JNIEnv *env,
            const jobject jVkCommandBufferCollectionObject,
            VkCommandBuffer **vkCommandBuffers,
            int *numberOfVkCommandBuffers,
            std::vector<void *> *memoryToFree);

    void getVkPipelineStageFlagsCollection(
            JNIEnv *env,
            const jobject jVkPipelineStageFlagsCollectionObject,
            VkPipelineStageFlags **vkPipelineStageFlags,
            int *numberOfVkPipelineStageFlags,
            std::vector<void *> *memoryToFree);

    void getVkPresentInfoKHR(
            JNIEnv *env,
            jobject jVkPresentInfoKHRObject,
            VkPresentInfoKHR *vkPresentInfoKHR,
            jobject *jVkResultsCollectionObject,
            std::vector<void *> *memoryToFree);

    void getVkSwapchainKHRCollection(
            JNIEnv *env,
            const jobject jVkSwapchainKHRCollectionObject,
            VkSwapchainKHR **vkSwapchainKHR,
            int *numberOfVkSwapchainKHRs,
            std::vector<void *> *memoryToFree);

    void getVkBufferCreateInfo(
            JNIEnv *env,
            jobject jVkBufferCreateInfoObject,
            VkBufferCreateInfo *vkBufferCreateInfo,
            std::vector<void *> *memoryToFree);

    jobject getVkMemoryPropertyFlagsAsEnumSet(JNIEnv *env, VkMemoryPropertyFlags alphaFlags);

    jobject getVkMemoryHeapFlagsAsEnumSet(JNIEnv *env, VkMemoryHeapFlags memoryHeapFlags);

    void getVkMemoryAllocateInfo(
            JNIEnv *env,
            jobject jVkMemoryAllocateInfoObject,
            VkMemoryAllocateInfo *vkMemoryAllocateInfo,
            std::vector<void *> *memoryToFree);

    void getVkBufferCopyCollection(
            JNIEnv *env,
            const jobject jVkBufferCopyCollectionObject,
            VkBufferCopy **vkBufferCopies,
            int *numberOfVkSemaphores,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetLayoutCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutCreateInfoObject,
            VkDescriptorSetLayoutCreateInfo *vkDescriptorSetLayoutCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkSamplerCollection(
            JNIEnv *env,
            const jobject jVkSamplerCollectionObject,
            VkSampler **vkSamplers,
            int *numberOfVkSamplers,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetLayoutBinding(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutBindingObject,
            VkDescriptorSetLayoutBinding *vkDescriptorSetLayoutBinding,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetLayoutBindingCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutBindingCollectionObject,
            VkDescriptorSetLayoutBinding **vkDescriptorSetLayoutBindings,
            int *numberOfVkDescriptorSetLayoutBindings,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorPoolCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorPoolCreateInfoObject,
            VkDescriptorPoolCreateInfo *vkDescriptorPoolCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorPoolSizeCollection(
            JNIEnv *env,
            const jobject jVkDescriptorPoolSizeCollectionObject,
            VkDescriptorPoolSize **vkDescriptorPoolSizes,
            int *numberOfVkDescriptorPoolSizes,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorPoolSize(
            JNIEnv *env,
            const jobject jVkDescriptorPoolSizeObject,
            VkDescriptorPoolSize *vkDescriptorPoolSize,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetAllocateInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoCollectionObject,
            VkDescriptorSetAllocateInfo **vkDescriptorSetAllocateInfos,
            int *numberOfVkDescriptorSetAllocateInfos,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetAllocateInfo(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoObject,
            VkDescriptorSetAllocateInfo *vkDescriptorSetAllocateInfo,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetLayoutCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutCollectionObject,
            VkDescriptorSetLayout **vkDescriptorSetLayout,
            int *numberOfVkDescriptorSetLayouts,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorImageInfo(
            JNIEnv *env,
            const jobject jVkDescriptorImageInfoObject,
            VkDescriptorImageInfo *vkDescriptorImageInfo,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorImageInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorImageInfoCollectionObject,
            VkDescriptorImageInfo **vkDescriptorImageInfos,
            int *numberOfVkDescriptorImageInfos,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorBufferInfo(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoObject,
            VkDescriptorBufferInfo *vkDescriptorBufferInfo,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorBufferInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoCollectionObject,
            VkDescriptorBufferInfo **vkDescriptorBufferInfos,
            int *numberOfVkDescriptorBufferInfos,
            std::vector<void *> *memoryToFree);

    void getVkBufferViewCollection(
            JNIEnv *env,
            const jobject jVkBufferViewCollectionObject,
            VkBufferView **vkBufferView,
            int *numberOfVkBufferViews,
            std::vector<void *> *memoryToFree);

    void getVkWriteDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetCollectionObject,
            VkWriteDescriptorSet **vkWriteDescriptorSets,
            int *numberOfVkWriteDescriptorSets,
            std::vector<void *> *memoryToFree);

    void getVkWriteDescriptorSet(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetObject,
            VkWriteDescriptorSet *vkWriteDescriptorSet,
            std::vector<void *> *memoryToFree);

    void getVkCopyDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkCopyDescriptorSetCollectionObject,
            VkCopyDescriptorSet **vkCopyDescriptorSets,
            int *numberOfVkCopyDescriptorSets,
            std::vector<void *> *memoryToFree);

    void getVkCopyDescriptorSet(
            JNIEnv *env,
            jobject jVkCopyDescriptorSetObject,
            VkCopyDescriptorSet *vkCopyDescriptorSet,
            std::vector<void *> *memoryToFree);

    void getVkDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetCollectionObject,
            VkDescriptorSet **vkDescriptorSets,
            int *numberOfVkDescriptorSets,
            std::vector<void *> *memoryToFree);

    void getVkImageCreateInfo(
            JNIEnv *env,
            jobject jVkImageCreateInfoObject,
            VkImageCreateInfo *vkImageCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkMemoryBarrier(
            JNIEnv *env,
            const jobject jVkMemoryBarrierObject,
            VkMemoryBarrier *vkMemoryBarrier,
            std::vector<void *> *memoryToFree);

    void getVkMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkMemoryBarrierCollectionObject,
            VkMemoryBarrier **vkMemoryBarrier,
            int *numberOfVkMemoryBarriers,
            std::vector<void *> *memoryToFree);

    void getVkBufferMemoryBarrier(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierObject,
            VkBufferMemoryBarrier *vkBufferMemoryBarrier,
            std::vector<void *> *memoryToFree);

    void getVkBufferMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkBufferMemoryBarrierCollectionObject,
            VkBufferMemoryBarrier **vkBufferMemoryBarriers,
            int *numberOfVkBufferMemoryBarriers,
            std::vector<void *> *memoryToFree);

    void getVkImageSubresourceRange(
            JNIEnv *env,
            const jobject jVkImageSubresourceRangeObject,
            VkImageSubresourceRange *vkImageSubresourceRange,
            std::vector<void *> *memoryToFree);

    void getVkImageMemoryBarrier(
            JNIEnv *env,
            const jobject jVkImageMemoryBarrierObject,
            VkImageMemoryBarrier *vkImageMemoryBarrier,
            std::vector<void *> *memoryToFree);

    void getVkImageMemoryBarrierCollection(
            JNIEnv *env,
            const jobject jVkImageMemoryBarrierCollectionObject,
            VkImageMemoryBarrier **vkImageMemoryBarriers,
            int *numberOfVkImageMemoryBarriers,
            std::vector<void *> *memoryToFree);

    void getVkBufferImageCopy(
            JNIEnv *env,
            const jobject jVkBufferImageCopyObject,
            VkBufferImageCopy *vkBufferImageCopy,
            std::vector<void *> *memoryToFree);

    void getVkBufferImageCopyCollection(
            JNIEnv *env,
            const jobject jVkBufferImageCopyCollectionObject,
            VkBufferImageCopy **vkBufferImageCopies,
            int *numberOfVkBufferImageCopies,
            std::vector<void *> *memoryToFree);

    void getVkImageSubresourceLayers(
            JNIEnv *env,
            const jobject jVkImageSubresourceLayersObject,
            VkImageSubresourceLayers *vkImageSubresourceLayers,
            std::vector<void *> *memoryToFree);

    void getVkBufferImageCopy(
            JNIEnv *env,
            const jobject jVkBufferImageCopyObject,
            VkBufferImageCopy *vkBufferImageCopy,
            std::vector<void *> *memoryToFree);

    void getVkBufferImageCopyCollection(
            JNIEnv *env,
            const jobject jVkBufferImageCopyCollectionObject,
            VkBufferImageCopy **vkBufferImageCopies,
            int *numberOfVkBufferImageCopies,
            std::vector<void *> *memoryToFree);

    void getVkSamplerCreateInfo(
            JNIEnv *env,
            jobject jVkSamplerCreateInfoObject,
            VkSamplerCreateInfo *vkSamplerCreateInfo,
            std::vector<void *> *memoryToFree);

    jobject getVkFormatFeatureFlagsEnumSet(JNIEnv *env, VkFormatFeatureFlags alphaFlags);

    void getVkAttachmentDescription2KHR(
            JNIEnv *env,
            const jobject jVkAttachmentDescription2KHRObject,
            VkAttachmentDescription2KHR *vkAttachmentDescription2KHR,
            std::vector<void *> *memoryToFree);

    void getVkAttachmentDescription2KHRCollection(
            JNIEnv *env,
            const jobject jVkAttachmentDescription2KHRCollectionObject,
            VkAttachmentDescription2KHR **vkAttachmentDescription2KHRs,
            int *numberOfVkAttachmentDescription2KHRs,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDescription2KHR(
            JNIEnv *env,
            const jobject jVkSubpassDescription2KHRObject,
            VkSubpassDescription2KHR *vkSubpassDescription2KHR,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDescription2KHRCollection(
            JNIEnv *env,
            const jobject jVkSubpassDescription2KHRCollectionObject,
            VkSubpassDescription2KHR **vkSubpassDescription2KHRs,
            int *numberOfVkSubpassDescription2KHRs,
            std::vector<void *> *memoryToFree);

    void getVkAttachmentReference2KHR(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRObject,
            VkAttachmentReference2KHR *vkAttachmentReference2KHR,
            std::vector<void *> *memoryToFree);

    void getVkAttachmentReference2KHRCollection(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRCollectionObject,
            VkAttachmentReference2KHR **vkAttachmentReference2KHRs,
            int *numberOfVkAttachmentReference2KHRs,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDependency2KHR(
            JNIEnv *env,
            const jobject jVkSubpassDependency2KHRObject,
            VkSubpassDependency2KHR *vkSubpassDependency2KHR,
            std::vector<void *> *memoryToFree);

    void getVkSubpassDependency2KHRCollection(
            JNIEnv *env,
            const jobject jVkSubpassDependency2KHRCollectionObject,
            VkSubpassDependency2KHR **vkSubpassDependency2KHRs,
            int *numberOfVkSubpassDependency2KHRs,
            std::vector<void *> *memoryToFree);

    void getBitSetCollection(
            JNIEnv *env,
            const jobject jBitSetCollectionObject,
            uint32_t **outputBitMasks,
            int *numberOfOutputBitMasks,
            std::vector<void *> *memoryToFree);

    void getVkRenderPassCreateInfo2KHR(
            JNIEnv *env,
            jobject jVkRenderPassCreateInfo2KHRObject,
            VkRenderPassCreateInfo2KHR *vkRenderPassCreateInfo2KHR,
            std::vector<void *> *memoryToFree);

    void getVkAcquireNextImageInfoKHR(
            JNIEnv *env,
            jobject jVkAcquireNextImageInfoKHRObject,
            VkAcquireNextImageInfoKHR *vkAcquireNextImageInfoKHR,
            std::vector<void *> *memoryToFree);

    void getVkBindBufferMemoryInfo(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoObject,
            VkBindBufferMemoryInfo *vkBindBufferMemoryInfo,
            std::vector<void *> *memoryToFree);

    void getVkBindBufferMemoryInfoCollection(
            JNIEnv *env,
            const jobject jVkBindBufferMemoryInfoCollectionObject,
            VkBindBufferMemoryInfo **vkBindBufferMemoryInfo,
            int *numberOfVkBindBufferMemoryInfos,
            std::vector<void *> *memoryToFree);

    void getVkBindImageMemoryInfo(
            JNIEnv *env,
            const jobject jVkBindImageMemoryInfoObject,
            VkBindImageMemoryInfo *vkBindImageMemoryInfo,
            std::vector<void *> *memoryToFree);

    void getVkBindImageMemoryInfoCollection(
            JNIEnv *env,
            const jobject jVkBindImageMemoryInfoCollectionObject,
            VkBindImageMemoryInfo **vkBindImageMemoryInfo,
            int *numberOfVkBindImageMemoryInfos,
            std::vector<void *> *memoryToFree);

    void getVkBindAccelerationStructureMemoryInfoNV(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoNVObject,
            VkBindAccelerationStructureMemoryInfoNV *vkBindAccelerationStructureMemoryInfoNV,
            std::vector<void *> *memoryToFree);

    void getVkBindAccelerationStructureMemoryInfoNVCollection(
            JNIEnv *env,
            const jobject jVkBindAccelerationStructureMemoryInfoNVCollectionObject,
            VkBindAccelerationStructureMemoryInfoNV **vkBindAccelerationStructureMemoryInfoNVs,
            int *numberOfVkBindAccelerationStructureMemoryInfoNVs,
            std::vector<void *> *memoryToFree);

    void getVkAccelerationStructureCreateInfoNV(
            JNIEnv *env,
            jobject jVkAccelerationStructureCreateInfoNVObject,
            VkAccelerationStructureCreateInfoNV *vkAccelerationStructureCreateInfoNV,
            std::vector<void *> *memoryToFree);

    void getVkAccelerationStructureInfoNV(
            JNIEnv *env,
            jobject jVkAccelerationStructureInfoNVObject,
            VkAccelerationStructureInfoNV *vkAccelerationStructureInfoNV,
            std::vector<void *> *memoryToFree);

    void getVkGeometryNV(
            JNIEnv *env,
            const jobject jVkGeometryNVObject,
            VkGeometryNV *vkGeometryNV,
            std::vector<void *> *memoryToFree);

    void getVkGeometryNVCollection(
            JNIEnv *env,
            const jobject jVkGeometryNVCollectionObject,
            VkGeometryNV **vkGeometryNVs,
            int *numberOfVkGeometryNVs,
            std::vector<void *> *memoryToFree);

    void getVkGeometryDataNV(
            JNIEnv *env,
            const jobject jVkGeometryDataNVObject,
            VkGeometryDataNV *vkGeometryDataNV,
            std::vector<void *> *memoryToFree);

    void getVkGeometryTrianglesNV(
            JNIEnv *env,
            const jobject jVkGeometryTrianglesNVObject,
            VkGeometryTrianglesNV *vkGeometryTrianglesNV,
            std::vector<void *> *memoryToFree);

    void getVkGeometryAABBNV(
            JNIEnv *env,
            const jobject jVkGeometryAABBNVObject,
            VkGeometryAABBNV *vkGeometryAABBNV,
            std::vector<void *> *memoryToFree);

    void getVkBufferViewCreateInfo(
            JNIEnv *env,
            jobject jVkBufferViewCreateInfoObject,
            VkBufferViewCreateInfo *vkBufferViewCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkComputePipelineCreateInfoCollection(
            JNIEnv *env,
            const jobject jVkComputePipelineCreateInfoCollectionObject,
            VkComputePipelineCreateInfo **vkComputePipelineCreateInfos,
            int *numberOfCreateInfos,
            std::vector<void *> *memoryToFree);

    void getVkComputePipelineCreateInfo(
            JNIEnv *env,
            jobject jVkComputePipelineCreateInfoObject,
            VkComputePipelineCreateInfo *vkComputePipelineCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkDebugUtilsLabelEXT(
            JNIEnv *env,
            const jobject jVkDebugUtilsLabelEXT,
			VkDebugUtilsLabelEXT *vkDebugUtilsLabelEXT,
            std::vector<void *> *memoryToFree);

    void getVkDebugUtilsLabelEXTCollection(
            JNIEnv *env,
            const jobject jVkDebugUtilsLabelEXTCollectionObject,
			VkDebugUtilsLabelEXT **vkDebugUtilsLabels,
            int *numberOfVkDebugUtilsLabels,
            std::vector<void *> *memoryToFree);

	void getVkDebugUtilsMessengerCreateInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsMessengerCreateInfoEXTObject,
		VkDebugUtilsMessengerCreateInfoEXT *vkDebugUtilsMessengerCreateInfoEXT,
        std::vector<void *> *memoryToFree);

    jobject getVkDebugUtilsMessageTypeFlagsEXTAsEnumSet(JNIEnv *env, VkDebugUtilsMessageTypeFlagsEXT messageTypes);

    jobject getVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet(JNIEnv *env, VkDebugUtilsMessengerCallbackDataFlagsEXT flags);

    jobject createVkDebugUtilsMessageSeverityFlagBitsEXT(JNIEnv *env, jint value);

    jobject createVkDebugUtilsLabelEXT(JNIEnv *env, const VkDebugUtilsLabelEXT *labelData);

    jobject createVkDebugUtilsLabelEXTCollection(JNIEnv *env, int labelsCount, const VkDebugUtilsLabelEXT labels[]);

    jobject createVkDebugUtilsLabelEXT(JNIEnv *env, const VkDebugUtilsLabelEXT *labelData);

    jobject createVkDebugUtilsMessengerCallbackDataEXT(JNIEnv *env, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData);

    jobject createVkDebugUtilsObjectNameInfoEXT(JNIEnv *env, const VkDebugUtilsObjectNameInfoEXT *objectNameInfo);

    jobject createVkDebugUtilsObjectNameInfoEXTCollection(JNIEnv *env, int objectCount, const VkDebugUtilsObjectNameInfoEXT objects[]);

	void getVkDebugUtilsObjectNameInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsObjectNameInfoEXTObject,
		VkDebugUtilsObjectNameInfoEXT *vkDebugUtilsObjectNameInfoEXT,
        std::vector<void *> *memoryToFree);

    void getVkDebugUtilsObjectNameInfoEXTCollection(
            JNIEnv *env,
            const jobject jVkDebugUtilsObjectNameInfoEXTCollectionObject,
			VkDebugUtilsObjectNameInfoEXT **objects,
            int *numberOfObjectss,
            std::vector<void *> *memoryToFree);

    void getVkDebugUtilsObjectTagInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsObjectTagInfoEXTObject,
		VkDebugUtilsObjectTagInfoEXT *vkDebugUtilsObjectTagInfoEXT,
        std::vector<void *> *memoryToFree);

	void getvkDebugUtilsMessengerCallbackDataEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsMessengerCallbackDataEXTObject,
		VkDebugUtilsMessengerCallbackDataEXT *vkDebugUtilsMessengerCallbackDataEXT,
        std::vector<void *> *memoryToFree);

	void logClassName(JNIEnv *env, const jobject theObject);

    void getVkDescriptorUpdateTemplateCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorUpdateTemplateCreateInfoObject,
			VkDescriptorUpdateTemplateCreateInfo *vkDescriptorUpdateTemplateCreateInfo,
            std::vector<void *> *memoryToFree);

	void getVkDescriptorUpdateTemplateEntry(
        JNIEnv *env,
        const jobject jVkDescriptorUpdateTemplateEntryObject,
		VkDescriptorUpdateTemplateEntry *vkDescriptorUpdateTemplateEntry,
        std::vector<void *> *memoryToFree);

    void getVkDescriptorUpdateTemplateEntryCollection(
            JNIEnv *env,
            const jobject jVkDescriptorUpdateTemplateEntryCollectionObject,
			VkDescriptorUpdateTemplateEntry **vkDescriptorUpdateTemplateEntries,
            int *numberOfVkDescriptorUpdateTemplateEntries,
            std::vector<void *> *memoryToFree);

    void getVkDisplayModeCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkDisplayModeCreateInfoKHRObject,
			VkDisplayModeCreateInfoKHR *vkDisplayModeCreateInfoKHR,
            std::vector<void *> *memoryToFree);

    void getVkDisplayModeParametersKHR(
            JNIEnv *env,
            const jobject jVkDisplayModeParametersKHRObject,
			VkDisplayModeParametersKHR *vkDisplayModeParametersKHR,
            std::vector<void *> *memoryToFree);

    void getVkDisplaySurfaceCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkDisplaySurfaceCreateInfoKHRObject,
			VkDisplaySurfaceCreateInfoKHR *vkDisplaySurfaceCreateInfoKHR,
            std::vector<void *> *memoryToFree);

	void getVkInstanceCreateInfo(
        JNIEnv *env,
        const jobject jVkInstanceCreateInfoObject,
		VkInstanceCreateInfo *vkInstanceCreateInfo,
        std::vector<void *> *memoryToFree);

	void getVkApplicationInfo(
        JNIEnv *env,
        const jobject jVkApplicationInfoObject,
		VkApplicationInfo *vkApplicationInfo,
        std::vector<void *> *memoryToFree);

	jobject getpNextObject(
        JNIEnv *env,
        const jobject jVulkanCreateInfoStructureObject);

    void getStringCollection(
            JNIEnv *env,
            jobject jCollectionOfStrings,
            char ***stringArrayResult,
            int *numberOfStrings,
            std::vector<void *> *memoryToFree);

	void getpNextChain(
			JNIEnv *env,
			jobject jVulkanCreateInfoStructureObject,
			void  **headOfpNextChain,
			std::vector<void *> *memoryToFree);

	void getVkValidationFeaturesEXT(
		JNIEnv *env,
		const jobject jVkValidationFeaturesEXTObject,
		VkValidationFeaturesEXT *vkValidationFeaturesEXT,
		std::vector<void *> *memoryToFree);

    void getVkValidationFeatureEnableEXTCollection(
            JNIEnv *env,
            const jobject jVkValidationFeatureEnableEXTCollectionObject,
			VkValidationFeatureEnableEXT **vkValidationFeatureEnableEXTs,
            int *numberOfVkValidationFeatureEnableEXTs,
            std::vector<void *> *memoryToFree);

    void getVkValidationFeatureDisableEXTCollection(
            JNIEnv *env,
            const jobject jVkValidationFeatureDisableEXTCollectionObject,
			VkValidationFeatureDisableEXT **vkValidationFeatureDisableEXTs,
            int *numberOfVkValidationFeatureDisableEXTs,
            std::vector<void *> *memoryToFree);

	void getVkValidationFlagsEXT(
		JNIEnv *env,
		const jobject jVkValidationFlagsEXTObject,
		VkValidationFlagsEXT *vkValidationFlagsEXT,
		std::vector<void *> *memoryToFree);

	void getVkValidationCheckEXTCollection(
            JNIEnv *env,
            const jobject jVkValidationFlagsEXTCollectionObject,
			VkValidationCheckEXT **vkValidationCheckEXTs,
            int *numberOfVkValidationCheckEXTs,
            std::vector<void *> *memoryToFree);

	void createVkPhysicalDeviceProperties(
    		JNIEnv *env,
			jobject jVkPhysicalDevicePropertiesObject,
			const VkPhysicalDeviceProperties *vkPhysicalDeviceProperties);

	void populatepNextChain(
			JNIEnv *env,
			jobject jVulkanCreateInfoStructureObject,
			void  *headOfpNextChain,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject,
			const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceConservativeRasterizationPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceConservativeRasterizationPropertiesEXTObject,
			const VkPhysicalDeviceConservativeRasterizationPropertiesEXT* vkPhysicalDeviceConservativeRasterizationPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceShaderCorePropertiesAMD(
			JNIEnv *env,
			jobject jVkPhysicalDeviceShaderCorePropertiesAMDObject,
			const VkPhysicalDeviceShaderCorePropertiesAMD* vkPhysicalDeviceShaderCorePropertiesAMD,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceMultiviewProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMultiviewPropertiesObject,
			const VkPhysicalDeviceMultiviewProperties* vkPhysicalDeviceMultiviewProperties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceCooperativeMatrixPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceCooperativeMatrixPropertiesNVObject,
			const VkPhysicalDeviceCooperativeMatrixPropertiesNV* vkPhysicalDeviceCooperativeMatrixPropertiesNV,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDepthStencilResolvePropertiesKHRObject,
			const VkPhysicalDeviceDepthStencilResolvePropertiesKHR *vkPhysicalDeviceDepthStencilResolvePropertiesKHR,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceDescriptorIndexingPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDescriptorIndexingPropertiesEXTObject,
			const VkPhysicalDeviceDescriptorIndexingPropertiesEXT *vkPhysicalDeviceDescriptorIndexingPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceDiscardRectanglePropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDiscardRectanglePropertiesEXTObject,
			const VkPhysicalDeviceDiscardRectanglePropertiesEXT *vkPhysicalDeviceDiscardRectanglePropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceDriverPropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDeviceDriverPropertiesKHRObject,
			const VkPhysicalDeviceDriverPropertiesKHR *vkPhysicalDeviceDriverPropertiesKHR,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceExternalMemoryHostPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceExternalMemoryHostPropertiesEXTObject,
			const VkPhysicalDeviceExternalMemoryHostPropertiesEXT *vkPhysicalDeviceExternalMemoryHostPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceFloatControlsPropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFloatControlsPropertiesKHRObject,
			const VkPhysicalDeviceFloatControlsPropertiesKHR *vkPhysicalDeviceFloatControlsPropertiesKHR,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceFragmentDensityMapPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceFragmentDensityMapPropertiesEXTObject,
			const VkPhysicalDeviceFragmentDensityMapPropertiesEXT *vkPhysicalDeviceFragmentDensityMapPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceIDProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceIDPropertiesObject,
			const VkPhysicalDeviceIDProperties *vkPhysicalDeviceIDProperties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceInlineUniformBlockPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceInlineUniformBlockPropertiesEXTObject,
			const VkPhysicalDeviceInlineUniformBlockPropertiesEXT *vkPhysicalDeviceInlineUniformBlockPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceMaintenance3Properties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMaintenance3PropertiesObject,
			const VkPhysicalDeviceMaintenance3Properties *vkPhysicalDeviceMaintenance3Properties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceMeshShaderPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMeshShaderPropertiesNVObject,
			const VkPhysicalDeviceMeshShaderPropertiesNV *vkPhysicalDeviceMeshShaderPropertiesNV,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVXObject,
			const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDevicePCIBusInfoPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDevicePCIBusInfoPropertiesEXTObject,
			const VkPhysicalDevicePCIBusInfoPropertiesEXT *vkPhysicalDevicePCIBusInfoPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceProtectedMemoryProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceProtectedMemoryPropertiesObject,
			const VkPhysicalDeviceProtectedMemoryProperties *vkPhysicalDeviceProtectedMemoryProperties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDevicePointClippingProperties(
			JNIEnv *env,
			jobject jVkPhysicalDevicePointClippingPropertiesObject,
			const VkPhysicalDevicePointClippingProperties *vkPhysicalDevicePointClippingProperties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDevicePushDescriptorPropertiesKHR(
			JNIEnv *env,
			jobject jVkPhysicalDevicePushDescriptorPropertiesKHRObject,
			const VkPhysicalDevicePushDescriptorPropertiesKHR *vkPhysicalDevicePushDescriptorPropertiesKHR,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceRayTracingPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceRayTracingPropertiesNVObject,
			const VkPhysicalDeviceRayTracingPropertiesNV *vkPhysicalDeviceRayTracingPropertiesNV,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceSampleLocationsPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSampleLocationsPropertiesEXTObject,
			const VkPhysicalDeviceSampleLocationsPropertiesEXT *vkPhysicalDeviceSampleLocationsPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXTObject,
			const VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceShadingRateImagePropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceShadingRateImagePropertiesNVObject,
			const VkPhysicalDeviceShadingRateImagePropertiesNV *vkPhysicalDeviceShadingRateImagePropertiesNV,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceSubgroupProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSubgroupPropertiesObject,
			const VkPhysicalDeviceSubgroupProperties *vkPhysicalDeviceSubgroupProperties,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceTransformFeedbackPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject,
			const VkPhysicalDeviceTransformFeedbackPropertiesEXT *vkPhysicalDeviceTransformFeedbackPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceVertexAttributeDivisorPropertiesEXTObject,
			const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT,
			std::vector<void *> *memoryToFree);

	void populateVkPhysicalDeviceFeatures(
		JNIEnv *env,
		jobject jVkPhysicalDeviceFeaturesObject,
		const VkPhysicalDeviceFeatures *vkPhysicalDeviceFeatures,
		std::vector<void *> *memoryToFree);

	jobject getVkShaderStageFlagsAsEnumSet(JNIEnv *env, VkShaderStageFlags vkShaderStageFlags);

    jobject getVkResolveModeFlagsKHRAsEnumSet(JNIEnv *env, VkResolveModeFlagsKHR vkResolveModeFlagsKHR);

	jobject createVkConformanceVersionKHR(JNIEnv *env, const VkConformanceVersionKHR *vkConformanceVersionKHR);

	jobject createVkExtent2D(JNIEnv *env, const VkExtent2D *vkExtent2D);

    jobject getVkSampleCountFlagsAsEnumSet(JNIEnv *env, VkSampleCountFlags vkSampleCountFlags);

    jobject getVkSubgroupFeatureFlagsAsEnumSet(JNIEnv *env, VkSubgroupFeatureFlags vkSubgroupFeatureFlags);

    void getVkPhysicalDeviceCollection(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceCollectionObject,
			VkPhysicalDevice **vkPhysicalDevices,
            int *numberOfVkPhysicalDevices,
            std::vector<void *> *memoryToFree);

    void getVkDeviceGroupDeviceCreateInfo(
            JNIEnv *env,
            jobject jVkDeviceGroupDeviceCreateInfoObject,
			VkDeviceGroupDeviceCreateInfo *vkDeviceGroupDeviceCreateInfo,
            std::vector<void *> *memoryToFree);

    void getVkDeviceMemoryOverallocationCreateInfoAMD(
            JNIEnv *env,
            jobject jVkDeviceMemoryOverallocationCreateInfoAMDObject,
			VkDeviceMemoryOverallocationCreateInfoAMD *vkDeviceMemoryOverallocationCreateInfoAMD,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDevice16BitStorageFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDevice16BitStorageFeaturesObject,
			VkPhysicalDevice16BitStorageFeatures *vkPhysicalDevice16BitStorageFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDevice8BitStorageFeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDevice8BitStorageFeaturesKHRObject,
			VkPhysicalDevice8BitStorageFeaturesKHR *vkPhysicalDevice8BitStorageFeaturesKHR,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceASTCDecodeFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceASTCDecodeFeaturesEXTObject,
			VkPhysicalDeviceASTCDecodeFeaturesEXT *vkPhysicalDeviceASTCDecodeFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceBlendOperationAdvancedFeaturesEXTObject,
			VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *vkPhysicalDeviceBlendOperationAdvancedFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceBufferDeviceAddressFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceBufferDeviceAddressFeaturesEXTObject,
			VkPhysicalDeviceBufferDeviceAddressFeaturesEXT *vkPhysicalDeviceBufferDeviceAddressFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceComputeShaderDerivativesFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceComputeShaderDerivativesFeaturesNVObject,
			VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *vkPhysicalDeviceComputeShaderDerivativesFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceConditionalRenderingFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceConditionalRenderingFeaturesEXTObject,
			VkPhysicalDeviceConditionalRenderingFeaturesEXT *vkPhysicalDeviceConditionalRenderingFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceCooperativeMatrixFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceCooperativeMatrixFeaturesNVObject,
			VkPhysicalDeviceCooperativeMatrixFeaturesNV *vkPhysicalDeviceCooperativeMatrixFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceCornerSampledImageFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceCornerSampledImageFeaturesNVObject,
			VkPhysicalDeviceCornerSampledImageFeaturesNV *vkPhysicalDeviceCornerSampledImageFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNVObject,
			VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV *vkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceDepthClipEnableFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceDepthClipEnableFeaturesEXTObject,
			VkPhysicalDeviceDepthClipEnableFeaturesEXT *vkPhysicalDeviceDepthClipEnableFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceDescriptorIndexingFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject,
			VkPhysicalDeviceDescriptorIndexingFeaturesEXT *vkPhysicalDeviceDescriptorIndexingFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceExclusiveScissorFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceExclusiveScissorFeaturesNVObject,
			VkPhysicalDeviceExclusiveScissorFeaturesNV *vkPhysicalDeviceExclusiveScissorFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceFeatures2(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceFeatures2Object,
			VkPhysicalDeviceFeatures2 *vkPhysicalDeviceFeatures2,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceFloat16Int8FeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceFloat16Int8FeaturesKHRObject,
			VkPhysicalDeviceFloat16Int8FeaturesKHR *vkPhysicalDeviceFloat16Int8FeaturesKHR,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceFragmentDensityMapFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceFragmentDensityMapFeaturesEXTObject,
			VkPhysicalDeviceFragmentDensityMapFeaturesEXT *vkPhysicalDeviceFragmentDensityMapFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceFragmentShaderBarycentricFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceFragmentShaderBarycentricFeaturesNVObject,
			VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV *vkPhysicalDeviceFragmentShaderBarycentricFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceHostQueryResetFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceHostQueryResetFeaturesEXTObject,
			VkPhysicalDeviceHostQueryResetFeaturesEXT *vkPhysicalDeviceHostQueryResetFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceInlineUniformBlockFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceInlineUniformBlockFeaturesEXTObject,
			VkPhysicalDeviceInlineUniformBlockFeaturesEXT *vkPhysicalDeviceInlineUniformBlockFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceMemoryPriorityFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceMemoryPriorityFeaturesEXTObject,
			VkPhysicalDeviceMemoryPriorityFeaturesEXT *vkPhysicalDeviceMemoryPriorityFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceMeshShaderFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceMeshShaderFeaturesNVObject,
			VkPhysicalDeviceMeshShaderFeaturesNV *vkPhysicalDeviceMeshShaderFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceMultiviewFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceMultiviewFeaturesObject,
			VkPhysicalDeviceMultiviewFeatures *vkPhysicalDeviceMultiviewFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceProtectedMemoryFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceProtectedMemoryFeaturesObject,
			VkPhysicalDeviceProtectedMemoryFeatures *vkPhysicalDeviceProtectedMemoryFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceRepresentativeFragmentTestFeaturesNVObject,
			VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV *vkPhysicalDeviceRepresentativeFragmentTestFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceSamplerYcbcrConversionFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceSamplerYcbcrConversionFeaturesObject,
			VkPhysicalDeviceSamplerYcbcrConversionFeatures *vkPhysicalDeviceSamplerYcbcrConversionFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceScalarBlockLayoutFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceScalarBlockLayoutFeaturesEXTObject,
			VkPhysicalDeviceScalarBlockLayoutFeaturesEXT *vkPhysicalDeviceScalarBlockLayoutFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceShaderAtomicInt64FeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject,
			VkPhysicalDeviceShaderAtomicInt64FeaturesKHR *vkPhysicalDeviceShaderAtomicInt64FeaturesKHR,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceShaderDrawParametersFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceShaderDrawParametersFeaturesObject,
			VkPhysicalDeviceShaderDrawParametersFeatures *vkPhysicalDeviceShaderDrawParametersFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceShaderImageFootprintFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceShaderImageFootprintFeaturesNVObject,
			VkPhysicalDeviceShaderImageFootprintFeaturesNV *vkPhysicalDeviceShaderImageFootprintFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceShadingRateImageFeaturesNV(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceShadingRateImageFeaturesNVObject,
			VkPhysicalDeviceShadingRateImageFeaturesNV *vkPhysicalDeviceShadingRateImageFeaturesNV,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceTransformFeedbackFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceTransformFeedbackFeaturesEXTObject,
			VkPhysicalDeviceTransformFeedbackFeaturesEXT *vkPhysicalDeviceTransformFeedbackFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceVariablePointersFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceVariablePointersFeaturesObject,
			VkPhysicalDeviceVariablePointersFeatures *vkPhysicalDeviceVariablePointersFeatures,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceVertexAttributeDivisorFeaturesEXTObject,
			VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceVulkanMemoryModelFeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceVulkanMemoryModelFeaturesKHRObject,
			VkPhysicalDeviceVulkanMemoryModelFeaturesKHR *vkPhysicalDeviceVulkanMemoryModelFeaturesKHR,
            std::vector<void *> *memoryToFree);

    void getVkPhysicalDeviceYcbcrImageArraysFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceYcbcrImageArraysFeaturesEXTObject,
			VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *vkPhysicalDeviceYcbcrImageArraysFeaturesEXT,
            std::vector<void *> *memoryToFree);

//    void getVkD3D12FenceSubmitInfoKHR(
//            JNIEnv *env,
//            const jobject jVkD3D12FenceSubmitInfoKHRObject,
//			VkD3D12FenceSubmitInfoKHR *vkD3D12FenceSubmitInfoKHR,
//            std::vector<void *> *memoryToFree);

    void getVkDeviceGroupSubmitInfo(
            JNIEnv *env,
            const jobject jVkDeviceGroupSubmitInfoObject,
			VkDeviceGroupSubmitInfo *vkDeviceGroupSubmitInfo,
            std::vector<void *> *memoryToFree);

    void getVkProtectedSubmitInfo(
            JNIEnv *env,
            const jobject jVkProtectedSubmitInfoObject,
			VkProtectedSubmitInfo *vkProtectedSubmitInfo,
            std::vector<void *> *memoryToFree);

    void getVkExportFenceCreateInfo(
            JNIEnv *env,
            const jobject jVkExportFenceCreateInfoObject,
			VkExportFenceCreateInfo *vkExportFenceCreateInfo,
            std::vector<void *> *memoryToFree);
}

#endif /* STRUCTUREHELPERFUNCTIONS_HH_ */
