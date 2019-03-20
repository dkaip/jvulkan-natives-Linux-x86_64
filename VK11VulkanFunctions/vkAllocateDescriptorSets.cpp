#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkAllocateDescriptorSets
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkDescriptorSetAllocateInfo;Ljava/util/Collection;)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkAllocateDescriptorSets
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkDescriptorSetAllocateInfo, jobject jVkDescriptorSetCollection)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    std::vector<void *> memoryToFree(5);
    VkDescriptorSetAllocateInfo vkDescriptorSetAllocateInfo = {};
    hwjvi::getVkDescriptorSetAllocateInfo(
            env,
            jVkDescriptorSetAllocateInfo,
            &vkDescriptorSetAllocateInfo,
            &memoryToFree);
//    int numberOfVkDescriptorSetAllocateInfos = 0;
//    VkDescriptorSetAllocateInfo *vkDescriptorSetAllocateInfo = nullptr;
//
//    std::cout << "Gack00" << std::endl;
//    hwjvi::getVkDescriptorSetAllocateInfoCollection(
//            env,
//            jVkDescriptorSetAllocateInfoCollection,
//            &vkDescriptorSetAllocateInfo,
//            &numberOfVkDescriptorSetAllocateInfos,
//            &memoryToFree);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    VkDescriptorSet *descriptorSets = (VkDescriptorSet *)calloc(vkDescriptorSetAllocateInfo.descriptorSetCount, sizeof(VkDescriptorSet *));

    int result = vkAllocateDescriptorSets(
            logicalDeviceHandle,
            &vkDescriptorSetAllocateInfo,
            descriptorSets);

    hwjvi::freeMemory(&memoryToFree);

    jclass vkDescriptorSetCollectionClass = env->GetObjectClass(jVkDescriptorSetCollection);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID methodId = env->GetMethodID(vkDescriptorSetCollectionClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jint numberOfElements = env->CallIntMethod(jVkDescriptorSetCollection, methodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    if (vkDescriptorSetAllocateInfo.descriptorSetCount != (uint32_t)numberOfElements)
    {
        std::cerr << "ERROR: The collection size for resulting descriptor set collection must be the same as vkDescriptorSetAllocateInfo.descriptorSetCount." << std::endl;
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jobject iteratorObject = env->CallObjectMethod(jVkDescriptorSetCollection, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
        return hwjvi::createVkResult(env, VK_RESULT_MAX_ENUM);
    }

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

        jobject jVkDescriptorSet = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
            break;
        }

        /*
         * Now transfer the VkDevice data to Java
         */
        hwjvi::setHandleValue(env, jVkDescriptorSet, descriptorSets[i]);

        i++;
    } while(true);

    free(descriptorSets);

    return hwjvi::createVkResult(env, result);
}
