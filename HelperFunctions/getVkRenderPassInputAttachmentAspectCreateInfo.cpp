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
 * getVkRenderPassInputAttachmentAspectCreateInfo.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassInputAttachmentAspectCreateInfo(
            JNIEnv *env,
            const jobject jVkRenderPassInputAttachmentAspectCreateInfoObject,
			VkRenderPassInputAttachmentAspectCreateInfo *vkRenderPassInputAttachmentAspectCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassInputAttachmentAspectCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRenderPassInputAttachmentAspectCreateInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkRenderPassInputAttachmentAspectCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSType failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassInputAttachmentAspectCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getAspectReferences", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAspectReferences");
            return;
        }

        jobject jVkInputAttachmentAspectReferenceCollectionObject = env->CallObjectMethod(jVkRenderPassInputAttachmentAspectCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int numberOfVkInputAttachmentAspectReferenceObjects = 0;
        VkInputAttachmentAspectReference *vkInputAttachmentAspectReferences = nullptr;
        if (jVkInputAttachmentAspectReferenceCollectionObject != nullptr)
        {
            getVkInputAttachmentAspectReferenceCollection(
                    env,
					jVkInputAttachmentAspectReferenceCollectionObject,
                    &vkInputAttachmentAspectReferences,
                    &numberOfVkInputAttachmentAspectReferenceObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkInputAttachmentAspectReferenceCollection");
                return;
            }
        }


        vkRenderPassInputAttachmentAspectCreateInfo->sType = sTypeValue;
        vkRenderPassInputAttachmentAspectCreateInfo->pNext = pNext;
        vkRenderPassInputAttachmentAspectCreateInfo->aspectReferenceCount = numberOfVkInputAttachmentAspectReferenceObjects;
		vkRenderPassInputAttachmentAspectCreateInfo->pAspectReferences = vkInputAttachmentAspectReferences;
    }
}
