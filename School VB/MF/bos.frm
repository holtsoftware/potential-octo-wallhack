VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Begin VB.Form bos 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "By Or Sell Fund"
   ClientHeight    =   3615
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3960
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3615
   ScaleWidth      =   3960
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Cmdclose 
      Caption         =   "&Close"
      Height          =   375
      Left            =   2280
      TabIndex        =   12
      Top             =   3120
      Width           =   1215
   End
   Begin VB.CommandButton CmdS 
      Caption         =   "Su&bmit"
      Height          =   375
      Left            =   600
      TabIndex        =   11
      Top             =   3120
      Width           =   1215
   End
   Begin VB.OptionButton OptMS 
      Caption         =   "Mail Sell"
      Height          =   255
      Left            =   2160
      TabIndex        =   7
      Top             =   1920
      Width           =   1215
   End
   Begin VB.OptionButton OptTS 
      Caption         =   "Telephone Sell"
      Height          =   255
      Left            =   2160
      TabIndex        =   6
      Top             =   1440
      Width           =   1455
   End
   Begin VB.OptionButton OptMB 
      Caption         =   "Mail Buy"
      Height          =   255
      Left            =   240
      TabIndex        =   5
      Top             =   1920
      Width           =   1215
   End
   Begin VB.OptionButton OptTB 
      Caption         =   "Telephone Buy"
      Height          =   255
      Left            =   240
      TabIndex        =   4
      Top             =   1440
      Value           =   -1  'True
      Width           =   1575
   End
   Begin VB.Frame Frame1 
      Caption         =   "Buy/Sell Options"
      Height          =   1335
      Left            =   120
      TabIndex        =   10
      Top             =   1080
      Width           =   3735
   End
   Begin MSAdodcLib.Adodc Adodc1 
      Height          =   735
      Left            =   4920
      Top             =   2040
      Visible         =   0   'False
      Width           =   1455
      _ExtentX        =   2566
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
      UserName        =   ""
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
   Begin VB.TextBox TxtGA 
      Height          =   375
      Left            =   1560
      TabIndex        =   9
      Top             =   2520
      Width           =   2175
   End
   Begin VB.ComboBox CmbFN 
      Height          =   315
      Left            =   1560
      TabIndex        =   3
      Top             =   600
      Width           =   2175
   End
   Begin VB.Label Label4 
      Caption         =   "Gross Amount:"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      Top             =   2640
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Fund Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   600
      Width           =   1695
   End
   Begin VB.Label lblan 
      Caption         =   "1"
      Height          =   255
      Left            =   1560
      TabIndex        =   1
      Top             =   120
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Account Number:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   120
      Width           =   1575
   End
End
Attribute VB_Name = "bos"
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

Private Sub Cmdclose_Click()
Unload Me
End Sub

Private Sub CmdS_Click()
Dim fundid As String
Dim tc As Integer
Dim pps, sa, ts
Call connect
Set Rds = cnn.Execute("select Fund_ID from FUNDINFO where Fund_name ='" & CmbFN.Text & "'")
fundid = Rds(0)
If (OptTB.Value = True) Then
tc = 1
ElseIf (OptMB.Value = True) Then
tc = 2
ElseIf (OptTS.Value = True) Then
tc = 3
Else
tc = 4
End If

Set Rds = cnn.Execute("select PricePerShare from DFI where InfoDate = '" & DateTime.Date & _
                    "' and Fund_ID = " & fundid)
If (Rds.BOF And Rds.EOF) Then
    MsgBox "The Fund Daily Info is not updated yet"
Else
    pps = Rds(0)
    sa = Round(TxtGA.Text / pps, 3)
    cnn.Execute ("insert into FUNDTRANS values(" & tc & "," & lblan.Caption & _
                "," & fundid & "," & pps & "," & sa & "," & TxtGA.Text & ",'" _
                & DateTime.Date & "')")
    Set Rds = cnn.Execute("select TotalShares from ACH " & _
                          "where AccountN= " & lblan.Caption & " and Fund_ID = " _
                          & fundid)
    If (tc = 3 Or tc = 4) Then
        sa = sa * (-1)
    End If
    
    If Rds.EOF And Rds.BOF Then
        ts = sa
        cnn.Execute ("insert into ACH Values (" & _
                    lblan.Caption & "," & _
                    fundid & ",'" & _
                    DateTime.Date & _
                    "'," & ts & ")")
    Else
        ts = Rds(0) + sa
        cnn.Execute ("update ACH set TotalShares = " & ts & ", " & _
                    "Date = '" & DateTime.Date & "' where AccountN = " & _
                    lblan.Caption & " and Fund_ID = " & fundid)
    End If
    MsgBox "Submited"
End If
Set Rds = Nothing
cnn.Close
End Sub

Private Sub Form_Load()
Call connect
Set Rds = cnn.Execute("select Fund_name from FUNDINFO")
If Not (Rds.EOF And Rds.BOF) Then
    CmbFN.Text = RTrim(Rds(0))
    Do While Not Rds.EOF
        CmbFN.AddItem RTrim(Rds(0))
        Rds.MoveNext
    Loop
End If
Set Rds = Nothing
cnn.Close
End Sub

Private Sub Form_Unload(Cancel As Integer)
accountinfo.Enabled = True
End Sub
