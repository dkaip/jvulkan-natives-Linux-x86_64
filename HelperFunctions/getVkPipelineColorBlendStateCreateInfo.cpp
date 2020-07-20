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
    void getVkPipelineColorBlendStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineColorBlendStateCreateInfoObject,
            VkPipelineColorBlendStateCreateInfo *vkPipelineColorBlendStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineColorBlendStateCreateInfoClass = env->GetObjectClass(jVkPipelineColorBlendStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineColorBlendStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineColorBlendStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineColorBlendStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineColorBlendStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineMultisampleStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendStateCreateInfoClass, "isLogicOpEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jLogicOpEnable = env->CallBooleanMethod(jVkPipelineColorBlendStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendStateCreateInfoClass, "getLogicOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkLogicOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkLogicOpObject = env->CallObjectMethod(jVkPipelineColorBlendStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkLogicOpEnumClass = env->GetObjectClass(jVkLogicOpObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkLogicOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkLogicOp vkLogicOpEnumValue = (VkLogicOp)env->CallIntMethod(jVkLogicOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendStateCreateInfoClass, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPipelineColorBlendAttachmentStateCollectionObject = env->CallObjectMethod(jVkPipelineColorBlendStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkPipelineColorBlendAttachmentStates = 0;
        VkPipelineColorBlendAttachmentState *vkPipelineColorBlendAttachmentState = nullptr;
        if (jVkPipelineColorBlendAttachmentStateCollectionObject != nullptr)
        {
            jvulkan::getVkPipelineColorBlendAttachmentStateCollection(
                    env,
                    jVkPipelineColorBlendAttachmentStateCollectionObject,
                    &vkPipelineColorBlendAttachmentState,
                    &numberOfVkPipelineColorBlendAttachmentStates,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineColorBlendStateCreateInfoClass, "getBlendConstants", "()[F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloatArray jBlendConstants = (jfloatArray)env->CallObjectMethod(jVkPipelineColorBlendStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        float *blendConstantsArray = nullptr;
        jsize arrayLength = 0;
        if (jBlendConstants != nullptr)
        {
            arrayLength = env->GetArrayLength(jBlendConstants);

            blendConstantsArray = (float *)calloc(arrayLength, sizeof(float));
            memoryToFree->push_back(blendConstantsArray);

            env->GetFloatArrayRegion(jBlendConstants, 0, arrayLength, blendConstantsArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        vkPipelineColorBlendStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineColorBlendStateCreateInfo->pNext = (void *)pNext;
        vkPipelineColorBlendStateCreateInfo->flags = (VkPipelineColorBlendStateCreateFlags)flags;
        vkPipelineColorBlendStateCreateInfo->logicOpEnable = jLogicOpEnable;
        vkPipelineColorBlendStateCreateInfo->logicOp = vkLogicOpEnumValue;
        vkPipelineColorBlendStateCreateInfo->attachmentCount = numberOfVkPipelineColorBlendAttachmentStates;
        vkPipelineColorBlendStateCreateInfo->pAttachments = vkPipelineColorBlendAttachmentState;
        vkPipelineColorBlendStateCreateInfo->blendConstants[0] = blendConstantsArray[0];
        vkPipelineColorBlendStateCreateInfo->blendConstants[1] = blendConstantsArray[1];
        vkPipelineColorBlendStateCreateInfo->blendConstants[2] = blendConstantsArray[2];
        vkPipelineColorBlendStateCreateInfo->blendConstants[3] = blendConstantsArray[3];
    }
}
