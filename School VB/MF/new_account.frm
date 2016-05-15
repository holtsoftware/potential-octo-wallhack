VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form new_account 
   Caption         =   "New Account"
   ClientHeight    =   2760
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6600
   LinkTopic       =   "Form1"
   ScaleHeight     =   2760
   ScaleWidth      =   6600
   StartUpPosition =   3  'Windows Default
   Begin MSAdodcLib.Adodc connection 
      Height          =   735
      Left            =   1440
      Top             =   3480
      Width           =   3495
      _ExtentX        =   6165
      _ExtentY        =   1296
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   8
      CursorOptions   =   0
      CacheSize       =   50
      MaxRecords      =   0
      BOFAction       =   0
      EOFAction       =   0
      ConnectStringType=   3
      Appearance      =   1
      BackColor       =   -2147483643
      ForeColor       =   -2147483640
      Orientation     =   0
      Enabled         =   -1
      Connect         =   "DSN=MF"
      OLEDBString     =   ""
      OLEDBFile       =   ""
      DataSourceName  =   "MF"
      OtherAttributes =   ""
      UserName        =   "sa"
      Password        =   ""
      RecordSource    =   ""
      Caption         =   "Adodc1"
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      _Version        =   393216
   End
   Begin VB.CommandButton CmdClose 
      Caption         =   "&Close"
      Height          =   375
      Left            =   5040
      TabIndex        =   10
      Top             =   120
      Width           =   1455
   End
   Begin VB.TextBox TxtOD 
      Height          =   375
      Left            =   4440
      TabIndex        =   8
      Top             =   2280
      Width           =   2055
   End
   Begin VB.TextBox TxtEmail 
      Height          =   375
      Left            =   1440
      MaxLength       =   25
      TabIndex        =   7
      Top             =   2160
      Width           =   1695
   End
   Begin VB.TextBox TxtFax 
      Height          =   375
      Left            =   4440
      MaxLength       =   14
      TabIndex        =   6
      Top             =   1800
      Width           =   2055
   End
   Begin VB.TextBox TxtPN 
      Height          =   375
      Left            =   1440
      MaxLength       =   14
      TabIndex        =   5
      Top             =   1680
      Width           =   1695
   End
   Begin VB.TextBox TxtAdd 
      Height          =   855
      Left            =   4440
      MaxLength       =   50
      MultiLine       =   -1  'True
      TabIndex        =   4
      Top             =   720
      Width           =   2055
   End
   Begin VB.TextBox TxtName 
      Height          =   375
      Left            =   1440
      MaxLength       =   25
      TabIndex        =   3
      Top             =   1200
      Width           =   1695
   End
   Begin VB.TextBox TxtAN 
      Height          =   375
      Left            =   1440
      Locked          =   -1  'True
      MaxLength       =   4
      TabIndex        =   2
      Top             =   720
      Width           =   1695
   End
   Begin VB.CommandButton CmdCA 
      Caption         =   "&Create Account"
      Height          =   375
      Left            =   3360
      TabIndex        =   9
      Top             =   120
      Width           =   1455
   End
   Begin VB.TextBox TxtSSN 
      Height          =   375
      Left            =   720
      MaxLength       =   9
      TabIndex        =   1
      Top             =   120
      Width           =   2415
   End
   Begin VB.Label Label8 
      Caption         =   "Open Date:"
      Height          =   255
      Left            =   3240
      TabIndex        =   17
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label7 
      Caption         =   "E-mail:"
      Height          =   255
      Left            =   120
      TabIndex        =   16
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label6 
      Caption         =   "Fax #:"
      Height          =   255
      Left            =   3240
      TabIndex        =   15
      Top             =   1800
      Width           =   1215
   End
   Begin VB.Label Label5 
      Caption         =   "Phone #:"
      Height          =   255
      Left            =   120
      TabIndex        =   14
      Top             =   1800
      Width           =   1215
   End
   Begin VB.Label Label4 
      Caption         =   "Address:"
      Height          =   255
      Left            =   3240
      TabIndex        =   13
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   12
      Top             =   1320
      Width           =   735
   End
   Begin VB.Label Label2 
      Caption         =   "Account Number:"
      Height          =   255
      Left            =   120
      TabIndex        =   11
      Top             =   840
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   " SSN:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   495
   End
End
Attribute VB_Name = "new_account"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public cnn As New ADODB.connection
Public Rds As ADODB.Recordset

Function connect()
Set cnn = New ADODB.connection
    cnn.Provider = "MSDASQL"
    cnn.ConnectionString = "Provider=MSDASQL.1;" & _
                           "Persist Security Info=False;" & _
                           "Data Source=MF"
    cnn.Open
End Function

Private Sub CmdCA_Click()
If (Len(TxtSSN.Text) < 9) Then
    MsgBox ("Invalid SSN")
    Exit Sub
End If
If (Len(TxtName.Text) <= 0) Then
    MsgBox ("You must enter a name")
    Exit Sub
End If
If (Len(TxtAdd.Text) <= 0) Then
    MsgBox ("You must enter an address")
    Exit Sub
End If
If (Len(TxtOD.Text) <= 0) Then
    TxtOD.Text = DateTime.Date
End If
Call connect
Set Rds = cnn.Execute("SELECT MAX(AccountN) FROM CACCOUNT")
TxtAN.Text = Rds(0) + 1
cnn.Execute ("Insert into CACCOUNT Values ( " & _
                            TxtAN.Text & ",'" & _
                            TxtName.Text & "','" & _
                            TxtSSN.Text & "','" & _
                            TxtAdd.Text & "','" & _
                            TxtPN.Text & "','" & _
                            TxtFax.Text & "','" & _
                            TxtEmail.Text & "','" & _
                            TxtOD.Text & "',''," & _
                             Str(1) & ")")
cnn.Close

End Sub

Private Sub Cmdclose_Click()
Unload Me
End Sub

Private Sub Form_Load()
main.Enabled = False
End Sub

Private Sub Form_Unload(Cancel As Integer)
main.Enabled = True
End Sub
