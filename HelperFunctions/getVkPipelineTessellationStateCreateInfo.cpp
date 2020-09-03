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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineTessellationStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineTessellationStateCreateInfoObject,
            VkPipelineTessellationStateCreateInfo *vkPipelineTessellationStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineTessellationStateCreateInfoClass = env->GetObjectClass(jVkPipelineTessellationStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineTessellationStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineTessellationStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineTessellationStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineTessellationStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPipelineTessellationStateCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineTessellationStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineTessellationStateCreateInfoClass, "getPatchControlPoints", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint patchControlPoints = env->CallIntMethod(jVkPipelineTessellationStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineTessellationStateCreateInfo->sType = sTypeValue;
        vkPipelineTessellationStateCreateInfo->pNext = (void *)pNext;
        vkPipelineTessellationStateCreateInfo->flags = flags;
        vkPipelineTessellationStateCreateInfo->patchControlPoints = patchControlPoints;
    }
}
