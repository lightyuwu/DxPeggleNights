#pragma once
#include <Windows.h>
#include <d3d9.h>
#include "../DxPeggleNights.h"
#include "ScreenToClient.h"
#include "../dxpncfg.h"

namespace Hooks {
	class D3D9 {
	private:
		typedef HRESULT(__stdcall* Present_t)(
			IDirect3DDevice9*,
			CONST RECT*,
			CONST RECT*,
			HWND,
			CONST RGNDATA*
			);

		typedef HRESULT(WINAPI* Reset_t)(
			IDirect3DDevice9*,
			D3DPRESENT_PARAMETERS*
			);
	public:
		static Present_t originalPresent;
		static Reset_t originalReset;

		static HRESULT WINAPI hookReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* param);

		static HRESULT __stdcall hookPresent(
			IDirect3DDevice9* device,
			CONST RECT* src,
			CONST RECT* dest,
			HWND win,
			CONST RGNDATA* region);

		// No applyHooks(); here as it is done differently.
	};
}