# Microsoft Developer Studio Project File - Name="InsaneFX" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=InsaneFX - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "InsaneFX.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "InsaneFX.mak" CFG="InsaneFX - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "InsaneFX - Win32 Release" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InsaneFX - Win32 Debug" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "InsaneFX - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386

!ELSEIF  "$(CFG)" == "InsaneFX - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ""
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"../../../bin/win/InsaneFX.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "InsaneFX - Win32 Release"
# Name "InsaneFX - Win32 Debug"
# Begin Group "Ressourcendateien"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Group "InsaneFX"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\insaneFX.cpp
# End Source File
# Begin Source File

SOURCE=..\..\insaneFX.h
# End Source File
# End Group
# Begin Group "RenderDevice"

# PROP Default_Filter "cpp; h"
# Begin Source File

SOURCE=..\..\RenderDevice\OpenGL\fxGL.cpp
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\OpenGL\fxGL.h
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\OpenGL\fxGL_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\OpenGL\fxGL_win.h
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderDevice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderDevice.h
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderDevice_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderWindow.h
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderWindow_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\fxRenderWindow_win.h
# End Source File
# Begin Source File

SOURCE=..\..\RenderDevice\OpenGL\glext.h
# End Source File
# End Group
# Begin Group "Kernel"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\Kernel\fxClass.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxClass.h
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxConsole.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxConsole.h
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxRefClass.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxRefClass.h
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxTimer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxTimer.h
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxTimer_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxVars.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Kernel\fxVars.h
# End Source File
# End Group
# Begin Group "shared"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\Shared\fxConst.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\fxLimits.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\fxList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\fxList.h
# End Source File
# Begin Source File

SOURCE=..\..\Shared\fxParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Shared\fxParser.h
# End Source File
# End Group
# Begin Group "Math"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\Math\fxColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxColor.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxMath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxMath.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxMatrix.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxMatrix.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxPlane.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxPlane.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxPoint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxPoint.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxVector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxVector.h
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxVertex.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Math\fxVertex.h
# End Source File
# End Group
# Begin Group "Material"

# PROP Default_Filter "cpp;h"
# Begin Group "libjpeg"

# PROP Default_Filter "c;h"
# Begin Source File

SOURCE=..\..\Materials\libjpeg\cderror.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\cdjpeg.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jcomapi.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jconfig.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdapimin.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdapistd.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdatadst.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdatasrc.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdcoefct.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdcolor.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdct.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jddctmgr.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdhuff.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdhuff.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdinput.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdmainct.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdmarker.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdmaster.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdmerge.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdphuff.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdpostct.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdsample.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jdtrans.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jerror.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jerror.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jfdctflt.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jfdctfst.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jfdctint.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jidctflt.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jidctfst.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jidctint.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jidctred.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jinclude.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jmemansi.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jmemmgr.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jmemsys.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jmorecfg.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jpegint.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jpeglib.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jquant1.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jquant2.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jutils.c
# End Source File
# Begin Source File

SOURCE=..\..\Materials\libjpeg\jversion.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\Materials\fxLayer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxLayer.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxMaterial.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxMaterial.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxMaterialMng.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxMaterialMng.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxTexture.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxTexture.h
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxTexture_win.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxTextureMng.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Materials\fxTextureMng.h
# End Source File
# End Group
# Begin Group "Camera"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\Camera\fxCamera.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Camera\fxCamera.h
# End Source File
# End Group
# Begin Group "Scene"

# PROP Default_Filter "cpp;h"
# Begin Group "Mesh"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\Scene\fxMeshNode\3D Studio 3DS\3DSimport.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\Scene\fxMeshNode\3D Studio 3DS\3DSimport.h"
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMesh.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMesh.h
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMeshMng.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMeshMng.h
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMeshNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxMeshNode\fxMeshNode.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\Scene\fxScene.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxScene.h
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxSceneNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\Scene\fxSceneNode.h
# End Source File
# End Group
# Begin Group "SceneGraph"

# PROP Default_Filter "cpp;h"
# Begin Source File

SOURCE=..\..\SceneGraph\fxSceneGraph.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SceneGraph\fxSceneGraph.h
# End Source File
# Begin Source File

SOURCE=..\..\SceneGraph\fxSGNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\SceneGraph\fxSGNode.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\linux.txt
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\Programme\vc6\Lib\OPENGL32.LIB
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\Programme\vc6\Lib\GLU32.LIB
# End Source File
# End Target
# End Project
