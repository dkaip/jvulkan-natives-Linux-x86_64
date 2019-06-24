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
 * wlSeatGetPointer.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

static void wlpointerHandleEnter(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, struct wl_surface *wl_surface, wl_fixed_t surface_x, wl_fixed_t surface_y)
{

}

static void wlpointerHandleLeave(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, struct wl_surface *wl_surface)
{

}

static void wlpointerHandleMotion(void *data, struct wl_pointer *wl_pointer, uint32_t time, wl_fixed_t surface_x, wl_fixed_t surface_y)
{

}

static void wlpointerHandleButton(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, uint32_t time, uint32_t button, uint32_t state)
{

}

static void wlpointerHandleAxis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value)
{

}

static void wlpointerHandleFrame(void *data, struct wl_pointer *wl_pointer)
{

}

static void wlpointerHandleAxisSource(void *data, struct wl_pointer *wl_pointer, uint32_t axisSource)
{

}

static void wlpointerHandleAxisStop(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis)
{

}

static void wlpointerHandleAxisDiscrete(void *data, struct wl_pointer *wl_pointer, uint32_t axis, int32_t discrete)
{

}

static const wl_pointer_listener pointer_listener
{
	wlpointerHandleEnter,
	wlpointerHandleLeave,
	wlpointerHandleMotion,
	wlpointerHandleButton,
	wlpointerHandleAxis,
	wlpointerHandleFrame,
	wlpointerHandleAxisSource,
	wlpointerHandleAxisStop,
	wlpointerHandleAxisDiscrete
};
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlSeatGetPointer
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlSeatGetPointer
  (JNIEnv *env, jobject, jobject jWLSeat)
{
    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, jWLSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_pointer *pointer = wl_seat_get_pointer(waylandSeatHandle);
    if (pointer != nullptr)
    {
    	wl_pointer_add_listener(pointer, &pointer_listener, nullptr);
    }
//    if (pointer == nullptr)
//    {
//    	LOGERROR(env, "%s", "Error calling wl_seat_get_pointer.");
//        return nullptr;
//    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jInterfacePointer;
}

