#ifndef _LINUX_PLATFORM_H_
#define _LINUX_PLATFORM_H_

#ifdef __GNUC__

	#ifndef USE_PLATFORM_LINUX

        #define USE_PLATFORM_LINUX

		typedef void* EngineModule;

        #ifndef DLL_EXPORT
		    #define DLL_EXPORT __attribute__ ((dllexport))
        #endif // DLL_EXPORT

        #ifndef DLL_IMPORT
		    #define DLL_IMPORT __attribute__ ((dllimport))
        #endif // DLL_IMPORT

	#endif // USE_PLATFORM_LINUX

#endif // __GNUC__

#endif // _LINUX_PLATFORM_H_