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
 * DebugCallbackListEntry.cpp
 *
 *  Created on: Jul 22, 2018
 *      Author: Douglas Kaip
 */
#include "DebugReportCallbackListEntry.h"

using namespace jvulkan;

DebugReportCallbackListEntry::DebugReportCallbackListEntry(unsigned long long the1stKey, VkDebugReportCallbackEXT the2ndKey, jobject objectReference, jobject userData) :
		        the1stKey(the1stKey),
				the2ndKey(the2ndKey),
                objectReference(objectReference),
                javaUserData(userData) {}

DebugReportCallbackListEntry::~DebugReportCallbackListEntry()
{
}

unsigned long long DebugReportCallbackListEntry::getThe1stKey()
{
	return the1stKey;
}

VkDebugReportCallbackEXT DebugReportCallbackListEntry::getThe2ndKey()
{
	return the2ndKey;
}

jobject DebugReportCallbackListEntry::getObjectReference()
{
	return objectReference;
}

jobject DebugReportCallbackListEntry::getJavaUserData()
{
	return javaUserData;
}
