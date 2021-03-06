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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorBufferInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorBufferInfoCollectionObject,
            VkDescriptorBufferInfo **vkDescriptorBufferInfos,
            int *numberOfVkDescriptorBufferInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorBufferInfoCollectionClass = env->GetObjectClass(jVkDescriptorBufferInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkDescriptorBufferInfoCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorBufferInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkDescriptorBufferInfos = numberOfElements;
        *vkDescriptorBufferInfos = (VkDescriptorBufferInfo *)calloc(numberOfElements, sizeof(VkDescriptorBufferInfo));
        if (*vkDescriptorBufferInfos == nullptr)
        {
        	LOGERROR(env, "Could not allocate %d elements for vkDescriptorBufferInfos,", numberOfElements);
        	return;
        }

        memoryToFree->push_back(*vkDescriptorBufferInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorBufferInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorBufferInfoCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for iteratorObject.");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for hasNext.");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for next.");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkDescriptorBufferInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            if (jVkDescriptorBufferInfoObject == nullptr)
            {
            	LOGERROR(env, "%s", "jVkDescriptorBufferInfoObject is null");
            }

            getVkDescriptorBufferInfo(
                    env,
                    jVkDescriptorBufferInfoObject,
                    &((*vkDescriptorBufferInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorBufferInfo.");
                break;
            }

            i++;
        } while(true);
    }
}
