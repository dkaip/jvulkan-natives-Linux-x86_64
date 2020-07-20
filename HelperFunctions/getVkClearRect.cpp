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
/*
 * getVkClearRect.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkClearRect(
            JNIEnv *env,
            const jobject jVkClearRectObject,
			VkClearRect *vkClearRect,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkClearRectObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getRect", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkRect2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method ID for getRect");
            return;
        }

        jobject jVkRect2DObject = env->CallObjectMethod(jVkClearRectObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        VkRect2D *vkRect2D = (VkRect2D *)calloc(1, sizeof(VkRect2D));
        if (vkRect2D == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for vkRect2D");
        	return;
        }

        memoryToFree->push_back(vkRect2D);

        getVkRect2D(
                env,
				jVkRect2DObject,
                vkRect2D,
                memoryToFree);

        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkRect2D");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getBaseArrayLayer", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method ID for getBaseArrayLayer");
            return;
        }

        jint baseArrayLayer = env->CallIntMethod(jVkClearRectObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLayerCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method ID for getLayerCount");
            return;
        }

        jint layerCount = env->CallIntMethod(jVkClearRectObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }


        (void)memcpy(&vkClearRect->rect, vkRect2D, sizeof(vkClearRect->rect));
        vkClearRect->baseArrayLayer = baseArrayLayer;
        vkClearRect->layerCount = layerCount;
    }
}
