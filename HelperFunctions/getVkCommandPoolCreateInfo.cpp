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

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkCommandPoolCreateInfo(
            JNIEnv *env,
            jobject jVkCommandPoolCreateInfoObject,
            VkCommandPoolCreateInfo *vkCommandPoolCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkCommandPoolCreateInfoClass = env->GetObjectClass(jVkCommandPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkCommandPoolCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkCommandPoolCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkCommandPoolCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkCommandPoolCreateInfoObject, methodId);
        VkCommandPoolCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCommandPoolCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkCommandPoolCreateInfoClass, "getQueueFamilyIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jQueueFamilyIndex = env->CallIntMethod(jVkCommandPoolCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkCommandPoolCreateInfo->sType = (VkStructureType)sTypeValue;
        vkCommandPoolCreateInfo->pNext = (void *)pNext;
        vkCommandPoolCreateInfo->flags = flags;
        vkCommandPoolCreateInfo->queueFamilyIndex = jQueueFamilyIndex;
    }
}
