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
 * populatepNextChain.cpp
 *
 *  Created on: May 12, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	struct InfoStructure
	{
		VkStructureType  sType;
		void			*pNext;
	};

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

		VkStructureType sType = ((struct InfoStructure *)headOfpNextChain)->sType;
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
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR");
				populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDepthStencilResolvePropertiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR.");
					return;
				}
				break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT");
				populateVkPhysicalDeviceDescriptorIndexingPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDescriptorIndexingPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDepthStencilResolvePropertiesKHR.");
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
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR");
				populateVkPhysicalDeviceDriverPropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceDriverPropertiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceDriverPropertiesKHR.");
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
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR");
				populateVkPhysicalDeviceFloatControlsPropertiesKHR(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceFloatControlsPropertiesKHR *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceFloatControlsPropertiesKHR.");
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
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
				LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT");
				populateVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT(
						env,
						jVulkanCreateInfoStructureObject,
						(VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *)headOfpNextChain,
						memoryToFree);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Error calling populateVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT.");
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
			default:
				LOGWARN(env, "Unhandled sType of %d", sType);
				break;
		}

		void *pNext = ((struct InfoStructure *)headOfpNextChain)->pNext;

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
