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
 * getVkRectLayerKHR.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkRectLayerKHR(
            JNIEnv *env,
            const jobject jVkRectLayerKHRObject,
			VkRectLayerKHR *vkRectLayerKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkRectLayerKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkRectLayerKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getOffset", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkOffset2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getOffset.");
            return;
        }

        jobject jVkOffset2DObject = env->CallObjectMethod(jVkRectLayerKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkOffset2D offset = {};
		getVkOffset2D(
				env,
				jVkOffset2DObject,
				&offset,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkOffset2D.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getExtent.");
            return;
        }

        jobject jVkExtent2DObject = env->CallObjectMethod(jVkRectLayerKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkExtent2D extent = {};
		getVkExtent2D(
				env,
				jVkExtent2DObject,
				&extent,
				memoryToFree);
		if (env->ExceptionOccurred())
		{
        	LOGERROR(env, "%s", "Error calling getVkExtent2D.");
			return;
		}

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getLayer", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getLayer.");
            return;
        }

        jint layer = env->CallIntMethod(jVkRectLayerKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkRectLayerKHR->offset.x = offset.x;
		vkRectLayerKHR->offset.y = offset.y;
		vkRectLayerKHR->extent.width = extent.width;
		vkRectLayerKHR->extent.height = extent.height;
        vkRectLayerKHR->layer = layer;
    }
}
