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
/*
 * getVkValidationFeatureDisableEXTCollection.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkValidationFeatureDisableEXTCollection(
            JNIEnv *env,
            const jobject jVkValidationFeatureDisableEXTCollectionObject,
			VkValidationFeatureDisableEXT **vkValidationFeatureDisableEXTs,
            int *numberOfVkValidationFeatureDisableEXTs,
            std::vector<void *> *memoryToFree)
    {
        jclass VkValidationFeatureDisableEXTCollectionClass = env->GetObjectClass(jVkValidationFeatureDisableEXTCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkValidationFeatureDisableEXTCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(VkValidationFeatureDisableEXTCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkValidationFeatureDisableEXTCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod on size method.");
            return;
        }

        *numberOfVkValidationFeatureDisableEXTs = numberOfElements;
        *vkValidationFeatureDisableEXTs = (VkValidationFeatureDisableEXT *)calloc(numberOfElements, sizeof(VkValidationFeatureDisableEXT));
        memoryToFree->push_back(*vkValidationFeatureDisableEXTs);

        jmethodID iteratorMethodId = env->GetMethodID(VkValidationFeatureDisableEXTCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkValidationFeatureDisableEXTCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on iteratorMethodId.");
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
        	LOGERROR(env, "%s", "Could not get method id for hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for next");
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod on hasNextMethodId.");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkValidationFeatureDisableEXTObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod on nextMethod.");
                break;
            }

            // TODO move this out of the loop
            jclass vkValidationFeatureDisableEXTEnumClass = env->GetObjectClass(jVkValidationFeatureDisableEXTObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error trying to get class for jVkValidationFeatureDisableEXTObject.");
                break;
            }


            jmethodID valueOfMethodId = env->GetMethodID(vkValidationFeatureDisableEXTEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not get method id for valueOf");
                return;
            }

            VkValidationFeatureDisableEXT vkValidationFeatureDisableEXTeEnumValue = (VkValidationFeatureDisableEXT)env->CallIntMethod(jVkValidationFeatureDisableEXTObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallIntMethod on valueOf.");
                return;
            }

            (*vkValidationFeatureDisableEXTs)[i] = vkValidationFeatureDisableEXTeEnumValue;

            i++;
        } while(true);
    }
}
