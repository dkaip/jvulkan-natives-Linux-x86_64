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
 * getVkPresentRegionKHR.cpp
 *
 *  Created on: May 30, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
    void getVkPresentRegionKHR(
            JNIEnv *env,
            const jobject jVkPresentRegionKHRObject,
			VkPresentRegionKHR *vkPresentRegionKHR,
            std::vector<void *> *memoryToFree)
    {
        jclass theClass = env->GetObjectClass(jVkPresentRegionKHRObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkPresentRegionKHRObject");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "getRectangles", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for getRectangles");
            return;
        }

        jobject jRectanglesObject = env->CallObjectMethod(jVkPresentRegionKHRObject, methodId);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling CallObjectMethod");
            return;
        }

        int rectangleCount = 0;
        VkRectLayerKHR *rectangles = nullptr;
        getVkRectLayerKHRCollection(
                env,
				jRectanglesObject,
                &rectangles,
                &rectangleCount,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getVkRectLayerKHRCollection");
            return;
        }

        vkPresentRegionKHR->rectangleCount = rectangleCount;
        vkPresentRegionKHR->pRectangles = rectangles;
    }
}
