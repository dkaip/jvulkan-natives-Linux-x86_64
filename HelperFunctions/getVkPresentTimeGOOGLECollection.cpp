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
 * getVkPresentTimeGOOGLECollection.cpp
 *
 *  Created on: Sep 13, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPresentTimeGOOGLECollection(
            JNIEnv *env,
            const jobject jVkPresentTimeGOOGLECollectionObject,
			VkPresentTimeGOOGLE **vkPresentTimeGOOGLEs,
            int *numberOfVkPresentTimeGOOGLEs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkPresentTimeGOOGLECollectionClass = env->GetObjectClass(jVkPresentTimeGOOGLECollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkPresentTimeGOOGLECollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkPresentTimeGOOGLECollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkPresentTimeGOOGLECollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkPresentTimeGOOGLEs = numberOfElements;
        *vkPresentTimeGOOGLEs = (VkPresentTimeGOOGLE *)calloc(numberOfElements, sizeof(VkPresentTimeGOOGLE));
        memoryToFree->push_back(*vkPresentTimeGOOGLEs);

        jmethodID iteratorMethodId = env->GetMethodID(vkPresentTimeGOOGLECollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkPresentTimeGOOGLECollectionObject, iteratorMethodId);
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

            jobject jVkPresentTimeGOOGLEObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            getVkPresentTimeGOOGLE(
                    env,
                    jVkPresentTimeGOOGLEObject,
                    &((*vkPresentTimeGOOGLEs)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkPresentTimeGOOGLE.");
                break;
            }

            i++;
        } while(true);
    }
}
