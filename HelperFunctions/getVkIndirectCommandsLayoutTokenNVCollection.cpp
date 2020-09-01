/*
 * Copyright 2020 Douglas Kaip
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
 * getVkIndirectCommandsLayoutTokenNVCollection.cpp
 *
 *  Created on: Aug 31, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkIndirectCommandsLayoutTokenNVCollection(
            JNIEnv *env,
            const jobject jVkIndirectCommandsLayoutTokenNVCollectionObject,
			VkIndirectCommandsLayoutTokenNV **vkIndirectCommandsLayoutTokenNVs,
            int *numberOfVkIndirectCommandsLayoutTokenNVs,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkIndirectCommandsLayoutTokenNVCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkIndirectCommandsLayoutTokenNVCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkIndirectCommandsLayoutTokenNVCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkIndirectCommandsLayoutTokenNVs = numberOfElements;
        *vkIndirectCommandsLayoutTokenNVs = (VkIndirectCommandsLayoutTokenNV *)calloc(numberOfElements, sizeof(VkIndirectCommandsLayoutTokenNV));
        memoryToFree->push_back(*vkIndirectCommandsLayoutTokenNVs);

        jmethodID iteratorMethodId = env->GetMethodID(theClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkIndirectCommandsLayoutTokenNVCollectionObject, iteratorMethodId);
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

            jobject jVkIndirectCommandsLayoutTokenNVObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            getVkIndirectCommandsLayoutTokenNV(
                    env,
					jVkIndirectCommandsLayoutTokenNVObject,
                    &((*vkIndirectCommandsLayoutTokenNVs)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkIndirectCommandsLayoutTokenNV.");
                break;
            }

            i++;
        } while(true);
    }
}
