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
 * getVkDisplaySurfaceCreateInfoKHR.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    void getVkDisplaySurfaceCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkDisplaySurfaceCreateInfoKHRObject,
			VkDisplaySurfaceCreateInfoKHR *vkDisplaySurfaceCreateInfoKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDisplaySurfaceCreateInfoKHRClass = env->GetObjectClass(jVkDisplaySurfaceCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get the class for jVkDisplaySurfaceCreateInfoKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkDisplaySurfaceCreateInfoKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "getSTypeAsInt failed");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNext(env, jVkDisplaySurfaceCreateInfoKHRObject);
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
        jmethodID methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getFlags");
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        VkDisplaySurfaceCreateFlagsKHR flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulka/VulkanExtensions/VK11/Enums/VkDisplaySurfaceCreateFlagBitsKHR");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getDisplayMode", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDisplayModeKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDisplayMode methodId");
            return;
        }

        jobject jVkDisplayModeKHRHandleObject = env->CallObjectMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getDisplayMode");
            return;
        }

        VkDisplayModeKHR_T *vkDisplayModeKHRHandle = (VkDisplayModeKHR_T *)jvulkan::getHandleValue(env, jVkDisplayModeKHRHandleObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getHandleValue for jVkDisplayModeKHRHandleObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getPlaneIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPlaneIndex");
            return;
        }

        jint planeIndex = env->CallIntMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed for getPlaneIndex");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getPlaneStackIndex", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getPlaneStackIndex");
            return;
        }

        jint planeStackIndex = env->CallIntMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed for getPlaneStackIndex");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getTransform", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTransform methodId");
            return;
        }

        jobject jVkSurfaceTransformFlagBitsKHRObject = env->CallObjectMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getTransform for objectType");
            return;
        }

        jclass vkSurfaceTransformFlagBitsKHREnumClass = env->GetObjectClass(jVkSurfaceTransformFlagBitsKHRObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkSurfaceTransformFlagBitsKHREnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkSurfaceTransformFlagBitsKHR vkSurfaceTransformFlagBitsKHREnumValue = (VkSurfaceTransformFlagBitsKHR)env->CallIntMethod(jVkSurfaceTransformFlagBitsKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getGlobalAlpha", "()F");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getGlobalAlpha");
            return;
        }

        jfloat globalAlpha = env->CallFloatMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallFloatMethod failed for getGlobalAlpha");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getAlphaMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDisplayPlaneAlphaFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getAlphaMode methodId");
            return;
        }

        jobject jVkDisplayPlaneAlphaFlagBitsKHRObject = env->CallObjectMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getAlphaMode for objectType");
            return;
        }

        jclass vkDisplayPlaneAlphaFlagBitsKHREnumClass = env->GetObjectClass(jVkSurfaceTransformFlagBitsKHRObject);

        valueOfMethodId = env->GetMethodID(vkSurfaceTransformFlagBitsKHREnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkDisplayPlaneAlphaFlagBitsKHR vkDisplayPlaneAlphaFlagBitsKHREnumValue = (VkDisplayPlaneAlphaFlagBitsKHR)env->CallIntMethod(jVkDisplayPlaneAlphaFlagBitsKHRObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDisplaySurfaceCreateInfoKHRClass, "getImageExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getImageExtent");
            return;
        }

        jobject jVkExtent2DObject = env->CallObjectMethod(jVkDisplaySurfaceCreateInfoKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallObjectMethod failed for getImageExtent");
            return;
        }

        VkExtent2D vkExtent2D = {};
        getVkExtent2D(
                env,
                jVkExtent2DObject,
                &vkExtent2D,
                memoryToFree);


        vkDisplaySurfaceCreateInfoKHR->sType 			= (VkStructureType)sTypeValue;
        vkDisplaySurfaceCreateInfoKHR->pNext 			= (void *)pNext;
        vkDisplaySurfaceCreateInfoKHR->flags 			= flags;
        vkDisplaySurfaceCreateInfoKHR->displayMode 		= vkDisplayModeKHRHandle;
		vkDisplaySurfaceCreateInfoKHR->planeIndex 		= planeIndex;
		vkDisplaySurfaceCreateInfoKHR->planeStackIndex 	= planeStackIndex;
		vkDisplaySurfaceCreateInfoKHR->transform 		= vkSurfaceTransformFlagBitsKHREnumValue;
		vkDisplaySurfaceCreateInfoKHR->globalAlpha 		= globalAlpha;
		vkDisplaySurfaceCreateInfoKHR->alphaMode 		= vkDisplayPlaneAlphaFlagBitsKHREnumValue;
		vkDisplaySurfaceCreateInfoKHR->imageExtent.height = vkExtent2D.height;
		vkDisplaySurfaceCreateInfoKHR->imageExtent.width  = vkExtent2D.width;
    }
}
