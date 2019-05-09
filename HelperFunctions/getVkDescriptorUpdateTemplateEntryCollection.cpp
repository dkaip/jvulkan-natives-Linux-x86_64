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
 * getVkDescriptorUpdateTemplateEntryCollection.cpp
 *
 *  Created on: May 8, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkDescriptorUpdateTemplateEntryCollection(
            JNIEnv *env,
            const jobject jVkDescriptorUpdateTemplateEntryCollectionObject,
			VkDescriptorUpdateTemplateEntry **vkDescriptorUpdateTemplateEntries,
            int *numberOfVkDescriptorUpdateTemplateEntries,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDescriptorUpdateTemplateEntryCollectionClass = env->GetObjectClass(jVkDescriptorUpdateTemplateEntryCollectionObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get class for jVkDescriptorUpdateTemplateEntryCollectionObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not get method size for class for jVkDescriptorUpdateTemplateEntryCollectionObject");
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkDescriptorUpdateTemplateEntryCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "CallIntMethod failed to get the size for jVkDescriptorUpdateTemplateEntryCollectionObject");
            return;
        }

        *numberOfVkDescriptorUpdateTemplateEntries = numberOfElements;
        *vkDescriptorUpdateTemplateEntries = (VkDescriptorUpdateTemplateEntry *)calloc(numberOfElements, sizeof(VkDescriptorUpdateTemplateEntry));
        memoryToFree->push_back(*vkDescriptorUpdateTemplateEntries);

        jmethodID iteratorMethodId = env->GetMethodID(vkDescriptorUpdateTemplateEntryCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(vkDescriptorUpdateTemplateEntryCollectionClass, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
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
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkDescriptorUpdateTemplateEntryObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkDescriptorUpdateTemplateEntry(
                    env,
					jVkDescriptorUpdateTemplateEntryObject,
                    &((*vkDescriptorUpdateTemplateEntries)[i]),
                    memoryToFree);

            i++;
        } while(true);
    }
}
