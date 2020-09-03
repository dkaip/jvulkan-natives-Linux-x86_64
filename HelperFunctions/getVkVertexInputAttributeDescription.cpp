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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkVertexInputAttributeDescription(
            JNIEnv *env,
            const jobject jVkVertexInputAttributeDescriptionObject,
            VkVertexInputAttributeDescription *vkVertexInputAttributeDescription,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputAttributeDescriptionClass = env->GetObjectClass(jVkVertexInputAttributeDescriptionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getLocation", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint location = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint binding = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkFormatObject = env->CallObjectMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumClass = env->GetObjectClass(jVkFormatObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkFormatEnumValue = env->CallIntMethod(jVkFormatObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputAttributeDescriptionClass, "getOffset", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint offset = env->CallIntMethod(jVkVertexInputAttributeDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkVertexInputAttributeDescription->location = location;
        vkVertexInputAttributeDescription->binding  = binding;
        vkVertexInputAttributeDescription->format   = (VkFormat)vkFormatEnumValue;
        vkVertexInputAttributeDescription->offset   = offset;
    }
}
