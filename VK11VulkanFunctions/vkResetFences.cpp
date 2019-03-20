#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkResetFences
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkResetFences
  (JNIEnv *env , jobject, jobject jVkDevice, jobject jVkFenceCollectionObject)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass collectionClass = env->GetObjectClass(jVkFenceCollectionObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jVkFenceCollectionObject, iteratorMethodId);
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

    jsize collectionSize = env->CallIntMethod(jVkFenceCollectionObject, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    if (collectionSize == 0)
    {
        cerr << "Collection size is zero." << endl;
        return;
    }

    VkFence_T  **arrayOfPointers = (VkFence_T **)calloc(collectionSize, sizeof(VkFence_T *));

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

        jobject jVkFenceObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        VkFence_T *fenceHandle = (VkFence_T *)hwjvi::getHandleValue(env, jVkFenceObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        arrayOfPointers[i++] = fenceHandle;

    } while (i < collectionSize);

    vkResetFences(logicalDeviceHandle, collectionSize, (VkFence_T * const *)arrayOfPointers);

    free(arrayOfPointers);
}

