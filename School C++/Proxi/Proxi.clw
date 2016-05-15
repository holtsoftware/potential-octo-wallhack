; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CProxiDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Proxi.h"
ODLFile=Proxi.odl

ClassCount=4
Class1=CProxiApp
Class2=CProxiDlg
Class3=CAboutDlg
Class4=CProxiDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PROXI_DIALOG

[CLS:CProxiApp]
Type=0
HeaderFile=Proxi.h
ImplementationFile=Proxi.cpp
Filter=N

[CLS:CProxiDlg]
Type=0
HeaderFile=ProxiDlg.h
ImplementationFile=ProxiDlg.cpp
Filter=D
LastObject=IDC_EDIT2
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ProxiDlg.h
ImplementationFile=ProxiDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CProxiDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_PROXI_DIALOG]
Type=1
Class=CProxiDlg
ControlCount=4
Control1=IDC_MYEDIT,edit,1350631620
Control2=IDC_MYPORT,edit,1350631552
Control3=IDC_CMDBIND,button,1342242816
Control4=IDC_STATIC,static,1342308352

