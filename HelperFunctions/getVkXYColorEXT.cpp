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
 * getVkXYColorEXT.cpp
 *
 *  Created on: Oct 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkXYColorEXT(
			JNIEnv *env,
			jobject jVkXYColorEXTObject,
			VkXYColorEXT *vkXYColorEXT,
			std::vector<void *> *memoryToFree)
	{
		jclass theClass = env->GetObjectClass(jVkXYColorEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get class for jVkXYColorEXTObject");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getX", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getX");
            return;
        }

        jfloat x = env->CallFloatMethod(jVkXYColorEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getY", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getY");
            return;
        }

        jfloat y = env->CallFloatMethod(jVkXYColorEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        vkXYColorEXT->x = x;
        vkXYColorEXT->y = y;
	}
}
