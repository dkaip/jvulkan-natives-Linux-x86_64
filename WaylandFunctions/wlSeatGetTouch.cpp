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
 * wlSeatGetTouch.cpp
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
 * Method:    wlSeatGetTouch
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlTouchHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlSeatGetTouch
  (JNIEnv *env, jobject, jobject jWLSeat)
{
    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, jWLSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_touch *touch = wl_seat_get_touch(waylandSeatHandle);
//    if (pointer == nullptr)
//    {
//    	LOGERROR(env, "%s", "Error calling wl_seat_get_pointer.");
//        return nullptr;
//    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlTouchHandle", touch);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }
zzzzzzzzzzzzzzzzzzzzzzzzzzz
    return jInterfacePointer;
}

