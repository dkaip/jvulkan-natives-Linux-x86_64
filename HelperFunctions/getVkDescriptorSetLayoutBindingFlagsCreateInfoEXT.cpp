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
 * getVkDescriptorSetLayoutBindingFlagsCreateInfoEXT.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorSetLayoutBindingFlagsCreateInfoEXT(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject,
			VkDescriptorSetLayoutBindingFlagsCreateInfoEXT *vkDescriptorSetLayoutBindingFlagsCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject);
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

        jobject jVkDescriptorBindingFlagsEXTCollection = env->CallObjectMethod(jVkDescriptorSetLayoutBindingFlagsCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getBindingFlags");
            return;
        }

        int numberOfVkDescriptorBindingFlagsEXTs = 0;
        VkDescriptorBindingFlagsEXT *vkDescriptorBindingFlagsEXTs = nullptr;

		jvulkan::getVkDescriptorBindingFlagsEXTCollection(
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

        vkDescriptorSetLayoutBindingFlagsCreateInfoEXT->sType 			= (VkStructureType)sTypeValue;
        vkDescriptorSetLayoutBindingFlagsCreateInfoEXT->pNext 			= (void *)pNext;
        vkDescriptorSetLayoutBindingFlagsCreateInfoEXT->bindingCount	= numberOfVkDescriptorBindingFlagsEXTs;
        vkDescriptorSetLayoutBindingFlagsCreateInfoEXT->pBindingFlags	= vkDescriptorBindingFlagsEXTs;
    }
}
