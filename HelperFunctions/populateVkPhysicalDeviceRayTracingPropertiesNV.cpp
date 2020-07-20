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
 * populateVkPhysicalDeviceRayTracingPropertiesNV.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceRayTracingPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceRayTracingPropertiesNVObject,
			const VkPhysicalDeviceRayTracingPropertiesNV *vkPhysicalDeviceRayTracingPropertiesNV,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceRayTracingPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceRayTracingPropertiesNV");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setShaderGroupHandleSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderGroupHandleSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->shaderGroupHandleSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxRecursionDepth", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxRecursionDepth");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxRecursionDepth);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxShaderGroupStride", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxShaderGroupStride");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxShaderGroupStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setShaderGroupBaseAlignment", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setShaderGroupBaseAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->shaderGroupBaseAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxGeometryCount", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxGeometryCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxGeometryCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxInstanceCount", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxInstanceCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxInstanceCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTriangleCount", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTriangleCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxTriangleCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxDescriptorSetAccelerationStructures", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDescriptorSetAccelerationStructures");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRayTracingPropertiesNVObject, methodId, vkPhysicalDeviceRayTracingPropertiesNV->maxDescriptorSetAccelerationStructures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
