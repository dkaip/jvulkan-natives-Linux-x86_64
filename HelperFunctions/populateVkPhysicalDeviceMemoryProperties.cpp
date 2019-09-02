/*
 * populateVkPhysicalDeviceMemoryProperties.cpp
 *
 *  Created on: Aug 30, 2019
 *      Author: Douglas Kaip
 */


#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void populateVkPhysicalDeviceMemoryProperties(
			JNIEnv *env,
			jobject jVkPhysicalDeviceMemoryPropertiesObject,
			VkPhysicalDeviceMemoryProperties const *vkPhysicalDeviceMemoryProperties)
	{
        // Locate the VkPhysicalDeviceMemoryProperties class
        jclass theClass = env->GetObjectClass(jVkPhysicalDeviceMemoryPropertiesObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkPhysicalDeviceMemoryProperties");
            return;
        }

        jmethodID memoryTypesMethodId = env->GetMethodID(theClass, "getMemoryTypes", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMemoryTypes");
            return;
        }

        jobject jMemoryTypesCollectionObject = env->CallObjectMethod(jVkPhysicalDeviceMemoryPropertiesObject, memoryTypesMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Wrror calling CallObjectMethod");
            return;
        }

        jmethodID memoryHeapsMethodId = env->GetMethodID(theClass, "getMemoryHeaps", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getMemoryHeaps");
            return;
        }

        jobject jMemoryHeapsCollectionObject = env->CallObjectMethod(jVkPhysicalDeviceMemoryPropertiesObject, memoryHeapsMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Wrror calling CallObjectMethod");
            return;
        }

        jclass memoryTypesCollectionClass = env->GetObjectClass(jMemoryTypesCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Wrror calling GetObjectClass");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(memoryTypesCollectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            return;
        }

        jclass vkMemoryTypeClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryType;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryType");
            return;
        }

        jclass vkMemoryHeapClass = env->FindClass("Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryHeap;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkMemoryHeap");
            return;
        }

        jmethodID typesConstructorMethodId = env->GetMethodID(vkMemoryTypeClass, "<init>", "(Ljava/util/EnumSet;I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        jmethodID heapsConstructorMethodId = env->GetMethodID(vkMemoryHeapClass, "<init>", "(JLjava/util/EnumSet;)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            return;
        }

        for (uint32_t i = 0; i < vkPhysicalDeviceMemoryProperties->memoryTypeCount; i++)
        {
            jobject jEnumSetObject = jvulkan::createVkMemoryPropertyFlagsAsEnumSet(env, vkPhysicalDeviceMemoryProperties->memoryTypes[i].propertyFlags);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::createVkMemoryPropertyFlagsAsEnumSet.");
                return;
            }

            jobject jVkMemoryTypeObject = env->NewObject(
                    vkMemoryTypeClass,
                    typesConstructorMethodId,
                    jEnumSetObject,
                    vkPhysicalDeviceMemoryProperties->memoryTypes[i].heapIndex);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling constructor for VkMemoryType object.");
                return;
            }

            jboolean addResult = env->CallBooleanMethod(jMemoryTypesCollectionObject, addMethodId, jVkMemoryTypeObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Wrror calling CallBooleanMethod");
                return;
            }

            if (addResult == 0)
            {
            	LOGERROR(env, "%s", "Failed trying to add jMemoryTypesCollectionObject");
            }
        }

        for (uint32_t i = 0; i < vkPhysicalDeviceMemoryProperties->memoryHeapCount; i++)
        {
            jobject jEnumSetObject = jvulkan::createVkMemoryHeapFlagsAsEnumSet(env, vkPhysicalDeviceMemoryProperties->memoryHeaps[i].flags);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling jvulkan::createVkMemoryHeapFlagsAsEnumSet.");
                return;
            }

            jobject jVkMemoryHeapObject = env->NewObject(
                    vkMemoryHeapClass,
                    heapsConstructorMethodId,
                    vkPhysicalDeviceMemoryProperties->memoryHeaps[i].size,
                    jEnumSetObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling constructor for VkMemoryHeap object.");
                return;
            }

            jboolean addResult = env->CallBooleanMethod(jMemoryHeapsCollectionObject, addMethodId, jVkMemoryHeapObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Wrror calling CallBooleanMethod");
                return;
            }

            if (addResult == 0)
            {
            	LOGERROR(env, "%s", "Failed trying to add jMemoryTypesCollectionObject");
            }

        }
	}
}
