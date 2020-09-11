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
 * populateVkPhysicalDeviceLineRasterizationPropertiesEXT.cpp
 *
 *  Created on: Sep 8, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceLineRasterizationPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceLineRasterizationPropertiesEXTObject,
			const VkPhysicalDeviceLineRasterizationPropertiesEXT *vkPhysicalDeviceLineRasterizationPropertiesEXT)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPhysicalDeviceLineRasterizationPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceLineRasterizationPropertiesEXTObject");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setLineSubPixelPrecisionBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLineSubPixelPrecisionBits");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceLineRasterizationPropertiesEXTObject, methodId, vkPhysicalDeviceLineRasterizationPropertiesEXT->lineSubPixelPrecisionBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
