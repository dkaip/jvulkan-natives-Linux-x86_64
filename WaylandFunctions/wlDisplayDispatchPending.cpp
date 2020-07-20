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
 * wlDisplayDispatchPending.cpp
 *
 *  Created on: Jun 23, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlDisplayDispatchPending
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle;)I
 */
JNIEXPORT jint JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlDisplayDispatchPending
  (JNIEnv *env, jobject, jobject jWlDisplay)
{
    wl_display *waylandDisplayHandle = (wl_display *)jvulkan::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return -1;
    }

    return wl_display_dispatch_pending(waylandDisplayHandle);
}
