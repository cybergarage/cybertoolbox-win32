# Microsoft Developer Studio Generated NMAKE File, Format Version 4.20
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=CyberToolBox - Win32 Debug
!MESSAGE 構成が指定されていません。ﾃﾞﾌｫﾙﾄの CyberToolBox - Win32 Debug を設定します。
!ENDIF 

!IF "$(CFG)" != "CyberToolBox - Win32 Release" && "$(CFG)" !=\
 "CyberToolBox - Win32 Debug"
!MESSAGE 指定された ﾋﾞﾙﾄﾞ ﾓｰﾄﾞ "$(CFG)" は正しくありません。
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛ 'CFG' を定義することによって
!MESSAGE NMAKE 実行時にﾋﾞﾙﾄﾞ ﾓｰﾄﾞを指定できます。例えば:
!MESSAGE 
!MESSAGE NMAKE /f "CyberToolBox.mak" CFG="CyberToolBox - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "CyberToolBox - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "CyberToolBox - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 
!ERROR 無効な構成が指定されています。
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "CyberToolBox - Win32 Debug"
CPP=cl.exe
MTL=mktyplib.exe
RSC=rc.exe

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\CyberToolBox.exe" "$(OUTDIR)\CyberToolBox.pch"

CLEAN : 
	-@erase "$(INTDIR)\CDiagram.obj"
	-@erase "$(INTDIR)\CDiagramWindow.obj"
	-@erase "$(INTDIR)\CEvent.obj"
	-@erase "$(INTDIR)\CFontInfo.obj"
	-@erase "$(INTDIR)\CModule.obj"
	-@erase "$(INTDIR)\CModuleType.obj"
	-@erase "$(INTDIR)\CUndoAction.obj"
	-@erase "$(INTDIR)\CUndoActionFn.obj"
	-@erase "$(INTDIR)\CyberToolBox.obj"
	-@erase "$(INTDIR)\CyberToolBox.pch"
	-@erase "$(INTDIR)\CyberToolBox.res"
	-@erase "$(INTDIR)\CyberToolBoxDoc.obj"
	-@erase "$(INTDIR)\CyberToolBoxView.obj"
	-@erase "$(INTDIR)\DiagramDoc.obj"
	-@erase "$(INTDIR)\DiagramFrame.obj"
	-@erase "$(INTDIR)\DiagramNew.obj"
	-@erase "$(INTDIR)\DiagramView.obj"
	-@erase "$(INTDIR)\DialogNewUserEvent.obj"
	-@erase "$(INTDIR)\DialogNodeConfig.obj"
	-@erase "$(INTDIR)\DialogObjectName.obj"
	-@erase "$(INTDIR)\DialogWorldConstant.obj"
	-@erase "$(INTDIR)\FileIO.obj"
	-@erase "$(INTDIR)\icon.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\moduleconfig.obj"
	-@erase "$(INTDIR)\ModuleFloating.obj"
	-@erase "$(INTDIR)\ModuleMathPage.obj"
	-@erase "$(INTDIR)\ModuleNumericPage.obj"
	-@erase "$(INTDIR)\ModuleObjectPage.obj"
	-@erase "$(INTDIR)\ModulePage.obj"
	-@erase "$(INTDIR)\ModuleWorldPage.obj"
	-@erase "$(INTDIR)\OpenGLFn.obj"
	-@erase "$(INTDIR)\PerspectiveDoc.obj"
	-@erase "$(INTDIR)\PerspectiveFrame.obj"
	-@erase "$(INTDIR)\PerspectiveView.obj"
	-@erase "$(INTDIR)\RegKey.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StringFn.obj"
	-@erase "$(INTDIR)\UserEventPickupPage.obj"
	-@erase "$(INTDIR)\World.obj"
	-@erase "$(OUTDIR)\CyberToolBox.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /WX /GX /O2 /I "./Common" /I "./Dialog" /I "../VRMLBrowser" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
