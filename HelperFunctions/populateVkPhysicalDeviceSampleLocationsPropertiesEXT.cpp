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
 * populateVkPhysicalDeviceSampleLocationsPropertiesEXT.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDeviceSampleLocationsPropertiesEXT(
			JNIEnv *env,
			jobject jVkPhysicalDeviceSampleLocationsPropertiesEXTObject,
			const VkPhysicalDeviceSampleLocationsPropertiesEXT *vkPhysicalDeviceSampleLocationsPropertiesEXT,
			std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDeviceSampleLocationsPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceSampleLocationsPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setSampleLocationSampleCounts", "(Ljava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampleLocationSampleCounts");
            return;
        }

        jobject jVkSampleCountFlags = createVkSampleCountFlagsAsEnumSet(env, vkPhysicalDeviceSampleLocationsPropertiesEXT->sampleLocationSampleCounts);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkShaderStageFlagsAsEnumSet");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSampleLocationsPropertiesEXTObject, methodId, jVkSampleCountFlags);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setMaxSampleLocationGridSize", "(Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setMaxSampleLocationGridSize");
            return;
        }

	    jobject extent2DObject = createVkExtent2D(env, &(vkPhysicalDeviceSampleLocationsPropertiesEXT->maxSampleLocationGridSize));
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVkExtent2D");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSampleLocationsPropertiesEXTObject, methodId, extent2DObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
		methodId = env->GetMethodID(theClass, "setSampleLocationCoordinateRange", "([F)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampleLocationCoordinateRange");
            return;
        }

        jfloatArray sampleLocationCoordinateRange = env->NewFloatArray(sizeof(vkPhysicalDeviceSampleLocationsPropertiesEXT->sampleLocationCoordinateRange)/sizeof(float));
        if (sampleLocationCoordinateRange == nullptr)
        {
        	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for sampleLocationCoordinateRange");
            return;
        }

        env->SetFloatArrayRegion(sampleLocationCoordinateRange, 0, sizeof(vkPhysicalDeviceSampleLocationsPropertiesEXT->sampleLocationCoordinateRange)/sizeof(float), (const jfloat *)vkPhysicalDeviceSampleLocationsPropertiesEXT->sampleLocationCoordinateRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling ExceptionOccurred");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSampleLocationsPropertiesEXTObject, methodId, sampleLocationCoordinateRange);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setSampleLocationSubPixelBits", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setSampleLocationSubPixelBits");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSampleLocationsPropertiesEXTObject, methodId, vkPhysicalDeviceSampleLocationsPropertiesEXT->sampleLocationSubPixelBits);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setVariableSampleLocations", "(Z)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setVariableSampleLocations");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDeviceSampleLocationsPropertiesEXTObject, methodId, vkPhysicalDeviceSampleLocationsPropertiesEXT->variableSampleLocations);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
