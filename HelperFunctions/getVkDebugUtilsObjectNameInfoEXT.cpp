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
 * getVkDebugUtilsObjectNameInfoEXT.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDebugUtilsObjectNameInfoEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsObjectNameInfoEXTObject,
		VkDebugUtilsObjectNameInfoEXT *vkDebugUtilsObjectNameInfoEXT,
        std::vector<void *> *memoryToFree)
    {
		jclass vkDebugUtilsObjectNameInfoEXTClass = env->GetObjectClass(jVkDebugUtilsObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkDebugUtilsObjectNameInfoEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugUtilsObjectNameInfoEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getpNext methodId");
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDebugUtilsObjectNameInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod for pNext");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTClass, "getObjectType", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkObjectType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectType methodId");
            return;
        }

        jobject jVkObjectTypeObject = env->CallObjectMethod(jVkDebugUtilsObjectNameInfoEXTObject, methodId);
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
        methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTClass, "getObjectHandle", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectHandle methodId");
            return;
        }

        jobject jVkObjectHandle = env->CallObjectMethod(jVkDebugUtilsObjectNameInfoEXTObject, methodId);
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
        methodId = env->GetMethodID(vkDebugUtilsObjectNameInfoEXTClass, "getObjectName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjectName methodId");
            return;
        }

        jstring jTheObjectName = (jstring)env->CallObjectMethod(jVkDebugUtilsObjectNameInfoEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for objectName");
            return;
        }

        const char *tempString = env->GetStringUTFChars(jTheObjectName, 0);

        char *theObjectName = (char *)calloc(1, strlen(tempString) + 1);
        memoryToFree->push_back(theObjectName);

        strcpy(theObjectName, tempString);
        env->ReleaseStringUTFChars(jTheObjectName, tempString);


        vkDebugUtilsObjectNameInfoEXT->sType = (VkStructureType)sTypeValue;
        vkDebugUtilsObjectNameInfoEXT->pNext = (void *)pNext;
        vkDebugUtilsObjectNameInfoEXT->objectType = vkObjectTypeEnumValue;
        vkDebugUtilsObjectNameInfoEXT->objectHandle = objectHandle;
        vkDebugUtilsObjectNameInfoEXT->pObjectName = theObjectName;
    }
}
