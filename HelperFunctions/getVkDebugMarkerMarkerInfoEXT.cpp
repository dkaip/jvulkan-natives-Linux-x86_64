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
 * getVkDebugMarkerMarkerInfoEXT.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDebugMarkerMarkerInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugMarkerMarkerInfoEXTObject,
		VkDebugMarkerMarkerInfoEXT *vkDebugMarkerMarkerInfoEXT,
        std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDebugMarkerMarkerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDebugMarkerMarkerInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDebugMarkerMarkerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkDebugMarkerMarkerInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getpNextObject");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getMarkerName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMarkerName");
            return;
        }

        jstring jTheMarkerName = (jstring)env->CallObjectMethod(jVkDebugMarkerMarkerInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        const char *tempString = env->GetStringUTFChars(jTheMarkerName, 0);

        char *theMarkerName = (char *)calloc(1, strlen(tempString) + 1);
        memoryToFree->push_back(theMarkerName);

        strcpy(theMarkerName, tempString);
        env->ReleaseStringUTFChars(jTheMarkerName, tempString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getColor", "()[F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getColor");
            return;
        }

        jfloatArray jColors = (jfloatArray)env->CallObjectMethod(jVkDebugMarkerMarkerInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
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
            	LOGERROR(env, "%s", "Error calling GetFloatArrayRegion");
                return;
            }
        }

        vkDebugMarkerMarkerInfoEXT->sType = sTypeValue;
        vkDebugMarkerMarkerInfoEXT->pNext = (void *)pNext;
        vkDebugMarkerMarkerInfoEXT->pMarkerName = theMarkerName;
        vkDebugMarkerMarkerInfoEXT->color[0] = colorsArray[0];
        vkDebugMarkerMarkerInfoEXT->color[1] = colorsArray[1];
        vkDebugMarkerMarkerInfoEXT->color[2] = colorsArray[2];
        vkDebugMarkerMarkerInfoEXT->color[3] = colorsArray[3];

        free(colorsArray);
    }
}
