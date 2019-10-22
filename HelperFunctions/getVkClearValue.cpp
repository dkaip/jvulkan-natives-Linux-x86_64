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
 * getVkClearValue.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: Douglas Kaip
 */

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "JVulkanHelperFunctions.hh"

namespace jvulkan
{
    void getVkClearValue(
            JNIEnv *env,
            jobject jVkClearValueObject,
            VkClearValue *vkClearValue,
            std::vector<void *> *memoryToFree)
    {
        jclass vkClearValueClass = env->GetObjectClass(jVkClearValueObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkClearValueClass, "getClearColorValue", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkClearColorValue;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jClearColorValueObject = env->CallObjectMethod(jVkClearValueObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        if (jClearColorValueObject != nullptr)
        {
            /*
             * Okay, we have determined that the VkClearValue is a VkClearColorValue
             * object.
             */

            jclass vkClearColorValueClass = env->GetObjectClass(jClearColorValueObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(vkClearColorValueClass, "getFloatValues", "()[F");
            jfloatArray floatArrayObject = (jfloatArray)env->CallObjectMethod(jClearColorValueObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            if (floatArrayObject != nullptr)
            {
                env->GetFloatArrayRegion(floatArrayObject, 0, sizeof(vkClearValue->color.float32)/4, vkClearValue->color.float32);
                if (env->ExceptionOccurred())
                {
                    return;
                }
//
//                std::cerr << vkClearValue->color.float32[0] << " " << vkClearValue->color.float32[1] <<
//                        " " << vkClearValue->color.float32[2] << " " << vkClearValue->color.float32[3] << std::endl;
            }
            else
            {
                // Well, it is not a float array
                methodId = env->GetMethodID(vkClearColorValueClass, "getIntValues", "()[I");
                jintArray intArrayObject = (jintArray)env->CallObjectMethod(jClearColorValueObject, methodId);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                if (intArrayObject != nullptr)
                {
                    env->GetIntArrayRegion(intArrayObject, 0, sizeof(vkClearValue->color.int32)/4, vkClearValue->color.int32);
                    if (env->ExceptionOccurred())
                    {
                        return;
                    }
                }
                else
                {
                    methodId = env->GetMethodID(vkClearColorValueClass, "getUintValues", "()[J");
                    jlongArray longArrayObject = (jlongArray)env->CallObjectMethod(jClearColorValueObject, methodId);
                    if (env->ExceptionOccurred())
                    {
                        return;
                    }

                    if (longArrayObject == nullptr)
                    {
                        std::cerr << "The VkClearColorValue object does not seem to have been initialized." << std::endl;
                        return;
                    }

                    jlong tempLongArray[4];
                    env->GetLongArrayRegion(longArrayObject, 0, sizeof(tempLongArray), tempLongArray);
                    if (env->ExceptionOccurred())
                    {
                        return;
                    }

                    vkClearValue->color.uint32[0] =  (uint32_t)tempLongArray[0];
                    vkClearValue->color.uint32[1] =  (uint32_t)tempLongArray[1];
                    vkClearValue->color.uint32[2] =  (uint32_t)tempLongArray[2];
                    vkClearValue->color.uint32[3] =  (uint32_t)tempLongArray[3];
                }
            }
        }
        else
        {
            /*
             * Okay, we have determined that the VkClearValue is a VkClearDepthStencilValue
             * object.
             */
            methodId = env->GetMethodID(vkClearValueClass, "getClearDepthStencilValue", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkClearDepthStencilValue;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jobject jClearDepthStencilValueObject = env->CallObjectMethod(jVkClearValueObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            if (jClearDepthStencilValueObject == nullptr)
            {
                std::cerr << "The VkClearValue object does not seem to have been initialized." << std::endl;
                return;
            }

            jclass vkClearDepthStencilValueClass = env->GetObjectClass(jClearDepthStencilValueObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(vkClearDepthStencilValueClass, "getDepth", "()F");
            jfloat depth = env->CallFloatMethod(jClearDepthStencilValueObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(vkClearDepthStencilValueClass, "getStencil", "()J");
            jlong stencil = env->CallLongMethod(jClearDepthStencilValueObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

//            std::cerr << "Depth " << depth << " stencil " << stencil << std::endl;
            vkClearValue->depthStencil.depth = depth;
            vkClearValue->depthStencil.stencil = (uint32_t)stencil;
        }
    }
}
