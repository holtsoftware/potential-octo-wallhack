VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form ServerFrm 
   Caption         =   "Form1"
   ClientHeight    =   4350
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5880
   LinkTopic       =   "Form1"
   ScaleHeight     =   4350
   ScaleWidth      =   5880
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox TxtPort 
      Height          =   405
      Left            =   4200
      TabIndex        =   5
      Top             =   2760
      Width           =   1575
   End
   Begin VB.ListBox lstIP 
      Height          =   1620
      Left            =   3000
      TabIndex        =   4
      Top             =   240
      Width           =   2895
   End
   Begin VB.ListBox lstUC 
      Height          =   1620
      Left            =   0
      TabIndex        =   3
      Top             =   240
      Width           =   2895
   End
   Begin MSWinsockLib.Winsock WSCON 
      Left            =   1320
      Top             =   2760
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      Protocol        =   1
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Command1"
      Height          =   495
      Left            =   120
      TabIndex        =   0
      Top             =   3720
      Width           =   1215
   End
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   495
      Left            =   4200
      Top             =   3720
      Visible         =   0   'False
      Width           =   1575
      _ExtentX        =   2778
      _ExtentY        =   873
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
      Connect         =   "DSN=MDB"
      OLEDBString     =   ""
      OLEDBFile       =   ""
      DataSourceName  =   "MDB"
      OtherAttributes =   ""
      UserName        =   "dba"
      Password        =   "dba"
      RecordSource    =   ""
      Caption         =   ""
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
   Begin MSWinsockLib.Winsock WSCon2 
      Left            =   2400
      Top             =   2880
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      Protocol        =   1
      RemotePort      =   745
   End
   Begin VB.Label Label4 
      Caption         =   "Users IP Address"
      Height          =   255
      Left            =   3000
      TabIndex        =   7
      Top             =   0
      Width           =   2775
   End
   Begin VB.Label Label3 
      Caption         =   "Users Connected"
      Height          =   255
      Left            =   0
      TabIndex        =   6
      Top             =   0
      Width           =   2895
   End
   Begin VB.Label Label2 
      Caption         =   "Label2"
      Height          =   495
      Left            =   2880
      TabIndex        =   2
      Top             =   3600
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Label1"
      Height          =   495
      Left            =   1560
      TabIndex        =   1
      Top             =   3600
      Width           =   1215
   End
End
Attribute VB_Name = "ServerFrm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim accountchenck As New CAccount
Public Function CFSC(command As String, data As String)
Select Case command
Case "LogOn"
    Dim ip As String
    Dim un As String
    Dim pass As String
    ip = get_first(data)
    data = removeToC(data)
    un = get_first(data)
    data = removeToC(data)
    pass = get_first(data)
    If accountchenck.LogOnSucced(un, pass) Then
        lstUC.AddItem un
        lstIP.AddItem ip
        'If WSCon2.State = sckOpen Then
        '    WSCon2.Close
        'End If
        WSCon2.RemoteHost = ip
        WSCon2.RemotePort = 745
        WSCon2.SendData ("LogedIn:")
    End If
Case "REED"
    For i = 0 To lstIP.ListCount
        WSCON.RemoteHost = lstIP.List(i)
        WSCON.RemotePort = 745
        WSCON.SendData "REED:" + data
    Next i
End Select
End Function

Private Sub Command1_Click()
accountchenck.connecttodatabase
End Sub


Private Sub Form_Load()
WSCON.Bind 745, "192.168.0.1"
End Sub

Private Sub WSCON_DataArrival(ByVal bytesTotal As Long)
Dim data As String
Dim command As String
WSCON.GetData data
command = get_first(data)
data = removeToC(data)
CFSC command, data
End Sub

Private Sub WSCON_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
MsgBox (Description)
End Sub



