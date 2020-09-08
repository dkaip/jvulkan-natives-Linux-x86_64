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

		jclass theClass = nullptr;
		jobject theObject = nullptr;
		createJavaObjectUsingDefaultConstructor(
				env,
				"com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsMessengerCallbackDataEXT",
				&theClass,
				&theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createJavaObjectUsingDefaultConstructor");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jFlags = createVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet(
        		env,
				pCallbackData->flags);

        jmethodID methodId = env->GetMethodID(theClass, "setFlags", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setFlags");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, jFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setFlags");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMessageIdName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessageIdName");
            return nullptr;
        }

        jstring messageIdNameString = env->NewStringUTF(pCallbackData->pMessageIdName);

        env->CallVoidMethod(theObject, methodId, messageIdNameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessageIdName");
            return nullptr;
        }

        env->DeleteLocalRef(messageIdNameString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMessageIdNumber", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessageIdNumber");
            return nullptr;
        }

        env->CallVoidMethod(theObject, methodId, pCallbackData->messageIdNumber);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessageIdNumber");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMessage", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setMessage");
            return nullptr;
        }

        jstring messageString = env->NewStringUTF(pCallbackData->pMessage);

        env->CallVoidMethod(theObject, methodId, messageString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setMessage");
            return nullptr;
        }

        env->DeleteLocalRef(messageString);


        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setQueueLabels", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setQueueLabels");
            return nullptr;
        }

        jobject queueLabelsCollection = createVkDebugUtilsLabelEXTCollection(
        		env, pCallbackData->queueLabelCount, pCallbackData->pQueueLabels);

        env->CallVoidMethod(theObject, methodId, queueLabelsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setQueueLabels");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setCmdBufLabels", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setCmdBufLabels");
            return nullptr;
        }

        jobject cmdBufLabelsCollection = createVkDebugUtilsLabelEXTCollection(
        		env, pCallbackData->cmdBufLabelCount, pCallbackData->pCmdBufLabels);

        env->CallVoidMethod(theObject, methodId, cmdBufLabelsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setCmdBufLabels");
            return nullptr;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setObjects", "(Ljava/util/Collection;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method setObjects");
            return nullptr;
        }

        jobject objectsCollection = createVkDebugUtilsObjectNameInfoEXTCollection(
        		env, pCallbackData->objectCount, pCallbackData->pObjects);


        env->CallVoidMethod(theObject, methodId, objectsCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "failed executing method setObjects");
            return nullptr;
        }

        return theObject;
    }
}
