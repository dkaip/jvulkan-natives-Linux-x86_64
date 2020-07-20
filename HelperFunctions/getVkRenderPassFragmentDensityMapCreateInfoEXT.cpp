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
 * getVkRenderPassFragmentDensityMapCreateInfoEXT.cpp
 *
 *  Created on: May 20, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRenderPassFragmentDensityMapCreateInfoEXT(
            JNIEnv *env,
            const jobject jVkRenderPassFragmentDensityMapCreateInfoEXTObject,
			VkRenderPassFragmentDensityMapCreateInfoEXT *vkRenderPassFragmentDensityMapCreateInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRenderPassFragmentDensityMapCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRenderPassFragmentDensityMapCreateInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkRenderPassFragmentDensityMapCreateInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkRenderPassFragmentDensityMapCreateInfoEXTObject);
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
        jmethodID methodId = env->GetMethodID(theClass, "getFragmentDensityMapAttachment", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAttachmentReference;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getFragmentDensityMapAttachment");
            return;
        }

        jobject fragmentDensityMapAttachmentObject = env->CallObjectMethod(jVkRenderPassFragmentDensityMapCreateInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        getVkAttachmentReference(
                env,
				fragmentDensityMapAttachmentObject,
    			&vkRenderPassFragmentDensityMapCreateInfoEXT->fragmentDensityMapAttachment,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkAttachmentReference.");
            return;
        }


        vkRenderPassFragmentDensityMapCreateInfoEXT->sType = sTypeValue;
        vkRenderPassFragmentDensityMapCreateInfoEXT->pNext = pNext;
    }
}
