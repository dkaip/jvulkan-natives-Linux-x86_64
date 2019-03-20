#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlDisplayGetRegistry
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlDisplay;)Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlRegistry;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlDisplayGetRegistry
  (JNIEnv *env , jobject, jobject jWlDisplay)
{
    wl_display *waylandDisplayHandle = (wl_display *)hwjvi::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
        return nullptr;
    }

    struct wl_registry *registry = wl_display_get_registry(waylandDisplayHandle);

    /*
     * Now transfer the WlDisplay data to Java
     */
    jobject jWlRegistry = hwjvi::createHandle(env, "com/CIMthetics/hwjvi/Wayland/Handles/WlRegistry", registry);

    return jWlRegistry;
}

