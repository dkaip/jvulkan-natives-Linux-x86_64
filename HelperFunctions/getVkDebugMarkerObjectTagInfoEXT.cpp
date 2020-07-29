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
 * getVkDebugMarkerObjectTagInfoEXT.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDebugMarkerObjectTagInfoEXT(
            JNIEnv *env,
            jobject jVkDebugMarkerObjectTagInfoEXTObject,
			VkDebugMarkerObjectTagInfoEXT *vkDebugMarkerObjectTagInfoEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkDebugMarkerObjectTagInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "jVkDebugMarkerObjectTagInfoEXTObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugMarkerObjectTagInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkDebugMarkerObjectTagInfoEXTObject);
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

        jobject jVkDebugReportObjectTypeEXTObject = env->CallObjectMethod(jVkDebugMarkerObjectTagInfoEXTObject, methodId);
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

        jlong object = env->CallLongMethod(jVkDebugMarkerObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getTagName", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getTagName.");
            return;
        }

        jlong tagName = env->CallLongMethod(jVkDebugMarkerObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getTag", "()[B");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTag methodId");
            return;
        }

        jbyteArray jTag= (jbyteArray)env->CallObjectMethod(jVkDebugMarkerObjectTagInfoEXTObject, methodId);

        char *tagArray = nullptr;
        jsize arrayLength = 0;
        if (jTag != nullptr)
        {
            arrayLength = env->GetArrayLength(jTag);

            tagArray = (char *)calloc(arrayLength, sizeof(char));
            memoryToFree->push_back(tagArray);

            env->GetByteArrayRegion(jTag, 0, arrayLength, (signed char *)tagArray);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error trying to get GetByteArrayRegion for tag");
                return;
            }
        }


        vkDebugMarkerObjectTagInfoEXT->sType = (VkStructureType)sTypeValue;
        vkDebugMarkerObjectTagInfoEXT->pNext = (void *)pNext;
        vkDebugMarkerObjectTagInfoEXT->objectType = objectTypeEnumValue;
        vkDebugMarkerObjectTagInfoEXT->object = object;
        vkDebugMarkerObjectTagInfoEXT->tagName = tagName;
        vkDebugMarkerObjectTagInfoEXT->pTag = tagArray;
    }
}
