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
 * populateVkDeviceGroupPresentCapabilitiesKHR.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkDeviceGroupPresentCapabilitiesKHR(
			JNIEnv *env,
			jobject jVkDeviceGroupPresentCapabilitiesKHRObject,
			const VkDeviceGroupPresentCapabilitiesKHR* vkDeviceGroupPresentCapabilitiesKHR,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkDeviceGroupPresentCapabilitiesKHRObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDeviceGroupPresentCapabilitiesKHR");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setPresentMask", "([I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPresentMask");
            return;
        }

        jintArray presentMaskObject = env->NewIntArray(VK_MAX_DEVICE_GROUP_SIZE);
        if (presentMaskObject == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for presentMaskObject");
            return;
        }

        env->SetIntArrayRegion(presentMaskObject, 0, VK_MAX_DEVICE_GROUP_SIZE, (const jint *)vkDeviceGroupPresentCapabilitiesKHR->presentMask);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling SetIntArrayRegion");
            return;
        }

        env->CallVoidMethod(jVkDeviceGroupPresentCapabilitiesKHRObject, methodId, presentMaskObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setModes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setModes");
            return;
        }

        jobject vkDeviceGroupPresentModeFlagsKHREnumSet = createVkDeviceGroupPresentModeFlagsKHRAsEnumSet(env, vkDeviceGroupPresentCapabilitiesKHR->modes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkDeviceGroupPresentModeFlagsKHRAsEnumSet");
            return;
        }

        if (vkDeviceGroupPresentModeFlagsKHREnumSet == nullptr)
        {
        	LOGERROR(env, "%s", "Error calling createVkDeviceGroupPresentModeFlagsKHRAsEnumSet, vkDeviceGroupPresentModeFlagsKHREnumSet was nullptr");
            return;
        }

        env->CallVoidMethod(jVkDeviceGroupPresentCapabilitiesKHRObject, methodId, vkDeviceGroupPresentModeFlagsKHREnumSet);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
