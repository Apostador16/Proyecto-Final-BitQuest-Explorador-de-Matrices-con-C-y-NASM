# Proyecto: Explorador de Matrices con C y NASM

**Asignatura:** Lenguaje Ensamblador  
**Plataforma:** Windows (64 bits)  
**Arquitectura:** x86-64  
**Herramientas:** GCC y NASM  

---

## Descripción del Proyecto
Este es un videojuego en consola desarrollado utilizando programación híbrida (C y Ensamblador x86-64). El juego representa un entorno de laberinto estructurado mediante mapas matriciales de $60 \times 60$[cite: 9]. 

Para optimizar la visualización en la consola, el motor del juego implementa una **ventana visible de $20 \times 20$** que se desplaza dinámicamente centrándose en la posición actual del jugador (`P`)[cite: 6, 7]. El objetivo consiste en explorar el mapa, recolectar monedas (`M`), localizar la llave (`K`) para abrir la puerta cerrada (`D`) y acceder a la trampilla de salida (`E`) para avanzar a lo largo de 3 niveles progresivos[cite: 8].

---

## 🎮 Manual de Usuario: Cómo Jugar

Al arrancar el juego, la pantalla mostrará una sección recortada del mapa interactivo[cite: 6]. A continuación se detallan las reglas, simbología y controles del sistema:

### 1. Simbología del Mapa
Cada carácter en la pantalla representa un elemento con el que puedes interactuar:
* **`P` (Jugador):** Tu personaje actual en el mapa[cite: 8].
* **`#` (Paredes):** Obstáculos insuperables[cite: 8]. El sistema de colisiones por ensamblador te impedirá avanzar a través de ellos[cite: 10].
* **`.` (Camino Libre / Celdas Libres):** Espacios vacíos por los que te puedes desplazar con total libertad[cite: 8, 10].
* **`M` (Monedas):** Ítems coleccionables repartidos por el mapa[cite: 8]. Recolectarlas incrementará tu puntuación final[cite: 10].
* **`K` (Llave / Key):** Objeto indispensable para poder abrir la puerta del laberinto[cite: 8]. Solo hay una por nivel.
* **`D` (Puerta / Door):** Una barrera física que bloquea el camino hacia la salida[cite: 8]. Si intentas cruzarla sin haber recogido la llave (`K`) primero, el juego no te dejará avanzar.
* **`E` (Salida / Exit):** La escotilla o trampilla final[cite: 8]. Al pisarla teniendo el camino libre, completarás el nivel actual y avanzarás al siguiente[cite: 8].

### 2. Controles del Juego
El desplazamiento se realiza en tiempo real utilizando las teclas de dirección clásicas de los videojuegos de PC (no es necesario presionar Enter después de cada tecla):
* **`W` / `w` :** Mover al jugador hacia **Arriba**.
* **`S` / `s` :** Mover al jugador hacia **Abajo**.
* **`A` / `a` :** Mover al jugador hacia la **Izquierda**.
* **`D` / `d` :** Mover al jugador hacia la **Derecha**.
* **`Q` / `q` :** **Salir** del juego inmediatamente y cerrar el programa de forma segura.

### 3. Mecánica de Puntuación (Score)
Al completar los 3 niveles con éxito, la rutina en bajo nivel calculará tu puntaje final bajo los siguientes criterios matemáticos[cite: 8, 10]:
* Ganarás **100 puntos** por cada moneda (`M`) recolectada[cite: 10].
* Perderás **2 puntos** por cada paso ejecutado (¡sé eficiente y no des vueltas en círculo!)[cite: 10].
* Recibirás un bono de **500 puntos** extra por cada nivel completado con éxito[cite: 10].

---

## Módulos del Sistema

- **`Main.c`**: Contiene el punto de entrada del programa, la definición física de las matrices de los mapas con alineación de fin de línea ($60 \times 61$ bytes) y el ciclo principal de juego (game loop)[cite: 8, 9].
- **`Juego.c` / `juego.h`**: Implementa la lógica matemática de recorte para la ventana visible y define los prototipos de las funciones externas[cite: 6, 7].
- **`Mapa.h`**: Gestiona las directivas de preprocesamiento de dimensiones y el enlace externo de la matriz tridimensional de niveles[cite: 9].
- **`rutinas.asm`**: Contiene el núcleo de rendimiento del juego programado puramente en bajo nivel (NASM), implementando 5 funciones clave bajo la convención de llamadas de Windows de 64 bits[cite: 10].

---

## Funciones Obligatorias en NASM (64-bits)

El proyecto delega el procesamiento crítico en las siguientes rutinas de ensamblador:
1. `contar_caracteres`: Escanea la memoria secuencial de los mapas para calcular dinámicamente el total de monedas iniciales sin hardcodeo[cite: 10].
2. `validar_movimiento`: Calcula el índice lineal indexado de la matriz para verificar colisiones en tiempo real contra paredes (`#`)[cite: 10].
3. `calcular_puntaje`: Ejecuta una fórmula aritmética balanceada utilizando desplazamientos de bits (`shl`) e instrucciones aritméticas para el score final[cite: 10].
4. `detectar_objeto`: Inspecciona una coordenada específica evaluando interacciones físicas con elementos interactivos (`M`, `K`, `D`, `E`)[cite: 10].
5. `contar_celdas_libres`: Realiza un conteo iterativo al final de cada nivel para determinar los caminos transitables (`.`) remanentes[cite: 10].

---

## Requisitos de Construcción
Para compilar y ejecutar este proyecto de forma híbrida es necesario contar con:
- **MinGW-w64** (con el compilador `gcc` en las variables de entorno del sistema).
- **NASM** (Netwide Assembler configurado para salidas `win64`).

---

## Instrucciones de Compilación y Ejecución

El repositorio incluye un script de automatización por lotes para realizar el ensamblado y enlazado de manera directa.

1. Abra una terminal de comandos (`cmd`) en la raíz del proyecto.
2. Ejecute el archivo de automatización:
```bash
   build.bat
