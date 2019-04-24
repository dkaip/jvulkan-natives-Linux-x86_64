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

#include <atomic>
#include <vector>
#include <mutex>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "DebugReportCallbackListEntry.h"
#include "slf4j.hh"

using namespace jvulkan;

std::atomic<unsigned long long>g_vkDebugReportCallbackList_UniqueNumber { 1 };
std::vector<jvulkan::DebugReportCallbackListEntry *>g_vkDebugReportCallbackList;
std::mutex g_vkDebugReportCallbackListMutex;

JavaVM *l_JavaVM;
std::mutex l_JavaVM_Mutex;

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
    void *the1stKey = userData;
    jobject javaCallbackObject = nullptr;
    jobject javaUserData = nullptr;

    unsigned long int entryNumber = 0;
    bool foundIt = false;

    JNIEnv *localEnv;
    int envStatus = l_JavaVM->GetEnv((void **)&localEnv, JNI_VERSION_1_6);
    if (envStatus == JNI_EDETACHED)
    {
        if (l_JavaVM->AttachCurrentThread((void **)&localEnv, nullptr) != 0)
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

    LOGWARN(localEnv, "%s", "A debug callback has been triggered");
    /*
     * Lock the debugCallbackList vector so that we may
     * work with it.
     */
    {
        std::lock_guard<std::mutex> lock(g_vkDebugReportCallbackListMutex);

        for (; entryNumber < g_vkDebugReportCallbackList.size(); entryNumber++)
        {
        	if (the1stKey == (void *)g_vkDebugReportCallbackList[entryNumber]->getThe1stKey())
            {
                javaCallbackObject = g_vkDebugReportCallbackList[entryNumber]->getObjectReference();
                javaUserData = g_vkDebugReportCallbackList[entryNumber]->getJavaUserData();
                foundIt = true;
                break;
            }
        }
    }

    if (foundIt == false)
    {
        LOGERROR(localEnv, "%s", "We were not able to find the stored callback information on the g_vkDebugReportCallbackList");

        //TODO
        /*
         * We have a problem here...We cannot find the callback information
         * we need.
         */
        return false;
    }

    /*
     * Okay, we have found the exception information.  Now we need to use it in
     * order execute the callback in the java code.
     */
    jstring layerPrefixString = localEnv->NewStringUTF(layerPrefix);
    jstring msgString         = localEnv->NewStringUTF(msg);

    jclass javaClass = localEnv->GetObjectClass(javaCallbackObject);
    if (localEnv->ExceptionOccurred())
    {
        LOGERROR(localEnv, "%s", "Could not get the class for the callback object");
        return false;
    }

    /*
     * Create the EnumSet for the flags.
     */
    jclass enumSetClass = localEnv->FindClass("java/util/EnumSet");
    if (localEnv->ExceptionOccurred())
    {
        LOGERROR(localEnv, "%s", "Could not find the class java/util/EnumSet");
        return false;
    }

    jmethodID enumSetNoneOfMethod = localEnv->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
    if (localEnv->ExceptionOccurred() != 0)
    {
        LOGERROR(localEnv, "%s", "Could not find the static methodId for noneOf");
        return false;
    }

    jclass enumClass = localEnv->FindClass("com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT");

    jobject enumSetObject = localEnv->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
    if (localEnv->ExceptionOccurred())
    {
        LOGERROR(localEnv, "%s", "Failed calling CallStaticObjectMethod on EnumSet object");
        cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
        return false;
    }

    jclass setClass = localEnv->FindClass("java/util/Set");
    jmethodID setAddMethod = localEnv->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
        LOGERROR(localEnv, "%s", "Could not find the methodId for add for the EnumSet");
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
        LOGERROR(localEnv, "Unhandled case for flags %d", flags);
        return false;
    }

    if (flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_INFORMATION_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
        	LOGWARN(localEnv, "%s", "Failed to add VK_DEBUG_REPORT_INFORMATION_BIT_EXT to EnumSet");
        }
    }

    if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_WARNING_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
        	LOGWARN(localEnv, "%s", "Failed to add VK_DEBUG_REPORT_WARNING_BIT_EXT to EnumSet");
        }
    }

    if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
        	LOGWARN(localEnv, "%s", "Failed to add VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT to EnumSet");
        }
    }

    if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_ERROR_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
        	LOGWARN(localEnv, "%s", "Failed to add VK_DEBUG_REPORT_ERROR_BIT_EXT to EnumSet");
        }
    }

    if (flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT)
    {
        jfieldID fieldId = localEnv->GetStaticFieldID(enumClass, "VK_DEBUG_REPORT_DEBUG_BIT_EXT", "Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT;");
        jobject theEnum = localEnv->GetStaticObjectField(enumClass, fieldId);

        bool addResult = localEnv->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
        if (addResult == false)
        {
        	LOGWARN(localEnv, "%s", "Failed to add VK_DEBUG_REPORT_DEBUG_BIT_EXT to EnumSet");
        }
    }

    jmethodID methodId = localEnv->GetMethodID(javaClass, "invoke", "(Ljava/util/EnumSet;IJJILjava/lang/String;Ljava/lang/String;Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
        LOGERROR(localEnv, "%s", "Could not find the methodId for invoke");
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

    l_JavaVM->DetachCurrentThread();

    return (VkBool32)result;
}

