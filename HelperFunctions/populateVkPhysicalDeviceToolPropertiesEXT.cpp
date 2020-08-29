/*
 * Copyright 2020 Douglas Kaip
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
 * populateVkPhysicalDeviceToolPropertiesEXT.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceToolPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceToolPropertiesEXTObject,
			VkPhysicalDeviceToolPropertiesEXT const *vkPhysicalDeviceToolPropertiesEXT)
	{
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceToolPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDeviceToolPropertiesEXT");
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setName", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setName");
            return;
        }

        jstring nameString = env->NewStringUTF(vkPhysicalDeviceToolPropertiesEXT->name);

        env->CallVoidMethod(jVkPhysicalDeviceToolPropertiesEXTObject, methodId, nameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(nameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setVersion", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVersion");
            return;
        }

        nameString = env->NewStringUTF(vkPhysicalDeviceToolPropertiesEXT->version);

        env->CallVoidMethod(jVkPhysicalDeviceToolPropertiesEXTObject, methodId, nameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(nameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPurposes", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPurposes");
            return;
        }

        jobject jpurposes = createVkToolPurposeFlagsEXTAsEnumSet(env, vkPhysicalDeviceToolPropertiesEXT->purposes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkShaderStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceToolPropertiesEXTObject, methodId, jpurposes);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setDescription", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setDescription");
            return;
        }

        nameString = env->NewStringUTF(vkPhysicalDeviceToolPropertiesEXT->description);

        env->CallVoidMethod(jVkPhysicalDeviceToolPropertiesEXTObject, methodId, nameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(nameString);

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setLayer", "(Ljava/lang/String;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setLayer");
            return;
        }

        nameString = env->NewStringUTF(vkPhysicalDeviceToolPropertiesEXT->layer);

        env->CallVoidMethod(jVkPhysicalDeviceToolPropertiesEXTObject, methodId, nameString);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        env->DeleteLocalRef(nameString);
	}
}
