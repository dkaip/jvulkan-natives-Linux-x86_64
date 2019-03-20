#include <iostream>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlConnectDisplay
 * Signature: (Ljava/lang/String;)Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlDisplay;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlConnectDisplay
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
    jclass javaClass = env->FindClass("com/CIMthetics/hwjvi/Wayland/Handles/WlDisplay");
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

