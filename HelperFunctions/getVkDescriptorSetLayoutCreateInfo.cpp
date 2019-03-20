#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorSetLayoutCreateInfo(
            JNIEnv *env,
            jobject jVkDescriptorSetLayoutCreateInfoObject,
            VkDescriptorSetLayoutCreateInfo *vkDescriptorSetLayoutCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetLayoutCreateInfoClass = env->GetObjectClass(jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDescriptorSetLayoutCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        VkDescriptorSetLayoutCreateFlags flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDescriptorSetLayoutCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetLayoutCreateInfoClass, "getBindings", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutBindingCollection = env->CallObjectMethod(jVkDescriptorSetLayoutCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorSetLayoutBindingCollection = 0;
        VkDescriptorSetLayoutBinding *vkDescriptorSetLayoutBindings = nullptr;

        if (jVkDescriptorSetLayoutBindingCollection != nullptr)
        {
            hwjvi::getVkDescriptorSetLayoutBindingCollection(
                    env,
                    jVkDescriptorSetLayoutBindingCollection,
                    &vkDescriptorSetLayoutBindings,
                    &numberOfVkDescriptorSetLayoutBindingCollection,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetLayoutCreateInfo->sType = (VkStructureType)sTypeValue;
        vkDescriptorSetLayoutCreateInfo->pNext = (void *)pNext;
        vkDescriptorSetLayoutCreateInfo->flags = flags;
        vkDescriptorSetLayoutCreateInfo->bindingCount = numberOfVkDescriptorSetLayoutBindingCollection;
        vkDescriptorSetLayoutCreateInfo->pBindings = vkDescriptorSetLayoutBindings;
    }
}
