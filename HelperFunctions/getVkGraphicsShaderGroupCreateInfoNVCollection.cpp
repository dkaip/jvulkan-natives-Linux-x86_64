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
 * getVkGraphicsShaderGroupCreateInfoNVCollection.cpp
 *
 *  Created on: Sep 10, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkGraphicsShaderGroupCreateInfoNVCollection(
            JNIEnv *env,
            const jobject jVkGraphicsShaderGroupCreateInfoNVCollectionObject,
			VkGraphicsShaderGroupCreateInfoNV **vkGraphicsShaderGroupCreateInfoNVs,
            int *numberOfVkGraphicsShaderGroupCreateInfoNVs,
            std::vector<void *> *memoryToFree)
    {
        if (jVkGraphicsShaderGroupCreateInfoNVCollectionObject == nullptr)
        {
        	LOGERROR(env, "%s", "jVkGraphicsShaderGroupCreateInfoNVCollectionObject is nullptr.");
            return;
        }

        jclass vkGraphicsShaderGroupCreateInfoNVCollectionClass = env->GetObjectClass(jVkGraphicsShaderGroupCreateInfoNVCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkGraphicsShaderGroupCreateInfoNVCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkGraphicsShaderGroupCreateInfoNVCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size.");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkGraphicsShaderGroupCreateInfoNVCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod.");
            return;
        }

        *numberOfVkGraphicsShaderGroupCreateInfoNVs = numberOfElements;
        *vkGraphicsShaderGroupCreateInfoNVs = (VkGraphicsShaderGroupCreateInfoNV *)calloc(numberOfElements, sizeof(VkGraphicsShaderGroupCreateInfoNV));
        if (*vkGraphicsShaderGroupCreateInfoNVs == nullptr)
        {
        	LOGERROR(env, "Could not allocate %d bytes for *vkGraphicsShaderGroupCreateInfoNVs", numberOfElements *sizeof(VkGraphicsShaderGroupCreateInfoNV));
            return;
        }
        memoryToFree->push_back(*vkGraphicsShaderGroupCreateInfoNVs);

        jmethodID iteratorMethodId = env->GetMethodID(vkGraphicsShaderGroupCreateInfoNVCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkGraphicsShaderGroupCreateInfoNVCollectionObject, iteratorMethodId);
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

            jobject jVkGraphicsShaderGroupCreateInfoNVObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
                break;
            }

            getVkGraphicsShaderGroupCreateInfoNV(
                    env,
					jVkGraphicsShaderGroupCreateInfoNVObject,
                    &(*vkGraphicsShaderGroupCreateInfoNVs)[i],
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling getVkGraphicsShaderGroupCreateInfoNV.");
                break;
            }

            i++;
        } while(true);
    }
}
