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
    void getVkSubmitInfoCollection(
            JNIEnv *env,
            const jobject jVkSubmitInfoCollectionObject,
            VkSubmitInfo **vkSubmitInfos,
            int *numberOfVkSubmitInfos,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubmitInfoCollectionClass = env->GetObjectClass(jVkSubmitInfoCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkSubmitInfoCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubmitInfoCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubmitInfoCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed for size");
            return;
        }

        *numberOfVkSubmitInfos = numberOfElements;
        *vkSubmitInfos = (VkSubmitInfo *)calloc(numberOfElements, sizeof(VkSubmitInfo));
        memoryToFree->push_back(*vkSubmitInfos);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubmitInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get methodId for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubmitInfoCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallObjectMethod failed for iterator");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "GetObjectClass failed for iterator");
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

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "CallBooleanMethod failed for hasNext");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkSubmitInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "CallObjectMethod failed for next");
                break;
            }

            getVkSubmitInfo(
                    env,
                    jVkSubmitInfoObject,
                    &((*vkSubmitInfos)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "getVkSubmitInfo failed");
                return;
            }

            i++;
        } while(true);
    }
}
