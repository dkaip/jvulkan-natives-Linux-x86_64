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
 * getVkPhysicalDeviceShaderAtomicFloatFeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceShaderAtomicFloatFeaturesEXT(
            JNIEnv *env,
            jobject jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject,
			VkPhysicalDeviceShaderAtomicFloatFeaturesEXT *vkPhysicalDeviceShaderAtomicFloatFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShaderBufferFloat32Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferFloat32Atomics.");
            return;
        }

        VkBool32 shaderBufferFloat32Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderBufferFloat32AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferFloat32AtomicAdd.");
            return;
        }

        VkBool32 shaderBufferFloat32AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderBufferFloat64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferFloat64Atomics.");
            return;
        }

        VkBool32 shaderBufferFloat64Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderBufferFloat64AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferFloat64AtomicAdd.");
            return;
        }

        VkBool32 shaderBufferFloat64AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedFloat32Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedFloat32Atomics.");
            return;
        }

        VkBool32 shaderSharedFloat32Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedFloat32AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedFloat32AtomicAdd.");
            return;
        }

        VkBool32 shaderSharedFloat32AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedFloat64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedFloat64Atomics.");
            return;
        }

        VkBool32 shaderSharedFloat64Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedFloat64AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedFloat64AtomicAdd.");
            return;
        }

        VkBool32 shaderSharedFloat64AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderImageFloat32Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderImageFloat32Atomics.");
            return;
        }

        VkBool32 shaderImageFloat32Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderImageFloat32AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isCustomBorderColorWithoutFormat.");
            return;
        }

        VkBool32 shaderImageFloat32AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSparseImageFloat32Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSparseImageFloat32Atomics.");
            return;
        }

        VkBool32 sparseImageFloat32Atomics = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isSparseImageFloat32AtomicAdd", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isSparseImageFloat32AtomicAdd.");
            return;
        }

        VkBool32 sparseImageFloat32AtomicAdd = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicFloatFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
            return;
        }


        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->sType 	= sTypeValue;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->pNext 	= (void *)pNext;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderBufferFloat32Atomics	= shaderBufferFloat32Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderBufferFloat32AtomicAdd	= shaderBufferFloat32AtomicAdd;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderBufferFloat64Atomics	= shaderBufferFloat64Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderBufferFloat64AtomicAdd	= shaderBufferFloat64AtomicAdd;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderSharedFloat32Atomics	= shaderSharedFloat32Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderSharedFloat32AtomicAdd	= shaderSharedFloat32AtomicAdd;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderSharedFloat64Atomics	= shaderSharedFloat64Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderSharedFloat64AtomicAdd	= shaderSharedFloat64AtomicAdd;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderImageFloat32Atomics	= shaderImageFloat32Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->shaderImageFloat32AtomicAdd	= shaderImageFloat32AtomicAdd;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->sparseImageFloat32Atomics	= sparseImageFloat32Atomics;
        vkPhysicalDeviceShaderAtomicFloatFeaturesEXT->sparseImageFloat32AtomicAdd	= sparseImageFloat32AtomicAdd;
    }
}
