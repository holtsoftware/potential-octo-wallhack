VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form accountinfo 
   Caption         =   "Account Information"
   ClientHeight    =   3735
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6615
   LinkTopic       =   "Form1"
   ScaleHeight     =   3735
   ScaleWidth      =   6615
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CmdST 
      Caption         =   "Show Transactions"
      Enabled         =   0   'False
      Height          =   375
      Left            =   480
      TabIndex        =   25
      Top             =   3240
      Width           =   1695
   End
   Begin VB.CommandButton CmdBS 
      Caption         =   "Buy/Sell"
      Enabled         =   0   'False
      Height          =   375
      Left            =   2280
      TabIndex        =   24
      Top             =   3240
      Width           =   1215
   End
   Begin VB.CommandButton CmdUInfo 
      Caption         =   "&Update Info"
      Height          =   375
      Left            =   3600
      TabIndex        =   23
      Top             =   3240
      Width           =   1215
   End
   Begin VB.OptionButton OptClosed 
      Caption         =   "Closed"
      Height          =   255
      Left            =   5520
      TabIndex        =   22
      Top             =   2760
      Width           =   855
   End
   Begin VB.OptionButton OptOpen 
      Caption         =   "Open"
      Height          =   255
      Left            =   4320
      TabIndex        =   21
      Top             =   2760
      Width           =   975
   End
   Begin VB.TextBox TxtCD 
      Height          =   375
      Left            =   1440
      TabIndex        =   18
      Top             =   2640
      Width           =   1695
   End
   Begin VB.TextBox TxtSSN 
      Height          =   375
      Left            =   1440
      MaxLength       =   9
      TabIndex        =   3
      Top             =   1200
      Width           =   1695
   End
   Begin VB.CommandButton CmdLoad 
      Caption         =   "&Load Account"
      Default         =   -1  'True
      Height          =   375
      Left            =   3360
      TabIndex        =   8
      Top             =   120
      Width           =   1455
   End
   Begin VB.TextBox TxtAN 
      Height          =   375
      Left            =   1440
      MaxLength       =   4
      TabIndex        =   0
      Top             =   120
      Width           =   1695
   End
   Begin VB.TextBox TxtName 
      Height          =   375
      Left            =   1440
      MaxLength       =   25
      TabIndex        =   1
      Top             =   720
      Width           =   1695
   End
   Begin VB.TextBox TxtAdd 
      Height          =   855
      Left            =   4440
      MaxLength       =   50
      MultiLine       =   -1  'True
      TabIndex        =   2
      Top             =   720
      Width           =   2055
   End
   Begin VB.TextBox TxtPN 
      Height          =   375
      Left            =   1440
      MaxLength       =   14
      TabIndex        =   4
      Top             =   1680
      Width           =   1695
   End
   Begin VB.TextBox TxtFax 
      Height          =   375
      Left            =   4440
      MaxLength       =   14
      TabIndex        =   5
      Top             =   1680
      Width           =   2055
   End
   Begin VB.TextBox TxtEmail 
      Height          =   375
      Left            =   1440
      MaxLength       =   25
      TabIndex        =   6
      Top             =   2160
      Width           =   1695
   End
   Begin VB.TextBox TxtOD 
      Height          =   375
      Left            =   4440
      Locked          =   -1  'True
      TabIndex        =   7
      Top             =   2160
      Width           =   2055
   End
   Begin VB.CommandButton CmdClose 
      Caption         =   "&Close"
      Height          =   375
      Left            =   5040
      TabIndex        =   10
      Top             =   3240
      Width           =   1455
   End
   Begin MSAdodcLib.Adodc connection 
      Height          =   735
      Left            =   1320
      Top             =   4440
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
   Begin VB.Label Label10 
      Caption         =   "Status:"
      Height          =   255
      Left            =   3240
      TabIndex        =   20
      Top             =   2760
      Width           =   855
   End
   Begin VB.Label Label9 
      Caption         =   "Close Date:"
      Height          =   255
      Left            =   120
      TabIndex        =   19
      Top             =   2760
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   " SSN:"
      Height          =   255
      Left            =   120
      TabIndex        =   17
      Top             =   1320
      Width           =   495
   End
   Begin VB.Label Label2 
      Caption         =   "Account Number:"
      Height          =   255
      Left            =   120
      TabIndex        =   16
      Top             =   240
      Width           =   1335
   End
   Begin VB.Label Label3 
      Caption         =   "Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   15
      Top             =   840
      Width           =   735
   End
   Begin VB.Label Label4 
      Caption         =   "Address:"
      Height          =   255
      Left            =   3240
      TabIndex        =   14
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label5 
      Caption         =   "Phone #:"
      Height          =   255
      Left            =   120
      TabIndex        =   13
      Top             =   1800
      Width           =   1215
   End
   Begin VB.Label Label6 
      Caption         =   "Fax #:"
      Height          =   255
      Left            =   3240
      TabIndex        =   12
      Top             =   1800
      Width           =   1215
   End
   Begin VB.Label Label7 
      Caption         =   "E-mail:"
      Height          =   255
      Left            =   120
      TabIndex        =   11
      Top             =   2280
      Width           =   1215
   End
   Begin VB.Label Label8 
      Caption         =   "Open Date:"
      Height          =   255
      Left            =   3240
      TabIndex        =   9
      Top             =   2280
      Width           =   1215
   End
