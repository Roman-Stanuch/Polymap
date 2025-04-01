@echo off

if not exist "../build/windows" mkdir "../build/windows"

set "outdir=../build/windows"
set "src=../src"
set "srcfiles=%src%/main.c"

gcc %srcfiles% -o %outdir%/app.exe -L ../lib/windows -I ../include -lraylib -lopengl32 -lgdi32 -lwinmm -Wall
