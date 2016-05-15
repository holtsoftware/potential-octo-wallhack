VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "Richtx32.ocx"
Begin VB.Form ServerFRM 
   Caption         =   "Home Messanger"
   ClientHeight    =   3750
   ClientLeft      =   4200
   ClientTop       =   2970
   ClientWidth     =   4440
   Icon            =   "ServerFRM.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   3750
   ScaleWidth      =   4440
   Begin RichTextLib.RichTextBox RTB 
      Height          =   2415
      Left            =   120
      TabIndex        =   6
      Top             =   720
      Width           =   4215
      _ExtentX        =   7435
      _ExtentY        =   4260
      _Version        =   393217
      ScrollBars      =   3
      TextRTF         =   $"ServerFRM.frx":030A
   End
   Begin VB.TextBox TxtPort 
      Height          =   375
      Left            =   2280
      TabIndex        =   3
      Tag             =   "2"
      Top             =   240
      Width           =   2055
   End
   Begin VB.TextBox TxtRC 
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Tag             =   "1"
      Top             =   240
      Width           =   2055
   End
   Begin VB.CommandButton CmdSend 
      Caption         =   "&Send"
      Default         =   -1  'True
      Height          =   375
      Left            =   3120
      TabIndex        =   1
      Tag             =   "4"
      Top             =   3240
      Width           =   1215
   End
   Begin VB.TextBox TxtSend 
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Tag             =   "0"
      Top             =   3240
      Width           =   2895
   End
   Begin MSWinsockLib.Winsock WSCON 
      Left            =   3600
      Top             =   4440
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      Protocol        =   1
   End
   Begin VB.Label l3 
      Caption         =   "Server Name or IP"
      Height          =   375
      Left            =   120
      TabIndex        =   7
      Top             =   3000
      Visible         =   0   'False
      Width           =   2895
   End
   Begin VB.Label l2 
      Caption         =   "Port"
      Height          =   375
      Left            =   2280
      TabIndex        =   5
      Top             =   0
      Width           =   1575
   End
   Begin VB.Label l1 
      Caption         =   "Remote Computer"
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Top             =   0
      Width           =   1455
   End
   Begin VB.Menu mnuFile 
      Caption         =   "&File"
      Begin VB.Menu mnuFileLogOut 
         Caption         =   "Log &Out"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileSeparator 
         Caption         =   "-"
         Visible         =   0   'False
      End
      Begin VB.Menu mnuFileSave 
         Caption         =   "&Save"
      End
      Begin VB.Menu mnuFileSep1 
         Caption         =   "-"
      End
      Begin VB.Menu mnuFileExit 
         Caption         =   "E&xit"
      End
   End
   Begin VB.Menu mnuTools 
      Caption         =   "Tools"
      Begin VB.Menu mnuToolsServiceType 
         Caption         =   "Service Type"
         Begin VB.Menu mnuToolsServiceTypeServer 
            Caption         =   "Server"
            Enabled         =   0   'False
         End
         Begin VB.Menu mnuToolsServiceTypePeerToPeer 
            Caption         =   "Peer To Peer"
            Checked         =   -1  'True
         End
      End
      Begin VB.Menu mnuToolsSettings 
         Caption         =   "Settings"
      End
   End
End
Attribute VB_Name = "ServerFRM"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Public ServerPort As Integer
Dim dsetts As New AppSettings
Dim RemoteHost As String
Dim RemotePort As String

Public Function CFCC(command As String, data As String)
Select Case command
Case "REED"
    data = removeToC(data)
    RTB.TextRTF = add_rt(RTB.TextRTF, data)
Case "/quit"
    End
Case "LogedIn"
    CmdSend.Caption = "&Send"
    mnuFileLogOut.Visible = True
    RTB.Visible = True
    TxtPort.Enabled = False
    l3.Visible = False
    CmdSend.Caption = "&Send"
    TxtRC.Enabled = False
Case "/beep"
    Beep
End Select
If (InStr(1, data, "/beep")) Then
    Beep
End If
If (InStr(1, data, "\quit") > 0) Then
    End
End If
End Function


Private Sub CmdSend_Click()
Dim name As String
name = TxtRC.Text

On Error GoTo CmdSend_Click
Dim data As String
If (CmdSend.Caption = "&Send") Then

WSCON.RemoteHost = RemoteHost
WSCON.RemotePort = (Val(RemotePort))
data = "REED" + ":" + WSCON.LocalIP + ":\b " + WSCON.LocalHostName + ": \b0 " + TxtSend.Text
WSCON.SendData (data)
CFCC TxtSend.Text, ""
If mnuFileLogOut.Visible = False Then
    RTB.TextRTF = add_rt(RTB.TextRTF, "\b " + WSCON.LocalHostName + ": \b0 " + TxtSend.Text + "\par")
