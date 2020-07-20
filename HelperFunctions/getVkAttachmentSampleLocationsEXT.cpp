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
 * getVkAttachmentSampleLocationsEXT.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentSampleLocationsEXT(
            JNIEnv *env,
            const jobject jVkAttachmentSampleLocationsEXTObject,
			VkAttachmentSampleLocationsEXT *vkAttachmentSampleLocationsEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkAttachmentSampleLocationsEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAttachmentSampleLocationsEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getAttachmentIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getAttachmentIndex");
            return;
        }

        jint attachmentIndex = env->CallIntMethod(jVkAttachmentSampleLocationsEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getSampleLocationsInfo", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkSampleLocationsInfoEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSampleLocationsInfo");
            return;
        }

        jobject jVkSampleLocationsInfoEXT = env->CallObjectMethod(jVkAttachmentSampleLocationsEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkSampleLocationsInfoEXT *vkSampleLocationsInfoEXT = (VkSampleLocationsInfoEXT *)calloc(1, sizeof(VkSampleLocationsInfoEXT));
        if (vkSampleLocationsInfoEXT == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for vkSampleLocationsInfoEXT");
            return;
        }
        memoryToFree->push_back(vkSampleLocationsInfoEXT);

        getVkSampleLocationsInfoEXT(
                env,
				jVkSampleLocationsInfoEXT,
				vkSampleLocationsInfoEXT,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getVkRenderPassSampleLocationsBeginInfoEXT failed.");
            return;
        }

        vkAttachmentSampleLocationsEXT->attachmentIndex = attachmentIndex;
        memcpy(&vkAttachmentSampleLocationsEXT->sampleLocationsInfo,
        		vkSampleLocationsInfoEXT,
				sizeof(vkAttachmentSampleLocationsEXT->sampleLocationsInfo));
    }
}
