VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "AutoRun"
   ClientHeight    =   2190
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   4710
   Icon            =   "AutoRunFRM.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2190
   ScaleWidth      =   4710
   StartUpPosition =   3  'Windows Default
   Begin VB.Label Label4 
      Caption         =   "CD Code 25595-OEM-0003301-54321"
      Height          =   375
      Left            =   120
      TabIndex        =   6
      Top             =   120
      Width           =   2055
   End
   Begin VB.Label Label3 
      Caption         =   "Internet Explorer 4"
      Height          =   375
      Left            =   3240
      TabIndex        =   5
      Top             =   1680
      Width           =   1335
   End
   Begin VB.OLE OLE3 
      Height          =   975
      Left            =   3240
      TabIndex        =   4
      Top             =   600
      Width           =   1335
   End
   Begin VB.Label Label2 
      Caption         =   "MSN Internet Access Verson2.6"
      Height          =   495
      Left            =   1680
      TabIndex        =   3
      Top             =   1680
      Width           =   1335
   End
   Begin VB.OLE OLE2 
      Height          =   975
      Left            =   1680
      TabIndex        =   2
      Top             =   600
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "MS Windows 95 Plus Pack"
      Height          =   495
      Left            =   120
      TabIndex        =   1
      Top             =   1680
      Width           =   1215
   End
   Begin VB.OLE OLE1 
      Height          =   975
      Left            =   120
      TabIndex        =   0
      Top             =   600
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
OLE1.CreateLink ("Win95PlusPack\SETUP.EXE")
OLE2.CreateLink ("CDSETUP.EXE")
OLE3.CreateLink ("MsnSetup\Compnts\IE4Inst\ie4setup.exe")
End Sub

