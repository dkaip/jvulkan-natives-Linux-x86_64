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
 * wlSeatGetPointer.cpp
 *
 *  Created on: Jun 20, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

static void wlpointerHandleEnter(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, struct wl_surface *wl_surface, wl_fixed_t surface_x, wl_fixed_t surface_y)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleEnter");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;DD)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
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

    double doubleSurfaceX = wl_fixed_to_double(surface_x);
    double doubleSurfaceY = wl_fixed_to_double(surface_y);

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlPointer, serialNumber, jWlSurface, doubleSurfaceX, doubleSurfaceY);
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

static void wlpointerHandleLeave(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, struct wl_surface *wl_surface)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleEnter");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;ILcom/CIMthetics/jvulkan/Wayland/Handles/WlSurfaceHandle;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
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

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlPointer, serialNumber, jWlSurface);
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

static void wlpointerHandleMotion(void *data, struct wl_pointer *wl_pointer, uint32_t time, wl_fixed_t surface_x, wl_fixed_t surface_y)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleMotion");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;JDD)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    double doubleSurfaceX = wl_fixed_to_double(surface_x);
    double doubleSurfaceY = wl_fixed_to_double(surface_y);

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlPointer, (uint64_t)time, doubleSurfaceX, doubleSurfaceY);
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

static void wlpointerHandleButton(void *data, struct wl_pointer *wl_pointer, uint32_t serialNumber, uint32_t time, uint32_t button, uint32_t state)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleButton");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;IJILcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerButtonState;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlPointerButtonStateClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlPointerButtonState");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlPointerButtonState.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlPointerButtonStateClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerButtonState;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerButtonState;.");
		return;
	}

	jobject buttonStateEnumObject = env->CallStaticObjectMethod(wlPointerButtonStateClass, methodId, state);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlPointer, serialNumber, (uint64_t)time, button, buttonStateEnumObject);
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

static void wlpointerHandleAxis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axisType, wl_fixed_t value)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleAxis");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;JLcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;D)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlPointerAxisTypeClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlPointerAxisTypeClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;.");
		return;
	}

	jobject axisTypeEnumObject = env->CallStaticObjectMethod(wlPointerAxisTypeClass, methodId, axisType);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    double doubleValue = wl_fixed_to_double(value);

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlPointer, (uint64_t)time, axisTypeEnumObject, doubleValue);
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

static void wlpointerHandleFrame(void *data, struct wl_pointer *wl_pointer)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleFrame");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlPointer);
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

static void wlpointerHandleAxisSource(void *data, struct wl_pointer *wl_pointer, uint32_t axisSource)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleAxisSource");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisSource;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlPointerAxisSourceClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisSource");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisSource.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlPointerAxisSourceClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisSource;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisSource;.");
		return;
	}

	jobject axisSourceEnumObject = env->CallStaticObjectMethod(wlPointerAxisSourceClass, methodId, axisSource);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlPointer, axisSourceEnumObject);
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

static void wlpointerHandleAxisStop(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axisType)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleAxisStop");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;JLcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlPointerAxisTypeClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlPointerAxisTypeClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;.");
		return;
	}

	jobject axisTypeEnumObject = env->CallStaticObjectMethod(wlPointerAxisTypeClass, methodId, axisType);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlPointer, (uint64_t)time, axisTypeEnumObject);
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

static void wlpointerHandleAxisDiscrete(void *data, struct wl_pointer *wl_pointer, uint32_t axisType, int32_t discrete)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "wlpointerHandleAxisDiscrete");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlPointerEvents.");
       return;
    }

    jmethodID constructorMethodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlPointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", wl_pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

	jclass wlPointerAxisTypeClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType.");
		return;
	}

	jmethodID methodId = env->GetStaticMethodID(wlPointerAxisTypeClass, "fromValue", "(I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;");
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Could not find static method fromValue with signature (I)Lcom/CIMthetics/jvulkan/Wayland/Enums/WlPointerAxisType;.");
		return;
	}

	jobject axisTypeEnumObject = env->CallStaticObjectMethod(wlPointerAxisTypeClass, methodId, axisType);
	if (env->ExceptionOccurred())
	{
    	LOGERROR(env, "%s", "Error calling CallStaticObjectMethod.");
		return;
	}

    jobject jwaylandEventObject = env->NewObject(javaClass, constructorMethodId, jWlPointer, axisTypeEnumObject, discrete);
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

static const wl_pointer_listener pointer_listener
{
	wlpointerHandleEnter,
	wlpointerHandleLeave,
	wlpointerHandleMotion,
	wlpointerHandleButton,
	wlpointerHandleAxis,
	wlpointerHandleFrame,
	wlpointerHandleAxisSource,
	wlpointerHandleAxisStop,
	wlpointerHandleAxisDiscrete
};
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlSeatGetPointer
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Objects/WlSeatHandle;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlSeatGetPointer
  (JNIEnv *env, jobject, jobject jWLSeat)
{
    struct wl_seat *waylandSeatHandle = (struct wl_seat *)jvulkan::getHandleValue(env, jWLSeat);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_pointer *pointer = wl_seat_get_pointer(waylandSeatHandle);
    if (pointer != nullptr)
    {
    	wl_pointer_add_listener(pointer, &pointer_listener, nullptr);
    }
//    if (pointer == nullptr)
//    {
//    	LOGERROR(env, "%s", "Error calling wl_seat_get_pointer.");
//        return nullptr;
//    }

    jobject jInterfacePointer = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlPointerHandle", pointer);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jInterfacePointer;
}

