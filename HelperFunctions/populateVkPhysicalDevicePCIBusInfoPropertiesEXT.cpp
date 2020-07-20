/*
 * populateVkPhysicalDevicePCIBusInfoPropertiesEXT.cpp
 *
 *  Created on: May 15, 2019
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

extern const char *voidMethodErrorText;

namespace jvulkan
{
	void populateVkPhysicalDevicePCIBusInfoPropertiesEXT(
		JNIEnv *env,
		jobject jVkPhysicalDevicePCIBusInfoPropertiesEXTObject,
		const VkPhysicalDevicePCIBusInfoPropertiesEXT *vkPhysicalDevicePCIBusInfoPropertiesEXT,
		std::vector<void *> *memoryToFree)
	{
		jboolean handlingException = env->ExceptionCheck();
		if (handlingException == true)
		{
			LOGWARN(env, "%s", "handlingException was already true...clearing");
			env->ExceptionClear();
		}

		jclass theClass = env->GetObjectClass(
				jVkPhysicalDevicePCIBusInfoPropertiesEXTObject);
		if (env->ExceptionOccurred())
		{
			LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanExtensions/Structures/VkPhysicalDevicePCIBusInfoPropertiesEXT");
			return;
		}

        ///////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(theClass, "setPciDomain", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPciDomain");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePCIBusInfoPropertiesEXTObject, methodId, vkPhysicalDevicePCIBusInfoPropertiesEXT->pciDomain);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPciBus", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPciBus");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePCIBusInfoPropertiesEXTObject, methodId, vkPhysicalDevicePCIBusInfoPropertiesEXT->pciBus);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPciDevice", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPciDevice");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePCIBusInfoPropertiesEXTObject, methodId, vkPhysicalDevicePCIBusInfoPropertiesEXT->pciDevice);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }

        ///////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(theClass, "setPciFunction", "(I)V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id setPciFunction");
            return;
        }

        env->CallVoidMethod(jVkPhysicalDevicePCIBusInfoPropertiesEXTObject, methodId, vkPhysicalDevicePCIBusInfoPropertiesEXT->pciFunction);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", voidMethodErrorText);
            return;
        }
	}
}
