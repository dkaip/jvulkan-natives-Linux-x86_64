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
 * getVkPhysicalDeviceVulkan11Features.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceVulkan11Features(
            JNIEnv *env,
            jobject jVkPhysicalDeviceVulkan11FeaturesObject,
			VkPhysicalDeviceVulkan11Features *vkPhysicalDeviceVulkan11Features,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceVulkan11FeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceVulkan11FeaturesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceVulkan11FeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceVulkan11FeaturesObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isStorageBuffer16BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageBuffer16BitAccess.");
            return;
        }

        VkBool32 storageBuffer16BitAccess = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isUniformAndStorageBuffer16BitAccess", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isUniformAndStorageBuffer16BitAccess.");
            return;
        }

        VkBool32 uniformAndStorageBuffer16BitAccess = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStoragePushConstant16", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStoragePushConstant16.");
            return;
        }

        VkBool32 storagePushConstant16 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isStorageInputOutput16", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isStorageInputOutput16.");
            return;
        }

        VkBool32 storageInputOutput16 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isMultiview", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isMultiview.");
            return;
        }

        VkBool32 multiview = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isMultiviewGeometryShader", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isMultiviewGeometryShader.");
            return;
        }

        VkBool32 multiviewGeometryShader = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isMultiviewTessellationShader", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isMultiviewTessellationShader.");
            return;
        }

        VkBool32 multiviewTessellationShader = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVariablePointersStorageBuffer", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVariablePointersStorageBuffer.");
            return;
        }

        VkBool32 variablePointersStorageBuffer = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isVariablePointers", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isVariablePointers.");
            return;
        }

        VkBool32 variablePointers = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isProtectedMemory", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isProtectedMemory.");
            return;
        }

        VkBool32 protectedMemory = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSamplerYcbcrConversion", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSamplerYcbcrConversion.");
            return;
        }

        VkBool32 samplerYcbcrConversion = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderDrawParameters", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderDrawParameters.");
            return;
        }

        VkBool32 shaderDrawParameters = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceVulkan11FeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceVulkan11Features->sType 	= sTypeValue;
        vkPhysicalDeviceVulkan11Features->pNext 	= (void *)pNext;
        vkPhysicalDeviceVulkan11Features->storageBuffer16BitAccess	= storageBuffer16BitAccess;
        vkPhysicalDeviceVulkan11Features->uniformAndStorageBuffer16BitAccess	= uniformAndStorageBuffer16BitAccess;
        vkPhysicalDeviceVulkan11Features->storagePushConstant16	= storagePushConstant16;
        vkPhysicalDeviceVulkan11Features->storageInputOutput16	= storageInputOutput16;
        vkPhysicalDeviceVulkan11Features->multiview	= multiview;
        vkPhysicalDeviceVulkan11Features->multiviewGeometryShader	= multiviewGeometryShader;
        vkPhysicalDeviceVulkan11Features->multiviewTessellationShader	= multiviewTessellationShader;
        vkPhysicalDeviceVulkan11Features->variablePointersStorageBuffer	= variablePointersStorageBuffer;
        vkPhysicalDeviceVulkan11Features->variablePointers	= variablePointers;
        vkPhysicalDeviceVulkan11Features->protectedMemory	= protectedMemory;
        vkPhysicalDeviceVulkan11Features->samplerYcbcrConversion	= samplerYcbcrConversion;
        vkPhysicalDeviceVulkan11Features->shaderDrawParameters	= shaderDrawParameters;
    }
}
