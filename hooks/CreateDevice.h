#pragma once
#include <Windows.h>
#include <d3d9.h>
#include "../DxPeggleNights.h"
#include "WndProc.h"
#include "D3D9.h"

namespace Hooks {
	class CreateDevice {
	private:
		typedef HRESULT(WINAPI* CreateDevice_t)(
			IDirect3D9*,
			UINT,
			D3DDEVTYPE,
			HWND,
			DWORD,
			D3DPRESENT_PARAMETERS*,
			IDirect3DDevice9**
			);
	public:
		static HRESULT WINAPI hook(
			IDirect3D9* self,
			UINT Adapter,
			D3DDEVTYPE Type,
			HWND hwnd,
			DWORD flags,
			D3DPRESENT_PARAMETERS* pp,
			IDirect3DDevice9** out);
		static CreateDevice_t original;

		// no applyHooks(); as this is done differently
	};
}