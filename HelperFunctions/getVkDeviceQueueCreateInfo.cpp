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
 * getVkDeviceQueueCreateInfo.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDeviceQueueCreateInfo(
			JNIEnv *env,
			const jobject jVkDeviceQueueCreateInfoObject,
			VkDeviceQueueCreateInfo *vkDeviceQueueCreateInfo,
			std::vector<void *> *memoryToFree)
	{
        jclass vkDeviceQueueCreateInfoClass = env->GetObjectClass(jVkDeviceQueueCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkDeviceQueueCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDeviceQueueCreateInfoObject);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDeviceQueueCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getFlags.");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDeviceQueueCreateInfoObject, methodId);
        VkDeviceQueueCreateFlags flags = (VkDeviceQueueCreateFlags)getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDeviceQueueCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling getEnumSetValue.");
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getQueueFamilyIndex.");
            return;
        }

        jint queueFamilyIndex = env->CallIntMethod(jVkDeviceQueueCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallIntMethod failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getQueueCount.");
            return;
        }

        jint queueCount = env->CallIntMethod(jVkDeviceQueueCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallIntMethod failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueuePriorities", "()[F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getQueuePriorities.");
            return;
        }

        jfloatArray jQueuePriorities = (jfloatArray)env->CallObjectMethod(jVkDeviceQueueCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
            return;
        }

        float *queuePrioritiesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueuePriorities != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueuePriorities);

            queuePrioritiesArray = (float *)calloc(arrayLength, sizeof(float));
            memoryToFree->push_back(queuePrioritiesArray);

            env->GetFloatArrayRegion(jQueuePriorities, 0, arrayLength, queuePrioritiesArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to GetFloatArrayRegion failed.");
                return;
            }
        }


        vkDeviceQueueCreateInfo->sType   = sTypeValue;
        vkDeviceQueueCreateInfo->pNext   = pNext;
        vkDeviceQueueCreateInfo->flags   = flags;
        vkDeviceQueueCreateInfo->queueFamilyIndex = queueFamilyIndex;
        vkDeviceQueueCreateInfo->queueCount = queueCount;
        vkDeviceQueueCreateInfo->pQueuePriorities = queuePrioritiesArray;
	}
}
