<html>
<body>
<pre>
<h1>Build Log</h1>
<h3>
--------------------Configuration: WLanOnOff - Win32 (WCE ARMV4I) Release--------------------
</h3>
<h3>Command Lines</h3>
Creating command line "rc.exe /l 0x409 /fo"ARMV4IRel/WLanOnOff.res" /d UNDER_CE=500 /d _WIN32_WCE=500 /d "UNICODE" /d "_UNICODE" /d "NDEBUG" /d "WCE_PLATFORM_BIP5000R" /d "THUMB" /d "_THUMB_" /d "ARM" /d "_ARM_" /d "ARMV4I" /d "_AFXDLL" /r "E:\work\WLanOnOff\WLanOnOff.rc"" 
Creating temporary file "C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB4.tmp" with contents
[
/nologo /W3 /I "D:\WINCE500\PLATFORM\NERF\COMMON" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=500 /D _WIN32_WCE=500 /D "WCE_PLATFORM_BIP5000R" /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fp"ARMV4IRel/WLanOnOff.pch" /Yu"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"E:\work\WLanOnOff\WLanOnOff.cpp"
"E:\work\WLanOnOff\WLanOnOffDlg.cpp"
]
Creating command line "clarm.exe @C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB4.tmp" 
Creating temporary file "C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB5.tmp" with contents
[
/nologo /W3 /I "D:\WINCE500\PLATFORM\NERF\COMMON" /D "ARM" /D "_ARM_" /D "ARMV4I" /D UNDER_CE=500 /D _WIN32_WCE=500 /D "WCE_PLATFORM_BIP5000R" /D "UNICODE" /D "_UNICODE" /D "NDEBUG" /D "_AFXDLL" /Fp"ARMV4IRel/WLanOnOff.pch" /Yc"stdafx.h" /Fo"ARMV4IRel/" /QRarch4T /QRinterwork-return /O2 /MC /c 
"E:\work\WLanOnOff\StdAfx.cpp"
]
Creating command line "clarm.exe @C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB5.tmp" 
Creating temporary file "C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB6.tmp" with contents
[
/nologo /base:"0x00010000" /stack:0x10000,0x1000 /entry:"wWinMainCRTStartup" /incremental:no /pdb:"ARMV4IRel/WLanOnOff.pdb" /out:"ARMV4IRel/WLanOnOff.exe" /libpath:"D:\WINCE500\PLATFORM\NERF\COMMON" /subsystem:windowsce,5.00 /MACHINE:THUMB 
.\ARMV4IRel\StdAfx.obj
.\ARMV4IRel\WLanOnOff.obj
.\ARMV4IRel\WLanOnOffDlg.obj
.\ARMV4IRel\WLanOnOff.res
]
Creating command line "link.exe @C:\Users\HWANGJ~1\AppData\Local\Temp\RSP6EB6.tmp"
<h3>Output Window</h3>
Compiling resources...
Compiling...
StdAfx.cpp
Compiling...
WLanOnOff.cpp
WLanOnOffDlg.cpp
e:\work\wlanonoff\monahans_clkmgr.h(37) : fatal error C1083: Cannot open include file: 'xllp_clkmgr.h': No such file or directory
Generating Code...
Error executing clarm.exe.



<h3>Results</h3>
WLanOnOff.exe - 1 error(s), 0 warning(s)
</pre>
</body>
</html>
