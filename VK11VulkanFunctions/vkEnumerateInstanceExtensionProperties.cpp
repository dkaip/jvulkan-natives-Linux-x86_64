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
 * vkEnumerateInstanceExtensionProperties.cpp
 *
 *  Created on: Oct 27, 2019
 *      Author: Douglas Kaip
 */

#include <vector>

#include "com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies.h"
#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

/*
 * Class:     com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies
 * Method:    vkEnumerateInstanceExtensionProperties
 * Signature: (Ljava/lang/String;Ljava/util/Collection;)Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkResult;
 */
JNIEXPORT jobject JNICALL Java_com_CIMthetics_jvulkan_VulkanCore_VK11_NativeProxies_vkEnumerateInstanceExtensionProperties
  (JNIEnv *env, jobject, jstring jLayerName, jobject jVkExtensionPropertiesCollection)
{
    const char *layerName = nullptr;
    if (jLayerName != nullptr)
    {
        layerName = env->GetStringUTFChars(jLayerName, 0);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Call to GetStringUTFChars failed.");
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }
    }

    uint32_t propertyCount = 0;

    VkResult result = vkEnumerateInstanceExtensionProperties(
    		layerName,
			&propertyCount,
			nullptr);

    if (result != VK_SUCCESS)
    {
    	LOGERROR(env, "%s", "Call to vkEnumerateInstanceExtensionProperties failed.");
        if (jLayerName != nullptr)
        {
            env->ReleaseStringUTFChars(jLayerName, layerName);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
            }
        }
        return jvulkan::createVkResult(env, result);
    }

    if (propertyCount != 0)
    {
        std::vector<VkExtensionProperties> properties(propertyCount);

        result = vkEnumerateInstanceExtensionProperties(
        		layerName,
				&propertyCount,
				properties.data());

		if (result != VK_SUCCESS)
		{
			LOGERROR(env, "%s", "Call to vkEnumerateInstanceExtensionProperties failed.");
	        if (jLayerName != nullptr)
	        {
	            env->ReleaseStringUTFChars(jLayerName, layerName);
	            if (env->ExceptionOccurred())
	            {
	            	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
	            }
	        }
			return jvulkan::createVkResult(env, result);
		}

		jclass vkExtensionPropertiesClass = env->FindClass("com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtensionProperties");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class com/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtensionProperties");
            if (jLayerName != nullptr)
            {
                env->ReleaseStringUTFChars(jLayerName, layerName);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                }
            }
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID constructorMethod = env->GetMethodID(vkExtensionPropertiesClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for <init>");
            if (jLayerName != nullptr)
            {
                env->ReleaseStringUTFChars(jLayerName, layerName);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                }
            }
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jclass collectionClass = env->GetObjectClass(jVkExtensionPropertiesCollection);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find class for jVkExtensionPropertiesCollection");
            if (jLayerName != nullptr)
            {
                env->ReleaseStringUTFChars(jLayerName, layerName);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                }
            }
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        jmethodID addMethodId = env->GetMethodID(collectionClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Could not find method id for add");
            if (jLayerName != nullptr)
            {
                env->ReleaseStringUTFChars(jLayerName, layerName);
                if (env->ExceptionOccurred())
                {
                	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                }
            }
            return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
        }

        for (const auto& property : properties)
        {
            jobject newObject = env->NewObject(vkExtensionPropertiesClass, constructorMethod);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Could not create a new VkExtensionProperties object");
                if (jLayerName != nullptr)
                {
                    env->ReleaseStringUTFChars(jLayerName, layerName);
                    if (env->ExceptionOccurred())
                    {
                    	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                    }
                }
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            jvulkan::populateVkExtensionProperties(
            		env,
        			newObject,
					&property);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling populateVkExtensionProperties");
                if (jLayerName != nullptr)
                {
                    env->ReleaseStringUTFChars(jLayerName, layerName);
                    if (env->ExceptionOccurred())
                    {
                    	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                    }
                }
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            bool addResult = env->CallBooleanMethod(jVkExtensionPropertiesCollection, addMethodId, newObject);
            if (env->ExceptionOccurred())
            {
            	LOGERROR(env, "%s", "Error calling CallBooleanMethod");
                if (jLayerName != nullptr)
                {
                    env->ReleaseStringUTFChars(jLayerName, layerName);
                    if (env->ExceptionOccurred())
                    {
                    	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                    }
                }
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }

            if (addResult == false)
            {
            	LOGERROR(env, "%s", "Error VkExtensionProperties element did not get added.");
                if (jLayerName != nullptr)
                {
                    env->ReleaseStringUTFChars(jLayerName, layerName);
                    if (env->ExceptionOccurred())
                    {
                    	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
                    }
                }
                return jvulkan::createVkResult(env, VK_RESULT_MAX_ENUM);
            }
        }
    }

    if (jLayerName != nullptr)
    {
        env->ReleaseStringUTFChars(jLayerName, layerName);
        if (env->ExceptionOccurred())
        {
        	LOGERROR(env, "%s", "Error calling ReleaseStringUTFChars");
        }
    }

    return jvulkan::createVkResult(env, result);
}
