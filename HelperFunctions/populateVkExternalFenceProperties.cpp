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
 * populateVkExternalFenceProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkExternalFenceProperties(
    		JNIEnv *env,
			jobject jVkExternalFencePropertiesObject,
			const VkExternalFenceProperties *vkExternalFenceProperties)
    {
		if (jVkExternalFencePropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkExternalFencePropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExternalFencePropertiesObject == nullptr");
			return;
		}

		if (vkExternalFenceProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkExternalFenceProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExternalFenceProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkExternalFencePropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalFenceProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalFenceHandleTypeFlags = createVkExternalFenceHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalFenceProperties->exportFromImportedHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalMemoryFeatureFlagsAsEnumSet.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setExportFromImportedHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExportFromImportedHandleTypes");
            return;
        }

        env->CallVoidMethod(jVkExternalFencePropertiesObject, methodId, VkExternalFenceHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        VkExternalFenceHandleTypeFlags = createVkExternalFenceHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalFenceProperties->compatibleHandleTypes);
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

        env->CallVoidMethod(jVkExternalFencePropertiesObject, methodId, VkExternalFenceHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalFenceFeatureFlags = createVkExternalFenceFeatureFlagsAsEnumSet(
        		env,
				vkExternalFenceProperties->externalFenceFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalMemoryHandleTypeFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setExternalFenceFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExternalFenceFeatures");
            return;
        }

        env->CallVoidMethod(jVkExternalFencePropertiesObject, methodId, VkExternalFenceFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
