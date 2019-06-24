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
 * wlKeyboardRelease.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlKeyboardRelease
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlKeyboardRelease
  (JNIEnv *env, jobject, jobject jWlKeyboard)
{
    struct wl_keyboard *waylandKeyboardHandle = (struct wl_keyboard *)jvulkan::getHandleValue(env, jWlKeyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    wl_keyboard_release(waylandKeyboardHandle);
}

