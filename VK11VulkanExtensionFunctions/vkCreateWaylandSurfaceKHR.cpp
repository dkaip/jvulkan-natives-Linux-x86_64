#include <iostream>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCreateWaylandSurfaceKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Structures/CreateInfos/VkWaylandSurfaceCreateInfoKHR;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCreateWaylandSurfaceKHR
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkWaylandSurfaceCreateInfoKHR, jobject jAlternateAllocator, jobject jVkSurfaceKHR)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)hwjvi::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    jclass javaClass = env->GetObjectClass(jVkWaylandSurfaceCreateInfoKHR);

    int sTypeValue = hwjvi::getSTypeAsInt(env, jVkWaylandSurfaceCreateInfoKHR);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(javaClass, "getpNext", "()J");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    void *pNext = (void *)env->CallLongMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);

    methodId = env->GetMethodID(javaClass, "getFlags", "()Ljava/util/EnumSet;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject flagsObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    int32_t flags = hwjvi::getEnumSetValue(
            env,
            flagsObject,
            "com/CIMthetics/hwjvi/VulkanExtensions/VK11/Enums/VkWaylandSurfaceCreateFlagsKHR");

    methodId = env->GetMethodID(javaClass, "getWlDisplay", "()Lcom/CIMthetics/hwjvi/Wayland/Handles/WlDisplay;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlDisplayObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_display *wlDisplay = (struct wl_display *)hwjvi::getHandleValue(env, wlDisplayObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    methodId = env->GetMethodID(javaClass, "getWlSurface", "()Lcom/CIMthetics/hwjvi/Wayland/Handles/WlSurface;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject wlSurfaceObject = env->CallObjectMethod(jVkWaylandSurfaceCreateInfoKHR, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    struct wl_surface *wlSurface = (struct wl_surface *)hwjvi::getHandleValue(env, wlSurfaceObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
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
        hwjvi::setHandleValue(env, jVkSurfaceKHR, surface);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;

    return hwjvi::createVkResult(env, result);
}

