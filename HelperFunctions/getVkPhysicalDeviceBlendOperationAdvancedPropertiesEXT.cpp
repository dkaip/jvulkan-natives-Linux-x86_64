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
 * getVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT.cpp
 *
 *  Created on: May 12, 2019
 *      Author: Douglas Kaip
 */

#include "HelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
{
	/*
	 * This function looks different from others of this sort because it is
	 * just getting the pNext chain and the sType.  The structure
	 *  VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT is one that is
	 *  filled in by the LunarG SDK and so we are only ever expecting the pNext
	 *  chain and the sType to be filled in from the Java side of things.
	 */
	void getVkPhysicalDeviceBlendOperationAdvancedPropertiesEXT(
		JNIEnv *env,
		const jobject jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject,
		VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT *vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT,
		std::vector<void *> *memoryToFree)
	{
        ////////////////////////////////////////////////////////////////////////
        VkStructureType sTypeValue = (VkStructureType)getSTypeAsInt(env, jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling getSTypeAsInt");
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject jpNextObject = getpNextObject(env, jVkPhysicalDeviceBlendOperationAdvancedPropertiesEXTObject);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to getpNextObject failed.");
            return;
        }

        void *pNext = nullptr;
        if (jpNextObject != nullptr)
        {
        	getpNextChain(
        			env,
					jpNextObject,
        			&pNext,
        			memoryToFree);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Call to getpNextChain failed.");
                return;
            }
        }


        vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->sType	= sTypeValue;
        vkPhysicalDeviceBlendOperationAdvancedPropertiesEXT->pNext	= pNext;
	}
}
