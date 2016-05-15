VERSION 5.00
Begin VB.Form main 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Mutual Fund Database"
   ClientHeight    =   1680
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   3825
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1680
   ScaleWidth      =   3825
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton CmdExit 
      Caption         =   "E&xit"
      Height          =   375
      Left            =   1320
      TabIndex        =   4
      Top             =   1200
      Width           =   1215
   End
   Begin VB.CommandButton CmdIF 
      Caption         =   "&Insert Fund"
      Height          =   375
      Left            =   2040
      TabIndex        =   3
      Top             =   240
      Width           =   1695
   End
   Begin VB.CommandButton CmdUSP 
      Caption         =   "&Update Share Price"
      Height          =   375
      Left            =   2040
      TabIndex        =   2
      Top             =   720
      Width           =   1695
   End
   Begin VB.CommandButton CmdInfo 
      Caption         =   "&Account Info"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   720
      Width           =   1695
   End
   Begin VB.CommandButton CmdNA 
      Caption         =   "&New Account"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   240
      Width           =   1695
   End
End
Attribute VB_Name = "main"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub CmdExit_Click()
End
End Sub

Private Sub CmdIF_Click()
InsertFund.Show
End Sub

Private Sub CmdInfo_Click()
accountinfo.Show
End Sub

Private Sub CmdNA_Click()
new_account.Show
End Sub

Private Sub CmdUSP_Click()
USP.Show
End Sub
