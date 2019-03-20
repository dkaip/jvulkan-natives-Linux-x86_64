#include <iostream>
#include <vector>

using namespace std;

#include "com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    vkGetImageMemoryRequirements
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkDevice;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage;Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkMemoryRequirements;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_vkGetImageMemoryRequirements
  (JNIEnv *env, jobject, jobject jVkDevice, jobject jVkImage, jobject jVkMemoryRequirements)
{
    VkDevice_T *logicalDeviceHandle = (VkDevice_T *)hwjvi::getHandleValue(env, jVkDevice);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkImage_T *imageHandle = (VkImage_T *)hwjvi::getHandleValue(env, jVkImage);
    if (env->ExceptionOccurred())
    {
        return;
    }

    VkMemoryRequirements vkMemoryRequirements = {};

    vkGetImageMemoryRequirements(logicalDeviceHandle, imageHandle, &vkMemoryRequirements);

    jclass vkMemoryRequirementsClass = env->GetObjectClass(jVkMemoryRequirements);
    if (env->ExceptionOccurred())
    {
        return;
    }

    ////////////////////////////////////////////////////////////////////////////
    jmethodID methodId = env->GetMethodID(vkMemoryRequirementsClass, "setSize", "(J)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jVkMemoryRequirements, methodId, vkMemoryRequirements.size);

    ////////////////////////////////////////////////////////////////////////////
    methodId = env->GetMethodID(vkMemoryRequirementsClass, "setAlignment", "(J)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jVkMemoryRequirements, methodId, vkMemoryRequirements.alignment);

    ////////////////////////////////////////////////////////////////////////////
    jclass bitSetClass = env->FindClass("java/util/BitSet");

    methodId = env->GetMethodID(bitSetClass, "<init>", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    jobject bitSetObject = env->NewObject(bitSetClass, methodId, 32);
    if (env->ExceptionOccurred())
    {
        return;
    }

    methodId = env->GetMethodID(bitSetClass, "set", "(I)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    for (uint32_t i = 0; i < 32; i++)
    {
        if ((1 << i) & vkMemoryRequirements.memoryTypeBits)
        {
            env->CallVoidMethod(bitSetObject, methodId, i);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }
    }

    methodId = env->GetMethodID(vkMemoryRequirementsClass, "setMemoryTypeBits", "(Ljava/util/BitSet;)V");
    if (env->ExceptionOccurred())
    {
        return;
    }

    env->CallVoidMethod(jVkMemoryRequirements, methodId, bitSetObject);

    return;
}
