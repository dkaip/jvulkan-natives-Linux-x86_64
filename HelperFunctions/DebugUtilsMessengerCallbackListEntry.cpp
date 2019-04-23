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
 * DebugUtilsMessengerCallbackListEntry.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include "DebugUtilsMessengerCallbackListEntry.h"

using namespace jvulkan;

DebugUtilsMessengerCallbackListEntry::DebugUtilsMessengerCallbackListEntry(unsigned long long the1stKey, VkDebugUtilsMessengerEXT the2ndKey, jobject objectReference, jobject userData) :
		        the1stKey(the1stKey),
				the2ndKey(the2ndKey),
                objectReference(objectReference),
                javaUserData(userData) {}

DebugUtilsMessengerCallbackListEntry::~DebugUtilsMessengerCallbackListEntry()
{
}

unsigned long long DebugUtilsMessengerCallbackListEntry::getThe1stKey()
{
	return the1stKey;
}

VkDebugUtilsMessengerEXT DebugUtilsMessengerCallbackListEntry::getThe2ndKey()
{
	return the2ndKey;
}

jobject DebugUtilsMessengerCallbackListEntry::getObjectReference()
{
	return objectReference;
}

jobject DebugUtilsMessengerCallbackListEntry::getJavaUserData()
{
	return javaUserData;
}