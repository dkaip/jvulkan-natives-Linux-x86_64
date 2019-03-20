/*
 * DebugCallbackListEntry.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: Douglas Kaip
 */
#include "DebugCallbackListEntry.h"

using namespace hwjvi;
//{
//    class DebugCallbackListEntry
//    {
//        public:
DebugCallbackListEntry::DebugCallbackListEntry(void *callbackHandle, jobject objectReference, jobject userData, VkDebugReportCallbackEXT vkDebugReportCallbackEXT) :
                callbackHandle(callbackHandle),
                objectReference(objectReference),
                javaUserData(userData),
                vkDebugReportCallbackEXT(vkDebugReportCallbackEXT) {}

DebugCallbackListEntry::~DebugCallbackListEntry()
            {
            }

void *DebugCallbackListEntry::getCallbackHandle()
            {
                return callbackHandle;
            }

            jobject DebugCallbackListEntry::getObjectReference()
            {
                return objectReference;
            }

            jobject DebugCallbackListEntry::getJavaUserData()
            {
                return javaUserData;
            }

            VkDebugReportCallbackEXT DebugCallbackListEntry::getVkDebugReportCallbackEXT()
            {
                return vkDebugReportCallbackEXT;
            }
//    };
//}
