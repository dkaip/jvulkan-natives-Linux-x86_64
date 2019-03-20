#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlDisconnectDisplay
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlDisplay;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlDisconnectDisplay
  (JNIEnv *env, jobject, jobject jWlDisplay)
{
    struct wl_display *waylandDisplayHandle = (struct wl_display *)hwjvi::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
        return;
    }

    wl_display_disconnect(waylandDisplayHandle);
}

