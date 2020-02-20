#include "CoreModule.h"
#include "Engine/Engine.inl"

#include <iostream>

CoreModule::CoreModule()
{

}

CoreModule::~CoreModule()
{
	SAFE_DELETE(gEngine);
}

void CoreModule::Initialize()
{
	std::cout << "Initialize Engine..." << std::endl;

	gEngine = new ICoreGlobalVariable();

	InitializeParams params;
	params.gEngine = gEngine;
	
	this->LoadEngineModules(params);

	std::cout << "The engine was successfully initialized." << std::endl;
}

void CoreModule::Run()
{
    m_isRunnig = true;

    while (m_isRunnig)
    {
        for (auto module : m_modules)
			module->object->Update();
    }
}

void CoreModule::Release()
{
    this->~CoreModule();
}

void CoreModule::Quit()
{
    m_isRunnig = false;
}

bool CoreModule::IsQuiting()
{
    return !m_isRunnig;
}

std::string CoreModule::GetRootDir()
{
    return std::string();
}

void CoreModule::LoadEngineModules(const InitializeParams& params)
{
    // [TODO]: Load modules names from XAML file

    for (auto& modl : modules)
	{
		EngineModule module = LoadModule(modl);

		////ASSERT(module, nullptr, "The loading module " + modl + " is not valid...");

		auto obj = EngineGetProcAddress<IEngineModule::TModulePoint>(module, "CreateEngineModule");

		//ASSERT(obj, nullptr, "Couldn't get function \"CreateEngineModule\"...");

		auto objectDll = obj();

		//ASSERT(objectDll, nullptr, "Couldn't create " + modl + " module object...");

		objectDll->RegisterEngineModule(params);

		m_modules.push_back(new Module(module, objectDll));
	}
}

void CoreModule::ReleaseEngineModules()
{
	for (auto module : m_modules)
		SAFE_RELEASE(module->object);
}

void CoreModule::EngineEvent(const EEngineEvent& event)
{
    
}