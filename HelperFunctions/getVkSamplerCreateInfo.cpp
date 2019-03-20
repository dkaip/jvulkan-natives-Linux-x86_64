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
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkSamplerCreateInfo(
            JNIEnv *env,
            jobject jVkSamplerCreateInfoObject,
            VkSamplerCreateInfo *vkSamplerCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSamplerCreateInfoClass = env->GetObjectClass(jVkSamplerCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSamplerCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        VkSamplerCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSamplerCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMagFilter", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFilter;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFilterObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFilterEnumClass = env->GetObjectClass(jVkFilterObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFilterEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFilter magFilterEnumValue = (VkFilter)env->CallIntMethod(jVkFilterObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMinFilter", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFilter;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkFilterObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        valueOfMethodId = env->GetMethodID(vkFilterEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkFilter minFilterEnumValue = (VkFilter)env->CallIntMethod(jVkFilterObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMipmapMode", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSamplerMipmapMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSamplerMipmapModeObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSamplerMipmapModeEnumClass = env->GetObjectClass(jVkSamplerMipmapModeObject);

        valueOfMethodId = env->GetMethodID(vkSamplerMipmapModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSamplerMipmapMode mipmapModeEnumValue = (VkSamplerMipmapMode)env->CallIntMethod(jVkSamplerMipmapModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getAddressModeU", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSamplerAddressMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSamplerAddressModeObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSamplerAddressModeEnumClass = env->GetObjectClass(jVkSamplerAddressModeObject);

        valueOfMethodId = env->GetMethodID(vkSamplerAddressModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSamplerAddressMode addressModeUEnumValue = (VkSamplerAddressMode)env->CallIntMethod(jVkSamplerAddressModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getAddressModeV", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSamplerAddressMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkSamplerAddressModeObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        valueOfMethodId = env->GetMethodID(vkSamplerAddressModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSamplerAddressMode addressModeVEnumValue = (VkSamplerAddressMode)env->CallIntMethod(jVkSamplerAddressModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getAddressModeW", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSamplerAddressMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkSamplerAddressModeObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        valueOfMethodId = env->GetMethodID(vkSamplerAddressModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSamplerAddressMode addressModeWEnumValue = (VkSamplerAddressMode)env->CallIntMethod(jVkSamplerAddressModeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMipLodBias", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat mipLodBias = env->CallFloatMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "isAnisotropyEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean anisotropyEnable = env->CallBooleanMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMaxAnisotropy", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat maxAnisotropy = env->CallFloatMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "isCompareEnable", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean compareEnable = env->CallBooleanMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getCompareOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompareOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCompareOpObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkCompareOpClass = env->GetObjectClass(jVkCompareOpObject);

        valueOfMethodId = env->GetMethodID(vkCompareOpClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkCompareOp compareOpEnumValue = (VkCompareOp)env->CallIntMethod(jVkCompareOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMinLod", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat minLod = env->CallFloatMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getMaxLod", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat maxLod = env->CallFloatMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "getBorderColor", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkBorderColor;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkBorderColorObject = env->CallObjectMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkBorderColorClass = env->GetObjectClass(jVkBorderColorObject);

        valueOfMethodId = env->GetMethodID(vkBorderColorClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkBorderColor borderColorEnumValue = (VkBorderColor)env->CallIntMethod(jVkBorderColorObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSamplerCreateInfoClass, "isUnnormalizedCoordinates", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean unnormalizedCoordinates = env->CallBooleanMethod(jVkSamplerCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkSamplerCreateInfo->sType = (VkStructureType)sTypeValue;
        vkSamplerCreateInfo->pNext = (void *)pNext;
        vkSamplerCreateInfo->flags = flags;
        vkSamplerCreateInfo->magFilter = magFilterEnumValue;
        vkSamplerCreateInfo->minFilter = minFilterEnumValue;
        vkSamplerCreateInfo->mipmapMode = mipmapModeEnumValue;
        vkSamplerCreateInfo->addressModeU = addressModeUEnumValue;
        vkSamplerCreateInfo->addressModeV = addressModeVEnumValue;
        vkSamplerCreateInfo->addressModeW = addressModeWEnumValue;
        vkSamplerCreateInfo->mipLodBias = mipLodBias;
        vkSamplerCreateInfo->anisotropyEnable = anisotropyEnable;
        vkSamplerCreateInfo->maxAnisotropy = maxAnisotropy;
        vkSamplerCreateInfo->compareEnable = compareEnable;
        vkSamplerCreateInfo->compareOp = compareOpEnumValue;
        vkSamplerCreateInfo->minLod = minLod;
        vkSamplerCreateInfo->maxLod = maxLod;
        vkSamplerCreateInfo->borderColor = borderColorEnumValue;
        vkSamplerCreateInfo->unnormalizedCoordinates = unnormalizedCoordinates;
    }
}
