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

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

static void wlshellsurfaceHandlePing(void *data, struct wl_shell_surface *wl_shell_surface, uint32_t serialNumber)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlshellsurfaceHandlePing");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlShellSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle", wl_shell_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlShellSurface, serialNumber);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create KEYMAP event.");
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

static void wlshellsurfaceHandleConfigure(void *data, struct wl_shell_surface *wl_shell_surface, uint32_t edges, int32_t width, int32_t height)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlshellsurfaceHandleConfigure");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceResize;II)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlShellSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle", wl_shell_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlShellSurfaceResizeClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceResize");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceResize.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlShellSurfaceResizeClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceResize;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlShellSurfaceResize;.");
		return;
	}

	jobject edgesEnumObject = env->CallStaticObjectMethod(wlShellSurfaceResizeClass, methodId, edges);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlShellSurface, edgesEnumObject, width, height);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create KEYMAP event.");
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

static void wlshellsurfaceHandlePopupDone(void *data, struct wl_shell_surface *wl_shell_surface)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlshellsurfaceHandlePopupDone");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlShellSurfaceEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlShellSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle", wl_shell_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlShellSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create KEYMAP event.");
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

static const wl_shell_surface_listener shell_surface_listener
{
	wlshellsurfaceHandlePing,
	wlshellsurfaceHandleConfigure,
	wlshellsurfaceHandlePopupDone
};
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlShellGetShellSurface
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlShell;Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlSurface;)Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlShellSurface;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlShellGetShellSurface
  (JNIEnv *env, jobject, jobject jWlShell, jobject jWlSurface)
{
    wl_shell *shellInterfaceHandle = (wl_shell *)jvulkan::getHandleValue(env, jWlShell);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    wl_surface *surfaceHandle = (wl_surface *)jvulkan::getHandleValue(env, jWlSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    wl_shell_surface *shellSurface = wl_shell_get_shell_surface(shellInterfaceHandle, surfaceHandle);

    jobject returnHandle = nullptr;
    if (shellSurface != nullptr)
    {
//    	LOGERROR(env, "%s", "Adding shell surface listener.");
    	wl_shell_surface_add_listener(shellSurface, &shell_surface_listener, nullptr);

        returnHandle = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellSurfaceHandle", shellSurface);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
            return nullptr;
        }
    }

    return returnHandle;
}

