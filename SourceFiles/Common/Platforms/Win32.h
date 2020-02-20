#ifndef _WIN32_PLATFORM_H_
#define _WIN32_PLATFORM_H_

#ifdef _WIN64

	#ifndef USE_PLATFORM_WINDOWS

        #define USE_PLATFORM_WINDOWS

		#include <Windows.h>

		typedef HMODULE EngineModule;

        #ifndef DLL_EXPORT
		    #define DLL_EXPORT __declspec(dllexport)
        #endif // DLL_EXPORT

        #ifndef DLL_IMPORT
		    #define DLL_IMPORT __declspec(dllimport)
        #endif // DLL_IMPORT

	#endif // USE_PLATFORM_WINDOWS

#endif // _WIN64

#endif // _WIN32_PLATFORM_H_