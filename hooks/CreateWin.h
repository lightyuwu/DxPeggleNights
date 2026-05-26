#pragma once
#include <Windows.h>
#include "../DxPeggleNights.h"
#include "WndProc.h"

namespace Hooks {
	class CreateWin
	{
	private:
		typedef HWND(WINAPI* CreateA_t)(DWORD, LPCSTR, LPCSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);
		typedef HWND(WINAPI* CreateW_t)(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID);

		static CreateA_t oCreateA;
		static CreateW_t oCreateW;


		static HWND WINAPI hookCreateA(
			DWORD exStyle, LPCSTR cls, LPCSTR name, DWORD style,
			int x, int y, int w, int h, HWND parent, HMENU menu, HINSTANCE inst, LPVOID param);

		static HWND WINAPI hookCreateW(
			DWORD exStyle, LPCWSTR cls, LPCWSTR name, DWORD style,
			int x, int y, int w, int h, HWND parent, HMENU menu, HINSTANCE inst, LPVOID param);
	public:
		static void applyHooks();
	};
};