CPP_PROJ=/nologo /MD /W3 /WX /GX /O2 /I "./Common" /I "./Dialog" /I\
 "../VRMLBrowser" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS"\
 /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x411 /fo"$(INTDIR)/CyberToolBox.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CyberToolBox.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 SceneGraph.lib javai.lib opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"LIBCD.LIB"
LINK32_FLAGS=SceneGraph.lib javai.lib opengl32.lib glu32.lib glaux.lib /nologo\
 /subsystem:windows /incremental:no /pdb:"$(OUTDIR)/CyberToolBox.pdb"\
 /machine:I386 /nodefaultlib:"LIBCD.LIB" /out:"$(OUTDIR)/CyberToolBox.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CDiagram.obj" \
	"$(INTDIR)\CDiagramWindow.obj" \
	"$(INTDIR)\CEvent.obj" \
	"$(INTDIR)\CFontInfo.obj" \
	"$(INTDIR)\CModule.obj" \
	"$(INTDIR)\CModuleType.obj" \
	"$(INTDIR)\CUndoAction.obj" \
	"$(INTDIR)\CUndoActionFn.obj" \
	"$(INTDIR)\CyberToolBox.obj" \
	"$(INTDIR)\CyberToolBox.res" \
	"$(INTDIR)\CyberToolBoxDoc.obj" \
	"$(INTDIR)\CyberToolBoxView.obj" \
	"$(INTDIR)\DiagramDoc.obj" \
	"$(INTDIR)\DiagramFrame.obj" \
	"$(INTDIR)\DiagramNew.obj" \
	"$(INTDIR)\DiagramView.obj" \
	"$(INTDIR)\DialogNewUserEvent.obj" \
	"$(INTDIR)\DialogNodeConfig.obj" \
	"$(INTDIR)\DialogObjectName.obj" \
	"$(INTDIR)\DialogWorldConstant.obj" \
	"$(INTDIR)\FileIO.obj" \
	"$(INTDIR)\icon.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\moduleconfig.obj" \
	"$(INTDIR)\ModuleFloating.obj" \
	"$(INTDIR)\ModuleMathPage.obj" \
	"$(INTDIR)\ModuleNumericPage.obj" \
	"$(INTDIR)\ModuleObjectPage.obj" \
	"$(INTDIR)\ModulePage.obj" \
	"$(INTDIR)\ModuleWorldPage.obj" \
	"$(INTDIR)\OpenGLFn.obj" \
	"$(INTDIR)\PerspectiveDoc.obj" \
	"$(INTDIR)\PerspectiveFrame.obj" \
	"$(INTDIR)\PerspectiveView.obj" \
	"$(INTDIR)\RegKey.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StringFn.obj" \
	"$(INTDIR)\UserEventPickupPage.obj" \
	"$(INTDIR)\World.obj"

"$(OUTDIR)\CyberToolBox.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\CyberToolBox.exe" "$(OUTDIR)\CyberToolBox.pch"

