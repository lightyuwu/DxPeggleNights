#include "WndProc.h"

namespace Hooks {
	LRESULT WINAPI WndProc::hook(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// Intercept X and Y positions for EVERY mouse event
		switch (msg)
		{
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MBUTTONDBLCLK:
		case WM_XBUTTONDOWN:
		case WM_XBUTTONUP:
		case WM_XBUTTONDBLCLK:
		case WM_MOUSEWHEEL:
		case WM_MOUSEHWHEEL:
		{
			int x = (int)(short)LOWORD(lParam);
			int y = (int)(short)HIWORD(lParam);

			int fx, fy;
			DxPeggleNights::transformMouse(x, y, fx, fy);

			lParam = MAKELPARAM(fx, fy);
			break;
		}
		}

		return CallWindowProc(DxPeggleNights::GOrigWndProc, hwnd, msg, wParam, lParam);
	}
}