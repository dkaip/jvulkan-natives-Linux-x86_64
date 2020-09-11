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
 * getVkPhysicalDeviceRayTracingFeaturesKHR.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
//    void getVkPhysicalDeviceRayTracingFeaturesKHR(
//            JNIEnv *env,
//            jobject jVkPhysicalDeviceRayTracingFeaturesKHRObject,
//			VkPhysicalDeviceRayTracingFeaturesKHR *vkPhysicalDeviceRayTracingFeaturesKHR,
//            std::vector<void *> *memoryToFree)
//    {
//        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceRayTracingFeaturesKHRObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not get class for jVkPhysicalDeviceRayTracingFeaturesKHRObject");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        VkStructureType sTypeValue = getSType(env, jVkPhysicalDeviceRayTracingFeaturesKHRObject);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Call to getSType failed.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceRayTracingFeaturesKHRObject);
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
//        jmethodID methodId = env->GetMethodID(theClass, "isRayTracing", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracing.");
//            return;
//        }
//
//        VkBool32 rayTracing = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingShaderGroupHandleCaptureReplay", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingShaderGroupHandleCaptureReplay.");
//            return;
//        }
//
//        VkBool32 rayTracingShaderGroupHandleCaptureReplay = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingShaderGroupHandleCaptureReplayMixed", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingShaderGroupHandleCaptureReplayMixed.");
//            return;
//        }
//
//        VkBool32 rayTracingShaderGroupHandleCaptureReplayMixed = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingAccelerationStructureCaptureReplay", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingAccelerationStructureCaptureReplay.");
//            return;
//        }
//
//        VkBool32 rayTracingAccelerationStructureCaptureReplay = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingIndirectTraceRays", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingIndirectTraceRays.");
//            return;
//        }
//
//        VkBool32 rayTracingIndirectTraceRays = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingIndirectAccelerationStructureBuild", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingIndirectAccelerationStructureBuild.");
//            return;
//        }
//
//        VkBool32 rayTracingIndirectAccelerationStructureBuild = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingHostAccelerationStructureCommands", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingHostAccelerationStructureCommands.");
//            return;
//        }
//
//        VkBool32 rayTracingHostAccelerationStructureCommands = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayQuery", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayQuery.");
//            return;
//        }
//
//        VkBool32 rayQuery = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//        ////////////////////////////////////////////////////////////////////////
//        methodId = env->GetMethodID(theClass, "isRayTracingPrimitiveCulling", "()Z");
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Could not find method id for isRayTracingPrimitiveCulling.");
//            return;
//        }
//
//        VkBool32 rayTracingPrimitiveCulling = (VkBool32)env->CallBooleanMethod(jVkPhysicalDeviceRayTracingFeaturesKHRObject, methodId);
//        if (env->ExceptionOccurred())
//        {
//        	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
//            return;
//        }
//
//
//        vkPhysicalDeviceRayTracingFeaturesKHR->sType 	= sTypeValue;
//        vkPhysicalDeviceRayTracingFeaturesKHR->pNext 	= (void *)pNext;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracing	= rayTracing;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingShaderGroupHandleCaptureReplay	= rayTracingShaderGroupHandleCaptureReplay;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingShaderGroupHandleCaptureReplayMixed	= rayTracingShaderGroupHandleCaptureReplayMixed;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingAccelerationStructureCaptureReplay	= rayTracingAccelerationStructureCaptureReplay;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingIndirectTraceRays	= rayTracingIndirectTraceRays;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingIndirectAccelerationStructureBuild	= rayTracingIndirectAccelerationStructureBuild;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingHostAccelerationStructureCommands	= rayTracingHostAccelerationStructureCommands;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayQuery	= rayQuery;
//        vkPhysicalDeviceRayTracingFeaturesKHR->rayTracingPrimitiveCulling	= rayTracingPrimitiveCulling;
//    }
}
