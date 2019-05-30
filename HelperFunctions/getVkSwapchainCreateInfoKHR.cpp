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
 * getSwapchainCreateInfoKHR.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSwapchainCreateInfoKHR(
			JNIEnv *env,
			const jobject jVkSwapchainCreateInfoKHR,
			VkSwapchainCreateInfoKHR *swapchainCreateInfo,
			std::vector<void *> *memoryToFree)
	{
		jclass vkSwapchainCreateInfoKHRClass = env->GetObjectClass(jVkSwapchainCreateInfoKHR);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		int sTypeValue = getSTypeAsInt(env, jVkSwapchainCreateInfoKHR);
		if (env->ExceptionOccurred())
		{
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkSwapchainCreateInfoKHR);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
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
                return;
            }
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		int32_t flags = getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkSwapchainCreateFlagBitsKHR");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getSurface", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject jSurfaceHandle = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)getHandleValue(env, jSurfaceHandle);

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getMinImageCount", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint minImageCount = env->CallIntMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject imageFormatEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass imageFormatEnumClass = env->GetObjectClass(imageFormatEnumObject);

		jmethodID valueOfMethodId = env->GetMethodID(imageFormatEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint imageFormatEnumValue = env->CallIntMethod(imageFormatEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageColorSpace", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject imageColorSpaceEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass imageColorSpaceEnumClass = env->GetObjectClass(imageColorSpaceEnumObject);

		valueOfMethodId = env->GetMethodID(imageColorSpaceEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint imageColorSpaceEnumValue = env->CallIntMethod(imageColorSpaceEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject imageImageExtentObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		VkExtent2D *imageExtent = nullptr;

		if (imageImageExtentObject != nullptr)
		{
			imageExtent = (VkExtent2D *)calloc(1, sizeof(VkExtent2D));

			jclass imageImageExtentClass = env->GetObjectClass(imageImageExtentObject);

			methodId = env->GetMethodID(imageImageExtentClass, "getWidth", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint extentWidth = env->CallIntMethod(imageImageExtentObject, methodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			methodId = env->GetMethodID(imageImageExtentClass, "getHeight", "()I");
			if (env->ExceptionOccurred())
			{
				return;
			}

			jint extentHeight = env->CallIntMethod(imageImageExtentObject, methodId);
			if (env->ExceptionOccurred())
			{
				return;
			}

			imageExtent->width = extentWidth;
			imageExtent->height = extentHeight;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageArrayLayers", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint imageArrayLayers = env->CallIntMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageUsage", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject imageUsageObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		int32_t imageUsage = getEnumSetValue(
				env,
				imageUsageObject,
				"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits");

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSharingMode;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject imageSharingModeEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass imageSharingModeEnumClass = env->GetObjectClass(imageSharingModeEnumObject);

		valueOfMethodId = env->GetMethodID(imageSharingModeEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint imageSharingModeEnumValue = env->CallIntMethod(imageSharingModeEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getQueueFamilyIndices", "()[I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		int *queueFamilyIndicesArray = nullptr;
		jsize arrayLength = 0;
		if (jQueueFamilyIndices != nullptr)
		{
			arrayLength = env->GetArrayLength(jQueueFamilyIndices);

			queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
			memoryToFree->push_back(queueFamilyIndicesArray);

			env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
			if (env->ExceptionOccurred())
			{
				return;
			}
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPreTransform", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject preTransformEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass preTransformEnumClass = env->GetObjectClass(preTransformEnumObject);

		valueOfMethodId = env->GetMethodID(preTransformEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint preTransformEnumClassValue = env->CallIntMethod(preTransformEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getCompositeAlpha", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject compositeAlphaEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass compositeAlphaEnumClass = env->GetObjectClass(compositeAlphaEnumObject);

		valueOfMethodId = env->GetMethodID(compositeAlphaEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint compositeAlphaEnumClassValue = env->CallIntMethod(compositeAlphaEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPresentMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject presentModeEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jclass presentModeEnumClass = env->GetObjectClass(presentModeEnumObject);

		valueOfMethodId = env->GetMethodID(presentModeEnumClass, "valueOf", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint presentModeEnumClassValue = env->CallIntMethod(presentModeEnumObject, valueOfMethodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getClipped", "()Z");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jboolean jclipped = env->CallBooleanMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		bool clipped = false;
		if (jclipped != 0)
		{
			clipped = true;
		}

		////////////////////////////////////////////////////////////////////////
		VkSwapchainKHR_T *oldSwapchainHandle = nullptr;

		methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getOldSwapchain", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSwapchainKHR;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject jOldSwapchainHandle = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		if (jOldSwapchainHandle != nullptr)
		{
			oldSwapchainHandle = (VkSwapchainKHR_T *)getHandleValue(env, jOldSwapchainHandle);
		}

		swapchainCreateInfo->sType = (VkStructureType)sTypeValue;
		swapchainCreateInfo->pNext = (void *)pNext;
		swapchainCreateInfo->flags = flags;
		swapchainCreateInfo->surface = surfaceHandle;
		swapchainCreateInfo->minImageCount = minImageCount;
		swapchainCreateInfo->imageFormat = (VkFormat)imageFormatEnumValue;
		swapchainCreateInfo->imageColorSpace = (VkColorSpaceKHR)imageColorSpaceEnumValue;

		if (imageExtent != nullptr)
		{
			swapchainCreateInfo->imageExtent.width = imageExtent->width;
			swapchainCreateInfo->imageExtent.height = imageExtent->height;
		}
		else
		{
			swapchainCreateInfo->imageExtent.width = 0;
			swapchainCreateInfo->imageExtent.height = 0;
		}

		free(imageExtent);

		swapchainCreateInfo->imageArrayLayers = imageArrayLayers;
		swapchainCreateInfo->imageUsage = imageUsage;
		swapchainCreateInfo->imageSharingMode = (VkSharingMode)imageSharingModeEnumValue;
		swapchainCreateInfo->queueFamilyIndexCount = arrayLength;
		swapchainCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
		swapchainCreateInfo->preTransform = (VkSurfaceTransformFlagBitsKHR)preTransformEnumClassValue;
		swapchainCreateInfo->compositeAlpha = (VkCompositeAlphaFlagBitsKHR)compositeAlphaEnumClassValue;
		swapchainCreateInfo->presentMode = (VkPresentModeKHR)presentModeEnumClassValue;
		swapchainCreateInfo->clipped = clipped;
		swapchainCreateInfo->oldSwapchain = oldSwapchainHandle;
	}
}
