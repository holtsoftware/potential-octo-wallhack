# Microsoft Developer Studio Generated NMAKE File, Based on new4.dsp
!IF "$(CFG)" == ""
CFG=new4 - Win32 Debug
!MESSAGE No configuration specified. Defaulting to new4 - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "new4 - Win32 Release" && "$(CFG)" != "new4 - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "new4.mak" CFG="new4 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "new4 - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "new4 - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.\Release
INTDIR=.\Release

ALL : 


CLEAN :
	-@erase 

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

MTL=midl.exe

!IF  "$(CFG)" == "new4 - Win32 Release"

!ELSEIF  "$(CFG)" == "new4 - Win32 Debug"

!ENDIF 

MTL_PROJ=

!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("new4.dep")
!INCLUDE "new4.dep"
!ELSE 
!MESSAGE Warning: cannot find "new4.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "new4 - Win32 Release" || "$(CFG)" == "new4 - Win32 Debug"

!ENDIF 

