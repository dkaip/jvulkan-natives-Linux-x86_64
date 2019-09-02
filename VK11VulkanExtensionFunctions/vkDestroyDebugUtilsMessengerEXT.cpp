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
 * vkDestroyDebugUtilsMessengerEXT.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include <vector>
#include <mutex>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "DebugUtilsMessengerCallbackListEntry.h"
#include "slf4j.hh"

using namespace jvulkan;

extern std::vector<jvulkan::DebugUtilsMessengerCallbackListEntry *>g_vkCreateDebugUtilsMessengerList;
extern std::mutex g_vkCreateDebugUtilsMessengerListMutex;

extern PFN_vkDestroyDebugUtilsMessengerEXT	vkDestroyDebugUtilsMessengerEXTFunc;


//static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT handle, const VkAllocationCallbacks* pAllocator)
//{
//    auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
//    if (func != nullptr)
//    {
//        func(instance, handle, pAllocator);
//    }
//}

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkDestroyDebugUtilsMessengerEXT
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkDebugUtilsMessengerEXT;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkDestroyDebugUtilsMessengerEXT
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkDebugUtilsMessengerEXT, jobject jAlternateAllocator)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error retrieving vkInstanceHandle");
        return;
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    VkDebugUtilsMessengerEXT_T *vkDebugUtilsMessengerEXTHandle = (VkDebugUtilsMessengerEXT_T *)jvulkan::getHandleValue(env, jVkDebugUtilsMessengerEXT);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error retrieving vkDebugUtilsMessengerEXTHandle");
        return;
    }

    /*
     * Lock the debugCallbackList vector so that we may
     * work with it.
     */
    {
        std::lock_guard<std::mutex> lock(g_vkCreateDebugUtilsMessengerListMutex);

        for (int entryNumber = 0; entryNumber < g_vkCreateDebugUtilsMessengerList.size(); entryNumber++)
        {
        	/*
        	 * We now need to remove the entry in the g_vkDebugReportCallbackList
        	 * that is no longer needed.  In this case we do no have access to
        	 * the first key that is used in vkCreateDebugReportCallbackEXT,
        	 * however, we do have access to the vkDebugReportCallbackEXTHandle.
        	 * Since we save that as well when the callback was created we
        	 * can use it to find the appropriate recode in the
        	 * g_vkDebugReportCallbackList and perform the needed processing
        	 * on it.
        	 */
        	if (vkDebugUtilsMessengerEXTHandle == g_vkCreateDebugUtilsMessengerList[entryNumber]->getThe2ndKey())
            {
            	/*
            	 * We found the entry we need to deal with.
            	 */
                jobject javaCallbackObject = g_vkCreateDebugUtilsMessengerList[entryNumber]->getObjectReference();
                jobject javaUserData = g_vkCreateDebugUtilsMessengerList[entryNumber]->getJavaUserData();

                /*
                 * We need to delete the global references.  This will allow
                 * Java to move the objects around or possibly garbage collect
                 * them.
                 */
                env->DeleteGlobalRef(javaCallbackObject);
                env->DeleteGlobalRef(javaUserData);

                // Delete the entry for this vkDebugReportCallbackEXTHandle
                g_vkCreateDebugUtilsMessengerList.erase(g_vkCreateDebugUtilsMessengerList.begin() + entryNumber);
                break;
            }
        }
    }

    vkDestroyDebugUtilsMessengerEXTFunc(vkInstanceHandle, vkDebugUtilsMessengerEXTHandle, allocatorCallbacks);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error while calling DestroyDebugUtilsMessengerEXT");
        return;
    }
}
