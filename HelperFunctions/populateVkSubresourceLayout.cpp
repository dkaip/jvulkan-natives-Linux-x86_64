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
 * populateVkSubresourceLayout.cpp
 *
 *  Created on: Nov 4, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
    void populateVkSubresourceLayout(
    		JNIEnv *env,
			jobject jVkSubresourceLayoutObject,
			const VkSubresourceLayout *vkSubresourceLayout)
    {
		if (jVkSubresourceLayoutObject == nullptr)
		{
			LOGERROR(env, "%s", "jVkSubresourceLayoutObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkSubresourceLayoutObject == nullptr");
			return;
		}

		if (vkSubresourceLayout == nullptr)
		{
			LOGERROR(env, "%s", "vkSubresourceLayout == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkSubresourceLayout == nullptr");
			return;
		}

		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

        jclass theClass = env->GetObjectClass(jVkSubresourceLayoutObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkSubresourceLayout");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setOffset", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setOffset");
            return;
        }

        env->CallVoidMethod(jVkSubresourceLayoutObject, methodId, vkSubresourceLayout->offset);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSize", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSize");
            return;
        }

        env->CallVoidMethod(jVkSubresourceLayoutObject, methodId, vkSubresourceLayout->size);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setRowPitch", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setRowPitch");
            return;
        }

        env->CallVoidMethod(jVkSubresourceLayoutObject, methodId, vkSubresourceLayout->rowPitch);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setArrayPitch", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setArrayPitch");
            return;
        }

        env->CallVoidMethod(jVkSubresourceLayoutObject, methodId, vkSubresourceLayout->arrayPitch);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDepthPitch", "(J)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDepthPitch");
            return;
        }

        env->CallVoidMethod(jVkSubresourceLayoutObject, methodId, vkSubresourceLayout->depthPitch);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
    }
}
