
#include "Engine/Engine.h"

int main()
{
    EngineModule module = LoadModule("Engine.Core");
	ICoreModule* pEngineCore = EngineGetProcAddress<ICoreModule::TModulePoint>(module, "CreateEngineCoreModule")();

	pEngineCore->Initialize();
	pEngineCore->Run();
	pEngineCore->Release();

    return 0;
}