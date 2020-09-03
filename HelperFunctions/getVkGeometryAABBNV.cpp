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
 * getVkGeometryAABBNV.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGeometryAABBNV(
            JNIEnv *env,
            const jobject jVkGeometryAABBNVObject,
            VkGeometryAABBNV *vkGeometryAABBNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkGeometryAABBNVClass = env->GetObjectClass(jVkGeometryAABBNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkGeometryAABBNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkGeometryAABBNVObject);
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
        jmethodID methodId = env->GetMethodID(vkGeometryAABBNVClass, "getAabbData", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferHandleObject = env->CallObjectMethod(jVkGeometryAABBNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *aabbDataHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryAABBNVClass, "getNumAABBs", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numAABBs = env->CallIntMethod(jVkGeometryAABBNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryAABBNVClass, "getStride", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint stride = env->CallIntMethod(jVkGeometryAABBNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryAABBNVClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong offset = env->CallLongMethod(jVkGeometryAABBNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkGeometryAABBNV->sType         = (VkStructureType)sTypeValue;
        vkGeometryAABBNV->pNext         = (void *)pNext;
        vkGeometryAABBNV->aabbData      = aabbDataHandle;
        vkGeometryAABBNV->numAABBs      = numAABBs;
        vkGeometryAABBNV->stride        = stride;
        vkGeometryAABBNV->offset        = offset;
    }
}
