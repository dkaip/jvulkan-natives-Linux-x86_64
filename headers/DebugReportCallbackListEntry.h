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
 * DebugReportCallbackListEntry.h
 *
 *  Created on: Jul 22, 2018
 *      Author: Douglas Kaip
 */

#include <jni.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#ifndef DEBUGCALLBACKLISTENTRY_H_
#define DEBUGCALLBACKLISTENTRY_H_

namespace jvulkan
{
    class DebugReportCallbackListEntry
    {
        private:
    	    unsigned long long          the1stKey;
            VkDebugReportCallbackEXT    the2ndKey;
            jobject                     objectReference;
            jobject                     javaUserData;

        public:
            DebugReportCallbackListEntry(unsigned long long the1stKey, VkDebugReportCallbackEXT the2ndKey, jobject objectReference, jobject userData);
            virtual ~DebugReportCallbackListEntry();

            unsigned long long getThe1stKey();
            VkDebugReportCallbackEXT getThe2ndKey();
            jobject   getObjectReference();
            jobject   getJavaUserData();

    };
} /* namespace jvulkan */

#endif /* DEBUGCALLBACKLISTENTRY_H_ */
