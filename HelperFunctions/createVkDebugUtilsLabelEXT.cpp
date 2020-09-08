/*
 * Copyright 2019-2020 Douglas Kaip
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
 * createVkDebugUtilsLabelEXT.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */


#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkDebugUtilsLabelEXT(JNIEnv *env, const VkDebugUtilsLabelEXT *labelData)
    {
		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsLabelEXT",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setLabelName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying to get methodId of setLabelName");
            return nullptr;
        }

        jstring labelNameString = env->NewStringUTF(labelData->pLabelName);

        env->CallVoidMethod(theObject, methodId, labelNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying execute to get methodId of setLabelName");
            return nullptr;
        }

        env->DeleteLocalRef(labelNameString);

        ////////////////////////////////////////////////////////////////////////
        jfloatArray jColorArray = env->NewFloatArray(sizeof(labelData->color));

        env->SetFloatArrayRegion(jColorArray, 0, sizeof(labelData->color), labelData->color);

        methodId = env->GetMethodID(theClass, "setColor", "([F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying to get methodId of setColor");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jColorArray);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying execute to get methodId of setColor");
            return nullptr;
        }

        return theObject;
    }
}
