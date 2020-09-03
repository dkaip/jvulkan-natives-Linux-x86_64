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
    void getVkPipelineInputAssemblyStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineInputAssemblyStateCreateInfoObject,
            VkPipelineInputAssemblyStateCreateInfo *vkPipelineInputAssemblyStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineInputAssemblyStateCreateInfoClass = env->GetObjectClass(jVkPipelineInputAssemblyStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkPipelineInputAssemblyStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineInputAssemblyStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPipelineInputAssemblyStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineInputAssemblyStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineVertexInputStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineInputAssemblyStateCreateInfoClass, "getTopology", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkPrimitiveTopology;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPrimitiveTopologyObject = env->CallObjectMethod(jVkPipelineInputAssemblyStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkPrimitiveTopologyEnumClass = env->GetObjectClass(jVkPrimitiveTopologyObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkPrimitiveTopologyEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkPrimitiveTopologyEnumValue = env->CallIntMethod(jVkPrimitiveTopologyObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineInputAssemblyStateCreateInfoClass, "isPrimitiveRestartEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jrestartEnable = env->CallBooleanMethod(jVkPipelineInputAssemblyStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBool32 restartEnable = false;
        if (jrestartEnable != 0)
        {
            restartEnable = true;
        }

        vkPipelineInputAssemblyStateCreateInfo->sType = sTypeValue;
        vkPipelineInputAssemblyStateCreateInfo->pNext = (void *)pNext;
        vkPipelineInputAssemblyStateCreateInfo->flags = (VkPipelineInputAssemblyStateCreateFlags)flags;
        vkPipelineInputAssemblyStateCreateInfo->topology = (VkPrimitiveTopology)vkPrimitiveTopologyEnumValue;
        vkPipelineInputAssemblyStateCreateInfo->primitiveRestartEnable = restartEnable;
    }
}
