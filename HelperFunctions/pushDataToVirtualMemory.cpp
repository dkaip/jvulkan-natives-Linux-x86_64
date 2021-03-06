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
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([BLcom/CIMthetics/jvulkan/VulkanCore/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_pushDataToVirtualMemory___3BLcom_CIMthetics_jvulkan_VulkanCore_Handles_MappedMemoryPointer_2
  (JNIEnv *env , jobject, jbyteArray jDataToCopyArray, jobject jVoidPointer)
{
    signed char *destinationMemoryHandle = (signed char *)jvulkan::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVoidPointer");
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
    	LOGERROR(env, "%s", "Push source data is null.");
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetByteArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetByteArrayRegion.");
        return;
    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([FLcom/CIMthetics/jvulkan/VulkanCore/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_pushDataToVirtualMemory___3FLcom_CIMthetics_jvulkan_VulkanCore_Handles_MappedMemoryPointer_2
  (JNIEnv *env, jobject, jfloatArray jDataToCopyArray, jobject jVoidPointer)
{
    float *destinationMemoryHandle = (float *)jvulkan::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVoidPointer");
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
    	LOGERROR(env, "%s", "Push source data is null.");
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetFloatArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetFloatArrayRegion.");
        return;
    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([ILcom/CIMthetics/jvulkan/VulkanCore/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_pushDataToVirtualMemory___3ILcom_CIMthetics_jvulkan_VulkanCore_Handles_MappedMemoryPointer_2
  (JNIEnv *env, jobject, jintArray jDataToCopyArray, jobject jVoidPointer)
{
    int *destinationMemoryHandle = (int *)jvulkan::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error trying to get jVoidPointer");
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
    	LOGERROR(env, "%s", "Push source data is null.");
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetIntArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetIntArrayRegion.");
        return;
    }
}

