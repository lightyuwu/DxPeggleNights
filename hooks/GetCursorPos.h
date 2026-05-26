#pragma once
#include <Windows.h>
#include "../DxPeggleNights.h"
#include "ScreenToClient.h"

namespace Hooks {
	class GetCursorPos {
	private:
		typedef BOOL(WINAPI* GetCursorPos_t)(LPPOINT);
		static GetCursorPos_t original;
		static BOOL WINAPI hook(LPPOINT lp);
	public:
		static void applyHooks();
	};
}