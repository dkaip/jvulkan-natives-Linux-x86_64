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
			default:
				LOGWARN(env, "Unhandled sType of %d", sTypeValue);
			break;
        }

        // We are done
        return;
	}
}
