#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([BLcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_pushDataToVirtualMemory___3BLcom_CIMthetics_hwjvi_VulkanCore_VK11_Handles_MappedMemoryPointer_2
  (JNIEnv *env , jobject, jbyteArray jDataToCopyArray, jobject jVoidPointer)
{
    signed char *destinationMemoryHandle = (signed char *)hwjvi::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
        std::cerr << "jDataToCopyArray is nullptr" << std::endl;
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetByteArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
        return;
    }
}

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([FLcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_pushDataToVirtualMemory___3FLcom_CIMthetics_hwjvi_VulkanCore_VK11_Handles_MappedMemoryPointer_2
  (JNIEnv *env, jobject, jfloatArray jDataToCopyArray, jobject jVoidPointer)
{
    float *destinationMemoryHandle = (float *)hwjvi::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
        std::cerr << "jDataToCopyArray is nullptr" << std::endl;
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetFloatArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
        return;
    }
}

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    pushDataToVirtualMemory
 * Signature: ([ILcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/MappedMemoryPointer;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_pushDataToVirtualMemory___3ILcom_CIMthetics_hwjvi_VulkanCore_VK11_Handles_MappedMemoryPointer_2
  (JNIEnv *env, jobject, jintArray jDataToCopyArray, jobject jVoidPointer)
{
    int *destinationMemoryHandle = (int *)hwjvi::getHandleValue(env, jVoidPointer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (jDataToCopyArray == nullptr)
    {
        std::cerr << "jDataToCopyArray is nullptr" << std::endl;
        return;
    }

    jsize arrayLength = 0;
    arrayLength = env->GetArrayLength(jDataToCopyArray);

    env->GetIntArrayRegion(jDataToCopyArray, 0, arrayLength, destinationMemoryHandle);
    if (env->ExceptionOccurred())
    {
        return;
    }
}

