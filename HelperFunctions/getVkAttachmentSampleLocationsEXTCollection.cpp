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
 * getVkAttachmentSampleLocationsEXTCollection.cpp
 *
 *  Created on: May 21, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkAttachmentSampleLocationsEXTCollection(
            JNIEnv *env,
            const jobject jVkAttachmentSampleLocationsEXTCollectionObject,
			VkAttachmentSampleLocationsEXT **vkAttachmentSampleLocationsEXT,
            int *numberOfVkAttachmentSampleLocationsEXTs,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkAttachmentSampleLocationsEXTCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkAttachmentSampleLocationsEXTCollectionObject.");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentSampleLocationsEXTCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod");
            return;
        }

        *numberOfVkAttachmentSampleLocationsEXTs = numberOfElements;
        *vkAttachmentSampleLocationsEXT = (VkAttachmentSampleLocationsEXT *)calloc(numberOfElements, sizeof(VkAttachmentSampleLocationsEXT));
        if (*vkAttachmentSampleLocationsEXT == nullptr)
        {
        	LOGERROR(env, "%s", "Error trying to allocate memory for *vkAttachmentSampleLocationsEXT");
            return;
        }

        memoryToFree->push_back(*vkAttachmentSampleLocationsEXT);

        jmethodID iteratorMethodId = env->GetMethodID(theClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(theClass, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for iteratorObject.");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for hasNext");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for next");
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

            jobject jVkAttachmentSampleLocationsEXTObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                break;
            }

            getVkAttachmentSampleLocationsEXT(
                    env,
					jVkAttachmentSampleLocationsEXTObject,
                    &((*vkAttachmentSampleLocationsEXT)[i]),
                    memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling method getVkInputAttachmentAspectReference");
                break;
            }

            i++;
        } while(true);
    }
}
