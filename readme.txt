
*# BitQuest: Explorador de Matrices con C y NASM

**Proyecto Final - Lenguaje Ensamblador**

##  Descripción General
**BitQuest** es un videojuego de consola desarrollado mediante programación híbrida utilizando **C y Ensamblador (NASM) de 64 bits**. El objetivo del juego es controlar a un personaje ('P') para explorar un laberinto, recolectar monedas ('M'), encontrar la llave ('K') para abrir la puerta ('D') y llegar a la salida ('E').

El proyecto cumple al 100% con los requerimientos de la rúbrica oficial, incluyendo el manejo de matrices de 60x60 con una ventana visible (cámara) de 20x20, llamadas a funciones en NASM desde C, cálculo de puntaje y reportes por nivel.

---

##  Características y Puntos Extra Implementados
Además de los requisitos mínimos, esta versión incluye las siguientes mejoras (Puntos Extra):
- **Menú interactivo de Dificultad** (Fácil, Normal, Difícil con límite de pasos).
- **Selección de Nivel Inicial**.
- **5 Niveles funcionales** (2 más de los requeridos).
- **Uso de colores en consola** mediante secuencias ANSI.
- **Pantalla de inicio y pantalla de victoria** con arte ASCII.

---

## Requisitos del Sistema (Windows)
Para compilar y ejecutar este proyecto, el sistema debe contar con las siguientes herramientas configuradas en las variables de entorno (`PATH`):
- **GCC (MinGW-w64)**: Para compilar los archivos fuente en C.
- **NASM (Netwide Assembler)**: Para ensamblar el código de 64 bits.

---

##  Instrucciones de Compilación

### Opción 1: Compilación Automatizada (Recomendado)
El repositorio incluye un script de procesamiento por lotes que automatiza el ensamblado y enlazado. Solo ejecuta en la terminal o da doble clic en:
> .\build.bat

### Opción 2: Compilación Manual
Si prefieres realizar el proceso paso a paso desde la terminal:
1. Ensamblar las rutinas de NASM:
   > nasm -f win64 rutinas.asm -o rutinas.obj
2. Compilar los archivos de C y generar el ejecutable:
   > gcc main.c juego.c rutinas.obj -o BitQuest.exe

---

##  Instrucciones de Ejecución
Una vez generado el ejecutable `BitQuest.exe`, puedes iniciar el juego ejecutando el siguiente comando en la terminal:
> .\BitQuest.exe

---

## Controles del Juego
- **W** : Mover hacia Arriba
- **A** : Mover hacia la Izquierda
- **S** : Mover hacia Abajo
- **D** : Mover hacia la Derecha
- **Q** : Salir del juego

---

##  Elementos del Mapa
- `#` : Pared (No se puede atravesar).
- `.` : Camino libre.
- `P` : Jugador.
- `M` : Moneda (Suma al contador).
- `K` : Llave (Necesaria para abrir la puerta).
- `D` : Puerta (Solo se abre con la llave).
- `E` : Salida (Termina el nivel).

---

##  Funciones Obligatorias en NASM Integradas
El núcleo lógico del juego hace uso de **5 funciones implementadas estrictamente en NASM (rutinas.asm)**, las cuales reciben parámetros desde C siguiendo la convención de llamadas de Windows x64:

1. **`contar_caracteres`**: Recorre la matriz completa al inicio de cada nivel para calcular el total exacto de monedas (`M`) disponibles en el mapa.
2. **`validar_movimiento`**: Valida las coordenadas del jugador para evitar que atraviese los muros (`#`).
3. **`calcular_puntaje`**: Calcula el score final del jugador basándose en los pasos realizados, niveles completados y monedas obtenidas.
4. **`detectar_objeto`**: Analiza celdas específicas de la matriz para interactuar con la Llave (`K`), Puerta (`D`), Monedas (`M`) y Salida (`E`).
5. **`contar_celdas_libres`**: Analiza el mapa para contar los caminos transitables (`.`) y lo muestra en el resumen de cada nivel.

---
*Desarrollado para la materia de Lenguaje Ensamblador - Universidad Autónoma de Aguascalientes (UAA).*
