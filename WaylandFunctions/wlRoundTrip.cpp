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
#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlRoundTrip
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlDisplay;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlRoundTrip
  (JNIEnv *env, jobject, jobject jWlDisplay)
{
    wl_display *waylandDisplayHandle = (wl_display *)jvulkan::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
        return;
    }

    wl_display_roundtrip(waylandDisplayHandle);
}
