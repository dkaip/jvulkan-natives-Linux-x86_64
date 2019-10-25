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

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <vulkan/vulkan_android.h>
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getpNextChain(
		JNIEnv *env,
		jobject jVulkanCreateInfoStructureObject,
		void  **headOfpNextChain,
		std::vector<void *> *memoryToFree);

	static void *getpNext(
			JNIEnv *env,
			jobject jVulkanCreateInfoStructureObject,
			std::vector<void *> *memoryToFree)
	{
        jobject jpNextObject = getpNextObject(env, jVulkanCreateInfoStructureObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNextObject failed.");
            return nullptr;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return nullptr;
            }
        }

        return pNext;
	}

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

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT");

	        	VkPhysicalDeviceConservativeRasterizationPropertiesEXT *vkPhysicalDeviceConservativeRasterizationPropertiesEXT = (VkPhysicalDeviceConservativeRasterizationPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceConservativeRasterizationPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceConservativeRasterizationPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceConservativeRasterizationPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceConservativeRasterizationPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD");

	        	VkPhysicalDeviceShaderCorePropertiesAMD *vkPhysicalDeviceShaderCorePropertiesAMD = (VkPhysicalDeviceShaderCorePropertiesAMD *)calloc(1, sizeof(VkPhysicalDeviceShaderCorePropertiesAMD));
	        	memoryToFree->push_back(vkPhysicalDeviceShaderCorePropertiesAMD);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceShaderCorePropertiesAMD->sType	= sTypeValue;
	            vkPhysicalDeviceShaderCorePropertiesAMD->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceShaderCorePropertiesAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES");

	        	VkPhysicalDeviceMultiviewProperties *vkPhysicalDeviceMultiviewProperties = (VkPhysicalDeviceMultiviewProperties *)calloc(1, sizeof(VkPhysicalDeviceMultiviewProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceMultiviewProperties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceMultiviewProperties->sType	= sTypeValue;
	            vkPhysicalDeviceMultiviewProperties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceMultiviewProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV");

	        	VkPhysicalDeviceCooperativeMatrixPropertiesNV *vkPhysicalDeviceCooperativeMatrixPropertiesNV = (VkPhysicalDeviceCooperativeMatrixPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceCooperativeMatrixPropertiesNV);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceCooperativeMatrixPropertiesNV->sType	= sTypeValue;
	            vkPhysicalDeviceCooperativeMatrixPropertiesNV->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceCooperativeMatrixPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR");

	        	VkPhysicalDeviceDepthStencilResolvePropertiesKHR *vkPhysicalDeviceDepthStencilResolvePropertiesKHR = (VkPhysicalDeviceDepthStencilResolvePropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceDepthStencilResolvePropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceDepthStencilResolvePropertiesKHR);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceDepthStencilResolvePropertiesKHR->sType	= sTypeValue;
	            vkPhysicalDeviceDepthStencilResolvePropertiesKHR->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceDepthStencilResolvePropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT");

	        	VkPhysicalDeviceDescriptorIndexingPropertiesEXT *vkPhysicalDeviceDescriptorIndexingPropertiesEXT = (VkPhysicalDeviceDescriptorIndexingPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceDescriptorIndexingPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDescriptorIndexingPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceDescriptorIndexingPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceDescriptorIndexingPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceDescriptorIndexingPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT");

	        	VkPhysicalDeviceDiscardRectanglePropertiesEXT *vkPhysicalDeviceDiscardRectanglePropertiesEXT = (VkPhysicalDeviceDiscardRectanglePropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDiscardRectanglePropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceDiscardRectanglePropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceDiscardRectanglePropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceDiscardRectanglePropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR");

	        	VkPhysicalDeviceDriverPropertiesKHR *vkPhysicalDeviceDriverPropertiesKHR = (VkPhysicalDeviceDriverPropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceDriverPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceDriverPropertiesKHR);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceDriverPropertiesKHR->sType	= sTypeValue;
	            vkPhysicalDeviceDriverPropertiesKHR->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceDriverPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT");

	        	VkPhysicalDeviceExternalMemoryHostPropertiesEXT *vkPhysicalDeviceExternalMemoryHostPropertiesEXT = (VkPhysicalDeviceExternalMemoryHostPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceExternalMemoryHostPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceExternalMemoryHostPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceExternalMemoryHostPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceExternalMemoryHostPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR");

	        	VkPhysicalDeviceFloatControlsPropertiesKHR *vkPhysicalDeviceFloatControlsPropertiesKHR = (VkPhysicalDeviceFloatControlsPropertiesKHR *)calloc(1, sizeof(VkPhysicalDeviceFloatControlsPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceFloatControlsPropertiesKHR);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceFloatControlsPropertiesKHR->sType	= sTypeValue;
	            vkPhysicalDeviceFloatControlsPropertiesKHR->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceFloatControlsPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT");

	        	VkPhysicalDeviceFragmentDensityMapPropertiesEXT *vkPhysicalDeviceFragmentDensityMapPropertiesEXT = (VkPhysicalDeviceFragmentDensityMapPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceFragmentDensityMapPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceFragmentDensityMapPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceFragmentDensityMapPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceFragmentDensityMapPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES");

	        	VkPhysicalDeviceIDProperties *vkPhysicalDeviceIDProperties = (VkPhysicalDeviceIDProperties *)calloc(1, sizeof(VkPhysicalDeviceIDProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceIDProperties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceIDProperties->sType	= sTypeValue;
	            vkPhysicalDeviceIDProperties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceIDProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT");

	        	VkPhysicalDeviceInlineUniformBlockPropertiesEXT *vkPhysicalDeviceInlineUniformBlockPropertiesEXT = (VkPhysicalDeviceInlineUniformBlockPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceInlineUniformBlockPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceInlineUniformBlockPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceInlineUniformBlockPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceInlineUniformBlockPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceInlineUniformBlockPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES");

	        	VkPhysicalDeviceMaintenance3Properties *vkPhysicalDeviceMaintenance3Properties = (VkPhysicalDeviceMaintenance3Properties *)calloc(1, sizeof(VkPhysicalDeviceMaintenance3Properties));
	        	memoryToFree->push_back(vkPhysicalDeviceMaintenance3Properties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceMaintenance3Properties->sType	= sTypeValue;
	            vkPhysicalDeviceMaintenance3Properties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceMaintenance3Properties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV");

	        	VkPhysicalDeviceMeshShaderPropertiesNV *vkPhysicalDeviceMeshShaderPropertiesNV = (VkPhysicalDeviceMeshShaderPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceMeshShaderPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceMeshShaderPropertiesNV);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceMeshShaderPropertiesNV->sType	= sTypeValue;
	            vkPhysicalDeviceMeshShaderPropertiesNV->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceMeshShaderPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX");

	        	VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX = (VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX *)calloc(1, sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX));
	        	memoryToFree->push_back(vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX->sType	= sTypeValue;
	            vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT");

	        	VkPhysicalDevicePCIBusInfoPropertiesEXT *vkPhysicalDevicePCIBusInfoPropertiesEXT = (VkPhysicalDevicePCIBusInfoPropertiesEXT *)calloc(1, sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDevicePCIBusInfoPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDevicePCIBusInfoPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDevicePCIBusInfoPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDevicePCIBusInfoPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES");

	        	VkPhysicalDevicePointClippingProperties *vkPhysicalDevicePointClippingProperties = (VkPhysicalDevicePointClippingProperties *)calloc(1, sizeof(VkPhysicalDevicePointClippingProperties));
	        	memoryToFree->push_back(vkPhysicalDevicePointClippingProperties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDevicePointClippingProperties->sType	= sTypeValue;
	            vkPhysicalDevicePointClippingProperties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDevicePointClippingProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES");

	        	VkPhysicalDeviceProtectedMemoryProperties *vkPhysicalDeviceProtectedMemoryProperties = (VkPhysicalDeviceProtectedMemoryProperties *)calloc(1, sizeof(VkPhysicalDeviceProtectedMemoryProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceProtectedMemoryProperties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceProtectedMemoryProperties->sType	= sTypeValue;
	            vkPhysicalDeviceProtectedMemoryProperties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceProtectedMemoryProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR");

	        	VkPhysicalDevicePushDescriptorPropertiesKHR *vkPhysicalDevicePushDescriptorPropertiesKHR = (VkPhysicalDevicePushDescriptorPropertiesKHR *)calloc(1, sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR));
	        	memoryToFree->push_back(vkPhysicalDevicePushDescriptorPropertiesKHR);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDevicePushDescriptorPropertiesKHR->sType	= sTypeValue;
	            vkPhysicalDevicePushDescriptorPropertiesKHR->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDevicePushDescriptorPropertiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV");

	        	VkPhysicalDeviceRayTracingPropertiesNV *vkPhysicalDeviceRayTracingPropertiesNV = (VkPhysicalDeviceRayTracingPropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceRayTracingPropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceRayTracingPropertiesNV);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceRayTracingPropertiesNV->sType	= sTypeValue;
	            vkPhysicalDeviceRayTracingPropertiesNV->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceRayTracingPropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT");

	        	VkPhysicalDeviceSampleLocationsPropertiesEXT *vkPhysicalDeviceSampleLocationsPropertiesEXT = (VkPhysicalDeviceSampleLocationsPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceSampleLocationsPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceSampleLocationsPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceSampleLocationsPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceSampleLocationsPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT");

	        	VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT = (VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV");

	        	VkPhysicalDeviceShadingRateImagePropertiesNV *vkPhysicalDeviceShadingRateImagePropertiesNV = (VkPhysicalDeviceShadingRateImagePropertiesNV *)calloc(1, sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceShadingRateImagePropertiesNV);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceShadingRateImagePropertiesNV->sType	= sTypeValue;
	            vkPhysicalDeviceShadingRateImagePropertiesNV->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceShadingRateImagePropertiesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES");

	        	VkPhysicalDeviceSubgroupProperties *vkPhysicalDeviceSubgroupProperties = (VkPhysicalDeviceSubgroupProperties *)calloc(1, sizeof(VkPhysicalDeviceSubgroupProperties));
	        	memoryToFree->push_back(vkPhysicalDeviceSubgroupProperties);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceSubgroupProperties->sType	= sTypeValue;
	            vkPhysicalDeviceSubgroupProperties->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceSubgroupProperties;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT");

	        	VkPhysicalDeviceTransformFeedbackPropertiesEXT *vkPhysicalDeviceTransformFeedbackPropertiesEXT = (VkPhysicalDeviceTransformFeedbackPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceTransformFeedbackPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceTransformFeedbackPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceTransformFeedbackPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceTransformFeedbackPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT");

	        	VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT = (VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT *)calloc(1, sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT);

	            void *pNext = getpNext(env, jVulkanCreateInfoStructureObject, memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getpNext failed.");
	                return;
	            }

	            vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT->sType	= sTypeValue;
	            vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT->pNext	= pNext;
	            *headOfpNextChain = vkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO");

	        	VkDeviceGroupDeviceCreateInfo *vkDeviceGroupDeviceCreateInfo = (VkDeviceGroupDeviceCreateInfo *)calloc(1, sizeof(VkDeviceGroupDeviceCreateInfo));
	        	memoryToFree->push_back(vkDeviceGroupDeviceCreateInfo);

	            getVkDeviceGroupDeviceCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
	        			vkDeviceGroupDeviceCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceGroupDeviceCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceGroupDeviceCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD");

	        	VkDeviceMemoryOverallocationCreateInfoAMD *vkDeviceMemoryOverallocationCreateInfoAMD = (VkDeviceMemoryOverallocationCreateInfoAMD *)calloc(1, sizeof(VkDeviceMemoryOverallocationCreateInfoAMD));
	        	memoryToFree->push_back(vkDeviceMemoryOverallocationCreateInfoAMD);

	            getVkDeviceMemoryOverallocationCreateInfoAMD(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDeviceMemoryOverallocationCreateInfoAMD,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceMemoryOverallocationCreateInfoAMD failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceMemoryOverallocationCreateInfoAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES");

	        	VkPhysicalDevice16BitStorageFeatures *vkPhysicalDevice16BitStorageFeatures = (VkPhysicalDevice16BitStorageFeatures *)calloc(1, sizeof(VkPhysicalDevice16BitStorageFeatures));
	        	memoryToFree->push_back(vkPhysicalDevice16BitStorageFeatures);

	            getVkPhysicalDevice16BitStorageFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDevice16BitStorageFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDevice16BitStorageFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDevice16BitStorageFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR");

	        	VkPhysicalDevice8BitStorageFeaturesKHR *vkPhysicalDevice8BitStorageFeaturesKHR = (VkPhysicalDevice8BitStorageFeaturesKHR *)calloc(1, sizeof(VkPhysicalDevice8BitStorageFeaturesKHR));
	        	memoryToFree->push_back(vkPhysicalDevice8BitStorageFeaturesKHR);

	            getVkPhysicalDevice8BitStorageFeaturesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDevice8BitStorageFeaturesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDevice8BitStorageFeaturesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDevice8BitStorageFeaturesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT");

	        	VkPhysicalDeviceASTCDecodeFeaturesEXT *vkPhysicalDeviceASTCDecodeFeaturesEXT = (VkPhysicalDeviceASTCDecodeFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceASTCDecodeFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceASTCDecodeFeaturesEXT);

	            getVkPhysicalDeviceASTCDecodeFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceASTCDecodeFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceASTCDecodeFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceASTCDecodeFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT");

	        	VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *vkPhysicalDeviceBlendOperationAdvancedFeaturesEXT = (VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceBlendOperationAdvancedFeaturesEXT);

	            getVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceBlendOperationAdvancedFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceBlendOperationAdvancedFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT");

	        	VkPhysicalDeviceBufferDeviceAddressFeaturesEXT *vkPhysicalDeviceBufferDeviceAddressFeaturesEXT = (VkPhysicalDeviceBufferDeviceAddressFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceBufferDeviceAddressFeaturesEXT);

	            getVkPhysicalDeviceBufferDeviceAddressFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceBufferDeviceAddressFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceBufferDeviceAddressFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceBufferDeviceAddressFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV");

	        	VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *vkPhysicalDeviceComputeShaderDerivativesFeaturesNV = (VkPhysicalDeviceComputeShaderDerivativesFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceComputeShaderDerivativesFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceComputeShaderDerivativesFeaturesNV);

	            getVkPhysicalDeviceComputeShaderDerivativesFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceComputeShaderDerivativesFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceComputeShaderDerivativesFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceComputeShaderDerivativesFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT");

	        	VkPhysicalDeviceConditionalRenderingFeaturesEXT *vkPhysicalDeviceConditionalRenderingFeaturesEXT = (VkPhysicalDeviceConditionalRenderingFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceConditionalRenderingFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceConditionalRenderingFeaturesEXT);

	            getVkPhysicalDeviceConditionalRenderingFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceConditionalRenderingFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceConditionalRenderingFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceConditionalRenderingFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV");

	        	VkPhysicalDeviceCooperativeMatrixFeaturesNV *vkPhysicalDeviceCooperativeMatrixFeaturesNV = (VkPhysicalDeviceCooperativeMatrixFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceCooperativeMatrixFeaturesNV);

	            getVkPhysicalDeviceCooperativeMatrixFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceCooperativeMatrixFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceCooperativeMatrixFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceCooperativeMatrixFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV");

	        	VkPhysicalDeviceCornerSampledImageFeaturesNV *vkPhysicalDeviceCornerSampledImageFeaturesNV = (VkPhysicalDeviceCornerSampledImageFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceCornerSampledImageFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceCornerSampledImageFeaturesNV);

	            getVkPhysicalDeviceCornerSampledImageFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceCornerSampledImageFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceCornerSampledImageFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceCornerSampledImageFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV");

	        	VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV *vkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV = (VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV);

	            getVkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT");

	        	VkPhysicalDeviceDepthClipEnableFeaturesEXT *vkPhysicalDeviceDepthClipEnableFeaturesEXT = (VkPhysicalDeviceDepthClipEnableFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceDepthClipEnableFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDepthClipEnableFeaturesEXT);

	            getVkPhysicalDeviceDepthClipEnableFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceDepthClipEnableFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceDepthClipEnableFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDepthClipEnableFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT");

	        	VkPhysicalDeviceDescriptorIndexingFeaturesEXT *vkPhysicalDeviceDescriptorIndexingFeaturesEXT = (VkPhysicalDeviceDescriptorIndexingFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceDescriptorIndexingFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceDescriptorIndexingFeaturesEXT);

	            getVkPhysicalDeviceDescriptorIndexingFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceDescriptorIndexingFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceDescriptorIndexingFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceDescriptorIndexingFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV");

	        	VkPhysicalDeviceExclusiveScissorFeaturesNV *vkPhysicalDeviceExclusiveScissorFeaturesNV = (VkPhysicalDeviceExclusiveScissorFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceExclusiveScissorFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceExclusiveScissorFeaturesNV);

	            getVkPhysicalDeviceExclusiveScissorFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceExclusiveScissorFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceExclusiveScissorFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceExclusiveScissorFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2");

	        	VkPhysicalDeviceFeatures2 *vkPhysicalDeviceFeatures2 = (VkPhysicalDeviceFeatures2 *)calloc(1, sizeof(VkPhysicalDeviceFeatures2));
	        	memoryToFree->push_back(vkPhysicalDeviceFeatures2);

	            getVkPhysicalDeviceFeatures2(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceFeatures2,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceFeatures2 failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFeatures2;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR");

	        	VkPhysicalDeviceFloat16Int8FeaturesKHR *vkPhysicalDeviceFloat16Int8FeaturesKHR = (VkPhysicalDeviceFloat16Int8FeaturesKHR *)calloc(1, sizeof(VkPhysicalDeviceFloat16Int8FeaturesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceFloat16Int8FeaturesKHR);

	            getVkPhysicalDeviceFloat16Int8FeaturesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceFloat16Int8FeaturesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceFloat16Int8FeaturesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFloat16Int8FeaturesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT");

	        	VkPhysicalDeviceFragmentDensityMapFeaturesEXT *vkPhysicalDeviceFragmentDensityMapFeaturesEXT = (VkPhysicalDeviceFragmentDensityMapFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceFragmentDensityMapFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceFragmentDensityMapFeaturesEXT);

	            getVkPhysicalDeviceFragmentDensityMapFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceFragmentDensityMapFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceFragmentDensityMapFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFragmentDensityMapFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV");

	        	VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV *vkPhysicalDeviceFragmentShaderBarycentricFeaturesNV = (VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceFragmentShaderBarycentricFeaturesNV);

	            getVkPhysicalDeviceFragmentShaderBarycentricFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceFragmentShaderBarycentricFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceFragmentShaderBarycentricFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT");

	        	VkPhysicalDeviceHostQueryResetFeaturesEXT *vkPhysicalDeviceHostQueryResetFeaturesEXT = (VkPhysicalDeviceHostQueryResetFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceHostQueryResetFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceHostQueryResetFeaturesEXT);

	            getVkPhysicalDeviceHostQueryResetFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceHostQueryResetFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceHostQueryResetFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceHostQueryResetFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT");

	        	VkPhysicalDeviceInlineUniformBlockFeaturesEXT *vkPhysicalDeviceInlineUniformBlockFeaturesEXT = (VkPhysicalDeviceInlineUniformBlockFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceInlineUniformBlockFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceInlineUniformBlockFeaturesEXT);

	            getVkPhysicalDeviceInlineUniformBlockFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceInlineUniformBlockFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceInlineUniformBlockFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceInlineUniformBlockFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT");

	        	VkPhysicalDeviceMemoryPriorityFeaturesEXT *vkPhysicalDeviceMemoryPriorityFeaturesEXT = (VkPhysicalDeviceMemoryPriorityFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceMemoryPriorityFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceMemoryPriorityFeaturesEXT);

	            getVkPhysicalDeviceMemoryPriorityFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceMemoryPriorityFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceMemoryPriorityFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMemoryPriorityFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV");

	        	VkPhysicalDeviceMeshShaderFeaturesNV *vkPhysicalDeviceMeshShaderFeaturesNV = (VkPhysicalDeviceMeshShaderFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceMeshShaderFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceMeshShaderFeaturesNV);

	            getVkPhysicalDeviceMeshShaderFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceMeshShaderFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceMeshShaderFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMeshShaderFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES");

	        	VkPhysicalDeviceMultiviewFeatures *vkPhysicalDeviceMultiviewFeatures = (VkPhysicalDeviceMultiviewFeatures *)calloc(1, sizeof(VkPhysicalDeviceMultiviewFeatures));
	        	memoryToFree->push_back(vkPhysicalDeviceMultiviewFeatures);

	            getVkPhysicalDeviceMultiviewFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceMultiviewFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceMultiviewFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceMultiviewFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES");

	        	VkPhysicalDeviceProtectedMemoryFeatures *vkPhysicalDeviceProtectedMemoryFeatures = (VkPhysicalDeviceProtectedMemoryFeatures *)calloc(1, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
	        	memoryToFree->push_back(vkPhysicalDeviceProtectedMemoryFeatures);

	            getVkPhysicalDeviceProtectedMemoryFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceProtectedMemoryFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceProtectedMemoryFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceProtectedMemoryFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV");

	        	VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV *vkPhysicalDeviceRepresentativeFragmentTestFeaturesNV = (VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceRepresentativeFragmentTestFeaturesNV);

	            getVkPhysicalDeviceRepresentativeFragmentTestFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceRepresentativeFragmentTestFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceRepresentativeFragmentTestFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES");

	        	VkPhysicalDeviceSamplerYcbcrConversionFeatures *vkPhysicalDeviceSamplerYcbcrConversionFeatures = (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)calloc(1, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
	        	memoryToFree->push_back(vkPhysicalDeviceSamplerYcbcrConversionFeatures);

	            getVkPhysicalDeviceSamplerYcbcrConversionFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceSamplerYcbcrConversionFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceSamplerYcbcrConversionFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceSamplerYcbcrConversionFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT");

	        	VkPhysicalDeviceScalarBlockLayoutFeaturesEXT *vkPhysicalDeviceScalarBlockLayoutFeaturesEXT = (VkPhysicalDeviceScalarBlockLayoutFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceScalarBlockLayoutFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceScalarBlockLayoutFeaturesEXT);

	            getVkPhysicalDeviceScalarBlockLayoutFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceScalarBlockLayoutFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceScalarBlockLayoutFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceScalarBlockLayoutFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR");

	        	VkPhysicalDeviceShaderAtomicInt64FeaturesKHR *vkPhysicalDeviceShaderAtomicInt64FeaturesKHR = (VkPhysicalDeviceShaderAtomicInt64FeaturesKHR *)calloc(1, sizeof(VkPhysicalDeviceShaderAtomicInt64FeaturesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceShaderAtomicInt64FeaturesKHR);

	            getVkPhysicalDeviceShaderAtomicInt64FeaturesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceShaderAtomicInt64FeaturesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceShaderAtomicInt64FeaturesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShaderAtomicInt64FeaturesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES");

	        	VkPhysicalDeviceShaderDrawParametersFeatures *vkPhysicalDeviceShaderDrawParametersFeatures = (VkPhysicalDeviceShaderDrawParametersFeatures *)calloc(1, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
	        	memoryToFree->push_back(vkPhysicalDeviceShaderDrawParametersFeatures);

	            getVkPhysicalDeviceShaderDrawParametersFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceShaderDrawParametersFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceShaderDrawParametersFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShaderDrawParametersFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV");

	        	VkPhysicalDeviceShaderImageFootprintFeaturesNV *vkPhysicalDeviceShaderImageFootprintFeaturesNV = (VkPhysicalDeviceShaderImageFootprintFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceShaderImageFootprintFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceShaderImageFootprintFeaturesNV);

	            getVkPhysicalDeviceShaderImageFootprintFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceShaderImageFootprintFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceShaderImageFootprintFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShaderImageFootprintFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV");

	        	VkPhysicalDeviceShadingRateImageFeaturesNV *vkPhysicalDeviceShadingRateImageFeaturesNV = (VkPhysicalDeviceShadingRateImageFeaturesNV *)calloc(1, sizeof(VkPhysicalDeviceShadingRateImageFeaturesNV));
	        	memoryToFree->push_back(vkPhysicalDeviceShadingRateImageFeaturesNV);

	            getVkPhysicalDeviceShadingRateImageFeaturesNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceShadingRateImageFeaturesNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceShadingRateImageFeaturesNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceShadingRateImageFeaturesNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT");

	        	VkPhysicalDeviceTransformFeedbackFeaturesEXT *vkPhysicalDeviceTransformFeedbackFeaturesEXT = (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceTransformFeedbackFeaturesEXT);

	            getVkPhysicalDeviceTransformFeedbackFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceTransformFeedbackFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceTransformFeedbackFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceTransformFeedbackFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES");

	        	VkPhysicalDeviceVariablePointersFeatures *vkPhysicalDeviceVariablePointersFeatures = (VkPhysicalDeviceVariablePointersFeatures *)calloc(1, sizeof(VkPhysicalDeviceVariablePointersFeatures));
	        	memoryToFree->push_back(vkPhysicalDeviceVariablePointersFeatures);

	            getVkPhysicalDeviceVariablePointersFeatures(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceVariablePointersFeatures,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceVariablePointersFeatures failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceVariablePointersFeatures;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT");

	        	VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT = (VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT);

	            getVkPhysicalDeviceVertexAttributeDivisorFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceVertexAttributeDivisorFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR");

	        	VkPhysicalDeviceVulkanMemoryModelFeaturesKHR *vkPhysicalDeviceVulkanMemoryModelFeaturesKHR = (VkPhysicalDeviceVulkanMemoryModelFeaturesKHR *)calloc(1, sizeof(VkPhysicalDeviceVulkanMemoryModelFeaturesKHR));
	        	memoryToFree->push_back(vkPhysicalDeviceVulkanMemoryModelFeaturesKHR);

	            getVkPhysicalDeviceVulkanMemoryModelFeaturesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceVulkanMemoryModelFeaturesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceVulkanMemoryModelFeaturesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceVulkanMemoryModelFeaturesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT");

	        	VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *vkPhysicalDeviceYcbcrImageArraysFeaturesEXT = (VkPhysicalDeviceYcbcrImageArraysFeaturesEXT *)calloc(1, sizeof(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceYcbcrImageArraysFeaturesEXT);

	            getVkPhysicalDeviceYcbcrImageArraysFeaturesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceYcbcrImageArraysFeaturesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceYcbcrImageArraysFeaturesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceYcbcrImageArraysFeaturesEXT;
			}
			break;
//			case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
//			{
//	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR");
//
//	        	VkD3D12FenceSubmitInfoKHR *vkD3D12FenceSubmitInfoKHR = (VkD3D12FenceSubmitInfoKHR *)calloc(1, sizeof(VkD3D12FenceSubmitInfoKHR));
//	        	memoryToFree->push_back(vkD3D12FenceSubmitInfoKHR);
//
//	            getVkD3D12FenceSubmitInfoKHR(
//	                    env,
//						jVulkanCreateInfoStructureObject,
//						vkD3D12FenceSubmitInfoKHR,
//	                    memoryToFree);
//	            if (env->ExceptionOccurred())
//	            {
//	            	LOGERROR(env, "%s", "Call to getVkD3D12FenceSubmitInfoKHR failed.");
//	                return;
//	            }
//
//	            *headOfpNextChain = vkD3D12FenceSubmitInfoKHR;
//			}
//			break;
			case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO");

	        	VkDeviceGroupSubmitInfo *vkDeviceGroupSubmitInfo = (VkDeviceGroupSubmitInfo *)calloc(1, sizeof(VkDeviceGroupSubmitInfo));
	        	memoryToFree->push_back(vkDeviceGroupSubmitInfo);

	            getVkDeviceGroupSubmitInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDeviceGroupSubmitInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceGroupSubmitInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceGroupSubmitInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO");

	        	VkProtectedSubmitInfo *vkProtectedSubmitInfo = (VkProtectedSubmitInfo *)calloc(1, sizeof(VkProtectedSubmitInfo));
	        	memoryToFree->push_back(vkProtectedSubmitInfo);

	            getVkProtectedSubmitInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkProtectedSubmitInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkProtectedSubmitInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkProtectedSubmitInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO");

	        	VkExportFenceCreateInfo *vkExportFenceCreateInfo = (VkExportFenceCreateInfo *)calloc(1, sizeof(VkExportFenceCreateInfo));
	        	memoryToFree->push_back(vkExportFenceCreateInfo);

	            getVkExportFenceCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExportFenceCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExportFenceCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkExportFenceCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO");

	        	VkExportSemaphoreCreateInfo *vkExportSemaphoreCreateInfo = (VkExportSemaphoreCreateInfo *)calloc(1, sizeof(VkExportSemaphoreCreateInfo));
	        	memoryToFree->push_back(vkExportSemaphoreCreateInfo);

	            getVkExportSemaphoreCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExportSemaphoreCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExportSemaphoreCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkExportSemaphoreCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT");

	        	VkRenderPassFragmentDensityMapCreateInfoEXT *vkRenderPassFragmentDensityMapCreateInfoEXT = (VkRenderPassFragmentDensityMapCreateInfoEXT *)calloc(1, sizeof(VkRenderPassFragmentDensityMapCreateInfoEXT));
	        	memoryToFree->push_back(vkRenderPassFragmentDensityMapCreateInfoEXT);

	            getVkRenderPassFragmentDensityMapCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkRenderPassFragmentDensityMapCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkRenderPassFragmentDensityMapCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkRenderPassFragmentDensityMapCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO");

	        	VkRenderPassInputAttachmentAspectCreateInfo *vkRenderPassInputAttachmentAspectCreateInfo = (VkRenderPassInputAttachmentAspectCreateInfo *)calloc(1, sizeof(VkRenderPassInputAttachmentAspectCreateInfo));
	        	memoryToFree->push_back(vkRenderPassInputAttachmentAspectCreateInfo);

	            getVkRenderPassInputAttachmentAspectCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkRenderPassInputAttachmentAspectCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkRenderPassInputAttachmentAspectCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkRenderPassInputAttachmentAspectCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO");

	        	VkRenderPassMultiviewCreateInfo *vkRenderPassMultiviewCreateInfo = (VkRenderPassMultiviewCreateInfo *)calloc(1, sizeof(VkRenderPassMultiviewCreateInfo));
	        	memoryToFree->push_back(vkRenderPassMultiviewCreateInfo);

	            getVkRenderPassMultiviewCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkRenderPassMultiviewCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkRenderPassMultiviewCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkRenderPassMultiviewCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO");

	        	VkDeviceGroupRenderPassBeginInfo *vkDeviceGroupRenderPassBeginInfo = (VkDeviceGroupRenderPassBeginInfo *)calloc(1, sizeof(VkDeviceGroupRenderPassBeginInfo));
	        	memoryToFree->push_back(vkDeviceGroupRenderPassBeginInfo);

	            getVkDeviceGroupRenderPassBeginInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDeviceGroupRenderPassBeginInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceGroupRenderPassBeginInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceGroupRenderPassBeginInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT");

	        	VkRenderPassSampleLocationsBeginInfoEXT *vkRenderPassSampleLocationsBeginInfoEXT = (VkRenderPassSampleLocationsBeginInfoEXT *)calloc(1, sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
	        	memoryToFree->push_back(vkRenderPassSampleLocationsBeginInfoEXT);

	            getVkRenderPassSampleLocationsBeginInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkRenderPassSampleLocationsBeginInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkRenderPassSampleLocationsBeginInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkRenderPassSampleLocationsBeginInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT");

	        	VkPipelineCreationFeedbackCreateInfoEXT *vkPipelineCreationFeedbackCreateInfoEXT = (VkPipelineCreationFeedbackCreateInfoEXT *)calloc(1, sizeof(VkPipelineCreationFeedbackCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineCreationFeedbackCreateInfoEXT);

	            getVkPipelineCreationFeedbackCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineCreationFeedbackCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineCreationFeedbackCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineCreationFeedbackCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT");

	        	VkPipelineDiscardRectangleStateCreateInfoEXT *vkPipelineDiscardRectangleStateCreateInfoEXT = (VkPipelineDiscardRectangleStateCreateInfoEXT *)calloc(1, sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineDiscardRectangleStateCreateInfoEXT);

	            getVkPipelineDiscardRectangleStateCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineDiscardRectangleStateCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineDiscardRectangleStateCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineDiscardRectangleStateCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV");

	        	VkPipelineRepresentativeFragmentTestStateCreateInfoNV *vkPipelineRepresentativeFragmentTestStateCreateInfoNV = (VkPipelineRepresentativeFragmentTestStateCreateInfoNV *)calloc(1, sizeof(VkPipelineRepresentativeFragmentTestStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineRepresentativeFragmentTestStateCreateInfoNV);

	            getVkPipelineRepresentativeFragmentTestStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineRepresentativeFragmentTestStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineRepresentativeFragmentTestStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineRepresentativeFragmentTestStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV");

	        	VkDedicatedAllocationMemoryAllocateInfoNV *vkDedicatedAllocationMemoryAllocateInfoNV = (VkDedicatedAllocationMemoryAllocateInfoNV *)calloc(1, sizeof(VkDedicatedAllocationMemoryAllocateInfoNV));
	        	memoryToFree->push_back(vkDedicatedAllocationMemoryAllocateInfoNV);

	            getVkDedicatedAllocationMemoryAllocateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDedicatedAllocationMemoryAllocateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDedicatedAllocationMemoryAllocateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkDedicatedAllocationMemoryAllocateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO");

	        	VkExportMemoryAllocateInfo *vkExportMemoryAllocateInfo = (VkExportMemoryAllocateInfo *)calloc(1, sizeof(VkExportMemoryAllocateInfo));
	        	memoryToFree->push_back(vkExportMemoryAllocateInfo);

	            getVkExportMemoryAllocateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExportMemoryAllocateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExportMemoryAllocateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkExportMemoryAllocateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV");

	        	VkExportMemoryAllocateInfoNV *vkExportMemoryAllocateInfoNV = (VkExportMemoryAllocateInfoNV *)calloc(1, sizeof(VkExportMemoryAllocateInfoNV));
	        	memoryToFree->push_back(vkExportMemoryAllocateInfoNV);

	            getVkExportMemoryAllocateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExportMemoryAllocateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExportMemoryAllocateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkExportMemoryAllocateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR");

	        	VkImportMemoryFdInfoKHR *vkImportMemoryFdInfoKHR = (VkImportMemoryFdInfoKHR *)calloc(1, sizeof(VkImportMemoryFdInfoKHR));
	        	memoryToFree->push_back(vkImportMemoryFdInfoKHR);

	            getVkImportMemoryFdInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImportMemoryFdInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImportMemoryFdInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkImportMemoryFdInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT");

	        	VkImportMemoryHostPointerInfoEXT *vkImportMemoryHostPointerInfoEXT = (VkImportMemoryHostPointerInfoEXT *)calloc(1, sizeof(VkImportMemoryHostPointerInfoEXT));
	        	memoryToFree->push_back(vkImportMemoryHostPointerInfoEXT);

	            getVkImportMemoryHostPointerInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImportMemoryHostPointerInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImportMemoryHostPointerInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkImportMemoryHostPointerInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO");

	        	VkMemoryAllocateFlagsInfo *vkMemoryAllocateFlagsInfo = (VkMemoryAllocateFlagsInfo *)calloc(1, sizeof(VkMemoryAllocateFlagsInfo));
	        	memoryToFree->push_back(vkMemoryAllocateFlagsInfo);

	            getVkMemoryAllocateFlagsInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkMemoryAllocateFlagsInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkMemoryAllocateFlagsInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkMemoryAllocateFlagsInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO");

	        	VkMemoryDedicatedAllocateInfo *vkMemoryDedicatedAllocateInfo = (VkMemoryDedicatedAllocateInfo *)calloc(1, sizeof(VkMemoryDedicatedAllocateInfo));
	        	memoryToFree->push_back(vkMemoryDedicatedAllocateInfo);

	            getVkMemoryDedicatedAllocateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkMemoryDedicatedAllocateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkMemoryDedicatedAllocateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkMemoryDedicatedAllocateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT");

	        	VkMemoryPriorityAllocateInfoEXT *vkMemoryPriorityAllocateInfoEXT = (VkMemoryPriorityAllocateInfoEXT *)calloc(1, sizeof(VkMemoryPriorityAllocateInfoEXT));
	        	memoryToFree->push_back(vkMemoryPriorityAllocateInfoEXT);

	            getVkMemoryPriorityAllocateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkMemoryPriorityAllocateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkMemoryPriorityAllocateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkMemoryPriorityAllocateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT");

	        	VkBufferDeviceAddressCreateInfoEXT *vkBufferDeviceAddressCreateInfoEXT = (VkBufferDeviceAddressCreateInfoEXT *)calloc(1, sizeof(VkBufferDeviceAddressCreateInfoEXT));
	        	memoryToFree->push_back(vkBufferDeviceAddressCreateInfoEXT);

	            getVkBufferDeviceAddressCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkBufferDeviceAddressCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkBufferDeviceAddressCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkBufferDeviceAddressCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV");

	        	VkDedicatedAllocationBufferCreateInfoNV *vkDedicatedAllocationBufferCreateInfoNV = (VkDedicatedAllocationBufferCreateInfoNV *)calloc(1, sizeof(VkDedicatedAllocationBufferCreateInfoNV));
	        	memoryToFree->push_back(vkDedicatedAllocationBufferCreateInfoNV);

	            getVkDedicatedAllocationBufferCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDedicatedAllocationBufferCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDedicatedAllocationBufferCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkDedicatedAllocationBufferCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO");

	        	VkExternalMemoryBufferCreateInfo *vkExternalMemoryBufferCreateInfo = (VkExternalMemoryBufferCreateInfo *)calloc(1, sizeof(VkExternalMemoryBufferCreateInfo));
	        	memoryToFree->push_back(vkExternalMemoryBufferCreateInfo);

	            getVkExternalMemoryBufferCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExternalMemoryBufferCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExternalMemoryBufferCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkExternalMemoryBufferCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV");

	        	VkDedicatedAllocationImageCreateInfoNV *vkDedicatedAllocationImageCreateInfoNV = (VkDedicatedAllocationImageCreateInfoNV *)calloc(1, sizeof(VkDedicatedAllocationImageCreateInfoNV));
	        	memoryToFree->push_back(vkDedicatedAllocationImageCreateInfoNV);

	            getVkDedicatedAllocationImageCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDedicatedAllocationImageCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDedicatedAllocationImageCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkDedicatedAllocationImageCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO");

	        	VkExternalMemoryImageCreateInfo *vkExternalMemoryImageCreateInfo = (VkExternalMemoryImageCreateInfo *)calloc(1, sizeof(VkExternalMemoryImageCreateInfo));
	        	memoryToFree->push_back(vkExternalMemoryImageCreateInfo);

	            getVkExternalMemoryImageCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExternalMemoryImageCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExternalMemoryImageCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkExternalMemoryImageCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV");

	        	VkExternalMemoryImageCreateInfoNV *vkExternalMemoryImageCreateInfoNV = (VkExternalMemoryImageCreateInfoNV *)calloc(1, sizeof(VkExternalMemoryImageCreateInfoNV));
	        	memoryToFree->push_back(vkExternalMemoryImageCreateInfoNV);

	            getVkExternalMemoryImageCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExternalMemoryImageCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExternalMemoryImageCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkExternalMemoryImageCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT");

	        	VkImageDrmFormatModifierExplicitCreateInfoEXT *vkImageDrmFormatModifierExplicitCreateInfoEXT = (VkImageDrmFormatModifierExplicitCreateInfoEXT *)calloc(1, sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
	        	memoryToFree->push_back(vkImageDrmFormatModifierExplicitCreateInfoEXT);

	            getVkImageDrmFormatModifierExplicitCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageDrmFormatModifierExplicitCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageDrmFormatModifierExplicitCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageDrmFormatModifierExplicitCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT");

	        	VkImageDrmFormatModifierListCreateInfoEXT *vkImageDrmFormatModifierListCreateInfoEXT = (VkImageDrmFormatModifierListCreateInfoEXT *)calloc(1, sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
	        	memoryToFree->push_back(vkImageDrmFormatModifierListCreateInfoEXT);

	            getVkImageDrmFormatModifierListCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageDrmFormatModifierListCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageDrmFormatModifierListCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageDrmFormatModifierListCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR");

	        	VkImageFormatListCreateInfoKHR *vkImageFormatListCreateInfoKHR = (VkImageFormatListCreateInfoKHR *)calloc(1, sizeof(VkImageFormatListCreateInfoKHR));
	        	memoryToFree->push_back(vkImageFormatListCreateInfoKHR);

	            getVkImageFormatListCreateInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageFormatListCreateInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageFormatListCreateInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageFormatListCreateInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT");

	        	VkImageStencilUsageCreateInfoEXT *vkImageStencilUsageCreateInfoEXT = (VkImageStencilUsageCreateInfoEXT *)calloc(1, sizeof(VkImageStencilUsageCreateInfoEXT));
	        	memoryToFree->push_back(vkImageStencilUsageCreateInfoEXT);

	            getVkImageStencilUsageCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageStencilUsageCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageStencilUsageCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageStencilUsageCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR");

	        	VkImageSwapchainCreateInfoKHR *vkImageSwapchainCreateInfoKHR = (VkImageSwapchainCreateInfoKHR *)calloc(1, sizeof(VkImageSwapchainCreateInfoKHR));
	        	memoryToFree->push_back(vkImageSwapchainCreateInfoKHR);

	            getVkImageSwapchainCreateInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageSwapchainCreateInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageSwapchainCreateInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageSwapchainCreateInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT");

	        	VkImageViewASTCDecodeModeEXT *vkImageViewASTCDecodeModeEXT = (VkImageViewASTCDecodeModeEXT *)calloc(1, sizeof(VkImageViewASTCDecodeModeEXT));
	        	memoryToFree->push_back(vkImageViewASTCDecodeModeEXT);

	            getVkImageViewASTCDecodeModeEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageViewASTCDecodeModeEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageViewASTCDecodeModeEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageViewASTCDecodeModeEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO");

	        	VkImageViewUsageCreateInfo *vkImageViewUsageCreateInfo = (VkImageViewUsageCreateInfo *)calloc(1, sizeof(VkImageViewUsageCreateInfo));
	        	memoryToFree->push_back(vkImageViewUsageCreateInfo);

	            getVkImageViewUsageCreateInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkImageViewUsageCreateInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkImageViewUsageCreateInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkImageViewUsageCreateInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO");

	        	VkSamplerYcbcrConversionInfo *vkSamplerYcbcrConversionInfo = (VkSamplerYcbcrConversionInfo *)calloc(1, sizeof(VkSamplerYcbcrConversionInfo));
	        	memoryToFree->push_back(vkSamplerYcbcrConversionInfo);

	            getVkSamplerYcbcrConversionInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSamplerYcbcrConversionInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSamplerYcbcrConversionInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkSamplerYcbcrConversionInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO");

	        	VkBindImageMemoryDeviceGroupInfo *vkBindImageMemoryDeviceGroupInfo = (VkBindImageMemoryDeviceGroupInfo *)calloc(1, sizeof(VkBindImageMemoryDeviceGroupInfo));
	        	memoryToFree->push_back(vkBindImageMemoryDeviceGroupInfo);

	            getVkBindImageMemoryDeviceGroupInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkBindImageMemoryDeviceGroupInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkBindImageMemoryDeviceGroupInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkBindImageMemoryDeviceGroupInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR");

	        	VkBindImageMemorySwapchainInfoKHR *vkBindImageMemorySwapchainInfoKHR = (VkBindImageMemorySwapchainInfoKHR *)calloc(1, sizeof(VkBindImageMemorySwapchainInfoKHR));
	        	memoryToFree->push_back(vkBindImageMemorySwapchainInfoKHR);

	            getVkBindImageMemorySwapchainInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkBindImageMemorySwapchainInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkBindImageMemorySwapchainInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkBindImageMemorySwapchainInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO");

	        	VkBindImagePlaneMemoryInfo *vkBindImagePlaneMemoryInfo = (VkBindImagePlaneMemoryInfo *)calloc(1, sizeof(VkBindImagePlaneMemoryInfo));
	        	memoryToFree->push_back(vkBindImagePlaneMemoryInfo);

	            getVkBindImagePlaneMemoryInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkBindImagePlaneMemoryInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkBindImagePlaneMemoryInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkBindImagePlaneMemoryInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT");

	        	VkSamplerReductionModeCreateInfoEXT *vkSamplerReductionModeCreateInfoEXT = (VkSamplerReductionModeCreateInfoEXT *)calloc(1, sizeof(VkSamplerReductionModeCreateInfoEXT));
	        	memoryToFree->push_back(vkSamplerReductionModeCreateInfoEXT);

	            getVkSamplerReductionModeCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSamplerReductionModeCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSamplerReductionModeCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkSamplerReductionModeCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV");

	        	VkWriteDescriptorSetAccelerationStructureNV *vkWriteDescriptorSetAccelerationStructureNV = (VkWriteDescriptorSetAccelerationStructureNV *)calloc(1, sizeof(VkWriteDescriptorSetAccelerationStructureNV));
	        	memoryToFree->push_back(vkWriteDescriptorSetAccelerationStructureNV);

	            getVkWriteDescriptorSetAccelerationStructureNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkWriteDescriptorSetAccelerationStructureNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkWriteDescriptorSetAccelerationStructureNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkWriteDescriptorSetAccelerationStructureNV;
			}
			break;
			case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT");

	        	VkWriteDescriptorSetInlineUniformBlockEXT *vkWriteDescriptorSetInlineUniformBlockEXT = (VkWriteDescriptorSetInlineUniformBlockEXT *)calloc(1, sizeof(VkWriteDescriptorSetInlineUniformBlockEXT));
	        	memoryToFree->push_back(vkWriteDescriptorSetInlineUniformBlockEXT);

	            getVkWriteDescriptorSetInlineUniformBlockEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkWriteDescriptorSetInlineUniformBlockEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkWriteDescriptorSetInlineUniformBlockEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkWriteDescriptorSetInlineUniformBlockEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV");

	        	VkPipelineViewportCoarseSampleOrderStateCreateInfoNV *vkPipelineViewportCoarseSampleOrderStateCreateInfoNV = (VkPipelineViewportCoarseSampleOrderStateCreateInfoNV *)calloc(1, sizeof(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineViewportCoarseSampleOrderStateCreateInfoNV);

	            getVkPipelineViewportCoarseSampleOrderStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineViewportCoarseSampleOrderStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineViewportCoarseSampleOrderStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineViewportCoarseSampleOrderStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV");

	        	VkPipelineViewportExclusiveScissorStateCreateInfoNV *vkPipelineViewportExclusiveScissorStateCreateInfoNV = (VkPipelineViewportExclusiveScissorStateCreateInfoNV *)calloc(1, sizeof(VkPipelineViewportExclusiveScissorStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineViewportExclusiveScissorStateCreateInfoNV);

	            getVkPipelineViewportExclusiveScissorStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineViewportExclusiveScissorStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineViewportExclusiveScissorStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineViewportExclusiveScissorStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV");

	        	VkPipelineViewportShadingRateImageStateCreateInfoNV *vkPipelineViewportShadingRateImageStateCreateInfoNV = (VkPipelineViewportShadingRateImageStateCreateInfoNV *)calloc(1, sizeof(VkPipelineViewportShadingRateImageStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineViewportShadingRateImageStateCreateInfoNV);

	            getVkPipelineViewportShadingRateImageStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineViewportShadingRateImageStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineViewportShadingRateImageStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineViewportShadingRateImageStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV");

	        	VkPipelineViewportSwizzleStateCreateInfoNV *vkPipelineViewportSwizzleStateCreateInfoNV = (VkPipelineViewportSwizzleStateCreateInfoNV *)calloc(1, sizeof(VkPipelineViewportSwizzleStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineViewportSwizzleStateCreateInfoNV);

	            getVkPipelineViewportSwizzleStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineViewportSwizzleStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineViewportSwizzleStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineViewportSwizzleStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV");

	        	VkPipelineViewportWScalingStateCreateInfoNV *vkPipelineViewportWScalingStateCreateInfoNV = (VkPipelineViewportWScalingStateCreateInfoNV *)calloc(1, sizeof(VkPipelineViewportWScalingStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineViewportWScalingStateCreateInfoNV);

	            getVkPipelineViewportWScalingStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineViewportWScalingStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineViewportWScalingStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineViewportWScalingStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT");

	        	VkPipelineRasterizationConservativeStateCreateInfoEXT *vkPipelineRasterizationConservativeStateCreateInfoEXT = (VkPipelineRasterizationConservativeStateCreateInfoEXT *)calloc(1, sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineRasterizationConservativeStateCreateInfoEXT);

	            getVkPipelineRasterizationConservativeStateCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineRasterizationConservativeStateCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineRasterizationConservativeStateCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineRasterizationConservativeStateCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT");

	        	VkPipelineRasterizationDepthClipStateCreateInfoEXT *vkPipelineRasterizationDepthClipStateCreateInfoEXT = (VkPipelineRasterizationDepthClipStateCreateInfoEXT *)calloc(1, sizeof(VkPipelineRasterizationDepthClipStateCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineRasterizationDepthClipStateCreateInfoEXT);

	            getVkPipelineRasterizationDepthClipStateCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineRasterizationDepthClipStateCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineRasterizationDepthClipStateCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineRasterizationDepthClipStateCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD");

	        	VkPipelineRasterizationStateRasterizationOrderAMD *vkPipelineRasterizationStateRasterizationOrderAMD = (VkPipelineRasterizationStateRasterizationOrderAMD *)calloc(1, sizeof(VkPipelineRasterizationStateRasterizationOrderAMD));
	        	memoryToFree->push_back(vkPipelineRasterizationStateRasterizationOrderAMD);

	            getVkPipelineRasterizationStateRasterizationOrderAMD(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineRasterizationStateRasterizationOrderAMD,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineRasterizationStateRasterizationOrderAMD failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineRasterizationStateRasterizationOrderAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT");

	        	VkPipelineRasterizationStateStreamCreateInfoEXT *vkPipelineRasterizationStateStreamCreateInfoEXT = (VkPipelineRasterizationStateStreamCreateInfoEXT *)calloc(1, sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineRasterizationStateStreamCreateInfoEXT);

	            getVkPipelineRasterizationStateStreamCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineRasterizationStateStreamCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineRasterizationStateStreamCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineRasterizationStateStreamCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV");

	        	VkPipelineCoverageModulationStateCreateInfoNV *vkPipelineCoverageModulationStateCreateInfoNV = (VkPipelineCoverageModulationStateCreateInfoNV *)calloc(1, sizeof(VkPipelineCoverageModulationStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineCoverageModulationStateCreateInfoNV);

	            getVkPipelineCoverageModulationStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineCoverageModulationStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineCoverageModulationStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineCoverageModulationStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV");

	        	VkPipelineCoverageToColorStateCreateInfoNV *vkPipelineCoverageToColorStateCreateInfoNV = (VkPipelineCoverageToColorStateCreateInfoNV *)calloc(1, sizeof(VkPipelineCoverageToColorStateCreateInfoNV));
	        	memoryToFree->push_back(vkPipelineCoverageToColorStateCreateInfoNV);

	            getVkPipelineCoverageToColorStateCreateInfoNV(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineCoverageToColorStateCreateInfoNV,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineCoverageToColorStateCreateInfoNV failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineCoverageToColorStateCreateInfoNV;
			}
			break;
			case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT");

	        	VkPipelineSampleLocationsStateCreateInfoEXT *vkPipelineSampleLocationsStateCreateInfoEXT = (VkPipelineSampleLocationsStateCreateInfoEXT *)calloc(1, sizeof(VkPipelineSampleLocationsStateCreateInfoEXT));
	        	memoryToFree->push_back(vkPipelineSampleLocationsStateCreateInfoEXT);

	            getVkPipelineSampleLocationsStateCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPipelineSampleLocationsStateCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPipelineSampleLocationsStateCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPipelineSampleLocationsStateCreateInfoEXT;
			}
			break;
//			case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
//			{
//	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT");
//
//	        	VkSurfaceFullScreenExclusiveInfoEXT *vkSurfaceFullScreenExclusiveInfoEXT = (VkSurfaceFullScreenExclusiveInfoEXT *)calloc(1, sizeof(VkSurfaceFullScreenExclusiveInfoEXT));
//	        	memoryToFree->push_back(vkSurfaceFullScreenExclusiveInfoEXT);
//
//	            getVkSurfaceFullScreenExclusiveInfoEXT(
//	                    env,
//						jVulkanCreateInfoStructureObject,
//						vkSurfaceFullScreenExclusiveInfoEXT,
//	                    memoryToFree);
//	            if (env->ExceptionOccurred())
//	            {
//	            	LOGERROR(env, "%s", "Call to getVkSurfaceFullScreenExclusiveInfoEXT failed.");
//	                return;
//	            }
//
//	            *headOfpNextChain = vkSurfaceFullScreenExclusiveInfoEXT;
//			}
//			break;
			case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD");

	        	VkDisplayNativeHdrSurfaceCapabilitiesAMD *vkDisplayNativeHdrSurfaceCapabilitiesAMD = (VkDisplayNativeHdrSurfaceCapabilitiesAMD *)calloc(1, sizeof(VkDisplayNativeHdrSurfaceCapabilitiesAMD));
	        	memoryToFree->push_back(vkDisplayNativeHdrSurfaceCapabilitiesAMD);

	            getVkDisplayNativeHdrSurfaceCapabilitiesAMD(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDisplayNativeHdrSurfaceCapabilitiesAMD,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDisplayNativeHdrSurfaceCapabilitiesAMD failed.");
	                return;
	            }

	            *headOfpNextChain = vkDisplayNativeHdrSurfaceCapabilitiesAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR");

	        	VkSharedPresentSurfaceCapabilitiesKHR *vkSharedPresentSurfaceCapabilitiesKHR = (VkSharedPresentSurfaceCapabilitiesKHR *)calloc(1, sizeof(VkSharedPresentSurfaceCapabilitiesKHR));
	        	memoryToFree->push_back(vkSharedPresentSurfaceCapabilitiesKHR);

	            getVkSharedPresentSurfaceCapabilitiesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSharedPresentSurfaceCapabilitiesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSharedPresentSurfaceCapabilitiesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkSharedPresentSurfaceCapabilitiesKHR;
			}
			break;
//			case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
//			{
//	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT");
//
//	        	VkSurfaceCapabilitiesFullScreenExclusiveEXT *vkSurfaceCapabilitiesFullScreenExclusiveEXT = (VkSurfaceCapabilitiesFullScreenExclusiveEXT *)calloc(1, sizeof(VkSurfaceCapabilitiesFullScreenExclusiveEXT));
//	        	memoryToFree->push_back(vkSurfaceCapabilitiesFullScreenExclusiveEXT);
//
//	            getVkSurfaceCapabilitiesFullScreenExclusiveEXT(
//	                    env,
//						jVulkanCreateInfoStructureObject,
//						vkSurfaceCapabilitiesFullScreenExclusiveEXT,
//	                    memoryToFree);
//	            if (env->ExceptionOccurred())
//	            {
//	            	LOGERROR(env, "%s", "Call to getVkSurfaceCapabilitiesFullScreenExclusiveEXT failed.");
//	                return;
//	            }
//
//	            *headOfpNextChain = vkSurfaceCapabilitiesFullScreenExclusiveEXT;
//			}
//			break;
			case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR");

	        	VkSurfaceProtectedCapabilitiesKHR *vkSurfaceProtectedCapabilitiesKHR = (VkSurfaceProtectedCapabilitiesKHR *)calloc(1, sizeof(VkSurfaceProtectedCapabilitiesKHR));
	        	memoryToFree->push_back(vkSurfaceProtectedCapabilitiesKHR);

	            getVkSurfaceProtectedCapabilitiesKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSurfaceProtectedCapabilitiesKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSurfaceProtectedCapabilitiesKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkSurfaceProtectedCapabilitiesKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR");

	        	VkDeviceGroupSwapchainCreateInfoKHR *vkDeviceGroupSwapchainCreateInfoKHR = (VkDeviceGroupSwapchainCreateInfoKHR *)calloc(1, sizeof(VkDeviceGroupSwapchainCreateInfoKHR));
	        	memoryToFree->push_back(vkDeviceGroupSwapchainCreateInfoKHR);

	            getVkDeviceGroupSwapchainCreateInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDeviceGroupSwapchainCreateInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceGroupSwapchainCreateInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceGroupSwapchainCreateInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT");

	        	VkSwapchainCounterCreateInfoEXT *vkSwapchainCounterCreateInfoEXT = (VkSwapchainCounterCreateInfoEXT *)calloc(1, sizeof(VkSwapchainCounterCreateInfoEXT));
	        	memoryToFree->push_back(vkSwapchainCounterCreateInfoEXT);

	            getVkSwapchainCounterCreateInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSwapchainCounterCreateInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSwapchainCounterCreateInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkSwapchainCounterCreateInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD");

	        	VkSwapchainDisplayNativeHdrCreateInfoAMD *vkSwapchainDisplayNativeHdrCreateInfoAMD = (VkSwapchainDisplayNativeHdrCreateInfoAMD *)calloc(1, sizeof(VkSwapchainDisplayNativeHdrCreateInfoAMD));
	        	memoryToFree->push_back(vkSwapchainDisplayNativeHdrCreateInfoAMD);

	            getVkSwapchainDisplayNativeHdrCreateInfoAMD(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkSwapchainDisplayNativeHdrCreateInfoAMD,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkSwapchainDisplayNativeHdrCreateInfoAMD failed.");
	                return;
	            }

	            *headOfpNextChain = vkSwapchainDisplayNativeHdrCreateInfoAMD;
			}
			break;
			case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR");

	        	VkDeviceGroupPresentInfoKHR *vkDeviceGroupPresentInfoKHR = (VkDeviceGroupPresentInfoKHR *)calloc(1, sizeof(VkDeviceGroupPresentInfoKHR));
	        	memoryToFree->push_back(vkDeviceGroupPresentInfoKHR);

	            getVkDeviceGroupPresentInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDeviceGroupPresentInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDeviceGroupPresentInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkDeviceGroupPresentInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR");

	        	VkDisplayPresentInfoKHR *vkDisplayPresentInfoKHR = (VkDisplayPresentInfoKHR *)calloc(1, sizeof(VkDisplayPresentInfoKHR));
	        	memoryToFree->push_back(vkDisplayPresentInfoKHR);

	            getVkDisplayPresentInfoKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkDisplayPresentInfoKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkDisplayPresentInfoKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkDisplayPresentInfoKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR");

	        	VkPresentRegionsKHR *vkPresentRegionsKHR = (VkPresentRegionsKHR *)calloc(1, sizeof(VkPresentRegionsKHR));
	        	memoryToFree->push_back(vkPresentRegionsKHR);

	            getVkPresentRegionsKHR(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPresentRegionsKHR,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPresentRegionsKHR failed.");
	                return;
	            }

	            *headOfpNextChain = vkPresentRegionsKHR;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO");

	        	VkPhysicalDeviceExternalImageFormatInfo *vkPhysicalDeviceExternalImageFormatInfo = (VkPhysicalDeviceExternalImageFormatInfo *)calloc(1, sizeof(VkPhysicalDeviceExternalImageFormatInfo));
	        	memoryToFree->push_back(vkPhysicalDeviceExternalImageFormatInfo);

	            getVkPhysicalDeviceExternalImageFormatInfo(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceExternalImageFormatInfo,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceExternalImageFormatInfo failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceExternalImageFormatInfo;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT");

	        	VkPhysicalDeviceImageDrmFormatModifierInfoEXT *vkPhysicalDeviceImageDrmFormatModifierInfoEXT = (VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)calloc(1, sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceImageDrmFormatModifierInfoEXT);

	            getVkPhysicalDeviceImageDrmFormatModifierInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceImageDrmFormatModifierInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceImageDrmFormatModifierInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceImageDrmFormatModifierInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT");

	        	VkPhysicalDeviceImageViewImageFormatInfoEXT *vkPhysicalDeviceImageViewImageFormatInfoEXT = (VkPhysicalDeviceImageViewImageFormatInfoEXT *)calloc(1, sizeof(VkPhysicalDeviceImageViewImageFormatInfoEXT));
	        	memoryToFree->push_back(vkPhysicalDeviceImageViewImageFormatInfoEXT);

	            getVkPhysicalDeviceImageViewImageFormatInfoEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkPhysicalDeviceImageViewImageFormatInfoEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkPhysicalDeviceImageViewImageFormatInfoEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkPhysicalDeviceImageViewImageFormatInfoEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT");

	        	VkFilterCubicImageViewImageFormatPropertiesEXT *vkFilterCubicImageViewImageFormatPropertiesEXT = (VkFilterCubicImageViewImageFormatPropertiesEXT *)calloc(1, sizeof(VkFilterCubicImageViewImageFormatPropertiesEXT));
	        	memoryToFree->push_back(vkFilterCubicImageViewImageFormatPropertiesEXT);

	            getVkFilterCubicImageViewImageFormatPropertiesEXT(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkFilterCubicImageViewImageFormatPropertiesEXT,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkFilterCubicImageViewImageFormatPropertiesEXT failed.");
	                return;
	            }

	            *headOfpNextChain = vkFilterCubicImageViewImageFormatPropertiesEXT;
			}
			break;
			case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
			{
	        	LOGTRACE(env, "%s", "Handling VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID");

	        	VkExternalFormatANDROID *vkExternalFormatANDROID = (VkExternalFormatANDROID *)calloc(1, sizeof(VkExternalFormatANDROID));
	        	memoryToFree->push_back(vkExternalFormatANDROID);

	            getVkExternalFormatANDROID(
	                    env,
						jVulkanCreateInfoStructureObject,
						vkExternalFormatANDROID,
	                    memoryToFree);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Call to getVkExternalFormatANDROID failed.");
	                return;
	            }

	            *headOfpNextChain = vkExternalFormatANDROID;
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
