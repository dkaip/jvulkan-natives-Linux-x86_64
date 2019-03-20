#include <iostream>
#include <mutex>

#include <wayland-client.h>

using namespace std;

#include "../headers/com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies.h"
#include "../headers/HelperFunctions.hh"

// TODO these may need to get cleaned up if the registry is destroyed
static jobject savedUserData;
static jobject savedCallbackObject;
static std::mutex g_CallbackInfoMutex;

static JavaVM *g_JavaVM;


static void globalRegistryAddAnnouncementCallback(
        void *userData,
        struct wl_registry *wl_registry,
        uint32_t name,
        const char *interface,
        uint32_t version)
{
    std::lock_guard<std::mutex> lock(g_CallbackInfoMutex);

    JNIEnv *localEnv;
    int envStatus = g_JavaVM->GetEnv((void **)&localEnv, JNI_VERSION_1_6);
    if (envStatus == JNI_EDETACHED)
    {
        if (g_JavaVM->AttachCurrentThread((void **)&localEnv, nullptr) != 0)
        {
            cout << "globalRegistryAddAnnouncementCallback: Failed to attach" << endl;
        }
    }
    else if (envStatus == JNI_OK)
    {
        ;
    }
    else if (envStatus == JNI_EVERSION)
    {
        cout << "globalRegistryAddAnnouncementCallback: JNI_VERSION_1_6 not supported." << endl;
        return;
    }

    jobject wlRegistryObject = hwjvi::createHandle(localEnv, "com/CIMthetics/hwjvi/Wayland/Handles/WlRegistry", wl_registry);

    jstring interfaceNameText = localEnv->NewStringUTF(interface);

    jclass javaClass = localEnv->GetObjectClass(savedCallbackObject);
    if (localEnv->ExceptionOccurred())
    {
        cout << "globalRegistryAddAnnouncementCallback: Error getting callback object class ... returning" << endl;
        return;
    }

    jmethodID callbackMethodId = localEnv->GetMethodID(
            javaClass,
            "registryAddEventHandler",
            "(Ljava/lang/Object;Lcom/CIMthetics/hwjvi/Wayland/Handles/WlRegistry;ILjava/lang/String;I)V");

    if (localEnv->ExceptionOccurred())
    {
        cout << "globalRegistryAddAnnouncementCallback: Error getting callback object class ... returning" << endl;
        return;
    }

    localEnv->CallVoidMethod(savedCallbackObject, callbackMethodId,
            savedUserData,
            wlRegistryObject,
            name,
            interfaceNameText,
            version);

    g_JavaVM->DetachCurrentThread();
}

static void globalRegistryRemovalAnnouncementCallback(
        void *userData,
        struct wl_registry *wl_registry,
        uint32_t name)
{
    std::lock_guard<std::mutex> lock(g_CallbackInfoMutex);

    JNIEnv *localEnv;
    int envStatus = g_JavaVM->GetEnv((void **)&localEnv, JNI_VERSION_1_6);
    if (envStatus == JNI_EDETACHED)
    {
        if (g_JavaVM->AttachCurrentThread((void **)&localEnv, nullptr) != 0)
        {
            cout << "globalRegistryAddAnnouncementCallback: Failed to attach" << endl;
        }
    }
    else if (envStatus == JNI_OK)
    {
        ;
    }
    else if (envStatus == JNI_EVERSION)
    {
        cout << "globalRegistryAddAnnouncementCallback: JNI_VERSION_1_6 not supported." << endl;
        return;
    }

    jobject wlRegistryObject = hwjvi::createHandle(localEnv, "com/CIMthetics/hwjvi/Wayland/Handles/WlRegistry", wl_registry);

    jclass javaClass = localEnv->GetObjectClass(savedCallbackObject);
    if (localEnv->ExceptionOccurred())
    {
        cout << "globalRegistryAddAnnouncementCallback: Error getting callback object class ... returning" << endl;
        return;
    }

    jmethodID callbackMethodId = localEnv->GetMethodID(
            javaClass,
            "registryRemoveEventHandler",
            "(Ljava/lang/Object;Lcom/CIMthetics/hwjvi/Wayland/Handles/WlRegistry;I)V");

    if (localEnv->ExceptionOccurred())
    {
        cout << "globalRegistryAddAnnouncementCallback: Error getting callback object class ... returning" << endl;
        return;
    }

    localEnv->CallVoidMethod(savedCallbackObject, callbackMethodId,
            savedUserData,
            wlRegistryObject,
            name);

    g_JavaVM->DetachCurrentThread();
}

static const struct wl_registry_listener registry_listener =
{
    globalRegistryAddAnnouncementCallback,
    globalRegistryRemovalAnnouncementCallback
};

/*
 * Class:     com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies
 * Method:    wlRegistryAddListener
 * Signature: (Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/WlRegistry;Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/WlRegistryListener;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_CIMthetics_hwjvi_VulkanCore_VK11_NativeProxies_wlRegistryAddListener
  (JNIEnv *env, jobject, jobject jWlRegistry, jobject jWlRegistryListener, jobject jUserData)
{
    if (g_JavaVM == nullptr)
    {
        jint returnValue = env->GetJavaVM(&g_JavaVM);
        if (returnValue < 0)
        {
            cout << "ERROR: Could not get a pointer to the JVM." << endl;
            // TODO need to throw an exception here.
            return;
        }
    }

    wl_registry *waylandRegistryHandle = (wl_registry *)hwjvi::getHandleValue(env, jWlRegistry);

    // Need to get a global ref because this will be used later in a callback.
    jobject callbackObject = env->NewGlobalRef(jWlRegistryListener);

//    cout << "Got callback object " << globalCallbackObject << endl;

    // Need to get a global ref because this will be used later in a callback.
    jobject userData = env->NewGlobalRef(jUserData);

    {
        std::lock_guard<std::mutex> lock(g_CallbackInfoMutex);

        if (savedCallbackObject != nullptr)
        {
            if (env->IsSameObject(callbackObject, savedCallbackObject) == false)
            {
                cout << "WARNING: There was a previous listener callback, it is being replaced by the new one." << endl;

                // Delete the previous global reference
                env->DeleteGlobalRef(savedCallbackObject);

                //Save the new callback in its place
                savedCallbackObject = callbackObject;
            }
        }
        else
        {
            savedCallbackObject = callbackObject;
        }

        if (savedUserData != nullptr)
        {
            if (env->IsSameObject(userData, savedUserData) == false)
            {
                cout << "WARNING: There was a previous callback user data, it is being replaced by the new one." << endl;

                // Delete the previous global reference
                env->DeleteGlobalRef(savedUserData);

                //Save the new callback in its place
                savedUserData = userData;
            }
        }
        else
        {
            savedUserData = userData;
        }
    }

    wl_registry_add_listener(waylandRegistryHandle, &registry_listener, 0);
}

