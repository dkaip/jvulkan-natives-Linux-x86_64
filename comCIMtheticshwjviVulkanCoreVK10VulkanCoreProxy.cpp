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
 * comCIMtheticsjvulkanVulkanCoreVK10VulkanCoreProxy.cpp
 *
 *  Created on: Jul 12, 2018
 *      Author: Douglas Kaip
 */

#include <iostream>
#include <atomic>
#include <vector>
#include <mutex>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "DebugCallbackListEntry.h"

using namespace jvulkan;

std::atomic<unsigned long long>g_uniqueNumber { 1 };
std::vector<jvulkan::DebugCallbackListEntry *>g_debugCallbackList;
std::mutex g_debugCallbackListMutex;

JavaVM *g_JavaVM;

static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugReportFlagsEXT flags,
    VkDebugReportObjectTypeEXT objType,
    uint64_t obj,
    size_t location,
    int32_t code,
    const char* layerPrefix,
    const char* msg,
    void* userData)
{
    void *callbackReference = userData;
    jobject javaCallbackObject = nullptr;
    jobject javaUserData = nullptr;

    cout << "Callback called key is " <<  (jobject *)callbackReference << endl;

    unsigned long int entryNumber = 0;
    bool foundIt = false;
    /*
     * Lock the debugCallbackList vector so that we may
     * work with it.
     */
    {
        std::lock_guard<std::mutex> lock(g_debugCallbackListMutex);

        for (; entryNumber < g_debugCallbackList.size(); entryNumber++)
        {
            if (callbackReference == (void *)g_debugCallbackList[entryNumber]->getCallbackHandle())
            {
                javaCallbackObject = g_debugCallbackList[entryNumber]->getObjectReference();
                javaUserData = g_debugCallbackList[entryNumber]->getJavaUserData();
                foundIt = true;
                break;
            }
        }
    }

    cout << "Go data from list entry" << endl;
    if (foundIt == false)
    {
        //TODO
        /*
         * We have a problem here...We cannot find the callback information
         * we need.
         */
        throw 99999;
    }

    JNIEnv *localEnv;
    int envStatus = g_JavaVM->GetEnv((void **)&localEnv, JNI_VERSION_1_6);
    if (envStatus == JNI_EDETACHED)
    {
        if (g_JavaVM->AttachCurrentThread((void **)&localEnv, nullptr) != 0)
        {
            cout << "Failed to attach" << endl;
        }
    }
    else if (envStatus == JNI_OK)
    {
        ;
    }
    else if (envStatus == JNI_EVERSION)
    {
        cout << "JNI_VERSION_1_6 not supported." << endl;
        return (VkBool32)false;
    }

//    cout << "Fixed java env" << endl;

    /*
     * Okay, we have found the exception information.  Now we need to use it in
     * order execute the callback in the java code.
     */
    jstring layerPrefixString = localEnv->NewStringUTF(layerPrefix);
    jstring msgString         = localEnv->NewStringUTF(msg);

//    cout << "Layer Prefix String:" << layerPrefixString << endl;
//    cout << "Message:" << msgString << endl;
//
//    cout << "callback getting class " << javaCallbackObject << endl;
//
    jclass javaClass = localEnv->GetObjectClass(javaCallbackObject);
    if (localEnv->ExceptionOccurred())
    {
        cout << "Error getting callback object class ... returning" << endl;
        return false;
    }

    /*
     * Create the EnumSet for the flags.
     */
    jclass enumSetClass = localEnv->FindClass("java/util/EnumSet");
    if (localEnv->ExceptionOccurred())
    {
        cout << "Error finding EnumSet class ... returning" << endl;
        return false;
    }
//    cout << "Found EnumSet class" << endl;

    jmethodID enumSetNoneOfMethod = localEnv->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
    if (localEnv->ExceptionOccurred() != 0)
    {
        cout << "Error getting noneOf ... returning" << endl;
        return false;
    }

//    cout << "Got noneOfMethod" << endl;

    jclass enumClass = localEnv->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT");

    jobject enumSetObject = localEnv->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
    if (localEnv->ExceptionOccurred())
    {
        cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
        return false;
    }

//    cout << "Made the empty EnumSet flags is " << flags << endl;

    jclass setClass = localEnv->FindClass("java/util/Set");
    jmethodID setAddMethod = localEnv->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
        cout << "Error getting add method on EnumSet ... returning" << endl;
        return false;
    }

    /*
     * Make sure that flags does not have an unexpected value.  This would
     * indicate that this code is out of sync with the LunarG Vulkan SDK.
     */
    if ((flags &
         !(VK_DEBUG_REPORT_INFORMATION_BIT_EXT |
          VK_DEBUG_REPORT_WARNING_BIT_EXT |
          VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT |
          VK_DEBUG_REPORT_ERROR_BIT_EXT |
          VK_DEBUG_REPORT_DEBUG_BIT_EXT)) != 0)
    {
        cout << "ERROR: Unhandled case for flags...value is " << flags << endl;
        return false;
    }

    if (flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_INFORMATION_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        cout << "The add result was " << addResult << endl;
    }

    if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_WARNING_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        cout << "The add result was " << addResult << endl;
    }

    if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        cout << "The add result was " << addResult << endl;
    }

    if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_ERROR_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        cout << "The add result was Z" << addResult << endl;
    }

    if (flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_DEBUG_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        cout << "The add result was " << addResult << endl;
    }

    cout << "callback got add method" << endl;
    jmethodID methodId = localEnv->GetMethodID(javaClass, "invoke", "(Ljava/util/EnumSet;IJJILjava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
        cout << "oops" << endl;
        return false;
    }

    jboolean result = localEnv->CallBooleanMethod(javaCallbackObject, methodId,
            enumSetObject,
            objType,
            obj,
            location,
            code,
            layerPrefixString,
            msgString,
            javaUserData);

    if (localEnv->ExceptionOccurred())
    {
        return false;
    }

    localEnv->DeleteLocalRef(layerPrefixString);
    localEnv->DeleteLocalRef(msgString);

    g_JavaVM->DetachCurrentThread();

    return (VkBool32)result;
}

