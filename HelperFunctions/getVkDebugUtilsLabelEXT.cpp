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
 * getVkDebugUtilsLabelEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace jvulkan
{
	void getVkDebugUtilsLabelEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsLabelEXTObject,
		VkDebugUtilsLabelEXT *vkDebugUtilsLabelEXT,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDebugUtilsLabelEXTClass = env->GetObjectClass(jVkDebugUtilsLabelEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugUtilsLabelEXTObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsLabelEXTClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDebugUtilsLabelEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsLabelEXTClass, "getLabelName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jstring jTheLabelName = (jstring)env->CallObjectMethod(jVkDebugUtilsLabelEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        const char *tempString = env->GetStringUTFChars(jTheLabelName, 0);

        char *theLabelName = (char *)calloc(1, strlen(tempString) + 1);
        memoryToFree->push_back(theLabelName);

        strcpy(theLabelName, tempString);
        env->ReleaseStringUTFChars(jTheLabelName, tempString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsLabelEXTClass, "getColor", "()[F");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jfloatArray jColors = (jfloatArray)env->CallObjectMethod(jVkDebugUtilsLabelEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        float *colorsArray = nullptr;
        jsize arrayLength = 0;
        if (jColors != nullptr)
        {
            arrayLength = env->GetArrayLength(jColors);

            colorsArray = (float *)calloc(arrayLength, sizeof(float));

            env->GetFloatArrayRegion(jColors, 0, arrayLength, colorsArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkDebugUtilsLabelEXT->sType = (VkStructureType)sTypeValue;
        vkDebugUtilsLabelEXT->pNext = (void *)pNext;
        vkDebugUtilsLabelEXT->pLabelName = theLabelName;
        vkDebugUtilsLabelEXT->color[0] = colorsArray[0];
        vkDebugUtilsLabelEXT->color[1] = colorsArray[1];
        vkDebugUtilsLabelEXT->color[2] = colorsArray[2];
        vkDebugUtilsLabelEXT->color[3] = colorsArray[3];

        free(colorsArray);
    }
}
