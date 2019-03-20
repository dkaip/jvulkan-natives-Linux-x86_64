#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkQueueWaitIdle
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkQueue;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkQueueWaitIdle
  (JNIEnv *env, jobject, jobject jVkQueue)
{
    VkQueue_T *vkQueueHandle = (VkQueue_T *)hwjvi::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkQueueWaitIdle(vkQueueHandle);

    return hwjvi::createVkResult(env, result);
}

