#pragma once
#include <cstdarg>
#include <cstdio>
#include "minhook/include/MinHook.h"

class DxPeggleNights
{
public:
	static HWND GWindow;
	static WNDPROC GOrigWndProc;
	static void debug(const char* prefix, const char* fmt, ...);
	static void doHook(HMODULE mod, const char* name, void* hook, void** orig);
	static void transformMouse(int inX, int inY, int& outX, int& outY);

	static int GVirtualW;
	static int GVirtualH;
};

