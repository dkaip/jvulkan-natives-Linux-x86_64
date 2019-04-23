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
 * Method:    wlShellGetShellSurface
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlShell;Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlSurface;)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlShellSurface;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlShellGetShellSurface
  (JNIEnv *env, jobject, jobject jWlShell, jobject jWlSurface)
{
    wl_shell *shellInterfaceHandle = (wl_shell *)jvulkan::getHandleValue(env, jWlShell);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    wl_surface *surfaceHandle = (wl_surface *)jvulkan::getHandleValue(env, jWlSurface);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    wl_shell_surface *shellSurface = wl_shell_get_shell_surface(shellInterfaceHandle, surfaceHandle);

    jobject returnHandle = nullptr;
    if (shellSurface != nullptr)
    {
        returnHandle = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellSurface", shellSurface);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }
    }

    return returnHandle;
}

