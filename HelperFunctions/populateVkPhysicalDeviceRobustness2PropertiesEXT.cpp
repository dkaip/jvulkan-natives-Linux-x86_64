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
 * populateVkPhysicalDeviceRobustness2PropertiesEXT.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceRobustness2PropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceRobustness2PropertiesEXTObject,
			const VkPhysicalDeviceRobustness2PropertiesEXT *vkPhysicalDeviceRobustness2PropertiesEXT)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceRobustness2PropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceRobustness2PropertiesEXTObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setRobustStorageBufferAccessSizeAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRobustStorageBufferAccessSizeAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRobustness2PropertiesEXTObject, methodId, vkPhysicalDeviceRobustness2PropertiesEXT->robustStorageBufferAccessSizeAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setRobustUniformBufferAccessSizeAlignment", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRobustUniformBufferAccessSizeAlignment");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceRobustness2PropertiesEXTObject, methodId, vkPhysicalDeviceRobustness2PropertiesEXT->robustUniformBufferAccessSizeAlignment);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
