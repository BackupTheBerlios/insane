# Microsoft Developer Studio Generated NMAKE File, Based on InsaneFX.dsp
!IF "$(CFG)" == ""
CFG=InsaneFX - Win32 Debug
!MESSAGE Keine Konfiguration angegeben. InsaneFX - Win32 Debug wird als Standard verwendet.
!ENDIF 

!IF "$(CFG)" != "InsaneFX - Win32 Release" && "$(CFG)" != "InsaneFX - Win32 Debug"
!MESSAGE UngÅltige Konfiguration "$(CFG)" angegeben.
!MESSAGE Sie kînnen beim AusfÅhren von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "InsaneFX.mak" CFG="InsaneFX - Win32 Debug"
!MESSAGE 
!MESSAGE FÅr die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "InsaneFX - Win32 Release" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE "InsaneFX - Win32 Debug" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR Eine ungÅltige Konfiguration wurde angegeben.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "InsaneFX - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\InsaneFX.dll"


CLEAN :
	-@erase "$(INTDIR)\3DSimport.obj"
	-@erase "$(INTDIR)\fxCamera.obj"
	-@erase "$(INTDIR)\fxClass.obj"
	-@erase "$(INTDIR)\fxColor.obj"
	-@erase "$(INTDIR)\fxConsole.obj"
	-@erase "$(INTDIR)\fxGL.obj"
	-@erase "$(INTDIR)\fxGL_win.obj"
	-@erase "$(INTDIR)\fxLayer.obj"
	-@erase "$(INTDIR)\fxList.obj"
	-@erase "$(INTDIR)\fxMaterial.obj"
	-@erase "$(INTDIR)\fxMaterialMng.obj"
	-@erase "$(INTDIR)\fxMath.obj"
	-@erase "$(INTDIR)\fxMatrix.obj"
	-@erase "$(INTDIR)\fxMesh.obj"
	-@erase "$(INTDIR)\fxMeshMng.obj"
	-@erase "$(INTDIR)\fxMeshNode.obj"
	-@erase "$(INTDIR)\fxParser.obj"
	-@erase "$(INTDIR)\fxPlane.obj"
	-@erase "$(INTDIR)\fxPoint.obj"
	-@erase "$(INTDIR)\fxRefClass.obj"
	-@erase "$(INTDIR)\fxRenderDevice_win.obj"
	-@erase "$(INTDIR)\fxRenderWindow_win.obj"
	-@erase "$(INTDIR)\fxScene.obj"
	-@erase "$(INTDIR)\fxSceneGraph.obj"
	-@erase "$(INTDIR)\fxSceneNode.obj"
	-@erase "$(INTDIR)\fxSGNode.obj"
	-@erase "$(INTDIR)\fxTexture.obj"
	-@erase "$(INTDIR)\fxTexture_win.obj"
	-@erase "$(INTDIR)\fxTextureMng.obj"
	-@erase "$(INTDIR)\fxTimer.obj"
	-@erase "$(INTDIR)\fxTimer_win.obj"
	-@erase "$(INTDIR)\fxVars.obj"
	-@erase "$(INTDIR)\fxVector.obj"
	-@erase "$(INTDIR)\fxVertex.obj"
	-@erase "$(INTDIR)\insaneFX.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jdapimin.obj"
	-@erase "$(INTDIR)\jdapistd.obj"
	-@erase "$(INTDIR)\jdatadst.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdinput.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdphuff.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jdtrans.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctflt.obj"
	-@erase "$(INTDIR)\jfdctfst.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctfst.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jidctred.obj"
	-@erase "$(INTDIR)\jmemansi.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\InsaneFX.dll"
	-@erase "$(OUTDIR)\InsaneFX.exp"
	-@erase "$(OUTDIR)\InsaneFX.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /Fp"$(INTDIR)\InsaneFX.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InsaneFX.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\InsaneFX.pdb" /machine:I386 /out:"$(OUTDIR)\InsaneFX.dll" /implib:"$(OUTDIR)\InsaneFX.lib" 
