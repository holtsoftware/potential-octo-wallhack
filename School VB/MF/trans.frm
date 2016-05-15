VERSION 5.00
Object = "{5E9E78A0-531B-11CF-91F6-C2863C385E30}#1.0#0"; "Msflxgrd.ocx"
Begin VB.Form trans 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Transactions"
   ClientHeight    =   5040
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8505
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   5040
   ScaleWidth      =   8505
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CmdClose 
      Caption         =   "&Close"
      Height          =   375
      Left            =   3720
      TabIndex        =   4
      Top             =   4560
      Width           =   1215
   End
   Begin MSFlexGridLib.MSFlexGrid MSFlexGrid2 
      Height          =   1935
      Left            =   120
      TabIndex        =   1
      Top             =   2520
      Width           =   8295
      _ExtentX        =   14631
      _ExtentY        =   3413
      _Version        =   393216
      Cols            =   4
   End
   Begin MSFlexGridLib.MSFlexGrid MSFlexGrid1 
      Height          =   1935
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   8295
      _ExtentX        =   14631
      _ExtentY        =   3413
      _Version        =   393216
      Cols            =   6
   End
   Begin VB.Label Label2 
      Caption         =   "Account Current Holdings"
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   2280
      Width           =   2175
   End
   Begin VB.Label Label1 
      Caption         =   "Transactions"
      Height          =   495
      Left            =   120
      TabIndex        =   2
      Top             =   0
      Width           =   1215
   End
End
Attribute VB_Name = "trans"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

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

Private Sub Form_Load()
Call connect
Set Rds = cnn.Execute("select f.Fund_ID, ft.TTN ,f.PricePerShare, f.ShareAmount " _
                      & ", f.GrossAmount, f.TradeDate from FUNDTRANS f inner join" _
                      & " FTT ft on f.FTTC = FT.TT where f.AccountN = " & _
                      accountinfo.account)
Dim traderow
traderow = 0
With MSFlexGrid1
    .Clear
    .Rows = 1
    .Cols = 6
    .Row = traderow
    .ColWidth(0) = 1500
    .Col = 0
    .Text = "Fund ID"
    .ColWidth(1) = 1500
    .Col = 1
    .Text = "Transaction Type"
    .ColWidth(2) = 1500
    .Col = 2
    .Text = "Price Per Share"
    .ColWidth(3) = 1500
    .Col = 3
    .Text = "Share Amount"
    .ColWidth(4) = 1500
    .Col = 4
    .Text = "Gross Amount"
    .ColWidth(5) = 1500
    .Col = 5
    .Text = "Trade Date"
End With

If Not (Rds.EOF And Rds.BOF) Then
    With MSFlexGrid1
        Do While Not Rds.EOF
        .Rows = .Rows + 1
        traderow = traderow + 1
        .Row = traderow
        .Col = 0
        .Text = Rds(0)
        .Col = 1
        .Text = Rds(1)
        .Col = 2
        .Text = Rds(2)
        .Col = 3
        .Text = Rds(3)
        .Col = 4
        .Text = Rds(4)
        .Col = 5
        .Text = Rds(5)
        Rds.MoveNext
        Loop
    End With
End If

Dim holdingrow
holdingrow = 0
With MSFlexGrid2
    .Clear
    .Rows = 1
    .Cols = 4
    .Row = holdingrow
    .ColWidth(0) = 1500
    .Col = 0
    .Text = "Account Number"
    .ColWidth(1) = 1500
    .Col = 1
    .Text = "Fund ID"
    .ColWidth(2) = 1500
    .Col = 2
    .Text = "Last change Date"
    .ColWidth(3) = 1500
    .Col = 3
    .Text = "Total Shares"
End With

Set Rds = cnn.Execute("select * from ACH where AccountN= " & accountinfo.account)
If Not (Rds.EOF And Rds.BOF) Then
    With MSFlexGrid2
    Do While Not Rds.EOF
        .Rows = .Rows + 1
        holdingrow = holdingrow + 1
        .Row = holdingrow
        .Col = 0
        .Text = Rds(0)
        .Col = 1
        .Text = Rds(1)
        .Col = 2
        .Text = Rds(2)
        .Col = 3
        .Text = Rds(3)
        Rds.MoveNext
    Loop
    End With
End If

Set Rds = Nothing
cnn.Close
End Sub

Private Sub Form_Unload(Cancel As Integer)
accountinfo.Enabled = True
End Sub
