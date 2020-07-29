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
 * populateVkPipelineCreationFeedbackCreateInfoEXT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkPipelineCreationFeedbackCreateInfoEXT(
			JNIEnv *env,
			jobject jVkPipelineCreationFeedbackCreateInfoEXTObject,
			const VkPipelineCreationFeedbackCreateInfoEXT *vkPipelineCreationFeedbackCreateInfoEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(jVkPipelineCreationFeedbackCreateInfoEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkPipelineCreationFeedbackCreateInfoEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getPipelineCreationFeedback", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineCreationFeedbackEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getPipelineCreationFeedback");
            return;
        }

        jobject jPipelineCreationFeedbackObject = env->CallObjectMethod(jVkPipelineCreationFeedbackCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        populateVkPipelineCreationFeedbackEXT(
    			env,
				jPipelineCreationFeedbackObject,
    			vkPipelineCreationFeedbackCreateInfoEXT->pPipelineCreationFeedback,
    			nullptr);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling populateVkPipelineCreationFeedbackEXT.");
    		return;
    	}

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getPipelineStageCreationFeedbacks", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getPipelineStageCreationFeedbacks");
            return;
        }

        jobject jPipelineCreationFeedbackCollectionObject = env->CallObjectMethod(jVkPipelineCreationFeedbackCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        populateVkPipelineCreationFeedbackEXTCollection(
                env,
				jPipelineCreationFeedbackCollectionObject,
				vkPipelineCreationFeedbackCreateInfoEXT->pPipelineStageCreationFeedbacks,
				nullptr);
    	if (env->ExceptionOccurred())
    	{
    		LOGERROR(env, "%s", "Error calling populateVkPipelineCreationFeedbackEXTCollection.");
    		return;
    	}
	}
}
