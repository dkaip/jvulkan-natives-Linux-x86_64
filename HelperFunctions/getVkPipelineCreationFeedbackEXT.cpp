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
 * getVkPipelineCreationFeedbackEXT.cpp
 *
 *  Created on: May 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineCreationFeedbackEXT(
            JNIEnv *env,
            const jobject jVkPipelineCreationFeedbackEXTObject,
			VkPipelineCreationFeedbackEXT *vkPipelineCreationFeedbackEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineCreationFeedbackEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineCreationFeedbackEXTObject");
            return;
        }

		////////////////////////////////////////////////////////////////////////
		jmethodID methodId = env->GetMethodID(theClass, "getFlags", "()Ljava/util/EnumSet;");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
			return;
		}

		jobject flagsObject = env->CallObjectMethod(jVkPipelineCreationFeedbackEXTObject, methodId);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
			return;
		}

		VkPipelineCreationFeedbackFlagsEXT flags = (VkPipelineCreationFeedbackFlagsEXT)getEnumSetValue(
				env,
				flagsObject,
				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineCreationFeedbackFlagBitsEXT");
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getDuration", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getDuration");
            return;
        }

        jlong duration = env->CallLongMethod(jVkPipelineCreationFeedbackEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }


        vkPipelineCreationFeedbackEXT->flags = flags;
        vkPipelineCreationFeedbackEXT->duration = duration;
    }
}