LINK32_OBJS= \
	"$(INTDIR)\insaneFX.obj" \
	"$(INTDIR)\fxGL.obj" \
	"$(INTDIR)\fxClass.obj" \
	"$(INTDIR)\fxConsole.obj" \
	"$(INTDIR)\fxRefClass.obj" \
	"$(INTDIR)\fxVars.obj" \
	"$(INTDIR)\fxList.obj" \
	"$(INTDIR)\fxParser.obj" \
	"$(INTDIR)\fxColor.obj" \
	"$(INTDIR)\fxMath.obj" \
	"$(INTDIR)\fxMatrix.obj" \
	"$(INTDIR)\fxPlane.obj" \
	"$(INTDIR)\fxPoint.obj" \
	"$(INTDIR)\fxVector.obj" \
	"$(INTDIR)\fxVertex.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jdapimin.obj" \
	"$(INTDIR)\jdapistd.obj" \
	"$(INTDIR)\jdatadst.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdinput.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdphuff.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jdtrans.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctflt.obj" \
	"$(INTDIR)\jfdctfst.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctfst.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jidctred.obj" \
	"$(INTDIR)\jmemansi.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\fxLayer.obj" \
	"$(INTDIR)\fxMaterial.obj" \
	"$(INTDIR)\fxMaterialMng.obj" \
	"$(INTDIR)\fxTexture.obj" \
	"$(INTDIR)\fxTextureMng.obj" \
	"$(INTDIR)\fxCamera.obj" \
	"$(INTDIR)\3DSimport.obj" \
	"$(INTDIR)\fxMesh.obj" \
	"$(INTDIR)\fxMeshMng.obj" \
	"$(INTDIR)\fxMeshNode.obj" \
	"$(INTDIR)\fxScene.obj" \
	"$(INTDIR)\fxSceneNode.obj" \
	"$(INTDIR)\fxSceneGraph.obj" \
	"$(INTDIR)\fxSGNode.obj" \
	"..\..\..\..\..\Programme\vc60\Lib\OPENGL32.LIB" \
	"..\..\..\..\..\Programme\vc60\Lib\GLU32.LIB" \
	"$(INTDIR)\fxRenderWindow_win.obj" \
	"$(INTDIR)\fxRenderDevice_win.obj" \
	"$(INTDIR)\fxGL_win.obj" \
	"$(INTDIR)\fxTimer_win.obj" \
	"$(INTDIR)\fxTimer.obj" \
	"$(INTDIR)\fxTexture_win.obj"

"$(OUTDIR)\InsaneFX.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "InsaneFX - Win32 Debug"

OUTDIR=.
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.
# End Custom Macros

ALL : "$(OUTDIR)\InsaneFX.dll"


