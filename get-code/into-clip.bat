@echo off
set txtfile=%1
mshta vbscript:clipboarddata.setdata("text",%txtfile%)(close)
