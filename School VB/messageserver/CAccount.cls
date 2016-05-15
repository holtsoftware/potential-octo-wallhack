VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "CAccount"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit
Public cnn As New ADODB.Connection
Public Rds As New ADODB.Recordset


Public Function connecttodatabase()
'On Error Resume Next
    Set cnn = New ADODB.Connection
    cnn.Provider = "MSDASQL"
    cnn.ConnectionString = "Provider=MSDASQL.1;" & _
                           "Persist Security Info=True;" & _
                           "User ID=dba;" & _
                           "Password=dba;" & _
                           "Data Source=MDB"
    cnn.Open
End Function

Public Function LogOnSucced(un As String, pass As String) As Boolean
    Dim num As String
    Dim npass As String
    connecttodatabase
    Set Rds = cnn.Execute("SELECT TOP 1 * From AccInfo WHERE Account = '" & un & "'")
    If Rds.BOF And Rds.EOF Then
    Else
        num = RTrim(Rds(0))
        npass = RTrim(Rds(1))
        If num = un And npass = pass Then
        LogOnSucced = True
        Else
            LogOnSucced = False
        End If
    End If
End Function
