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

#include "HelperFunctions.hh"
#include "slf4j.hh"

using namespace std;

namespace jvulkan
{
    void freeMemory(std::vector<void *> *memoryToFree)
    {
        if (memoryToFree->size() == 0)
            return;

        for (long unsigned int i = 0; i < memoryToFree->size(); i++)
        {
            free((*memoryToFree)[i]);
        }
    }

    void *getHandleValue(JNIEnv *env, jobject jHandle)
    {
        if (jHandle == nullptr)
        {
            cout << __FILE__ << " " << __LINE__ << " Handle Object must not be null." << endl;
            return nullptr;
        }

        jclass handleClass = env->GetObjectClass(jHandle);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "getHandle", "()J");
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        jlong handle = env->CallLongMethod(jHandle, methodId);
        if (env->ExceptionOccurred())
        {
            return nullptr;
        }

        return (void *)handle;
    }

    void setHandleValue(JNIEnv *env, jobject jHandle, void *value)
    {
        jclass handleClass = env->GetObjectClass(jHandle);
        if (env->ExceptionOccurred())
        {
            cout << "setHandleValue: could not find class "<< endl;
            return;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "setHandle", "(J)V");
        if (env->ExceptionOccurred())
        {
            cout << "setHandleValue: could not find method setHandle (J)V" << endl;
            return;
        }

        env->CallVoidMethod(jHandle, methodId, (jlong)value);
    }

    void setIntReturnValue(JNIEnv *env, jobject jReturnValue, jint value)
    {
        jclass handleClass = env->GetObjectClass(jReturnValue);
        if (env->ExceptionOccurred())
        {
            cout << "setHandleValue: could not find class "<< endl;
            return;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "setValue", "(I)V");
        if (env->ExceptionOccurred())
        {
            cout << "setIntReturnValue: could not find method setHandle (J)V" << endl;
            return;
        }

        env->CallVoidMethod(jReturnValue, methodId, value);
    }

    jobject getVkImageUsageFlagsAsEnumSet(JNIEnv *env, VkImageUsageFlags usageFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits;";
        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
            cout << "Error finding EnumSet class ... returning" << endl;
            return nullptr;
        }
    //    cout << "Found EnumSet class" << endl;

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
            cout << "Error getting noneOf ... returning" << endl;
            return nullptr;
        }

    //    cout << "Got noneOfMethod" << endl;

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
            cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
            return nullptr;
        }

    //    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;

        jclass setClass = env->FindClass("java/util/Set");
        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            cout << "Error getting add method on EnumSet ... returning" << endl;
            return nullptr;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((usageFlags &
             !(VK_IMAGE_USAGE_TRANSFER_SRC_BIT |
               VK_IMAGE_USAGE_TRANSFER_DST_BIT |
               VK_IMAGE_USAGE_SAMPLED_BIT |
               VK_IMAGE_USAGE_STORAGE_BIT |
               VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT |
               VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT |
               VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT |
               VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT)) != 0)
        {
            cout << "ERROR: Unhandled case for usageFlags...value is " << usageFlags << endl;
            return nullptr;
        }

        if (usageFlags & VK_IMAGE_USAGE_TRANSFER_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_TRANSFER_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_TRANSFER_SRC_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_TRANSFER_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_TRANSFER_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_TRANSFER_DST_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_SAMPLED_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_SAMPLED_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_SAMPLED_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_STORAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_STORAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_STORAGE_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (usageFlags & VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }

    jobject getVkCompositeAlphaFlagsKHRAsEnumSet(JNIEnv *env, VkCompositeAlphaFlagsKHR alphaFlags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR;";
        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
            cout << "Error finding EnumSet class ... returning" << endl;
            return nullptr;
        }
    //    cout << "Found EnumSet class" << endl;

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
            cout << "Error getting noneOf ... returning" << endl;
            return nullptr;
        }

    //    cout << "Got noneOfMethod" << endl;

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
            cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
            return nullptr;
        }

    //    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;

        jclass setClass = env->FindClass("java/util/Set");
        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            cout << "Error getting add method on EnumSet ... returning" << endl;
            return nullptr;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((alphaFlags &
             !(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR |
               VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR |
               VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR |
               VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR)) != 0)
        {
            cout << "ERROR: Unhandled case for alphaFlags...value is " << alphaFlags << endl;
            return nullptr;
        }

        if (alphaFlags & VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (alphaFlags & VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (alphaFlags & VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (alphaFlags & VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }

    jobject getVkFormatFeatureFlagsEnumSet(JNIEnv *env, VkFormatFeatureFlags flags)
    {
        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormatFeatureFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormatFeatureFlagBits;";

        /*
         * Create the EnumSet for the flags.
         */
        jclass enumSetClass = env->FindClass("java/util/EnumSet");
        if (env->ExceptionOccurred())
        {
            cout << "Error finding EnumSet class ... returning" << endl;
            return nullptr;
        }

        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
        if (env->ExceptionOccurred() != 0)
        {
            cout << "Error getting noneOf ... returning" << endl;
            return nullptr;
        }

        jclass enumClass = env->FindClass(enumClassString);

        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
        if (env->ExceptionOccurred())
        {
            cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
            return nullptr;
        }

        jclass setClass = env->FindClass("java/util/Set");
        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
        if (env->ExceptionOccurred())
        {
            cout << "Error getting add method on EnumSet ... returning" << endl;
            return nullptr;
        }

        /*
         * Make sure that flags does not have an unexpected value.  This would
         * indicate that this code is out of sync with the LunarG Vulkan SDK.
         */
        if ((flags &
             !(VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT |
               VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT |
               VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT |
               VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT |
               VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT |
               VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT |
               VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT |
               VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT |
               VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT |
               VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT |
               VK_FORMAT_FEATURE_BLIT_SRC_BIT |
               VK_FORMAT_FEATURE_BLIT_DST_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT |
               VK_FORMAT_FEATURE_TRANSFER_SRC_BIT |
               VK_FORMAT_FEATURE_TRANSFER_DST_BIT |
               VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT |
               VK_FORMAT_FEATURE_DISJOINT_BIT |
               VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG |
               VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT)) != 0)
        {
            cout << "ERROR: Unhandled case for alphaFlags...value is " << flags << endl;
            return nullptr;
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_BLIT_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_BLIT_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_BLIT_SRC_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_BLIT_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_BLIT_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_BLIT_DST_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_TRANSFER_SRC_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_TRANSFER_SRC_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_TRANSFER_DST_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_TRANSFER_DST_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_TRANSFER_DST_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_DISJOINT_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_DISJOINT_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_DISJOINT_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG to EnumSet" << endl;
                return nullptr;
            }
        }

        if (flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT to EnumSet" << endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }

//    jobject getVkSurfaceTransformFlagsKHRAsEnumSet(JNIEnv *env, VkSurfaceTransformFlagsKHR transformFlags)
//    {
//        char const *enumClassString = "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR";
//        char const *enumObjectString = "Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;";
//        /*
//         * Create the EnumSet for the flags.
//         */
//        jclass enumSetClass = env->FindClass("java/util/EnumSet");
//        if (env->ExceptionOccurred())
//        {
//            cout << "Error finding EnumSet class ... returning" << endl;
//            return nullptr;
//        }
//    //    cout << "Found EnumSet class" << endl;
//
//        jmethodID enumSetNoneOfMethod = env->GetStaticMethodID(enumSetClass, "noneOf", "(Ljava/lang/Class;)Ljava/util/EnumSet;");
//        if (env->ExceptionOccurred() != 0)
//        {
//            cout << "Error getting noneOf ... returning" << endl;
//            return nullptr;
//        }
//
//    //    cout << "Got noneOfMethod" << endl;
//
//        jclass enumClass = env->FindClass(enumClassString);
//
//        jobject enumSetObject = env->CallStaticObjectMethod(enumSetClass, enumSetNoneOfMethod, enumClass);
//        if (env->ExceptionOccurred())
//        {
//            cout << "Error CallStaticObjectMethod on enumset object class ... returning" << endl;
//            return nullptr;
//        }
//
//    //    cout << "Made the empty EnumSet flags is " << vkSampleCountFlags << endl;
//
//        jclass setClass = env->FindClass("java/util/Set");
//        jmethodID setAddMethod = env->GetMethodID(setClass, "add", "(Ljava/lang/Object;)Z");
//        if (env->ExceptionOccurred())
//        {
//            cout << "Error getting add method on EnumSet ... returning" << endl;
//            return nullptr;
//        }
//
//        /*
//         * Make sure that flags does not have an unexpected value.  This would
//         * indicate that this code is out of sync with the LunarG Vulkan SDK.
//         */
//        if ((transformFlags &
//             !(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR |
//               VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR |
//               VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR |
//               VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR |
//               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR |
//               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR |
//               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR |
//               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR |
//               VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)) != 0)
//        {
//            cout << "ERROR: Unhandled case for transformFlags...value is " << transformFlags << endl;
//            return nullptr;
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        if (transformFlags & VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)
//        {
//            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR", enumObjectString);
//            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);
//
//            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
//            if (addResult == false)
//            {
//                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR to EnumSet" << endl;
//                return nullptr;
//            }
//        }
//
//        return enumSetObject;
//    }
//
	void getAllocatorCallbacks(
	        JNIEnv *env,
	        const jobject jAlternateAllocator,
	        VkAllocationCallbacks *allocatorCallbacks)
	{

	}

    void getSwapchainCreateInfoKHR(
            JNIEnv *env,
            const jobject jVkSwapchainCreateInfoKHR,
            VkSwapchainCreateInfoKHR *swapchainCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSwapchainCreateInfoKHRClass = env->GetObjectClass(jVkSwapchainCreateInfoKHR);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkSwapchainCreateInfoKHR);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jobject pNextObject = getpNextObject(env, jVkSwapchainCreateInfoKHR);
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
        jmethodID methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkSwapchainCreateFlagBitsKHR");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getSurface", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Handles/VkSurfaceKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jSurfaceHandle = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkSurfaceKHR_T *surfaceHandle = (VkSurfaceKHR_T *)getHandleValue(env, jSurfaceHandle);

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getMinImageCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint minImageCount = env->CallIntMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageFormatEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass imageFormatEnumClass = env->GetObjectClass(imageFormatEnumObject);

        jmethodID valueOfMethodId = env->GetMethodID(imageFormatEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageFormatEnumValue = env->CallIntMethod(imageFormatEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageColorSpace", "()Lcom/CIMthetics/jvulkan/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageColorSpaceEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass imageColorSpaceEnumClass = env->GetObjectClass(imageColorSpaceEnumObject);

        valueOfMethodId = env->GetMethodID(imageColorSpaceEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageColorSpaceEnumValue = env->CallIntMethod(imageColorSpaceEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageExtent", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkExtent2D;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageImageExtentObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkExtent2D *imageExtent = nullptr;

        if (imageImageExtentObject != nullptr)
        {
            imageExtent = (VkExtent2D *)calloc(1, sizeof(VkExtent2D));

            jclass imageImageExtentClass = env->GetObjectClass(imageImageExtentObject);

            methodId = env->GetMethodID(imageImageExtentClass, "getWidth", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint extentWidth = env->CallIntMethod(imageImageExtentObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(imageImageExtentClass, "getHeight", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint extentHeight = env->CallIntMethod(imageImageExtentObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            imageExtent->width = extentWidth;
            imageExtent->height = extentHeight;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageArrayLayers", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageArrayLayers = env->CallIntMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageUsage", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageUsageObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        int32_t imageUsage = getEnumSetValue(
                env,
                imageUsageObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageUsageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageSharingMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSharingMode;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageSharingModeEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass imageSharingModeEnumClass = env->GetObjectClass(imageSharingModeEnumObject);

        valueOfMethodId = env->GetMethodID(imageSharingModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageSharingModeEnumValue = env->CallIntMethod(imageSharingModeEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getQueueFamilyIndices", "()[I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jQueueFamilyIndices = (jintArray)env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int *queueFamilyIndicesArray = nullptr;
        jsize arrayLength = 0;
        if (jQueueFamilyIndices != nullptr)
        {
            arrayLength = env->GetArrayLength(jQueueFamilyIndices);

            queueFamilyIndicesArray = (int *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(queueFamilyIndicesArray);

            env->GetIntArrayRegion(jQueueFamilyIndices, 0, arrayLength, queueFamilyIndicesArray);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPreTransform", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject preTransformEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass preTransformEnumClass = env->GetObjectClass(preTransformEnumObject);

        valueOfMethodId = env->GetMethodID(preTransformEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint preTransformEnumClassValue = env->CallIntMethod(preTransformEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getCompositeAlpha", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject compositeAlphaEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass compositeAlphaEnumClass = env->GetObjectClass(compositeAlphaEnumObject);

        valueOfMethodId = env->GetMethodID(compositeAlphaEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint compositeAlphaEnumClassValue = env->CallIntMethod(compositeAlphaEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPresentMode", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPresentModeKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject presentModeEnumObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass presentModeEnumClass = env->GetObjectClass(presentModeEnumObject);

        valueOfMethodId = env->GetMethodID(presentModeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint presentModeEnumClassValue = env->CallIntMethod(presentModeEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getClipped", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jboolean jclipped = env->CallBooleanMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        bool clipped = false;
        if (jclipped != 0)
        {
            clipped = true;
        }

        ////////////////////////////////////////////////////////////////////////
        VkSwapchainKHR_T *oldSwapchainHandle = nullptr;

        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getOldSwapchain", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Handles/VkSwapchainKHR;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jOldSwapchainHandle = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        if (jOldSwapchainHandle != nullptr)
        {
            oldSwapchainHandle = (VkSwapchainKHR_T *)getHandleValue(env, jOldSwapchainHandle);
        }

        swapchainCreateInfo->sType = (VkStructureType)sTypeValue;
        swapchainCreateInfo->pNext = (void *)pNext;
        swapchainCreateInfo->flags = flags;
        swapchainCreateInfo->surface = surfaceHandle;
        swapchainCreateInfo->minImageCount = minImageCount;
        swapchainCreateInfo->imageFormat = (VkFormat)imageFormatEnumValue;
        swapchainCreateInfo->imageColorSpace = (VkColorSpaceKHR)imageColorSpaceEnumValue;

        if (imageExtent != nullptr)
        {
            swapchainCreateInfo->imageExtent.width = imageExtent->width;
            swapchainCreateInfo->imageExtent.height = imageExtent->height;
        }
        else
        {
            swapchainCreateInfo->imageExtent.width = 0;
            swapchainCreateInfo->imageExtent.height = 0;
        }

        free(imageExtent);

        swapchainCreateInfo->imageArrayLayers = imageArrayLayers;
        swapchainCreateInfo->imageUsage = imageUsage;
        swapchainCreateInfo->imageSharingMode = (VkSharingMode)imageSharingModeEnumValue;
        swapchainCreateInfo->queueFamilyIndexCount = arrayLength;
        swapchainCreateInfo->pQueueFamilyIndices = (uint32_t *)queueFamilyIndicesArray;
        swapchainCreateInfo->preTransform = (VkSurfaceTransformFlagBitsKHR)preTransformEnumClassValue;
        swapchainCreateInfo->compositeAlpha = (VkCompositeAlphaFlagBitsKHR)compositeAlphaEnumClassValue;
        swapchainCreateInfo->presentMode = (VkPresentModeKHR)presentModeEnumClassValue;
        swapchainCreateInfo->clipped = clipped;
        swapchainCreateInfo->oldSwapchain = oldSwapchainHandle;
    }

    void getVkAttachmentDescriptions(
            JNIEnv *env,
            const jobject jVkAttachmentDescriptionCollectionObject,
            VkAttachmentDescription **attachmentDescriptions,
            int *numberOfAttachments,
            std::vector<void *> *memoryToFree)
    {
        jclass vkAttachmentDescriptionCollectionClass = env->GetObjectClass(jVkAttachmentDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfAttachments = numberOfElements;
        *attachmentDescriptions = (VkAttachmentDescription *)calloc(numberOfElements, sizeof(VkAttachmentDescription));
        memoryToFree->push_back(*attachmentDescriptions);

        jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAttachmentDescriptionCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkAttachmentDescriptionClass = nullptr;
        jmethodID getFlagsMethodId;
        jmethodID getFormatMethodId;
        jmethodID getSamplesMethodId;
        jmethodID getLoadOpMethodId;
        jmethodID getStoreOpMethodId;
        jmethodID getStencilLoadOpMethodId;
        jmethodID getStencilStoreOpMethodId;
        jmethodID getInitialLayoutMethodId;
        jmethodID getFinalLayoutMethodId;
        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkAttachmentDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (i == 0)
            {
                /*
                 * This "setup" only needs to be done in the first iteration.
                 */
                vkAttachmentDescriptionClass = env->GetObjectClass(jVkAttachmentDescriptionObject);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getFlagsMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFlags", "()Ljava/util/EnumSet;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getFormatMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFormat", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkFormat;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getSamplesMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getSamples", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSampleCountFlagBits;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStencilLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilLoadOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStencilStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilStoreOp", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getInitialLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getInitialLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getFinalLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFinalLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

            }

            ////////////////////////////////////////////////////////////////////////
            jobject flagsObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFlagsMethodId);
            int32_t flags = getEnumSetValue(
                    env,
                    flagsObject,
                    "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAttachmentDescriptionFlagBits");

            ////////////////////////////////////////////////////////////////////////
            jobject vkFormatEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFormatMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkFormatEnumEnumClass = env->GetObjectClass(vkFormatEnumObject);

            jmethodID valueOfMethodId = env->GetMethodID(vkFormatEnumEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint vkFormatEnumEnumValue = env->CallIntMethod(vkFormatEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            jobject vkSampleCountFlagBitsEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getSamplesMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkSampleCountFlagBitsEnumClass = env->GetObjectClass(vkSampleCountFlagBitsEnumObject);

            valueOfMethodId = env->GetMethodID(vkSampleCountFlagBitsEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint vkSampleCountFlagBitsEnumValue = env->CallIntMethod(vkSampleCountFlagBitsEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            jobject vkAttachmentLoadOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getLoadOpMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkAttachmentLoadOpEnumClass = env->GetObjectClass(vkAttachmentLoadOpEnumObject);

            valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint vkAttachmentLoadOpEnumValue = env->CallIntMethod(vkAttachmentLoadOpEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            jobject vkAttachmentStoreOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStoreOpMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkAttachmentStoreOpEnumClass = env->GetObjectClass(vkAttachmentStoreOpEnumObject);

            valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint vkAttachmentStoreOpEnumValue = env->CallIntMethod(vkAttachmentStoreOpEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            vkAttachmentLoadOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStencilLoadOpMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkAttachmentLoadOpEnumClass = env->GetObjectClass(vkAttachmentLoadOpEnumObject);

            valueOfMethodId = env->GetMethodID(vkAttachmentLoadOpEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint stencilLoadOpEnumValue = env->CallIntMethod(vkAttachmentLoadOpEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            vkAttachmentStoreOpEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getStencilStoreOpMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkAttachmentStoreOpEnumClass = env->GetObjectClass(vkAttachmentStoreOpEnumObject);

            valueOfMethodId = env->GetMethodID(vkAttachmentStoreOpEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint stencilStoreOpEnumValue = env->CallIntMethod(vkAttachmentStoreOpEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            jobject vkImageLayoutEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getInitialLayoutMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkImageLayoutEnumClass = env->GetObjectClass(vkImageLayoutEnumObject);

            valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint initialLayoutEnumValue = env->CallIntMethod(vkImageLayoutEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            vkImageLayoutEnumObject = env->CallObjectMethod(jVkAttachmentDescriptionObject, getFinalLayoutMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkImageLayoutEnumClass = env->GetObjectClass(vkImageLayoutEnumObject);

            valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint finalLayoutEnumValue = env->CallIntMethod(vkImageLayoutEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            (*attachmentDescriptions)[i].flags    = (VkAttachmentDescriptionFlags)flags;
            (*attachmentDescriptions)[i].format   = (VkFormat)vkFormatEnumEnumValue;
            (*attachmentDescriptions)[i].samples  = (VkSampleCountFlagBits)vkSampleCountFlagBitsEnumValue;
            (*attachmentDescriptions)[i].loadOp   = (VkAttachmentLoadOp)vkAttachmentLoadOpEnumValue;
            (*attachmentDescriptions)[i].storeOp  = (VkAttachmentStoreOp)vkAttachmentStoreOpEnumValue;
            (*attachmentDescriptions)[i].stencilLoadOp  = (VkAttachmentLoadOp)stencilLoadOpEnumValue;
            (*attachmentDescriptions)[i].stencilStoreOp = (VkAttachmentStoreOp)stencilStoreOpEnumValue;
            (*attachmentDescriptions)[i].initialLayout  = (VkImageLayout)initialLayoutEnumValue;
            (*attachmentDescriptions)[i].finalLayout    = (VkImageLayout)finalLayoutEnumValue;

            i++;
        } while(true);
    }

    void getVkAttachmentReference(
            JNIEnv *env,
            const jobject jVkAttachmentReferenceObject,
            VkAttachmentReference *attachmentReference)
    {
        jclass vkAttachmentReferenceClass = env->GetObjectClass(jVkAttachmentReferenceObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentReferenceClass, "getAttachment", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint attachment = env->CallIntMethod(jVkAttachmentReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkAttachmentReferenceClass, "getLayout", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkImageLayout;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject vkImageLayoutEnumObject = env->CallObjectMethod(jVkAttachmentReferenceObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkImageLayoutEnumClass = env->GetObjectClass(vkImageLayoutEnumObject);

        jmethodID valueOfMethodId = env->GetMethodID(vkImageLayoutEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkImageLayoutEnumValue = env->CallIntMethod(vkImageLayoutEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        attachmentReference->attachment = attachment;
        attachmentReference->layout = (VkImageLayout)vkImageLayoutEnumValue;
    }

    void getCollectionOfVkAttachmentReference(
            JNIEnv *env,
            const jobject jVkAttachmentReferenceCollectionObject,
            VkAttachmentReference **attachmentReferences,
            int *numberOfAttachmentReferences,
            std::vector<void *> *memoryToFree)
    {
        if (jVkAttachmentReferenceCollectionObject == nullptr)
        {
            return;
        }

        jclass vkAttachmentReferenceCollectionClass = env->GetObjectClass(jVkAttachmentReferenceCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkAttachmentReferenceCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkAttachmentReferenceCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfAttachmentReferences = numberOfElements;
        *attachmentReferences = (VkAttachmentReference *)calloc(numberOfElements, sizeof(VkAttachmentReference));
        memoryToFree->push_back(*attachmentReferences);

        jmethodID iteratorMethodId = env->GetMethodID(vkAttachmentReferenceCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkAttachmentReferenceCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkAttachmentReferenceObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkAttachmentReference(
                    env,
                    jVkAttachmentReferenceObject,
                    &(*attachmentReferences)[i]);

            i++;
        } while(true);
    }

    void getVkSubpassDescriptions(
            JNIEnv *env,
            const jobject jVkSubpassDescriptionCollectionObject,
            VkSubpassDescription **subpassDescriptions,
            int *numberOfDescriptions,
            std::vector<void *> *memoryToFree)
    {
        jclass vkSubpassDescriptionCollectionClass = env->GetObjectClass(jVkSubpassDescriptionCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubpassDescriptionCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubpassDescriptionCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfDescriptions = numberOfElements;
        *subpassDescriptions = (VkSubpassDescription *)calloc(numberOfElements, sizeof(VkSubpassDescription));
        memoryToFree->push_back(*subpassDescriptions);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDescriptionCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubpassDescriptionCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        jclass vkSubpassDescriptionClass = nullptr;
        jmethodID getFlagsMethodId;
        jmethodID getPipelineBindPointMethodId;
        jmethodID getInputAttachmentsMethodId;
        jmethodID getColorAttachmentsMethodId;
        jmethodID getResolveAttachmentsMethodId;
        jmethodID getDepthStencilAttachmentMethodId;
        jmethodID getPreserveAttachmentsMethodId;

        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkSubpassDescriptionObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (i == 0)
            {
                /*
                 * This "setup" only needs to be done in the first iteration.
                 */
                vkSubpassDescriptionClass = env->GetObjectClass(jVkSubpassDescriptionObject);
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getFlagsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getFlags", "()Ljava/util/EnumSet;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getPipelineBindPointMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getPipelineBindPoint", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineBindPoint;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getInputAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getInputAttachments", "()Ljava/util/Collection;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getColorAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getColorAttachments", "()Ljava/util/Collection;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getResolveAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getResolveAttachments", "()Ljava/util/Collection;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getDepthStencilAttachmentMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getDepthStencilAttachment", "()Lcom/CIMthetics/jvulkan/VulkanCore/VK11/Structures/VkAttachmentReference;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getPreserveAttachmentsMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getPreserveAttachments", "()[I");
                if (env->ExceptionOccurred())
                {
                    return;
                }
            }

            ////////////////////////////////////////////////////////////////////////
            jobject flagsObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getFlagsMethodId);
            int32_t flags = getEnumSetValue(
                    env,
                    flagsObject,
                    "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkSubpassDescriptionFlagBits");

            ////////////////////////////////////////////////////////////////////////
            jobject vkPipelineBindPointEnumObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getPipelineBindPointMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkPipelineBindPointEnumClass = env->GetObjectClass(vkPipelineBindPointEnumObject);

            jmethodID valueOfMethodId = env->GetMethodID(vkPipelineBindPointEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jint vkPipelineBindPointEnumValue = env->CallIntMethod(vkPipelineBindPointEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            ////////////////////////////////////////////////////////////////////////
            jobject vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getInputAttachmentsMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            int numberOfInputAttachments = 0;
            VkAttachmentReference *inputAttachements = nullptr;

            getCollectionOfVkAttachmentReference(
                    env,
                    vkAttachmentReferenceCollectionObject,
                    &inputAttachements,
                    &numberOfInputAttachments,
                    memoryToFree);

            ////////////////////////////////////////////////////////////////////////
            vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getColorAttachmentsMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            int numberOfColorAttachments = 0;
            VkAttachmentReference *colorAttachements = nullptr;

            getCollectionOfVkAttachmentReference(
                    env,
                    vkAttachmentReferenceCollectionObject,
                    &colorAttachements,
                    &numberOfColorAttachments,
                    memoryToFree);

            ////////////////////////////////////////////////////////////////////////
            vkAttachmentReferenceCollectionObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getResolveAttachmentsMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            int numberOfResolveAttachments = 0;
            VkAttachmentReference *resolveAttachements = nullptr;

            getCollectionOfVkAttachmentReference(
                    env,
                    vkAttachmentReferenceCollectionObject,
                    &resolveAttachements,
                    &numberOfResolveAttachments,
                    memoryToFree);

            ////////////////////////////////////////////////////////////////////////
            jobject jVkAttachmentReferenceObject = env->CallObjectMethod(jVkSubpassDescriptionObject, getDepthStencilAttachmentMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            VkAttachmentReference *depthStencilAttachment = nullptr;
            if (jVkAttachmentReferenceObject != nullptr)
            {
                depthStencilAttachment = (VkAttachmentReference *)calloc(1, sizeof(VkAttachmentReference));
                memoryToFree->push_back(depthStencilAttachment);

                getVkAttachmentReference(
                    env,
                    jVkAttachmentReferenceObject,
                    depthStencilAttachment);
            }

            ////////////////////////////////////////////////////////////////////////
            jintArray jPreserveAttachmentArray = (jintArray)env->CallObjectMethod(jVkSubpassDescriptionObject, getPreserveAttachmentsMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            uint32_t *preserveAttachmentArray = nullptr;
            jsize arrayLength = 0;
            if (jPreserveAttachmentArray != nullptr)
            {
                arrayLength = env->GetArrayLength(jPreserveAttachmentArray);

                preserveAttachmentArray = (uint32_t *)calloc(arrayLength, sizeof(uint32_t));
                memoryToFree->push_back(preserveAttachmentArray);

                env->GetIntArrayRegion(jPreserveAttachmentArray, 0, arrayLength, (int *)preserveAttachmentArray);
                if (env->ExceptionOccurred())
                {
                    return;
                }
            }

            (*subpassDescriptions)[i].flags         = (VkSubpassDescriptionFlags)flags;
            (*subpassDescriptions)[i].pipelineBindPoint = (VkPipelineBindPoint)vkPipelineBindPointEnumValue;
            (*subpassDescriptions)[i].inputAttachmentCount = numberOfInputAttachments;
            (*subpassDescriptions)[i].pInputAttachments = inputAttachements;
            (*subpassDescriptions)[i].colorAttachmentCount = numberOfColorAttachments;
            (*subpassDescriptions)[i].pColorAttachments = colorAttachements;
            (*subpassDescriptions)[i].pResolveAttachments = resolveAttachements;
            (*subpassDescriptions)[i].pDepthStencilAttachment = depthStencilAttachment;
            (*subpassDescriptions)[i].preserveAttachmentCount = (uint32_t)arrayLength;
            (*subpassDescriptions)[i].pPreserveAttachments = preserveAttachmentArray;

            i++;
        } while(true);
    }

    void getVkSubpassDependency(
            JNIEnv *env,
            const jobject jVkSubpassDependencyObject,
            VkSubpassDependency *subpassDependency)
    {
        jclass vkSubpassDependencyClass = env->GetObjectClass(jVkSubpassDependencyObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        jmethodID methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint srcSubpass = env->CallIntMethod(jVkSubpassDependencyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstSubpass", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint dstSubpass = env->CallIntMethod(jVkSubpassDependencyObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcStageMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t srcStageMask = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstStageMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t dstStageMask = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependencyClass, "getSrcAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t srcAccessMask = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSubpassDependencyClass, "getDstAccessMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t dstAccessMask = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkAccessFlagBits");

        methodId = env->GetMethodID(vkSubpassDependencyClass, "getDependencyFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t dependencyFlags = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/jvulkan/VulkanCore/VK11/Enums/VkDependencyFlagBits");

        subpassDependency->srcSubpass = (uint32_t)srcSubpass;
        subpassDependency->dstSubpass = (uint32_t)dstSubpass;
        subpassDependency->srcStageMask = srcStageMask;
        subpassDependency->dstStageMask = dstStageMask;
        subpassDependency->srcAccessMask = srcAccessMask;
        subpassDependency->dstAccessMask = dstAccessMask;
        subpassDependency->dependencyFlags = dependencyFlags;
    }

    void getCollectionOfVkSubpassDependency(
            JNIEnv *env,
            const jobject jVkSubpassDependencyCollectionObject,
            VkSubpassDependency **subpassDependencies,
            int *numberOfSubpassDependencies,
            std::vector<void *> *memoryToFree)
    {
        if (jVkSubpassDependencyCollectionObject == nullptr)
        {
            return;
        }

        jclass vkSubpassDependencyCollectionClass = env->GetObjectClass(jVkSubpassDependencyCollectionObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkSubpassDependencyCollectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numberOfElements = env->CallIntMethod(jVkSubpassDependencyCollectionObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        *numberOfSubpassDependencies = numberOfElements;
        *subpassDependencies = (VkSubpassDependency *)calloc(numberOfElements, sizeof(VkSubpassDependency));
        memoryToFree->push_back(*subpassDependencies);

        jmethodID iteratorMethodId = env->GetMethodID(vkSubpassDependencyCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkSubpassDependencyCollectionObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        int i = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if (hasNext == false)
            {
                break;
            }

            jobject jVkSubpassDependencyObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            getVkSubpassDependency(
                    env,
                    jVkSubpassDependencyObject,
                    &(*subpassDependencies)[i]);

            i++;
        } while(true);
    }

}
