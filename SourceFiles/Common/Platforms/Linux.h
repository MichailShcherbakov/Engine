#ifndef _LINUX_PLATFORM_H_
#define _LINUX_PLATFORM_H_

#ifndef _WIN32

	#ifndef USE_PLATFORM_LINUX

        #define USE_PLATFORM_LINUX

        #include <dlfcn.h>

		typedef void* EngineModule;

        #ifndef DLL_EXPORT
		    #define DLL_EXPORT __attribute__ ((dllexport))
        #endif // DLL_EXPORT

        #ifndef DLL_IMPORT
		    #define DLL_IMPORT __attribute__ ((dllimport))
        #endif // DLL_IMPORT

        #ifndef ENGINE_API
			#define ENGINE_API
		#endif // ENGINE_API

	#endif // USE_PLATFORM_LINUX

#endif // __GNUC__

#endif // _LINUX_PLATFORM_H_