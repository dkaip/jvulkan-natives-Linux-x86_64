/*
 * Copyright 2019-2020 Douglas Kaip
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
 * wlDisplayConnect.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: Douglas Kaip
 */

#include <wayland-client.h>

#include "JVulkanHelperFunctions.hh"
#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"
#include "slf4j.hh"


using namespace std;

extern JavaVM *l_JavaVM;
extern std::mutex l_JavaVM_Mutex;

jobject globalWaylandEventQueueObject;
//
//static void handleError(void *data, struct wl_display *wl_display, void *object_id, uint32_t code, const char *message)
//{
//    JNIEnv *env = jvulkan::getJNIEnv();
//    if (env == nullptr)
//    {
//    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
//    	return;
//    }
//
//    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Events/WlDisplayEvents");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Events/WlDisplayEvents.");
//       return;
//    }
//
//    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/WlDisplayHandle;Lcom/CIMthetics/jvulkan/VulkanCore/Handles/VulkanHandle;ILjava/lang/String;)V");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find constructor.");
//       return;
//    }
//
//    jobject jWlDisplay = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle", wl_display);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
//       return;
//    }
//
//    jobject jWObject = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/VulkanHandle", object_id);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
//       return;
//    }
//
//    jstring messageString = env->NewStringUTF(message);
//
//    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlDisplay, jWObject, code, messageString);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to create error event.");
//       return;
//    }
//
//    env->DeleteLocalRef(messageString);
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
//static void handleDeleteId(void *data, struct wl_display *wl_display, uint32_t id)
//{
//    JNIEnv *env = jvulkan::getJNIEnv();
//    if (env == nullptr)
//    {
//    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
//    	return;
//    }
//
//    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Events/WlDisplayEvents");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Events/WlDisplayEvents.");
//       return;
//    }
//
//    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/VulkanCore/Handles/WlDisplayHandle;I)V");
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to find constructor.");
//       return;
//    }
//
//    jobject jWlDisplay = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlDisplay", wl_display);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
//       return;
//    }
//
//    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlDisplay, id);
//    if (env->ExceptionOccurred())
//    {
//    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
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
//
//}
//
//static const wl_display_listener display_listener
//{
//	handleError,
//	handleDeleteId
//};
//
/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlDisplayConnect
 * Signature: (Ljava/lang/String;Ljava/util/concurrent/LinkedBlockingQueue;)Lcom/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlDisplayConnect
  (JNIEnv *env, jobject, jstring jDisplayName, jobject jWaylandEventQueueObject)
{
	LOGTRACE(env, "%s", "wlDisplayConnect called"); // This line is mainly here so that the logging stuff gets initialized before any errors.

    {
    	/*
    	 * Lock the Mutex for the l_JavaVM variable.  It should only be
    	 * needed here since once set the variable should not change
    	 * for the duration of the program's execution.
    	 */
        std::lock_guard<std::mutex> lock(l_JavaVM_Mutex);
		if (l_JavaVM == nullptr)
		{
			jint returnValue = env->GetJavaVM(&l_JavaVM);
			if (returnValue < 0)
			{
				LOGERROR(env, "%s", "Could not get pointer to the JVM");
				// TODO need to throw an exception here.
				return nullptr;
			}
		}
    }

    // Need to get a global ref because this will be used later in a callback.
    globalWaylandEventQueueObject = reinterpret_cast<jobject>(env->NewGlobalRef(jWaylandEventQueueObject));
//    LOGDEBUG(env, "jobject globalWaylandEventQueueObject initialized to:%lx", globalWaylandEventQueueObject);

    const char *displayName = nullptr;

    if (jDisplayName != nullptr)
    {
        displayName = env->GetStringUTFChars(jDisplayName, 0);
    }

    LOGDEBUG(env, "Attemping to connect to Wayland Display Server:%s", displayName);

    struct wl_display *display = nullptr;

    display = wl_display_connect(displayName);

    if (jDisplayName != nullptr)
    {
        env->ReleaseStringUTFChars(jDisplayName, displayName);
    }

//    LOGDEBUG(env, "wl_display proxy:%lx", display);
//
//    (void)wl_display_add_listener(display, &display_listener, nullptr);

//    LOGINFO(env, "Display handle is:%lx", display);
    /*
     * Now transfer the WlDisplay data to Java
     */
    jobject jDisplay = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlDisplayHandle", display);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

    return jDisplay;
}




