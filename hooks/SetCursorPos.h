#pragma once
#include <Windows.h>
#include "../DxPeggleNights.h"

namespace Hooks {
	class SetCursorPos {
	private:
		typedef BOOL(WINAPI* SetCursorPos_t)(int, int);
		static SetCursorPos_t original;
		static BOOL WINAPI hook(int X, int Y);
	public:
		static void applyHooks();
	};
}