#ifndef _GLFW_MODULE_H_
#define _GLFW_MODULE_H_

#include <Engine/Engine.h>

#define GLFW_EXPOSE_NATIVE_WIN32

#include "glfw3.h"
#include "glfw3native.h"

struct Point;
class GLFWModule : public IEngineModule
{
public:
	GLFWModule();
	~GLFWModule() override;

public:
	// IEngineModule
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;
	virtual std::string GetModuleName() { return "Engine.GLFW"; }
	virtual void RegisterEngineModule(const InitializeParams& params)  override;
	virtual void OnEngineEvent(const EEngineEvent& event) override;
	// ~IEngineModule

public:
	static void SetWindowSizeCallback(GLFWwindow* window, int width, int height);
	static void SetCursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void SetKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void SetMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

private:
	GLFWwindow* m_pWindow = nullptr;
	
public:
	static Point MousePos;

private:
	IEngineModule* m_pGraphicsModule = nullptr;
};

REGISTER_ENGINE_MODULE(GLFWModule)

#endif // _RENDERER_VULKAN_MODULE_H_