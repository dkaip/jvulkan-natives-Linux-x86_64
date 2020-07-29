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
 * populateVkPipelineExecutableInternalRepresentationKHR.cpp
 *
 *  Created on: Oct 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPipelineExecutableInternalRepresentationKHR(
			JNIEnv *env,
			jobject jVkPipelineExecutableInternalRepresentationKHRObject,
			VkPipelineExecutableInternalRepresentationKHR const *vkPipelineExecutableInternalRepresentationKHR)
	{
        jclass theClass = env->GetObjectClass(jVkPipelineExecutableInternalRepresentationKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutableInternalRepresentationKHR");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setName");
            return;
        }

        jstring nameString = env->NewStringUTF(vkPipelineExecutableInternalRepresentationKHR->name);

        env->CallVoidMethod(jVkPipelineExecutableInternalRepresentationKHRObject, methodId, nameString);
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

        jstring descriptionString = env->NewStringUTF(vkPipelineExecutableInternalRepresentationKHR->description);

        env->CallVoidMethod(jVkPipelineExecutableInternalRepresentationKHRObject, methodId, descriptionString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(descriptionString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setText", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setText");
            return;
        }

        env->CallVoidMethod(jVkPipelineExecutableInternalRepresentationKHRObject, methodId, vkPipelineExecutableInternalRepresentationKHR->isText);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setData", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setData");
            return;
        }

        /*
         * I don't know if the "text" in data is null terminated so I'm doing it here.
         */
        uint64_t dataSize = vkPipelineExecutableInternalRepresentationKHR->dataSize + 1;
        char *stringData = (char *)calloc(dataSize, sizeof(char));
        strncpy(stringData, (const char *)vkPipelineExecutableInternalRepresentationKHR->pData, dataSize-1);


        jstring dataString = env->NewStringUTF(stringData);

        env->CallVoidMethod(jVkPipelineExecutableInternalRepresentationKHRObject, methodId, dataString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(dataString);

        free(stringData);
	}
}
