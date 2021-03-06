/*
 * Copyright 2019-2020 Douglas Kaip
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
 * DebugUtilsMessengerCallbackListEntry.h
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include <jni.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

#ifndef HEADERS_DEBUGUTILSMESSENGERCALLBACKLISTENTRY_H_
#define HEADERS_DEBUGUTILSMESSENGERCALLBACKLISTENTRY_H_

namespace jvulkan
{
    class DebugUtilsMessengerCallbackListEntry
    {
        private:
    	    unsigned long long          the1stKey;
    	    VkDebugUtilsMessengerEXT    the2ndKey;
            jobject                     objectReference;
            jobject                     javaUserData;

        public:
            DebugUtilsMessengerCallbackListEntry(unsigned long long the1stKey, jobject objectReference, jobject userData);
            virtual ~DebugUtilsMessengerCallbackListEntry() {}

            unsigned long long getThe1stKey() {return the1stKey;}
            VkDebugUtilsMessengerEXT getThe2ndKey() {return the2ndKey;}
            jobject   getObjectReference() {return objectReference;}
            jobject   getJavaUserData() {return javaUserData;}

            void      setThe2ndKey(VkDebugUtilsMessengerEXT the2ndKey) {this->the2ndKey = the2ndKey;}

    };
} /* namespace jvulkan */

#endif /* HEADERS_DEBUGUTILSMESSENGERCALLBACKLISTENTRY_H_ */
