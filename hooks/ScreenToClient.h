#pragma once
#include <Windows.h>
#include "../DxPeggleNights.h"

namespace Hooks {
	class ScreenToClient {
	private:
		typedef BOOL(WINAPI* ScreenToClient_t)(HWND, LPPOINT);
		static BOOL WINAPI hook(HWND hWnd, LPPOINT lp);
	public:
		static ScreenToClient_t original;
		static void applyHooks();
	};
}