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
    void getVkVertexInputBindingDescription(
            JNIEnv *env,
            const jobject jVkVertexInputBindingDescriptionObject,
            VkVertexInputBindingDescription *vkVertexInputBindingDescription,
            std::vector<void *> *memoryToFree)
    {
        jclass vkVertexInputBindingDescriptionClass = env->GetObjectClass(jVkVertexInputBindingDescriptionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getBinding", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint binding = env->CallIntMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getStride", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint stride = env->CallIntMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkVertexInputBindingDescriptionClass, "getInputRate", "()Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkVertexInputRate;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkVertexInputRateObject = env->CallObjectMethod(jVkVertexInputBindingDescriptionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkVertexInputRateEnumClass = env->GetObjectClass(jVkVertexInputRateObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkVertexInputRateEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkVertexInputRateEnumValue = env->CallIntMethod(jVkVertexInputRateObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkVertexInputBindingDescription->binding = binding;
        vkVertexInputBindingDescription->stride = stride;
        vkVertexInputBindingDescription->inputRate = (VkVertexInputRate)vkVertexInputRateEnumValue;
    }
}
