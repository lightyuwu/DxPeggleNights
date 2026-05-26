#include "CreateWin.h"

namespace Hooks {
	CreateWin::CreateA_t CreateWin::oCreateA = nullptr;
	CreateWin::CreateW_t CreateWin::oCreateW = nullptr;

	HWND WINAPI CreateWin::hookCreateA(
		DWORD exStyle, LPCSTR cls, LPCSTR name, DWORD style,
		int x, int y, int w, int h, HWND parent, HMENU menu, HINSTANCE inst, LPVOID param) {

		HWND window = oCreateA(exStyle, cls, name, style, x, y, w, h, parent, menu, inst, param);
		
		// Steal window if this is a valid and we have none
		if (window && !DxPeggleNights::GWindow) {
			DxPeggleNights::GWindow = window;
			DxPeggleNights::GOrigWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)Hooks::WndProc::hook);
			DxPeggleNights::debug("Initialize", "HWND via CreateWindowExA: %p\n", window);
		}

		return window;
	}

	HWND WINAPI CreateWin::hookCreateW(
		DWORD exStyle, LPCWSTR cls, LPCWSTR name, DWORD style,
		int x, int y, int w, int h, HWND parent, HMENU menu, HINSTANCE inst, LPVOID param) {
		HWND window = oCreateW(exStyle, cls, name, style, x, y, w, h, parent, menu, inst, param);
		
		// Steal window if this is a valid and we have none
		if (window && !DxPeggleNights::GWindow) {
			DxPeggleNights::GWindow = window;
			DxPeggleNights::GOrigWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)Hooks::WndProc::hook);
			DxPeggleNights::debug("Initialize", "HWND via CreateWindowExW: %p\n", window);
		}

		return window;
	}

	void CreateWin::applyHooks() {
		HMODULE user32 = GetModuleHandleA("user32.dll");

		DxPeggleNights::doHook(user32, "CreateWindowExA", (void*)hookCreateA, (void**)&oCreateA);
		DxPeggleNights::doHook(user32, "CreateWindowExW", (void*)hookCreateW, (void**)&oCreateW);

	}
}