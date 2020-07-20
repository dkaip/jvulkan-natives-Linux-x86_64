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
 * getvkDebugUtilsMessengerCallbackDataEXT.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: Douglas Kaip
 */
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getvkDebugUtilsMessengerCallbackDataEXT(
        JNIEnv *env,
        const jobject jVkDebugUtilsMessengerCallbackDataEXTObject,
		VkDebugUtilsMessengerCallbackDataEXT *vkDebugUtilsMessengerCallbackDataEXT,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDebugUtilsMessengerCallbackDataEXTClass = env->GetObjectClass(jVkDebugUtilsMessengerCallbackDataEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to GetObjectClass for jVkDebugUtilsMessengerCallbackDataEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDebugUtilsMessengerCallbackDataEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkDebugUtilsMessengerCallbackDataEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        if (pNextObject != nullptr)
        {
        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
            return;
        }

        void *pNext = nullptr;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getFlags methodId");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        VkDebugUtilsMessengerCallbackDataFlagsEXT flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessengerCallbackDataFlagBitsEXT");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getMessageIdName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getMessageIdName methodId");
            return;
        }

        jstring jMessageIdName = (jstring)env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getMessageIdName");
            return;
        }

        char *theMessageIdName = nullptr;
        if (jMessageIdName != nullptr)
        {
			const char *tempString1 = env->GetStringUTFChars(jMessageIdName, 0);

			theMessageIdName = (char *)calloc(1, strlen(tempString1) + 1);
			memoryToFree->push_back(theMessageIdName);

			strcpy(theMessageIdName, tempString1);
			env->ReleaseStringUTFChars(jMessageIdName, tempString1);
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getMessageIdNumber", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getMessageIdNumber methodId");
            return;
        }

        jint messageIdNumber = env->CallIntMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getMessageIdNumber");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getMessage", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getMessage methodId");
            return;
        }

        jstring jMessage = (jstring)env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getMessage");
            return;
        }

        char *message = nullptr;
        if (jMessage != nullptr)
        {
			const char *tempString2 = env->GetStringUTFChars(jMessage, 0);

			message = (char *)calloc(1, strlen(tempString2) + 1);
			memoryToFree->push_back(message);

			strcpy(message, tempString2);
			env->ReleaseStringUTFChars(jMessage, tempString2);
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getQueueLabels", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getQueueLabels methodId");
            return;
        }

        jobject jVkDebugUtilsLabelEXTCollectionObject = env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getQueueLabels");
            return;
        }

        int numberOfQLabels = 0;
        VkDebugUtilsLabelEXT *queueLabels = nullptr;

        if (jVkDebugUtilsLabelEXTCollectionObject != nullptr)
        {
            jvulkan::getVkDebugUtilsLabelEXTCollection(
                    env,
					jVkDebugUtilsLabelEXTCollectionObject,
                    &queueLabels,
                    &numberOfQLabels,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkDebugUtilsLabelEXTCollection failed");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getCmdBufLabels", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getCmdBufLabels methodId");
            return;
        }

        jVkDebugUtilsLabelEXTCollectionObject = env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getCmdBufLabels");
            return;
        }

        int numberOfCmdBufLabels = 0;
        VkDebugUtilsLabelEXT *cmdBufLabels = nullptr;

        if (jVkDebugUtilsLabelEXTCollectionObject != nullptr)
        {
            jvulkan::getVkDebugUtilsLabelEXTCollection(
                    env,
					jVkDebugUtilsLabelEXTCollectionObject,
                    &cmdBufLabels,
                    &numberOfCmdBufLabels,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkDebugUtilsLabelEXTCollection failed");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTClass, "getObjects", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getObjects methodId");
            return;
        }

        jobject jVkDebugUtilsObjectNameInfoEXTCollectionObject = env->CallObjectMethod(jVkDebugUtilsMessengerCallbackDataEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getObjects");
            return;
        }

        int numberOfObjects = 0;
        VkDebugUtilsObjectNameInfoEXT *objects = nullptr;

        if (jVkDebugUtilsObjectNameInfoEXTCollectionObject != nullptr)
        {
            jvulkan::getVkDebugUtilsObjectNameInfoEXTCollection(
                    env,
					jVkDebugUtilsObjectNameInfoEXTCollectionObject,
                    &objects,
                    &numberOfObjects,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getVkDebugUtilsLabelEXTCollection failed");
                return;
            }
        }


        vkDebugUtilsMessengerCallbackDataEXT->sType = (VkStructureType)sTypeValue;
        vkDebugUtilsMessengerCallbackDataEXT->pNext = (void *)pNext;
        vkDebugUtilsMessengerCallbackDataEXT->flags = flags;
        vkDebugUtilsMessengerCallbackDataEXT->pMessageIdName = theMessageIdName;
		vkDebugUtilsMessengerCallbackDataEXT->messageIdNumber = messageIdNumber;
		vkDebugUtilsMessengerCallbackDataEXT->pMessage = message;
		vkDebugUtilsMessengerCallbackDataEXT->queueLabelCount = numberOfQLabels;
		vkDebugUtilsMessengerCallbackDataEXT->pQueueLabels = queueLabels;
		vkDebugUtilsMessengerCallbackDataEXT->cmdBufLabelCount = numberOfCmdBufLabels;
		vkDebugUtilsMessengerCallbackDataEXT->pCmdBufLabels = cmdBufLabels;
		vkDebugUtilsMessengerCallbackDataEXT->objectCount = numberOfObjects;
		vkDebugUtilsMessengerCallbackDataEXT->pObjects = objects;
    }
}
