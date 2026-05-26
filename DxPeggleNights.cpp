#include "pch.h"
#include "DxPeggleNights.h"
#include "dxpncfg.h"

HWND DxPeggleNights::GWindow = nullptr;
WNDPROC DxPeggleNights::GOrigWndProc = nullptr;

int DxPeggleNights::GVirtualW = 800;
int DxPeggleNights::GVirtualH = 600;

void DxPeggleNights::debug(const char* prefix, const char* fmt, ...)
{
#if PN_DEBUG_ENABLED
    printf("[%s] ", prefix);
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
#endif
}

void DxPeggleNights::doHook(HMODULE mod, const char* name, void* hook, void** orig)
{
    void* fn = GetProcAddress(mod, name);
    if (fn && MH_CreateHook(fn, hook, orig) == MH_OK)
        MH_EnableHook(fn);
};

void DxPeggleNights::transformMouse(int inX, int inY, int& outX, int& outY)
{
	if (!GWindow) { outX = inX; outY = inY; return; }

	RECT r;
	GetClientRect(GWindow, &r);
	int w = r.right - r.left;
	int h = r.bottom - r.top;
	if (w <= 0 || h <= 0) { outX = inX; outY = inY; return; }

	// Compute the letterboxed game area (aspect-correct, centered)
	float scaleX = (float)w / (float)GVirtualW;
	float scaleY = (float)h / (float)GVirtualH;
	float scale = min(scaleX, scaleY);         // fit-inside scaling

	int gameW = (int)(GVirtualW * scale);
	int gameH = (int)(GVirtualH * scale);
	int leftBar = (w - gameW) / 2;              // black bar width on each side
	int topBar = (h - gameH) / 2;              // black bar height top/bottom

	// Strip the letterbox offset, then scale into virtual space
	float vx = (float)(inX - leftBar) / scale;
	float vy = (float)(inY - topBar) / scale;

	// Clamp to virtual resolution
	outX = (int)max(0.0f, min(vx, (float)(GVirtualW - 1)));
	outY = (int)max(0.0f, min(vy, (float)(GVirtualH - 1)));
}
