#ifndef _I_CORE_MODULE_H_
#define _I_CORE_MODULE_H_

#include <string>
#include <cstdint>

enum class EEngineEvent : uint16_t
{
	EVENT_ENGINE_CORE_INIT_COMPLETE,
	EVENT_ENGINE_GLFW_INIT_COMPLETE,
	EVENT_ENGINE_SURFACE_INIT_COMPLETE,
	EVENT_ENGINE_RENDERER_INIT_COMPLETE
};

struct ICoreModule
{
    typedef ICoreModule* (*TModulePoint)();

    virtual ~ICoreModule() {}

    virtual void Initialize() = 0;
    virtual void Run() = 0;
    virtual void Release() = 0;
    virtual void Quit() = 0;
    virtual bool IsQuiting() = 0;
    virtual std::string GetModuleName() = 0;
    virtual std::string GetRootDir() = 0;
	virtual void LoadEngineModules(const InitializeParams& params) = 0;
    virtual void ReleaseEngineModules() = 0;
	virtual void EngineEvent(const EEngineEvent& event) = 0;
};

#endif // _I_CORE_MODULE_H_