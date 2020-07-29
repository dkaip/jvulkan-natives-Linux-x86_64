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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetBufferMemoryRequirements
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDevice;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkMemoryRequirements;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetBufferMemoryRequirements
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkBuffer, jobject jVkMemoryRequirements)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)jvulkan::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkBuffer_T *bufferHandle = (VkBuffer_T *)jvulkan::getHandleValue(env, jVkBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkMemoryRequirements vkMemoryRequirements = {};

    vkGetBufferMemoryRequirements(logicalDeviceHandle, bufferHandle, &vkMemoryRequirements);

//    jclass vkMemoryRequirementsClass = env->GetObjectClass(jVkMemoryRequirements);
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    ////////////////////////////////////////////////////////////////////////////
//    jmethodID methodId = env->GetMethodID(vkMemoryRequirementsClass, "setSize", "(J)V");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    env->CallVoidMethod(jVkMemoryRequirements, methodId, vkMemoryRequirements.size);
//
//    ////////////////////////////////////////////////////////////////////////////
//    methodId = env->GetMethodID(vkMemoryRequirementsClass, "setAlignment", "(J)V");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    env->CallVoidMethod(jVkMemoryRequirements, methodId, vkMemoryRequirements.alignment);
//
//    ////////////////////////////////////////////////////////////////////////////
//    jclass bitSetClass = env->FindClass("java/util/BitSet");
//
//    methodId = env->GetMethodID(bitSetClass, "<init>", "(I)V");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    jobject bitSetObject = env->NewObject(bitSetClass, methodId, 32);
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    methodId = env->GetMethodID(bitSetClass, "set", "(I)V");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    for (uint32_t i = 0; i < 32; i++)
//    {
//        if ((1 << i) & vkMemoryRequirements.memoryTypeBits)
//        {
//            env->CallVoidMethod(bitSetObject, methodId, i);
//            if (env->ExceptionOccurred())
//            {
//                return;
//            }
//        }
//    }
//
//    methodId = env->GetMethodID(vkMemoryRequirementsClass, "setMemoryTypeBits", "(Ljava/util/BitSet;)V");
//    if (env->ExceptionOccurred())
//    {
//        return;
//    }
//
//    env->CallVoidMethod(jVkMemoryRequirements, methodId, bitSetObject);
//
    jvulkan::populateVkMemoryRequirements(
    		env,
			jVkMemoryRequirements,
			&vkMemoryRequirements);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling populateVkMemoryRequirements");
        return;
    }

    return;
}
