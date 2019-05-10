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
    void getVkMemoryAllocateInfo(
            JNIEnv *env,
            jobject jVkMemoryAllocateInfoObject,
            VkMemoryAllocateInfo *vkMemoryAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkMemoryAllocateInfoClass = env->GetObjectClass(jVkMemoryAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkMemoryAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkMemoryAllocateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkMemoryAllocateInfoClass, "getAllocationSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jAllocationSize = env->CallLongMethod(jVkMemoryAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkMemoryAllocateInfoClass, "getMemoryTypeIndex", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jMemoryTypeIndex = env->CallIntMethod(jVkMemoryAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkMemoryAllocateInfo->sType = (VkStructureType)sTypeValue;
        vkMemoryAllocateInfo->pNext = (void *)pNext;
        vkMemoryAllocateInfo->allocationSize = jAllocationSize;
        vkMemoryAllocateInfo->memoryTypeIndex = jMemoryTypeIndex;
    }
}
