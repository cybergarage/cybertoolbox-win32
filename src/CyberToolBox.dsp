# Microsoft Developer Studio Project File - Name="CyberToolBox" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=CyberToolBox - Win32 Release
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "CyberToolBox.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "CyberToolBox.mak" CFG="CyberToolBox - Win32 Release"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "CyberToolBox - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "CyberToolBox - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CyberToolBox - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /WX /GX /O2 /I ".\Common" /I ".\Dialog" /D "NDEBUG" /D "SUPPORT_STL" /D "SUPPORT_OPENGL" /D "SUPPORT_JPEG" /D "SUPPORT_PNG" /D "SUPPORT_JSAI" /D "SUPPORT_SOUND" /D "SUPPORT_URL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "OPENGL" /D "_AFXDLL" /FD /c
# SUBTRACT CPP /X /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 javai.lib opengl32.lib glu32.lib glaux.lib winmm.lib jpeg6a.lib libpng.lib zlib.lib LibCyberVRML97.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"LIBCD.LIB LIBMTD" /out:".\Bin/CyberToolBox.exe" /libpath:"..\SceneGraph" /libpath:"..\jpeg-6a" /libpath:"..\lpng102" /libpath:"..\zlib113" /libpath:"c:\jdk1.1.6\lib"

!ELSEIF  "$(CFG)" == "CyberToolBox - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /WX /Gm /GX /ZI /Od /I "c:\jdk1.1.6\include" /I "c:\jdk1.1.6\include\win32" /I ".\Common" /I ".\Dialog" /D "_DEBUG" /D "SUPPORT_STL" /D "SUPPORT_OPENGL" /D "SUPPORT_JPEG" /D "SUPPORT_PNG" /D "SUPPORT_JSAI" /D "SUPPORT_SOUND" /D "SUPPORT_URL" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "OPENGL" /D "_AFXDLL" /FD /c
# SUBTRACT CPP /X /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 javai.lib opengl32.lib glu32.lib glaux.lib winmm.lib jpeg6a.lib libpng.lib zlib.lib LibCyberVRML97.lib /nologo /subsystem:windows /profile /map /debug /machine:I386 /nodefaultlib:"LIBCD.LIB" /out:".\Bin/CyberToolBox.exe" /libpath:"..\SceneGraph" /libpath:"..\jpeg-6a" /libpath:"..\lpng102" /libpath:"..\zlib113" /libpath:"c:\jdk1.1.6\lib"

!ENDIF 

# Begin Target

# Name "CyberToolBox - Win32 Release"
# Name "CyberToolBox - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Common\CDiagram.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CDiagramClipboard.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CDiagramWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\CFontInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CGlobalData.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CJavaConsole.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CModule.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CModuleType.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CUndoAction.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\CUndoActionFn.cpp
# End Source File
# Begin Source File

SOURCE=.\CyberToolBox.cpp
# End Source File
# Begin Source File

SOURCE=.\CyberToolBox.rc
# End Source File
# Begin Source File

SOURCE=.\CyberToolBoxDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\CyberToolBoxView.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagramDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagramFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DiagramNew.cpp
# End Source File
# Begin Source File

SOURCE=.\DiagramView.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialgoBackgroundName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogAudioClipName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogDiagram.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogDiagramConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventArea.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventClock.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventDrag.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventFrame.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventPickup.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventTimer.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterHigh.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterLow.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterRange.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterScale.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogGlobalDataName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogImageTextureName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogLightName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogMaterialName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogMFieldConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterOrientationInterp.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterPosition2DInterp.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterPosition3DInterp.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterScalarInterp.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpColor.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpNormal.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpOrientation.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpPosition.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpScalar.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleMiscPlaySound.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringBool.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringOrientation.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringPosition.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringVector.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogNewUserEvent.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogNodeConfig.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogNodeNew.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogObjectAppearance.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DIalogObjectCollision.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogObjectName.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogOrthviewConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogPerspectiveViewConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogProgress.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogRouteInfo.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFBoolConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFFloatConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFInt32Config.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFRotationConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFStringConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFTimeConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFVec2fConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFVec3fConfig.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSwitchName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogTextName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogViewName.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogWorldConstant.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\File.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\icon.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\LicenceCode.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleBooleanPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\moduleconfig.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\ModuleFilename.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleFilterPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\ModuleFloating.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleGeomPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleInterpPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleLightPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMaterialPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMathPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMiscPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleNodePage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleNumericPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleObjectPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModulePage.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleViewPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleWorldPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\OpenGLFn.cpp
# End Source File
# Begin Source File

