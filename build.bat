@echo off
SetLocal EnableDelayedExpansion

set srcs=
for /R %%f in (*.cpp) do (
    set srcs=!srcs! %%f
)

set defines=-D GE_DEBUG -D _DEBUG
set includep=-Iinclude -Iinclude/imgui
set libp=-Llib
set libflags=-lglfw3dll -lassimp.dll -limgui -lglad -lstbi -lstbp

g++ %defines% %includep% %libp% %srcs% %libflags% -o bin/engine.exe