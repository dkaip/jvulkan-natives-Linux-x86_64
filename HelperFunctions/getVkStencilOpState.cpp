#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkStencilOpState(
            JNIEnv *env,
            jobject jVkStencilOpStateObject,
            VkStencilOpState *vkStencilOpState,
            std::vector<void *> *memoryToFree)
    {
        jclass vkStencilOpStateClass = env->GetObjectClass(jVkStencilOpStateObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkStencilOpStateClass, "getFailOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint failOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getPassOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint passOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getDepthFailOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkStencilOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jVkStencilOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpEnumClass = env->GetObjectClass(jVkStencilOpObject);

        valueOfMethodId = env->GetMethodID(vkStencilOpEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint depthFailOpEnumValue = env->CallIntMethod(jVkStencilOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getCompareOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompareOp;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkCompareOpObject = env->CallObjectMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkCompareOpObjectEnumClass = env->GetObjectClass(jVkCompareOpObject);

        valueOfMethodId = env->GetMethodID(vkCompareOpObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint compareOpEnumValue = env->CallIntMethod(jVkCompareOpObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getCompareMask", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint compareMask = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getWriteMask", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint writeMask = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkStencilOpStateClass, "getReference", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint reference = env->CallIntMethod(jVkStencilOpStateObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkStencilOpState->failOp        = (VkStencilOp)failOpEnumValue;
        vkStencilOpState->passOp        = (VkStencilOp)passOpEnumValue;
        vkStencilOpState->depthFailOp   = (VkStencilOp)depthFailOpEnumValue;
        vkStencilOpState->compareOp     = (VkCompareOp)compareOpEnumValue;
        vkStencilOpState->compareMask   = compareMask;
        vkStencilOpState->writeMask     = writeMask;
        vkStencilOpState->reference     = reference;
    }
}