SOURCE=.\OrthoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\OrthoFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\OrthoView.cpp
# End Source File
# Begin Source File

SOURCE=.\PerspectiveDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PerspectiveFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\PerspectiveView.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\PrimitiveFloating.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\Common\RegKey.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Common\StringFn.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventAreaPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventClockPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventCollisionPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventDragPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventPickupPage.cpp
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventTimerPage.cpp
# ADD CPP /I ".."
# End Source File
# Begin Source File

SOURCE=.\Common\UserMessage.cpp
# End Source File
# Begin Source File

SOURCE=.\Common\World.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\Common\CDiagram.h
# End Source File
# Begin Source File

SOURCE=.\Common\CDiagramClipboard.h
# End Source File
# Begin Source File

SOURCE=.\Common\CDiagramWindow.h
# End Source File
# Begin Source File

SOURCE=.\Common\CEvent.h
# End Source File
# Begin Source File

SOURCE=.\CFontInfo.h
# End Source File
# Begin Source File

SOURCE=.\Common\CGlobalData.h
# End Source File
# Begin Source File

SOURCE=.\CJavaConsole.h
# End Source File
# Begin Source File

SOURCE=.\Common\CModule.h
# End Source File
# Begin Source File

SOURCE=.\Common\CModuleType.h
# End Source File
# Begin Source File

SOURCE=.\Common\CUndoAction.h
# End Source File
# Begin Source File

SOURCE=.\Common\CUndoActionFn.h
# End Source File
# Begin Source File

SOURCE=.\CyberToolBox.h
# End Source File
# Begin Source File

SOURCE=.\CyberToolBoxDoc.h
# End Source File
# Begin Source File

SOURCE=.\CyberToolBoxView.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DiagloViewName.h
# End Source File
# Begin Source File

SOURCE=.\DiagramDoc.h
# End Source File
# Begin Source File

SOURCE=.\DiagramFrame.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DiagramNew.h
# End Source File
# Begin Source File

SOURCE=.\DiagramView.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialgoBackgroundName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogAudioClipName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogDiagram.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogDiagramConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEvent.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventArea.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventClock.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventDrag.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventFrame.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventPickup.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogEventTimer.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterHigh.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterLow.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterRange.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogFilterScale.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogGlobalDataName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogImageTextureName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogLightName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogMaterialName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogMFieldConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterOrientationInterp.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterPosition2DInterp.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterPosition3DInterp.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleFilterScalarInterp.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpColor.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpNormal.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpOrientation.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpPosition.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleInterpScalar.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleMiscPlaySound.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModulePosition2DInterp.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringBool.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringOrientation.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringPosition.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringPostion.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogModuleStringVector.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogNodeConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogNodeNew.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogObjectAppearance.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DIalogObjectCollision.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogObjectName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogOrthviewConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogPerspectiveViewConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogProgress.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogRouteInfo.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFBoolConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFFloatConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFieldConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFInt32Config.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFRotation.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFRotationConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFStringConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFTimeConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFVec2fConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSFVec3fConfig.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogSwitchName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogTextName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogVewName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogViewName.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\DialogWorldConstant.h
# End Source File
# Begin Source File

SOURCE=.\Common\FileIO.h
# End Source File
# Begin Source File

SOURCE=.\Common\GenCode.h
# End Source File
# Begin Source File

SOURCE=.\Common\Icon.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleBooleanPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleConfig.h
# End Source File
# Begin Source File

