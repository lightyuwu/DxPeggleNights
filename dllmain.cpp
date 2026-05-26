// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "dxpncfg.h"
#include "minhook/include/MinHook.h"
#include "hooks/WndProc.h"
#include "hooks/GetCursorPos.h"
#include "hooks/SetCursorPos.h"
#include "hooks/ScreenToClient.h"
#include "hooks/CreateWin.h"
#include "hooks/Direct3D9Create.h"

void installHooks() {
    Hooks::GetCursorPos::applyHooks();
    Hooks::ScreenToClient::applyHooks();
    Hooks::SetCursorPos::applyHooks();
    Hooks::CreateWin::applyHooks();
    Hooks::Direct3D9Create::applyHooks();
}


#if PN_DEBUG_ENABLED
static void initConsole()
{
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	DxPeggleNights::debug("DX9", "Logger started\n");
}
#endif

DWORD WINAPI mainThread(LPVOID)
{
#if PN_DEBUG_ENABLED
	initConsole();
#endif
	return 0;
}



BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);

		if (MH_Initialize() == MH_OK)
			installHooks();

		CreateThread(nullptr, 0, mainThread, nullptr, 0, nullptr);
	}
	return TRUE;
}
