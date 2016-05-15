VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Object = "{3B7C8863-D78F-101B-B9B5-04021C009402}#1.2#0"; "Richtx32.ocx"
Begin VB.UserControl messanger 
   ClientHeight    =   3930
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   4485
   MaskPicture     =   "messanger.ctx":0000
   ScaleHeight     =   3930
   ScaleWidth      =   4485
   Begin VB.TextBox TxtSend 
      Height          =   375
      Left            =   120
      TabIndex        =   4
      Tag             =   "0"
      Top             =   3360
      Width           =   2895
   End
   Begin VB.CommandButton CmdSend 
      Caption         =   "&Send"
      Height          =   375
      Left            =   3120
      TabIndex        =   3
      Tag             =   "4"
      Top             =   3360
      Width           =   1215
   End
   Begin VB.TextBox TxtRC 
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Tag             =   "1"
      Text            =   "A1"
      Top             =   360
      Width           =   2055
   End
   Begin VB.TextBox TxtPort 
      Height          =   375
      Left            =   2280
      TabIndex        =   1
      Tag             =   "2"
      Text            =   "745"
      Top             =   360
      Width           =   2055
   End
   Begin RichTextLib.RichTextBox RTB 
      Height          =   2415
      Left            =   120
      TabIndex        =   0
      Top             =   840
      Width           =   4215
      _ExtentX        =   7435
      _ExtentY        =   4260
      _Version        =   393217
      ReadOnly        =   -1  'True
      TextRTF         =   $"messanger.ctx":030A
   End
   Begin MSWinsockLib.Winsock WSCON 
      Left            =   720
      Top             =   3960
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
      Protocol        =   1
   End
   Begin VB.Label l1 
      Caption         =   "Remote Computer"
      Height          =   375
      Left            =   120
      TabIndex        =   7
      Top             =   120
      Width           =   1455
   End
   Begin VB.Label l2 
      Caption         =   "Port"
      Height          =   375
      Left            =   2280
      TabIndex        =   6
      Top             =   120
      Width           =   1575
   End
   Begin VB.Label l3 
      Caption         =   "Server Name or IP"
      Height          =   375
      Left            =   120
      TabIndex        =   5
      Top             =   3120
      Visible         =   0   'False
      Width           =   2895
   End
End
Attribute VB_Name = "messanger"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True

Option Explicit

Function Check_four_commands()

End Function

Function remove_return(data As String) As String
Dim toreturn As String
Dim pos As Integer
pos = InStr(1, data, ":")
toreturn = Left(data, pos)
data = Replace(data, Left(data, pos), "")
remove_return = data
End Function

Private Sub CmdSend_Click()
Dim name As String
name = TxtRC.Text

On Error GoTo CmdSend_Click
If (CmdSend.Caption = "&Send") Then
WSCON.RemoteHost = name
WSCON.RemotePort = (Val(TxtPort.Text))
WSCON.SendData (WSCON.LocalIP + ":\b " + WSCON.LocalHostName + ": \b0 " + TxtSend.Text)

RTB.TextRTF = add_rt(RTB.TextRTF, "\b " + WSCON.LocalHostName + ": \b0 " + TxtSend.Text + "\par")

TxtSend.SelStart = 0
TxtSend.SelLength = Len(TxtSend.Text)
Else

End If
Exit Sub
CmdSend_Click:
MsgBox "The Computer " + TxtRC.Text + " dosn't exist or rejected the connection be shure that the port on the remote computer is using the same port that you are.", , "Remote Computer"
Exit Sub
End Sub




Private Sub TxtSend_DblClick()
CmdSend_Click
End Sub


Private Sub TxtSend_KeyPress(KeyAscii As Integer)
If KeyAscii = 13 Then
CmdSend_Click
End If
End Sub

Private Sub TxtSend_Validate(Cancel As Boolean)
CmdSend_Click
End Sub

Public Sub UserControl_Initialize()
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



Private Sub WSCON_DataArrival(ByVal bytesTotal As Long)
Dim data As String
Dim pos As Integer
On Error Resume Next
WSCON.GetData data
data = remove_return(data)
RTB.TextRTF = add_rt(RTB.TextRTF, data)
End Sub

Private Sub WSCON_Error(ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
MsgBox (Description)
End Sub

