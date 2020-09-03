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
    void getVkPushConstantRangeCollection(
            JNIEnv *env,
            const jobject jVkPushConstantRangeCollectionObject,
            VkPushConstantRange *pushConstantRanges[],
            int *numberOfPushConstantRanges,
            std::vector<void *> *memoryToFree)
    {
        if (jVkPushConstantRangeCollectionObject == nullptr)
        {
        	LOGERROR(env, "%s", "jVkPushConstantRangeCollectionObject was nullptr.");
            return;
        }

        jclass vkPushConstantRangeCollectionClass = env->GetObjectClass(jVkPushConstantRangeCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPushConstantRangeCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPushConstantRangeCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfPushConstantRanges = numberOfElements;
        *pushConstantRanges = (VkPushConstantRange *)calloc(numberOfElements, sizeof(VkPushConstantRange));
        memoryToFree->push_back(*pushConstantRanges);

        jmethodID iteratorMethodId = env->GetMethodID(vkPushConstantRangeCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPushConstantRangeCollectionObject, iteratorMethodId);
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
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod.");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkPushConstantRangeObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            getVkPushConstantRange(
                    env,
                    jVkPushConstantRangeObject,
                    &(*pushConstantRanges)[i]);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPushConstantRange.");
                return;
            }

            i++;
        } while(true);
    }
}
