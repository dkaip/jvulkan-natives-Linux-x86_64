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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkCooperativeMatrixPropertiesNV",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "setmSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setmSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkCooperativeMatrixPropertiesNV->MSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setnSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setnSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkCooperativeMatrixPropertiesNV->NSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setkSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setkSize");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, vkCooperativeMatrixPropertiesNV->KSize);
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

		methodId = env->GetMethodID(theClass, "setaType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setaType");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkComponentTypeNV);
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

		methodId = env->GetMethodID(theClass, "setbType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setbType");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkComponentTypeNV);
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

		methodId = env->GetMethodID(theClass, "setcType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setcType");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkComponentTypeNV);
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

		methodId = env->GetMethodID(theClass, "setdType", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkComponentTypeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setdType");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkComponentTypeNV);
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

		methodId = env->GetMethodID(theClass, "setScope", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkScopeNV;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setScope");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jVkScopeNV);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return nullptr;
        }

        return theObject;
	}
}
