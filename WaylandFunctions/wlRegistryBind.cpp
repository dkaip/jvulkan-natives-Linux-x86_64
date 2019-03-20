#include <iostream>
#include <cstring>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlRegistryBind
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlRegistry;ILjava/lang/String;I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VulkanHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlRegistryBind
  (JNIEnv *env, jobject, jobject jWlRegistry, jint interfaceId, jstring jTextInterfaceName, jint interfaceVersion)
{
    wl_registry *waylandRegistryHandle = (wl_registry *)hwjvi::getHandleValue(env, jWlRegistry);

    const char *interfaceName = nullptr;

    if (jTextInterfaceName == nullptr)
    {
        cout << "ERROR the interface name must not be null." << endl;
        return nullptr;
    }

    interfaceName = env->GetStringUTFChars(jTextInterfaceName, 0);

    const struct wl_interface *interfacePointer = nullptr;

    if (strcmp(interfaceName, "wl_display_interface") == 0)
    {
        interfacePointer = &wl_display_interface;
    }
    else if (strcmp(interfaceName, "wl_registry_interface") == 0)
    {
        interfacePointer = &wl_registry_interface;
    }
    else if (strcmp(interfaceName, "wl_callback_interface") == 0)
    {
        interfacePointer = &wl_callback_interface;
    }
    else if (strcmp(interfaceName, "wl_compositor_interface") == 0)
    {
        interfacePointer = &wl_compositor_interface;
    }
    else if (strcmp(interfaceName, "wl_shm_pool_interface") == 0)
    {
        interfacePointer = &wl_shm_pool_interface;
    }
    else if (strcmp(interfaceName, "wl_shm_interface") == 0)
    {
        interfacePointer = &wl_shm_interface;
    }
    else if (strcmp(interfaceName, "wl_buffer_interface") == 0)
    {
        interfacePointer = &wl_buffer_interface;
    }
    else if (strcmp(interfaceName, "wl_data_offer_interface") == 0)
    {
        interfacePointer = &wl_data_offer_interface;
    }
    else if (strcmp(interfaceName, "wl_data_source_interface") == 0)
    {
        interfacePointer = &wl_data_source_interface;
    }
    else if (strcmp(interfaceName, "wl_data_device_interface") == 0)
    {
        interfacePointer = &wl_data_device_interface;
    }
    else if (strcmp(interfaceName, "wl_data_device_manager_interface") == 0)
    {
        interfacePointer = &wl_data_device_manager_interface;
    }
    else if (strcmp(interfaceName, "wl_shell_interface") == 0)
    {
        interfacePointer = &wl_shell_interface;
    }
    else if (strcmp(interfaceName, "wl_shell_surface_interface") == 0)
    {
        interfacePointer = &wl_shell_surface_interface;
    }
    else if (strcmp(interfaceName, "wl_surface_interface") == 0)
    {
        interfacePointer = &wl_surface_interface;
    }
    else if (strcmp(interfaceName, "wl_seat_interface") == 0)
    {
        interfacePointer = &wl_seat_interface;
    }
    else if (strcmp(interfaceName, "wl_pointer_interface") == 0)
    {
        interfacePointer = &wl_pointer_interface;
    }
    else if (strcmp(interfaceName, "wl_keyboard_interface") == 0)
    {
        interfacePointer = &wl_keyboard_interface;
    }
    else if (strcmp(interfaceName, "wl_touch_interface") == 0)
    {
        interfacePointer = &wl_touch_interface;
    }
    else if (strcmp(interfaceName, "wl_output_interface") == 0)
    {
        interfacePointer = &wl_output_interface;
    }
    else if (strcmp(interfaceName, "wl_region_interface") == 0)
    {
        interfacePointer = &wl_region_interface;
    }
    else if (strcmp(interfaceName, "wl_subcompositor_interface") == 0)
    {
        interfacePointer = &wl_subcompositor_interface;
    }
    else if (strcmp(interfaceName, "wl_subsurface_interface") == 0)
    {
        interfacePointer = &wl_subsurface_interface;
    }
    else
    {
        cout << "File:" << __FILE__ << " Line:" << __LINE__ << " ERROR: unhandled interface name of " << interfaceName << "." << endl;
        env->ReleaseStringUTFChars(jTextInterfaceName, interfaceName);
        return nullptr;
    }

    env->ReleaseStringUTFChars(jTextInterfaceName, interfaceName);

    void *result = wl_registry_bind(
            (wl_registry *)waylandRegistryHandle,
            interfaceId,
            interfacePointer,
            interfaceVersion);

    jobject jInterfacePointer = hwjvi::createHandle(env, "com/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VulkanHandle", result);

    return jInterfacePointer;
}

