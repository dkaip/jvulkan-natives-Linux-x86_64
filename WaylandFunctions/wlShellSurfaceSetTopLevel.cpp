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
#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlShellSurfaceSetTopLevel
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlShellSurface;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlShellSurfaceSetTopLevel
  (JNIEnv *env, jobject, jobject jWlShellSurface)
{
    wl_shell_surface *shellSurfaceHandle = (wl_shell_surface *)jvulkan::getHandleValue(env, jWlShellSurface);
    if (env->ExceptionOccurred())
    {
        return;
    }

    wl_shell_surface_set_toplevel(shellSurfaceHandle);
}

