#include "GLFWModule.h"

#include <iostream>

struct Point {};

Point GLFWModule::MousePos;

GLFWModule::GLFWModule()
{
}

GLFWModule::~GLFWModule()
{
	if (m_pWindow)
		glfwTerminate();
		
	gEngine->pCore->OnEngineEvent -= LISTENER(*this, GLFWModule::OnEngineEvent);
}

void GLFWModule::Initialize()
{
	if (!glfwInit())
		std::cout << "GLFW was not initialized" << std::endl; //FATAL_ERROR("GLFW was not initialized");

	m_pWindow = glfwCreateWindow(1280, 920, "RenderVulkan", NULL, NULL);

	if (!m_pWindow)
	{
		//FATAL_ERROR("Can't create glfw window");
		glfwTerminate();
	}

	glfwMakeContextCurrent(m_pWindow);

	glfwSetKeyCallback(m_pWindow, SetKeyCallback);
	glfwSetCursorPosCallback(m_pWindow, SetCursorPosCallback);
	glfwSetWindowSizeCallback(m_pWindow, SetWindowSizeCallback);
	glfwSetMouseButtonCallback(m_pWindow, SetMouseButtonCallback);

	//gEngine->pSurface = new ISurface(glfwGetWin32Window(m_pWindow));

	gEngine->pCore->EngineEvent(EEngineEvent::EVENT_ENGINE_SURFACE_INIT_COMPLETE);
}

void GLFWModule::Update()
{
	if (!glfwWindowShouldClose(m_pWindow))
	{
		glfwPollEvents();
	}
	else
	{
		gEngine->pCore->Quit();
	}
}

void GLFWModule::Release()
{
	//_Log("Releasing the module...");

	this->~GLFWModule();
}

void GLFWModule::RegisterEngineModule(const InitializeParams& params)
{
	gEngine = params.gEngine;

	gEngine->pCore->OnEngineEvent += LISTENER(*this, GLFWModule::OnEngineEvent);

	//_LogSuccess("Module has been loaded.");
}

void GLFWModule::OnEngineEvent(const EEngineEvent& event)
{
	switch (event)
	{
	case EEngineEvent::EVENT_ENGINE_CORE_INIT_COMPLETE:
		Initialize();
		break;
	}
}

void GLFWModule::SetWindowSizeCallback(GLFWwindow* window, int width, int height)
{
	//emit gEngine->pSurface->EmitOnSurfaceSizeEvent(width, height);
}

void GLFWModule::SetCursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	/*HoverEvent event(Point(xpos, ypos), GLFWModule::MousePos);
	GLFWModule::MousePos = Point(xpos, ypos);
	emit gEngine->pSurface->EmitOnHoverEvent(event);*/
}

void GLFWModule::SetKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	/*if (action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		GLFWModule::MousePos = Point(xpos, ypos);

		MouseEvent event(MousePos);
		emit gEngine->pSurface->EmitOnMousePressEvent(event);
	}*/
}

void GLFWModule::SetMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	/*double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	GLFWModule::MousePos = Point(xpos, ypos);

	MouseEvent event(MousePos);

	switch (action)
	{
	case GLFW_PRESS:
	{
		emit gEngine->pSurface->EmitOnMousePressEvent(event);
		break;
	}
	case GLFW_RELEASE:
	{
		emit gEngine->pSurface->EmitOnMouseReleaseEvent(event);
		break;
	}
	}*/
}
