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
 * populateVkPipelineExecutablePropertiesKHR.cpp
 *
 *  Created on: Sep 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPipelineExecutablePropertiesKHR(
			JNIEnv *env,
			jobject jVkPipelineExecutablePropertiesKHRObject,
			VkPipelineExecutablePropertiesKHR const *vkPipelineExecutablePropertiesKHR)
	{
        jclass theClass = env->GetObjectClass(jVkPipelineExecutablePropertiesKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkPipelineExecutablePropertiesKHR");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setStages", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setStages");
            return;
        }

        jobject jflags = createVkShaderStageFlagsAsEnumSet(env, vkPipelineExecutablePropertiesKHR->stages);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkShaderStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPipelineExecutablePropertiesKHRObject, methodId, jflags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setName");
            return;
        }

        jstring nameString = env->NewStringUTF(vkPipelineExecutablePropertiesKHR->name);

        env->CallVoidMethod(jVkPipelineExecutablePropertiesKHRObject, methodId, nameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(nameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDescription", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDescription");
            return;
        }

        jstring descriptionString = env->NewStringUTF(vkPipelineExecutablePropertiesKHR->description);

        env->CallVoidMethod(jVkPipelineExecutablePropertiesKHRObject, methodId, descriptionString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(descriptionString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSubgroupSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSubgroupSize");
            return;
        }

        jint subgroupSize = vkPipelineExecutablePropertiesKHR->subgroupSize;
        env->CallVoidMethod(jVkPipelineExecutablePropertiesKHRObject, methodId, subgroupSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
