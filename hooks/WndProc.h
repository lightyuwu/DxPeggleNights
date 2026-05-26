#pragma once
#include <Windows.h>
#include "../DxPeggleNights.h"

namespace Hooks {
	class WndProc {
	public:
		static LRESULT WINAPI hook(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	};
}