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
 * getVkPipelineViewportCoarseSampleOrderStateCreateInfoNV.cpp
 *
 *  Created on: May 28, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPipelineViewportCoarseSampleOrderStateCreateInfoNV(
            JNIEnv *env,
            const jobject jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject,
			VkPipelineViewportCoarseSampleOrderStateCreateInfoNV *vkPipelineViewportCoarseSampleOrderStateCreateInfoNV,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNext failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getSampleOrderType", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkCoarseSampleOrderTypeNV;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType getSampleOrderType");
            return;
        }

        jobject jVkCoarseSampleOrderTypeNVObject = env->CallObjectMethod(jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getSampleOrderType");
            return;
        }

        jclass vkCoarseSampleOrderTypeNVObjectEnumClass = env->GetObjectClass(jVkCoarseSampleOrderTypeNVObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for sampleOrderType");
            return;
        }

        jmethodID valueOfMethodId = env->GetMethodID(vkCoarseSampleOrderTypeNVObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkCoarseSampleOrderTypeNV vkCoarseSampleOrderTypeNVEnumValue = (VkCoarseSampleOrderTypeNV)env->CallIntMethod(jVkCoarseSampleOrderTypeNVObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "getCustomSampleOrders", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getCustomSampleOrders");
            return;
        }

        jobject jCustomSampleOrders = env->CallObjectMethod(jVkPipelineViewportCoarseSampleOrderStateCreateInfoNVObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int customSampleOrderCount = 0;
        VkCoarseSampleOrderCustomNV *customSampleOrders = nullptr;
        getVkCoarseSampleOrderCustomNVCollection(
                env,
				jCustomSampleOrders,
                &customSampleOrders,
                &customSampleOrderCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkPipelineCreationFeedbackEXTCollection");
            return;
        }


        vkPipelineViewportCoarseSampleOrderStateCreateInfoNV->sType = sTypeValue;
        vkPipelineViewportCoarseSampleOrderStateCreateInfoNV->pNext = pNext;
        vkPipelineViewportCoarseSampleOrderStateCreateInfoNV->sampleOrderType = vkCoarseSampleOrderTypeNVEnumValue;
        vkPipelineViewportCoarseSampleOrderStateCreateInfoNV->customSampleOrderCount = customSampleOrderCount;
        vkPipelineViewportCoarseSampleOrderStateCreateInfoNV->pCustomSampleOrders = customSampleOrders;
    }
}
