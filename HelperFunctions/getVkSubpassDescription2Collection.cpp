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
    void getVkSubpassDescription2Collection(
            JNIEnv *env,
            const jobject jVkSubpassDescription2CollectionObject,
            VkSubpassDescription2 **vkSubpassDescription2s,
            int *numberOfVkSubpassDescription2s,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDescription2KHRCollectionClass = env->GetObjectClass(jVkSubpassDescription2CollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkSubpassDescription2CollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubpassDescription2KHRCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubpassDescription2CollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkSubpassDescription2s = numberOfElements;
        *vkSubpassDescription2s = (VkSubpassDescription2 *)calloc(numberOfElements, sizeof(VkSubpassDescription2));
        memoryToFree->push_back(*vkSubpassDescription2s);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDescription2KHRCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubpassDescription2CollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for iteratorObject.");
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

            jobject jVkSubpassDescription2Object = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            getVkSubpassDescription2(
                    env,
                    jVkSubpassDescription2Object,
                    &((*vkSubpassDescription2s)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkSubpassDescription2.");
                break;
            }

            i++;
        } while(true);
    }
}
