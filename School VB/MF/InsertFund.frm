VERSION 5.00
Object = "{67397AA1-7FB1-11D0-B148-00A0C922E820}#6.0#0"; "MSADODC.OCX"
Object = "{CDE57A40-8B86-11D0-B3C6-00A0C90AEA82}#1.0#0"; "MSDATGRD.OCX"
Begin VB.Form InsertFund 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Insert Fund"
   ClientHeight    =   5040
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   6720
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5040
   ScaleWidth      =   6720
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox TxtMII 
      Height          =   375
      Left            =   1800
      TabIndex        =   12
      Top             =   2160
      Width           =   3855
   End
   Begin MSDataGridLib.DataGrid DataGrid1 
      Bindings        =   "InsertFund.frx":0000
      Height          =   2055
      Left            =   120
      TabIndex        =   10
      Top             =   2880
      Width           =   6495
      _ExtentX        =   11456
      _ExtentY        =   3625
      _Version        =   393216
      HeadLines       =   1
      RowHeight       =   15
      FormatLocked    =   -1  'True
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
      ColumnCount     =   5
      BeginProperty Column00 
         DataField       =   "Fund_ID"
         Caption         =   "Fund_ID"
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
         DataField       =   "Fund_name"
         Caption         =   "Fund_name"
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
      BeginProperty Column02 
         DataField       =   "Ticker"
         Caption         =   "Ticker"
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
      BeginProperty Column03 
         DataField       =   "IDate"
         Caption         =   "IDate"
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
      BeginProperty Column04 
         DataField       =   "MII"
         Caption         =   "MII"
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
            ColumnWidth     =   915.024
         EndProperty
         BeginProperty Column01 
            ColumnWidth     =   1739.906
         EndProperty
         BeginProperty Column02 
            ColumnWidth     =   915.024
         EndProperty
         BeginProperty Column03 
            ColumnWidth     =   1140.095
         EndProperty
         BeginProperty Column04 
            ColumnWidth     =   1140.095
         EndProperty
      EndProperty
   End
   Begin MSAdodcLib.Adodc connection 
      Height          =   735
      Left            =   7200
      Top             =   2400
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
      CommandType     =   2
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
      RecordSource    =   "FUNDINFO"
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
   Begin VB.CommandButton Command2 
      Caption         =   "&Close"
      Height          =   375
      Left            =   5400
      TabIndex        =   9
      Top             =   240
      Width           =   1215
   End
   Begin VB.CommandButton CmdInsert 
      Caption         =   "&Insert"
      Default         =   -1  'True
      Height          =   375
      Left            =   3720
      TabIndex        =   8
      Top             =   240
      Width           =   1215
   End
   Begin VB.TextBox TxtID 
      Height          =   375
      Left            =   1800
      TabIndex        =   7
      Top             =   1680
      Width           =   3855
   End
   Begin VB.TextBox TxtTicker 
      Height          =   375
      Left            =   1800
      MaxLength       =   8
      TabIndex        =   5
      Top             =   1200
      Width           =   3855
   End
   Begin VB.TextBox TxtFN 
      Height          =   375
      Left            =   1800
      MaxLength       =   25
      TabIndex        =   3
      Top             =   720
      Width           =   3855
   End
   Begin VB.TextBox TxtFID 
      Height          =   375
      Left            =   1800
      Locked          =   -1  'True
      TabIndex        =   1
      Top             =   240
      Width           =   1455
   End
   Begin VB.Label Label5 
      Caption         =   "Min Initial Investment:"
      Height          =   255
      Left            =   120
      TabIndex        =   11
      Top             =   2280
      Width           =   1575
   End
   Begin VB.Label Label4 
      Caption         =   "Inception Date:"
      Height          =   255
      Left            =   120
      TabIndex        =   6
      Top             =   1800
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "NASDAQ Ticker:"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   1320
      Width           =   1215
   End
   Begin VB.Label Label2 
      Caption         =   "Fund Name:"
      Height          =   255
      Left            =   120
      TabIndex        =   2
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "Fund ID:"
      Height          =   255
      Left            =   120
      TabIndex        =   0
      Top             =   360
      Width           =   1215
   End
End
Attribute VB_Name = "InsertFund"
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

Private Sub CmdInsert_Click()
If (Len(TxtFN.Text) <= 0) Then
    MsgBox "You must enter a Fund Name"
    Exit Sub
End If
If (Val(TxtTicker.Text) <= 0) Then
    MsgBox "You must enter a valid NASDAQ ticker"
    Exit Sub
End If
If (Len(TxtID.Text) <= 0) Then
    TxtID.Text = DateTime.Date
End If
If (Len(TxtMII.Text) <= 0) Then
    TxtMII.Text = 0
End If
Call connect
Set Rds = cnn.Execute("select max(Fund_ID) from FUNDINFO")
If (Rds.EOF And Rds.BOF Or IsNull(Rds(0))) Then
    TxtFID.Text = 1
Else
    TxtFID.Text = Rds(0) + 1
End If
cnn.Execute ("insert into FUNDINFO values(" & _
                TxtFID.Text & ",'" & _
                TxtFN.Text & "'," & _
                TxtTicker.Text & ",'" & _
                TxtID.Text & "','" & _
                TxtMII.Text & "')")
cnn.Close
Unload Me
Me.Show
End Sub

Private Sub Command2_Click()
Unload Me
End Sub

Private Sub Form_Load()
main.Enabled = False
End Sub

Private Sub Form_Unload(Cancel As Integer)
main.Enabled = True
End Sub
