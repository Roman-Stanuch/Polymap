@echo off
if not exist "./build" mkdir build
set "srcfiles=src/main.c"
gcc %srcfiles% -o build/app.exe -L ./lib -I ./include -lraylib -Wall
xcopy .\lib\raylib.dll .\build /d > nul
