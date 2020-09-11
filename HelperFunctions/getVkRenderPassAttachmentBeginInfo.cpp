/*
 * Copyright 2020 Douglas Kaip
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
 * getVkRenderPassAttachmentBeginInfo.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassAttachmentBeginInfo(
            JNIEnv *env,
            jobject jVkRenderPassAttachmentBeginInfoObject,
			VkRenderPassAttachmentBeginInfo *vkRenderPassAttachmentBeginInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassAttachmentBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkRenderPassAttachmentBeginInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRenderPassAttachmentBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassAttachmentBeginInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAttachments.");
            return;
        }

        jobject jVkImageViewCollection = env->CallObjectMethod(jVkRenderPassAttachmentBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        int numberOfVkImageViewHandles = 0;
        VkImageView *vkImageViewHandles = nullptr;
        if (jVkImageViewCollection != nullptr)
        {
            getVkImageViewCollection(
                    env,
                    jVkImageViewCollection,
                    &vkImageViewHandles,
                    &numberOfVkImageViewHandles,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkImageViewCollection.");
                return;
            }
        }


        vkRenderPassAttachmentBeginInfo->sType 	= sTypeValue;
        vkRenderPassAttachmentBeginInfo->pNext 	= (void *)pNext;
        vkRenderPassAttachmentBeginInfo->attachmentCount = numberOfVkImageViewHandles;
        vkRenderPassAttachmentBeginInfo->pAttachments = vkImageViewHandles;
    }
}
