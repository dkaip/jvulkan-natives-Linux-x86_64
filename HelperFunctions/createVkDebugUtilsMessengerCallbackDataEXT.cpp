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
 * createVkDebugUtilsMessengerCallbackDataEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

//#include <cstring>
//#include <iostream>
//#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    jobject createVkDebugUtilsMessengerCallbackDataEXT(JNIEnv *env, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
    {
        jboolean handlingException = env->ExceptionCheck();
        if (handlingException == true)
        {
        	LOGWARN(env, "%s", "handlingException was already true...clearing");
            env->ExceptionClear();
        }

        // Locate the VkDebugUtilsMessengerCallbackDataEXT class
        jclass vkDebugUtilsMessengerCallbackDataEXTclass = env->FindClass(
        		"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsMessengerCallbackDataEXT");
        if ( vkDebugUtilsMessengerCallbackDataEXTclass == nullptr)
        {
        	LOGERROR(env, "%s", "could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsMessengerCallbackDataEXT");
        	return nullptr;
        }

        // Locate the constructor
        jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "<init>", "()V");
        if (methodId == nullptr)
        {
        	LOGERROR(env, "%s", "could not find constructor");
        	return nullptr;
        }

        jobject vkDebugUtilsMessengerCallbackDataEXTObject =
        		env->NewObject(vkDebugUtilsMessengerCallbackDataEXTclass, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed executing constructor for VkDebugUtilsMessengerCallbackDataEXT object");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jFlags = createVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet(
        		env,
				pCallbackData->flags);

        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setFlags");
            return nullptr;
        }

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, jFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setFlags");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setMessageIdName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessageIdName");
            return nullptr;
        }

        jstring messageIdNameString = env->NewStringUTF(pCallbackData->pMessageIdName);

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, messageIdNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessageIdName");
            return nullptr;
        }

        env->DeleteLocalRef(messageIdNameString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setMessageIdNumber", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessageIdNumber");
            return nullptr;
        }

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, pCallbackData->messageIdNumber);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessageIdNumber");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setMessage", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessage");
            return nullptr;
        }

        jstring messageString = env->NewStringUTF(pCallbackData->pMessage);

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, messageString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessage");
            return nullptr;
        }

        env->DeleteLocalRef(messageString);


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setQueueLabels", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setQueueLabels");
            return nullptr;
        }

        jobject queueLabelsCollection = createVkDebugUtilsLabelEXTCollection(
        		env, pCallbackData->queueLabelCount, pCallbackData->pQueueLabels);

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, queueLabelsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setQueueLabels");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setCmdBufLabels", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setCmdBufLabels");
            return nullptr;
        }

        jobject cmdBufLabelsCollection = createVkDebugUtilsLabelEXTCollection(
        		env, pCallbackData->cmdBufLabelCount, pCallbackData->pCmdBufLabels);

        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, cmdBufLabelsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setCmdBufLabels");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDebugUtilsMessengerCallbackDataEXTclass, "setObjects", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setObjects");
            return nullptr;
        }

        jobject objectsCollection = createVkDebugUtilsObjectNameInfoEXTCollection(
        		env, pCallbackData->objectCount, pCallbackData->pObjects);


        env->CallVoidMethod(vkDebugUtilsMessengerCallbackDataEXTObject, methodId, objectsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setObjects");
            return nullptr;
        }

        return vkDebugUtilsMessengerCallbackDataEXTObject;
    }
}
