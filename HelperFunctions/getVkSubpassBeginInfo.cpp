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
 * getVkSubpassBeginInfo.cpp
 *
 *  Created on: Aug 30, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkSubpassBeginInfo(
            JNIEnv *env,
            jobject jVkSubpassBeginInfoObject,
			VkSubpassBeginInfo *vkSubpassBeginInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkSubpassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkSubpassBeginInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkSubpassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkSubpassBeginInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getContents", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSubpassContents;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getContents.");
            return;
        }

        jobject jVkSubpassContentsObject = env->CallObjectMethod(jVkSubpassBeginInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass vkSubpassContentsObjectEnumClass = env->GetObjectClass(jVkSubpassContentsObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkSubpassContentsObject.");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkSubpassContentsObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for valueOf.");
            return;
        }

        VkSubpassContents vkSubpassContentsEnumValue = (VkSubpassContents)env->CallIntMethod(jVkSubpassContentsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkSubpassBeginInfo->sType = sTypeValue;
        vkSubpassBeginInfo->pNext = pNext;
        vkSubpassBeginInfo->contents = vkSubpassContentsEnumValue;
    }
}
