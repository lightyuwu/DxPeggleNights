#include "D3D9.h"

namespace Hooks {

	D3D9::Present_t D3D9::originalPresent = nullptr;
	D3D9::Reset_t D3D9::originalReset = nullptr;

	HRESULT WINAPI D3D9::hookReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* param) {
		DxPeggleNights::debug("DX9", "Reset %ux%u Windowed=%d\n",
			param->BackBufferWidth,
			param->BackBufferHeight,
			param->Windowed
		);

		return originalReset(device, param);
	}

	HRESULT __stdcall D3D9::hookPresent(
		IDirect3DDevice9* device,
		CONST RECT* src,
		CONST RECT* dest,
		HWND win,
		CONST RGNDATA* region) {

		// Return original if we didn't capture the window
		if (!DxPeggleNights::GWindow)
			return originalPresent(device, src, dest, win, region);
		
		// Window Size
		RECT r;
		GetClientRect(DxPeggleNights::GWindow, &r);
		int w = r.right - r.left;
		int h = r.bottom - r.top;

		// Invalid Size => error, don't leave it unhandled though
		if (!(w > 0 && h > 0))
			return originalPresent(device, src, dest, win, region);
		
		// Calculate size
		float scale = min((float)w / (float)DxPeggleNights::GVirtualW, (float)h / (float)DxPeggleNights::GVirtualH);
		int gameW = (int)((float)DxPeggleNights::GVirtualW * scale);
		int gameH = (int)((float)DxPeggleNights::GVirtualH * scale);
		int left = (w - gameW) / 2;

		// Get back buffer
		IDirect3DSurface9* back = nullptr;
		HRESULT hrGB = device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &back);
		DxPeggleNights::debug("DX9", "Present %dx%d gameArea=%dx%d+%d bbp=%p hr=%08X\n", w, h, gameW, gameH, left, back, hrGB);

		// If we have a valid back buffer
		if ( SUCCEEDED(hrGB) )
		{
			// Draw the fixed borders (left and right)
			if (left > 0)
			{
				RECT border = { 0, 0, left, h };
#if PN_DEBUG_SIDE_BARS
				HRESULT hrCF = device->ColorFill(back, &border, D3DCOLOR_XRGB(0xff, 0, 0));
#else
				HRESULT hrCF = device->ColorFill(back, &border, D3DCOLOR_XRGB(0, 0, 0));
#endif
				DxPeggleNights::debug("DX9", "ColorFill left hr=%08X\n", hrCF);
			}
			int rightEdge = left + gameW;
			if (rightEdge < w)
			{
				RECT border = { rightEdge, 0, w, h };
#if PN_DEBUG_SIDE_BARS
				HRESULT hrCF = device->ColorFill(back, &border, D3DCOLOR_XRGB(0xff, 0, 0));
#else
				HRESULT hrCF = device->ColorFill(back, &border, D3DCOLOR_XRGB(0, 0, 0));
#endif
				DxPeggleNights::debug("DX9", "ColorFill right hr=%08X\n", hrCF);
			}

			// Release the back buffer
			back->Release();
		}
		

		return originalPresent(device, src, dest, win, region);
	}
}