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
 * createVkResult.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
	jobject createVkResult(JNIEnv *env, jint value)
	{
		/*
		 * This function is usually called just before the caller is returning
		 * back to Java.  If value does not correspond to VK_SUCCESS it may be
		 * because some other function call has failed and thrown an exception.
		 * In that case our "env" methods will not work properly.  Since the
		 * calling function is most likely going to return with the result of
		 * this call immediately we are going to clear the exception so that
		 * we can properly create the appropriate response.
		 */
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "Clearing an exception.");
			env->ExceptionClear();
		}

		jobject vkResultObject = createEnumFromValue(
				env,
				"com/CIMthetics/jvulkan/VulkanCore/Enums/VkResult",
				value);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling createEnumFromValue.");
			return nullptr;
		}

		return vkResultObject;
	}
}
