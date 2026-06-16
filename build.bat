@echo off
title Compilador Proyecto - UAA
cls

echo ============================================================
echo      COMPILANDO RUTINAS EN ENSAMBLADOR (NASM 64-BITS)
echo ============================================================
nasm -f win64 rutinas.asm -o rutinas.obj
if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Hubo un problema al compilar rutinas.asm con NASM.
    pause
    exit /b %errorlevel%
)
echo [OK] rutinas.obj generado correctamente.
echo.

echo ============================================================
echo      COMPILANDO CODIGO EN C Y ENLAZANDO CON GCC
echo ============================================================
gcc Main.c Juego.c rutinas.obj -o Proyecto.exe -I.
if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Hubo un problema al compilar o enlazar con GCC.
    pause
    exit /b %errorlevel%
)
echo [OK] Proyecto.exe generado con exito.
echo.

echo ============================================================
echo             EJECUTANDO PROYECTO...
echo ============================================================
echo.
Proyecto.exe
pause
