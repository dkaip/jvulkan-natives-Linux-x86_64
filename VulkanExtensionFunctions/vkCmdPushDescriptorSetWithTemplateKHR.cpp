/*
 * Copyright 2019-2020 Douglas Kaip
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
/*
 * vkCmdPushDescriptorSetWithTemplateKHR.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

static void getObjectCollection(
        JNIEnv *env,
        const jobject jObjectCollection,
        void **datavkCommandBuffers,
        int *dataSize,
        std::vector<void *> *memoryToFree);

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    vkCmdPushDescriptorSetWithTemplateKHR
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkCommandBuffer;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkDescriptorUpdateTemplate;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VkPipelineLayout;Ljava/util/Collection;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_vkCmdPushDescriptorSetWithTemplateKHR
  (JNIEnv *env, jobject, jobject jVkCommandBuffer, jobject jVkDescriptorUpdateTemplate, jobject jVkPipelineLayout, jobject jObjectCollection)
{
    VkCommandBuffer_T *commandBufferHandle = (VkCommandBuffer_T *)jvulkan::getHandleValue(env, jVkCommandBuffer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkCommandBuffer handle");
        return;
    }

    VkDescriptorUpdateTemplate_T *descriptorUpdateTemplateHandle = (VkDescriptorUpdateTemplate_T *)jvulkan::getHandleValue(env, jVkDescriptorUpdateTemplate);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkDescriptorUpdateTemplate handle");
        return;
    }

    VkPipelineLayout_T *pipelineLayoutHandle = (VkPipelineLayout_T *)jvulkan::getHandleValue(env, jVkPipelineLayout);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not retrieve VkPipelineLayout handle");
        return;
    }

    std::vector<void *> memoryToFree(5);
    int dataSize = 0;
    void *data = nullptr;
	getObjectCollection(
			env,
			jObjectCollection,
			&data,
			&dataSize,
			&memoryToFree);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error calling getObjectCollection");
		return;
	}

    vkCmdPushDescriptorSetWithTemplateKHR(
    		commandBufferHandle,
			descriptorUpdateTemplateHandle,
			pipelineLayoutHandle,
			dataSize,
			data);

    jvulkan::freeMemory(&memoryToFree);
}

static void getObjectCollection(
        JNIEnv *env,
        const jobject jObjectCollection,
        void **data,
        int *dataSize,
        std::vector<void *> *memoryToFree)
{
    jclass theClass = env->GetObjectClass(jObjectCollection);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get object class for jObjectCollection");
        return;
    }

    jmethodID methodId = env->GetMethodID(theClass, "size", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get methodId for size");
        return;
    }

    jint numberOfElements = env->CallIntMethod(jObjectCollection, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to retrieve the number of elements");
        return;
    }

    jmethodID iteratorMethodId = env->GetMethodID(theClass, "iterator", "()Ljava/util/Iterator;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get methodId for iterator");
        return;
    }

    jobject iteratorObject = env->CallObjectMethod(jObjectCollection, iteratorMethodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed calling CallObjectMethod to get iterator");
        return;
    }

    jclass iteratorClass = env->GetObjectClass(iteratorObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed calling GetObjectClass for iterator");
        return;
    }

    jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get methodId for hasNext");
        return;
    }

    jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get methodId for next");
        return;
    }

    *dataSize = numberOfElements;
    *data = (void *)calloc(1, 1);
    int offset = 0;

    int i = 0;
    do
    {
        jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying to get hasNext value");
            break;
        }

        if (hasNext == false)
        {
            break;
        }

        jobject theObject = env->CallObjectMethod(iteratorObject, nextMethod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Failed trying to get next element");
            break;
        }

        char *className = jvulkan::getClassName(env, theObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getClassName");
            break;
        }

        if (strcmp(className, "com.CIMthetics.jvulkan.VulkanCore.Structures.VkDescriptorImageInfo") == 0)
        {
            free(className);
        	// This element is a VkDescriptorImageInfo

            VkDescriptorImageInfo vkDescriptorImageInfo = {};
            jvulkan::getVkDescriptorImageInfo(
                    env,
					theObject,
        			&vkDescriptorImageInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorImageInfo.");
                return;
            }

            *data = (void *)realloc(*data, offset + sizeof(VkDescriptorImageInfo));
            if (*data == nullptr)
            {
            	LOGERROR(env, "%s", "Error while trying to reallocate memory for data");
            	break;
            }
            (void)memcpy(*data, &vkDescriptorImageInfo, sizeof(VkDescriptorImageInfo));

            offset += sizeof(VkDescriptorImageInfo);
        }
        else if (strcmp(className, "com.CIMthetics.jvulkan.VulkanCore.Structures.VkDescriptorBufferInfo") == 0)
        {
            free(className);
        	// This element is a VkDescriptorBufferInfo

            VkDescriptorBufferInfo vkDescriptorBufferInfo = {};
            jvulkan::getVkDescriptorBufferInfo(
                    env,
					theObject,
        			&vkDescriptorBufferInfo,
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorBufferInfo.");
                return;
            }

            *data = (void *)realloc(*data, offset + sizeof(VkDescriptorBufferInfo));
            if (*data == nullptr)
            {
            	LOGERROR(env, "%s", "Error while trying to reallocate memory for data");
            	break;
            }
            (void)memcpy(*data, &vkDescriptorBufferInfo, sizeof(VkDescriptorBufferInfo));

            offset += sizeof(VkDescriptorBufferInfo);
        }
        else if (strcmp(className, "com.CIMthetics.jvulkan.VulkanCore.Handles.VkBufferView") == 0)
        {
            free(className);
        	// This element is a VkBufferView

            VkBufferView_T *vkBufferVieWHandle = (VkBufferView_T *)jvulkan::getHandleValue(env, theObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not get methodId for size");
                break;
            }

            *data = (void *)realloc(*data, offset + sizeof(VkBufferView_T *));
            if (*data == nullptr)
            {
            	LOGERROR(env, "%s", "Error while trying to reallocate memory for data");
            	break;
            }
            (void)memcpy(*data, &vkBufferVieWHandle, sizeof(VkBufferView_T *));

            offset += sizeof(VkBufferView_T *);
        }
        else
        {
            free(className);
        	LOGERROR(env, "The object class of %s was not expected and is not handled.", className);
            break;
        }

        i++;
    } while(true);

    memoryToFree->push_back(*data);
}

