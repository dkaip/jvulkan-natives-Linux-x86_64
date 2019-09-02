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
 * getVkPhysicalDeviceDescriptorIndexingFeaturesEXT.cpp
 *
 *  Created on: May 17, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPhysicalDeviceDescriptorIndexingFeaturesEXT(
            JNIEnv *env,
            const jobject jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject,
			VkPhysicalDeviceDescriptorIndexingFeaturesEXT *vkPhysicalDeviceDescriptorIndexingFeaturesEXT,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->sType = sTypeValue;

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject);
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

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->pNext = pNext;

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayDynamicIndexing");
            return;
        }

        jboolean theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderInputAttachmentArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayDynamicIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderUniformTexelBufferArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayDynamicIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayDynamicIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderStorageTexelBufferArrayDynamicIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderUniformBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderSampledImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderSampledImageArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderSampledImageArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderStorageBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageImageArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageImageArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderStorageImageArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderInputAttachmentArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderInputAttachmentArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderInputAttachmentArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderUniformTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderUniformTexelBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderUniformTexelBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isShaderStorageTexelBufferArrayNonUniformIndexing", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isShaderStorageTexelBufferArrayNonUniformIndexing");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->shaderStorageTexelBufferArrayNonUniformIndexing = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingUniformBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingSampledImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingSampledImageUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingSampledImageUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageImageUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageImageUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingStorageImageUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingStorageBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUniformTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUniformTexelBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingUniformTexelBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingStorageTexelBufferUpdateAfterBind", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingStorageTexelBufferUpdateAfterBind");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingStorageTexelBufferUpdateAfterBind = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingUpdateUnusedWhilePending", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingUpdateUnusedWhilePending");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingUpdateUnusedWhilePending = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingPartiallyBound", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingPartiallyBound");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingPartiallyBound = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isDescriptorBindingVariableDescriptorCount", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isDescriptorBindingVariableDescriptorCount");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->descriptorBindingVariableDescriptorCount = theValue;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "isRuntimeDescriptorArray", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for isRuntimeDescriptorArray");
            return;
        }

        theValue = env->CallBooleanMethod(jVkPhysicalDeviceDescriptorIndexingFeaturesEXTObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
            return;
        }

        vkPhysicalDeviceDescriptorIndexingFeaturesEXT->runtimeDescriptorArray = theValue;

    }
}
