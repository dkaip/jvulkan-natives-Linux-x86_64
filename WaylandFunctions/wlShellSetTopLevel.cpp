#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlShellSetTopLevel
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlShellSurface;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlShellSetTopLevel
  (JNIEnv *env, jobject, jobject jWlShellSurface)
{
    wl_shell_surface *shellSurfaceHandle = (wl_shell_surface *)hwjvi::getHandleValue(env, jWlShellSurface);
    if (env->ExceptionOccurred())
    {
        return;
    }

    wl_shell_surface_set_toplevel(shellSurfaceHandle);
}

