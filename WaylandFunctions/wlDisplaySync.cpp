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
 * wlDisplaySync.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"

using namespace std;

//extern JavaVM *l_JavaVM;
//
//extern jobject globalWaylandEventQueueObject;
//
//static void handleDone(void *data, struct wl_callback *wl_callback, uint32_t callbackData)
//{
//    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "HandleDone");
//    if (env == nullptr)
//    {
//    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
//    	return;
//    }
//
//    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Events/WlCallbackEvents");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Events/WlCallbackEvents.");
//       return;
//    }
//
//    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/WlCallbackHandle;)V");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find constructor.");
//       return;
//    }
//
//    jobject jWlCallback = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlCallbackHandle", wl_callback);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
//       return;
//    }
//
//    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlCallback);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to create error event.");
//       return;
//    }
//
//	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
//       return;
//    }
//
//	// This is important, don't forget to do it.
//    l_JavaVM->DetachCurrentThread();
//}
//
//
//static const wl_callback_listener callback_listener
//{
//	handleDone
//};
//
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlDisplaySync
 * Signature: (Lcom/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlDisplaySync
  (JNIEnv *env, jobject, jobject jWlDisplay)
{
    wl_display *waylandDisplayHandle = (wl_display *)jvulkan::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return;
    }

    wl_display_roundtrip(waylandDisplayHandle);
}

