#include "CreateDevice.h"

namespace Hooks {

	CreateDevice::CreateDevice_t CreateDevice::original = nullptr;

	HRESULT WINAPI CreateDevice::hook(
		IDirect3D9* self,
		UINT Adapter,
		D3DDEVTYPE Type,
		HWND hwnd,
		DWORD flags,
		D3DPRESENT_PARAMETERS* pp,
		IDirect3DDevice9** out) {

		HRESULT hr = original(self, Adapter, Type, hwnd, flags, pp, out);

		if (SUCCEEDED(hr) && out && *out)
		{
			DxPeggleNights::GWindow = hwnd;

			DxPeggleNights::debug("DX9", "HWND captured : % p\n", DxPeggleNights::GWindow);

			void** vtbl = *reinterpret_cast<void***>(*out);

			MH_CreateHook(vtbl[16], Hooks::D3D9::hookReset, reinterpret_cast<void**>(&Hooks::D3D9::originalReset));
			MH_EnableHook(vtbl[16]);

			MH_CreateHook(vtbl[17], Hooks::D3D9::hookPresent, reinterpret_cast<void**>(&Hooks::D3D9::originalPresent));
			MH_EnableHook(vtbl[17]);

			if (DxPeggleNights::GWindow && !DxPeggleNights::GOrigWndProc)
			{
				DxPeggleNights::GOrigWndProc = (WNDPROC)SetWindowLongPtr(
					DxPeggleNights::GWindow,
					GWLP_WNDPROC,
					(LONG_PTR)Hooks::WndProc::hook
				);

				DxPeggleNights::debug("DX9", "WndProc hooked\n");
			}
		}

		return hr;
	}
}