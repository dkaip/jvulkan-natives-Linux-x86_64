#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkQueuePresentKHR
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkQueue;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkPresentInfoKHR;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkQueuePresentKHR
  (JNIEnv *env, jobject, jobject jVkQueue, jobject jVkPresentInfoKHR)
{
    VkQueue_T *vkQueueHandle = (VkQueue_T *)hwjvi::getHandleValue(env, jVkQueue);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkPresentInfoKHR vkPresentInfoKHR = {};
    jobject jVkResultsCollectionObject = nullptr;

    hwjvi::getVkPresentInfoKHR(
            env,
            jVkPresentInfoKHR,
            &vkPresentInfoKHR,
            &jVkResultsCollectionObject,
            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    int result = vkQueuePresentKHR(
            vkQueueHandle,
            &vkPresentInfoKHR);

    if (jVkResultsCollectionObject != nullptr)
    {
        jclass vkResultsCollectionClass = env->GetObjectClass(jVkResultsCollectionObject);
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(vkResultsCollectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (uint32_t i = 0; i < vkPresentInfoKHR.swapchainCount; i++)
        {
            jobject jVkResultObject = hwjvi::createVkResult(env, vkPresentInfoKHR.pResults[i]);
            if (env->ExceptionOccurred())
            {
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jboolean added = env->CallBooleanMethod(jVkResultsCollectionObject, addMethodId, jVkResultObject);
            if (env->ExceptionOccurred())
            {
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (added == 0)
            {
                std::cerr << "Could not add VkResult to output collection." << std::endl;
                return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    hwjvi::freeMemory(&memoryToFree);

    return hwjvi::createVkResult(env, result);
}
