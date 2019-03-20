#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkPipelineStageFlagsCollection(
            JNIEnv *env,
            const jobject jVkPipelineStageFlagsCollectionObject,
            VkPipelineStageFlags **vkPipelineStageFlags,
            int *numberOfVkPipelineStageFlags,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineStageFlagsCollectionClass = env->GetObjectClass(jVkPipelineStageFlagsCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPipelineStageFlagsCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPipelineStageFlagsCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkPipelineStageFlags = numberOfElements;
        *vkPipelineStageFlags = (VkPipelineStageFlags *)calloc(numberOfElements, sizeof(VkPipelineStageFlags));
        memoryToFree->push_back(*vkPipelineStageFlags);

        jmethodID iteratorMethodId = env->GetMethodID(vkPipelineStageFlagsCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPipelineStageFlagsCollectionObject, iteratorMethodId);
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

            jobject jVkPipelineStageFlagsObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            VkPipelineStageFlags flags = getEnumSetValue(
                    env,
                    jVkPipelineStageFlagsObject,
                    "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

            (*vkPipelineStageFlags)[i] = flags;

            i++;
        } while(true);
    }
}
