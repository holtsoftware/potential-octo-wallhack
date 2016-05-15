VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "AppSettings"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Private data() As String
Private length As Integer
Private loaded As Boolean
Private wasdone As Boolean

Public Function isloaded() As Boolean
isloaded = loaded
End Function

Public Function add(toadd As String)
If loaded And Not wasdone Then
    ReDim data(0)
    length = 0
    wasdone = True
End If
ReDim Preserve data(length + 1)
length = length + 1
data(length - 1) = toadd
End Function

Public Function getitem(index As Integer) As String
If (index < length) Then
    getitem = data(index)
Else
    MsgBox "Index Out Of Bound!!!" & vbCrLf & "Index " & Str(index), , "Index Out Of Bound!!!"
End If
End Function

Public Function save(file As String)
Open file For Output As #1
Write #1, length
For i = 0 To length
    Write #1, data(i)
Next i
Close #1
End Function

Public Function load(file As String) As Boolean
Dim tempdata As String
On Error GoTo AppSettings_load
Open file For Input As #1
If Not EOF(1) Then
Input #1, tempdata
length = Val(tempdata)
ReDim data(length)
For i = 0 To length
    Input #1, tempdata
    data(i) = tempdata
Next i
load = True
loaded = True
Else
load = False
loaded = False
wasdone = False
End If
Close #1
Exit Function
AppSettings_load:
loaded = False
Exit Function
End Function
