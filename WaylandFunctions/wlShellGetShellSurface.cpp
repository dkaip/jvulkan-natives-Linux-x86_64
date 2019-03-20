#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlShellGetShellSurface
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlShell;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlSurface;)Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlShellSurface;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlShellGetShellSurface
  (JNIEnv *env, jobject, jobject jWlShell, jobject jWlSurface)
{
    wl_shell *shellInterfaceHandle = (wl_shell *)hwjvi::getHandleValue(env, jWlShell);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    wl_surface *surfaceHandle = (wl_surface *)hwjvi::getHandleValue(env, jWlSurface);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    wl_shell_surface *shellSurface = wl_shell_get_shell_surface(shellInterfaceHandle, surfaceHandle);

    jobject returnHandle = nullptr;
    if (shellSurface != nullptr)
    {
        returnHandle = hwjvi::createHandle(env, "com/CIMthetics/hwjvi/Wayland/Handles/WlShellSurface", shellSurface);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }
    }

    return returnHandle;
}

