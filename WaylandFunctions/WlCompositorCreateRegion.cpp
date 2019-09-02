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
 * WlCompositorCreateRegion.cpp
 *
 *  Created on: Jun 18, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlCompositorCreateRegion
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlCompositorHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlRegionHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlCompositorCreateRegion
(JNIEnv *env, jobject, jobject jWlCompositor)
{
    struct wl_compositor *waylandCompositorHandle = (struct wl_compositor *)jvulkan::getHandleValue(env, jWlCompositor);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_region *region = wl_compositor_create_region(waylandCompositorHandle);
    if (region == nullptr)
    {
    	LOGERROR(env, "%s", "Error calling wl_compositor_create_region.");
        return nullptr;
    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlRegionHandle", region);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jInterfacePointer;
}

