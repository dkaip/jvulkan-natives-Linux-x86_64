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
 * populateVkPhysicalDeviceTransformFeedbackPropertiesEXT.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceTransformFeedbackPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject,
			const VkPhysicalDeviceTransformFeedbackPropertiesEXT *vkPhysicalDeviceTransformFeedbackPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceTransformFeedbackPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackStreams", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackStreams");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackStreams);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackBuffers", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackBuffers");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackBuffers);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackBufferSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackBufferSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackBufferSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackStreamDataSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackStreamDataSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackStreamDataSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackBufferDataSize", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackBufferDataSize");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackBufferDataSize);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxTransformFeedbackBufferDataStride", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxTransformFeedbackBufferDataStride");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->maxTransformFeedbackBufferDataStride);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTransformFeedbackQueries", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTransformFeedbackQueries");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->transformFeedbackQueries);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTransformFeedbackStreamsLinesTriangles", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTransformFeedbackStreamsLinesTriangles");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->transformFeedbackStreamsLinesTriangles);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTransformFeedbackRasterizationStreamSelect", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTransformFeedbackRasterizationStreamSelect");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->transformFeedbackRasterizationStreamSelect);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setTransformFeedbackDraw", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setTransformFeedbackDraw");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceTransformFeedbackPropertiesEXTObject, methodId, vkPhysicalDeviceTransformFeedbackPropertiesEXT->transformFeedbackDraw);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
