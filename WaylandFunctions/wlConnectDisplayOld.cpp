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

#include "com_CIMthetics_jvulkan_VulkanCore_NativeProxies.h"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_NativeProxies
 * Method:    wlConnectDisplay
 * Signature: (Ljava/lang/String;)Lcom/CIMthetics/jvulkan/VulkanExtensions/Handles/WlDisplay;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_NativeProxies_wlConnectDisplay
  (JNIEnv *env, jobject, jstring jDisplayName)
{
    const char *displayName = nullptr;

    if (jDisplayName != nullptr)
    {
        displayName = env->GetStringUTFChars(jDisplayName, 0);
    }

    struct wl_display *display = nullptr;

    display = wl_display_connect(displayName);

    if (jDisplayName != nullptr)
    {
        env->ReleaseStringUTFChars(jDisplayName, displayName);
    }

    /*
     * Now transfer the WlDisplay data to Java
     */
    jclass javaClass = env->FindClass("com/CIMthetics/jvulkan/Wayland/Handles/WlDisplay");
    if (env->ExceptionOccurred())
    {
       return nullptr;
    }

    jmethodID methodId = env->GetMethodID(javaClass, "<init>", "()V");
    if (env->ExceptionOccurred())
    {
       return nullptr;
    }

    jobject jWlDisplay = env->NewObject(javaClass, methodId);
    if (env->ExceptionOccurred())
    {
       return nullptr;
    }

    methodId = env->GetMethodID(javaClass, "setHandle", "(J)V");
    if (env->ExceptionOccurred())
    {
       return nullptr;
    }

    env->CallVoidMethod(jWlDisplay, methodId, display);
    if (env->ExceptionOccurred())
    {
       return nullptr;
    }

    return jWlDisplay;
}

