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
 * putOnLinkedBlockingQueue.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Douglas Kaip
 */

#include <mutex>

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

static jmethodID methodId = nullptr;
static std::mutex l_QueueClass_Mutex;

namespace jvulkan
{
	void putOnLinkedBlockingQueue(JNIEnv *env, jobject jQueue, jobject entry)
	{
//    	LOGERROR(env, "%s", "putOnLinkedBlockingQueue.");
	    {
	    	if (methodId == nullptr)
	    	{
				std::lock_guard<std::mutex> lock(l_QueueClass_Mutex);
//		    	LOGERROR(env, "%s:%lx", "AAAA.", jQueue);
				jclass queueClass = env->GetObjectClass(jQueue);
			    if (env->ExceptionOccurred())
			    {
			    	LOGERROR(env, "%s", "Failed trying to find class for JQueue.");
			       return;
			    }

//		    	LOGERROR(env, "%s", "BBBB.");
			    methodId = env->GetMethodID(queueClass, "put", "(Ljava/lang/Object;)V");
				if (env->ExceptionOccurred())
				{
					LOGERROR(env, "%s", "Failed to find method id put.");
				   return;
				}
	    	}
	    }

//    	LOGERROR(env, "%s", "CCCC.");
	    env->CallVoidMethod(jQueue, methodId, entry);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Failed to put the entry on the LinkedBlockingQueue.");
		   return;
		}
	}
}
