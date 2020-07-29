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
/*
 * getStringCollection.cpp
 *
 *  Created on: May 9, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getStringCollection(
            JNIEnv *env,
            jobject jCollectionOfStrings,
            char ***stringArrayResult,
            int *numberOfStrings,
            std::vector<void *> *memoryToFree)
    {
        jclass collectionClass = env->FindClass("java/util/Collection");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class java/util/Collection");
            return;
        }

        jmethodID sizeMethod = env->GetMethodID(collectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for size.");
            return;
        }

        jint numStrings = env->CallIntMethod(jCollectionOfStrings, sizeMethod);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallIntMethod on jCollectionOfStrings");
            return;
        }

        jclass iteratorClass = env->FindClass("java/util/Iterator");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class java/util/Iterator");
            return;
        }

        jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for iterator.");
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jCollectionOfStrings, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod on jCollectionOfStrings");
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for hasNext.");
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for next.");
            return;
        }

        /*
         * Create an array of pointers to "c" strings;
         */
        char **arrayOfPointersToStrings = new char *[numStrings];
        memoryToFree->push_back((void *)arrayOfPointersToStrings);

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod on iteratorObject");
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jstring stringObject = (jstring)env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            const char* theCString = env->GetStringUTFChars(stringObject, nullptr);

            char *aString = (char *)calloc(strlen(theCString) + 1, sizeof(char));
            memoryToFree->push_back((void *)aString);

            strcpy(aString, theCString);

            arrayOfPointersToStrings[i] = aString;

            env->ReleaseStringUTFChars(stringObject, theCString);

            env->DeleteLocalRef(stringObject);

            i++;
        } while(true);

        *numberOfStrings = numStrings;
        *stringArrayResult = arrayOfPointersToStrings;
    }
}
