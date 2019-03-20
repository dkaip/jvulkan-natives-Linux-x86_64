#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlCompositorCreateSurface
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlCompositor;)Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlSurface;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlCompositorCreateSurface
  (JNIEnv *env, jobject, jobject jWlCompositor)
{
    struct wl_compositor *waylandCompositorHandle = (struct wl_compositor *)hwjvi::getHandleValue(env, jWlCompositor);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    struct wl_surface *surface = wl_compositor_create_surface(waylandCompositorHandle);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    jobject jInterfacePointer = hwjvi::createHandle(env, "com/CIMthetics/hwjvi/Wayland/Handles/WlSurface", surface);

    return jInterfacePointer;
}

