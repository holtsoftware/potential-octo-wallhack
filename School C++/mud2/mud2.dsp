# Microsoft Developer Studio Project File - Name="mud2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mud2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mud2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mud2.mak" CFG="mud2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mud2 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mud2 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mud2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "mud2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mud2 - Win32 Release"
# Name "mud2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\ACT_COMM.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\ACT_INFO.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\ACT_MOVE.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\ACT_OBJ.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\ACT_WIZ.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\COMM.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\CONST.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\DB.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\FIGHT.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\HANDLER.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\INTERP.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MAGIC.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MERC22.RC"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MERC22SV.RC"
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MOB_COMM.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MOB_PROG.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\SAVE.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\SPECIAL.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\UPDATE.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\W32COMM.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\WIN32SRV.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\WSCKCOMM.C"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\XRAND.C"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\MERC.H"
# End Source File
# Begin Source File

SOURCE="..\..\..\New Folder\New Folder (3)\TELNET.H"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
