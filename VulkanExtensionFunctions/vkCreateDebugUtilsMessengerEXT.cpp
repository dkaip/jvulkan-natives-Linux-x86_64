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
/*
 * vkCreateDebugUtilsMessengerEXT.cpp
 *
 *  Created on: Apr 21, 2019
 *      Author: Douglas Kaip
 */

#include <atomic>
#include <vector>
#include <mutex>
#include <stdbool.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "DebugUtilsMessengerCallbackListEntry.h"
#include "slf4j.hh"

using namespace jvulkan;

std::atomic<unsigned long long>g_vkCreateDebugUtilsMessengerList_UniqueNumber { 1 };
std::vector<jvulkan::DebugUtilsMessengerCallbackListEntry *>g_vkCreateDebugUtilsMessengerList;
std::mutex g_vkCreateDebugUtilsMessengerListMutex;

extern JavaVM *l_JavaVM;
extern std::mutex l_JavaVM_Mutex;

bool functionPointersInitialized = false;

PFN_vkCmdBeginDebugUtilsLabelEXT 	vkCmdBeginDebugUtilsLabelEXTFunc;
PFN_vkCmdEndDebugUtilsLabelEXT 		vkCmdEndDebugUtilsLabelEXTFunc;
PFN_vkCmdInsertDebugUtilsLabelEXT 	vkCmdInsertDebugUtilsLabelEXTFunc;
PFN_vkSetDebugUtilsObjectNameEXT 	vkSetDebugUtilsObjectNameEXTFunc;
PFN_vkSetDebugUtilsObjectTagEXT 	vkSetDebugUtilsObjectTagEXTFunc;

PFN_vkSubmitDebugUtilsMessageEXT	vkSubmitDebugUtilsMessageEXTFunc;
PFN_vkQueueBeginDebugUtilsLabelEXT	vkQueueBeginDebugUtilsLabelEXTFunc;
PFN_vkQueueEndDebugUtilsLabelEXT	vkQueueEndDebugUtilsLabelEXTFunc;
PFN_vkQueueInsertDebugUtilsLabelEXT	vkQueueInsertDebugUtilsLabelEXTFunc;

