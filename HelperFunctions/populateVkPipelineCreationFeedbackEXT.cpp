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
 * populateVkPipelineCreationFeedbackEXT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPipelineCreationFeedbackEXT(
			JNIEnv *env,
			jobject jVkPipelineCreationFeedbackEXTObject,
			const VkPipelineCreationFeedbackEXT *vkPipelineCreationFeedbackEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPipelineCreationFeedbackEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineCreationFeedbackEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFlags");
            return;
        }

        jobject jflags = createVkPipelineCreationFeedbackFlagsEXTAsEnumSet(env, vkPipelineCreationFeedbackEXT->flags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkPipelineCreationFeedbackFlagsEXTAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPipelineCreationFeedbackEXTObject, methodId, jflags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDuration", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDuration");
            return;
        }

        env->CallVoidMethod(jVkPipelineCreationFeedbackEXTObject, methodId, vkPipelineCreationFeedbackEXT->duration);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

//        LOGERROR(env, "flags:%d duration:%ld", vkPipelineCreationFeedbackEXT->flags, vkPipelineCreationFeedbackEXT->duration);
	}
}
