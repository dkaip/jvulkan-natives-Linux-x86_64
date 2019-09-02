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
 * vkDestroyDebugReportCallbackEXT.cpp
 *
 *  Created on: Apr 17, 2019
 *      Author: Douglas Kaip
 */

#include <vector>
#include <mutex>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "DebugReportCallbackListEntry.h"
#include "slf4j.hh"

using namespace jvulkan;

extern std::vector<jvulkan::DebugReportCallbackListEntry *>g_vkDebugReportCallbackList;
extern std::mutex g_vkDebugReportCallbackListMutex;

static void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT handle, const VkAllocationCallbacks* pAllocator)
{
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr)
    {
        func(instance, handle, pAllocator);
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
    	LOGERROR(env, "%s", "Error retrieving vkInstanceHandle");
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
    	LOGERROR(env, "%s", "Error retrieving vkDebugReportCallbackEXTHandle");
        return;
    }

    /*
     * Lock the debugCallbackList vector so that we may
     * work with it.
     */
    {
        std::lock_guard<std::mutex> lock(g_vkDebugReportCallbackListMutex);

        for (int entryNumber = 0; entryNumber < g_vkDebugReportCallbackList.size(); entryNumber++)
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
        	if (vkDebugReportCallbackEXTHandle == g_vkDebugReportCallbackList[entryNumber]->getThe2ndKey())
            {
            	/*
            	 * We found the entry we need to deal with.
            	 */
                jobject javaCallbackObject = g_vkDebugReportCallbackList[entryNumber]->getObjectReference();
                jobject javaUserData = g_vkDebugReportCallbackList[entryNumber]->getJavaUserData();

                /*
                 * We need to delete the global references.  This will allow
                 * Java to move the objects around or possibly garbage collect
                 * them.
                 */
                env->DeleteGlobalRef(javaCallbackObject);
                env->DeleteGlobalRef(javaUserData);

                // Delete the entry for this vkDebugReportCallbackEXTHandle
                g_vkDebugReportCallbackList.erase(g_vkDebugReportCallbackList.begin() + entryNumber);
                break;
            }
        }
    }

    DestroyDebugReportCallbackEXT(vkInstanceHandle, vkDebugReportCallbackEXTHandle, allocatorCallbacks);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling DestroyDebugReportCallbackEXT");
        return;
    }
}

