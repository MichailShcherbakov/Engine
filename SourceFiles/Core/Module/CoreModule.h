#ifndef _CORE_H_
#define _CORE_H_

#include <vector>
#include <Engine/Engine.h>

class CoreModule final : public ICoreModule
{
    struct Module
	{
		EngineModule module;
		IEngineModule* object;

		Module(const EngineModule& module, IEngineModule* object)
		{
			this->module = module;
			this->object = object;
		}

		~Module()
		{
			if (object)
				delete object;

			EngineModuleFree(module);
			object = nullptr;
		}
	};

	using Modules = std::vector<Module*>;

public:
    CoreModule();
    ~CoreModule() override;

public:
    // ICoreModule
    virtual void Initialize() override;
    virtual void Run() override;
    virtual void Release() override;
    virtual void Quit() override;
    virtual bool IsQuiting() override;
    virtual std::string GetModuleName() override { return std::string("Engine.Core"); };
    virtual std::string GetRootDir() override;
	virtual void LoadEngineModules(const InitializeParams& params) override;
    virtual void ReleaseEngineModules() override;
	virtual void EngineEvent(const EEngineEvent& event) override;
    // ~ICoreModule

private:
    bool m_isRunnig = false;
    Modules m_modules;

private:
	std::vector<std::string> modules = 
	{
		//"Engine.GLFW", // Surface::Renderer
		//"Engine.RenderVulkan", // Type::Renderer
		"Engine.RendererOpenGL", // Type::Renderer
	};
};

ENGINE_CORE_MODULE(CoreModule)

#endif // _CORE_H_