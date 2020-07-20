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
 * getVkDescriptorBindingFlagsEXTCollection.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorBindingFlagsEXTCollection(
            JNIEnv *env,
            const jobject jVkDescriptorBindingFlagsEXTCollectionObject,
			VkDescriptorBindingFlagsEXT **vkDescriptorBindingFlagsEXTs,
            int *numberOfVkDescriptorBindingFlagsEXTs,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDescriptorBindingFlagsEXTCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDescriptorBindingFlagsEXTCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorBindingFlagsEXTCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        *numberOfVkDescriptorBindingFlagsEXTs = numberOfElements;
        *vkDescriptorBindingFlagsEXTs = (VkDescriptorBindingFlagsEXT *)calloc(numberOfElements, sizeof(VkDescriptorBindingFlagsEXT));
        if (*vkDescriptorBindingFlagsEXTs == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for *vkDescriptorBindingFlagsEXTs");
            return;
        }

        memoryToFree->push_back(*vkDescriptorBindingFlagsEXTs);

        jmethodID iteratorMethodId = env->GetMethodID(theClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorBindingFlagsEXTCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for iteratorObject.");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for next");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkDescriptorBindingFlagsEXTObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            VkDescriptorBindingFlagsEXT flags = (VkDescriptorBindingFlagsEXT)getEnumSetValue(
    				env,
					jVkDescriptorBindingFlagsEXTObject,
    				"com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDescriptorBindingFlagBitsEXT");
    		if (env->ExceptionOccurred())
    		{
            	LOGERROR(env, "%s", "Error calling getEnumSetValue");
    			return;
    		}

    		(*vkDescriptorBindingFlagsEXTs)[i] = flags;

            i++;
        } while(true);
    }
}
