#pragma once
#include <Windows.h>
#include <d3d9.h>
#include "../DxPeggleNights.h"
#include "CreateDevice.h"

namespace Hooks {
	class Direct3D9Create {
	private:
		typedef IDirect3D9* (WINAPI* Direct3DCreate9_t)(UINT);
		static Direct3DCreate9_t original;
		static IDirect3D9* WINAPI hook(UINT sdk);
	public:
		static void applyHooks();
	};
}