#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkCmdBindVertexBuffers
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkCommandBuffer;ILjava/util/Collection;[J)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkCmdBindVertexBuffers
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jint jFirstBinding, jobject jVkBufferCollectionObject, jlongArray jOffsetsArray)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)hwjvi::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jclass collectionClass = env->GetObjectClass(jVkBufferCollectionObject);
    if (env->ExceptionOccurred())
    {
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jVkBufferCollectionObject, iteratorMethodId);
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

    jsize collectionSize = env->CallIntMethod(jVkBufferCollectionObject, methodId);
    if (env->ExceptionOccurred())
    {
        return;
    }

    int bindingCount = collectionSize;
    if (collectionSize == 0)
    {
        cerr << "Collection size is zero." << endl;
        return;
    }

    VkBuffer_T  **arrayOfPointers = (VkBuffer_T **)calloc(collectionSize, sizeof(VkBuffer_T *));

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

        VkBuffer_T *bufferHandle = (VkBuffer_T *)hwjvi::getHandleValue(env, jVkFenceObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        arrayOfPointers[i++] = bufferHandle;

    } while (i < collectionSize);

    long *offsetsArray = nullptr;
    jsize arrayLength = 0;
    if (jOffsetsArray != nullptr)
    {
        arrayLength = env->GetArrayLength(jOffsetsArray);

        offsetsArray = (long *)calloc(arrayLength, sizeof(long));
//        memoryToFree->push_back(offsetsArray);

        env->GetLongArrayRegion(jOffsetsArray, 0, arrayLength, offsetsArray);
        if (env->ExceptionOccurred())
        {
            return;
        }
    }

    vkCmdBindVertexBuffers(
            commandBufferHandle,
            jFirstBinding,
            bindingCount,
            (VkBuffer_T * const *)arrayOfPointers,
            (unsigned long int *)offsetsArray);

    free(arrayOfPointers);
    free(offsetsArray);
}

