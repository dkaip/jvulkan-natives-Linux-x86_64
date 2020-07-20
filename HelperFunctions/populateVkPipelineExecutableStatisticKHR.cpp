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
 * populateVkPipelineExecutableStatisticKHR.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPipelineExecutableStatisticKHR(
			JNIEnv *env,
			jobject jVkPipelineExecutableStatisticKHRObject,
			VkPipelineExecutableStatisticKHR const *vkPipelineExecutableStatisticKHR)
	{
        jclass theClass = env->GetObjectClass(jVkPipelineExecutableStatisticKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPipelineExecutableStatisticKHR");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setName");
            return;
        }

        jstring nameString = env->NewStringUTF(vkPipelineExecutableStatisticKHR->name);

        env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, nameString);
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

        jstring descriptionString = env->NewStringUTF(vkPipelineExecutableStatisticKHR->description);

        env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, descriptionString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(descriptionString);

        ///////////////////////////////////////////////////////////////////////////
        jclass vkResultClass = env->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineExecutableStatisticFormatKHR");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineExecutableStatisticFormatKHR");
            return;
        }

        jmethodID staticMethodId = env->GetStaticMethodID(vkResultClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineExecutableStatisticFormatKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineExecutableStatisticFormatKHR;");
            return;
        }

        jobject formatEnum =  env->CallStaticObjectMethod(vkResultClass, methodId, vkPipelineExecutableStatisticKHR->format);

        methodId = env->GetMethodID(theClass, "setFormat", "(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkPipelineExecutableStatisticFormatKHR;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setFormat");
            return;
        }

        env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, formatEnum);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        if (vkPipelineExecutableStatisticKHR->format == VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR)
        {
            methodId = env->GetMethodID(theClass, "setBooleanValue", "(Z)V");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not find method id setBooleanValue");
                return;
            }

            jboolean booleanValue = vkPipelineExecutableStatisticKHR->value.b32;
            env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, booleanValue);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", voidMethodErrorText);
                return;
            }
        }
        else if (vkPipelineExecutableStatisticKHR->format == VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR)
        {
            methodId = env->GetMethodID(theClass, "setLongValue", "(J)V");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not find method id setLongValue");
                return;
            }

            jlong longValue = vkPipelineExecutableStatisticKHR->value.i64;
            env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, longValue);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", voidMethodErrorText);
                return;
            }
        }
        else if (vkPipelineExecutableStatisticKHR->format == VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR)
        {
            methodId = env->GetMethodID(theClass, "setLongValue", "(J)V");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not find method id setLongValue");
                return;
            }

            jlong longValue = vkPipelineExecutableStatisticKHR->value.u64;
            env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, longValue);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", voidMethodErrorText);
                return;
            }
        }
        else if (vkPipelineExecutableStatisticKHR->format == VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR)
        {
            methodId = env->GetMethodID(theClass, "setDoubleValue", "(D)V");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not find method id setDoubleValue");
                return;
            }

            jdouble doubleValue = vkPipelineExecutableStatisticKHR->value.f64;
            env->CallVoidMethod(jVkPipelineExecutableStatisticKHRObject, methodId, doubleValue);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", voidMethodErrorText);
                return;
            }
        }
        else
        {
        	LOGERROR(env, "Unhandled format type of:%d", vkPipelineExecutableStatisticKHR->format);
        	// TODO throw exception here
        	return;
        }
	}
}
