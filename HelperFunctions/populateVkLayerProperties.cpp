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
 * populateVkLayerProperties.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkLayerProperties(
    		JNIEnv *env,
			jobject jVkLayerPropertiesObject,
			const VkLayerProperties *vkLayerProperties)
    {
		if (jVkLayerPropertiesObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkLayerPropertiesObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkLayerPropertiesObject == nullptr");
			return;
		}

		if (vkLayerProperties == nullptr)
		{
			LOGERROR(env, "%s", "vkLayerProperties == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkLayerProperties == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkLayerPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/Structures/VkLayerProperties");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setLayerName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLayerName");
            return;
        }

        jstring layerNameString = env->NewStringUTF(vkLayerProperties->layerName);

        env->CallVoidMethod(jVkLayerPropertiesObject, methodId, layerNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(layerNameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSpecVersion", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSpecVersion");
            return;
        }

        env->CallVoidMethod(jVkLayerPropertiesObject, methodId, vkLayerProperties->specVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setImplementationVersion", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setImplementationVersion");
            return;
        }

        env->CallVoidMethod(jVkLayerPropertiesObject, methodId, vkLayerProperties->implementationVersion);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDescription", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDescription");
            return;
        }

        jstring descriptionString = env->NewStringUTF(vkLayerProperties->description);

        env->CallVoidMethod(jVkLayerPropertiesObject, methodId, descriptionString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(descriptionString);

        return;
    }
}
