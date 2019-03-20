/*
 * Copyright 2019 Douglas Kaip
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"

namespace hwjvi
{
    void getVkSpecializationMapEntry(
            JNIEnv *env,
            const jobject jVkSpecializationMapEntryObject,
            VkSpecializationMapEntry *vkSpecializationMapEntry,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSpecializationMapEntryClass = env->GetObjectClass(jVkSpecializationMapEntryObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSpecializationMapEntryClass, "getConstantId", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint constandId = env->CallIntMethod(jVkSpecializationMapEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSpecializationMapEntryClass, "getOffset", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint offset = env->CallIntMethod(jVkSpecializationMapEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSpecializationMapEntryClass, "getSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong size = env->CallIntMethod(jVkSpecializationMapEntryObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        vkSpecializationMapEntry->constantID = constandId;
        vkSpecializationMapEntry->offset = offset;
        vkSpecializationMapEntry->size = (size_t)size;
    }

    void getVkSpecializationMapEntryCollection(
            JNIEnv *env,
            const jobject jVkSpecializationMapEntryCollectionObject,
            VkSpecializationMapEntry **vkSpecializationMapEntries,
            int *numberOfVkSpecializationMapEntries,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSpecializationMapEntryCollectionClass = env->GetObjectClass(jVkSpecializationMapEntryCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSpecializationMapEntryCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSpecializationMapEntryCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfVkSpecializationMapEntries = numberOfElements;
        *vkSpecializationMapEntries = (VkSpecializationMapEntry *)calloc(numberOfElements, sizeof(VkSpecializationMapEntry));
        memoryToFree->push_back(*vkSpecializationMapEntries);

        jmethodID iteratorMethodId = env->GetMethodID(vkSpecializationMapEntryCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSpecializationMapEntryCollectionObject, iteratorMethodId);
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

            jobject jVkSpecializationMapEntryObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkSpecializationMapEntry(
                    env,
                    jVkSpecializationMapEntryObject,
                    &((*vkSpecializationMapEntries)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }

    void getVkSpecializationInfo(
            JNIEnv *env,
            const jobject jVkSpecializationInfoInfoObject,
            VkSpecializationInfo *vkSpecializationInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSpecializationInfoInfoClass = env->GetObjectClass(jVkSpecializationInfoInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSpecializationInfoInfoClass, "getMapEntries", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSpecializationInfoInfoCollection = env->CallObjectMethod(jVkSpecializationInfoInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfSpecializationInfoInfos = 0;
        VkSpecializationMapEntry *vkSpecializationMapEntrys = nullptr;
        if (jVkSpecializationInfoInfoCollection != nullptr)
        {
            getVkSpecializationMapEntryCollection(
                    env,
                    jVkSpecializationInfoInfoCollection,
                    &vkSpecializationMapEntrys,
                    &numberOfSpecializationInfoInfos,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {

                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSpecializationInfoInfoClass, "getData", "()[B");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jbyteArray jData = (jbyteArray)env->CallObjectMethod(jVkSpecializationInfoInfoObject, methodId);

        char *dataArray = nullptr;
        jsize arrayLength = 0;
        if (jData != nullptr)
        {
            arrayLength = env->GetArrayLength(jData);

            dataArray = (char *)calloc(arrayLength, sizeof(char));
            memoryToFree->push_back(dataArray);

            env->GetByteArrayRegion(jData, 0, arrayLength, (signed char *)dataArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }



        vkSpecializationInfo->mapEntryCount = numberOfSpecializationInfoInfos;
        vkSpecializationInfo->pMapEntries = vkSpecializationMapEntrys;
        vkSpecializationInfo->dataSize = arrayLength;
        vkSpecializationInfo->pData = dataArray;
    }

    void getVkPipelineShaderStageCreateInfo(
            JNIEnv *env,
            const jobject jVkPipelineShaderStageCreateInfoObject,
            VkPipelineShaderStageCreateInfo *vkPipelineShaderStageCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineShaderStageCreateInfoClass = env->GetObjectClass(jVkPipelineShaderStageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkPipelineShaderStageCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineShaderStageCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getStage", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkShaderStageFlagBits;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkShaderStageFlagBitsObject = env->CallObjectMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkShaderStageFlagBitsEnumClass = env->GetObjectClass(jVkShaderStageFlagBitsObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkShaderStageFlagBitsEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkShaderStageFlagBitsEnumValue = env->CallIntMethod(jVkShaderStageFlagBitsObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getModule", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkShaderModule;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkShaderModuleObject = env->CallObjectMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkShaderModule_T *shaderModuleHandle = (VkShaderModule_T *)hwjvi::getHandleValue(env, jVkShaderModuleObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jstring jTheName = (jstring)env->CallObjectMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        const char *tempString = env->GetStringUTFChars(jTheName, 0);

        char *theName = (char *)calloc(1, strlen(tempString) + 1);
        memoryToFree->push_back(theName);

        strcpy(theName, tempString);
        env->ReleaseStringUTFChars(jTheName, tempString);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoClass, "getSpecializationInfo", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkSpecializationInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jVkSpecializationInfoObject = env->CallObjectMethod(jVkPipelineShaderStageCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSpecializationInfo *vkSpecializationInfo = nullptr;

        if (jVkSpecializationInfoObject != nullptr)
        {
            vkSpecializationInfo = (VkSpecializationInfo *)calloc(1, sizeof(VkSpecializationInfo));
            memoryToFree->push_back(vkSpecializationInfo);

            getVkSpecializationInfo(
                    env,
                    jVkSpecializationInfoObject,
                    vkSpecializationInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        vkPipelineShaderStageCreateInfo->sType = (VkStructureType)sTypeValue;
        vkPipelineShaderStageCreateInfo->pNext = (void *)pNext;
        vkPipelineShaderStageCreateInfo->flags = (VkPipelineShaderStageCreateFlags)flags;
        vkPipelineShaderStageCreateInfo->stage = (VkShaderStageFlagBits)vkShaderStageFlagBitsEnumValue;
        vkPipelineShaderStageCreateInfo->module = shaderModuleHandle;
        vkPipelineShaderStageCreateInfo->pName = theName;
        vkPipelineShaderStageCreateInfo->pSpecializationInfo = vkSpecializationInfo;
    }

    void getVkPipelineShaderStageCreateInfoCollection(
            JNIEnv *env,
            jobject jVkPipelineShaderStageCreateInfoCollectionObject,
            VkPipelineShaderStageCreateInfo **vkPipelineShaderStageCreateInfos,
            int *numberOfPipelineShaderStages,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPipelineShaderStageCreateInfoCollectionClass = env->GetObjectClass(jVkPipelineShaderStageCreateInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPipelineShaderStageCreateInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPipelineShaderStageCreateInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfPipelineShaderStages = numberOfElements;
        *vkPipelineShaderStageCreateInfos = (VkPipelineShaderStageCreateInfo *)calloc(numberOfElements, sizeof(VkPipelineShaderStageCreateInfo));
        memoryToFree->push_back((void *)*vkPipelineShaderStageCreateInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkPipelineShaderStageCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPipelineShaderStageCreateInfoCollectionObject, iteratorMethodId);
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

            jobject jVkPipelineShaderStageCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkPipelineShaderStageCreateInfo(
                    env,
                    jVkPipelineShaderStageCreateInfoObject,
                    &((*vkPipelineShaderStageCreateInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }

            i++;
        } while(true);
    }
}