CLEAN : 
	-@erase "$(INTDIR)\CDiagram.obj"
	-@erase "$(INTDIR)\CDiagramWindow.obj"
	-@erase "$(INTDIR)\CEvent.obj"
	-@erase "$(INTDIR)\CFontInfo.obj"
	-@erase "$(INTDIR)\CModule.obj"
	-@erase "$(INTDIR)\CModuleType.obj"
	-@erase "$(INTDIR)\CUndoAction.obj"
	-@erase "$(INTDIR)\CUndoActionFn.obj"
	-@erase "$(INTDIR)\CyberToolBox.obj"
	-@erase "$(INTDIR)\CyberToolBox.pch"
	-@erase "$(INTDIR)\CyberToolBox.res"
	-@erase "$(INTDIR)\CyberToolBoxDoc.obj"
	-@erase "$(INTDIR)\CyberToolBoxView.obj"
	-@erase "$(INTDIR)\DiagramDoc.obj"
	-@erase "$(INTDIR)\DiagramFrame.obj"
	-@erase "$(INTDIR)\DiagramNew.obj"
	-@erase "$(INTDIR)\DiagramView.obj"
	-@erase "$(INTDIR)\DialogNewUserEvent.obj"
	-@erase "$(INTDIR)\DialogNodeConfig.obj"
	-@erase "$(INTDIR)\DialogObjectName.obj"
	-@erase "$(INTDIR)\DialogWorldConstant.obj"
	-@erase "$(INTDIR)\FileIO.obj"
	-@erase "$(INTDIR)\icon.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\moduleconfig.obj"
	-@erase "$(INTDIR)\ModuleFloating.obj"
	-@erase "$(INTDIR)\ModuleMathPage.obj"
	-@erase "$(INTDIR)\ModuleNumericPage.obj"
	-@erase "$(INTDIR)\ModuleObjectPage.obj"
	-@erase "$(INTDIR)\ModulePage.obj"
	-@erase "$(INTDIR)\ModuleWorldPage.obj"
	-@erase "$(INTDIR)\OpenGLFn.obj"
	-@erase "$(INTDIR)\PerspectiveDoc.obj"
	-@erase "$(INTDIR)\PerspectiveFrame.obj"
	-@erase "$(INTDIR)\PerspectiveView.obj"
	-@erase "$(INTDIR)\RegKey.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StringFn.obj"
	-@erase "$(INTDIR)\UserEventPickupPage.obj"
	-@erase "$(INTDIR)\vc40.idb"
	-@erase "$(INTDIR)\vc40.pdb"
	-@erase "$(INTDIR)\World.obj"
	-@erase "$(OUTDIR)\CyberToolBox.exe"
	-@erase "$(OUTDIR)\CyberToolBox.ilk"
	-@erase "$(OUTDIR)\CyberToolBox.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /WX /Gm /GX /Zi /Od /I "./Common" /I "./Dialog" /I "../VRMLBrowser" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /c
# SUBTRACT CPP /YX /Yc /Yu
CPP_PROJ=/nologo /MDd /W3 /WX /Gm /GX /Zi /Od /I "./Common" /I "./Dialog" /I\
 "../VRMLBrowser" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x411 /fo"$(INTDIR)/CyberToolBox.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/CyberToolBox.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 SceneGraph.lib javai.lib opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib:"LIBCD.LIB"
LINK32_FLAGS=SceneGraph.lib javai.lib opengl32.lib glu32.lib glaux.lib /nologo\
 /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)/CyberToolBox.pdb" /debug\
 /machine:I386 /nodefaultlib:"LIBCD.LIB" /out:"$(OUTDIR)/CyberToolBox.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CDiagram.obj" \
	"$(INTDIR)\CDiagramWindow.obj" \
	"$(INTDIR)\CEvent.obj" \
	"$(INTDIR)\CFontInfo.obj" \
	"$(INTDIR)\CModule.obj" \
	"$(INTDIR)\CModuleType.obj" \
	"$(INTDIR)\CUndoAction.obj" \
	"$(INTDIR)\CUndoActionFn.obj" \
	"$(INTDIR)\CyberToolBox.obj" \
	"$(INTDIR)\CyberToolBox.res" \
	"$(INTDIR)\CyberToolBoxDoc.obj" \
	"$(INTDIR)\CyberToolBoxView.obj" \
	"$(INTDIR)\DiagramDoc.obj" \
	"$(INTDIR)\DiagramFrame.obj" \
	"$(INTDIR)\DiagramNew.obj" \
	"$(INTDIR)\DiagramView.obj" \
	"$(INTDIR)\DialogNewUserEvent.obj" \
	"$(INTDIR)\DialogNodeConfig.obj" \
	"$(INTDIR)\DialogObjectName.obj" \
	"$(INTDIR)\DialogWorldConstant.obj" \
	"$(INTDIR)\FileIO.obj" \
	"$(INTDIR)\icon.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\moduleconfig.obj" \
	"$(INTDIR)\ModuleFloating.obj" \
	"$(INTDIR)\ModuleMathPage.obj" \
	"$(INTDIR)\ModuleNumericPage.obj" \
	"$(INTDIR)\ModuleObjectPage.obj" \
	"$(INTDIR)\ModulePage.obj" \
	"$(INTDIR)\ModuleWorldPage.obj" \
	"$(INTDIR)\OpenGLFn.obj" \
	"$(INTDIR)\PerspectiveDoc.obj" \
	"$(INTDIR)\PerspectiveFrame.obj" \
	"$(INTDIR)\PerspectiveView.obj" \
	"$(INTDIR)\RegKey.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\StringFn.obj" \
	"$(INTDIR)\UserEventPickupPage.obj" \
	"$(INTDIR)\World.obj"

