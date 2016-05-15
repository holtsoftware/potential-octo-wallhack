VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form USP 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Update Share Price"
   ClientHeight    =   3495
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   7080
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3495
   ScaleWidth      =   7080
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CmdClose 
      Caption         =   "&Close"
      Height          =   375
      Left            =   5760
      TabIndex        =   9
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CommandButton CmdSave 
      Caption         =   "&Save"
      Default         =   -1  'True
      Height          =   375
      Left            =   5760
      TabIndex        =   8
      Top             =   2160
      Width           =   1215
   End
   Begin VB.TextBox TxtNSP 
      Height          =   375
      Left            =   1440
      TabIndex        =   7
      Top             =   3000
      Width           =   1215
   End
   Begin VB.TextBox TxtID 
      Height          =   375
      Left            =   1440
      Locked          =   -1  'True
      TabIndex        =   5
      Top             =   2520
      Width           =   1215
   End
   Begin VB.ComboBox CmbFN 
      Height          =   315
      Left            =   1440
      TabIndex        =   3
      Top             =   2160
      Width           =   2175
   End
   Begin MSAdodcLib.Adodc connection 
      Height          =   615
      Left            =   7320
      Top             =   1560
      Width           =   1335
      _ExtentX        =   2355
      _ExtentY        =   1085
      ConnectMode     =   0
      CursorLocation  =   3
      IsolationLevel  =   -1
      ConnectionTimeout=   15
      CommandTimeout  =   30
      CursorType      =   3
      LockType        =   3
      CommandType     =   1
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
      RecordSource    =   $"USP.frx":0000
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
   Begin MSDataGridLib.DataGrid DataGrid1 
      Bindings        =   "USP.frx":008A
      Height          =   1575
      Left            =   120
      TabIndex        =   0
      Top             =   360
      Width           =   6855
      _ExtentX        =   12091
      _ExtentY        =   2778
      _Version        =   393216
      HeadLines       =   1
      RowHeight       =   15
      BeginProperty HeadFont {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ColumnCount     =   2
      BeginProperty Column00 
         DataField       =   ""
         Caption         =   ""
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   0
         EndProperty
      EndProperty
      BeginProperty Column01 
         DataField       =   ""
         Caption         =   ""
         BeginProperty DataFormat {6D835690-900B-11D0-9484-00A0C91110ED} 
            Type            =   0
            Format          =   ""
            HaveTrueFalseNull=   0
            FirstDayOfWeek  =   0
            FirstWeekOfYear =   0
            LCID            =   1033
            SubFormatType   =   0
         EndProperty
      EndProperty
      SplitCount      =   1
      BeginProperty Split0 
         BeginProperty Column00 
         EndProperty
         BeginProperty Column01 
         EndProperty
      EndProperty
   End
   Begin VB.Label Label4 
      Caption         =   "New Share Price:"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   3120
      Width           =   1575
   End
   Begin VB.Label Label3 
      Caption         =   "Infor Date:"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   2640
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Fund Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   2160
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Fund List"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   120
      Width           =   1215
   End
End
Attribute VB_Name = "USP"
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

Private Sub CmdSave_Click()
Dim g As String
Dim temp
If (Val(TxtNSP.Text) <= 0) Then
    MsgBox "Invalid share price"
    Exit Sub
End If
Call connect
Set Rds = cnn.Execute("select Fund_ID From FUNDINFO where Fund_name='" + CmbFN.Text + "'")
If (Rds.EOF Or Rds.BOF) Then
    MsgBox "invalid fund name"
    Exit Sub
End If
g = Str(Rds(0))
Set Rds = cnn.Execute("select InfoDate from DFI where Fund_ID=" + g)
If ((Rds.EOF And Rds.BOF)) Then
cnn.Execute ("insert into DFI values(" + g + ",'" + TxtID.Text + "'," + TxtNSP.Text + ")")
ElseIf (RTrim(Rds(0)) <> DateTime.Date) Then
cnn.Execute ("insert into DFI values(" + g + ",'" + TxtID.Text + "'," + TxtNSP.Text + ")")

Else
temp = Rds(0)
MsgBox "Fund price allready updated for today"
End If
cnn.Close
Unload Me
Me.Show
End Sub

Private Sub Form_Load()
Call connect
Set Rds = cnn.Execute("select Fund_name from FUNDINFO")
If Not (Rds.EOF And Rds.BOF) Then
    CmbFN.Text = Rds(0)
    Do While Not Rds.EOF
        CmbFN.AddItem Rds(0)
        Rds.MoveNext
    Loop
End If
Set Rds = Nothing
cnn.Close
TxtID.Text = DateTime.Date
End Sub

Private Sub Form_Unload(Cancel As Integer)
main.Enabled = True
End Sub
