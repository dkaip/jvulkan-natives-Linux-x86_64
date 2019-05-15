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
 * getpNextChain.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	/*
	 * The purpose of this function is to "run" the pNext chain of Java
	 * VulkanCreateInfoStructure objects and return a "chain" of LunarG SDK
	 * Vulkan objects.
	 */
	void getpNextChain(
			JNIEnv *env,
			jobject jVulkanCreateInfoStructureObject,
			void  **headOfpNextChain,
			std::vector<void *> *memoryToFree)
	{
        ////////////////////////////////////////////////////////////////////////
		VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVulkanCreateInfoStructureObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        switch(sTypeValue)
        {
			case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT");

	        	VkValidationFeaturesEXT *vkValidationFeaturesEXT = (VkValidationFeaturesEXT *)calloc(1, sizeof(VkValidationFeaturesEXT));
	        	memoryToFree->push_back(vkValidationFeaturesEXT);
	        	vkValidationFeaturesEXT->sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;

	        	getVkValidationFeaturesEXT(
	                env,
					jVulkanCreateInfoStructureObject,
					vkValidationFeaturesEXT,
	                memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkValidationFeaturesEXT");
	                return;
	            }

	            *headOfpNextChain = vkValidationFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT");

	        	VkValidationFlagsEXT *vkValidationFlagsEXT = (VkValidationFlagsEXT *)calloc(1, sizeof(VkValidationFlagsEXT));
	        	memoryToFree->push_back(vkValidationFlagsEXT);
	        	vkValidationFlagsEXT->sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;

	        	getVkValidationFlagsEXT(
	                env,
					jVulkanCreateInfoStructureObject,
					vkValidationFlagsEXT,
	                memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkValidationFlagsEXT");
	                return;
	            }

	            *headOfpNextChain = vkValidationFlagsEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT");

	        	VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT = (VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT);
	        	vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;

	        	getVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
	                env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
	                memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT");

	        	VkPhysicalDeviceConservativeRasterizationPropertiesEXT *vkPhysicalDeviceConservativeRasterizationPropertiesEXT = (VkPhysicalDeviceConservativeRasterizationPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceConservativeRasterizationPropertiesEXT);
	        	vkPhysicalDeviceConservativeRasterizationPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;

	        	getVkPhysicalDeviceConservativeRasterizationPropertiesEXT(
	                env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceConservativeRasterizationPropertiesEXT,
	                memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceConservativeRasterizationPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceConservativeRasterizationPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD");

	        	VkPhysicalDeviceShaderCorePropertiesAMD *vkPhysicalDeviceShaderCorePropertiesAMD = (VkPhysicalDeviceShaderCorePropertiesAMD *)calloc(1, sizeof(VkPhysicalDeviceShaderCorePropertiesAMD));
	        	memoryToFree->push_back(vkPhysicalDeviceShaderCorePropertiesAMD);
	        	vkPhysicalDeviceShaderCorePropertiesAMD->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;

	        	getVkPhysicalDeviceShaderCorePropertiesAMD(
	                env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceShaderCorePropertiesAMD,
	                memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceShaderCorePropertiesAMD");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShaderCorePropertiesAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES");

	        	VkPhysicalDeviceMultiviewProperties *vkPhysicalDeviceMultiviewProperties = (VkPhysicalDeviceMultiviewProperties *)calloc(1, sizeof(VkPhysicalDeviceMultiviewProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceMultiviewProperties);
	        	vkPhysicalDeviceMultiviewProperties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES;

	        	getVkPhysicalDeviceMultiviewProperties(
	        		env,
					jVulkanCreateInfoStructureObject,
	        		vkPhysicalDeviceMultiviewProperties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMultiviewProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMultiviewProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV");

	        	VkPhysicalDeviceCooperativeMatrixPropertiesNV *vkPhysicalDeviceCooperativeMatrixPropertiesNV = (VkPhysicalDeviceCooperativeMatrixPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceCooperativeMatrixPropertiesNV);
	        	vkPhysicalDeviceCooperativeMatrixPropertiesNV->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;

	        	getVkPhysicalDeviceCooperativeMatrixPropertiesNV(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceCooperativeMatrixPropertiesNV,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMultiviewProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceCooperativeMatrixPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR");

	        	VkPhysicalDeviceDepthStencilResolvePropertiesKHR *vkPhysicalDeviceDepthStencilResolvePropertiesKHR = (VkPhysicalDeviceDepthStencilResolvePropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceDepthStencilResolvePropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceDepthStencilResolvePropertiesKHR);
	        	vkPhysicalDeviceDepthStencilResolvePropertiesKHR->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR;

	        	getVkPhysicalDeviceDepthStencilResolvePropertiesKHR(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceDepthStencilResolvePropertiesKHR,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMultiviewProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDepthStencilResolvePropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT");

	        	VkPhysicalDeviceDescriptorIndexingPropertiesEXT *vkPhysicalDeviceDescriptorIndexingPropertiesEXT = (VkPhysicalDeviceDescriptorIndexingPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceDescriptorIndexingPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDescriptorIndexingPropertiesEXT);
	        	vkPhysicalDeviceDescriptorIndexingPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT;

	        	getVkPhysicalDeviceDescriptorIndexingPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceDescriptorIndexingPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMultiviewProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDescriptorIndexingPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT");

	        	VkPhysicalDeviceDiscardRectanglePropertiesEXT *vkPhysicalDeviceDiscardRectanglePropertiesEXT = (VkPhysicalDeviceDiscardRectanglePropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDiscardRectanglePropertiesEXT);
	        	vkPhysicalDeviceDiscardRectanglePropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;

	        	getVkPhysicalDeviceDiscardRectanglePropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceDiscardRectanglePropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceDiscardRectanglePropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDiscardRectanglePropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR");

	        	VkPhysicalDeviceDriverPropertiesKHR *vkPhysicalDeviceDriverPropertiesKHR = (VkPhysicalDeviceDriverPropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceDriverPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceDriverPropertiesKHR);
	        	vkPhysicalDeviceDriverPropertiesKHR->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR;

	        	getVkPhysicalDeviceDriverPropertiesKHR(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceDriverPropertiesKHR,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceDriverPropertiesKHR");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDriverPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT");

	        	VkPhysicalDeviceExternalMemoryHostPropertiesEXT *vkPhysicalDeviceExternalMemoryHostPropertiesEXT = (VkPhysicalDeviceExternalMemoryHostPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceExternalMemoryHostPropertiesEXT);
	        	vkPhysicalDeviceExternalMemoryHostPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;

	        	getVkPhysicalDeviceExternalMemoryHostPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceExternalMemoryHostPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceExternalMemoryHostPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceExternalMemoryHostPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR");

	        	VkPhysicalDeviceFloatControlsPropertiesKHR *vkPhysicalDeviceFloatControlsPropertiesKHR = (VkPhysicalDeviceFloatControlsPropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceFloatControlsPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceFloatControlsPropertiesKHR);
	        	vkPhysicalDeviceFloatControlsPropertiesKHR->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR;

	        	getVkPhysicalDeviceFloatControlsPropertiesKHR(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceFloatControlsPropertiesKHR,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceFloatControlsPropertiesKHR");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFloatControlsPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT");

	        	VkPhysicalDeviceFragmentDensityMapPropertiesEXT *vkPhysicalDeviceFragmentDensityMapPropertiesEXT = (VkPhysicalDeviceFragmentDensityMapPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceFragmentDensityMapPropertiesEXT);
	        	vkPhysicalDeviceFragmentDensityMapPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;

	        	getVkPhysicalDeviceFragmentDensityMapPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceFragmentDensityMapPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceFragmentDensityMapPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFragmentDensityMapPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES");

	        	VkPhysicalDeviceIDProperties *vkPhysicalDeviceIDProperties = (VkPhysicalDeviceIDProperties *)calloc(1, sizeof(VkPhysicalDeviceIDProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceIDProperties);
	        	vkPhysicalDeviceIDProperties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES;

	        	getVkPhysicalDeviceIDProperties(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceIDProperties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceIDProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceIDProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT");

	        	VkPhysicalDeviceInlineUniformBlockPropertiesEXT *vkPhysicalDeviceInlineUniformBlockPropertiesEXT = (VkPhysicalDeviceInlineUniformBlockPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceInlineUniformBlockPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceInlineUniformBlockPropertiesEXT);
	        	vkPhysicalDeviceInlineUniformBlockPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;

	        	getVkPhysicalDeviceInlineUniformBlockPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceInlineUniformBlockPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceInlineUniformBlockPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceInlineUniformBlockPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES");

	        	VkPhysicalDeviceMaintenance3Properties *vkPhysicalDeviceMaintenance3Properties = (VkPhysicalDeviceMaintenance3Properties *)calloc(1, sizeof(VkPhysicalDeviceMaintenance3Properties));
	        	memoryToFree->push_back(vkPhysicalDeviceMaintenance3Properties);
	        	vkPhysicalDeviceMaintenance3Properties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES;

	        	getVkPhysicalDeviceMaintenance3Properties(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceMaintenance3Properties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMaintenance3Properties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMaintenance3Properties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV");

	        	VkPhysicalDeviceMeshShaderPropertiesNV *vkPhysicalDeviceMeshShaderPropertiesNV = (VkPhysicalDeviceMeshShaderPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceMeshShaderPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceMeshShaderPropertiesNV);
	        	vkPhysicalDeviceMeshShaderPropertiesNV->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;

	        	getVkPhysicalDeviceMeshShaderPropertiesNV(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceMeshShaderPropertiesNV,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMeshShaderPropertiesNV");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMeshShaderPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX");

	        	VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = (VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *)calloc(1, sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX));
	        	memoryToFree->push_back(vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);
	        	vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;

	        	getVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT");

	        	VkPhysicalDevicePCIBusInfoPropertiesEXT *vkPhysicalDevicePCIBusInfoPropertiesEXT = (VkPhysicalDevicePCIBusInfoPropertiesEXT *)calloc(1, sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDevicePCIBusInfoPropertiesEXT);
	        	vkPhysicalDevicePCIBusInfoPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;

	        	getVkPhysicalDevicePCIBusInfoPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDevicePCIBusInfoPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDevicePCIBusInfoPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDevicePCIBusInfoPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES");

	        	VkPhysicalDevicePointClippingProperties *vkPhysicalDevicePointClippingProperties = (VkPhysicalDevicePointClippingProperties *)calloc(1, sizeof(VkPhysicalDevicePointClippingProperties));
	        	memoryToFree->push_back(vkPhysicalDevicePointClippingProperties);
	        	vkPhysicalDevicePointClippingProperties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES;

	        	getVkPhysicalDevicePointClippingProperties(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDevicePointClippingProperties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDevicePointClippingProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDevicePointClippingProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES");

	        	VkPhysicalDeviceProtectedMemoryProperties *vkPhysicalDeviceProtectedMemoryProperties = (VkPhysicalDeviceProtectedMemoryProperties *)calloc(1, sizeof(VkPhysicalDeviceProtectedMemoryProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceProtectedMemoryProperties);
	        	vkPhysicalDeviceProtectedMemoryProperties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES;

	        	getVkPhysicalDeviceProtectedMemoryProperties(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceProtectedMemoryProperties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceProtectedMemoryProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceProtectedMemoryProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR");

	        	VkPhysicalDevicePushDescriptorPropertiesKHR *vkPhysicalDevicePushDescriptorPropertiesKHR = (VkPhysicalDevicePushDescriptorPropertiesKHR *)calloc(1, sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDevicePushDescriptorPropertiesKHR);
	        	vkPhysicalDevicePushDescriptorPropertiesKHR->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;

	        	getVkPhysicalDevicePushDescriptorPropertiesKHR(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDevicePushDescriptorPropertiesKHR,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDevicePushDescriptorPropertiesKHR");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDevicePushDescriptorPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV");

	        	VkPhysicalDeviceRayTracingPropertiesNV *vkPhysicalDeviceRayTracingPropertiesNV = (VkPhysicalDeviceRayTracingPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceRayTracingPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceRayTracingPropertiesNV);
	        	vkPhysicalDeviceRayTracingPropertiesNV->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;

	        	getVkPhysicalDeviceRayTracingPropertiesNV(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceRayTracingPropertiesNV,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceRayTracingPropertiesNV");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceRayTracingPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT");

	        	VkPhysicalDeviceSampleLocationsPropertiesEXT *vkPhysicalDeviceSampleLocationsPropertiesEXT = (VkPhysicalDeviceSampleLocationsPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceSampleLocationsPropertiesEXT);
	        	vkPhysicalDeviceSampleLocationsPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;

	        	getVkPhysicalDeviceSampleLocationsPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceSampleLocationsPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceSampleLocationsPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceSampleLocationsPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT");

	        	VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT = (VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT);
	        	vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT;

	        	getVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV");

	        	VkPhysicalDeviceShadingRateImagePropertiesNV *vkPhysicalDeviceShadingRateImagePropertiesNV = (VkPhysicalDeviceShadingRateImagePropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceShadingRateImagePropertiesNV);
	        	vkPhysicalDeviceShadingRateImagePropertiesNV->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;

	        	getVkPhysicalDeviceShadingRateImagePropertiesNV(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceShadingRateImagePropertiesNV,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceShadingRateImagePropertiesNV");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShadingRateImagePropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES");

	        	VkPhysicalDeviceSubgroupProperties *vkPhysicalDeviceSubgroupProperties = (VkPhysicalDeviceSubgroupProperties *)calloc(1, sizeof(VkPhysicalDeviceSubgroupProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceSubgroupProperties);
	        	vkPhysicalDeviceSubgroupProperties->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES;

	        	getVkPhysicalDeviceSubgroupProperties(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceSubgroupProperties,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceSubgroupProperties");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceSubgroupProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT");

	        	VkPhysicalDeviceTransformFeedbackPropertiesEXT *vkPhysicalDeviceTransformFeedbackPropertiesEXT = (VkPhysicalDeviceTransformFeedbackPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceTransformFeedbackPropertiesEXT);
	        	vkPhysicalDeviceTransformFeedbackPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;

	        	getVkPhysicalDeviceTransformFeedbackPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceTransformFeedbackPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceTransformFeedbackPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceTransformFeedbackPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT");

	        	VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT = (VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT);
	        	vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT->sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;

	        	getVkPhysicalDeviceVertexAttributeDivisorPropertiesEXT(
	        		env,
					jVulkanCreateInfoStructureObject,
					vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT,
	        		memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Failed on call to getVkPhysicalDeviceVertexAttributeDivisorPropertiesEXT");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;
			}
			break;
			default:
				LOGWARN(env, "Unhandled sType of %d", sTypeValue);
			break;
        }

        // We are done
        return;
	}
}
