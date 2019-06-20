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
#include <cstring>

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

namespace jwayland
{
	jobject createWlOutputModeAsEnumSet(JNIEnv *env, int flags);
}

static void wloutputHandleGeometry(void *data, struct wl_output *wl_output, int32_t x, int32_t y, int32_t physicalWidth, int32_t physicalHeight,
		int subpixel, const char *make, const char *model, int transform)
{
    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "handleGeometry");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;IIIILcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputSubpixel;Ljava/lang/String;Ljava/lang/String;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputTransform;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

//    LOGERROR(env, "Subpixel is %d, transform is %d", subpixel, transform);
	jclass wlOutputSubpixelClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlOutputSubpixel");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlOutputSubpixel.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlOutputSubpixelClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputSubpixel;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputSubpixel;.");
		return;
	}

	jobject subpixelEnumObject = env->CallStaticObjectMethod(wlOutputSubpixelClass, methodId, subpixel);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

//    LOGERROR(env, "Subpixel is %d, transform is %d : %lx", subpixel, transform, subpixelEnumObject);
//
    jstring makeString = env->NewStringUTF(make);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling NewStringUTF.");
		return;
	}

	jstring modelString = env->NewStringUTF(model);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling NewStringUTF.");
		return;
	}

	jclass wlOutputTransformClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlOutputTransform");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlOutputTransform.");
		return;
	}

	methodId = env->GetStaticMethodID(wlOutputTransformClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputTransform;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlOutputTransform;.");
		return;
	}

	jobject transformEnumObject = env->CallStaticObjectMethod(wlOutputTransformClass, methodId, transform);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlOutput, x, y, physicalWidth, physicalHeight, subpixelEnumObject, makeString, modelString, transformEnumObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
       return;
    }

//    LOGERROR(env, "%s:%s", make, model);
    env->DeleteLocalRef(makeString);
    env->DeleteLocalRef(modelString);

//    LOGERROR(env, "JWO %lx", jwaylandEventObject);
    jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();
}

static void wloutputHandleMode(void *data, struct wl_output *wl_output, uint32_t flags, int32_t width, int32_t height, int32_t refresh)
{
    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "handleMode");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;Ljava/util/EnumSet;III)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject flagsEnumSetObject = jwayland::createWlOutputModeAsEnumSet(env, (int)flags);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createWlOutputModeAsEnumSet.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlOutput, flagsEnumSetObject, width, height, refresh);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
       return;
    }

//    LOGERROR(env, "JWO %lx", jwaylandEventObject);
	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();
}

static void wloutputHandleDone(void *data, struct wl_output *wl_output)
{
    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "handleDone");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlOutput);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
       return;
    }

//    LOGERROR(env, "JWO %lx", jwaylandEventObject);
	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();

}

static void wloutputHandleScale(void *data, struct wl_output *wl_output, int scaleFactor)
{
    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "handleScale");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlOutputEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlOutput = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", wl_output);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlOutput, scaleFactor);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
       return;
    }

//    LOGERROR(env, "JWO %lx", jwaylandEventObject);
	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();

}

static const wl_output_listener output_listener
{
	wloutputHandleGeometry,
	wloutputHandleMode,
	wloutputHandleDone,
	wloutputHandleScale
};


/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlRegistryBind
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlRegistry;ILjava/lang/String;I)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlRegistryBind
  (JNIEnv *env, jobject, jobject jWlRegistry, jint interfaceId, jstring jTextInterfaceName, jint interfaceVersion)
{
    wl_registry *waylandRegistryHandle = (wl_registry *)jvulkan::getHandleValue(env, jWlRegistry);

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
    	LOGERROR(env, "%s", "Surfaces are created using the WlCompositor interface.");
    	return nullptr;
//        interfacePointer = &wl_surface_interface;
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
    	LOGERROR(env, "Unhandled interface name of %s.", interfaceName);
        env->ReleaseStringUTFChars(jTextInterfaceName, interfaceName);
        return nullptr;
    }

    LOGERROR(env, "Attempting to bind interface %s.", interfaceName);
    void *result = wl_registry_bind(
            (wl_registry *)waylandRegistryHandle,
            interfaceId,
            interfacePointer,
            interfaceVersion);

    jobject jInterfacePointer = nullptr;

    if (strcmp(interfaceName, "wl_display_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_registry_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_callback_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_compositor_interface") == 0)
    {
    	jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlCompositorHandle", result);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
           return nullptr;
        }
    }
    else if (strcmp(interfaceName, "wl_shm_pool_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_shm_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_buffer_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_data_offer_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_data_source_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_data_device_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_data_device_manager_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_shell_interface") == 0)
    {
    	jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlShellHandle", result);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
           return nullptr;
        }
    }
    else if (strcmp(interfaceName, "wl_shell_surface_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_surface_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_seat_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_pointer_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_keyboard_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_touch_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_output_interface") == 0)
    {
    	jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlOutputHandle", result);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
           return nullptr;
        }

    	wl_output_add_listener((struct wl_output *)result, &output_listener, nullptr);
        LOGERROR(env, "Attempting to add listener for interface %s. Pointer is %lx.", interfaceName, result);

    }
    else if (strcmp(interfaceName, "wl_region_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_subcompositor_interface") == 0)
    {
    }
    else if (strcmp(interfaceName, "wl_subsurface_interface") == 0)
    {
    }
    else
    {
    	LOGERROR(env, "Unhandled interface name of %s.", interfaceName);
        env->ReleaseStringUTFChars(jTextInterfaceName, interfaceName);
        return nullptr;
    }

    env->ReleaseStringUTFChars(jTextInterfaceName, interfaceName);

    if (jInterfacePointer == nullptr)
    {
    	jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VulkanHandle", result);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
           return nullptr;
        }
    }

    return jInterfacePointer;
}

