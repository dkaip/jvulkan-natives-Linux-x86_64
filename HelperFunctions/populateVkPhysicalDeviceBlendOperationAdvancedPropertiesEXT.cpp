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
 * createVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT.cpp
 *
 *  Created on: May 12, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject,
			const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass = env->GetObjectClass(
				jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
			return;
		}

//		jclass vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass = env->FindClass(
//				"com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
//		if (env->ExceptionOccurred())
//		{
//			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
//			return nullptr;
//		}

//		// Locate the constructor
//		jmethodID methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "<init>", "()V");
//		if (env->ExceptionOccurred())
//		{
//		   	LOGERROR(env, "%s", "Could not find method id <init> for class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
//		    return;
//		}

//		// Create the Java vkPhysicalDeviceProperties object
//		jobject jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject =
//		  		env->NewObject(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, methodId);
//		if (env->ExceptionOccurred())
//		{
//		   	LOGERROR(env, "%s", "Could construct class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT");
//		    return nullptr;
//		}
//
//		LOGINFO(env, "advancedBlendMaxColorAttachments:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendMaxColorAttachments);
//		LOGINFO(env, "advancedBlendIndependentBlend:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendIndependentBlend);
//		LOGINFO(env, "advancedBlendNonPremultipliedSrcColor:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendNonPremultipliedSrcColor);
//		LOGINFO(env, "advancedBlendNonPremultipliedDstColor:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendNonPremultipliedDstColor);
//		LOGINFO(env, "advancedBlendCorrelatedOverlap:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendCorrelatedOverlap);
//		LOGINFO(env, "advancedBlendAllOperations:%d", vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendAllOperations);
        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendMaxColorAttachments", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendMaxColorAttachments");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendMaxColorAttachments);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendIndependentBlend", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendIndependentBlend");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendIndependentBlend);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendNonPremultipliedSrcColor", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendNonPremultipliedSrcColor");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendNonPremultipliedSrcColor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendNonPremultipliedDstColor", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendNonPremultipliedDstColor");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendNonPremultipliedDstColor);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendCorrelatedOverlap", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendCorrelatedOverlap");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendCorrelatedOverlap);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPhysicalDeviceBlendOperationAdvancedPropertiesEXTClass, "setAdvancedBlendAllOperations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setAdvancedBlendAllOperations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->advancedBlendAllOperations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

//        ///////////////////////////////////////////////////////////////////////////
//    	jobject pNextObject = populatepNextChain(
//    			env,
//				vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->pNext,
//    			memoryToFree);
//
//        jclass vulkanStructureClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
//            return;
//        }
//
//
//        methodId = env->GetMethodID(vulkanStructureClass, "setpNext", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure;)V");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id setpNext");
//            return;
//        }
//
//        env->CallVoidMethod(jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject, methodId, pNextObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", voidMethodErrorText);
//            return;
//        }
	}
}
