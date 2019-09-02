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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkBufferCreateInfo(
            JNIEnv *env,
            jobject jVkBufferCreateInfoObject,
            VkBufferCreateInfo *vkBufferCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferCreateInfoClass = env->GetObjectClass(jVkBufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkBufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkBufferCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkBufferCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        VkBufferCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkBufferCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong jBufferSize = env->CallLongMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        VkBufferUsageFlags bufferUsageFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkBufferUsageFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSharingModeObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSharingModeEnumClass = env->GetObjectClass(jVkSharingModeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkSharingModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSharingMode vkSharingModeEnumValue = (VkSharingMode)env->CallIntMethod(jVkSharingModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *queueFamilyIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueueFamilyIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueueFamilyIndices);

            queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(queueFamilyIndicesArray);

            env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkBufferCreateInfo->sType = (VkStructureType)sTypeValue;
        vkBufferCreateInfo->pNext = (void *)pNext;
        vkBufferCreateInfo->flags = flags;
        vkBufferCreateInfo->size = jBufferSize;
        vkBufferCreateInfo->usage = bufferUsageFlags;
        vkBufferCreateInfo->sharingMode = vkSharingModeEnumValue;
        vkBufferCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
    }
}
