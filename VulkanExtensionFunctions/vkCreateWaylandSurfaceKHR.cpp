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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCreateWaylandSurfaceKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/Structures/CreateInfos/VkWaylandSurfaceCreateInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/VkSurfaceKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCreateWaylandSurfaceKHR
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkWaylandSurfaceCreateInfoKHR, jobject jAlternateAllocator, jobject jVkSurfaceKHR)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getHandleValue failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getAllocatorCallbacks failed.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    jclass javaClass = env->GetObjectClass(jVkWaylandSurfaceCreateInfoKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to GetObjectClass failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkStructureType sTypeValue = jvulkan::getSType(env, jVkWaylandSurfaceCreateInfoKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getSTypeAsInt failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jobject pNextObject = jvulkan::getpNextObject(env, jVkWaylandSurfaceCreateInfoKHR);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getpNext failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (pNextObject != nullptr)
    {
    	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    void *pNext = nullptr;

    jmethodID methodId = env->GetMethodID(javaClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for getFlags.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int32_t flags = jvulkan::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanExtensions/Enums/VkWaylandSurfaceCreateFlagsKHR");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getEnumSetValue failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    methodId = env->GetMethodID(javaClass, "getWlDisplay", "()Lcom/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for getWlDisplay.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlDisplayObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_display *wlDisplay = (struct wl_display *)jvulkan::getHandleValue(env, wlDisplayObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getHandleValue failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    methodId = env->GetMethodID(javaClass, "getWlSurface", "()Lcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not find method id for getWlSurface.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlSurfaceObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to CallObjectMethod failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_surface *wlSurface = (struct wl_surface *)jvulkan::getHandleValue(env, wlSurfaceObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Call to getHandleValue failed.");
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    VkWaylandSurfaceCreateInfoKHR surfaceCreationInfo = {};
    surfaceCreationInfo.sType = sTypeValue;
    surfaceCreationInfo.pNext = pNext;
    surfaceCreationInfo.flags = flags;
    surfaceCreationInfo.display = wlDisplay;
    surfaceCreationInfo.surface = wlSurface;

    VkSurfaceKHR surface;

    int result = vkCreateWaylandSurfaceKHR(vkInstanceHandle, &surfaceCreationInfo, allocatorCallbacks, &surface);
    if (result == VK_SUCCESS)
    {
        jvulkan::setHandleValue(env, jVkSurfaceKHR, surface);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to setHandleValue failed.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    return jvulkan::createVkResult(env, result);
}

