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
 * getVkDebugMarkerObjectNameInfoEXT.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDebugMarkerObjectNameInfoEXT(
            JNIEnv *env,
            jobject jVkDebugMarkerObjectNameInfoEXTObject,
			VkDebugMarkerObjectNameInfoEXT *vkDebugMarkerObjectNameInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDebugMarkerObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "jVkDebugMarkerObjectNameInfoEXTObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = getSType(env, jVkDebugMarkerObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSType.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDebugMarkerObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "pNext must be null.");
			return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getObjectType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugReportObjectTypeEXT;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getObjectType");
            return;
        }

        jobject jVkDebugReportObjectTypeEXTObject = env->CallObjectMethod(jVkDebugMarkerObjectNameInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass vkDebugReportObjectTypeEXTEnumClass = env->GetObjectClass(jVkDebugReportObjectTypeEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkDebugReportObjectTypeEXTObject");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkDebugReportObjectTypeEXTEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for valueOf");
            return;
        }

        VkDebugReportObjectTypeEXT objectTypeEnumValue = (VkDebugReportObjectTypeEXT)env->CallIntMethod(jVkDebugReportObjectTypeEXTObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getObject", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getObject.");
            return;
        }

        jlong object = env->CallLongMethod(jVkDebugMarkerObjectNameInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getObjectName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getObjectName.");
            return;
        }

        jstring jString = (jstring)env->CallObjectMethod(jVkDebugMarkerObjectNameInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        const char *tempString = env->GetStringUTFChars(jString, 0);

        char *theObjectName = (char *)calloc(1, strlen(tempString) + 1);
        memoryToFree->push_back(theObjectName);

        strcpy(theObjectName, tempString);
        env->ReleaseStringUTFChars(jString, tempString);


        vkDebugMarkerObjectNameInfoEXT->sType = sTypeValue;
        vkDebugMarkerObjectNameInfoEXT->pNext = (void *)pNext;
        vkDebugMarkerObjectNameInfoEXT->objectType = objectTypeEnumValue;
        vkDebugMarkerObjectNameInfoEXT->object = object;
        vkDebugMarkerObjectNameInfoEXT->pObjectName = theObjectName;
    }
}
