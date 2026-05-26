#include "GetCursorPos.h"

namespace Hooks {

	GetCursorPos::GetCursorPos_t GetCursorPos::original = nullptr;

	BOOL WINAPI GetCursorPos::hook(LPPOINT lp) {
		DxPeggleNights::debug("HOOK", "GetCursorPos\n");

		BOOL res = original(lp);
		if (!res || !lp) return res;

		Hooks::ScreenToClient::original(DxPeggleNights::GWindow, lp);

		DxPeggleNights::debug("HOOK", "GetCursorPos raw=%ld,%ld\n", lp->x, lp->y);

		int fx, fy;
		DxPeggleNights::transformMouse(lp->x, lp->y, fx, fy);

		lp->x = fx;
		lp->y = fy;

		DxPeggleNights::debug("HOOK", "GetCursorPos fixed=%d,%d\n", fx, fy);

		return res;
	}


	void GetCursorPos::applyHooks() {
		HMODULE user32 = GetModuleHandleA("user32.dll");
		DxPeggleNights::doHook(user32, "GetCursorPos", (void*)GetCursorPos::hook, (void**)&GetCursorPos::original);
	}
}