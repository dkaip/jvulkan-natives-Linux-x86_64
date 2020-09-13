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
 * getVkExternalMemoryProperties.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkExternalMemoryProperties(
            JNIEnv *env,
            const jobject jVkExternalMemoryPropertiesObject,
			VkExternalMemoryProperties *vkExternalMemoryProperties,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkExternalMemoryPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkExternalMemoryPropertiesObject.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getExternalMemoryFeatures", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getExternalMemoryFeatures.");
            return;
        }

        jobject externalMemoryFeaturesObject = env->CallObjectMethod(jVkExternalMemoryPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkExternalMemoryFeatureFlags externalMemoryFeatures = (VkExternalMemoryFeatureFlags)getEnumSetValue(
                env,
				externalMemoryFeaturesObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryFeatureFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getExportFromImportedHandleTypes", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getExportFromImportedHandleTypes.");
            return;
        }

        jobject exportFromImportedHandleTypesObject = env->CallObjectMethod(jVkExternalMemoryPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkExternalMemoryHandleTypeFlags exportFromImportedHandleTypes = (VkExternalMemoryHandleTypeFlags)getEnumSetValue(
                env,
				exportFromImportedHandleTypesObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryHandleTypeFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCompatibleHandleTypes", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for getCompatibleHandleTypes.");
            return;
        }

        exportFromImportedHandleTypesObject = env->CallObjectMethod(jVkExternalMemoryPropertiesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        VkExternalMemoryHandleTypeFlags compatibleHandleTypes = (VkExternalMemoryHandleTypeFlags)getEnumSetValue(
                env,
				exportFromImportedHandleTypesObject,
                "com/CIMthetics/jvulkan/VulkanCore/Enums/VkExternalMemoryHandleTypeFlagBits");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
            return;
        }


        vkExternalMemoryProperties->externalMemoryFeatures = externalMemoryFeatures;
        vkExternalMemoryProperties->exportFromImportedHandleTypes = exportFromImportedHandleTypes;
        vkExternalMemoryProperties->compatibleHandleTypes = compatibleHandleTypes;
    }
}
