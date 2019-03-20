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

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkEnumeratePhysicalDevices
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkInstance;Ljava/util/Collection;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkEnumeratePhysicalDevices
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jDeviceHandleCollection)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)hwjvi::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

//    jclass vkInstanceClass = env->GetObjectClass(jVkInstance);
//    if (env->ExceptionOccurred())
//    {
//        return VK_RESULT_MAX_ENUM;
//    }
//
//    jmethodID methodId = env->GetMethodID(vkInstanceClass, "getHandle", "()J");
//    if (env->ExceptionOccurred())
//    {
//        return VK_RESULT_MAX_ENUM;
//    }
//
//    jlong instanceHandle = env->CallLongMethod(jVkInstance, methodId);
//    if (env->ExceptionOccurred())
//    {
//        return VK_RESULT_MAX_ENUM;
//    }
//
    uint32_t numberOfPhysicalDevices = 0;

    VkResult result = vkEnumeratePhysicalDevices(vkInstanceHandle, &numberOfPhysicalDevices, nullptr);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, result);
    }

    if (numberOfPhysicalDevices != 0)
    {
        std::vector<VkPhysicalDevice> deviceList(numberOfPhysicalDevices);

        VkResult result = vkEnumeratePhysicalDevices(vkInstanceHandle, &numberOfPhysicalDevices, deviceList.data());
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, result);
        }

        jclass javaClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkPhysicalDevice");
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jclass collectionClass = env->GetObjectClass(jDeviceHandleCollection);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (const auto& physicalDevice : deviceList)
        {
            jmethodID constructor = env->GetMethodID(javaClass, "<init>", "()V");
            if (env->ExceptionOccurred())
            {
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jobject newObject = env->NewObject(javaClass, constructor);
            if (env->ExceptionOccurred())
            {
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            hwjvi::setHandleValue(env, newObject, physicalDevice);

//            jmethodID methodId = env->GetMethodID(vkInstanceClass, "setHandle", "(J)V");
//            if (env->ExceptionOccurred())
//            {
//                return VK_RESULT_MAX_ENUM;
//            }
//
//            env->CallVoidMethod(newObject, methodId, physicalDevice);
//            if (env->ExceptionOccurred())
//            {
//                return VK_RESULT_MAX_ENUM;
//            }
//
            bool addResult = env->CallBooleanMethod(jDeviceHandleCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (addResult == false)
            {
                cout << "Error VkPhysicalDevice element did not get added." << endl;
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    return hwjvi::createVkResult(env, result);
}