End If

TxtSend.SelStart = 0
TxtSend.SelLength = Len(TxtSend.Text)
Else
WSCON.RemoteHost = TxtSend.Text
WSCON.RemotePort = ServerPort
data = "LogOn:" + WSCON.LocalIP + ":" + TxtRC.Text + ":" + TxtPort.Text + ":"
WSCON.SendData (data)
End If
Exit Sub
CmdSend_Click:
MsgBox "The Computer " + TxtRC.Text + " dosn't exist or rejected the connection be shure that the port on the remote computer is using the same port that you are.", , "Remote Computer"
Exit Sub
End Sub


Private Sub Form_Load()
Set dsetts = New AppSettings
If (dsetts.load("MessangerSettings.ini")) Then
    TxtRC.Text = dsetts.getitem(0)
    TxtPort.Text = dsetts.getitem(1)
End If
ServerPort = 745
RemotePort = TxtPort.Text
RemoteHost = TxtRC.Text
RTB.TextRTF = ""
On Error GoTo Form_Load_error
   WSCON.Bind (Val(TxtPort.Text))
Exit Sub
Form_Load_error:
    MsgBox "Port " + Str(Val(TxtPort.Text)) + " is allready being used!" + vbCrLf + _
    "Please select anther port.", vbOKOnly, "Port being used."
    CmdSend.Enabled = False
Exit Sub
End Sub

Private Sub mnuFileExit_Click()
End
End Sub

Private Sub mnuFileSave_Click()
RTB.SaveFile ("test.txt")
End Sub

Private Sub mnuToolsServiceTypePeerToPeer_Click()
If (mnuToolsServiceTypePeerToPeer.Checked = False) Then
If (dsetts.isloaded()) Then
    TxtRC.Text = dsetts.getitem(0)
    TxtPort.Text = dsetts.getitem(1)
End If
mnuToolsServiceTypeServer.Checked = False
mnuToolsServiceTypePeerToPeer.Checked = True
l1.Caption = "Remote Computer"
l2.Caption = "Port"
TxtPort.PasswordChar = ""
RTB.Visible = True
l3.Visible = False
CmdSend.Caption = "&Send"
TxtPort.Text = "745"
TxtSend.Text = ""
End If
End Sub

Private Sub mnuToolsServiceTypeServer_Click()
If (mnuToolsServiceTypeServer.Checked = False) Then

mnuToolsServiceTypeServer.Checked = True
mnuToolsServiceTypePeerToPeer.Checked = False
l1.Caption = "User Name"
l2.Caption = "Password"
TxtPort.PasswordChar = "*"
RTB.Visible = False
l3.Visible = True
CmdSend.Caption = "&Connect"
TxtRC.Text = ""
TxtPort.Text = ""
If WSCON.State = sckOpen Then
    WSCON.Close
End If
If (dsetts.isloaded()) Then
    TxtRC.Text = dsetts.getitem(3)
    TxtSend.Text = dsetts.getitem(2)
End If
WSCON.Bind ServerPort
End If
End Sub

Private Sub mnuToolsSettings_Click()
FrmSettings.Show
Me.Enabled = False
End Sub

Private Sub RTB_Change()
Dim tree
RTB.SelStart = Len(RTB.TextRTF)
End Sub

Private Sub TxtPort_LostFocus()
If (WSCON.State = sckOpen) Then
    WSCON.Close
End If

On Error GoTo TxtPort_LostFocus_error
WSCON.Bind (Val(TxtPort.Text))
CmdSend.Enabled = True
Exit Sub

TxtPort_LostFocus_error:
    MsgBox "Port " + Str(Val(TxtPort.Text)) + " is allready being used!" + vbCrLf + _
    "Please select anther port.", vbOKOnly, "Port being used."
    CmdSend.Enabled = False
Exit Sub
End Sub




Private Sub TxtRC_LostFocus()
If (l1.Caption = "Remote Computer") Then
    RemoteHost = TxtRC.Text
    RemotePort = Val(TxtPort.Text)
End If
End Sub

Private Sub WSCON_DataArrival(ByVal bytesTotal As Long)
Dim data As String
Dim command As String
On Error Resume Next
WSCON.GetData data
command = get_first(data)
data = removeToC(data)
CFCC command, data
End Sub

Private Sub WSCON_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
MsgBox (Description)
End Sub