static VkResult CreateDebugReportCallbackEXT(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pDebugReportCallbackCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugReportCallbackEXT* pCallback)
{
    auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
    if (func != nullptr)
    {
        return func(instance, pDebugReportCallbackCreateInfo, pAllocator, pCallback);
    }
    else
    {
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
    {
    	/*
    	 * Lock the Mutex for the l_JavaVM variable.  It should only be
    	 * needed here since once set the variable should not change
    	 * for the duration of the program's execution.
    	 */
        std::lock_guard<std::mutex> lock(l_JavaVM_Mutex);
		if (l_JavaVM == nullptr)
		{
			jint returnValue = env->GetJavaVM(&l_JavaVM);
			if (returnValue < 0)
			{
				LOGERROR(env, "%s", "Could not get pointer to the JVM");
				// TODO need to throw an exception here.
				jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
			}
		}
    }

    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the value of jVkInstance");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    jclass vkDebugReportCallbackCreateInfoEXTClass = env->GetObjectClass(jVkDebugReportCallbackCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the object class for jVkDebugReportCallbackCreateInfoEXT");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int sTypeValue = getSTypeAsInt(env, jVkDebugReportCallbackCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get getSTypeAsInt");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        LOGERROR(env, "%s", "Could not find the methodId for getpNext");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    void *pNext = (void *)env->CallLongMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        LOGERROR(env, "%s", "Could not find the methodId for getFlags");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);
    VkDebugReportFlagsEXT flags = getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugReportFlagBitsEXT");

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getCallbackObject", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/VkDebugReportCallback;");
    if (env->ExceptionOccurred())
    {
        LOGERROR(env, "%s", "Could not find the methodId for getCallbackObject");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localCallbackObject = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalCallbackObject = reinterpret_cast<jobject>(env->NewGlobalRef(localCallbackObject));

    methodId = env->GetMethodID(vkDebugReportCallbackCreateInfoEXTClass, "getUserData", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        LOGERROR(env, "%s", "Could not find the methodId for getUserData");
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localUserData = env->CallObjectMethod(jVkDebugReportCallbackCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalUserData = reinterpret_cast<jobject>(env->NewGlobalRef(localUserData));

    VkDebugReportCallbackCreateInfoEXT debugReportCallbackCreateInfoEXT = {};
    debugReportCallbackCreateInfoEXT.sType = (VkStructureType)sTypeValue;
    debugReportCallbackCreateInfoEXT.flags = flags;
    debugReportCallbackCreateInfoEXT.pNext = pNext;


    /*
     * put the info on the "list" and if the call fails take it off again.
     */
    unsigned long long key = g_vkDebugReportCallbackList_UniqueNumber.fetch_add( 1, std::memory_order_relaxed);
    /*
     * Save a unique number in the user data so we can use that as a key in
     * order to look up the callback information we are going to need.
     */
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
    	/*
    	 * We are using a unique number as the first key and the value of the
    	 * returned vkDebugReportCallbackEXT handle as the second search key.
    	 * This is because we do not have the value of vkDebugReportCallbackEXT
    	 * until after the call to CreateDebugReportCallbackEXT.
    	 *
    	 * When a callback occurs we will look up the unique number that was
    	 * saved in the userData field in order to get information needed to
    	 * execute the callback.
    	 */

    	// FIXME This is probably only okay if the pointers are 64-bit
        jvulkan::DebugReportCallbackListEntry *callbackListEntry =
            new jvulkan::DebugReportCallbackListEntry(key, vkDebugReportCallbackEXT, globalCallbackObject, globalUserData);

        std::lock_guard<std::mutex> lock(g_vkDebugReportCallbackListMutex);

        g_vkDebugReportCallbackList.push_back(callbackListEntry);
//        LOGDEBUG(env, "Put callback information on g_vkDebugReportCallbackList current size is %d, key is %ld", g_vkDebugReportCallbackList.size(), key);
    }

    /*
     * Now transfer the VkInstance data to Java
     */
    jvulkan::setHandleValue(env, jVkDebugReportCallbackEXT, vkDebugReportCallbackEXT);

    return jvulkan::createVkResult(env, result);
}
