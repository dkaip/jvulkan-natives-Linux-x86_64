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
    void getVkDescriptorImageInfoCollection(
            JNIEnv *env,
            const jobject jVkDescriptorImageInfoCollectionObject,
            VkDescriptorImageInfo **vkDescriptorImageInfos,
            int *numberOfVkDescriptorImageInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorImageInfoCollectionClass = env->GetObjectClass(jVkDescriptorImageInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get class for jVkDescriptorImageInfoCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorImageInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorImageInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkDescriptorImageInfos = numberOfElements;
        *vkDescriptorImageInfos = (VkDescriptorImageInfo *)calloc(numberOfElements, sizeof(VkDescriptorImageInfo));
        if (*vkDescriptorImageInfos == nullptr)
        {
        	LOGERROR(env, "Could not allocate %d elements for vkDescriptorImageInfos,", numberOfElements);
        	return;
        }

        memoryToFree->push_back(*vkDescriptorImageInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorImageInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error trying to get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkDescriptorImageInfoCollectionObject, iteratorMethodId);
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

            jobject jVkDescriptorImageInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            if (jVkDescriptorImageInfoObject == nullptr)
            {
            	LOGERROR(env, "%s", "jVkDescriptorImageInfoObject is null");
            }

            getVkDescriptorImageInfo(
                    env,
                    jVkDescriptorImageInfoObject,
                    &((*vkDescriptorImageInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkDescriptorImageInfo.");
                break;
            }

            i++;
        } while(true);
    }
}
