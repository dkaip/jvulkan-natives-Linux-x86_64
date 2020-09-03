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
 * getVkWriteDescriptorSetInlineUniformBlockEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkWriteDescriptorSetInlineUniformBlockEXT(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetInlineUniformBlockEXTObject,
			VkWriteDescriptorSetInlineUniformBlockEXT *vkWriteDescriptorSetInlineUniformBlockEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkWriteDescriptorSetInlineUniformBlockEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkWriteDescriptorSetInlineUniformBlockEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkWriteDescriptorSetInlineUniformBlockEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkWriteDescriptorSetInlineUniformBlockEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getData", "()[B");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getData methodId");
            return;
        }

        jbyteArray jData = (jbyteArray)env->CallObjectMethod(jVkWriteDescriptorSetInlineUniformBlockEXTObject, methodId);

        char *dataArray = nullptr;
        jsize arrayLength = 0;
        if (jData != nullptr)
        {
            arrayLength = env->GetArrayLength(jData);

            dataArray = (char *)calloc(arrayLength, sizeof(char));
            memoryToFree->push_back(dataArray);

            env->GetByteArrayRegion(jData, 0, arrayLength, (signed char *)dataArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error trying to get GetByteArrayRegion for tag");
                return;
            }
        }


        vkWriteDescriptorSetInlineUniformBlockEXT->sType = sTypeValue;
        vkWriteDescriptorSetInlineUniformBlockEXT->pNext = pNext;
        vkWriteDescriptorSetInlineUniformBlockEXT->dataSize = arrayLength;
        vkWriteDescriptorSetInlineUniformBlockEXT->pData = dataArray;
    }
}
