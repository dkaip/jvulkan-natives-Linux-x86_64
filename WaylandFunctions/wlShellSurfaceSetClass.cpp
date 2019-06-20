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
 * wlShellSurfaceSetClass.cpp
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
 * Method:    wlShellSurfaceSetClass
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlShellSurfaceSetClass
  (JNIEnv *env, jobject, jobject JWlShellSurface, jstring jClassName)
{
    struct wl_shell_surface *waylandShellSurfaceHandle = (struct wl_shell_surface *)jvulkan::getHandleValue(env, JWlShellSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    const char *className = nullptr;

    className = env->GetStringUTFChars(jClassName, 0);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling GetStringUTFChars.");
        return;
    }

    wl_shell_surface_set_class(waylandShellSurfaceHandle, className);

	env->ReleaseStringUTFChars(jClassName, className);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars.");
        return;
    }
}
