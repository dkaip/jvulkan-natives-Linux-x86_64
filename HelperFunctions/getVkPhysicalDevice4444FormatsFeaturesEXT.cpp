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
 * getVkPhysicalDevice4444FormatsFeaturesEXT.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
//    void getVkPhysicalDevice4444FormatsFeaturesEXT(
//            JNIEnv *env,
//            jobject jVkPhysicalDevice4444FormatsFeaturesEXTObject,
//			VkPhysicalDevice4444FormatsFeaturesEXT *vkPhysicalDevice4444FormatsFeaturesEXT,
//            std::vector<void *> *memoryToFree)
//    {
//        jclass theClass = env->GetObjectClass(jVkPhysicalDevice4444FormatsFeaturesEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDevice4444FormatsFeaturesEXTObject.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        VkStructureType sTypeValue = getSType(env, jVkPhysicalDevice4444FormatsFeaturesEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getSType failed.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jobject jpNextObject = getpNextObject(env, jVkPhysicalDevice4444FormatsFeaturesEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getpNext failed.");
//            return;
//        }
//
//        void *pNext = nullptr;
//        if (jpNextObject != nullptr)
//        {
//        	getpNextChain(
//        			env,
//					jpNextObject,
//        			&pNext,
//        			memoryToFree);
//            if (env->ExceptionOccurred())
//            {
//            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
//                return;
//            }
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jmethodID methodId = env->GetMethodID(theClass, "isFormatA4R4G4B4", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isFormatA4R4G4B4.");
//            return;
//        }
//
//        VkBool32 formatA4R4G4B4 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDevice4444FormatsFeaturesEXTObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to CallBooleanMethod failed.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jmethodID methodId = env->GetMethodID(theClass, "isFormatA4B4G4R4", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isFormatA4B4G4R4.");
//            return;
//        }
//
//        VkBool32 formatA4B4G4R4 = (VkBool32)env->CallBooleanMethod(jVkPhysicalDevice4444FormatsFeaturesEXTObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to CallBooleanMethod failed.");
//            return;
//        }
//
//
//        vkPhysicalDevice4444FormatsFeaturesEXT->sType = sTypeValue;
//        vkPhysicalDevice4444FormatsFeaturesEXT->pNext = pNext;
//        vkPhysicalDevice4444FormatsFeaturesEXT->formatA4R4G4B4 = formatA4R4G4B4;
//		vkPhysicalDevice4444FormatsFeaturesEXT->formatA4B4G4R4 = formatA4B4G4R4;
//    }
}