SOURCE=.\Common\ModuleFilename.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleFilterPage.h
# End Source File
# Begin Source File

SOURCE=.\ModuleFloating.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleGeomPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleInterpPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleLightPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMaterialPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMathPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleMiscPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleNodePage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleNumericPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleObjectPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModulePage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleViewPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\ModuleWorldPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\NodeNewDialog.h
# End Source File
# Begin Source File

SOURCE=..\VRMLBrowser\OpenGLFn.h
# End Source File
# Begin Source File

SOURCE=.\PerspectiveDoc.h
# End Source File
# Begin Source File

SOURCE=.\PerspectiveFrame.h
# End Source File
# Begin Source File

SOURCE=.\PerspectiveView.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\PrimitiveFloating.h
# End Source File
# Begin Source File

SOURCE=.\Common\RegKey.h
# End Source File
# Begin Source File

SOURCE=.\stdafx.h
# End Source File
# Begin Source File

SOURCE=.\Common\StringFn.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEvent.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventAreaPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventClock.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventClockPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventCollisionPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventDragPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventPage.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventPicking.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventTimer.h
# End Source File
# Begin Source File

SOURCE=.\Dialog\UserEventTimerPage.h
# End Source File
# Begin Source File

SOURCE=.\Common\World.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\backgrou.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BITMAP2.BMP
# End Source File
# Begin Source File

SOURCE=.\res\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00003.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00004.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BMP00005.BMP
# End Source File
# Begin Source File

SOURCE=.\res\bmp00006.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00007.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00008.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00009.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00010.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00011.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00012.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00013.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00014.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00015.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00016.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BMP00017.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00018.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00019.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00020.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00021.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00022.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00023.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00024.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00025.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00026.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00027.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00028.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00029.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00030.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00031.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00032.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00033.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00034.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00035.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00036.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00037.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00038.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00039.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00040.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00041.BMP
# End Source File
# Begin Source File

SOURCE=.\res\BMP00042.BMP
# End Source File
# Begin Source File

SOURCE=.\res\bmp00043.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00044.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00045.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00046.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00047.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00048.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00049.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00050.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00051.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00052.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00053.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00054.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00055.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmp00056.bmp
# End Source File
# Begin Source File

SOURCE=.\res\collisio.bmp
# End Source File
# Begin Source File

SOURCE=.\res\colorint.bmp
# End Source File
# Begin Source File

SOURCE=.\res\coordint.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cur00001.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00002.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00003.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00004.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00005.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00006.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00007.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00008.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00009.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00010.cur
# End Source File
# Begin Source File

SOURCE=.\res\cur00011.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\cursor2.cur
# End Source File
# Begin Source File

SOURCE=.\res\CyberToolBox.ico
# End Source File
# Begin Source File

SOURCE=.\res\CyberToolBox.rc2
# End Source File
# Begin Source File

SOURCE=.\res\CyberToolBoxDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\CYLINDER.BMP
# End Source File
# Begin Source File

SOURCE=.\res\diagram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\filter_h.ico
# End Source File
# Begin Source File

SOURCE=.\res\filter_l.ico
# End Source File
# Begin Source File

SOURCE=.\res\filter_r.ico
# End Source File
# Begin Source File

SOURCE=.\res\filter_s.ico
# End Source File
# Begin Source File

SOURCE=.\res\fontstyl.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00003.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00004.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00005.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00006.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00007.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00008.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00009.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00010.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00011.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00012.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00013.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\res\interp_.ico
# End Source File
# Begin Source File

SOURCE=.\res\movietex.bmp
# End Source File
# Begin Source File

SOURCE=.\res\navigati.bmp
# End Source File
# Begin Source File

SOURCE=.\res\position.bmp
# End Source File
# Begin Source File

SOURCE=.\res\primitiv.bmp
# End Source File
# Begin Source File

SOURCE=.\res\primitiv.cur
# End Source File
# Begin Source File

SOURCE=.\res\scenegra.bmp
# End Source File
# Begin Source File

SOURCE=.\res\textrans.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# End Group
# End Target
# End Project
