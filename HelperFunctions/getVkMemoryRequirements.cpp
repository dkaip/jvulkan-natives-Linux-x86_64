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
 * getVkMemoryRequirements.cpp
 *
 *  Created on: Sep 9, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkMemoryRequirements(
            JNIEnv *env,
            jobject jVkMemoryRequirementsObject,
			VkMemoryRequirements *vkMemoryRequirements,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkMemoryRequirementsObject);
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Error trying to get class for jVkMemoryRequirementsObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Could not find method id for getSize");
            return;
        }

        jlong size = env->CallLongMethod(jVkMemoryRequirementsObject, methodId);
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getAlignment", "()J");
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Could not find method id for getAlignment");
            return;
        }

        jlong alignment = env->CallLongMethod(jVkMemoryRequirementsObject, methodId);
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getMemoryTypeBits", "()Ljava/util/BitSet;");
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Could not find method id for getMemoryTypeBits");
            return;
        }

        jobject bitSetObject = env->CallObjectMethod(jVkMemoryRequirementsObject, methodId);
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        jclass bitSetClass = env->GetObjectClass(bitSetObject);
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Error calling GetObjectClass");
            return;
        }

        jmethodID getMethodId = env->GetMethodID(bitSetClass, "get", "(I)Z");
        if (env->ExceptionOccurred())
        {
            LOGERROR(env, "%s", "Could not find method id for get");
            return;
        }

        uint32_t memoryTypeBits = 0;
        for(int i = 0; i < 31; i++)
        {
            jboolean bitIsSet = env->CallBooleanMethod(bitSetObject, getMethodId);
            if (env->ExceptionOccurred())
            {
                LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                return;
            }

            if (bitIsSet == true)
            {
            	memoryTypeBits |= 1<<i;
            }
        }

        vkMemoryRequirements->size = size;
		vkMemoryRequirements->alignment = alignment;
		vkMemoryRequirements->memoryTypeBits = memoryTypeBits;
    }
}
