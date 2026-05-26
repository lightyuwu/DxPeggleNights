#include "Direct3D9Create.h"

namespace Hooks {

	Direct3D9Create::Direct3DCreate9_t Direct3D9Create::original = nullptr;

	IDirect3D9* WINAPI Direct3D9Create::hook(UINT sdk) {
		DxPeggleNights::debug("DX9", "Direct3DCreate9\n");

		IDirect3D9* d3d = original(sdk);

		if (d3d)
		{
			void** vtbl = *reinterpret_cast<void***>(d3d);

			MH_CreateHook(vtbl[16], Hooks::CreateDevice::hook, reinterpret_cast<void**>(&Hooks::CreateDevice::original));
			MH_EnableHook(vtbl[16]);
		}

		return d3d;
	}


	void Direct3D9Create::applyHooks() {
		HMODULE d3d9 = GetModuleHandleA("d3d9.dll");
		DxPeggleNights::doHook(d3d9, "Direct3DCreate9", (void*)Direct3D9Create::hook, (void**)&Direct3D9Create::original);
	}
}