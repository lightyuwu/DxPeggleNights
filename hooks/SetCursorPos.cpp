#include "SetCursorPos.h"

namespace Hooks {

	SetCursorPos::SetCursorPos_t SetCursorPos::original = nullptr;

	BOOL WINAPI SetCursorPos::hook(int X, int Y) {
		DxPeggleNights::debug("Hook", "SetCursorPos %d,%d\n", X, Y);

		if (DxPeggleNights::GWindow) {
			RECT r;
			GetClientRect(DxPeggleNights::GWindow, &r);
			int w = r.right - r.left;
			int h = r.bottom - r.top;

			if (w > 0 && h > 0)
			{
				float scale = min((float)w / (float)DxPeggleNights::GVirtualW, (float)h / (float)DxPeggleNights::GVirtualH);
				int gameW = (int)((float)DxPeggleNights::GVirtualW * scale);
				int gameH = (int)((float)DxPeggleNights::GVirtualH * scale);
				int left = (w - gameW) / 2;
				int top = (h - gameH) / 2;

				int cx = left + X * gameW / DxPeggleNights::GVirtualW;
				int cy = top + Y * gameH / DxPeggleNights::GVirtualH;

				POINT pt = { cx, cy };
				ClientToScreen(DxPeggleNights::GWindow, &pt);
				return original(pt.x, pt.y);
			}
		}

		return original(X, Y);
	}


	void SetCursorPos::applyHooks() {
		HMODULE user32 = GetModuleHandleA("user32.dll");
		DxPeggleNights::doHook(user32, "SetCursorPos", (void*)SetCursorPos::hook, (void**)&SetCursorPos::original);
	}
}