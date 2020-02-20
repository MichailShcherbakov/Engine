#ifndef _RENDERER_OPENGL_MODULE_H_
#define _RENDERER_OPENGL_MODULE_H_

#include "Engine/Engine.h"

class RendererOpenGLModule final : public IEngineModule
{
public:
 	RendererOpenGLModule();
    ~RendererOpenGLModule() override;

public:
    virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual std::string GetModuleName() { return "Engine.RendererModule"; }
	virtual void RegisterEngineModule(const InitializeParams& params) override;
	virtual void OnEngineEvent(const EEngineEvent& event) override;
};

REGISTER_ENGINE_MODULE(RendererOpenGLModule)

#endif // MODULE_SOURCE