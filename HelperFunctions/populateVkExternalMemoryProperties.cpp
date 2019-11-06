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
 * populateVkExternalMemoryProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkExternalMemoryProperties(
    		JNIEnv *env,
			jobject jVkExternalMemoryPropertiesObject,
			const VkExternalMemoryProperties *vkExternalMemoryProperties)
    {
		if (jVkExternalMemoryPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkExternalMemoryPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExternalMemoryPropertiesObject == nullptr");
			return;
		}

		if (vkExternalMemoryProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkExternalMemoryProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExternalMemoryProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkExternalMemoryPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExternalMemoryProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalMemoryFeatureFlags = createVkExternalMemoryFeatureFlagsAsEnumSet(
        		env,
				vkExternalMemoryProperties->externalMemoryFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalMemoryFeatureFlagsAsEnumSet.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setExternalMemoryFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExternalMemoryFeatures");
            return;
        }

        env->CallVoidMethod(jVkExternalMemoryPropertiesObject, methodId, VkExternalMemoryFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalMemoryHandleTypeFlags = createVkExternalMemoryHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalMemoryProperties->exportFromImportedHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalMemoryHandleTypeFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setExportFromImportedHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExportFromImportedHandleTypes");
            return;
        }

        env->CallVoidMethod(jVkExternalMemoryPropertiesObject, methodId, VkExternalMemoryHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        VkExternalMemoryHandleTypeFlags = createVkExternalMemoryHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalMemoryProperties->compatibleHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalMemoryHandleTypeFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setCompatibleHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCompatibleHandleTypes");
            return;
        }

        env->CallVoidMethod(jVkExternalMemoryPropertiesObject, methodId, VkExternalMemoryHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
