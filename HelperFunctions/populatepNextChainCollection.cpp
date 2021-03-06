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
 * populatepNextChainCollection.cpp
 *
 *  Created on: May 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void populatepNextChainCollection(
            JNIEnv *env,
            const jobject jCollectionObject,
			VkBaseOutStructure *collectionObjects,
            std::vector<void *> *memoryToFree)
    {
        jclass theCollectionClass = env->GetObjectClass(jCollectionObject);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find class for jCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(theCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        if (numberOfElements == 0)
        {
        	// Hmmm, the collection was empty...there is nothing we can do.
        	return;
        }

        jmethodID iteratorMethodId = env->GetMethodID(theCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
			LOGERROR(env, "%s", "Could not find class for iteratorObject");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id next");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            jclass jObjectClass = env->GetObjectClass(jObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error getting class for jObject");
                break;
            }

            jmethodID getpNextMethodId = env->GetMethodID(jObjectClass, "getpNext", "()Lcom/CIMthetics/jvulkan/VulkanCore/Structures/CreateInfos/VulkanCreateInfoStructure;");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not find method id getpNext");
                return;
            }

            jobject jpNextObject = env->CallObjectMethod(jObject, getpNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            if (collectionObjects[i].pNext != nullptr)
            {
            	populatepNextChain(
            			env,
						jpNextObject,
						collectionObjects[i].pNext,
            			memoryToFree);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling populatepNextChain");
                    break;
                }
            }

            i++;
        } while(true);
    }
}
