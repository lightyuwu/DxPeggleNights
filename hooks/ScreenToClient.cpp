#include "ScreenToClient.h"

namespace Hooks {

	ScreenToClient::ScreenToClient_t ScreenToClient::original = nullptr;

	BOOL WINAPI ScreenToClient::hook(HWND hWnd, LPPOINT lp) {
		DxPeggleNights::debug("Hook", "ScreenToClient\n");

		BOOL res = original(hWnd, lp);
		if (!res || !lp) return res;

		DxPeggleNights::debug("Hook", "ScreenToClient raw=%ld,%ld\n", lp->x, lp->y);

		int fx, fy;
		DxPeggleNights::transformMouse(lp->x, lp->y, fx, fy);

		lp->x = fx;
		lp->y = fy;

		DxPeggleNights::debug("Hook", "ScreenToClient fixed=%d,%d\n", fx, fy);

		return res;
	}


	void ScreenToClient::applyHooks() {
		HMODULE user32 = GetModuleHandleA("user32.dll");
		DxPeggleNights::doHook(user32, "ScreenToClient", (void*)ScreenToClient::hook, (void**)&ScreenToClient::original);
	}
}