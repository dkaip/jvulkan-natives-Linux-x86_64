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

#include <cstring>
#include <iostream>
#include <stdlib.h>

#include "HelperFunctions.hh"


using namespace std;

void jobjectToVkPhysicalDeviceFeatures(JNIEnv *env, jobject jPhysicalDeviceFeatures, VkPhysicalDeviceFeatures *vkPDF);

namespace hwjvi
{
    void collectionOfStringsToAOPTC(
            JNIEnv *env,
            jobject jCollectionOfStrings,
            char ***stringArrayResult,
            int *numberOfStrings,
            std::vector<void *> *memoryToFree);

	void getInstanceCreateInfo(
	        JNIEnv *env,
	        const jobject jInstanceCreateInfo,
	        VkInstanceCreateInfo *instanceCreateInfo,
	        VkApplicationInfo *applicationInfo,
	        std::vector<void *> *memoryToFree)
	{
        jclass instanceCreateInfoClass = env->GetObjectClass(jInstanceCreateInfo);

        int sTypeValue = getSTypeAsInt(env, jInstanceCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        cout << "Got getSTypeAsInt" << endl;

        jmethodID methodId = env->GetMethodID(instanceCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }
        void *pNext = (void *)env->CallLongMethod(jInstanceCreateInfo, methodId);

//        cout << "Got pNext" << endl;

        methodId = env->GetMethodID(instanceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }
        jobject flagsObject = env->CallObjectMethod(jInstanceCreateInfo, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkInstanceCreateFlagBits");

//        cout << "Got getFlagsAsInt" << endl;
//        cout << "going for getEnabledLayerNamesAsStringArray" << endl;

        methodId = env->GetMethodID(instanceCreateInfoClass, "getEnabledLayerNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject layerNamesObject = env->CallObjectMethod(jInstanceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        cout << "Finished to here" << endl;
        char **arrayOfPointersToLayerNames = nullptr;
        int numberOfLayerNames = 0;
        if (layerNamesObject != nullptr)
        {
            collectionOfStringsToAOPTC(env, layerNamesObject, &arrayOfPointersToLayerNames, &numberOfLayerNames, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        methodId = env->GetMethodID(instanceCreateInfoClass, "getEnabledExtensionNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject extensionNamesObject = env->CallObjectMethod(jInstanceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        char **arrayOfPointersToExtensionNames = nullptr;
        int numberOfExtensionNames = 0;
        if (extensionNamesObject != nullptr)
        {
            collectionOfStringsToAOPTC(env, extensionNamesObject, &arrayOfPointersToExtensionNames, &numberOfExtensionNames, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }


        instanceCreateInfo->sType = (VkStructureType)sTypeValue;
        instanceCreateInfo->pNext = pNext;
        instanceCreateInfo->flags = flags;
        instanceCreateInfo->pApplicationInfo = applicationInfo;
        instanceCreateInfo->enabledLayerCount = numberOfLayerNames;
        instanceCreateInfo->ppEnabledLayerNames = arrayOfPointersToLayerNames;
        instanceCreateInfo->enabledExtensionCount = numberOfExtensionNames;
        instanceCreateInfo->ppEnabledExtensionNames = arrayOfPointersToExtensionNames;
        instanceCreateInfo->pApplicationInfo = applicationInfo;

        methodId = env->GetMethodID(instanceCreateInfoClass, "getApplicationInfo", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VkApplicationInfo;");
        if (env->ExceptionOccurred())
        {
            return;
        }
//        cout << "Found method ID for application Info it is " << methodId << endl;
        jobject applicationInfoClassObject = env->CallObjectMethod(jInstanceCreateInfo, methodId);
        jclass applicationInfoClass = env->GetObjectClass(applicationInfoClassObject);

//        cout << "Got application class" << endl;

        sTypeValue = getSTypeAsInt(env, applicationInfoClassObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        methodId = env->GetMethodID(applicationInfoClass, "getSTypeAsInt", "()I");
//        if (env->ExceptionOccurred())
//        {
//            return;
//        }
//        sTypeValue = env->CallIntMethod(applicationInfoClassObject, methodId);
        applicationInfo->sType = (VkStructureType)sTypeValue;

//        cout << "Got getSTypeAsInt" << endl;

        methodId = env->GetMethodID(applicationInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }
        pNext = (void *)env->CallLongMethod(applicationInfoClassObject, methodId);
        applicationInfo->pNext = pNext;

//        cout << "Got pNext again" << endl;

        methodId = env->GetMethodID(applicationInfoClass, "getApplicationName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
            return;
        }
        jstring theJavaString = (jstring)env->CallObjectMethod(applicationInfoClassObject, methodId);
        const char *theCString = env->GetStringUTFChars(theJavaString, nullptr);
        char *tempString = (char *)calloc(strlen(theCString) + 1, sizeof( char));
        strcpy(tempString, theCString);
        applicationInfo->pApplicationName = tempString;
        env->ReleaseStringUTFChars(theJavaString, theCString);
        // The above string needs to be released

        memoryToFree->push_back(tempString);
        methodId = env->GetMethodID(applicationInfoClass, "getApplicationVersion", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }
        jint applicationVersion = env->CallLongMethod(applicationInfoClassObject, methodId);
        applicationInfo->applicationVersion = applicationVersion;

        methodId = env->GetMethodID(applicationInfoClass, "getEngineName", "()Ljava/lang/String;");
        if (env->ExceptionOccurred())
        {
            return;
        }
        theJavaString = (jstring)env->CallObjectMethod(applicationInfoClassObject, methodId);
        theCString = env->GetStringUTFChars(theJavaString, nullptr);
        tempString = (char *)calloc(strlen(theCString) + 1, sizeof( char));
        strcpy(tempString, theCString);
        applicationInfo->pEngineName = tempString;
        env->ReleaseStringUTFChars(theJavaString, theCString);
        // The above string needs to be released

        memoryToFree->push_back(tempString);

        methodId = env->GetMethodID(applicationInfoClass, "getEngineVersion", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }
        jint engineVersion = env->CallLongMethod(applicationInfoClassObject, methodId);
        applicationInfo->engineVersion = engineVersion;

        methodId = env->GetMethodID(applicationInfoClass, "getApiVersion", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }
        jint apiVersion = env->CallLongMethod(applicationInfoClassObject, methodId);
        applicationInfo->apiVersion = apiVersion;

//        cout << "Got API Version " << apiVersion << endl;
	}

    void getQueueCreateInfo(
            JNIEnv *env,
            const jclass jVkQueueCreateInfoCollectionClass,
            const jobject jVkQueueCreateInfoCollection,
            VkDeviceQueueCreateInfo queueCreateInfo[],
            std::vector<void *> *memoryToFree)
    {
        jmethodID iteratorMethodId = env->GetMethodID(jVkQueueCreateInfoCollectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jVkQueueCreateInfoCollection, iteratorMethodId);
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

        jclass vkDeviceQueueCreateInfoClass = nullptr;
        jmethodID getpNextMethodId = nullptr;
        jmethodID getFlagsMethodId = nullptr;
        jmethodID getQueueFamilyIndexMethodId = nullptr;
        jmethodID getQueueCountMethodId = nullptr;
        jmethodID getQueuePrioritiesMethodId = nullptr;
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

            jobject vkDeviceQueueCreateInfoObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            if(i == 0)
            {
                vkDeviceQueueCreateInfoClass = env->GetObjectClass(vkDeviceQueueCreateInfoObject);
                if (env->ExceptionOccurred())
                {
                    break;
                }

//                getSTypeAsIntMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getSTypeAsInt", "()I");
//                if (env->ExceptionOccurred())
//                {
//                    break;
//                }
//
                getpNextMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getpNext", "()J");
                if (env->ExceptionOccurred())
                {
                    break;
                }

                getFlagsMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
                if (env->ExceptionOccurred())
                {
                    break;
                }

                getQueueFamilyIndexMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueFamilyIndex", "()I");
                if (env->ExceptionOccurred())
                {
                    break;
                }

                getQueueCountMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueueCount", "()I");
                if (env->ExceptionOccurred())
                {
                    break;
                }

                getQueuePrioritiesMethodId = env->GetMethodID(vkDeviceQueueCreateInfoClass, "getQueuePriorities", "()[F");
                if (env->ExceptionOccurred())
                {
                    break;
                }
            }

            int sTypeValue = getSTypeAsInt(env, vkDeviceQueueCreateInfoObject);
            if (env->ExceptionOccurred())
            {
                return;
            }
//            jint sType = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getSTypeAsIntMethodId);
//            if (env->ExceptionOccurred())
//            {
//                break;
//            }
//
            jlong pNext = env->CallLongMethod(vkDeviceQueueCreateInfoObject, getpNextMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

//            jint flags = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getFlagsAsIntMethodId);
//            if (env->ExceptionOccurred())
//            {
//                break;
//            }
//
            jobject flagsObject = env->CallObjectMethod(vkDeviceQueueCreateInfoObject, getFlagsMethodId);
            int32_t flags = getEnumSetValue(
                    env,
                    flagsObject,
                    "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDeviceQueueCreateFlagBits");

            jint queueFamilyIndex = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getQueueFamilyIndexMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jint queueCount = env->CallIntMethod(vkDeviceQueueCreateInfoObject, getQueueCountMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jfloatArray queuePrioritiesArray = (jfloatArray)env->CallObjectMethod(vkDeviceQueueCreateInfoObject, getQueuePrioritiesMethodId);
            if (env->ExceptionOccurred())
            {
                break;
            }

            jsize sizeOfQueuePriorities = env->GetArrayLength(queuePrioritiesArray);
//            cout << "Size of queuePriorities array is " << sizeOfQueuePriorities << endl;
            if (sizeOfQueuePriorities != queueCount)
            {
                cout << "ERROR:The size of the queue priorities array must be the same as the queue count." << endl;
            }

            float *data = env->GetFloatArrayElements(queuePrioritiesArray, 0);
            float *heapQueuePriorities = (float *)calloc((size_t)sizeOfQueuePriorities, sizeof(float));
            memoryToFree->push_back(heapQueuePriorities);
            if (data != nullptr)
            {
                memcpy(heapQueuePriorities, data, sizeOfQueuePriorities);
                env->ReleaseFloatArrayElements(queuePrioritiesArray, data, JNI_ABORT);
            }

            queueCreateInfo[i].sType = (VkStructureType)sTypeValue;
            queueCreateInfo[i].pNext = (const void *)pNext;
            queueCreateInfo[i].flags = flags;
            queueCreateInfo[i].queueFamilyIndex = queueFamilyIndex;
            queueCreateInfo[i].queueCount = queueCount;
            queueCreateInfo[i].pQueuePriorities = heapQueuePriorities;

            i++;
        } while(true);
    }

    void getDeviceCreateInfo(
            JNIEnv *env,
            const jobject jVkDeviceCreateInfo,
            VkDeviceCreateInfo *deviceCreateInfo,
            std::vector<void *> *memoryToFree)
    {
        jclass vkDeviceCreateInfoClass = env->GetObjectClass(jVkDeviceCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int sTypeValue = getSTypeAsInt(env, jVkDeviceCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }
        jmethodID methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkDeviceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDeviceCreateFlagBits");

        methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledLayerNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject layerNamesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        cout << "Finished to here" << endl;
        char **arrayOfPointersToLayerNames = nullptr;
        int numberOfLayerNames = 0;
        if (layerNamesObject != nullptr)
        {
            collectionOfStringsToAOPTC(env, layerNamesObject, &arrayOfPointersToLayerNames, &numberOfLayerNames, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledExtensionNames", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject extensionNamesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        char **arrayOfPointersToExtensionNames = nullptr;
        int numberOfExtensionNames = 0;
        if (extensionNamesObject != nullptr)
        {
            collectionOfStringsToAOPTC(env, extensionNamesObject, &arrayOfPointersToExtensionNames, &numberOfExtensionNames, memoryToFree);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        methodId = env->GetMethodID(vkDeviceCreateInfoClass, "getEnabledFeatures", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkPhysicalDeviceFeatures;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject physicalDeviceFeaturesObject = env->CallObjectMethod(jVkDeviceCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkPhysicalDeviceFeatures *physicalDeviceFeatures = (VkPhysicalDeviceFeatures *)calloc(1, sizeof(VkPhysicalDeviceFeatures));
        memoryToFree->push_back(physicalDeviceFeatures);

        jobjectToVkPhysicalDeviceFeatures(env, physicalDeviceFeaturesObject, physicalDeviceFeatures);

        deviceCreateInfo->sType = (VkStructureType)sTypeValue;
        deviceCreateInfo->pNext = (void *)pNext;
        deviceCreateInfo->flags = flags;
        deviceCreateInfo->enabledLayerCount = numberOfLayerNames;
        deviceCreateInfo->ppEnabledLayerNames = arrayOfPointersToLayerNames;
        deviceCreateInfo->enabledExtensionCount = numberOfExtensionNames;
        deviceCreateInfo->ppEnabledExtensionNames = arrayOfPointersToExtensionNames;
        deviceCreateInfo->pEnabledFeatures = physicalDeviceFeatures;
    }

    /*
     * Accept a Java Collection of Strings and return a pointer to an array of
     * pointers to "c" string AND the number of "strings" in the array.
     *
     * Note:
     *
     * The memory allocated for stringArrayResult must be released when you are
     * finished with it.
     */
    void collectionOfStringsToAOPTC(
            JNIEnv *env,
            jobject jCollectionOfStrings,
            char ***stringArrayResult,
            int *numberOfStrings,
            std::vector<void *> *memoryToFree)
    {
        jclass collectionClass = env->FindClass("java/util/Collection");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID sizeMethod = env->GetMethodID(collectionClass, "size", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint numStrings = env->CallIntMethod(jCollectionOfStrings, sizeMethod);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass iteratorClass = env->FindClass("java/util/Iterator");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID iteratorMethodId = env->GetMethodID(collectionClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject iteratorObject = env->CallObjectMethod(jCollectionOfStrings, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

//        cout << "aZZZ " << endl;
        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return;
        }

//        cout << "ZZZ" << endl;
        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        /*
         * Create an array of pointers to "c" strings;
         */
//        cout << "Number of Strings is " << numStrings << endl;

        char **arrayOfPointersToStrings = new char *[numStrings];

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

            jstring stringObject = (jstring)env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                break;
            }

            const char* theCString = env->GetStringUTFChars(stringObject, nullptr);
//            cout << "Got the next c strings " << theCString << endl;

            char *aString = (char *)calloc(strlen(theCString) + 1, sizeof(char));
            strcpy(aString, theCString);

            arrayOfPointersToStrings[i] = aString;
            memoryToFree->push_back((void *)aString);

            env->ReleaseStringUTFChars(stringObject, theCString);

            env->DeleteLocalRef(stringObject);

            i++;
        } while(true);

        *numberOfStrings = numStrings;
        *stringArrayResult = arrayOfPointersToStrings;
        memoryToFree->push_back((void *)arrayOfPointersToStrings);
    }

    void freeMemory(std::vector<void *> *memoryToFree)
    {
        if (memoryToFree->size() == 0)
            return;

        for (long unsigned int i = 0; i < memoryToFree->size(); i++)
        {
            free((*memoryToFree)[i]);
        }
    }

    int getSTypeAsInt(
            JNIEnv *env,
            const jobject vulkanStructureObject)
    {
        jclass vulkanStructureClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Structures/CreateInfos/VulkanCreateInfoStructure");
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jmethodID methodId = env->GetMethodID(vulkanStructureClass, "getSType", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkStructureType;");
        if (env->ExceptionOccurred())
        {
            cout << "ERROR could not find getSType method" << endl;
            return -1;
        }

        jobject sTypeObject = env->CallObjectMethod(vulkanStructureObject, methodId);
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jclass enumClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkStructureType");
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        methodId = env->GetMethodID(enumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            cout << "ERROR could not find valueOf method" << endl;
            return -1;
        }

        jint result = env->CallIntMethod(sTypeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        return result;
    }

    int32_t getEnumSetValue(
            JNIEnv *env,
            const jobject enumSetObject,
            const char *enumClassName)
    {
//        cout << "Trying to process EnumSet class " << enumClassName << endl;
        jclass setClass = env->FindClass("java/util/Set");
        if (env->ExceptionOccurred())
        {
            cout << "Error finding EnumSet class ... returning" << endl;
            return -1;
        }

//        jmethodID sizeMethod = env->GetMethodID(setClass, "size", "()I");
//        jint size = env->CallIntMethod(enumSetObject, sizeMethod);
//        cout << "EnumSet size is " << size << endl;
//
        jmethodID iteratorMethodId = env->GetMethodID(setClass, "iterator", "()Ljava/util/Iterator;");
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jobject iteratorObject = env->CallObjectMethod(enumSetObject, iteratorMethodId);
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jclass iteratorClass = env->GetObjectClass(iteratorObject);
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jmethodID hasNextMethodId = env->GetMethodID(iteratorClass, "hasNext", "()Z");
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jmethodID nextMethod = env->GetMethodID(iteratorClass, "next", "()Ljava/lang/Object;");
        if (env->ExceptionOccurred())
        {
            return -1;
        }

        jclass enumClass = env->FindClass(enumClassName);
        if (env->ExceptionOccurred())
        {
            cout << "Error finding Enum class name " << enumClassName << " ... returning" << endl;
            return -1;
        }

//        int signatureLength = strlen(enumClassName) + 5;
//        char signature[signatureLength];
//        signature[0] = '(';
//        signature[1] = ')';
//        signature[2] = 'L';
//        strcpy(&signature[2], enumClassName);
//        signature[signatureLength - 1] = ';';
//        signature[signatureLength] = '\0';
//
//        jmethodID valueOfMethod = env->GetMethodID(enumClass, "valueOf", signature);
        jmethodID valueOfMethod = env->GetMethodID(enumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
//            cout << "ERROR finding valueOf method with signature " << signature << endl;
            cout << "ERROR finding valueOf method with signature " << "()I" << endl;
            return -1;
        }

        int32_t result = 0;
        do
        {
            jboolean hasNext = env->CallBooleanMethod(iteratorObject, hasNextMethodId);
            if (env->ExceptionOccurred())
            {
                result = -1;
                break;
            }

            if (hasNext == false)
            {
//                cout << "leaving Loop" << endl;
                break;
            }

            jobject enumObject = env->CallObjectMethod(iteratorObject, nextMethod);
            if (env->ExceptionOccurred())
            {
                result = -1;
                break;
            }

            jint value = env->CallIntMethod(enumObject, valueOfMethod);
            if (env->ExceptionOccurred())
            {
                result = -1;
                break;
            }

            result |= value;

//            cout << "result " << result << " value " << value << endl;

        } while(true);

//        cout << "returning EnumSet value of " << std::hex << result << " for enum " << enumClassName << endl;
        return result;
    }



//    void cleanupArrayOfPointersToStrings(char *** stringArrayResult, int numberOfStrings)
//    {
//        if (numberOfStrings == 0)
//            return;
//
//        char **arrayOfPointersToStrings = *stringArrayResult;
//
//        for (int i = 0; i < numberOfStrings; i++)
//        {
//            free(arrayOfPointersToStrings[i]);
//        }
//
//        free(arrayOfPointersToStrings);
//
//        *stringArrayResult = nullptr;
//    }
//
    void *getHandleValue(JNIEnv *env, jobject jHandle)
    {
        if (jHandle == nullptr)
        {
//            void *a = (void *)jHandle;
//            float b = *((float *)a);
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

    jobject createHandle(JNIEnv *env, const char *className, void *value)
    {
        jclass handleClass = env->FindClass(className);
        if (env->ExceptionOccurred())
        {
            cout << "createHandle: could not find class " << className << endl;
            return nullptr;
        }

        jmethodID methodId = env->GetMethodID(handleClass, "<init>", "()V");
        if (env->ExceptionOccurred())
        {
            cout << "createHandle: constructor error for class " << className << endl;
            return nullptr;
        }

        jobject handleObject = env->NewObject(handleClass, methodId);

        setHandleValue(env, handleObject, value);

        env->CallVoidMethod(handleObject, methodId, value);

        return handleObject;
    }

    jobject createVkResult(JNIEnv *env, jint value)
    {
        /*
         * This function is usually called just before the caller is returning
         * back to Java.  If value does not correspond to VK_SUCCESS it may be
         * because some other function call has failed and thrown an exception.
         * In that case our "env" methods will not work properly.  Since the
         * calling function is most likely going to return with the result of
         * this call immediately we are going to clear the exception so that
         * we can properly create the appropriate response.
         */
        jboolean handlingException = env->ExceptionCheck();
        if (handlingException == true)
        {
            env->ExceptionClear();
        }

        jclass vkResultClass = env->FindClass("com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult");
        if (env->ExceptionOccurred())
        {
            cout << "createVkResult: could not find class " << "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult" << endl;
            return nullptr;
        }

        jmethodID methodId = env->GetStaticMethodID(vkResultClass, "fromValue", "(I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;");
        if (env->ExceptionOccurred())
        {
            cout << "createVkResult: could not find static method " << "fromValue with signature (I)Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkResult;" << endl;
            return nullptr;
        }

        return env->CallStaticObjectMethod(vkResultClass, methodId, value);
    }

    jobject getVkImageUsageFlagsAsEnumSet(JNIEnv *env, VkImageUsageFlags usageFlags)
    {
        char const *enumClassString = "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageUsageFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageUsageFlagBits;";
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
        char const *enumClassString = "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR";
        char const *enumObjectString = "Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR;";
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
        char const *enumClassString = "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormatFeatureFlagBits";
        char const *enumObjectString = "Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormatFeatureFlagBits;";

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

    jobject getVkSurfaceTransformFlagsKHRAsEnumSet(JNIEnv *env, VkSurfaceTransformFlagsKHR transformFlags)
    {
        char const *enumClassString = "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR";
        char const *enumObjectString = "Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;";
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
        if ((transformFlags &
             !(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR |
               VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR |
               VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR |
               VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR |
               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR |
               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR |
               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR |
               VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR |
               VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)) != 0)
        {
            cout << "ERROR: Unhandled case for transformFlags...value is " << transformFlags << endl;
            return nullptr;
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR)
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

        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        if (transformFlags & VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR)
        {
            jfieldID fieldId = env->GetStaticFieldID(enumClass, "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR", enumObjectString);
            jobject theEnum = env->GetStaticObjectField(enumClass, fieldId);

            bool addResult = env->CallBooleanMethod(enumSetObject, setAddMethod, theEnum);
            if (addResult == false)
            {
                cout << "ERROR: could not add VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR to EnumSet" << endl;
                return nullptr;
            }
        }

        return enumSetObject;
    }

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

        jmethodID methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkSwapchainCreateInfoKHR, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkSwapchainCreateInfoKHR, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanExtensions/VK11/Enums/VkSwapchainCreateFlagBitsKHR");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getSurface", "()Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Handles/VkSurfaceKHR;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageFormat", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormat;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageColorSpace", "()Lcom/CIMthetics/hwjvi/VulkanExtensions/VK11/Enums/VkColorSpaceKHR;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageExtent", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkExtent2D;");
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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageUsageFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getImageSharingMode", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSharingMode;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPreTransform", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSurfaceTransformFlagBitsKHR;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getCompositeAlpha", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkCompositeAlphaFlagBitsKHR;");
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
        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getPresentMode", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPresentModeKHR;");
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

        methodId = env->GetMethodID(vkSwapchainCreateInfoKHRClass, "getOldSwapchain", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkSwapchainKHR;");
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

    void getImageViewCreateInfo(
        JNIEnv *env,
        const jobject jVkImageViewCreateInfo,
        VkImageViewCreateInfo *imageViewCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkImageViewCreateInfoClass = env->GetObjectClass(jVkImageViewCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkImageViewCreateInfo);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageViewCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getImage", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Handles/VkImage;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jImageHandle = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        VkImage_T *imageHandle = (VkImage_T *)getHandleValue(env, jImageHandle);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getViewType", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageViewType;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject imageViewTypeEnumObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass imageViewTypeEnumClass = env->GetObjectClass(imageViewTypeEnumObject);

        jmethodID valueOfMethodId = env->GetMethodID(imageViewTypeEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint imageViewTypeEnumClassValue = env->CallIntMethod(imageViewTypeEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getFormat", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormat;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject vkFormatEnumObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass vkFormatEnumEnumClass = env->GetObjectClass(vkFormatEnumObject);

        valueOfMethodId = env->GetMethodID(vkFormatEnumEnumClass, "valueOf", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint vkFormatEnumEnumClassValue = env->CallIntMethod(vkFormatEnumObject, valueOfMethodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getComponents", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkComponentMapping;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject componentsObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint componentRValue = 0;
        jint componentGValue = 0;
        jint componentBValue = 0;
        jint componentAValue = 0;

        if (componentsObject != nullptr)
        {
            jclass componentsObjectClass = env->GetObjectClass(componentsObject);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getR", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            jobject vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            jclass vkComponentSwizzleEnumClass = env->GetObjectClass(vkComponentSwizzleEnumObject);

            valueOfMethodId = env->GetMethodID(vkComponentSwizzleEnumClass, "valueOf", "()I");
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentRValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getG", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentGValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getB", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentBValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            methodId = env->GetMethodID(componentsObjectClass, "getA", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkComponentSwizzle;");
            if (env->ExceptionOccurred())
            {
                return;
            }

            vkComponentSwizzleEnumObject = env->CallObjectMethod(componentsObject, methodId);
            if (env->ExceptionOccurred())
            {
                return;
            }

            componentAValue = env->CallIntMethod(vkComponentSwizzleEnumObject, valueOfMethodId);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkImageViewCreateInfoClass, "getSubresourceRange", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkImageSubresourceRange;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject subresourceRangeObject = env->CallObjectMethod(jVkImageViewCreateInfo, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jclass subresourceRangeObjectClass = env->GetObjectClass(subresourceRangeObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getAspectMask", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject aspectMaskObject = env->CallObjectMethod(subresourceRangeObject, methodId);
        int32_t aspectMaskFlags = getEnumSetValue(
                env,
                aspectMaskObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageAspectFlagBits");

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getBaseMipLevel", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseMipLevel = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getLevelCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint levelCount = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getBaseArrayLayer", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint baseArrayLayer = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        methodId = env->GetMethodID(subresourceRangeObjectClass, "getLayerCount", "()I");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jint layerCount = env->CallIntMethod(subresourceRangeObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }


        imageViewCreateInfo->sType = (VkStructureType)sTypeValue;
        imageViewCreateInfo->pNext = (void *)pNext;
        imageViewCreateInfo->flags = flags;
        imageViewCreateInfo->image = imageHandle;
        imageViewCreateInfo->viewType = (VkImageViewType)imageViewTypeEnumClassValue;
        imageViewCreateInfo->format = (VkFormat)vkFormatEnumEnumClassValue;
        imageViewCreateInfo->components.r = (VkComponentSwizzle)componentRValue;
        imageViewCreateInfo->components.g = (VkComponentSwizzle)componentGValue;
        imageViewCreateInfo->components.b = (VkComponentSwizzle)componentBValue;
        imageViewCreateInfo->components.a = (VkComponentSwizzle)componentAValue;
        imageViewCreateInfo->subresourceRange.aspectMask = (VkImageAspectFlags)aspectMaskFlags;
        imageViewCreateInfo->subresourceRange.baseArrayLayer = baseArrayLayer;
        imageViewCreateInfo->subresourceRange.baseMipLevel = baseMipLevel;
        imageViewCreateInfo->subresourceRange.layerCount = layerCount;
        imageViewCreateInfo->subresourceRange.levelCount = levelCount;
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

                getFormatMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFormat", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkFormat;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getSamplesMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getSamples", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSampleCountFlagBits;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getLoadOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStoreOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStencilLoadOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilLoadOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAttachmentLoadOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getStencilStoreOpMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getStencilStoreOp", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAttachmentStoreOp;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getInitialLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getInitialLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
                if (env->ExceptionOccurred())
                {
                    return;
                }

                getFinalLayoutMethodId = env->GetMethodID(vkAttachmentDescriptionClass, "getFinalLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
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
                    "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAttachmentDescriptionFlagBits");

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
        methodId = env->GetMethodID(vkAttachmentReferenceClass, "getLayout", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkImageLayout;");
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

                getPipelineBindPointMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getPipelineBindPoint", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineBindPoint;");
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

                getDepthStencilAttachmentMethodId = env->GetMethodID(vkSubpassDescriptionClass, "getDepthStencilAttachment", "()Lcom/CIMthetics/hwjvi/VulkanCore/VK11/Structures/VkAttachmentReference;");
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
                    "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkSubpassDescriptionFlagBits");

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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkPipelineStageFlagBits");

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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

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
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkAccessFlagBits");

        methodId = env->GetMethodID(vkSubpassDependencyClass, "getDependencyFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        enumSetObject = env->CallObjectMethod(jVkSubpassDependencyObject, methodId);
        int32_t dependencyFlags = getEnumSetValue(
                env,
                enumSetObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkDependencyFlagBits");

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

    void getRenderPassCreateInfo(
        JNIEnv *env,
        const jobject jVkRenderPassCreateInfoObject,
        VkRenderPassCreateInfo *renderPassCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkRenderPassCreateInfoClass = env->GetObjectClass(jVkRenderPassCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkRenderPassCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkRenderPassCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkRenderPassCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getAttachments", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject jAttachmentDescriptionCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfAttachmentDescriptions = 0;
        VkAttachmentDescription *vkAttachmentDescriptions = nullptr;

        getVkAttachmentDescriptions(
                env,
                jAttachmentDescriptionCollection,
                &vkAttachmentDescriptions,
                &numberOfAttachmentDescriptions,
                memoryToFree);
        if (env->ExceptionOccurred())
        {

            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getSubpasses", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject subpassDescriptionCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfSubpassDescriptions = 0;
        VkSubpassDescription *vkSubpassDescription = nullptr;

        getVkSubpassDescriptions(
                env,
                subpassDescriptionCollection,
                &vkSubpassDescription,
                &numberOfSubpassDescriptions,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkRenderPassCreateInfoClass, "getDependencies", "()Ljava/util/Collection;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject subpassDependencCollection = env->CallObjectMethod(jVkRenderPassCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        int numberOfSubpassDependencies = 0;
        VkSubpassDependency *vkSubpassDependency = nullptr;

        getCollectionOfVkSubpassDependency(
                env,
                subpassDependencCollection,
                &vkSubpassDependency,
                &numberOfSubpassDependencies,
                memoryToFree);
        if (env->ExceptionOccurred())
        {
            return;
        }

        renderPassCreateInfo->sType = (VkStructureType)sTypeValue;
        renderPassCreateInfo->pNext = (void *)pNext;
        renderPassCreateInfo->flags = flags;
        renderPassCreateInfo->attachmentCount = numberOfAttachmentDescriptions;
        renderPassCreateInfo->pAttachments = vkAttachmentDescriptions;
        renderPassCreateInfo->subpassCount = (uint32_t)numberOfSubpassDescriptions;
        renderPassCreateInfo->pSubpasses = vkSubpassDescription;
        renderPassCreateInfo->dependencyCount = (uint32_t)numberOfSubpassDependencies;
        renderPassCreateInfo->pDependencies = vkSubpassDependency;
    }

    void getVkShaderModuleCreateInfo(
        JNIEnv *env,
        const jobject jVkShaderModuleCreateInfoObject,
        VkShaderModuleCreateInfo *shaderModuleCreateInfo,
        std::vector<void *> *memoryToFree)
    {
        jclass vkShaderModuleCreateInfoClass = env->GetObjectClass(jVkShaderModuleCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        int sTypeValue = getSTypeAsInt(env, jVkShaderModuleCreateInfoObject);
        if (env->ExceptionOccurred())
        {
            return;
        }

        jmethodID methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getpNext", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong pNext = env->CallLongMethod(jVkShaderModuleCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getFlags", "()Ljava/util/EnumSet;");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jobject flagsObject = env->CallObjectMethod(jVkShaderModuleCreateInfoObject, methodId);
        int32_t flags = getEnumSetValue(
                env,
                flagsObject,
                "com/CIMthetics/hwjvi/VulkanCore/VK11/Enums/VkShaderModuleCreateFlagBits");

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getCodeSize", "()J");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jlong codeSize = env->CallLongMethod(jVkShaderModuleCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        ////////////////////////////////////////////////////////////////////////
        methodId = env->GetMethodID(vkShaderModuleCreateInfoClass, "getCode", "()[B");
        if (env->ExceptionOccurred())
        {
            return;
        }

        jintArray jcodeArray = (jintArray)env->CallObjectMethod(jVkShaderModuleCreateInfoObject, methodId);
        if (env->ExceptionOccurred())
        {
            return;
        }

        uint32_t *code = nullptr;
        jsize arrayLength = 0;
        if (jcodeArray != nullptr)
        {
            arrayLength = env->GetArrayLength(jcodeArray);

            code = (uint32_t *)calloc(arrayLength, sizeof(int));
            memoryToFree->push_back(code);

            env->GetIntArrayRegion(jcodeArray, 0, arrayLength, (int *)code);
            if (env->ExceptionOccurred())
            {
                return;
            }
        }

        shaderModuleCreateInfo->sType = (VkStructureType)sTypeValue;
        shaderModuleCreateInfo->pNext = (void *)pNext;
        shaderModuleCreateInfo->flags = flags;
        shaderModuleCreateInfo->codeSize = (size_t)codeSize;
        shaderModuleCreateInfo->pCode = (uint32_t *)code;
    }
}
