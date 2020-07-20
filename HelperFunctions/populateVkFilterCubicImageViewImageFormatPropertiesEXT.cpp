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
 * populateVkFilterCubicImageViewImageFormatPropertiesEXT.cpp
 *
 *  Created on: Jun 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkFilterCubicImageViewImageFormatPropertiesEXT(
			JNIEnv *env,
			jobject jVkFilterCubicImageViewImageFormatPropertiesEXTObject,
			const VkFilterCubicImageViewImageFormatPropertiesEXT* vkFilterCubicImageViewImageFormatPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		if (jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkFilterCubicImageViewImageFormatPropertiesEXTObject == nullptr");
			return;
		}

		if (vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr)
		{
			LOGERROR(env, "%s", "vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkFilterCubicImageViewImageFormatPropertiesEXT == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkFilterCubicImageViewImageFormatPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkFilterCubicImageViewImageFormatPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setFilterCubic", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFilterCubic");
            return;
        }

        env->CallVoidMethod(jVkFilterCubicImageViewImageFormatPropertiesEXTObject, methodId, vkFilterCubicImageViewImageFormatPropertiesEXT->filterCubic);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setFilterCubicMinmax", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFilterCubicMinmax");
            return;
        }

        env->CallVoidMethod(jVkFilterCubicImageViewImageFormatPropertiesEXTObject, methodId, vkFilterCubicImageViewImageFormatPropertiesEXT->filterCubicMinmax);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
