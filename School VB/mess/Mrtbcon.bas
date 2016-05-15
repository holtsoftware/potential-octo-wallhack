Attribute VB_Name = "Mrtbcon"
Option Explicit

Public Function add_rt(RTBtext As String, toadd As String) As String
Dim headerr As String
headerr = Left(RTBtext, Len(RTBtext) - 3)
add_rt = headerr + toadd + "}"
End Function

Public Function remove_return(data As String) As String
Dim toreturn As String
Dim pos As Integer
pos = InStr(1, data, ":")
data = Replace(data, Left(data, pos), "")
remove_return = data
End Function

Public Function removeToC(data As String) As String
Dim toreturn As String
Dim pos As Integer
pos = InStr(1, data, ":")
data = Replace(data, Left(data, pos), "")
removeToC = data
End Function

Public Function get_first(data As String) As String
Dim toreturn As String
Dim pos As Integer
pos = InStr(1, data, ":")
If pos <> 0 Then
toreturn = Left(data, pos - 1)
End If
get_first = toreturn
End Function



