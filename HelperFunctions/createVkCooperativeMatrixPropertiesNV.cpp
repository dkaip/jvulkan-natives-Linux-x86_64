/*
 * Copyright 2020 Douglas Kaip
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
 * createVkCooperativeMatrixPropertiesNV.cpp
 *
 *  Created on: Sep 1, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	jobject createVkCooperativeMatrixPropertiesNV(
			JNIEnv *env,
			VkCooperativeMatrixPropertiesNV const *vkCooperativeMatrixPropertiesNV)
	{
		if (vkCooperativeMatrixPropertiesNV == nullptr)
		{
			LOGERROR(env, "%s", "vkCooperativeMatrixPropertiesNV == nullptr");
			return nullptr;
		}

		jclass vkCooperativeMatrixPropertiesNVClass = env->FindClass(
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCooperativeMatrixPropertiesNV");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCooperativeMatrixPropertiesNV");
            return nullptr;
        }

		// Locate the constructor
		jmethodID methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id <init> ()V");
            return nullptr;
        }

		jobject jVkCooperativeMatrixPropertiesNVObject =
				env->NewObject(vkCooperativeMatrixPropertiesNVClass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling <init>(constructor)");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setmSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setmSize");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, vkCooperativeMatrixPropertiesNV->MSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setnSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setnSize");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, vkCooperativeMatrixPropertiesNV->NSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setkSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setkSize");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, vkCooperativeMatrixPropertiesNV->KSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkComponentTypeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV",
				vkCooperativeMatrixPropertiesNV->AType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setaType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setaType");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, jVkComponentTypeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jVkComponentTypeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV",
				vkCooperativeMatrixPropertiesNV->BType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setbType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setbType");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, jVkComponentTypeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jVkComponentTypeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV",
				vkCooperativeMatrixPropertiesNV->CType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setcType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setcType");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, jVkComponentTypeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jVkComponentTypeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV",
				vkCooperativeMatrixPropertiesNV->DType);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setdType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setdType");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, jVkComponentTypeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
    	jobject jVkScopeNV = createEnumFromValue(
    			env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkScopeNV",
				vkCooperativeMatrixPropertiesNV->scope);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createEnumFromValue.");
            return nullptr;
        }

		methodId = env->GetMethodID(vkCooperativeMatrixPropertiesNVClass, "setScope", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkScopeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setScope");
            return nullptr;
        }

        env->CallVoidMethod(jVkCooperativeMatrixPropertiesNVObject, methodId, jVkScopeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return jVkCooperativeMatrixPropertiesNVObject;
	}
}
