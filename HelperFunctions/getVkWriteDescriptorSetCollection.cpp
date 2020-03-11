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

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkWriteDescriptorSetCollection(
            JNIEnv *env,
            const jobject jVkWriteDescriptorSetCollectionObject,
            VkWriteDescriptorSet **vkWriteDescriptorSets,
            int *numberOfVkWriteDescriptorSets,
            std::vector<void *> *memoryToFree)
    {
        jclass vkWriteDescriptorSetCollectionClass = env->GetObjectClass(jVkWriteDescriptorSetCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkWriteDescriptorSetCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkWriteDescriptorSetCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkWriteDescriptorSetCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkWriteDescriptorSets = numberOfElements;
        *vkWriteDescriptorSets = (VkWriteDescriptorSet *)calloc(numberOfElements, sizeof(VkWriteDescriptorSet));
        if (*vkWriteDescriptorSets == nullptr)
        {
        	LOGERROR(env, "%s", "Could not allocate memory for vkWriteDescriptorSets.");
        	return;
        }
        memoryToFree->push_back(*vkWriteDescriptorSets);

        jmethodID iteratorMethodId = env->GetMethodID(vkWriteDescriptorSetCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkWriteDescriptorSetCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
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
        	LOGERROR(env, "%s", "Could not get method id for hasNext.");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for next.");
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

            jobject jVkWriteDescriptorSetObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            jvulkan::getVkWriteDescriptorSet(
                    env,
                    jVkWriteDescriptorSetObject,
                    &((*vkWriteDescriptorSets)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkWriteDescriptorSet.");
                break;
            }

            i++;
        } while(true);
    }
}
