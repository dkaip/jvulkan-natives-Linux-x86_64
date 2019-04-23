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
 * slf4j.h
 *
 *  Created on: Apr 22, 2019
 *      Author: Douglas Kaip
 */

#include <cstdarg>
#include <iostream>
#include <string.h>
#include <jni.h>

#ifndef HEADERS_SLF4J_H_
#define HEADERS_SLF4J_H_

#ifdef __GNUC__

#define LOGINFO(format, ...) (Logger.getInstance()->info(__FILE__, __PRETTY_FUNCTION__,__LINE__, format, ##__VA_ARGS__);)
#define LOGDEBUG(format, ...) (Logger.getInstance()->debug(__FILE__, __PRETTY_FUNCTION__,__LINE__, format, ##__VA_ARGS__);)
#define LOGTRACE(format, ...) (Logger.getInstance()->trace(__FILE__, __PRETTY_FUNCTION__,__LINE__, format, ##__VA_ARGS__);)
#define LOGWARN(format, ...) (Logger.getInstance()->warn(__FILE__, __PRETTY_FUNCTION__,__LINE__, format, ##__VA_ARGS__);)
#define LOGERROR(format, ...) (Logger.getInstance()->error(__FILE__, __PRETTY_FUNCTION__,__LINE__, format, ##__VA_ARGS__);)

#else
#define LOGINFO(format, ...) (Logger.getInstance()->info(__FILE__, "",__LINE__, format, ##__VA_ARGS__);)
#define LOGDEBUG(format, ...) (Logger.getInstance()->debug(__FILE__, "",__LINE__, format, ##__VA_ARGS__);)
#define LOGTRACE(format, ...) (Logger.getInstance()->trace(__FILE__, "",__LINE__, format, ##__VA_ARGS__);)
#define LOGWARN(format, ...) (Logger.getInstance()->warn(__FILE__, "",__LINE__, format, ##__VA_ARGS__);)
#define LOGERROR(format, ...) (Logger.getInstance()->error(__FILE__, "",__LINE__, format, ##__VA_ARGS__);)
#endif

namespace slf4j
{
    class Logger
	{
		private:
    	    const char *loggerName = "jvulkan-natives";
    		static Logger *instance;
    		static std::mutex creation_Mutex;
    		static jobject slf4jLoggerObject;
    		static jclass loggerClass;
    		static jmethodID infoMethodId;
    		static jmethodID debugMethodId;
    		static jmethodID traceMethodId;
    		static jmethodID warnMethodId;
    		static jmethodID errorMethodId;

    		Logger(JNIEnv *env)
    		{
    			loggerClass = env->FindClass("org/slf4j/Logger");
    			if (loggerClass == nullptr)
    			{
    				std::cerr << "Could not find class org/slf4j/Logger...it is required." << std::endl;
    			}

    			jclass loggerFactoryClass = env->FindClass("org/slf4j/LoggerFactory");
    			if (loggerClass == nullptr)
    			{
    				std::cerr << "Could not find class org/slf4j/LoggerFactory...it is required." << std::endl;
    			}

    			jmethodID methodId = env->GetStaticMethodID(loggerFactoryClass, "getLogger", "(Ljava/lang/String;)Lorg/slf4j/Logger;");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method getLogger in org/slf4j/LoggerFactory with signature \"(Ljava/lang/String;)Lorg/slf4j/Logger;\"...it is required." << std::endl;
    			}

    		    jstring loggerNameString = env->NewStringUTF(loggerName);

    		    if (env->ExceptionOccurred())
    		    {
    		        return;
    		    }

    		    jobject localLoggerObject = env->CallObjectMethod(loggerFactoryClass, methodId, loggerNameString);

    		    env->DeleteLocalRef(loggerNameString);

    		    /*
    		     * We need to get a global ref because this will be used later in all logging calls.
    		     *
    		     * We are not deleting the global ref anywhere because it should hang around until
    		     * the program exits.
    		     */
    		    slf4jLoggerObject = reinterpret_cast<jobject>(env->NewGlobalRef(localLoggerObject));



    		    infoMethodId = env->GetMethodID(loggerClass, "info", "(Ljava/lang/String;)V");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method info in org/slf4j/Logger with signature \"(Ljava/lang/String;)V\"...it is required." << std::endl;
    			}

    		    debugMethodId = env->GetMethodID(loggerClass, "debug", "(Ljava/lang/String;)V");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method debug in org/slf4j/Logger with signature \"(Ljava/lang/String;)V\"...it is required." << std::endl;
    			}

    		    traceMethodId = env->GetMethodID(loggerClass, "trace", "(Ljava/lang/String;)V");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method trace in org/slf4j/Logger with signature \"(Ljava/lang/String;)V\"...it is required." << std::endl;
    			}

    		    warnMethodId = env->GetMethodID(loggerClass, "warn", "(Ljava/lang/String;)V");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method warn in org/slf4j/Logger with signature \"(Ljava/lang/String;)V\"...it is required." << std::endl;
    			}

    		    errorMethodId = env->GetMethodID(loggerClass, "error", "(Ljava/lang/String;)V");
    			if (methodId == nullptr)
    			{
    				std::cerr << "Could not find method error in org/slf4j/Logger with signature \"(Ljava/lang/String;)V\"...it is required." << std::endl;
    			}
    		}

		public:
    		Logger* getInstance(JNIEnv *env)
    	 	{
    			{
					std::lock_guard<std::mutex> lock(creation_Mutex);
					if (instance == nullptr)
					{
						instance = new Logger(env);
					}
    			}

    	 		return instance;
    	 	}

    	 	 Logger(Logger const&)			= delete;
    	 	 void operator=(Logger const&)	= delete;

    	 	 void info(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...);
    	 	 void debug(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...);
    	 	 void trace(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...);
    	 	 void warn(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...);
    	 	 void error(JNIEnv *env, const char *fileName, const char *methodName, int lineNumber, const char *formatString, ...);
	};
}

#endif /* HEADERS_SLF4J_H_ */
