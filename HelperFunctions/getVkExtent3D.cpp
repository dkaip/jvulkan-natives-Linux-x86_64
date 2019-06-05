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
#include "slf4j.hh"

namespace jvulkan
{
    void getVkExtent3D(
            JNIEnv *env,
            jobject jVkExtent3DObject,
            VkExtent3D *vkExtent3D,
            std::vector<void *> *memoryToFree)
    {
    	if (jVkExtent3DObject == nullptr)
    	{
    		LOGERROR(env, "%s", "jVkExtent3DObject == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "jVkExtent3DObject == nullptr");
    		return;
    	}

    	if (vkExtent3D == nullptr)
    	{
    		LOGERROR(env, "%s", "vkExtent3D == nullptr");
			env->ThrowNew(env->FindClass("java/lang/Exception"), "vkExtent3D == nullptr");
    		return;
    	}

        jclass vkExtent3DClass = env->GetObjectClass(jVkExtent3DObject);
        if (env->ExceptionOccurred())
        {
      		LOGERROR(env, "%d:%d:%d", vkExtent3D->width, vkExtent3D->height, vkExtent3D->depth);
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkExtent3DClass, "getWidth", "()I");
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Could not find method id getWidth.");
            return;
        }

        jint width = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkExtent3DClass, "getHeight", "()I");
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Could not find method id getHeight.");
            return;
        }

        jint height = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkExtent3DClass, "getDepth", "()I");
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Could not find method id getDepth.");
            return;
        }

        jint depth = env->CallIntMethod(jVkExtent3DObject, methodId);
        if (env->ExceptionOccurred())
        {
    		LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }


        vkExtent3D->width  = width;
        vkExtent3D->height = height;
        vkExtent3D->depth  = depth;
    }
}
