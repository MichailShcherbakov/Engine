#ifndef _GLOBAL_VARIABLE_H_
#define _GLOBAL_VARIABLE_H_

struct ICoreModule;
struct ILogSystem;
struct ISurface;

struct IECS
{
	void* pComponentManager = nullptr;
	void* pEntityManager = nullptr;
	void* pSystemManager = nullptr;
};

struct ICoreGlobalVariable
{
    ~ICoreGlobalVariable()
    {
        SAFE_DELETE(pCore);
        SAFE_DELETE(pLogSystem);
        SAFE_DELETE(pSurface);
        SAFE_DELETE(pECS);
    }

	ICoreModule* pCore = nullptr;
	ILogSystem* pLogSystem = nullptr;
	ISurface* pSurface = nullptr;

	IECS* pECS = nullptr;
};

struct InitializeParams
{
	ICoreGlobalVariable* gEngine;
};

extern ICoreGlobalVariable* gEngine;

#endif // _GLOBAL_VARIABLE_H_