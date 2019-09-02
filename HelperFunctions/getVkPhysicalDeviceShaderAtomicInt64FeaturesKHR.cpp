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
 * getVkPhysicalDeviceShaderAtomicInt64FeaturesKHR.cpp
 *
 *  Created on: May 19, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceShaderAtomicInt64FeaturesKHR(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject,
			VkPhysicalDeviceShaderAtomicInt64FeaturesKHR *vkPhysicalDeviceShaderAtomicInt64FeaturesKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "isShaderBufferInt64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderBufferInt64Atomics");
            return;
        }

        jboolean shaderBufferInt64Atomics = env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSharedInt64Atomics", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSharedInt64Atomics");
            return;
        }

        jboolean shaderSharedInt64Atomics = env->CallBooleanMethod(jVkPhysicalDeviceShaderAtomicInt64FeaturesKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }


        vkPhysicalDeviceShaderAtomicInt64FeaturesKHR->sType = sTypeValue;
        vkPhysicalDeviceShaderAtomicInt64FeaturesKHR->pNext = pNext;
        vkPhysicalDeviceShaderAtomicInt64FeaturesKHR->shaderBufferInt64Atomics = shaderBufferInt64Atomics;
        vkPhysicalDeviceShaderAtomicInt64FeaturesKHR->shaderSharedInt64Atomics = shaderSharedInt64Atomics;
    }
}