"$(OUTDIR)\CyberToolBox.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "CyberToolBox - Win32 Release"
# Name "CyberToolBox - Win32 Debug"

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CyberToolBox.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CYBER=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Dialog\ModuleMathPage.h"\
	".\./Dialog\ModuleNumericPage.h"\
	".\./Dialog\ModuleObjectPage.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\Common\Common.h"\
	".\CyberToolBoxDoc.h"\
	".\CyberToolBoxView.h"\
	".\DiagramDoc.h"\
	".\DiagramFrame.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	".\MainFrm.h"\
	".\ModuleFloating.h"\
	".\PerspectiveDoc.h"\
	".\PerspectiveFrame.h"\
	".\PerspectiveView.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CyberToolBox.obj" : $(SOURCE) $(DEP_CPP_CYBER) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CYBER=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\ModuleMathPage.h"\
	".\./Dialog\ModuleNumericPage.h"\
	".\./Dialog\ModuleObjectPage.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\CFontInfo.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\CyberToolBoxDoc.h"\
	".\CyberToolBoxView.h"\
	".\DiagramDoc.h"\
	".\DiagramFrame.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	".\MainFrm.h"\
	".\ModuleFloating.h"\
	".\PerspectiveDoc.h"\
	".\PerspectiveFrame.h"\
	".\PerspectiveView.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CyberToolBox.obj" : $(SOURCE) $(DEP_CPP_CYBER) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\Dialog\..\stdafx.h"\
	

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /WX /GX /O2 /I "./Common" /I "./Dialog" /I\
 "../VRMLBrowser" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/CyberToolBox.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CyberToolBox.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /WX /Gm /GX /Zi /Od /I "./Common" /I "./Dialog" /I\
 "../VRMLBrowser" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS"\
 /Fp"$(INTDIR)/CyberToolBox.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /Fd"$(INTDIR)/"\
 /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\CyberToolBox.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\./Common\RegKey.h"\
	".\./Dialog\DiagramNew.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\MainFrm.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CyberToolBoxDoc.cpp
DEP_CPP_CYBERT=\
	".\CyberToolBoxDoc.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	

