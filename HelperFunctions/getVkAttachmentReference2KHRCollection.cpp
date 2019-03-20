#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkAttachmentReference2KHR(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRObject,
            VkAttachmentReference2KHR *vkAttachmentReference2KHR,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentReference2KHRClass = env->GetObjectClass(jVkAttachmentReference2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkAttachmentReference2KHRObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getAttachment", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint jAttachment = env->CallIntMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        uint32_t attachment = (uint32_t)jAttachment;

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageLayoutTypeObject = env->CallObjectMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutTypeObjectEnumClass = env->GetObjectClass(jVkImageLayoutTypeObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageLayout layoutEnumValue = (VkImageLayout)env->CallIntMethod(jVkImageLayoutTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

         ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReference2KHRClass, "getAspectMask", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageAspectFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkImageAspectFlagBitsTypeObject = env->CallObjectMethod(jVkAttachmentReference2KHRObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageAspectFlagBitsTypeObjectEnumClass = env->GetObjectClass(jVkImageAspectFlagBitsTypeObject);

        valueOfMethodId = env->GetMethodID(vkImageAspectFlagBitsTypeObjectEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImageAspectFlagBits aspectMaskTypeEnumValue = (VkImageAspectFlagBits)env->CallIntMethod(jVkImageAspectFlagBitsTypeObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkAttachmentReference2KHR->sType = (VkStructureType)sTypeValue;
        vkAttachmentReference2KHR->pNext = (void *)pNext;
        vkAttachmentReference2KHR->attachment = attachment;
        vkAttachmentReference2KHR->layout = layoutEnumValue;
        vkAttachmentReference2KHR->aspectMask = aspectMaskTypeEnumValue;
    }

    void getVkAttachmentReference2KHRCollection(
            JNIEnv *env,
            const jobject jVkAttachmentReference2KHRCollectionObject,
            VkAttachmentReference2KHR **vkAttachmentReference2KHRs,
            int *numberOfVkAttachmentReference2KHRs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentReference2KHRCollectionClass = env->GetObjectClass(jVkAttachmentReference2KHRCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentReference2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentReference2KHRCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkAttachmentReference2KHRs = numberOfElements;
        *vkAttachmentReference2KHRs = (VkAttachmentReference2KHR *)calloc(numberOfElements, sizeof(VkAttachmentReference2KHR));
        memoryToFree->push_back(*vkAttachmentReference2KHRs);

        jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentReference2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAttachmentReference2KHRCollectionObject, iteratorMethodId);
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

            jobject jVkAttachmentReference2KHRObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkAttachmentReference2KHR(
                    env,
                    jVkAttachmentReference2KHRObject,
                    &((*vkAttachmentReference2KHRs)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
