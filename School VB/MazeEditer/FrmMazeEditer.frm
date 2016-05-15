VERSION 5.00
Begin VB.Form FrmMazeEditer 
   Caption         =   "Form1"
   ClientHeight    =   4455
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   5640
   LinkTopic       =   "Form1"
   ScaleHeight     =   4455
   ScaleWidth      =   5640
   StartUpPosition =   3  'Windows Default
   Begin VB.Image Image1 
      BorderStyle     =   1  'Fixed Single
      Height          =   495
      Left            =   2280
      OLEDragMode     =   1  'Automatic
      Top             =   2040
      Width           =   1215
   End
End
Attribute VB_Name = "FrmMazeEditer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_DragDrop(Source As Control, X As Single, Y As Single)
Source.Move X, Y
End Sub

Private Sub Image1_OLEDragDrop(Data As DataObject, Effect As Long, Button As Integer, Shift As Integer, X As Single, Y As Single)
Image1.Picture = Data.GetData
End Sub
