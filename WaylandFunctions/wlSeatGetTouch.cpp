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
 * wlSeatGetTouch.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

//extern JavaVM *l_JavaVM;
//
//extern jobject globalWaylandEventQueueObject;
//
static void wltouchHandleDown(void *data, struct wl_touch *wl_touch, uint32_t serialNumber, uint32_t time, struct wl_surface *wl_surface, int32_t id, wl_fixed_t x, wl_fixed_t y)
{
}

static void wltouchHandleUp(void *data, struct wl_touch *wl_touch, uint32_t serialNumber, uint32_t time, int32_t id)
{
}

static void wltouchHandleMotion(void *data, struct wl_touch *wl_touch, uint32_t time, int32_t id, wl_fixed_t x, wl_fixed_t y)
{
}

static void wltouchHandleFrame(void *data, struct wl_touch *wl_touch)
{
}

static void wltouchHandleCancel(void *data, struct wl_touch *wl_touch)
{
}

static void wltouchHandleShape(void *data, struct wl_touch *wl_touch, int32_t id, wl_fixed_t major, wl_fixed_t minor)
{
}

static void wltouchHandleOrientation(void *data, struct wl_touch *wl_touch, int32_t id, wl_fixed_t orientation)
{
}

static const wl_touch_listener touch_listener
{
	wltouchHandleDown,
	wltouchHandleUp,
	wltouchHandleMotion,
	wltouchHandleFrame,
	wltouchHandleCancel,
	wltouchHandleShape,
	wltouchHandleOrientation
};
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlSeatGetTouch
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlTouchHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlSeatGetTouch
  (JNIEnv *env, jobject, jobject jWLSeat)
{
    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, jWLSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_touch *touch = wl_seat_get_touch(waylandSeatHandle);
    if (touch != nullptr)
    {
    	wl_touch_add_listener(touch, &touch_listener, nullptr);
    }
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

    return jInterfacePointer;
}