VkResult CreateDebugReportCallbackEXT(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pDebugReportCallbackCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugReportCallbackEXT* pCallback)
{
//    cout << "pCallback is " << pCallback << endl;
    auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
    if (func != nullptr) {
        return func(instance, pDebugReportCallbackCreateInfo, pAllocator, pCallback);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateDebugReportCallbackEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkDebugReportCallbackCreateInfoEXT;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDebugReportCallbackEXT;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateDebugReportCallbackEXT
(JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDebugReportCallbackCreateInfoEXT, jobject jAlternateAllocator, jobject jVkDebugReportCallbackEXT)
{
    if (g_JavaVM == nullptr)
    {
        jint returnValue = env->GetJavaVM(&g_JavaVM);
        if (returnValue < 0)
        {
            cout << "ERROR: Could not get a pointer to the JVM." << endl;
            // TODO need to throw an exception here.
            jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

//    VkInstance vkInstance = (VkInstance)instanceHandle;

//    cout << "createdebugcallback vkinstance is " << vkInstance << endl;

    jclass vkDebugReportCallbackCreateInfoEXTClass = env->GetObjectClass(jVkDebugReportCallbackCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int sTypeValue = getSTypeAsInt(env, jVkDebugReportCallbackCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

//    cout << "Got getSTypeAsInt" << endl;

    jmethodID methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    void *pNext = (void *)env->CallLongMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

//    cout << "Got pNext" << endl;

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);
    int32_t flags = getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT");

//    cout << "Got getFlagsAsInt" << endl;

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getCallbackObject", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/VkDebugReportCallback;");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localCallbackObject = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalCallbackObject = reinterpret_cast<jobject>(env->NewGlobalRef(localCallbackObject));

//    cout << "Got callback object " << globalCallbackObject << endl;

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getUserData", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localUserData = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalUserData = reinterpret_cast<jobject>(env->NewGlobalRef(localUserData));

//    cout << "Got user data object" << endl;


    VkDebugReportCallbackCreateInfoEXT debugReportCallbackCreateInfoEXT = {};
    debugReportCallbackCreateInfoEXT.sType = (VkStructureType)sTypeValue;
    debugReportCallbackCreateInfoEXT.flags = flags;
    debugReportCallbackCreateInfoEXT.pNext = pNext;


    /*
     * put the info on the "list" and if the call fails take it off again.
     */
    unsigned long long key = g_uniqueNumber.fetch_add( 1, std::memory_order_relaxed);

    // FIXME This is probably only okay if the pointers are 64-bit
    debugReportCallbackCreateInfoEXT.pUserData = (void *)key;

    /*
     * Here we are assigning the callback to be the static function defined
     * above.  We will use the "key" created just above to save the actual
     * java callback object and the user data object supplied, if any.
     */
    debugReportCallbackCreateInfoEXT.pfnCallback = debugCallback;

    VkDebugReportCallbackEXT vkDebugReportCallbackEXT;


    VkResult result = CreateDebugReportCallbackEXT(
            vkInstanceHandle,
            &debugReportCallbackCreateInfoEXT,
            allocatorCallbacks,
            &vkDebugReportCallbackEXT);

    if (result == VK_SUCCESS)
    {
//        cout << "Created debug callback handle is " << vkDebugReportCallbackEXT << endl;
        jvulkan::DebugCallbackListEntry *callbackListEntry =
            new jvulkan::DebugCallbackListEntry((void *)key, globalCallbackObject, globalUserData, vkDebugReportCallbackEXT);

        std::lock_guard<std::mutex> lock(g_debugCallbackListMutex);

        g_debugCallbackList.push_back(callbackListEntry);
    }

//    cout << "*pCallback is " << vkDebugReportCallbackEXT << endl;

    /*
     * Now transfer the VkInstance data to Java
     */
    jvulkan::setHandleValue(env, jVkDebugReportCallbackEXT, vkDebugReportCallbackEXT);
//    jclass javaClass = env->GetObjectClass(jVkDebugReportCallbackEXT);
//    methodId = env->GetMethodID(javaClass, "setHandle", "(J)V");
//    env->CallVoidMethod(jVkDebugReportCallbackEXT, methodId, vkDebugReportCallbackEXT);
//
//    cout << "Debug callback handle " << vkDebugReportCallbackEXT << endl;

    return jvulkan::createVkResult(env, result);
}

void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator)
{
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr)
    {
        func(instance, callback, pAllocator);
    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkDestroyDebugReportCallbackEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkDebugReportCallbackEXT;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkDestroyDebugReportCallbackEXT
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDebugReportCallbackEXT, jobject jAlternateAllocator)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkDebugReportCallbackEXT_T *vkDebugReportCallbackEXTHandle = (VkDebugReportCallbackEXT_T *)jvulkan::getHandleValue(env, jVkDebugReportCallbackEXT);
    if (env->ExceptionOccurred())
    {
        return;
    }

    DestroyDebugReportCallbackEXT(vkInstanceHandle, vkDebugReportCallbackEXTHandle, allocatorCallbacks);
    if (env->ExceptionOccurred())
    {
        cout << "vkDestroyDebugReportCallbackEXT exception" << endl;
        return;
    }
}

