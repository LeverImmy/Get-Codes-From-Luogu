@echo off
set txtfile=%1
>%txtfile% mshta vbscript:CreateObject("Scripting.FileSystemObject").GetStandardStream(1).Write(clipboardData.getData("text"))(close)
