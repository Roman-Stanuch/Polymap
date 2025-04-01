@echo off

if not exist "../build/windows" mkdir "../build/windows"
if not exist "../build/windows/lib" mkdir "../build/windows/lib"

set "outdir=../build/windows"
set "src=../src"
set "srcfiles=%src%/main.c"

gcc %srcfiles% -o %outdir%/app.exe -L ../lib -I ../include -lraylib -Wall
xcopy ..\lib\raylib.dll %outdir%/lib /d > nul
