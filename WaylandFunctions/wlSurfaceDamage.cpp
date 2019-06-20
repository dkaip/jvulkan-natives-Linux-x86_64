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
 * wlSurfaceDamage.cpp
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
 * Method:    wlSurfaceDamage
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;IIII)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlSurfaceDamage
  (JNIEnv *env, jobject, jobject jWlSurface, jint x, jint y, jint width, jint height)
{
    struct wl_surface *waylandSurfaceHandle = (struct wl_surface *)jvulkan::getHandleValue(env, jWlSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    wl_surface_damage(waylandSurfaceHandle, x, y, width, height);
}
