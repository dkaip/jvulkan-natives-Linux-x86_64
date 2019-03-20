#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkImageCreateInfo(
            JNIEnv *env,
            jobject jVkImageCreateInfoObject,
            VkImageCreateInfo *vkImageCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkImageCreateInfoClass = env->GetObjectClass(jVkImageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkImageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkImageCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        VkImageCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageCreateFlagBits");


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getImageType", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageTypeObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageTypeEnumClass = env->GetObjectClass(jVkImageTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageType vkImageTypeEnumValue = (VkImageType)env->CallIntMethod(jVkImageTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getFormat", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumClass = env->GetObjectClass(jVkFormatObject);

        valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
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
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getExtent", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent3D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkExtent3DObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkExtent3D vkExtent3D = {};
        getVkExtent3D(env,
                jVkExtent3DObject,
                &vkExtent3D,
                memoryToFree);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getMipLevels", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint mipLevels = env->CallIntMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getArrayLayers", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint arrayLayers = env->CallIntMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getSamples", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSampleCountFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSampleCountFlagBitsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(jVkSampleCountFlagBitsObject);

        valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSampleCountFlagBits vkSampleCountFlagBitsEnumValue = (VkSampleCountFlagBits)env->CallIntMethod(jVkSampleCountFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getTiling", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageTiling;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageTilingObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageTilingEnumClass = env->GetObjectClass(jVkImageTilingObject);

        valueOfMethodId = env->GetMethodID(vkImageTilingEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageTiling vkImageTilingEnumValue = (VkImageTiling)env->CallIntMethod(jVkImageTilingObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject usageFlagsObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        VkImageUsageFlags imageUsageFlags = getEnumSetValue(
                env,
                usageFlagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageUsageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getSharingMode", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSharingModeObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkSharingModeEnumClass = env->GetObjectClass(jVkSharingModeObject);

        valueOfMethodId = env->GetMethodID(vkSharingModeEnumClass, "valueOf", "()I");
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
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
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

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageCreateInfoClass, "getInitialLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutObject = env->CallObjectMethod(jVkImageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutEnumClass = env->GetObjectClass(jVkImageLayoutObject);

        valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout vkImageLayoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkImageCreateInfo->sType = (VkStructureType)sTypeValue;
        vkImageCreateInfo->pNext = (void *)pNext;
        vkImageCreateInfo->flags = flags;
        vkImageCreateInfo->imageType = vkImageTypeEnumValue;
        vkImageCreateInfo->format = vkFormatEnumValue;

        vkImageCreateInfo->extent.width  = vkExtent3D.width;
        vkImageCreateInfo->extent.height = vkExtent3D.height;
        vkImageCreateInfo->extent.depth  = vkExtent3D.depth;

        vkImageCreateInfo->mipLevels = mipLevels;
        vkImageCreateInfo->arrayLayers = arrayLayers;
        vkImageCreateInfo->samples = vkSampleCountFlagBitsEnumValue;
        vkImageCreateInfo->tiling = vkImageTilingEnumValue;
        vkImageCreateInfo->usage = imageUsageFlags;
        vkImageCreateInfo->sharingMode = vkSharingModeEnumValue;
        vkImageCreateInfo->queueFamilyIndexCount = arrayLength;
        vkImageCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
        vkImageCreateInfo->initialLayout = vkImageLayoutEnumValue;
    }
}
