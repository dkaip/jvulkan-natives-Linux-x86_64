/*
 * Copyright 2020 Douglas Kaip
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
 * getVkSubpassDependency2.cpp
 *
 *  Created on: Jul 22, 2020
 *      Author: Douglas Kaip
 */

#include "JVulkanHelperFunctions.hh"
#include "slf4j.hh"

namespace jvulkan
 {
     void getVkSubpassDependency2(
             JNIEnv *env,
             const jobject jVkSubpassDependency2Object,
             VkSubpassDependency2 *vkSubpassDependency2,
             std::vector<void *> *memoryToFree)
     {
         jclass vkSubpassDependency2Class = env->GetObjectClass(jVkSubpassDependency2Object);
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Error trying to get class for jVkSubpassDependency2Object.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         int sTypeValue = getSType(env, jVkSubpassDependency2Object);
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Error calling getSTypeAsInt.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         jobject pNextObject = getpNextObject(env, jVkSubpassDependency2Object);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Call to getpNext failed.");
             return;
         }

         if (pNextObject != nullptr)
         {
        	 LOGERROR(env, "%s", "Unhandled case where pNextObject is not null.");
             return;
         }

         void *pNext = nullptr;

         ////////////////////////////////////////////////////////////////////////
         jmethodID methodId = env->GetMethodID(vkSubpassDependency2Class, "getSrcSubpass", "()I");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getSrcSubpass.");
             return;
         }

         jint srcSubpass = env->CallIntMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Error calling CallIntMethod.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "setDstSubpass", "()I");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for setDstSubpass.");
             return;
         }

         jint dstSubpass = env->CallIntMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Error calling CallIntMethod.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getSrcStageMask", "()Ljava/util/EnumSet;");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getSrcStageMask.");
             return;
         }

         jobject flagsObject = env->CallObjectMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
             return;
         }
         VkPipelineStageFlags srcStageMask = getEnumSetValue(
                 env,
                 flagsObject,
                 "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits");
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getDstStageMask", "()Ljava/util/EnumSet;");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getDstStageMask.");
             return;
         }

         flagsObject = env->CallObjectMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
             return;
         }
         VkPipelineStageFlags dstStageMask = getEnumSetValue(
                 env,
                 flagsObject,
                 "com/CIMthetics/jvulkan/VulkanCore/Enums/VkPipelineStageFlagBits");
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getSrcAccessMask", "()Ljava/util/EnumSet;");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getSrcAccessMask.");
             return;
         }

         flagsObject = env->CallObjectMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
             return;
         }
         VkAccessFlags srcAccessMask = getEnumSetValue(
                 env,
                 flagsObject,
                 "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getDstAccessMask", "()Ljava/util/EnumSet;");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getDstAccessMask.");
             return;
         }

         flagsObject = env->CallObjectMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
             return;
         }
         VkAccessFlags dstAccessMask = getEnumSetValue(
                 env,
                 flagsObject,
                 "com/CIMthetics/jvulkan/VulkanCore/Enums/VkAccessFlagBits");
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling getEnumSetValue.");
             return;
         }

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getDependencyFlags", "()Ljava/util/EnumSet;");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getDependencyFlags.");
             return;
         }

         flagsObject = env->CallObjectMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallObjectMethod.");
             return;
         }
         VkDependencyFlags dependencyFlags = getEnumSetValue(
                 env,
                 flagsObject,
                 "com/CIMthetics/jvulkan/VulkanCore/Enums/VkDependencyFlagBits");

         ////////////////////////////////////////////////////////////////////////
         methodId = env->GetMethodID(vkSubpassDependency2Class, "getViewOffset", "()I");
         if (env->ExceptionOccurred())
         {
        	 LOGERROR(env, "%s", "Could not get method id for getViewOffset.");
             return;
         }

         jint viewOffset = env->CallIntMethod(jVkSubpassDependency2Object, methodId);
         if (env->ExceptionOccurred())
         {
         	LOGERROR(env, "%s", "Error calling CallIntMethod.");
             return;
         }


         vkSubpassDependency2->sType = (VkStructureType)sTypeValue;
         vkSubpassDependency2->pNext = (void *)pNext;
         vkSubpassDependency2->srcSubpass = srcSubpass;
         vkSubpassDependency2->dstSubpass = dstSubpass;
         vkSubpassDependency2->srcStageMask = srcStageMask;
         vkSubpassDependency2->dstStageMask = dstStageMask;
         vkSubpassDependency2->srcAccessMask = srcAccessMask;
         vkSubpassDependency2->dstAccessMask = dstAccessMask;
         vkSubpassDependency2->dependencyFlags = dependencyFlags;
         vkSubpassDependency2->viewOffset = viewOffset;
     }
}
