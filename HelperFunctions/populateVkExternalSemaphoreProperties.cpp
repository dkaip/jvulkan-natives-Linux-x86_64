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
 * populateVkExternalSemaphoreProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkExternalSemaphoreProperties(
    		JNIEnv *env,
			jobject jVkExternalSemaphorePropertiesObject,
			const VkExternalSemaphoreProperties *vkExternalSemaphoreProperties)
    {
		if (jVkExternalSemaphorePropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkExternalSemaphorePropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExternalSemaphorePropertiesObject == nullptr");
			return;
		}

		if (vkExternalSemaphoreProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkExternalSemaphoreProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExternalSemaphoreProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkExternalSemaphorePropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkExternalSemaphoreProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalSemaphoreHandleTypeFlags = createVkExternalSemaphoreHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalSemaphoreProperties->exportFromImportedHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalSemaphoreHandleTypeFlagsAsEnumSet.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setExportFromImportedHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExportFromImportedHandleTypes");
            return;
        }

        env->CallVoidMethod(jVkExternalSemaphorePropertiesObject, methodId, VkExternalSemaphoreHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        VkExternalSemaphoreHandleTypeFlags = createVkExternalSemaphoreHandleTypeFlagsAsEnumSet(
        		env,
				vkExternalSemaphoreProperties->compatibleHandleTypes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalSemaphoreHandleTypeFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setCompatibleHandleTypes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setCompatibleHandleTypes");
            return;
        }

        env->CallVoidMethod(jVkExternalSemaphorePropertiesObject, methodId, VkExternalSemaphoreHandleTypeFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject VkExternalSemaphoreFeatureFlags = createVkExternalSemaphoreFeatureFlagsAsEnumSet(
        		env,
				vkExternalSemaphoreProperties->externalSemaphoreFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExternalSemaphoreFeatureFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setExternalSemaphoreFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setExternalSemaphoreFeatures");
            return;
        }

        env->CallVoidMethod(jVkExternalSemaphorePropertiesObject, methodId, VkExternalSemaphoreFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
