/*
 * Copyright 2019-2020 Douglas Kaip
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
 * populateVkPhysicalDeviceMeshShaderPropertiesNV.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceMeshShaderPropertiesNV(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMeshShaderPropertiesNVObject,
			const VkPhysicalDeviceMeshShaderPropertiesNV *vkPhysicalDeviceMeshShaderPropertiesNV,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass vkPhysicalDeviceMeshShaderPropertiesNVClass = env->GetObjectClass(
				jVkPhysicalDeviceMeshShaderPropertiesNVObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceMeshShaderPropertiesNV");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxDrawMeshTasksCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxDrawMeshTasksCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxDrawMeshTasksCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxTaskWorkGroupInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTaskWorkGroupInvocations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxTaskWorkGroupInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxTaskWorkGroupSize", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTaskWorkGroupSize");
            return;
        }

        jintArray maxTaskWorkGroupSize = env->NewIntArray(sizeof(vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize)/sizeof(int));
        if (maxTaskWorkGroupSize == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for maxTaskWorkGroupSize");
            return;
        }

        env->SetIntArrayRegion(maxTaskWorkGroupSize, 0, sizeof(vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize)/sizeof(int), (const jint *)vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, maxTaskWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxTaskTotalMemorySize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTaskTotalMemorySize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxTaskTotalMemorySize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxTaskOutputCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTaskOutputCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxTaskOutputCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshWorkGroupInvocations", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshWorkGroupInvocations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupInvocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshWorkGroupSize", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshWorkGroupSize");
            return;
        }

        jintArray maxMeshWorkGroupSize = env->NewIntArray(sizeof(vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize)/sizeof(int));
        if (maxMeshWorkGroupSize == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for maxMeshWorkGroupSize");
            return;
        }

        env->SetIntArrayRegion(maxMeshWorkGroupSize, 0, sizeof(vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize)/sizeof(int), (const jint *)vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, maxMeshWorkGroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshTotalMemorySize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshTotalMemorySize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshTotalMemorySize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshOutputVertices", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshOutputVertices");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshOutputVertices);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshOutputPrimitives", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshOutputPrimitives");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshOutputPrimitives);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMaxMeshMultiviewViewCount", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxMeshMultiviewViewCount");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->maxMeshMultiviewViewCount);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMeshOutputPerVertexGranularity", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMeshOutputPerVertexGranularity");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->meshOutputPerVertexGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(vkPhysicalDeviceMeshShaderPropertiesNVClass, "setMeshOutputPerPrimitiveGranularity", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMeshOutputPerPrimitiveGranularity");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceMeshShaderPropertiesNVObject, methodId, vkPhysicalDeviceMeshShaderPropertiesNV->meshOutputPerPrimitiveGranularity);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
