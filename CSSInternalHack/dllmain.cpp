// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "windows.h"
#include "EntityList.h"
#include "Engine.h"
#include "IVDebugOverlay.h"
#include "Interfaces.h"
#include "util.h"
#include "CBaseEntity.h"
#include "Esp.h"
#include <ostream>
#include <sstream>
DWORD WINAPI Main(HMODULE hModule)
{
	Interfaces* I = new Interfaces();
	ESP esp = ESP(I);
	//CBaseEntity* player1 = reinterpret_cast<CBaseEntity*>(entityList->GetClientEntity(2));
	//player_info_t info;
	bool quit = false;
	while (!quit)
	{
		esp.Draw();
		if (GetAsyncKeyState(VK_END) & 1)
		{
			quit = true;
		}
		Sleep(10);
	}
	MessageBox(0, L"Uninjected", L"CSSInternalHack", MB_OK);
	FreeLibraryAndExitThread(hModule, 0);
	return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		MessageBox(0, L"Injected", L"CSSInternalHack", MB_OK);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, hModule, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

