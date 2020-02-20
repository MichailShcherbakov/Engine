#include "RendererOpenGLModule.h"

RendererOpenGLModule::RendererOpenGLModule()
{

}

RendererOpenGLModule::~RendererOpenGLModule()
{

}

void RendererOpenGLModule::Initialize()
{

}

void RendererOpenGLModule::Update() 
{

}

void RendererOpenGLModule::Release() 
{
    this->~RendererOpenGLModule();
}

void RendererOpenGLModule::RegisterEngineModule(const InitializeParams& params) 
{
}

void RendererOpenGLModule::OnEngineEvent(const EEngineEvent& event) 
{

}