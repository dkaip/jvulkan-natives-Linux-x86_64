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
 * getVkDeviceQueueCreateInfo.cpp
 *
 *  Created on: Apr 24, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	void getVkDeviceQueueCreateInfo(
			JNIEnv *env,
			const jclass jVkQueueCreateInfoCollectionClass,
			const jobject jVkQueueCreateInfoCollection,
			VkDeviceQueueCreateInfo queueCreateInfo[],
			std::vector<void *> *memoryToFree)
	{
		jmethodID iteratorMethodId = env->GetMethodID(jVkQueueCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for iterator");
			return;
		}

		jobject iteratorObject = env->CallObjectMethod(jVkQueueCreateInfoCollection, iteratorMethodId);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed on CallObjectMethod for iterator");
			return;
		}

		jclass iteratorClass = env->GetObjectClass(iteratorObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get object class for iterator");
			return;
		}

		jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for hasNext");
			return;
		}

		jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not get methodId for next");
			return;
		}

		jclass vkDeviceQueueCreateInfoClass = nullptr;
		jmethodID getpNextMethodId = nullptr;
		jmethodID getFlagsMethodId = nullptr;
		jmethodID getQueueFamilyIndexMethodId = nullptr;
		jmethodID getQueueCountMethodId = nullptr;
		jmethodID getQueuePrioritiesMethodId = nullptr;
		int i = 0;
		do
		{
			jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on CallBooleanMethod for iterator");
				break;
			}

			if (hasNext == false)
			{
				break;
			}

			jobject vkDeviceQueueCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on CallObjectMethod for iterator");
				break;
			}

			if(i == 0)
			{
				vkDeviceQueueCreateInfoClass = env->GetObjectClass(vkDeviceQueueCreateInfoObject);
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Failed on GetObjectClass for vkDeviceQueueCreateInfoObject");
					break;
				}

//				getpNextMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getpNext", "()J");
//				if (env->ExceptionOccurred())
//				{
//					LOGERROR(env, "%s", "Could not get methodId for getpNext");
//					break;
//				}
//
				getFlagsMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Could not get methodId for getFlags");
					break;
				}

				getQueueFamilyIndexMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueFamilyIndex", "()I");
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Could not get methodId for getQueueFamilyIndex");
					break;
				}

				getQueueCountMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueCount", "()I");
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Could not get methodId for getQueueCount");
					break;
				}

				getQueuePrioritiesMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueuePriorities", "()[F");
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Could not get methodId for getQueuePriorities");
					break;
				}
			}

			int sTypeValue = getSTypeAsInt(env, vkDeviceQueueCreateInfoObject);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on getSTypeAsInt for vkDeviceQueueCreateInfoObject");
				return;
			}

	        jobject pNextObject = getpNext(env, vkDeviceQueueCreateInfoObject);
	        if (env->ExceptionOccurred())
	        {
	        	LOGERROR(env, "%s", "Call to getpNext failed.");
	            return;
	        }

	        if (pNextObject != nullptr)
	        {
	        	LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
	            return;
	        }

	        void *pNext = nullptr;

//			jlong pNext = env->CallLongMethod(vkDeviceQueueCreateInfoObject, getpNextMethodId);
//			if (env->ExceptionOccurred())
//			{
//				LOGERROR(env, "%s", "Failed on CallLongMethod for pNext");
//				break;
//			}
//
			jobject flagsObject = env->CallObjectMethod(vkDeviceQueueCreateInfoObject, getFlagsMethodId);
			int32_t flags = getEnumSetValue(
					env,
					flagsObject,
					"com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDeviceQueueCreateFlagBits");

			jint queueFamilyIndex = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getQueueFamilyIndexMethodId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on CallIntMethod for queueFamilyIndex");
				break;
			}

			jint queueCount = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getQueueCountMethodId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on CallIntMethod for queueCount");
				break;
			}

			jfloatArray queuePrioritiesArray = (jfloatArray)env->CallObjectMethod(vkDeviceQueueCreateInfoObject, getQueuePrioritiesMethodId);
			if (env->ExceptionOccurred())
			{
				LOGERROR(env, "%s", "Failed on CallObjectMethod for queuePriorities");
				break;
			}

			jsize sizeOfQueuePriorities = env->GetArrayLength(queuePrioritiesArray);
			if (sizeOfQueuePriorities != queueCount)
			{
				LOGERROR(env, "%s", "Failed on GetArrayLength for queuePrioritiesArray");
			}

			float *data = env->GetFloatArrayElements(queuePrioritiesArray, 0);
			float *heapQueuePriorities = (float *)calloc((size_t)sizeOfQueuePriorities, sizeof(float));
			memoryToFree->push_back(heapQueuePriorities);
			if (data != nullptr)
			{
				memcpy(heapQueuePriorities, data, sizeOfQueuePriorities * sizeof(float));
				env->ReleaseFloatArrayElements(queuePrioritiesArray, data, JNI_ABORT);
			}

			queueCreateInfo[i].sType = (VkStructureType)sTypeValue;
			queueCreateInfo[i].pNext = (const void *)pNext;
			queueCreateInfo[i].flags = flags;
			queueCreateInfo[i].queueFamilyIndex = queueFamilyIndex;
			queueCreateInfo[i].queueCount = queueCount;
			queueCreateInfo[i].pQueuePriorities = heapQueuePriorities;

			i++;
		} while(true);
	}
}
