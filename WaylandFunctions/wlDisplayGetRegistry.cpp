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

#include <wayland-client.h>

using namespace std;

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern JavaVM *l_JavaVM;

extern jobject globalWaylandEventQueueObject;

static void handleGlobalAnnounce(void *data, struct wl_registry *wl_registry, uint32_t objectName, const char *interfaceName, uint32_t interfaceVersion)
{
//	cerr << "handleGlobalAnnounce" << endl;
    JNIEnv *env = jvulkan::getJNIEnv();
//	LOGTRACE(env, "%s", "handleGlobalAnnounce");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlRegistryEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlRegistryEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlRegistryHandle;ILjava/lang/String;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlRegistry = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlRegistryHandle", wl_registry);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jstring interfaceNameString = env->NewStringUTF(interfaceName);

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlRegistry, objectName, interfaceNameString, interfaceVersion);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create error event.");
       return;
    }

    env->DeleteLocalRef(interfaceNameString);

//    LOGERROR(env, "LBQ:%lx:%lx", globalWaylandEventQueueObject, jwaylandEventObject);
	jvulkan::putOnLinkedBlockingQueue(env, globalWaylandEventQueueObject, jwaylandEventObject);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling putOnLinkedBlockingQueue.");
       return;
    }

	// This is important, don't forget to do it.
    l_JavaVM->DetachCurrentThread();
}

static void handleGlobalRemove(void *data, struct wl_registry *wl_registry, uint32_t interfaceName)
{
    JNIEnv *env = jvulkan::getJNIEnv();
	LOGTRACE(env, "%s", "handleGlobalRemove");
    if (env == nullptr)
    {
    	LOGERROR(env, "%s", "Failed trying to get JNI environment.");
    	return;
    }

    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Objects/WlRegistryEvents");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find class com/CIMthetics/jvulkan/Wayland/Objects/WlRegistryEvents.");
       return;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "(Lcom/CIMthetics/jvulkan/Wayland/Handles/WlRegistryHandle;I)V");
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to find constructor.");
       return;
    }

    jobject jWlDisplay = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlRegistryHandle", wl_registry);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
       return;
    }

    jobject jwaylandEventObject = env->NewObject(javaClass, methodId, jWlDisplay, interfaceName);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Failed trying to create delete id event.");
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

static const wl_registry_listener registry_listener
{
	handleGlobalAnnounce,
	handleGlobalRemove
};

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    wlDisplayGetRegistry
 * Signature: (Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlDisplay;)Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/WlRegistry;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_wlDisplayGetRegistry
  (JNIEnv *env , jobject, jobject jWlDisplay)
{
    wl_display *waylandDisplayHandle = (wl_display *)jvulkan::getHandleValue(env, jWlDisplay);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling getHandleValue.");
        return nullptr;
    }

    struct wl_registry *registry = wl_display_get_registry(waylandDisplayHandle);

    /*
     * Now transfer the WlDisplay data to Java
     */
    jobject jWlRegistry = jvulkan::createVulkanHandle(env, "com/CIMthetics/jvulkan/Wayland/Handles/WlRegistryHandle", registry);
    if (env->ExceptionOccurred())
    {
    	LOGERROR(env, "%s", "Error calling createVulkanHandle.");
        return nullptr;
    }

//    (void)wl_registry_add_listener(registry, &registry_listener, nullptr);

//    int count = wl_display_flush(waylandDisplayHandle);
//    LOGDEBUG(env, "A%d", count);
//    count = wl_display_dispatch(waylandDisplayHandle);
//    LOGDEBUG(env, "B%d", count);
//    count = wl_display_roundtrip(waylandDisplayHandle);
//    LOGDEBUG(env, "C%d", count);

    (void)wl_registry_add_listener(registry, &registry_listener, nullptr);

//	int count = wl_display_flush(waylandDisplayHandle);
//	LOGDEBUG(env, "D%d", count);
//	count = wl_display_dispatch(waylandDisplayHandle);
//	LOGDEBUG(env, "E%d", count);
//	count = wl_display_roundtrip(waylandDisplayHandle);
//	LOGDEBUG(env, "F%d", count);
//
    return jWlRegistry;
}

