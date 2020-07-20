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
    void getVkSubpassDependency2KHR(
            JNIEnv *env,
            const jobject jVkSubpassDependency2KHRObject,
            VkSubpassDependency2KHR *vkSubpassDependency2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDependency2KHRClass = env->GetObjectClass(jVkSubpassDependency2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSubpassDependency2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkSubpassDependency2KHRObject);
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
        jmethodID methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getSrcSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint srcSubpass = env->CallIntMethod(jVkSubpassDependency2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "setDstSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint dstSubpass = env->CallIntMethod(jVkSubpassDependency2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getSrcStageMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSubpassDependency2KHRObject, methodId);
        VkPipelineStageFlags srcStageMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getDstStageMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkSubpassDependency2KHRObject, methodId);
        VkPipelineStageFlags dstStageMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkSubpassDependency2KHRObject, methodId);
        VkAccessFlags srcAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkSubpassDependency2KHRObject, methodId);
        VkAccessFlags dstAccessMask = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getDependencyFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        flagsObject = env->CallObjectMethod(jVkSubpassDependency2KHRObject, methodId);
        VkDependencyFlags dependencyFlags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDependencyFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependency2KHRClass, "getViewOffset", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint viewOffset = env->CallIntMethod(jVkSubpassDependency2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkSubpassDependency2KHR->sType = (VkStructureType)sTypeValue;
        vkSubpassDependency2KHR->pNext = (void *)pNext;
        vkSubpassDependency2KHR->srcSubpass = srcSubpass;
        vkSubpassDependency2KHR->dstSubpass = dstSubpass;
        vkSubpassDependency2KHR->srcStageMask = srcStageMask;
        vkSubpassDependency2KHR->dstStageMask = dstStageMask;
        vkSubpassDependency2KHR->srcAccessMask = srcAccessMask;
        vkSubpassDependency2KHR->dstAccessMask = dstAccessMask;
        vkSubpassDependency2KHR->dependencyFlags = dependencyFlags;
        vkSubpassDependency2KHR->viewOffset = viewOffset;
    }

    void getVkSubpassDependency2KHRCollection(
            JNIEnv *env,
            const jobject jVkSubpassDependency2KHRCollectionObject,
            VkSubpassDependency2KHR **vkSubpassDependency2KHRs,
            int *numberOfVkSubpassDependency2KHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDependency2KHRCollectionClass = env->GetObjectClass(jVkSubpassDependency2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubpassDependency2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubpassDependency2KHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSubpassDependency2KHRs = numberOfElements;
        *vkSubpassDependency2KHRs = (VkSubpassDependency2KHR *)calloc(numberOfElements, sizeof(VkSubpassDependency2KHR));
        memoryToFree->push_back(*vkSubpassDependency2KHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDependency2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubpassDependency2KHRCollectionObject, iteratorMethodId);
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

            jobject jVkSubpassDependency2KHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkSubpassDependency2KHR(
                    env,
                    jVkSubpassDependency2KHRObject,
                    &((*vkSubpassDependency2KHRs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
