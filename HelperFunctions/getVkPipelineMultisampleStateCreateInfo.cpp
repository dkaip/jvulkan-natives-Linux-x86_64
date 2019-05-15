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
    void getVkPipelineMultisampleStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineMultisampleStateCreateInfoObject,
            VkPipelineMultisampleStateCreateInfo *vkPipelineMultisampleStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineMultisampleStateCreateInfoClass = env->GetObjectClass(jVkPipelineMultisampleStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineMultisampleStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineMultisampleStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineMultisampleStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "getRasterizationSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSampleCountFlagBitsObject = env->CallObjectMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(jVkSampleCountFlagBitsObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkSampleCountFlagBitsEnumValue = env->CallIntMethod(jVkSampleCountFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "isSampleShadingEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jSampleShadingEnable = env->CallBooleanMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "getMinSampleShading", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jMinSampleShading = env->CallFloatMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "getSampleMask", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jSampleMask = (jintArray)env->CallObjectMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *sampleMaskArray = nullptr;
        jsize arrayLength = 0;
        if (jSampleMask != nullptr)
        {
            arrayLength = env->GetArrayLength(jSampleMask);

            sampleMaskArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(sampleMaskArray);

            env->GetIntArrayRegion(jSampleMask, 0, arrayLength, sampleMaskArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "isAlphaToCoverageEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jAlphaToCoverageEnable = env->CallBooleanMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineMultisampleStateCreateInfoClass, "isAlphaToOneEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jAlphaToOneEnable = env->CallBooleanMethod(jVkPipelineMultisampleStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineMultisampleStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineMultisampleStateCreateInfo->pNext = (void *)pNext;
        vkPipelineMultisampleStateCreateInfo->flags = (VkPipelineMultisampleStateCreateFlags)flags;
        vkPipelineMultisampleStateCreateInfo->rasterizationSamples = (VkSampleCountFlagBits)vkSampleCountFlagBitsEnumValue;
        vkPipelineMultisampleStateCreateInfo->sampleShadingEnable = jSampleShadingEnable;
        vkPipelineMultisampleStateCreateInfo->minSampleShading = jMinSampleShading;
        vkPipelineMultisampleStateCreateInfo->pSampleMask = (unsigned int *)sampleMaskArray;
        vkPipelineMultisampleStateCreateInfo->alphaToCoverageEnable = jAlphaToCoverageEnable;
        vkPipelineMultisampleStateCreateInfo->alphaToOneEnable = jAlphaToOneEnable;
    }
}
