#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkFreeCommandBuffers
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandPool;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkFreeCommandBuffers
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkCommandPool, jobject jVkCommandBufferCollectionObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkCommandPool_T *commandPoolHandle = (VkCommandPool_T *)hwjvi::getHandleValue(env, jVkCommandPool);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass collectionClass = env->GetObjectClass(jVkCommandBufferCollectionObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jVkCommandBufferCollectionObject, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID methodId = env->GetMethodID(collectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jsize collectionSize = env->CallIntMethod(jVkCommandBufferCollectionObject, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (collectionSize == 0)
    {
        cerr << "Collection size is zero." << endl;
        return;
    }

    VkCommandBuffer_T  **arrayOfPointers = (VkCommandBuffer_T **)calloc(collectionSize, sizeof(VkCommandBuffer_T *));

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject vkCommandBufferObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, vkCommandBufferObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        arrayOfPointers[i++] = commandBufferHandle;

    } while (i < collectionSize);

    vkFreeCommandBuffers(logicalDeviceHandle, commandPoolHandle, collectionSize, (VkCommandBuffer_T * const *)arrayOfPointers);

    free(arrayOfPointers);
}

