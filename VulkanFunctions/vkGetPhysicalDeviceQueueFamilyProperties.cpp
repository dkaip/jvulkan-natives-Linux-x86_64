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
#include <iostream>
#include <vector>

using namespace std;

//#include <vulkan/vulkan.h>
//#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

static jobject getVkQueueFlagBits(JNIEnv *env, VkQueueFlags vkQueueFlagBits);


/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkGetPhysicalDeviceQueueFamilyProperties
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPhysicalDevice;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkGetPhysicalDeviceQueueFamilyProperties
  (JNIEnv *env, jobject, jobject jVkPhysicalDevice, jobject jQueueFamilyPropertiesCollection)
{
    VkPhysicalDevice_T *vkPhysicalDeviceHandle = (VkPhysicalDevice_T *)jvulkan::getHandleValue(env, jVkPhysicalDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    uint32_t numberOfQueueFamilyProperties = 0;

    vkGetPhysicalDeviceQueueFamilyProperties(
            vkPhysicalDeviceHandle,
            &numberOfQueueFamilyProperties,
            nullptr);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (numberOfQueueFamilyProperties != 0)
    {
        std::vector<VkQueueFamilyProperties> propertyList(numberOfQueueFamilyProperties);

        vkGetPhysicalDeviceQueueFamilyProperties(
                vkPhysicalDeviceHandle,
                &numberOfQueueFamilyProperties,
                propertyList.data());
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkQueueFamilyProperties");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass collectionClass = env->GetObjectClass(jQueueFamilyPropertiesCollection);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID constructor = env->GetMethodID(javaClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        for (const auto& queueFamily : propertyList)
        {
            jobject newObject = env->NewObject(javaClass, constructor);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ///////////////////////////////////////////////////////////////////////////

            jmethodID methodId = env->GetMethodID(javaClass, "setQueueFlags", "(Ljava/util/EnumSet;)V");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jobject vkQueueFlagBitsEnumSet = getVkQueueFlagBits(env, queueFamily.queueFlags);
            if (env->ExceptionOccurred())
            {
                return;
            }

            if (vkQueueFlagBitsEnumSet == nullptr)
            {
                return;
            }

            env->CallVoidMethod(newObject, methodId, vkQueueFlagBitsEnumSet);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ///////////////////////////////////////////////////////////////////////////

            methodId = env->GetMethodID(javaClass, "setQueueCount", "(I)V");
            if (env->ExceptionOccurred())
            {
                return;
            }

            env->CallVoidMethod(newObject, methodId, queueFamily.queueCount);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ///////////////////////////////////////////////////////////////////////////

            methodId = env->GetMethodID(javaClass, "setTimestampValidBits", "(I)V");
            if (env->ExceptionOccurred())
            {
                return;
            }

            env->CallVoidMethod(newObject, methodId, queueFamily.timestampValidBits);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ///////////////////////////////////////////////////////////////////////////

            jclass vkExtent3DClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jmethodID vkExtent3DConstructor = env->GetMethodID(vkExtent3DClass, "<init>", "(III)V");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jobject vkExtent3DObject = env->NewObject(vkExtent3DClass,
                    vkExtent3DConstructor,
                    queueFamily.minImageTransferGranularity.width,
                    queueFamily.minImageTransferGranularity.height,
                    queueFamily.minImageTransferGranularity.depth);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(javaClass, "setMinImageTransferGranularity", "(Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkExtent3D;)V");
            if (env->ExceptionOccurred())
            {
                return;
            }

            env->CallVoidMethod(newObject, methodId, vkExtent3DObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            env->CallVoidMethod(jQueueFamilyPropertiesCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

        }

    }
}

static jobject getVkQueueFlagBits(JNIEnv *env, VkQueueFlags vkQueueFlagBits)
{
    char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/Enums/VkQueueFlagBits";
    char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkQueueFlagBits;";
    /*
     * Create the EnumSet for the flags.
     */
    jclass enumSetClass = env->FindClass("java/util/EnumSet");
    if (env->ExceptionOccurred())
    {
        cout << "Error finding EnumSet class ... returning" << endl;
        return nullptr;
    }
//    cout << "Found EnumSet class" << endl;

    jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
    if (env->ExceptionOccurred() != 0)
    {
        cout << "Error getting noneOf ... returning" << endl;
        return nullptr;
    }

//    cout << "Got noneOfMethod" << endl;

    jclass enumClass = env->FindClass(enumClassString);

    jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
    if (env->ExceptionOccurred())
    {
        cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
        return nullptr;
    }

//    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;

    jclass setClass = env->FindClass("java/util/Set");
    jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
    if (env->ExceptionOccurred())
    {
        cout << "Error getting add method on EnumSet ... returning" << endl;
        return nullptr;
    }

    /*
     * Make sure that flags does not have an unexpected value.  This would
     * indicate that this code is out of sync with the LunarG Vulkan SDK.
     */
    if ((vkQueueFlagBits &
         !(VK_QUEUE_GRAPHICS_BIT |
           VK_QUEUE_COMPUTE_BIT |
           VK_QUEUE_TRANSFER_BIT |
           VK_QUEUE_SPARSE_BINDING_BIT |
           VK_QUEUE_PROTECTED_BIT)) != 0)
    {
        cout << "ERROR: Unhandled case for vkQueueFlagBits...value is " << vkQueueFlagBits << endl;
        return nullptr;
    }

    if (vkQueueFlagBits & VK_QUEUE_GRAPHICS_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_QUEUE_GRAPHICS_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_QUEUE_GRAPHICS_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkQueueFlagBits & VK_QUEUE_COMPUTE_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_QUEUE_COMPUTE_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_QUEUE_COMPUTE_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkQueueFlagBits & VK_QUEUE_TRANSFER_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_QUEUE_TRANSFER_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_QUEUE_TRANSFER_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkQueueFlagBits & VK_QUEUE_SPARSE_BINDING_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_QUEUE_SPARSE_BINDING_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_QUEUE_SPARSE_BINDING_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    if (vkQueueFlagBits & VK_QUEUE_PROTECTED_BIT)
    {
        jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_QUEUE_PROTECTED_BIT", enumObjectString);
        jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

        bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
            cout << "ERROR: could not add VK_QUEUE_PROTECTED_BIT to EnumSet" << endl;
            return nullptr;
        }
    }

    return enumSetObject;
}

