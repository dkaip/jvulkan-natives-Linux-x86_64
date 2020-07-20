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
 * getVkDescriptorUpdateTemplateEntry.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDescriptorUpdateTemplateEntry(
        JNIEnv *env,
        const jobject jVkDescriptorUpdateTemplateEntryObject,
		VkDescriptorUpdateTemplateEntry *vkDescriptorUpdateTemplateEntry,
        std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorUpdateTemplateEntryClass = env->GetObjectClass(jVkDescriptorUpdateTemplateEntryObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkDescriptorUpdateTemplateEntryObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getDstBinding", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDstBinding methodId");
            return;
        }

        jint dstBinding = env->CallIntMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getDstBinding");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getDstArrayElement", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDstArrayElement methodId");
            return;
        }

        jint dstArrayElement = env->CallIntMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getDstArrayElement");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getDescriptorCount", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDescriptorCount methodId");
            return;
        }

        jint descriptorCount = env->CallIntMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for getDescriptorCount");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getDescriptorType", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkDescriptorType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getTemplateType methodId");
            return;
        }

        jobject jVkDescriptorTypeObject = env->CallObjectMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod for getTemplateType");
            return;
        }

        jclass vkDescriptorTypeEnumClass = env->GetObjectClass(jVkDescriptorTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkDescriptorTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get valueOf methodId");
            return;
        }

        VkDescriptorType vkDescriptorTypeEnumValue = (VkDescriptorType)env->CallIntMethod(jVkDescriptorTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod for objectType enum value");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getOffset", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDescriptorCount getOffset");
            return;
        }

        jlong offset = env->CallLongMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod for getOffset");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryClass, "getStride", "()J");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get getDescriptorCount getStride");
            return;
        }

        jlong stride = env->CallLongMethod(jVkDescriptorUpdateTemplateEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallLongMethod for getStride");
            return;
        }


        vkDescriptorUpdateTemplateEntry->dstBinding = dstBinding;
        vkDescriptorUpdateTemplateEntry->dstArrayElement = dstArrayElement;
        vkDescriptorUpdateTemplateEntry->descriptorCount = descriptorCount;
        vkDescriptorUpdateTemplateEntry->descriptorType = vkDescriptorTypeEnumValue;
        vkDescriptorUpdateTemplateEntry->offset = offset;
        vkDescriptorUpdateTemplateEntry->stride = stride;
    }
}



