/*
 * DebugCallbackListEntry.h
 *
 *  Created on: Jul 22, 2018
 *      Author: Douglas Kaip
 */

#include <jni.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#ifndef DEBUGCALLBACKLISTENTRY_H_
#define DEBUGCALLBACKLISTENTRY_H_

namespace hwjvi
{
    class DebugCallbackListEntry
    {
        private:
            void                       *callbackHandle;
            jobject                     objectReference;
            jobject                     javaUserData;
            VkDebugReportCallbackEXT    vkDebugReportCallbackEXT;

        public:
            DebugCallbackListEntry(void *callbackHandle, jobject objectReference, jobject userData, VkDebugReportCallbackEXT vkDebugReportCallbackEXT);
            virtual ~DebugCallbackListEntry();

            void     *getCallbackHandle();
            jobject   getObjectReference();
            jobject   getJavaUserData();
            VkDebugReportCallbackEXT getVkDebugReportCallbackEXT();

    };
} /* namespace hwjvi */

#endif /* DEBUGCALLBACKLISTENTRY_H_ */
