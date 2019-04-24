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
 * createVkDebugUtilsMessageSeverityFlagBitsEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

using namespace std;

namespace jvulkan
{
    jobject createVkDebugUtilsMessageSeverityFlagBitsEXT(JNIEnv *env, jint value)
    {
        jboolean handlingException = env->ExceptionCheck();
        if (handlingException == true)
        {
            env->ExceptionClear();
        }

        jclass vkResultClass = env->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT");
        if (env->ExceptionOccurred())
        {
            cout << "createVkDebugUtilsMessageSeverityFlagBitsEXT: could not find class " << "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT" << endl;
            return nullptr;
        }

        jmethodID methodId = env->GetStaticMethodID(vkResultClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT;");
        if (env->ExceptionOccurred())
        {
            cout << "createVkDebugUtilsMessageSeverityFlagBitsEXT: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT;" << endl;
            return nullptr;
        }

        return env->CallStaticObjectMethod(vkResultClass, methodId, value);
    }
}