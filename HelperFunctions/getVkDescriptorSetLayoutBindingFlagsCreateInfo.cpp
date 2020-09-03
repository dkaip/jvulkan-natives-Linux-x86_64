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
 * getVkDescriptorSetLayoutBindingFlagsCreateInfoEXT.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorSetLayoutBindingFlagsCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutBindingFlagsCreateInfoObject,
			VkDescriptorSetLayoutBindingFlagsCreateInfo *vkDescriptorSetLayoutBindingFlagsCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDescriptorSetLayoutBindingFlagsCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDescriptorSetLayoutBindingFlagsCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDescriptorSetLayoutBindingFlagsCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDescriptorSetLayoutBindingFlagsCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getBindingFlags", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getBindingFlags methodId");
            return;
        }

        jobject jVkDescriptorBindingFlagsEXTCollection = env->CallObjectMethod(jVkDescriptorSetLayoutBindingFlagsCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getBindingFlags");
            return;
        }

        int numberOfVkDescriptorBindingFlagsEXTs = 0;
        VkDescriptorBindingFlagsEXT *vkDescriptorBindingFlagsEXTs = nullptr;

		jvulkan::getVkDescriptorBindingFlagsCollection(
				env,
				jVkDescriptorBindingFlagsEXTCollection,
				&vkDescriptorBindingFlagsEXTs,
				&numberOfVkDescriptorBindingFlagsEXTs,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling getVkDescriptorBindingFlagsEXTCollection");
			return;
		}

        vkDescriptorSetLayoutBindingFlagsCreateInfo->sType 			= sTypeValue;
        vkDescriptorSetLayoutBindingFlagsCreateInfo->pNext 			= (void *)pNext;
        vkDescriptorSetLayoutBindingFlagsCreateInfo->bindingCount	= numberOfVkDescriptorBindingFlagsEXTs;
        vkDescriptorSetLayoutBindingFlagsCreateInfo->pBindingFlags	= vkDescriptorBindingFlagsEXTs;
    }
}
