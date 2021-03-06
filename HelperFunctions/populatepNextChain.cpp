/*
 * Copyright 2019-2020 Douglas Kaip
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
 * populatepNextChain.cpp
 *
 *  Created on: May 12, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	/*
	 * This function is kind of the inverse of the getpNextChain function in that
	 * this will take objects that are on the pNext chain in the LunarG world
	 * and create the appropriate Java objects for them.
	 */
	void populatepNextChain(
			JNIEnv *env,
			jobject jVulkanCreateInfoStructureObject,
			void  *headOfpNextChain,
			std::vector<void *> *memoryToFree)
	{
		if (headOfpNextChain == nullptr)
		{
			// If it is null we cannot do anything
			LOGTRACE(env, "%s", "headOfpNextChain is nullptr...nothing to do");
			return;
		}

		VkStructureType sType = ((VkBaseOutStructure *)headOfpNextChain)->sType;
		switch(sType)
		{
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT");
				populateVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT");
				populateVkPhysicalDeviceConservativeRasterizationPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceConservativeRasterizationPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceConservativeRasterizationPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD");
				populateVkPhysicalDeviceShaderCorePropertiesAMD(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceShaderCorePropertiesAMD *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceShaderCorePropertiesAMD.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES");
				populateVkPhysicalDeviceMultiviewProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceMultiviewProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceMultiviewProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV");
				populateVkPhysicalDeviceCooperativeMatrixPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceCooperativeMatrixPropertiesNV *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceCooperativeMatrixPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES");
				populateVkPhysicalDeviceDepthStencilResolveProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDepthStencilResolveProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDepthStencilResolveProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES");
				populateVkPhysicalDeviceDescriptorIndexingProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDescriptorIndexingProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDepthStencilResolveProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT");
				populateVkPhysicalDeviceDiscardRectanglePropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDiscardRectanglePropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDiscardRectanglePropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES");
				populateVkPhysicalDeviceDriverProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDriverProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDriverProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT");
				populateVkPhysicalDeviceExternalMemoryHostPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceExternalMemoryHostPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceExternalMemoryHostPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES");
				populateVkPhysicalDeviceFloatControlsProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceFloatControlsProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFloatControlsProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT");
				populateVkPhysicalDeviceFragmentDensityMapPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceFragmentDensityMapPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFragmentDensityMapPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES");
				populateVkPhysicalDeviceIDProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceIDProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceIDProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT");
				populateVkPhysicalDeviceInlineUniformBlockPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceInlineUniformBlockPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceInlineUniformBlockPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES");
				populateVkPhysicalDeviceMaintenance3Properties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceMaintenance3Properties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceMaintenance3Properties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV");
				populateVkPhysicalDeviceMeshShaderPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceMeshShaderPropertiesNV *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceMeshShaderPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX");
				populateVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT");
				populateVkPhysicalDevicePCIBusInfoPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDevicePCIBusInfoPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDevicePCIBusInfoPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES");
				populateVkPhysicalDevicePointClippingProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDevicePointClippingProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDevicePointClippingProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES");
				populateVkPhysicalDeviceProtectedMemoryProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceProtectedMemoryProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceProtectedMemoryProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR");
				populateVkPhysicalDevicePushDescriptorPropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDevicePushDescriptorPropertiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceProtectedMemoryProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV");
				populateVkPhysicalDeviceRayTracingPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceRayTracingPropertiesNV *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceRayTracingPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT");
				populateVkPhysicalDeviceSampleLocationsPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceSampleLocationsPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceSampleLocationsPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES");
				populateVkPhysicalDeviceSamplerFilterMinmaxProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceSamplerFilterMinmaxProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceSamplerFilterMinmaxProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV");
				populateVkPhysicalDeviceShadingRateImagePropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceShadingRateImagePropertiesNV *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceShadingRateImagePropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES");
				populateVkPhysicalDeviceSubgroupProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceSubgroupProperties *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceSubgroupProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT");
				populateVkPhysicalDeviceTransformFeedbackPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceTransformFeedbackPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceTransformFeedbackPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT");
				populateVkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceVertexAttributeDivisorPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT");
				populateVkPipelineCreationFeedbackCreateInfoEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPipelineCreationFeedbackCreateInfoEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPipelineCreationFeedbackCreateInfoEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD");
				populateVkDisplayNativeHdrSurfaceCapabilitiesAMD(
						env,
						jVulkanCreateInfoStructureObject,
						(VkDisplayNativeHdrSurfaceCapabilitiesAMD *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkDisplayNativeHdrSurfaceCapabilitiesAMD.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR");
				populateVkSharedPresentSurfaceCapabilitiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkSharedPresentSurfaceCapabilitiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkSharedPresentSurfaceCapabilitiesKHR.");
					return;
				}
				break;
//			case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
//				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT");
//				populateVkSurfaceCapabilitiesFullScreenExclusiveEXT(
//						env,
//						jVulkanCreateInfoStructureObject,
//						(VkSurfaceCapabilitiesFullScreenExclusiveEXT *)headOfpNextChain,
//						memoryToFree);
//				if (env->ExceptionOccurred())
//				{
//					LOGERROR(env, "%s", "Error calling populateVkSurfaceCapabilitiesFullScreenExclusiveEXT.");
//					return;
//				}
//				break;
			case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR");
				populateVkSurfaceProtectedCapabilitiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkSurfaceProtectedCapabilitiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkSurfaceProtectedCapabilitiesKHR.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO");
				populateVkPhysicalDeviceExternalImageFormatInfo(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceExternalImageFormatInfo *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceExternalImageFormatInfo.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT");
				populateVkPhysicalDeviceImageDrmFormatModifierInfoEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceImageDrmFormatModifierInfoEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT");
				populateVkPhysicalDeviceImageViewImageFormatInfoEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceImageViewImageFormatInfoEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceImageViewImageFormatInfoEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT");
				populateVkFilterCubicImageViewImageFormatPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkFilterCubicImageViewImageFormatPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkFilterCubicImageViewImageFormatPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS");
				populateVkMemoryDedicatedRequirements(
						env,
						jVulkanCreateInfoStructureObject,
						(VkMemoryDedicatedRequirements *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkMemoryDedicatedRequirements.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT");
				populateVkPhysicalDeviceMemoryBudgetPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceMemoryBudgetPropertiesEXT *)headOfpNextChain,
						nullptr);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceMemoryBudgetPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV");
				populateVkQueueFamilyCheckpointPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkQueueFamilyCheckpointPropertiesNV *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkQueueFamilyCheckpointPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT");
				populateVkPhysicalDeviceCustomBorderColorPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceCustomBorderColorPropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceCustomBorderColorPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV");
				populateVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT");
				populateVkPhysicalDeviceFragmentDensityMap2PropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFragmentDensityMap2PropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT");
				populateVkPhysicalDeviceLineRasterizationPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceLineRasterizationPropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceLineRasterizationPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR");
				populateVkPhysicalDevicePerformanceQueryPropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDevicePerformanceQueryPropertiesKHR *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling VkPhysicalDevicePerformanceQueryPropertiesKHR.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_KHR");
				populateVkPhysicalDeviceRayTracingPropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceRayTracingPropertiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceRayTracingPropertiesKHR.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT");
				populateVkPhysicalDeviceRobustness2PropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceRobustness2PropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceRobustness2PropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD");
				populateVkPhysicalDeviceShaderCoreProperties2AMD(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceShaderCoreProperties2AMD *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceShaderCoreProperties2AMD.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV");
				populateVkPhysicalDeviceShaderSMBuiltinsPropertiesNV(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceShaderSMBuiltinsPropertiesNV.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT");
				populateVkPhysicalDeviceSubgroupSizeControlPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceSubgroupSizeControlPropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceSubgroupSizeControlPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT");
				populateVkPhysicalDeviceTexelBufferAlignmentPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceTexelBufferAlignmentPropertiesEXT.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES");
				populateVkPhysicalDeviceTimelineSemaphoreProperties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceTimelineSemaphoreProperties *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceTimelineSemaphoreProperties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES");
				populateVkPhysicalDeviceVulkan11Properties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceVulkan11Properties *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceVulkan11Properties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES");
				populateVkPhysicalDeviceVulkan12Properties(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceVulkan12Properties *)headOfpNextChain);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceVulkan12Properties.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
				/*
				 *  This should not be in the pNext chain except for the first
				 *  position.  There is not processing for this other than
				 *  looking for other pNext chain elements.
				 */
				break;
			case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
				/*
				 *  This should not be in the pNext chain except for the first
				 *  position.  There is not processing for this other than
				 *  looking for other pNext chain elements.
				 */
				break;
			default:
				LOGWARN(env, "Unhandled sType of %d", sType);
				break;
		}

		void *pNext = ((VkBaseOutStructure *)headOfpNextChain)->pNext;

        jobject jpNextObject = getpNextObject(env, jVulkanCreateInfoStructureObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNextObject failed.");
            return;
        }

		if (pNext == nullptr && jpNextObject == nullptr)
			return;
		else if (pNext != nullptr && jpNextObject == nullptr)
		{
			LOGERROR(env, "%s", "pNext was not null and jpNextObject was");
			return;
		}
		else if (pNext == nullptr && jpNextObject != nullptr)
		{
			LOGERROR(env, "%s", "pNext was null and jpNextObject was not null");
			return;
		}

		/*
		 * It appears there is at least one more pNext structure.
		 */
		populatepNextChain(
				env,
				jpNextObject,
				pNext,
				memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Recusive call to populatepNextChain failed.");
            return;
        }

		return;
	}

}
