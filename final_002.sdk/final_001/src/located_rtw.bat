@echo off

set MATLAB=D:\MATLAB

cd .

if "%1"=="" ("D:\MATLAB\bin\win64\gmake"  -f located_rtw.mk all) else ("D:\MATLAB\bin\win64\gmake"  -f located_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
