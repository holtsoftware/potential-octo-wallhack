; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDay6Dlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Day 6.h"

ClassCount=3
Class1=CDay6App
Class2=CDay6Dlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DAY6_DIALOG
Resource4=IDR_MENU1
Resource5=IDR_ACCELERATOR1

[CLS:CDay6App]
Type=0
HeaderFile=Day 6.h
ImplementationFile=Day 6.cpp
Filter=N

[CLS:CDay6Dlg]
Type=0
HeaderFile=Day 6Dlg.h
ImplementationFile=Day 6Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDM_FILE_EXIT

[CLS:CAboutDlg]
Type=0
HeaderFile=Day 6Dlg.h
ImplementationFile=Day 6Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DAY6_DIALOG]
Type=1
Class=CDay6Dlg
ControlCount=1
Control1=IDC_EXIT,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=CDay6Dlg
Command1=IDM_FILE_HELLO
Command2=IDM_FILE_EXIT
Command3=IDM_HELP_ABOUT
CommandCount=3

[ACL:IDR_ACCELERATOR1]
Type=1
Class=CDay6Dlg
Command1=IDM_HELP_ABOUT
Command2=IDM_FILE_EXIT
CommandCount=2

