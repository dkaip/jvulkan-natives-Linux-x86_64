#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getCollectionOfVkDescriptorSetLayout(
            JNIEnv *env,
            const jobject jVkDescriptorSetLayoutCollectionObject,
            VkDescriptorSetLayout_T **descriptorSetLayouts[],
            int *numberOfDescriptorSetLayouts,
            std::vector<void *> *memoryToFree)
    {
        if (jVkDescriptorSetLayoutCollectionObject == nullptr)
        {
            return;
        }

        jclass vkDescriptorSetLayoutCollectionClass = env->GetObjectClass(jVkDescriptorSetLayoutCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetLayoutCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfDescriptorSetLayouts = numberOfElements;
        *descriptorSetLayouts = (VkDescriptorSetLayout_T **)calloc(numberOfElements, sizeof(VkDescriptorSetLayout_T *));
        memoryToFree->push_back(*descriptorSetLayouts);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetLayoutCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetLayoutCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkDescriptorSetLayoutObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkDescriptorSetLayout_T *descriptorSetLayoutHandle = (VkDescriptorSetLayout_T *)hwjvi::getHandleValue(env, jVkDescriptorSetLayoutObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*descriptorSetLayouts)[i] = descriptorSetLayoutHandle;

            i++;
        } while(true);
    }

    void getVkPushConstantRange(
            JNIEnv *env,
            const jobject jVkPushConstantRangeObject,
            VkPushConstantRange *pushConstantRange)
    {
        jclass vkPushConstantRangeClass = env->GetObjectClass(jVkPushConstantRangeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkPushConstantRangeClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPushConstantRangeObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkShaderStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPushConstantRangeClass, "getOffset", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint offset = env->CallIntMethod(jVkPushConstantRangeObject, methodId);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPushConstantRangeClass, "getSize", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint size = env->CallIntMethod(jVkPushConstantRangeObject, methodId);

        pushConstantRange->stageFlags = (VkShaderStageFlags)flags;
        pushConstantRange->offset     = offset;
        pushConstantRange->size       = size;
    }

    void getCollectionOfVkPushConstantRange(
            JNIEnv *env,
            const jobject jVkPushConstantRangeCollectionObject,
            VkPushConstantRange *pushConstantRanges[],
            int *numberOfPushConstantRanges,
            std::vector<void *> *memoryToFree)
    {
        if (jVkPushConstantRangeCollectionObject == nullptr)
        {
            return;
        }

        jclass vkPushConstantRangeCollectionClass = env->GetObjectClass(jVkPushConstantRangeCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPushConstantRangeCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPushConstantRangeCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfPushConstantRanges = numberOfElements;
        *pushConstantRanges = (VkPushConstantRange *)calloc(numberOfElements, sizeof(VkPushConstantRange));
        memoryToFree->push_back(*pushConstantRanges);

        jmethodID iteratorMethodId = env->GetMethodID(vkPushConstantRangeCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPushConstantRangeCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkPushConstantRangeObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkPushConstantRange(
                    env,
                    jVkPushConstantRangeObject,
                    &(*pushConstantRanges)[i]);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }

    void getVkPipelineLayoutCreateInfo(
        JNIEnv *env,
        const jobject jVkPipelineLayoutCreateInfoObject,
        VkPipelineLayoutCreateInfo *vkPipelineLayoutCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineLayoutCreateInfoClass = env->GetObjectClass(jVkPipelineLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineLayoutCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getSetLayouts", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutCollection = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorSetLayout_T **vkDescriptorSetLayouts = nullptr;
        int numberOfDescriptorSetLayouts = 0;

        if (jVkDescriptorSetLayoutCollection != nullptr)
        {
            getCollectionOfVkDescriptorSetLayout(
                    env,
                    jVkDescriptorSetLayoutCollection,
                    &vkDescriptorSetLayouts,
                    &numberOfDescriptorSetLayouts,
                    memoryToFree);
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineLayoutCreateInfoClass, "getPushConstantRanges", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkPushConstantRangeCollection = env->CallObjectMethod(jVkPipelineLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPushConstantRange *vkPushConstantRanges = nullptr;
        int numberOfPushConstantRanges = 0;

        if (jVkPushConstantRangeCollection != nullptr)
        {
            getCollectionOfVkPushConstantRange(
                    env,
                    jVkPushConstantRangeCollection,
                    &vkPushConstantRanges,
                    &numberOfPushConstantRanges,
                    memoryToFree);
        }

        vkPipelineLayoutCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineLayoutCreateInfo->pNext = (void *)pNext;
        vkPipelineLayoutCreateInfo->flags = flags;
        vkPipelineLayoutCreateInfo->setLayoutCount = numberOfDescriptorSetLayouts;
        vkPipelineLayoutCreateInfo->pSetLayouts = vkDescriptorSetLayouts;
        vkPipelineLayoutCreateInfo->pushConstantRangeCount = numberOfPushConstantRanges;
        vkPipelineLayoutCreateInfo->pPushConstantRanges = vkPushConstantRanges;
    }

}
