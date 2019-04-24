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
 * getVkDebugUtilsObjectTagInfoEXT.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "../headers/slf4j.hh"
#include "HelperFunctions.hh"

namespace jvulkan
{
	void getVkDebugUtilsObjectTagInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsObjectTagInfoEXTObject,
		VkDebugUtilsObjectTagInfoEXT *vkDebugUtilsObjectTagInfoEXT,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDebugUtilsObjectTagInfoEXTClass = env->GetObjectClass(jVkDebugUtilsObjectTagInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkDebugUtilsObjectTagInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugUtilsObjectTagInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsObjectTagInfoEXTClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getpNext methodId");
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDebugUtilsObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod for pNext");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsObjectTagInfoEXTClass, "getObjectType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectType methodId");
            return;
        }

        jobject jVkObjectTypeObject = env->CallObjectMethod(jVkDebugUtilsObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for objectType");
            return;
        }

        jclass vkObjectTypeEnumClass = env->GetObjectClass(jVkObjectTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkObjectTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkObjectType vkObjectTypeEnumValue = (VkObjectType)env->CallIntMethod(jVkObjectTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsObjectTagInfoEXTClass, "getObjectHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectHandle methodId");
            return;
        }

        jobject jVkObjectHandle = env->CallObjectMethod(jVkDebugUtilsObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for objectType");
            return;
        }

    	uint64_t objectHandle = (uint64_t)jvulkan::getHandleValue(env, jVkObjectHandle);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to getHandleValue for jVkObjectHandle");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsObjectTagInfoEXTClass, "getTagName", "()J;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectName methodId");
            return;
        }

        uint64_t tagName = (uint64_t)env->CallLongMethod(jVkDebugUtilsObjectTagInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for objectName");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsObjectTagInfoEXTClass, "getTag", "()[B");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTag methodId");
            return;
        }

        jbyteArray jTag= (jbyteArray)env->CallObjectMethod(jVkDebugUtilsObjectTagInfoEXTObject, methodId);

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


        vkDebugUtilsObjectTagInfoEXT->sType = (VkStructureType)sTypeValue;
        vkDebugUtilsObjectTagInfoEXT->pNext = (void *)pNext;
        vkDebugUtilsObjectTagInfoEXT->objectType = vkObjectTypeEnumValue;
        vkDebugUtilsObjectTagInfoEXT->objectHandle = objectHandle;
        vkDebugUtilsObjectTagInfoEXT->tagName = tagName;
        vkDebugUtilsObjectTagInfoEXT->tagSize = arrayLength;
		vkDebugUtilsObjectTagInfoEXT->pTag = tagArray;
    }
}

