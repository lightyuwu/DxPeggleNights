#pragma once
#include <string>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

class LibConfig {
public:
	inline static const LPCWSTR CResolution = L"Resolution";
	inline static const LPCWSTR CResolution_Width = L"DefaultGameWidth";
	inline static const LPCWSTR CResolution_Height = L"DefaultGameHeight";

	inline static const LPCWSTR CConfigPath = L"DxPeggleNights.ini";


	static void createDefaultConfig();
	static int getFromConfig(LPCWSTR category, LPCWSTR name, int fallback);

private:
	static LPCWSTR _getFullPath();
};