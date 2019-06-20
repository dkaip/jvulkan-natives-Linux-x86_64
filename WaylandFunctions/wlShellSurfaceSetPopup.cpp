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
 * wlShellSurfaceSetPopup.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlShellSurfaceSetPopup
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;IILjava/util/EnumSet;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlShellSurfaceSetPopup
  (JNIEnv *env, jobject, jobject JWlShellSurface, jobject JWlSeat, jint serialNumber, jobject JWlSurface, jint x, jint y , jobject jWlShellSurfaceTransientBehaviorEnumSet)
{
    struct wl_shell_surface *waylandShellSurfaceHandle = (struct wl_shell_surface *)jvulkan::getHandleValue(env, JWlShellSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, JWlSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    struct wl_surface *waylandSurfaceHandle = (struct wl_surface *)jvulkan::getHandleValue(env, JWlSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    int flags = jvulkan::getEnumSetValue(
            env,
			jWlShellSurfaceTransientBehaviorEnumSet,
            "com/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceTransientBehavior");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
        return;
    }

    wl_shell_surface_set_popup(waylandShellSurfaceHandle, waylandSeatHandle, serialNumber, waylandSurfaceHandle, x, y, flags);
}
