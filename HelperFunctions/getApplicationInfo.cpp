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
 * getApplicationInfo.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkApplicationInfo(
        JNIEnv *env,
        const jobject jVkApplicationInfoObject,
		VkApplicationInfo *vkApplicationInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkApplicationInfoClass = env->GetObjectClass(jVkApplicationInfoObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkApplicationInfoObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkApplicationInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkApplicationInfoObject);
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
        jmethodID methodId = env->GetMethodID(vkApplicationInfoClass, "getApplicationName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getApplicationName.");
            return;
        }

        jstring theJavaString = (jstring)env->CallObjectMethod(jVkApplicationInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject.");
            return;
        }

        const char *theCString = env->GetStringUTFChars(theJavaString, nullptr);
        char *applicationName = (char *)calloc(strlen(theCString) + 1, sizeof( char));
        memoryToFree->push_back(applicationName);
        strcpy(applicationName, theCString);
        env->ReleaseStringUTFChars(theJavaString, theCString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkApplicationInfoClass, "getApplicationVersion", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getApplicationVersion.");
            return;
        }

        jint applicationVersion = env->CallIntMethod(jVkApplicationInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkApplicationInfoClass, "getEngineName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getEngineName.");
            return;
        }

        theJavaString = (jstring)env->CallObjectMethod(jVkApplicationInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject.");
            return;
        }

        theCString = env->GetStringUTFChars(theJavaString, nullptr);
        char *engineName = (char *)calloc(strlen(theCString) + 1, sizeof( char));
        memoryToFree->push_back(engineName);
        strcpy(engineName, theCString);
        env->ReleaseStringUTFChars(theJavaString, theCString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkApplicationInfoClass, "getEngineVersion", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getEngineVersion.");
            return;
        }

        jint engineVersion = env->CallIntMethod(jVkApplicationInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkApplicationInfoClass, "getApiVersion", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id getApiVersion.");
            return;
        }

        jint apiVersion = env->CallIntMethod(jVkApplicationInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Error calling CallObjectMethod on jVkApplicationInfoObject.");
            return;
        }


        vkApplicationInfo->sType 				= (VkStructureType)sTypeValue;
        vkApplicationInfo->pNext 				= pNext;
        vkApplicationInfo->pApplicationName 	= applicationName;
        vkApplicationInfo->applicationVersion 	= applicationVersion;
        vkApplicationInfo->pEngineName 			= engineName;
        vkApplicationInfo->engineVersion 		= engineVersion;
        vkApplicationInfo->apiVersion			= apiVersion;
    }
}



