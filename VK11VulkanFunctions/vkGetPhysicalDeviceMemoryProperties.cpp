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
#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkGetPhysicalDeviceMemoryProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkPhysicalDevice;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceMemoryProperties;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkGetPhysicalDeviceMemoryProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jVkPhysicalDeviceMemoryPropertiesObject)
{
    VkPhysicalDevice_T *physicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkPhysicalDeviceMemoryProperties vkPhysicalDeviceMemoryProperties = {};
    vkGetPhysicalDeviceMemoryProperties(physicalDeviceHandle, &vkPhysicalDeviceMemoryProperties);

    jclass vkPhysicalDeviceMemoryPropertiesClass = env->GetObjectClass(jVkPhysicalDeviceMemoryPropertiesObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID memoryTypesMethodId = env->GetMethodID(vkPhysicalDeviceMemoryPropertiesClass, "getMemoryTypes", "()Ljava/util/Collection;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject jMemoryTypesCollectionObject = env->CallObjectMethod(jVkPhysicalDeviceMemoryPropertiesObject, memoryTypesMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID memoryHeapsMethodId = env->GetMethodID(vkPhysicalDeviceMemoryPropertiesClass, "getMemoryHeaps", "()Ljava/util/Collection;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject jMemoryHeapsCollectionObject = env->CallObjectMethod(jVkPhysicalDeviceMemoryPropertiesObject, memoryHeapsMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass memoryTypesCollectionClass = env->GetObjectClass(jMemoryTypesCollectionObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID addMethodId = env->GetMethodID(memoryTypesCollectionClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass vkMemoryTypeClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryType;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass vkMemoryHeapClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryHeap;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID typesConstructorMethodId = env->GetMethodID(vkMemoryTypeClass, "<init>", "(Ljava/util/EnumSet;I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID heapsConstructorMethodId = env->GetMethodID(vkMemoryHeapClass, "<init>", "(JLjava/util/EnumSet;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

//    std::cerr << "Gack0" << std::endl;
//    jmethodID constructorMethodId = env->GetMethodID(vkPhysicalDeviceMemoryPropertiesClass, "<init>", "(Ljava/util/EnumSet;I)Z");
//    if (env->ExceptionOccurred())
//    {
//        std::cerr << "Gack1" << std::endl;
//        return;
//    }
//    std::cerr << "Gack2" << std::endl;

    for (uint32_t i = 0; i < vkPhysicalDeviceMemoryProperties.memoryTypeCount; i++)
    {
        jobject jEnumSetObject = jvulkan::getVkMemoryPropertyFlagsAsEnumSet(env, vkPhysicalDeviceMemoryProperties.memoryTypes[i].propertyFlags);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkMemoryTypeObject = env->NewObject(
                vkMemoryTypeClass,
                typesConstructorMethodId,
                jEnumSetObject,
                vkPhysicalDeviceMemoryProperties.memoryTypes[i].heapIndex);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean addResult = env->CallBooleanMethod(jMemoryTypesCollectionObject, addMethodId, jVkMemoryTypeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        if (addResult == 0)
        {
            std::cerr << "Failed trying to add jMemoryTypesCollectionObject" << std::endl;
        }

    }

    for (uint32_t i = 0; i < vkPhysicalDeviceMemoryProperties.memoryHeapCount; i++)
    {
        jobject jEnumSetObject = jvulkan::getVkMemoryHeapFlagsAsEnumSet(env, vkPhysicalDeviceMemoryProperties.memoryHeaps[i].flags);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkMemoryHeapObject = env->NewObject(
                vkMemoryHeapClass,
                heapsConstructorMethodId,
                vkPhysicalDeviceMemoryProperties.memoryHeaps[i].size,
                jEnumSetObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean addResult = env->CallBooleanMethod(jMemoryHeapsCollectionObject, addMethodId, jVkMemoryHeapObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        if (addResult == 0)
        {
            std::cerr << "Failed trying to add jMemoryTypesCollectionObject" << std::endl;
        }

    }
//
//    std::cout << "memoryTypeCount=" << vkPhysicalDeviceMemoryProperties.memoryTypeCount << std::endl;
//    std::cout << "memoryHeapCount=" << vkPhysicalDeviceMemoryProperties.memoryHeapCount << std::endl;
}