CLEAN :
	-@erase "$(INTDIR)\3DSimport.obj"
	-@erase "$(INTDIR)\fxCamera.obj"
	-@erase "$(INTDIR)\fxClass.obj"
	-@erase "$(INTDIR)\fxColor.obj"
	-@erase "$(INTDIR)\fxConsole.obj"
	-@erase "$(INTDIR)\fxGL.obj"
	-@erase "$(INTDIR)\fxGL_win.obj"
	-@erase "$(INTDIR)\fxLayer.obj"
	-@erase "$(INTDIR)\fxList.obj"
	-@erase "$(INTDIR)\fxMaterial.obj"
	-@erase "$(INTDIR)\fxMaterialMng.obj"
	-@erase "$(INTDIR)\fxMath.obj"
	-@erase "$(INTDIR)\fxMatrix.obj"
	-@erase "$(INTDIR)\fxMesh.obj"
	-@erase "$(INTDIR)\fxMeshMng.obj"
	-@erase "$(INTDIR)\fxMeshNode.obj"
	-@erase "$(INTDIR)\fxParser.obj"
	-@erase "$(INTDIR)\fxPlane.obj"
	-@erase "$(INTDIR)\fxPoint.obj"
	-@erase "$(INTDIR)\fxRefClass.obj"
	-@erase "$(INTDIR)\fxRenderDevice_win.obj"
	-@erase "$(INTDIR)\fxRenderWindow_win.obj"
	-@erase "$(INTDIR)\fxScene.obj"
	-@erase "$(INTDIR)\fxSceneGraph.obj"
	-@erase "$(INTDIR)\fxSceneNode.obj"
	-@erase "$(INTDIR)\fxSGNode.obj"
	-@erase "$(INTDIR)\fxTexture.obj"
	-@erase "$(INTDIR)\fxTexture_win.obj"
	-@erase "$(INTDIR)\fxTextureMng.obj"
	-@erase "$(INTDIR)\fxTimer.obj"
	-@erase "$(INTDIR)\fxTimer_win.obj"
	-@erase "$(INTDIR)\fxVars.obj"
	-@erase "$(INTDIR)\fxVector.obj"
	-@erase "$(INTDIR)\fxVertex.obj"
	-@erase "$(INTDIR)\insaneFX.obj"
	-@erase "$(INTDIR)\jcomapi.obj"
	-@erase "$(INTDIR)\jdapimin.obj"
	-@erase "$(INTDIR)\jdapistd.obj"
	-@erase "$(INTDIR)\jdatadst.obj"
	-@erase "$(INTDIR)\jdatasrc.obj"
	-@erase "$(INTDIR)\jdcoefct.obj"
	-@erase "$(INTDIR)\jdcolor.obj"
	-@erase "$(INTDIR)\jddctmgr.obj"
	-@erase "$(INTDIR)\jdhuff.obj"
	-@erase "$(INTDIR)\jdinput.obj"
	-@erase "$(INTDIR)\jdmainct.obj"
	-@erase "$(INTDIR)\jdmarker.obj"
	-@erase "$(INTDIR)\jdmaster.obj"
	-@erase "$(INTDIR)\jdmerge.obj"
	-@erase "$(INTDIR)\jdphuff.obj"
	-@erase "$(INTDIR)\jdpostct.obj"
	-@erase "$(INTDIR)\jdsample.obj"
	-@erase "$(INTDIR)\jdtrans.obj"
	-@erase "$(INTDIR)\jerror.obj"
	-@erase "$(INTDIR)\jfdctflt.obj"
	-@erase "$(INTDIR)\jfdctfst.obj"
	-@erase "$(INTDIR)\jfdctint.obj"
	-@erase "$(INTDIR)\jidctflt.obj"
	-@erase "$(INTDIR)\jidctfst.obj"
	-@erase "$(INTDIR)\jidctint.obj"
	-@erase "$(INTDIR)\jidctred.obj"
	-@erase "$(INTDIR)\jmemansi.obj"
	-@erase "$(INTDIR)\jmemmgr.obj"
	-@erase "$(INTDIR)\jquant1.obj"
	-@erase "$(INTDIR)\jquant2.obj"
	-@erase "$(INTDIR)\jutils.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\InsaneFX.dll"
	-@erase "$(OUTDIR)\InsaneFX.exp"
	-@erase "$(OUTDIR)\InsaneFX.ilk"
	-@erase "$(OUTDIR)\InsaneFX.lib"
	-@erase "$(OUTDIR)\InsaneFX.pdb"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "INSANEFX_EXPORTS" /Fp"$(INTDIR)\InsaneFX.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\InsaneFX.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\InsaneFX.pdb" /debug /machine:I386 /out:"$(OUTDIR)\InsaneFX.dll" /implib:"$(OUTDIR)\InsaneFX.lib" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\insaneFX.obj" \
	"$(INTDIR)\fxGL.obj" \
	"$(INTDIR)\fxClass.obj" \
	"$(INTDIR)\fxConsole.obj" \
	"$(INTDIR)\fxRefClass.obj" \
	"$(INTDIR)\fxVars.obj" \
	"$(INTDIR)\fxList.obj" \
	"$(INTDIR)\fxParser.obj" \
	"$(INTDIR)\fxColor.obj" \
	"$(INTDIR)\fxMath.obj" \
	"$(INTDIR)\fxMatrix.obj" \
	"$(INTDIR)\fxPlane.obj" \
	"$(INTDIR)\fxPoint.obj" \
	"$(INTDIR)\fxVector.obj" \
	"$(INTDIR)\fxVertex.obj" \
	"$(INTDIR)\jcomapi.obj" \
	"$(INTDIR)\jdapimin.obj" \
	"$(INTDIR)\jdapistd.obj" \
	"$(INTDIR)\jdatadst.obj" \
	"$(INTDIR)\jdatasrc.obj" \
	"$(INTDIR)\jdcoefct.obj" \
	"$(INTDIR)\jdcolor.obj" \
	"$(INTDIR)\jddctmgr.obj" \
	"$(INTDIR)\jdhuff.obj" \
	"$(INTDIR)\jdinput.obj" \
	"$(INTDIR)\jdmainct.obj" \
	"$(INTDIR)\jdmarker.obj" \
	"$(INTDIR)\jdmaster.obj" \
	"$(INTDIR)\jdmerge.obj" \
	"$(INTDIR)\jdphuff.obj" \
	"$(INTDIR)\jdpostct.obj" \
	"$(INTDIR)\jdsample.obj" \
	"$(INTDIR)\jdtrans.obj" \
	"$(INTDIR)\jerror.obj" \
	"$(INTDIR)\jfdctflt.obj" \
	"$(INTDIR)\jfdctfst.obj" \
	"$(INTDIR)\jfdctint.obj" \
	"$(INTDIR)\jidctflt.obj" \
	"$(INTDIR)\jidctfst.obj" \
	"$(INTDIR)\jidctint.obj" \
	"$(INTDIR)\jidctred.obj" \
	"$(INTDIR)\jmemansi.obj" \
	"$(INTDIR)\jmemmgr.obj" \
	"$(INTDIR)\jquant1.obj" \
	"$(INTDIR)\jquant2.obj" \
	"$(INTDIR)\jutils.obj" \
	"$(INTDIR)\fxLayer.obj" \
	"$(INTDIR)\fxMaterial.obj" \
	"$(INTDIR)\fxMaterialMng.obj" \
	"$(INTDIR)\fxTexture.obj" \
	"$(INTDIR)\fxTextureMng.obj" \
	"$(INTDIR)\fxCamera.obj" \
	"$(INTDIR)\3DSimport.obj" \
	"$(INTDIR)\fxMesh.obj" \
	"$(INTDIR)\fxMeshMng.obj" \
	"$(INTDIR)\fxMeshNode.obj" \
	"$(INTDIR)\fxScene.obj" \
	"$(INTDIR)\fxSceneNode.obj" \
	"$(INTDIR)\fxSceneGraph.obj" \
	"$(INTDIR)\fxSGNode.obj" \
	"..\..\..\..\..\Programme\vc60\Lib\OPENGL32.LIB" \
	"..\..\..\..\..\Programme\vc60\Lib\GLU32.LIB" \
	"$(INTDIR)\fxRenderWindow_win.obj" \
	"$(INTDIR)\fxRenderDevice_win.obj" \
	"$(INTDIR)\fxGL_win.obj" \
	"$(INTDIR)\fxTimer_win.obj" \
	"$(INTDIR)\fxTimer.obj" \
	"$(INTDIR)\fxTexture_win.obj"

