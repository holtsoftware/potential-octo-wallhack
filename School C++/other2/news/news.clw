; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNewsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "news.h"

ClassCount=3
Class1=CNewsApp
Class2=CNewsDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_NEWS_DIALOG

[CLS:CNewsApp]
Type=0
HeaderFile=news.h
ImplementationFile=news.cpp
Filter=N

[CLS:CNewsDlg]
Type=0
HeaderFile=newsDlg.h
ImplementationFile=newsDlg.cpp
Filter=D
LastObject=IDCANCEL
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=newsDlg.h
ImplementationFile=newsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NEWS_DIALOG]
Type=1
Class=CNewsDlg
ControlCount=1
Control1=IDC_BUTTON1,button,1342242816

