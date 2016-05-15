# Microsoft Developer Studio Project File - Name="mud" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=mud - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mud.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mud.mak" CFG="mud - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mud - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "mud - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mud - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "mud - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mud - Win32 Release"
# Name "mud - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\alloca.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\array.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\backend.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\bibopmalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\binaries.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\call_out.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\comm1.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\debug.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\debugmalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\dmalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\drand48.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\ed.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\efun_defs.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\func_spec.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\gc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\genfkntab.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\gmalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\hash.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\hname.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\interface.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\interpret.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\lang.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\lex.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\main.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\make_func.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\make_table.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mapping.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mstring.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mudstat.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\ndesc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\net.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\nqueue.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\object.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\otable.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\parse.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\port.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\regexp.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\signals.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\simul_efun.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\simulate.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\smalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\snprintf.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\sprintf.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\strerror.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\strpbrk.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\strtod.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\super_snoop.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\swap.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\sysmalloc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\tcpsvc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\telnet.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\udpsvc.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\vprintf.c"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\wildmat.c"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\alloca.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\bibopmalloc.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\binaries.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\call_out.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\comm.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\comm1.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\config.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\drand48.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\efun_table.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\exec.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\hash.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\hname.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\incralloc.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\inline_eqs.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\inline_svalue.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\instrs.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\interface.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\interpret.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\lang.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\lex.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\lint.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\main.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mapping.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\master.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mstring.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\mudstat.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\ndesc.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\net.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\nqueue.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\object.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\patchlevel.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\regexp.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\sent.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\signals.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\simulate.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\super_snoop.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\swap.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\tcpsvc.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\telnet.h"
# End Source File
# Begin Source File

SOURCE="..\..\mud\gamedriver-20010812\udpsvc.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