"$(OUTDIR)\InsaneFX.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("InsaneFX.dep")
!INCLUDE "InsaneFX.dep"
!ELSE 
!MESSAGE Warning: cannot find "InsaneFX.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "InsaneFX - Win32 Release" || "$(CFG)" == "InsaneFX - Win32 Debug"
SOURCE=..\..\insaneFX.cpp

"$(INTDIR)\insaneFX.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\RenderDevice\OpenGL\fxGL.cpp

"$(INTDIR)\fxGL.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\RenderDevice\OpenGL\fxGL_win.cpp

"$(INTDIR)\fxGL_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\RenderDevice\fxRenderDevice_win.cpp

"$(INTDIR)\fxRenderDevice_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\RenderDevice\fxRenderWindow_win.cpp

"$(INTDIR)\fxRenderWindow_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxClass.cpp

"$(INTDIR)\fxClass.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxConsole.cpp

"$(INTDIR)\fxConsole.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxRefClass.cpp

"$(INTDIR)\fxRefClass.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxTimer.cpp

"$(INTDIR)\fxTimer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxTimer_win.cpp

"$(INTDIR)\fxTimer_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Kernel\fxVars.cpp

"$(INTDIR)\fxVars.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Shared\fxList.cpp

"$(INTDIR)\fxList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Shared\fxParser.cpp

