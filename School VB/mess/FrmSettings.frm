VERSION 5.00
Begin VB.Form FrmSettings 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Settings"
   ClientHeight    =   2175
   ClientLeft      =   4440
   ClientTop       =   2910
   ClientWidth     =   4455
   Icon            =   "FrmSettings.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2175
   ScaleWidth      =   4455
   Begin VB.CommandButton CmdSave 
      Caption         =   "&Save"
      Default         =   -1  'True
      Height          =   375
      Left            =   1800
      TabIndex        =   9
      Tag             =   "4"
      Top             =   1680
      Width           =   1215
   End
   Begin VB.CommandButton CmdCancle 
      Caption         =   "Ca&ncle"
      Height          =   375
      Left            =   3120
      TabIndex        =   8
      Top             =   1680
      Width           =   1215
   End
   Begin VB.TextBox TxtDUN 
      Height          =   375
      Left            =   2280
      TabIndex        =   7
      Top             =   1200
      Width           =   2055
   End
   Begin VB.TextBox TxtDS 
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   1200
      Width           =   2055
   End
   Begin VB.TextBox TxtDP 
      Height          =   375
      Left            =   2280
      TabIndex        =   3
      Top             =   360
      Width           =   2055
   End
   Begin VB.TextBox TxtDRC 
      Height          =   375
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   2055
   End
   Begin VB.Line Line1 
      X1              =   0
      X2              =   4440
      Y1              =   840
      Y2              =   840
   End
   Begin VB.Label Label1 
      Caption         =   "Default Remote Computer"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1935
   End
   Begin VB.Label Label4 
      Caption         =   "Default User Name"
      Height          =   255
      Left            =   2280
      TabIndex        =   6
      Top             =   960
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "Default Server"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   960
      Width           =   2055
   End
   Begin VB.Label Label2 
      Caption         =   "Default Port"
      Height          =   255
      Left            =   2280
      TabIndex        =   2
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "FrmSettings"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim settings As New AppSettings
Dim settingfile As String

Private Sub CmdCancle_Click()
Unload Me
ServerFRM.Enabled = True
ServerFRM.Show
End Sub

Private Sub CmdSave_Click()
settings.add TxtDRC.Text
settings.add TxtDP.Text
settings.add TxtDS.Text
settings.add TxtDUN.Text
settings.save settingfile
Unload Me
ServerFRM.Enabled = True
ServerFRM.Show
End Sub

Private Sub Form_Load()
Set settings = New AppSettings
settingfile = "MessangerSettings.ini"
If (settings.load(settingfile)) Then
TxtDRC.Text = settings.getitem(0)
TxtDP.Text = settings.getitem(1)
TxtDS.Text = settings.getitem(2)
TxtDUN.Text = settings.getitem(3)
End If
End Sub

Private Sub Form_Unload(Cancel As Integer)
Unload Me
End Sub
