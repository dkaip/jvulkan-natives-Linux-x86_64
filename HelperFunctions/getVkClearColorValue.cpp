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
 * getClearColorValue.cpp
 *
 *  Created on: Oct 23, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkClearColorValue(
            JNIEnv *env,
            jobject jVkClearColorValueObject,
			VkClearColorValue *vkClearColorValue,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkClearColorValueObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkClearColorValueObject");
            return;
        }

        jmethodID methodId = env->GetMethodID(theClass, "getFloatValues", "()[F");
        jfloatArray floatArrayObject = (jfloatArray)env->CallObjectMethod(jVkClearColorValueObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        if (floatArrayObject != nullptr)
        {
            env->GetFloatArrayRegion(floatArrayObject, 0, sizeof(vkClearColorValue->float32)/4, vkClearColorValue->float32);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling GetFloatArrayRegion");
                return;
            }
        }
        else
        {
            // Well, it is not a float array
            methodId = env->GetMethodID(theClass, "getIntValues", "()[I");
            jintArray intArrayObject = (jintArray)env->CallObjectMethod(jVkClearColorValueObject, methodId);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                return;
            }

            if (intArrayObject != nullptr)
            {
                env->GetIntArrayRegion(intArrayObject, 0, sizeof(vkClearColorValue->int32)/4, vkClearColorValue->int32);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling GetIntArrayRegion");
                    return;
                }
            }
            else
            {
                methodId = env->GetMethodID(theClass, "getUintValues", "()[J");
                jlongArray longArrayObject = (jlongArray)env->CallObjectMethod(jVkClearColorValueObject, methodId);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling CallObjectMethod");
                    return;
                }

                if (longArrayObject == nullptr)
                {
                	LOGERROR(env, "%s", "The VkClearColorValue object does not seem to have been initialized.");
                    return;
                }

                jlong tempLongArray[4];
                env->GetLongArrayRegion(longArrayObject, 0, sizeof(tempLongArray), tempLongArray);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling GetLongArrayRegion");
                    return;
                }

                vkClearColorValue->uint32[0] =  (uint32_t)tempLongArray[0];
                vkClearColorValue->uint32[1] =  (uint32_t)tempLongArray[1];
                vkClearColorValue->uint32[2] =  (uint32_t)tempLongArray[2];
                vkClearColorValue->uint32[3] =  (uint32_t)tempLongArray[3];
            }
        }
    }
}