"$(INTDIR)\fxParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxColor.cpp

"$(INTDIR)\fxColor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxMath.cpp

"$(INTDIR)\fxMath.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxMatrix.cpp

"$(INTDIR)\fxMatrix.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxPlane.cpp

"$(INTDIR)\fxPlane.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxPoint.cpp

"$(INTDIR)\fxPoint.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxVector.cpp

"$(INTDIR)\fxVector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Math\fxVertex.cpp

"$(INTDIR)\fxVertex.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jcomapi.c

"$(INTDIR)\jcomapi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdapimin.c

"$(INTDIR)\jdapimin.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdapistd.c

"$(INTDIR)\jdapistd.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdatadst.c

"$(INTDIR)\jdatadst.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdatasrc.c

"$(INTDIR)\jdatasrc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdcoefct.c

"$(INTDIR)\jdcoefct.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdcolor.c

"$(INTDIR)\jdcolor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jddctmgr.c

"$(INTDIR)\jddctmgr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdhuff.c

"$(INTDIR)\jdhuff.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdinput.c

"$(INTDIR)\jdinput.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdmainct.c

"$(INTDIR)\jdmainct.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdmarker.c

"$(INTDIR)\jdmarker.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdmaster.c

"$(INTDIR)\jdmaster.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdmerge.c

"$(INTDIR)\jdmerge.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdphuff.c

"$(INTDIR)\jdphuff.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdpostct.c

"$(INTDIR)\jdpostct.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdsample.c

"$(INTDIR)\jdsample.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jdtrans.c

"$(INTDIR)\jdtrans.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jerror.c

"$(INTDIR)\jerror.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jfdctflt.c

"$(INTDIR)\jfdctflt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jfdctfst.c

"$(INTDIR)\jfdctfst.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jfdctint.c

"$(INTDIR)\jfdctint.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jidctflt.c

"$(INTDIR)\jidctflt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jidctfst.c

"$(INTDIR)\jidctfst.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jidctint.c

"$(INTDIR)\jidctint.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jidctred.c

"$(INTDIR)\jidctred.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jmemansi.c

"$(INTDIR)\jmemansi.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jmemmgr.c

"$(INTDIR)\jmemmgr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jquant1.c

"$(INTDIR)\jquant1.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jquant2.c

"$(INTDIR)\jquant2.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\libjpeg\jutils.c

"$(INTDIR)\jutils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxLayer.cpp

"$(INTDIR)\fxLayer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxMaterial.cpp

"$(INTDIR)\fxMaterial.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxMaterialMng.cpp

"$(INTDIR)\fxMaterialMng.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxTexture.cpp

"$(INTDIR)\fxTexture.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxTexture_win.cpp

"$(INTDIR)\fxTexture_win.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Materials\fxTextureMng.cpp

"$(INTDIR)\fxTextureMng.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Camera\fxCamera.cpp

"$(INTDIR)\fxCamera.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\Scene\fxMeshNode\3D Studio 3DS\3DSimport.cpp"

"$(INTDIR)\3DSimport.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Scene\fxMeshNode\fxMesh.cpp

"$(INTDIR)\fxMesh.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Scene\fxMeshNode\fxMeshMng.cpp

"$(INTDIR)\fxMeshMng.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Scene\fxMeshNode\fxMeshNode.cpp

"$(INTDIR)\fxMeshNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Scene\fxScene.cpp

"$(INTDIR)\fxScene.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\Scene\fxSceneNode.cpp

"$(INTDIR)\fxSceneNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\SceneGraph\fxSceneGraph.cpp

"$(INTDIR)\fxSceneGraph.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\SceneGraph\fxSGNode.cpp

"$(INTDIR)\fxSGNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

