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
 * getJNIEnv.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Douglas Kaip
 */

#include <iostream>

#include "HelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

namespace jvulkan
{
	JNIEnv *getJNIEnv()
	{
		JNIEnv *env = nullptr;

	    int envStatus = l_JavaVM->GetEnv((void **)&env, JNI_VERSION_1_6);
	    if (envStatus == JNI_EDETACHED)
	    {
	        if (l_JavaVM->AttachCurrentThread((void **)&env, nullptr) != 0)
	        {
	            std::cerr << "Failed to attach to current thread trying to get JNIEnv pointer." << std::endl;
	            return nullptr;
	        }
	    }
	    else if (envStatus == JNI_OK)
	    {
	        ;
	    }
	    else if (envStatus == JNI_EVERSION)
	    {
	    	std::cerr << "JNI_VERSION_1_6 not supported." << std::endl;
	        return nullptr;
	    }

	    return env;
	}
}
