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
 * slf4j.cpp
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include <stdarg.h>
#include <string.h>
#include <mutex>
#include "slf4j.h"

using namespace slf4j;

void Logger::info(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...)
{

}

void Logger::debug(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...)
{

}
void Logger::trace(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...)
{

}
void Logger::warn(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...)
{

}

void Logger::error(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...)
{
}


