#include "pch.h"
#include "LibConfig.h"
#include "DxPeggleNights.h"

void LibConfig::createDefaultConfig() {
    DxPeggleNights::debug("CFG", "Path: %ws", _getFullPath());
    // Use -1 as sentinel — not a valid resolution value
    if (GetPrivateProfileInt(CResolution, CResolution_Width, -1, _getFullPath()) == -1)
        WritePrivateProfileString(CResolution, CResolution_Width, L"800", _getFullPath());

    if (GetPrivateProfileInt(CResolution, CResolution_Height, -1, _getFullPath()) == -1)
        WritePrivateProfileString(CResolution, CResolution_Height, L"600", _getFullPath());
}

int LibConfig::getFromConfig(LPCWSTR category, LPCWSTR name, int fallback) {
	int value = GetPrivateProfileInt(category, name, fallback, _getFullPath());
	return value;
}

LPCWSTR LibConfig::_getFullPath() {
    static wchar_t fullPath[MAX_PATH];
    HMODULE hMod = NULL;

    // Get handle to our own DLL
    GetModuleHandleExW(
        GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
        (LPCWSTR)&LibConfig::_getFullPath,
        &hMod
    );

    GetModuleFileNameW(hMod, fullPath, MAX_PATH);  // Get full DLL path
    PathRemoveFileSpecW(fullPath);                  // Strip filename, keep directory
    wcscat_s(fullPath, L"\\DxPeggleNights.ini");   // Append ini filename

    return fullPath;
}