"$(INTDIR)\CyberToolBoxDoc.obj" : $(SOURCE) $(DEP_CPP_CYBERT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CyberToolBoxView.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CYBERTO=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DiagramNew.h"\
	".\./Dialog\DialogNodeConfig.h"\
	".\./Dialog\UserEventPickupPage.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\CyberToolBoxDoc.h"\
	".\CyberToolBoxView.h"\
	".\DiagramDoc.h"\
	".\DiagramFrame.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\DialogNewUserEvent.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CyberToolBoxView.obj" : $(SOURCE) $(DEP_CPP_CYBERTO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CYBERTO=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DiagramNew.h"\
	".\./Dialog\DialogNodeConfig.h"\
	".\./Dialog\ModuleMathPage.h"\
	".\./Dialog\ModuleNumericPage.h"\
	".\./Dialog\ModuleObjectPage.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\./Dialog\UserEventPickupPage.h"\
	".\CFontInfo.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\CyberToolBoxDoc.h"\
	".\CyberToolBoxView.h"\
	".\DiagramDoc.h"\
	".\DiagramFrame.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	".\DialogNewUserEvent.h"\
	".\ModuleFloating.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CyberToolBoxView.obj" : $(SOURCE) $(DEP_CPP_CYBERTO) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CyberToolBox.rc
DEP_RSC_CYBERTOO=\
	".\res\cursor1.cur"\
	".\res\CyberToolBox.ico"\
	".\res\CyberToolBox.rc2"\
	".\res\CyberToolBoxDoc.ico"\
	".\res\ico00001.ico"\
	".\res\icon1.ico"\
	".\res\Toolbar.bmp"\
	".\res\toolbar1.bmp"\
	

"$(INTDIR)\CyberToolBox.res" : $(SOURCE) $(DEP_RSC_CYBERTOO) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\World.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_WORLD=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Common\FileIO.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\World.obj" : $(SOURCE) $(DEP_CPP_WORLD) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_WORLD=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Common\FileIO.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\World.obj" : $(SOURCE) $(DEP_CPP_WORLD) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PerspectiveView.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_PERSP=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\../VRMLBrowser\OpenGLFn.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\PerspectiveView.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\gl\GLAUX.H"\
	{$(INCLUDE)}"\gl\GLU.H"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\PerspectiveView.obj" : $(SOURCE) $(DEP_CPP_PERSP) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_PERSP=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\../VRMLBrowser\OpenGLFn.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\PerspectiveView.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\gl\GLAUX.H"\
	{$(INCLUDE)}"\gl\GLU.H"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\PerspectiveView.obj" : $(SOURCE) $(DEP_CPP_PERSP) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\PerspectiveFrame.cpp
DEP_CPP_PERSPE=\
	".\./Common\RegKey.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\PerspectiveFrame.h"\
	

"$(INTDIR)\PerspectiveFrame.obj" : $(SOURCE) $(DEP_CPP_PERSPE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\PerspectiveDoc.cpp
DEP_CPP_PERSPEC=\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\PerspectiveDoc.h"\
	

"$(INTDIR)\PerspectiveDoc.obj" : $(SOURCE) $(DEP_CPP_PERSPEC) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\moduleconfig.cpp
DEP_CPP_MODUL=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModuleConfig.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\moduleconfig.obj" : $(SOURCE) $(DEP_CPP_MODUL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\ModuleWorldPage.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_MODULE=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModuleConfig.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\ModuleWorldPage.obj" : $(SOURCE) $(DEP_CPP_MODULE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_MODULE=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\CFontInfo.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModuleConfig.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\ModuleWorldPage.obj" : $(SOURCE) $(DEP_CPP_MODULE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ModuleFloating.cpp
DEP_CPP_MODULEF=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Dialog\ModuleMathPage.h"\
	".\./Dialog\ModuleNumericPage.h"\
	".\./Dialog\ModuleObjectPage.h"\
	".\./Dialog\ModuleWorldPage.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	".\ModuleFloating.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\ModuleFloating.obj" : $(SOURCE) $(DEP_CPP_MODULEF) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\ModuleMathPage.cpp
DEP_CPP_MODULEM=\
	".\./Dialog\ModuleMathPage.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	

"$(INTDIR)\ModuleMathPage.obj" : $(SOURCE) $(DEP_CPP_MODULEM) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CModuleType.cpp
DEP_CPP_CMODU=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Common\RegKey.h"\
	".\./Common\StringFn.h"\
	".\Common\Common.h"\
	".\Common\FileIO.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\CModuleType.obj" : $(SOURCE) $(DEP_CPP_CMODU) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\StringFn.cpp

"$(INTDIR)\StringFn.obj" : $(SOURCE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\icon.cpp
DEP_CPP_ICON_=\
	".\./Common\Icon.h"\
	

"$(INTDIR)\icon.obj" : $(SOURCE) $(DEP_CPP_ICON_) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\RegKey.cpp
DEP_CPP_REGKE=\
	".\./Common\RegKey.h"\
	".\Common\Common.h"\
	

"$(INTDIR)\RegKey.obj" : $(SOURCE) $(DEP_CPP_REGKE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\FileIO.cpp
DEP_CPP_FILEI=\
	".\./Common\StringFn.h"\
	".\Common\Common.h"\
	".\Common\FileIO.h"\
	

"$(INTDIR)\FileIO.obj" : $(SOURCE) $(DEP_CPP_FILEI) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CDiagram.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CDIAG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CDiagram.obj" : $(SOURCE) $(DEP_CPP_CDIAG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CDIAG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CDiagram.obj" : $(SOURCE) $(DEP_CPP_CDIAG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CModule.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CMODUL=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CModule.obj" : $(SOURCE) $(DEP_CPP_CMODUL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CMODUL=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CModule.obj" : $(SOURCE) $(DEP_CPP_CMODUL) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DiagramDoc.cpp
DEP_CPP_DIAGR=\
	".\DiagramDoc.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	

"$(INTDIR)\DiagramDoc.obj" : $(SOURCE) $(DEP_CPP_DIAGR) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DiagramFrame.cpp
DEP_CPP_DIAGRA=\
	".\DiagramFrame.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	

"$(INTDIR)\DiagramFrame.obj" : $(SOURCE) $(DEP_CPP_DIAGRA) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\DiagramView.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_DIAGRAM=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogObjectName.h"\
	".\./Dialog\DialogWorldConstant.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DiagramView.obj" : $(SOURCE) $(DEP_CPP_DIAGRAM) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_DIAGRAM=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogObjectName.h"\
	".\./Dialog\DialogWorldConstant.h"\
	".\CFontInfo.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DiagramView.obj" : $(SOURCE) $(DEP_CPP_DIAGRAM) "$(INTDIR)"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\DiagramNew.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_DIAGRAMN=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DiagramNew.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DiagramNew.obj" : $(SOURCE) $(DEP_CPP_DIAGRAMN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_DIAGRAMN=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DiagramNew.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DiagramNew.obj" : $(SOURCE) $(DEP_CPP_DIAGRAMN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CDiagramWindow.cpp
DEP_CPP_CDIAGR=\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CUndoAction.h"\
	".\Common\Common.h"\
	

"$(INTDIR)\CDiagramWindow.obj" : $(SOURCE) $(DEP_CPP_CDIAGR) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\DialogWorldConstant.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_DIALO=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogWorldConstant.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DialogWorldConstant.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_DIALO=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogWorldConstant.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DialogWorldConstant.obj" : $(SOURCE) $(DEP_CPP_DIALO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\ModuleNumericPage.cpp
DEP_CPP_MODULEN=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Dialog\ModuleNumericPage.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\ModuleNumericPage.obj" : $(SOURCE) $(DEP_CPP_MODULEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\ModulePage.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_MODULEP=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\ModuleConfig.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\ModulePage.obj" : $(SOURCE) $(DEP_CPP_MODULEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_MODULEP=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\CFontInfo.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\DiagramView.h"\
	".\Dialog\ModuleConfig.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\ModulePage.obj" : $(SOURCE) $(DEP_CPP_MODULEP) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CEvent.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CEVEN=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CEvent.obj" : $(SOURCE) $(DEP_CPP_CEVEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CEVEN=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CEvent.obj" : $(SOURCE) $(DEP_CPP_CEVEN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Src\VRMLBrowser\OpenGLFn.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_OPENG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\../VRMLBrowser\OpenGLFn.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\gl\GLAUX.H"\
	{$(INCLUDE)}"\gl\GLU.H"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\OpenGLFn.obj" : $(SOURCE) $(DEP_CPP_OPENG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_OPENG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\../VRMLBrowser\OpenGLFn.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\gl\GL.H"\
	{$(INCLUDE)}"\gl\GLAUX.H"\
	{$(INCLUDE)}"\gl\GLU.H"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\OpenGLFn.obj" : $(SOURCE) $(DEP_CPP_OPENG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\ModuleObjectPage.cpp
DEP_CPP_MODULEO=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CModuleType.h"\
	".\./Common\Icon.h"\
	".\./Dialog\ModuleObjectPage.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\Dialog\ModulePage.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\ModuleObjectPage.obj" : $(SOURCE) $(DEP_CPP_MODULEO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\DialogObjectName.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_DIALOG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogObjectName.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DialogObjectName.obj" : $(SOURCE) $(DEP_CPP_DIALOG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_DIALOG=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\DialogObjectName.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DialogObjectName.obj" : $(SOURCE) $(DEP_CPP_DIALOG) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CUndoAction.cpp
DEP_CPP_CUNDO=\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	".\./Common\CUndoAction.h"\
	".\Common\Common.h"\
	

"$(INTDIR)\CUndoAction.obj" : $(SOURCE) $(DEP_CPP_CUNDO) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\DialogNodeConfig.cpp
DEP_CPP_DIALOGN=\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFVec3f.h"\
	".\./Dialog\DialogNodeConfig.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\DialogNodeConfig.obj" : $(SOURCE) $(DEP_CPP_DIALOGN) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\CFontInfo.cpp
DEP_CPP_CFONT=\
	".\./Common\RegKey.h"\
	".\CFontInfo.h"\
	".\Common\Common.h"\
	

"$(INTDIR)\CFontInfo.obj" : $(SOURCE) $(DEP_CPP_CFONT) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Common\CUndoActionFn.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_CUNDOA=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CUndoActionFn.obj" : $(SOURCE) $(DEP_CPP_CUNDOA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_CUNDOA=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagram.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModule.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\CUndoActionFn.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\CUndoActionFn.obj" : $(SOURCE) $(DEP_CPP_CUNDOA) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\DialogNewUserEvent.cpp
DEP_CPP_DIALOGNE=\
	".\./Dialog\UserEventPickupPage.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	".\DialogNewUserEvent.h"\
	{$(INCLUDE)}"\JString.h"\
	

"$(INTDIR)\DialogNewUserEvent.obj" : $(SOURCE) $(DEP_CPP_DIALOGNE) "$(INTDIR)"


# End Source File
################################################################################
# Begin Source File

SOURCE=.\Dialog\UserEventPickupPage.cpp

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

DEP_CPP_USERE=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\UserEventPickupPage.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\UserEventPickupPage.obj" : $(SOURCE) $(DEP_CPP_USERE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

DEP_CPP_USERE=\
	"..\VrmlLIB\Anchor.h"\
	"..\VrmlLIB\Appearance.h"\
	"..\VrmlLIB\AudioClip.h"\
	"..\VrmlLIB\Background.h"\
	"..\VrmlLIB\Billboard.h"\
	"..\VrmlLIB\Box.h"\
	"..\VrmlLIB\CJavaVM.h"\
	"..\VrmlLIB\CLinkedList.h"\
	"..\VrmlLIB\CLinkedListNode.h"\
	"..\VrmlLIB\Collision.h"\
	"..\VrmlLIB\Color.h"\
	"..\VrmlLIB\ColorInterpolator.h"\
	"..\VrmlLIB\Cone.h"\
	"..\VrmlLIB\Coordinate.h"\
	"..\VrmlLIB\CoordinateInterpolator.h"\
	"..\VrmlLIB\Cylinder.h"\
	"..\VrmlLIB\CylinderSensor.h"\
	"..\VrmlLIB\DEF.h"\
	"..\VrmlLIB\DirectionalLight.h"\
	"..\VrmlLIB\ElevationGrid.h"\
	"..\VrmlLIB\Extrusion.h"\
	"..\VrmlLIB\Fog.h"\
	"..\VrmlLIB\FontStyle.h"\
	"..\VrmlLIB\Group.h"\
	"..\VrmlLIB\GroupingNode.h"\
	"..\VrmlLIB\ImageTexture.h"\
	"..\VrmlLIB\IndexedFaceSet.h"\
	"..\VrmlLIB\IndexedLineSet.h"\
	"..\VrmlLIB\Inline.h"\
	"..\VrmlLIB\JNode.h"\
	"..\VrmlLIB\JScript.h"\
	"..\VrmlLIB\JVector.h"\
	"..\VrmlLIB\Lod.h"\
	"..\VrmlLIB\Material.h"\
	"..\VrmlLIB\MFColor.h"\
	"..\VrmlLIB\MFFloat.h"\
	"..\VrmlLIB\MField.h"\
	"..\VrmlLIB\MFInt32.h"\
	"..\VrmlLIB\MFRotation.h"\
	"..\VrmlLIB\MFString.h"\
	"..\VrmlLIB\MFTime.h"\
	"..\VrmlLIB\MFVec2f.h"\
	"..\VrmlLIB\MFVec3f.h"\
	"..\VrmlLIB\MovieTexture.h"\
	"..\VrmlLIB\NavigationInfo.h"\
	"..\VrmlLIB\NodeList.h"\
	"..\VrmlLIB\Normal.h"\
	"..\VrmlLIB\NormalInterpolator.h"\
	"..\VrmlLIB\OrientationInterpolator.h"\
	"..\VrmlLIB\Parser.h"\
	"..\VrmlLIB\ParserNode.h"\
	"..\VrmlLIB\PixelTexture.h"\
	"..\VrmlLIB\PlaneSensor.h"\
	"..\VrmlLIB\PointLight.h"\
	"..\VrmlLIB\PointSet.h"\
	"..\VrmlLIB\PositionInterpolator.h"\
	"..\VrmlLIB\ProximitySensor.h"\
	"..\VrmlLIB\RootNode.h"\
	"..\VrmlLIB\Route.h"\
	"..\VrmlLIB\ScalarInterpolator.h"\
	"..\VrmlLIB\Script.h"\
	"..\VrmlLIB\SFColor.h"\
	"..\VrmlLIB\SFFloat.h"\
	"..\VrmlLIB\SFImage.h"\
	"..\VrmlLIB\SFInt32.h"\
	"..\VrmlLIB\SFMatrix.h"\
	"..\VrmlLIB\SFNode.h"\
	"..\VrmlLIB\SFRotation.h"\
	"..\VrmlLIB\SFString.h"\
	"..\VrmlLIB\SFTime.h"\
	"..\VrmlLIB\SFVec3f.h"\
	"..\VrmlLIB\Shape.h"\
	"..\VrmlLIB\Sound.h"\
	"..\VrmlLIB\Sphere.h"\
	"..\VrmlLIB\SphereSensor.h"\
	"..\VrmlLIB\SpotLight.h"\
	"..\VrmlLIB\Switch.h"\
	"..\VrmlLIB\Text.h"\
	"..\VrmlLIB\TextureCoordinate.h"\
	"..\VrmlLIB\TextureTransform.h"\
	"..\VrmlLIB\TimeSensor.h"\
	"..\VrmlLIB\TouchSensor.h"\
	"..\VrmlLIB\Transform.h"\
	"..\VrmlLIB\Viewpoint.h"\
	"..\VrmlLIB\VisibilitySensor.h"\
	"..\VrmlLIB\vrmlnodes.h"\
	"..\VrmlLIB\vrmlparser.h"\
	"..\VrmlLIB\WorldInfo.h"\
	".\./Common\CDiagramWindow.h"\
	".\./Common\CEvent.h"\
	".\./Common\CModuleType.h"\
	".\./Common\CUndoAction.h"\
	".\./Common\Icon.h"\
	".\./Common\StringFn.h"\
	".\./Common\World.h"\
	".\./Dialog\UserEventPickupPage.h"\
	".\Common\CEventType.h"\
	".\Common\Common.h"\
	".\Dialog\..\CyberToolBox.h"\
	".\Dialog\..\stdafx.h"\
	{$(INCLUDE)}"\Field.h"\
	{$(INCLUDE)}"\jni.h"\
	{$(INCLUDE)}"\jni_md.h"\
	{$(INCLUDE)}"\JString.h"\
	{$(INCLUDE)}"\Node.h"\
	{$(INCLUDE)}"\SceneGraph.h"\
	{$(INCLUDE)}"\SFBool.h"\
	{$(INCLUDE)}"\SFVec2f.h"\
	{$(INCLUDE)}"\sys\timeb.h"\
	{$(INCLUDE)}"\vrmlfields.h"\
	{$(INCLUDE)}"\vrmlstring.h"\
	

"$(INTDIR)\UserEventPickupPage.obj" : $(SOURCE) $(DEP_CPP_USERE) "$(INTDIR)"
   $(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
