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
 * getVkValidationCheckEXTCollection.cpp
 *
 *  Created on: May 10, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkValidationCheckEXTCollection(
            JNIEnv *env,
            const jobject jVkValidationCheckEXTCollectionObject,
			VkValidationCheckEXT **vkValidationCheckEXTs,
            int *numberOfVkValidationCheckEXTs,
            std::vector<void *> *memoryToFree)
    {
        jclass vkValidationCheckEXTCollectionClass = env->GetObjectClass(jVkValidationCheckEXTCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkValidationFlagsEXTCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkValidationCheckEXTCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkValidationCheckEXTCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod on size method.");
            return;
        }

        *numberOfVkValidationCheckEXTs = numberOfElements;
        *vkValidationCheckEXTs = (VkValidationCheckEXT *)calloc(numberOfElements, sizeof(VkValidationCheckEXT));
        memoryToFree->push_back(*vkValidationCheckEXTs);

        jmethodID iteratorMethodId = env->GetMethodID(vkValidationCheckEXTCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkValidationCheckEXTCollectionObject, iteratorMethodId);
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

            jobject jVkValidationCheckEXTObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod on nextMethod.");
                break;
            }

            // TODO move this out of the loop
            jclass vkValidationCheckEXTEnumClass = env->GetObjectClass(jVkValidationCheckEXTObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error trying to get class for jVkValidationCheckEXTObject.");
                break;
            }


            jmethodID valueOfMethodId = env->GetMethodID(vkValidationCheckEXTCollectionClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not get method id for valueOf");
                return;
            }

            VkValidationCheckEXT vkValidationCheckEXTEnumValue = (VkValidationCheckEXT)env->CallIntMethod(jVkValidationCheckEXTObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallIntMethod on valueOf.");
                return;
            }

            (*vkValidationCheckEXTs)[i] = vkValidationCheckEXTEnumValue;

            i++;
        } while(true);
    }
}
