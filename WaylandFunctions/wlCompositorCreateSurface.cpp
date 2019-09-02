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

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;


static void wlSurfaceEnter(void *data, struct wl_surface *wl_surface, struct wl_output *wl_output)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "handleScale");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlSurfaceEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlSurfaceEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle", wl_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlSurface, jWlOutput, 0);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create wlSurfaceEnter event.");
       return;
    }

	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();

}

static void wlSurfaceLeave(void *data, struct wl_surface *wl_surface, struct wl_output *wl_output)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "handleScale");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlSurfaceEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlSurfaceEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle", wl_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlSurface, jWlOutput, 1);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create wlSurfaceLeave event.");
       return;
    }

	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();

}

static const wl_surface_listener surface_listener
{
	wlSurfaceEnter,
	wlSurfaceLeave
};


/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlCompositorCreateSurface
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlCompositor;)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlSurface;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlCompositorCreateSurface
  (JNIEnv *env, jobject, jobject jWlCompositor)
{
    struct wl_compositor *waylandCompositorHandle = (struct wl_compositor *)jvulkan::getHandleValue(env, jWlCompositor);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_surface *surface = wl_compositor_create_surface(waylandCompositorHandle);
    if (surface == nullptr)
    {
    	LOGERROR(env, "%s", "Error calling wl_compositor_create_surface.");
        return nullptr;
    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle", surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    wl_surface_add_listener(surface, &surface_listener, nullptr);

    return jInterfacePointer;
}

