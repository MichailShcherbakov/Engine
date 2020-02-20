#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <string>

// Memory
#include "Memory.h"

// Global Variable
#include "GlobalVariable.h"

// Modules
#include "ICoreModule.h"
#include "IEngineModule.h"

// Platforms
#include "Platforms/Win32.h"
#include "Platforms/Linux.h"



#define REGISTER_ENGINE_MODULE(name)                                \
extern "C"                                                          \
{                                                                   \
	DLL_EXPORT IEngineModule* ENGINE_API CreateEngineModule()        \
	{                                                               \
		return new name();                                          \
	}                                                               \
};                                                                  \

#define ENGINE_CORE_MODULE(name)                                    \
extern "C"                                                          \
{                                                                   \
	DLL_EXPORT ICoreModule* ENGINE_API CreateEngineCoreModule()      \
	{                                                               \
		return new name();                                          \
	}                                                               \
};                                                                  \

static EngineModule LoadModule(const std::string& path)
{
	EngineModule module = nullptr;

#ifdef USE_PLATFORM_WINDOWS
	std::string dllPath = "lib" + path + ".dll";
	module = LoadLibraryA(dllPath.c_str());
#endif

#ifdef USE_PLATFORM_LINUX
	std::string soPath = ".bin/lib" + path + ".so";
	module = dlopen(soPath.c_str(), RTLD_NOW | RTLD_LOCAL);
#endif

	return module;
}

template<typename D>
static D EngineGetProcAddress(EngineModule moule, const std::string& func)
{
#ifdef USE_PLATFORM_WINDOWS
	return reinterpret_cast<D>(GetProcAddress(moule, func.c_str()));
#endif

#ifdef USE_PLATFORM_LINUX
	return reinterpret_cast<D>(dlsym(moule, func.c_str()));
#endif 
}

static void EngineModuleFree(EngineModule module)
{
#ifdef USE_PLATFORM_WINDOWS
	FreeLibrary(module);
#endif

#ifdef USE_PLATFORM_LINUX
	dlclose(module);
#endif 
}

#endif // _ENGINE_H_