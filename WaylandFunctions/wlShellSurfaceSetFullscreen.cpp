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
 * wlShellSurfaceSetFullscreen.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"

using namespace std;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlShellSurfaceSetFullscreen
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceFullscreenMethod;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlShellSurfaceSetFullscreen
  (JNIEnv *env, jobject, jobject JWlShellSurface, jobject jWlShellSurfaceFullscreenMethod, jint framerate, jobject jWlOutput)
{
    struct wl_shell_surface *waylandShellSurfaceHandle = (struct wl_shell_surface *)jvulkan::getHandleValue(env, JWlShellSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    struct wl_output *waylandOutputHandle = nullptr;
    if(jWlOutput != nullptr)
    {
    	waylandOutputHandle = (struct wl_output *)jvulkan::getHandleValue(env, jWlOutput);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Error calling getHandleValue.");
			return;
		}
    }

    jclass theClass = env->GetObjectClass(jWlShellSurfaceFullscreenMethod);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error getting class for jWlShellSurfaceFullscreenMethod.");
        return;
    }

    jmethodID methodId = env->GetMethodID(theClass, "valueOf", "()I");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Could not get method id for valueOf.");
        return;
    }

    jint method = env->CallIntMethod(jWlShellSurfaceFullscreenMethod, methodId);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling CallIntMethod.");
        return;
    }

    wl_shell_surface_set_fullscreen(waylandShellSurfaceHandle, method, framerate, waylandOutputHandle);
}
