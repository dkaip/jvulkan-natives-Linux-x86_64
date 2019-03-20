#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkDestroyInstance
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkInstance;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAllocationCallbacks;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkDestroyInstance
  (JNIEnv *env, jobject, jobject jVkInstance, jobject jAlternateAllocator)
{
    VkInstance_T *vkInstanceHandle = (VkInstance_T *)hwjvi::getHandleValue(env, jVkInstance);
    if (env->ExceptionOccurred())
    {
        return;
    }

//    jclass vkInstanceClass = env->GetObjectClass(jVkInstance);
//
//    jmethodID methodId = env->GetMethodID(vkInstanceClass, "getHandle", "()J");
//    jlong handle = env->CallLongMethod(jVkInstance, methodId);
//
    VkAllocationCallbacks *allocatorCallbacks = nullptr;
    if (jAlternateAllocator != nullptr)
    {
        allocatorCallbacks = new VkAllocationCallbacks();
        hwjvi::getAllocatorCallbacks(env, jAlternateAllocator, allocatorCallbacks);
    }

//    VkInstance vkInstance = (VkInstance)handle;
//
    vkDestroyInstance(vkInstanceHandle, allocatorCallbacks);

    // Free up the allocator callback structure if created.
    delete allocatorCallbacks;
    allocatorCallbacks = nullptr;
}

