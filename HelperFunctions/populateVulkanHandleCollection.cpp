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
 * populateVulkanHandleCollection.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
/*
 * This is kind of a hybrid between a "populate" and a "create" function.  If requires that
 * jVulkanHandleCollection already exist, but, it will create and add the individual handles
 * to the collection.
 */
    void populateVulkanHandleCollection(JNIEnv *env, const char *className, jobject jVulkanHandleCollection, int handlesCount, const void **handles)
    {
    	jclass collectionClass = env->GetObjectClass(jVulkanHandleCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVulkanHandleCollection");
            return;
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could find add method for collectionClass");
            return;
        }

    	for(int i = 0; i < handlesCount; i++)
    	{
    		jobject vulkanHandleObject =
    				createVulkanHandle(env, className, &handles[i]);

    		env->CallVoidMethod(jVulkanHandleCollection, addMethodId, vulkanHandleObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Failed trying to add a VulkanHandle object to jVulkanHandleCollection");
                return;
            }
    	}
    }
}
