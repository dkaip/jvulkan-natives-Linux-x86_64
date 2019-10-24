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
 * getVkClearDepthStencilValue.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkClearDepthStencilValue(
            JNIEnv *env,
            jobject jVkClearDepthStencilValueObject,
			VkClearDepthStencilValue *vkClearDepthStencilValue,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkClearDepthStencilValueObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkClearDepthStencilValueObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "getDepth", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getDepth");
            return;
        }

        jfloat depth = env->CallFloatMethod(jVkClearDepthStencilValueObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallFloatMethod");
            return;
        }

        methodId = env->GetMethodID(theClass, "getStencil", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getStencil");
            return;
        }

        jlong stencil = env->CallLongMethod(jVkClearDepthStencilValueObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        vkClearDepthStencilValue->depth = depth;
        vkClearDepthStencilValue->stencil = (uint32_t)stencil;
    }
}
