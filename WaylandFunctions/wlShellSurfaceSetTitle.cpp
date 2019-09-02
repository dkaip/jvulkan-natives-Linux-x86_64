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
 * wlShellSurfaceSetTitle.cpp
 *
 *  Created on: Jun 19, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "slf4j.hh"

using namespace std;

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlShellSurfaceSetTitle
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;[B)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlShellSurfaceSetTitle
  (JNIEnv *env, jobject, jobject JWlShellSurface, jbyteArray jWindowTitle)
{
    struct wl_shell_surface *waylandShellSurfaceHandle = (struct wl_shell_surface *)jvulkan::getHandleValue(env, JWlShellSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    char *windowTitle = nullptr;
    jsize arrayLength = 0;

	arrayLength = env->GetArrayLength(jWindowTitle);
	arrayLength++; // for null terminator

	windowTitle = (char *)calloc(arrayLength, sizeof(char));

	env->GetByteArrayRegion(jWindowTitle, 0, arrayLength - 1, (signed char *)windowTitle);
	if (env->ExceptionOccurred())
	{
		LOGERROR(env, "%s", "Error trying to get GetByteArrayRegion for tag");
		return;
	}

	wl_shell_surface_set_title(waylandShellSurfaceHandle, windowTitle);

	free(windowTitle);
}
