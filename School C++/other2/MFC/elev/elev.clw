; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CElevDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "elev.h"
ODLFile=elev.odl

ClassCount=4
Class1=CElevApp
Class2=CElevDlg
Class3=CAboutDlg
Class4=CElevDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_ELEV_DIALOG

[CLS:CElevApp]
Type=0
HeaderFile=elev.h
ImplementationFile=elev.cpp
Filter=N

[CLS:CElevDlg]
Type=0
HeaderFile=elevDlg.h
ImplementationFile=elevDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=elevDlg.h
ImplementationFile=elevDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CElevDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_ELEV_DIALOG]
Type=1
Class=CElevDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

