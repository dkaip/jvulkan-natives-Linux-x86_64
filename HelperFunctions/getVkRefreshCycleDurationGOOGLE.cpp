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
 * getVkRefreshCycleDurationGOOGLE.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkRefreshCycleDurationGOOGLE(
        JNIEnv *env,
        const jobject jVkRefreshCycleDurationGOOGLEObject,
		VkRefreshCycleDurationGOOGLE *vkRefreshCycleDurationGOOGLE,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRefreshCycleDurationGOOGLEObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkRefreshCycleDurationGOOGLEObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getRefreshDuration", "()J");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getRefreshDuration");
			return;
		}

		jlong refreshDuration = env->CallLongMethod(jVkRefreshCycleDurationGOOGLEObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
			return;
		}


		vkRefreshCycleDurationGOOGLE->refreshDuration = refreshDuration;
    }
}
