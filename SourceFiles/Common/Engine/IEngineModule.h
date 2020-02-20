#ifndef _I_ENGINE_MODULE_H_
#define _I_ENGINE_MODULE_H_

#include <string>

struct IEngineModule
{
    typedef IEngineModule* (*TModulePoint)();

    virtual ~IEngineModule() {}

    virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;
	virtual std::string GetModuleName() = 0;
	virtual void RegisterEngineModule(const InitializeParams& params) = 0;
	virtual void OnEngineEvent(const EEngineEvent& event) = 0;
};

#endif // _I_ENGINE_MODULE_H_