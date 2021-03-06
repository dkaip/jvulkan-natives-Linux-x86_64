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
 * wlPointerRelease.cpp
 *
 *  Created on: Jun 21, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlPointerRelease
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlPointerRelease
  (JNIEnv *env, jobject, jobject jWlPointer)
{
    struct wl_pointer *waylandPointerHandle = (struct wl_pointer *)jvulkan::getHandleValue(env, jWlPointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    wl_pointer_release(waylandPointerHandle);
}

