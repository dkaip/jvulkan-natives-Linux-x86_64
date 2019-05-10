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
    void getVkViewport(
            JNIEnv *env,
            jobject jVkViewportObject,
            VkViewport *vkViewport,
            std::vector<void *> *memoryToFree)
    {
        jclass vkViewportClass = env->GetObjectClass(jVkViewportObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkViewportClass, "getX", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat x = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getY", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat y = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getWidth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat width = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getHeight", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat height = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getMinDepth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat minDepth = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkViewportClass, "getMaxDepth", "()F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloat maxDepth = env->CallFloatMethod(jVkViewportObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkViewport->x = x;
        vkViewport->y = y;
        vkViewport->width  = width;
        vkViewport->height = height;
        vkViewport->minDepth = minDepth;
        vkViewport->maxDepth = maxDepth;
    }

    void getVkViewportCollection(
            JNIEnv *env,
            const jobject jVkViewportCollectionObject,
            VkViewport **viewports,
            int *numberOfViewports,
            std::vector<void *> *memoryToFree)
    {
        if (jVkViewportCollectionObject == nullptr)
        {
            return;
        }

        jclass vkViewportCollectionClass = env->GetObjectClass(jVkViewportCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkViewportCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkViewportCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfViewports = numberOfElements;
        *viewports = (VkViewport *)calloc(numberOfElements, sizeof(VkViewport));
        memoryToFree->push_back(*viewports);

        jmethodID iteratorMethodId = env->GetMethodID(vkViewportCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkViewportCollectionObject, iteratorMethodId);
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

            jobject jVkViewportObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkViewport(
                    env,
                    jVkViewportObject,
                    &(*viewports)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                break;
            }

            i++;
        } while(true);
    }

    void getVkPipelineViewportStateCreateInfo(
            JNIEnv *env,
            jobject jVkPipelineViewportStateCreateInfoObject,
            VkPipelineViewportStateCreateInfo *vkPipelineViewportStateCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineViewportStateCreateInfoClass = env->GetObjectClass(jVkPipelineViewportStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineViewportStateCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkPipelineViewportStateCreateInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineVertexInputStateCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getViewports", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkViewports = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkViewports = 0;
        VkViewport *vkViewports = nullptr;
        getVkViewportCollection(
                env,
                jVkViewports,
                &vkViewports,
                &numberOfVkViewports,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineViewportStateCreateInfoClass, "getScissors", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkRect2Ds = env->CallObjectMethod(jVkPipelineViewportStateCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfVkRect2Ds = 0;
        VkRect2D *vkRect2Ds = nullptr;
        getVkRect2DCollection(
                env,
                jVkRect2Ds,
                &vkRect2Ds,
                &numberOfVkRect2Ds,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }


        vkPipelineViewportStateCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineViewportStateCreateInfo->pNext = (void *)pNext;
        vkPipelineViewportStateCreateInfo->flags = (VkPipelineViewportStateCreateFlags)flags;
        vkPipelineViewportStateCreateInfo->viewportCount = numberOfVkViewports;
        vkPipelineViewportStateCreateInfo->pViewports = vkViewports;
        vkPipelineViewportStateCreateInfo->scissorCount = numberOfVkRect2Ds;
        vkPipelineViewportStateCreateInfo->pScissors = vkRect2Ds;
    }
}
