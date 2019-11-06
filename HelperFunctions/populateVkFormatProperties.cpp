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
 * populateVkFormatProperties.cpp
 *
 *  Created on: Nov 5, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkFormatProperties(
    		JNIEnv *env,
			jobject jVkFormatPropertiesObject,
			const VkFormatProperties *vkFormatProperties)
    {
		if (jVkFormatPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkFormatPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkFormatPropertiesObject == nullptr");
			return;
		}

		if (vkFormatProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkFormatProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkFormatProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkFormatPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkFormatProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jobject vkFormatFeatureFlags = createVkFormatFeatureFlagsAsEnumSet(
        		env,
				vkFormatProperties->linearTilingFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkFormatFeatureFlagsAsEnumSet.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "setLinearTilingFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLinearTilingFeatures");
            return;
        }

        env->CallVoidMethod(jVkFormatPropertiesObject, methodId, vkFormatFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        vkFormatFeatureFlags = createVkFormatFeatureFlagsAsEnumSet(
        		env,
				vkFormatProperties->optimalTilingFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkFormatFeatureFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setOptimalTilingFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOptimalTilingFeatures");
            return;
        }

        env->CallVoidMethod(jVkFormatPropertiesObject, methodId, vkFormatFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        vkFormatFeatureFlags = createVkFormatFeatureFlagsAsEnumSet(
        		env,
				vkFormatProperties->bufferFeatures);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkFormatFeatureFlagsAsEnumSet.");
            return;
        }

        methodId = env->GetMethodID(theClass, "setBufferFeatures", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setBufferFeatures");
            return;
        }

        env->CallVoidMethod(jVkFormatPropertiesObject, methodId, vkFormatFeatureFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        return;
    }
}
