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
    void getVkBufferCreateInfo(
            JNIEnv *env,
            jobject jVkBufferCreateInfoObject,
            VkBufferCreateInfo *vkBufferCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkBufferCreateInfoClass = env->GetObjectClass(jVkBufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkBufferCreateInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSTypeAsInt(env, jVkBufferCreateInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
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
        	LOGERROR(env, "%s", "Could not find method id for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkBufferCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkBufferCreateFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSize");
            return;
        }

        jlong jBufferSize = env->CallLongMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getUsage");
            return;
        }

        flagsObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkBufferUsageFlags bufferUsageFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkBufferUsageFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue");
            return;
        }


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getSharingMode");
            return;
        }

        jobject jVkSharingModeObject = env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkSharingModeEnumClass = env->GetObjectClass(jVkSharingModeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkSharingModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkSharingMode vkSharingModeEnumValue = (VkSharingMode)env->CallIntMethod(jVkSharingModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkBufferCreateInfoClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getQueueFamilyIndices");
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkBufferCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int *queueFamilyIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueueFamilyIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueueFamilyIndices);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetArrayLength");
                return;
            }

            queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            if (queueFamilyIndicesArray == nullptr)
            {
            	LOGERROR(env, "%s", "Error trying to allocate memory for queueFamilyIndicesArray.");
            	return;
            }
            memoryToFree->push_back(queueFamilyIndicesArray);

            env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                return;
            }
        }

        vkBufferCreateInfo->sType = sTypeValue;
        vkBufferCreateInfo->pNext = (void *)pNext;
        vkBufferCreateInfo->flags = flags;
        vkBufferCreateInfo->size = jBufferSize;
        vkBufferCreateInfo->usage = bufferUsageFlags;
        vkBufferCreateInfo->sharingMode = vkSharingModeEnumValue;
        vkBufferCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
    }
}
