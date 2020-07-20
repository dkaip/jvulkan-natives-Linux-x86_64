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
 * getVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    jobject createVkDebugUtilsMessengerCallbackDataFlagsEXTAsEnumSet(JNIEnv *env, VkDebugUtilsMessengerCallbackDataFlagsEXT flags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessengerCallbackDataFlagsEXT";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessengerCallbackDataFlagsEXT;";
        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class \"java/util/EnumSet\"");
            return nullptr;
        }

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
        	LOGERROR(env, "%s", "Could not find static method noneOf");
            return nullptr;
        }

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed calling static method noneOf");
            return nullptr;
        }

        // Currently there are no values for this Enum so we are returning an empty set.
        return enumSetObject;
    }
}
