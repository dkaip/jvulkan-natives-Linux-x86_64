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
 * getVkPresentTimeGOOGLE.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPresentTimeGOOGLE(
            JNIEnv *env,
            jobject jVkPresentTimeGOOGLEObject,
			VkPresentTimeGOOGLE *vkPresentTimeGOOGLE,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPresentTimeGOOGLEObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPresentTimeGOOGLEObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getPresentID", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getPresentID.");
            return;
        }

        uint32_t presentID = (uint32_t)env->CallIntMethod(jVkPresentTimeGOOGLEObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling .CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDesiredPresentTime", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getDesiredPresentTime.");
            return;
        }

        uint64_t desiredPresentTime = (uint64_t)env->CallLongMethod(jVkPresentTimeGOOGLEObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling .CallLongMethod");
            return;
        }


        vkPresentTimeGOOGLE->presentID = presentID;
        vkPresentTimeGOOGLE->desiredPresentTime = desiredPresentTime;
    }
}
