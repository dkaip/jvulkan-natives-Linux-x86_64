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
 * getVkPhysicalDeviceDescriptorIndexingFeatures.cpp
 *
 *  Created on: May 17, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceDescriptorIndexingFeatures(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceDescriptorIndexingFeaturesObject,
			VkPhysicalDeviceDescriptorIndexingFeatures *vkPhysicalDeviceDescriptorIndexingFeatures,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceDescriptorIndexingFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceDescriptorIndexingFeaturesObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSType(env, jVkPhysicalDeviceDescriptorIndexingFeaturesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->sType = sTypeValue;

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceDescriptorIndexingFeaturesObject);
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

        vkPhysicalDeviceDescriptorIndexingFeatures->pNext = pNext;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayDynamicIndexing");
            return;
        }

        jboolean theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderInputAttachmentArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayDynamicIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderUniformTexelBufferArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayDynamicIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderStorageTexelBufferArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderUniformBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSampledImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSampledImageArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderSampledImageArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderStorageBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageImageArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderStorageImageArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderInputAttachmentArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderUniformTexelBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->shaderStorageTexelBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingUniformBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingSampledImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingSampledImageUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingSampledImageUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageImageUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingStorageImageUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingStorageBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformTexelBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingUniformTexelBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageTexelBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingStorageTexelBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUpdateUnusedWhilePending", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUpdateUnusedWhilePending");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingUpdateUnusedWhilePending = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingPartiallyBound", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingPartiallyBound");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingPartiallyBound = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingVariableDescriptorCount", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingVariableDescriptorCount");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->descriptorBindingVariableDescriptorCount = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isRuntimeDescriptorArray", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRuntimeDescriptorArray");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeatures->runtimeDescriptorArray = theValue;

    }
}
