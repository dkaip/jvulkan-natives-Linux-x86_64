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
 * getVkSubpassDependencyCollection.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkSubpassDependencyCollection(
			JNIEnv *env,
			const jobject jVkSubpassDependencyCollectionObject,
			VkSubpassDependency **subpassDependencies,
			int *numberOfSubpassDependencies,
			std::vector<void *> *memoryToFree)
	{
		if (jVkSubpassDependencyCollectionObject == nullptr)
		{
			return;
		}

		jclass vkSubpassDependencyCollectionClass = env->GetObjectClass(jVkSubpassDependencyCollectionObject);
		if (env->ExceptionOccurred())
		{
			return;
		}

		jmethodID methodId = env->GetMethodID(vkSubpassDependencyCollectionClass, "size", "()I");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jint numberOfElements = env->CallIntMethod(jVkSubpassDependencyCollectionObject, methodId);
		if (env->ExceptionOccurred())
		{
			return;
		}

		*numberOfSubpassDependencies = numberOfElements;
		*subpassDependencies = (VkSubpassDependency *)calloc(numberOfElements, sizeof(VkSubpassDependency));
		memoryToFree->push_back(*subpassDependencies);

		jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDependencyCollectionClass, "iterator", "()Ljava/util/Iterator;");
		if (env->ExceptionOccurred())
		{
			return;
		}

		jobject iteratorObject = env->CallObjectMethod(jVkSubpassDependencyCollectionObject, iteratorMethodId);
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

			jobject jVkSubpassDependencyObject = env->CallObjectMethod(iteratorObject, nextMethod);
			if (env->ExceptionOccurred())
			{
				break;
			}

			getVkSubpassDependency(
					env,
					jVkSubpassDependencyObject,
					&(*subpassDependencies)[i],
					memoryToFree);

			i++;
		} while(true);
	}
}
