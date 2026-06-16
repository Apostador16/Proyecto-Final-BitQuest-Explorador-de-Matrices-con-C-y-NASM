@echo off
echo ========================================
echo Compilando BitQuest (C + NASM 64 bits)...
echo ========================================

echo 1. Ensamblando rutinas.asm...
nasm -f win64 rutinas.asm -o rutinas.obj
if %errorlevel% neq 0 (
    echo [ERROR] Fallo al ensamblar rutinas.asm
    pause
    exit /b %errorlevel%
)

echo 2. Compilando C y enlazando...
gcc Main.c Juego.c rutinas.obj -o BitQuest.exe
if %errorlevel% neq 0 (
    echo [ERROR] Fallo al compilar los archivos C
    pause
    exit /b %errorlevel%
)

echo.
echo [EXITO] Compilacion terminada. Ejecutable: BitQuest.exe
pause
