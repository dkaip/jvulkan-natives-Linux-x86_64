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
 * vkCreateDebugUtilsMessengerEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <iostream>
#include <atomic>
#include <vector>
#include <mutex>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "DebugUtilsMessengerCallbackListEntry.h"

using namespace jvulkan;

std::atomic<unsigned long long>g_vkCreateDebugUtilsMessengerList_UniqueNumber { 1 };
std::vector<jvulkan::DebugUtilsMessengerCallbackListEntry *>g_vkCreateDebugUtilsMessengerList;
std::mutex g_vkCreateDebugUtilsMessengerListMutex;

extern JavaVM *l_JavaVM;
extern std::mutex l_JavaVM_Mutex;

static VKAPI_ATTR VkBool32 VKAPI_CALL messengerCallback(
	    VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
	    VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
	    const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,
	    void*                                            userData)
{
    void *the1stKey = userData;
    jobject javaCallbackObject = nullptr;
    jobject javaUserData = nullptr;

    unsigned long int entryNumber = 0;
    bool foundIt = false;

    /*
     * Lock the debugCallbackList vector so that we may
     * work with it.
     */
    {
        std::lock_guard<std::mutex> lock(g_vkCreateDebugUtilsMessengerListMutex);

        for (; entryNumber < g_vkCreateDebugUtilsMessengerList.size(); entryNumber++)
        {
        	if (the1stKey == (void *)g_vkCreateDebugUtilsMessengerList[entryNumber]->getThe1stKey())
            {
                javaCallbackObject = g_vkCreateDebugUtilsMessengerList[entryNumber]->getObjectReference();
                javaUserData = g_vkCreateDebugUtilsMessengerList[entryNumber]->getJavaUserData();
                foundIt = true;
                break;
            }
        }
    }

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

    /*
     * Okay, we have found the exception information.  Now we need to use it in
     * order execute the callback in the java code.
     */
    jclass javaClass = localEnv->GetObjectClass(javaCallbackObject);
    if (localEnv->ExceptionOccurred())
    {
        cout << "Error getting callback object class ... returning" << endl;
        return false;
    }

    jobject jMessageSeverity = createVkDebugUtilsMessageSeverityFlagBitsEXT(
    		localEnv,
			messageSeverity);

    jobject jMessageTypesEnumSet = getVkDebugUtilsMessageTypeFlagsEXTAsEnumSet(
    		localEnv,
			messageTypes);

	jobject jVkDebugUtilsMessengerCallbackDataEXT = createVkDebugUtilsMessengerCallbackDataEXT(
			localEnv,
			pCallbackData);

    jmethodID methodId = localEnv->GetMethodID(javaClass, "invoke",
    		"(Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/VkDebugUtilsMessengerCallbackDataEXT;Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
        cout << "oops" << endl;
        return false;
    }

    jboolean result = localEnv->CallBooleanMethod(javaCallbackObject, methodId,
    		jMessageSeverity,
			jMessageTypesEnumSet,
			jVkDebugUtilsMessengerCallbackDataEXT,
            javaUserData);

    if (localEnv->ExceptionOccurred())
    {
        return false;
    }

    l_JavaVM->DetachCurrentThread();

    return (VkBool32)result;
}

static VkResult CreateDebugUtilsMessengerEXT(
        VkInstance instance,
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pMessenger)
{
    auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
    if (func != nullptr) {
        return func(instance, pCreateInfo, pAllocator, pMessenger);
    } else {
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateDebugUtilsMessengerEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkDebugUtilsMessengerCreateInfoEXT;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDebugUtilsMessengerEXT;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateDebugUtilsMessengerEXT
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDebugUtilsMessengerCreateInfoEXT, jobject jAlternateAllocator, jobject jVkDebugUtilsMessengerEXT)
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
				cout << "ERROR: Could not get a pointer to the JVM." << endl;
				// TODO need to throw an exception here.
				jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
			}
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

    VkDebugUtilsMessengerCreateInfoEXT vkDebugUtilsMessengerCreateInfoEXT = {};
    std::vector<void *> memoryToFree(5);

    jvulkan::getVkDebugUtilsMessengerCreateInfoEXT(env, jVkDebugUtilsMessengerCreateInfoEXT, &vkDebugUtilsMessengerCreateInfoEXT, &memoryToFree);
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass vkDebugUtilsMessengerCreateInfoEXTClass = env->GetObjectClass(jVkDebugUtilsMessengerCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getCallbackObject", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/VkDebugUtilsMessengerCallbackEXT;");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localCallbackObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalCallbackObject = reinterpret_cast<jobject>(env->NewGlobalRef(localCallbackObject));

    methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getUserData", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localUserData = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXT, methodId);

    // Need to get a global ref because this will be used later in a callback.
    jobject globalUserData = reinterpret_cast<jobject>(env->NewGlobalRef(localUserData));

    /*
     * put the info on the "list" and if the call fails take it off again.
     */
    unsigned long long key = g_vkCreateDebugUtilsMessengerList_UniqueNumber.fetch_add( 1, std::memory_order_relaxed);
    /*
     * Save a unique number in the user data so we can use that as a key in
     * order to look up the callback information we are going to need.
     */
    vkDebugUtilsMessengerCreateInfoEXT.pUserData = (void *)key;

    /*
     * Here we are assigning the callback to be the static function defined
     * above.  We will use the "key" created just above to save the actual
     * java callback object and the user data object supplied, if any.
     */
    vkDebugUtilsMessengerCreateInfoEXT.pfnUserCallback = messengerCallback;


    VkDebugUtilsMessengerEXT vkDebugUtilsMessengerEXT;


    VkResult result = CreateDebugUtilsMessengerEXT(
            vkInstanceHandle,
            &vkDebugUtilsMessengerCreateInfoEXT,
            allocatorCallbacks,
            &vkDebugUtilsMessengerEXT);

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
        jvulkan::DebugUtilsMessengerCallbackListEntry *callbackListEntry =
            new jvulkan::DebugUtilsMessengerCallbackListEntry(key, vkDebugUtilsMessengerEXT, globalCallbackObject, globalUserData);

        std::lock_guard<std::mutex> lock(g_vkCreateDebugUtilsMessengerListMutex);

        g_vkCreateDebugUtilsMessengerList.push_back(callbackListEntry);
    }

    /*
     * Now transfer the VkInstance data to Java
     */
    jvulkan::setHandleValue(env, jVkDebugUtilsMessengerEXT, vkDebugUtilsMessengerEXT);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
