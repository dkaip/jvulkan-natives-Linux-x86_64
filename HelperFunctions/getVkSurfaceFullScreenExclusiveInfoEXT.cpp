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
 * getVkSurfaceFullScreenExclusiveInfoEXT.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
//    void getVkSurfaceFullScreenExclusiveInfoEXT(
//            JNIEnv *env,
//            const jobject jVkSurfaceFullScreenExclusiveInfoEXTObject,
//			VkSurfaceFullScreenExclusiveInfoEXT *vkSurfaceFullScreenExclusiveInfoEXT,
//            std::vector<void *> *memoryToFree)
//    {
//        jclass theClass = env->GetObjectClass(jVkSurfaceFullScreenExclusiveInfoEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find class for jVkSurfaceFullScreenExclusiveInfoEXTObject");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        VkStructureType sTypeValue = getSTypeAsInt(env, jVkSurfaceFullScreenExclusiveInfoEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jobject jpNextObject = getpNextObject(env, jVkSurfaceFullScreenExclusiveInfoEXTObject);
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
//        jmethodID methodId = env->GetMethodID(theClass, "getFullScreenExclusive", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkFullScreenExclusiveEXT;");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for getFullScreenExclusive.");
//            return;
//        }
//
//        jobject jVkFullScreenExclusiveEXTObject = env->CallObjectMethod(jVkSurfaceFullScreenExclusiveInfoEXTObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
//            return;
//        }
//
//        jclass vkFullScreenExclusiveEXTEnumClass = env->GetObjectClass(jVkFullScreenExclusiveEXTObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find class for jVkFullScreenExclusiveEXTObject.");
//            return;
//        }
//
//        jmethodID valueOfMethodId = env->GetMethodID(vkFullScreenExclusiveEXTEnumClass, "valueOf", "()I");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for valueOf.");
//            return;
//        }
//
//        VkFullScreenExclusiveEXT vkFullScreenExclusiveEXTEnumValue = (VkFullScreenExclusiveEXT)env->CallIntMethod(jVkFullScreenExclusiveEXTObject, valueOfMethodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
//            return;
//        }
//
//
//        vkSurfaceFullScreenExclusiveInfoEXT->sType = sTypeValue;
//        vkSurfaceFullScreenExclusiveInfoEXT->pNext = pNext;
//        vkSurfaceFullScreenExclusiveInfoEXT->fullScreenExclusive = vkFullScreenExclusiveEXTEnumValue;
//    }
}