End
Attribute VB_Name = "accountinfo"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public cnn As New ADODB.connection
Public Rds As ADODB.Recordset
Public account

Function connect()
Set cnn = New ADODB.connection
    cnn.Provider = "MSDASQL"
    cnn.ConnectionString = "Provider=MSDASQL.1;" & _
                           "Persist Security Info=False;" & _
                           "Data Source=MF"
    cnn.Open
End Function

Private Sub CmdBS_Click()
Me.Enabled = False
bos.Show
bos.lblan = account
End Sub

Private Sub Cmdclose_Click()
Unload Me
End Sub

Private Sub CmdLoad_Click()
If (Len(TxtAN.Text) <> 4) Then
    MsgBox "The account number must be 4 charictes long."
    Exit Sub
End If
Call connect
Set Rds = cnn.Execute("SELECT * From CACCOUNT WHERE AccountN = " & TxtAN.Text)
If Rds.EOF And Rds.BOF Then
        MsgBox "The Account Number does not exsit in the system"
Else
    Dim stat As Integer
    TxtAN.Text = Rds(0)
    TxtName.Text = RTrim(Rds(1))
    TxtSSN.Text = RTrim(Rds(2))
    TxtAdd.Text = RTrim(Rds(3))
    TxtPN.Text = RTrim(Rds(4))
    TxtFax.Text = RTrim(Rds(5))
    TxtEmail.Text = RTrim(Rds(6))
    TxtOD.Text = RTrim(Rds(7))
    TxtCD.Text = RTrim(Rds(8))
    stat = Rds(9)
    account = TxtAN.Text
    CmdBS.Enabled = True
    CmdST.Enabled = True
    If (stat = 1) Then
        OptOpen.Value = True
        OptClosed.Value = False
    Else
        OptOpen.Value = False
        OptClosed.Value = True
    End If
End If
cnn.Close
End Sub

Private Sub CmdST_Click()
Me.Enabled = False
trans.Show
End Sub

Private Sub CmdUInfo_Click()
Dim stat
If (Len(TxtAN.Text) <> 4) Then
MsgBox "invalid account number"
End If
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
Set Rds = cnn.Execute("SELECT AccountN FROM CACCOUNT where AccountN = " & TxtAN.Text)
If (Rds.EOF And Rds.BOF) Then
    MsgBox "Account not in database"
    cnn.Close
    Exit Sub
End If
If (OptClosed.Value = True) Then
TxtCD.Text = DateTime.Date
stat = 0
Else
stat = 1
End If
cnn.Execute ("update CACCOUNT set Name = '" & TxtName.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set SSN = '" & TxtSSN.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set Address = '" & TxtAdd.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set PhoneN = '" & TxtPN.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set FaxN = '" & TxtFax.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set Email = '" & TxtEmail.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set AccountCD = '" & TxtCD.Text & "' where AccountN= " & TxtAN.Text)
cnn.Execute ("update CACCOUNT set AccountS = " & stat & " where AccountN = " & TxtAN.Text)

cnn.Close
End Sub

Private Sub Form_Load()
main.Enabled = False
End Sub

Private Sub Form_Unload(Cancel As Integer)
main.Enabled = True
End Sub

Private Sub OptClosed_Click()
If (OptOpen.Value = True) Then
OptOpen.Value = False
Else
OptClosed = True
End If
End Sub

Private Sub OptOpen_Click()
If (OptClosed.Value = True) Then
    OptClosed.Value = False
Else
    OptOpen.Value = True
End If

End Sub
