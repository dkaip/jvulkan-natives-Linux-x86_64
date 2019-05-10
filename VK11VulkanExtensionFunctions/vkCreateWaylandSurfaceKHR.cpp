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

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateWaylandSurfaceKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Structures/CreateInfos/VkWaylandSurfaceCreateInfoKHR;Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkCreateWaylandSurfaceKHR
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkWaylandSurfaceCreateInfoKHR, jobject jAlternateAllocator, jobject jVkSurfaceKHR)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)jvulkan::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        jvulkan::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    jclass javaClass = env->GetObjectClass(jVkWaylandSurfaceCreateInfoKHR);

    int sTypeValue = jvulkan::getSTypeAsInt(env, jVkWaylandSurfaceCreateInfoKHR);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    ////////////////////////////////////////////////////////////////////////
    jobject pNextObject = jvulkan::getpNext(env, jVkWaylandSurfaceCreateInfoKHR);
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
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    int32_t flags = jvulkan::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkWaylandSurfaceCreateFlagsKHR");

    methodId = env->GetMethodID(javaClass, "getWlDisplay", "()Lcom/CIMthetics/jvulkan/Wayland/Handles/WlDisplay;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlDisplayObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_display *wlDisplay = (struct wl_display *)jvulkan::getHandleValue(env, wlDisplayObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    methodId = env->GetMethodID(javaClass, "getWlSurface", "()Lcom/CIMthetics/jvulkan/Wayland/Handles/WlSurface;");
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlSurfaceObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_surface *wlSurface = (struct wl_surface *)jvulkan::getHandleValue(env, wlSurfaceObject);
    if (env->ExceptionOccurred())
    {
        return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
    }


    VkWaylandSurfaceCreateInfoKHR surfaceCreationInfo = {};
    surfaceCreationInfo.sType = (VkStructureType)sTypeValue;
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
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    return jvulkan::createVkResult(env, result);
}

