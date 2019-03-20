#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkDescriptorSetAllocateInfo(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoObject,
            VkDescriptorSetAllocateInfo *vkDescriptorSetAllocateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetAllocateInfoClass = env->GetObjectClass(jVkDescriptorSetAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDescriptorSetAllocateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorSetAllocateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDescriptorSetAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetAllocateInfoClass, "getDescriptorPool", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDescriptorPool;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jDescriptorPoolObject = env->CallObjectMethod(jVkDescriptorSetAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkDescriptorPool_T *descriptorPoolHandle = (VkDescriptorPool_T *)hwjvi::getHandleValue(env, jDescriptorPoolObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorSetAllocateInfoClass, "getSetLayouts", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkDescriptorSetLayoutCollection = env->CallObjectMethod(jVkDescriptorSetAllocateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkDescriptorSetLayouts = 0;
        VkDescriptorSetLayout *vkDescriptorSetLayouts = nullptr;

        if (jVkDescriptorSetLayoutCollection != nullptr)
        {
            hwjvi::getVkDescriptorSetLayoutCollection(
                    env,
                    jVkDescriptorSetLayoutCollection,
                    &vkDescriptorSetLayouts,
                    &numberOfVkDescriptorSetLayouts,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDescriptorSetAllocateInfo->sType = (VkStructureType)sTypeValue;
        vkDescriptorSetAllocateInfo->pNext = (void *)pNext;
        vkDescriptorSetAllocateInfo->descriptorPool = descriptorPoolHandle;
        vkDescriptorSetAllocateInfo->descriptorSetCount = numberOfVkDescriptorSetLayouts;
        vkDescriptorSetAllocateInfo->pSetLayouts = vkDescriptorSetLayouts;
    }

    void getVkDescriptorSetAllocateInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorSetAllocateInfoCollectionObject,
            VkDescriptorSetAllocateInfo **vkDescriptorSetAllocateInfos,
            int *numberOfVkDescriptorSetAllocateInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorSetAllocateInfoCollectionClass = env->GetObjectClass(jVkDescriptorSetAllocateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorSetAllocateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorSetAllocateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkDescriptorSetAllocateInfos = numberOfElements;
        *vkDescriptorSetAllocateInfos = (VkDescriptorSetAllocateInfo *)calloc(numberOfElements, sizeof(VkDescriptorSetAllocateInfo));
        memoryToFree->push_back(*vkDescriptorSetAllocateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetAllocateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetAllocateInfoCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorSetLayoutBindingObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorSetAllocateInfo(
                    env,
                    jVkDescriptorSetLayoutBindingObject,
                    &((*vkDescriptorSetAllocateInfos)[i]),
                    memoryToFree);
            std::cout << "Gack11" << std::endl;

            i++;
        } while(true);
    }
}
