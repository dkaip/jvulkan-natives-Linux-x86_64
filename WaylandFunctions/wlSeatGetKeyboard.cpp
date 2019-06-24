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
 * wlSeatGetKeyboard.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include <unistd.h>
#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "HelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

static void wlkeyboardHandleKeymap(void *data, struct wl_keyboard *wl_keyboard, uint32_t format, int fd, uint32_t size)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleKeymap");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

//    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat;II)V");
    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat;[B)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlKeyboardKeymapFormatClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlKeyboardKeymapFormatClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeymapFormat;.");
		return;
	}

	jobject keymapFormatEnumObject = env->CallStaticObjectMethod(wlKeyboardKeymapFormatClass, methodId, format);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

	char *keyMap = (char *)calloc(1, size);
	if (keyMap == nullptr)
	{
		LOGERROR(env, "Error trying to allocate %d bytes for keyMap data.", size);
		return;
	}

	ssize_t bytesRead = read(fd, keyMap, size);
	if (bytesRead != size)
	{
		LOGERROR(env, "An incorrect number of bytes(%d) have been read, should have read %d bytes.", bytesRead, size);
		close(fd);
		return;
	}

	close(fd);

    jbyteArray jKeyMap = env->NewByteArray(size);
    if (jKeyMap == 0)
    {
    	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for jKeyMap");
        return;
    }

    env->SetByteArrayRegion(jKeyMap, 0, size, (const signed char *)keyMap);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
        return;
    }

//    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlKeyboard, keymapFormatEnumObject, fd, size);
    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlKeyboard, keymapFormatEnumObject, jKeyMap);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create KEYMAP event.");
       return;
    }

    free(keyMap);

	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();
}

static void wlkeyboardHandleEnter(void *data, struct wl_keyboard *wl_keyboard, uint32_t serialNumber, struct wl_surface *wl_surface, struct wl_array *keys)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleEnter");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;[B)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jWlSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle", wl_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jbyteArray keysPressed = env->NewByteArray(keys->size);
    if (keysPressed == 0)
    {
    	LOGERROR(env, "%s", "ERROR: out of memory trying to allocate array for keysPressed");
        return;
    }

    env->SetByteArrayRegion(keysPressed, 0, keys->size, (const jbyte *)keys->data);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling SetByteArrayRegion");
        return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlKeyboard, serialNumber, jWlSurface, keysPressed);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create ENTER event.");
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

static void wlkeyboardHandleLeave(void *data, struct wl_keyboard *wl_keyboard, uint32_t serialNumber, struct wl_surface *wl_surface)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleLeave");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jWlSurface = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle", wl_surface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlKeyboard, serialNumber, jWlSurface);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create LEAVE event.");
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

static void wlkeyboardHandleKey(void *data, struct wl_keyboard *wl_keyboard, uint32_t serialNumber, uint32_t time, uint32_t key, uint32_t state)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleKey");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;IJILcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeyState;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlKeyboardKeyStateClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeyState");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeyState.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlKeyboardKeyStateClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeyState;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlKeyboardKeyState;.");
		return;
	}

	jobject keyboardKeyStateEnumObject = env->CallStaticObjectMethod(wlKeyboardKeyStateClass, methodId, state);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlKeyboard, serialNumber, (uint64_t)time, key, keyboardKeyStateEnumObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create KEY event.");
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

static void wlkeyboardHandleModifiers(void *data, struct wl_keyboard *wl_keyboard, uint32_t serialNumber, uint32_t modsDepressed, uint32_t modsLatched, uint32_t modsLocked, uint32_t group)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleModifiers");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;IIIII)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlKeyboard, serialNumber, modsDepressed, modsLatched, modsLocked, group);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create MODIFIERS event.");
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

static void wlkeyboardHandleRepeatInfo(void *data, struct wl_keyboard *wl_keyboard, int32_t rate, int32_t delay)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlkeyboardHandleRepeatInfo");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlKeyboardEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;II)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlKeyboard = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", wl_keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlKeyboard, rate, delay);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create REPEAT_INFO event.");
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


static const wl_keyboard_listener keyboard_listener
{
	wlkeyboardHandleKeymap,
	wlkeyboardHandleEnter,
	wlkeyboardHandleLeave,
	wlkeyboardHandleKey,
	wlkeyboardHandleModifiers,
	wlkeyboardHandleRepeatInfo

};

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlSeatGetKeyboard
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlSeatGetKeyboard
  (JNIEnv *env, jobject, jobject jWLSeat)
{
    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, jWLSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_keyboard *keyboard = wl_seat_get_keyboard(waylandSeatHandle);
    if (keyboard != nullptr)
    {
    	wl_keyboard_add_listener(keyboard, &keyboard_listener, nullptr);
    }
//    if (keyboard == nullptr)
//    {
//    	LOGERROR(env, "%s", "Error calling wl_seat_get_keyboard.");
//        return nullptr;
//    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlKeyboardHandle", keyboard);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jInterfacePointer;
}

