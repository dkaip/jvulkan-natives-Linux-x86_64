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
 * setLongReturnValue.cpp
 *
 *  Created on: Oct 29, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    void setLongReturnValue(JNIEnv *env, jobject jReturnValue, jlong value)
    {
        jclass handleClass = env->GetObjectClass(jReturnValue);
        if (env->ExceptionOccurred())
        {
            cout << "setHandleValue: could not find class "<< endl;
            return;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "setValue", "(J)V");
        if (env->ExceptionOccurred())
        {
            cout << "setIntReturnValue: could not find method setValue (J)V" << endl;
            return;
        }

        env->CallVoidMethod(jReturnValue, methodId, value);
    }
}
