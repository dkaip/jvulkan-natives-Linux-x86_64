#include <iostream>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"


/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkDestroySurfaceKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkDestroySurfaceKHR
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jVkSurfaceKHR, jobject jAlternateAllocator)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)hwjvi::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkSurfaceKHR_T *vkSurfaceKHRHandle = (VkSurfaceKHR_T *)hwjvi::getHandleValue(env, jVkSurfaceKHR);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

    vkDestroySurfaceKHR(vkInstanceHandle, vkSurfaceKHRHandle, allocatorCallbacks);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;
}

