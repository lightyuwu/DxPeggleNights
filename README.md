# DxPeggleNights
A fix for Peggle Nights that fixed DxWrapper Fullscreen Properly!



## Credits:

DxWrapper: https://github.com/elishacloud/dxwrapper

MinHook: https://github.com/TsudaKageyu/minhook



## Disclaimer:

Peggle Nights is a Trademark of PopCap Games, Inc. which is a subsidiary of Electronic Arts (EA).

Lighty (@lightyuwu), and DxPeggleNights are not affiliated with Electronic Arts or PopCap Games, Inc. 

DxPeggleNights does not infringe on any copyrights, it simply fixes a compatibility issue when using "DxWrapper"



## Installation:

1. Download the latest release of [DxWrapper](https://github.com/elishacloud/dxwrapper/releases/latest)

2. Download the latest release of [DxPeggleNights](https://github.com/lightyuwu/DxPeggleNights/releases/latest) (do not download DxPeggleNights.debug.dll unless you absolutely need)

3. Extract the DxWrapper .zip

4. Copy dxwrapper.dll & dxwrapper.ini into C:\ProgramData\PopCap Games\PeggleNights\

5. Go into the "Stub" folder of the Extracted DxWrapper, and copy the ddraw.dll into C:\ProgramData\PopCap Games\PeggleNights\

6. Copy the DxPeggleNights.dll into C:\ProgramData\PopCap Games\PeggleNights\

Your C:\ProgramData\PopCap Games\PeggleNights\ folder should now look something like this: 

```
PeggleNights/
├── ddraw.dll
├── DxPeggleNights.dll
├── dxwrapper.dll
├── dxwrapper.ini
└── popcapgame1.exe (might not be there, both cases are fine)
```

7. Open the dxwrapper.ini in any text editor (even notepad)

8. Delete everything in the file, and replace it with this:
```ini
;; Config file for DirectX DLL Wrapper
;;
;; For details, see: https://github.com/elishacloud/dxwrapper/wiki/Configuration
;;
[General]
RealDllPath                = AUTO
WrapperMode                = AUTO
LoadCustomDllPath          = DxPeggleNights.dll
ExcludeProcess             = 
IncludeProcess             = 
RunProcess                 = 
WaitForProcess             = 0
DisableLogging             = 0

[Plugins]
LoadPlugins                = 0
LoadFromScriptsOnly        = 0

[Compatibility]
Dd7to9                     = 1
D3d8to9                    = 1
D3d9to9Ex                  = 0
D3d9on12                   = 0
DDrawCompat                = 0
Dinputto8                  = 0
DisableGameUX              = 0
EnableDdrawWrapper         = 0
EnableD3d9Wrapper          = 0
EnableDinput8Wrapper       = 0
EnableDsoundWrapper        = 0
DisableGDIGammaRamp        = 0
EnableOpenDialogHook       = 0
WinVersionLie              = off
WinVersionLieSP            = 0
ForceKeyboardLayout        = 0
FixPerfCounterUptime       = 0
HandleExceptions           = 1
SingleProcAffinity         = 0

[DDrawCompat]
DDrawCompat20              = 0
DDrawCompat21              = 0
DDrawCompat32              = 0
DDrawCompatDisableGDIHook  = 0
DDrawCompatNoProcAffinity  = 0

[ddraw]
DdrawOverrideBitMode       = 0
DdrawUseDirect3D9Caps      = 0

[Dd7to9]
DdrawAutoFrameSkip         = 0
DdrawEmulateSurface        = 1
DdrawEmulateLock           = 1
DdrawUseShadowSurface      = 0
DdrawKeepAllInterfaceCache = 0
DdrawAllowMultiSampling    = 0
DdrawForceMipMapAutoGen    = 0
DdrawClampVertexZDepth     = 0
DdrawEnableByteAlignment   = 0
DdrawFixByteAlignment      = 0
DdrawIntroVideoFix         = 0
DdrawFilterActivateApp     = 0
DdrawRemoveScanlines       = 0
DdrawRemoveInterlacing     = 0
DdrawReadFromGDI           = 0
DdrawWriteToGDI            = 0
DdrawLimitTextureFormats   = 0
DdrawLimitDisplayModeCount = 1
DdrawCustomWidth           = 0
DdrawCustomHeight          = 0
DdrawLinearTextureFilter   = 0
DdrawUseNativeResolution   = 1
DdrawOverrideWidth         = 0
DdrawOverrideHeight        = 0
DdrawOverrideStencilFormat = 0
DdrawIntegerScalingClamp   = 0
DdrawMaintainAspectRatio   = 1

[d3d9]
AnisotropicFiltering       = 0
AntiAliasing               = 0
EnableMultisamplingATOC    = 0
EnvironmentCubeMapFix      = 0
ForceMipMapAutoGen         = 0
DepthBiasFactor            = 0
DepthBiasDropOffValue      = 0
EnableVSync                = 0
ForceVsyncMode             = 0
ShowFPSCounter             = 0
OverrideRefreshRate        = 0
LimitDisplayModeCount      = 0
CustomDisplayWidth         = 0
CustomDisplayHeight        = 0
LimitPerFrameFPS           = 60
EnableWindowMode           = 1
WindowModeBorder           = 0
WindowModeGammaShader      = 0
SetInitialWindowPosition   = 0
InitialWindowPositionLeft  = 0
InitialWindowPositionTop   = 0
FullscreenWindowMode       = 1
HideWindowFocusChanges     = 0
ForceExclusiveFullscreen   = 0
ForceMixedVertexProcessing = 0
ForceSystemMemVertexCache  = 0
UseShadowBackbuffer        = 0
OverrideStencilFormat      = 0
FlipEx                     = 0
SetSwapEffectShim          = 0
DisableMaxWindowedMode     = 0
GraphicsHybridAdapter      = 0

[FullScreen]
FullScreen                 = 1
ForceWindowResize          = 0
WaitForWindowChanges       = 0

[dinput8]
DeviceLookupCacheTime      = 0
FilterNonActiveInput       = 0
FixHighFrequencyMouse      = 0
MouseMovementFactor        = 0
MouseMovementPadding       = 0

[dsound]
Num2DBuffers               = 0
Num3DBuffers               = 0
ForceCertification         = 0
ForceExclusiveMode         = 0
ForceSoftwareMixing        = 0
ForceHardwareMixing        = 0
ForceHQ3DSoftMixing        = 0
ForceNonStaticBuffers      = 0
ForceVoiceManagement       = 0
ForcePrimaryBufferFormat   = 0
PrimaryBufferBits          = 16
PrimaryBufferSamples       = 44100
PrimaryBufferChannels      = 2
AudioClipDetection         = 0
```


9. Congrats! You now have working fullscreen mode in Peggle Nights!