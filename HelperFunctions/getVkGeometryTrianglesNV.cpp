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
 * getVkGeometryTrianglesNV.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGeometryTrianglesNV(
            JNIEnv *env,
            const jobject jVkGeometryTrianglesNVObject,
            VkGeometryTrianglesNV *vkGeometryTrianglesNV,
            std::vector<void *> *memoryToFree)
    {
        jclass vkGeometryTrianglesNVClass = env->GetObjectClass(jVkGeometryTrianglesNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSType(env, jVkGeometryTrianglesNVObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkGeometryTrianglesNVObject);
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
        jmethodID methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getVertexData", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBufferHandleObject = env->CallObjectMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *vertexDataHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getVertexOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong vertexOffset = env->CallLongMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getVertexCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vertexCount = env->CallIntMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getVertexStride", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong vertexStride = env->CallLongMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getVertexFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatClass = env->GetObjectClass(jVkFormatObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFormat vkFormatEnumValue = (VkFormat)env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getIndexData", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkBufferHandleObject = env->CallObjectMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *indexDataHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getIndexOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong indexOffset = env->CallLongMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getIndexCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint indexCount = env->CallIntMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getIndexType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkIndexType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkIndexTypeObject = env->CallObjectMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkIndexTypeClass = env->GetObjectClass(jVkIndexTypeObject);

        valueOfMethodId = env->GetMethodID(vkIndexTypeClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkIndexType vkIndexTypeEnumValue = (VkIndexType)env->CallIntMethod(jVkIndexTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getTransformData", "()Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkBufferHandleObject = env->CallObjectMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBuffer_T *transformDataHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBufferHandleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkGeometryTrianglesNVClass, "getTransformOffset", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong transformOffset = env->CallLongMethod(jVkGeometryTrianglesNVObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkGeometryTrianglesNV->sType        = (VkStructureType)sTypeValue;
        vkGeometryTrianglesNV->pNext        = (void *)pNext;
        vkGeometryTrianglesNV->vertexData   = vertexDataHandle;
        vkGeometryTrianglesNV->vertexOffset = vertexOffset;
        vkGeometryTrianglesNV->vertexCount  = vertexCount;
        vkGeometryTrianglesNV->vertexStride = vertexStride;
        vkGeometryTrianglesNV->vertexFormat = vkFormatEnumValue;
        vkGeometryTrianglesNV->indexData    = indexDataHandle;
        vkGeometryTrianglesNV->indexOffset  = indexOffset;
        vkGeometryTrianglesNV->indexCount   = indexCount;
        vkGeometryTrianglesNV->indexType    = vkIndexTypeEnumValue;
        vkGeometryTrianglesNV->transformData = transformDataHandle;
        vkGeometryTrianglesNV->transformOffset = transformOffset;
    }
}

