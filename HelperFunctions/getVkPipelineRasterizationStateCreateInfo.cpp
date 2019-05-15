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
    void getVkPipelineRasterizationStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineRasterizationStateCreateInfoInfoObject,
            VkPipelineRasterizationStateCreateInfo *vkPipelineRasterizationStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineRasterizationStateCreateInfoClass = env->GetObjectClass(jVkPipelineRasterizationStateCreateInfoInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineRasterizationStateCreateInfoInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkPipelineRasterizationStateCreateInfoInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineRasterizationStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "isDepthClampEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jDepthClampEnable = env->CallBooleanMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        VkBool32 depthClampEnable = VK_FALSE;
//        if (jDepthClampEnable != false)
//        {
//            depthClampEnable = VK_TRUE;
//        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "isRasterizerDiscardEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jRasterizerDiscardEnable = env->CallBooleanMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getPolygonMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPolygonMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPolygonModeObject = env->CallObjectMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkPrimitiveTopologyEnumClass = env->GetObjectClass(jVkPolygonModeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkPrimitiveTopologyEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkPolygonModeEnumValue = env->CallIntMethod(jVkPolygonModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getCullMode", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        int32_t cullModeFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCullModeFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getFrontFace", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFrontFace;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFrontFaceObject = env->CallObjectMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFrontFaceEnumClass = env->GetObjectClass(jVkFrontFaceObject);

        valueOfMethodId = env->GetMethodID(vkFrontFaceEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkFrontFaceEnumValue = env->CallIntMethod(jVkFrontFaceObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "isDepthBiasEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jDepthBiasEnable = env->CallBooleanMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getDepthBiasConstantFactor", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jDepthBiasConstantFactor = env->CallFloatMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getDepthBiasClamp", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jDepthBiasClamp = env->CallFloatMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getDepthBiasSlopeFactor", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jDepthBiasSlopeFactor = env->CallFloatMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineRasterizationStateCreateInfoClass, "getLineWidth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat jLineWidth = env->CallFloatMethod(jVkPipelineRasterizationStateCreateInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkPipelineRasterizationStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineRasterizationStateCreateInfo->pNext = (void *)pNext;
        vkPipelineRasterizationStateCreateInfo->flags = (VkPipelineRasterizationStateCreateFlags)flags;
        vkPipelineRasterizationStateCreateInfo->depthClampEnable = jDepthClampEnable;
        vkPipelineRasterizationStateCreateInfo->rasterizerDiscardEnable = jRasterizerDiscardEnable;
        vkPipelineRasterizationStateCreateInfo->polygonMode = (VkPolygonMode)vkPolygonModeEnumValue;
        vkPipelineRasterizationStateCreateInfo->cullMode = (VkCullModeFlags)cullModeFlags;
        vkPipelineRasterizationStateCreateInfo->frontFace = (VkFrontFace)vkFrontFaceEnumValue;
        vkPipelineRasterizationStateCreateInfo->depthBiasEnable = jDepthBiasEnable;
        vkPipelineRasterizationStateCreateInfo->depthBiasConstantFactor = jDepthBiasConstantFactor;
        vkPipelineRasterizationStateCreateInfo->depthBiasClamp = jDepthBiasClamp;
        vkPipelineRasterizationStateCreateInfo->depthBiasSlopeFactor = jDepthBiasSlopeFactor;
        vkPipelineRasterizationStateCreateInfo->lineWidth = jLineWidth;
    }
}