static PFN_vkCreateDebugUtilsMessengerEXT	vkCreateDebugUtilsMessengerEXTFunc;
PFN_vkDestroyDebugUtilsMessengerEXT	vkDestroyDebugUtilsMessengerEXTFunc;

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

    LOGWARN(localEnv, "%s", "A debug utils messenger callback has been triggered");
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
        LOGERROR(localEnv, "We were not able to find the stored callback information on the g_vkCreateDebugUtilsMessengerList for key:%lld", the1stKey);
        //TODO
        /*
         * We have a problem here...We cannot find the callback information
         * we need.
         */
        throw 99999;
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

    jobject jMessageTypesEnumSet = createVkDebugUtilsMessageTypeFlagsEXTAsEnumSet(
    		localEnv,
			messageTypes);

	jobject jVkDebugUtilsMessengerCallbackDataEXT = createVkDebugUtilsMessengerCallbackDataEXT(
			localEnv,
			pCallbackData);


    jmethodID methodId = localEnv->GetMethodID(javaClass, "invoke",
    		"(Lcom/CIMthetics/jvulkan/VulkanExtensions/Enums/VkDebugUtilsMessageSeverityFlagBitsEXT;Ljava/util/EnumSet;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/VkDebugUtilsMessengerCallbackDataEXT;Ljava/lang/Object;)Z");
    if (localEnv->ExceptionOccurred())
    {
    	LOGERROR(localEnv, "%s", "unable to find the invoke callback");
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

static void initFunctionPointers(VkInstance instance)
{
	/*
	 * Oh, this is ugliness of the first order...
	 *
	 * Basically, not all of the Vulkan function are statically available.
	 * The following two, functions should not be used
	 * unless a DebugUtilsMessenger is set up first...so we are getting
	 * their addresses here (since we have a VkInstance) so they will be
	 * available later when they may be needed.
	 */
	// TODO this may need some rework in the case where there are multiple VkInstances
	vkCmdBeginDebugUtilsLabelEXTFunc =
			(PFN_vkCmdBeginDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkCmdBeginDebugUtilsLabelEXT");
	vkCmdEndDebugUtilsLabelEXTFunc  =
			(PFN_vkCmdEndDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkCmdEndDebugUtilsLabelEXT");
	vkCmdInsertDebugUtilsLabelEXTFunc  =
			(PFN_vkCmdInsertDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkCmdInsertDebugUtilsLabelEXT");
	vkSetDebugUtilsObjectNameEXTFunc =
			(PFN_vkSetDebugUtilsObjectNameEXT)vkGetInstanceProcAddr(instance, "vkSetDebugUtilsObjectNameEXT");
	vkSetDebugUtilsObjectTagEXTFunc  =
			(PFN_vkSetDebugUtilsObjectTagEXT)vkGetInstanceProcAddr(instance, "vkSetDebugUtilsObjectTagEXT");

	vkSubmitDebugUtilsMessageEXTFunc =
			(PFN_vkSubmitDebugUtilsMessageEXT)vkGetInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT");
	vkQueueBeginDebugUtilsLabelEXTFunc =
			(PFN_vkQueueBeginDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkQueueBeginDebugUtilsLabelEXT");
	vkQueueEndDebugUtilsLabelEXTFunc =
			(PFN_vkQueueEndDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkQueueEndDebugUtilsLabelEXT");
	vkQueueInsertDebugUtilsLabelEXTFunc =
			(PFN_vkQueueInsertDebugUtilsLabelEXT)vkGetInstanceProcAddr(instance, "vkQueueInsertDebugUtilsLabelEXT");

	vkCreateDebugUtilsMessengerEXTFunc =
			(PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
	vkDestroyDebugUtilsMessengerEXTFunc =
			(PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
//	if (func != nullptr)
//    {
//        return func(instance, pCreateInfo, pAllocator, pMessenger);
//    }
//    else
//    {
//        return VK_ERROR_EXTENSION_NOT_PRESENT;
//    }
}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateDebugUtilsMessengerEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkDebugUtilsMessengerCreateInfoEXT;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDebugUtilsMessengerEXT;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateDebugUtilsMessengerEXT
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
				LOGERROR(env, "%s", "Could not get pointer to the JVM");
				// TODO need to throw an exception here.
				return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
			}
		}
    }

    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the value of jVkInstance");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
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
    	LOGERROR(env, "%s", "Failed on call to getVkDebugUtilsMessengerCreateInfoEXT");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass vkDebugUtilsMessengerCreateInfoEXTClass = env->GetObjectClass(jVkDebugUtilsMessengerCreateInfoEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the object class for jVkDebugUtilsMessengerCreateInfoEXT");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getCallbackObject", "()Lcom/CIMthetics/jvulkan/VulkanCore/VkDebugUtilsMessengerCallbackEXT;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the methodId for getCallbackObject");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localCallbackObject = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXT, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying CallObjectMethod for callback object");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    // Need to get a global ref because this will be used later in a callback.
    jobject globalCallbackObject = reinterpret_cast<jobject>(env->NewGlobalRef(localCallbackObject));

    methodId = env->GetMethodID(vkDebugUtilsMessengerCreateInfoEXTClass, "getUserData", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to get the methodId for getUserData");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject localUserData = env->CallObjectMethod(jVkDebugUtilsMessengerCreateInfoEXT, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying CallObjectMethod for userData object");
    	return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

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

    {
    	/*
    	 * Okay, this one is a little different that the other debug stuff.  In
    	 * this case, once the call is made to CreateDebugUtilsMessengerEXT
    	 * below one or more callbacks may immediately be triggered even before
    	 * the call completes.  If we don't have an entry on the g_vkCreateDebugUtilsMessengerList
    	 * we will have issues.  So, what are we going to do?
    	 *
    	 * We are going to add the entry now, even though we do not have the
    	 * assigned value for vkDebugUtilsMessengerEXT yet.  Since the value of
    	 * vkDebugUtilsMessengerEXT is only used by the vkDestroyDebugUtilsMessengerEXT
    	 * function we will replace the list entry with a corrected on once the
    	 * call to CreateDebugUtilsMessengerEXT returns successfully.
    	 */
		jvulkan::DebugUtilsMessengerCallbackListEntry *callbackListEntry =
			new jvulkan::DebugUtilsMessengerCallbackListEntry(key, globalCallbackObject, globalUserData);

		std::lock_guard<std::mutex> lock(g_vkCreateDebugUtilsMessengerListMutex);

		g_vkCreateDebugUtilsMessengerList.push_back(callbackListEntry);
    }

	if (functionPointersInitialized == false)
	{
		initFunctionPointers(vkInstanceHandle);
		functionPointersInitialized = true;
	}


    VkDebugUtilsMessengerEXT vkDebugUtilsMessengerEXT = nullptr;

    VkResult result = vkCreateDebugUtilsMessengerEXTFunc(
            vkInstanceHandle,
            &vkDebugUtilsMessengerCreateInfoEXT,
            allocatorCallbacks,
            &vkDebugUtilsMessengerEXT);

    if (result == VK_SUCCESS)
    {
    	/*
    	 * We are using a unique number as the first key and the value of the
    	 * returned VkDebugUtilsMessengerEXT handle as the second search key.
    	 * This is because we do not have the value of vkDebugUtilsMessengerEXT
    	 * until after the call to CreateDebugUtilsMessengerEXT.
    	 *
    	 * When a callback occurs we will look up the unique number that was
    	 * saved in the userData field in order to get information needed to
    	 * execute the callback.
    	 */
        std::lock_guard<std::mutex> lock(g_vkCreateDebugUtilsMessengerListMutex);

        bool foundIt = false;
        for (int entryNumber = 0; entryNumber < g_vkCreateDebugUtilsMessengerList.size(); entryNumber++)
        {
        	if (key == g_vkCreateDebugUtilsMessengerList[entryNumber]->getThe1stKey())
            {
        		/*
        		 * We found the entry we are looking for so we need to update
        		 * its 2ndKey value with the proper information.
        		 */
        		g_vkCreateDebugUtilsMessengerList[entryNumber]->setThe2ndKey(vkDebugUtilsMessengerEXT);
        		foundIt = true;
        		break;
            }
        }

        if (foundIt == false)
        {
        	LOGERROR(env, "We did not find the entry for key %lld on the g_vkCreateDebugUtilsMessengerList", key);
        }
    }
    else
    {
    	LOGERROR(env, "Failed calling CreateDebugUtilsMessengerEXT code is:%d", result);
    }

    /*
     * Now transfer the VkInstance data to Java
     */
    jvulkan::setHandleValue(env, jVkDebugUtilsMessengerEXT, vkDebugUtilsMessengerEXT);

    jvulkan::freeMemory(&memoryToFree);

    return jvulkan::createVkResult(env, result);
}
