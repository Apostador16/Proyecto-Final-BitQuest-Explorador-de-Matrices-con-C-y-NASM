#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <Juego.h>

int main() {
    int nivel_actual = 0;
    Jugador jugador = {0, 0, 0, 0, 0};

    // Buscar automaticamente dónde empieza el jugador ('P') en el nivel actual
    for (int i = 0; i < FILAS_MAPA; i++) {
        for (int j = 0; j < COLUMNAS_MAPA; j++) {
            if (mapas[nivel_actual][i][j] == 'P') {
                jugador.fila = i;
                jugador.col = j;
                break;
            }
        }
    }

    char tecla;
    int jugando = 1;

    // Bucle principal del juego
    while (jugando) {
        system("cls"); // Limpiar la consola en cada fotograma
        
        // Llamada a la funcion que armamos en juego.c
        imprimir_ventana(mapas[nivel_actual], jugador);
        
        printf("\nNivel: %d | Pasos: %d | Llave: %s\n", nivel_actual + 1, jugador.pasos, jugador.tiene_llave ? "Si" : "No");
        printf("Controles: W (Arriba) S (Abajo) A (Izq) D (Der) | Q (Salir)\n");
        
        tecla = _getch(); // Capturar la tecla [cite: 74]

        int nueva_fila = jugador.fila;
        int nueva_col = jugador.col;

        // Determinar a que coordenada intenta moverse el jugador 
        if (tecla == 'w' || tecla == 'W') nueva_fila--;
        else if (tecla == 's' || tecla == 'S') nueva_fila++;
        else if (tecla == 'a' || tecla == 'A') nueva_col--;
        else if (tecla == 'd' || tecla == 'D') nueva_col++;
        else if (tecla == 'q' || tecla == 'Q') jugando = 0;

        // Validación temporal de movimiento nota para no olviarme de pasarla al nasm
    
        // Solo se mueve si la siguiente casilla NO es una pared '#' 
        if (mapas[nivel_actual][nueva_fila][nueva_col] != '#') {
            
            // Borrar el rastro viejo del jugador dejandolo como camino libre '.'
            mapas[nivel_actual][jugador.fila][jugador.col] = '.';
            
            // Actualizar las coordenadas reales del jugador
            jugador.fila = nueva_fila;
            jugador.col = nueva_col;
            jugador.pasos++;
            
            // Dibujar al jugador en la nueva posicion
            mapas[nivel_actual][jugador.fila][jugador.col] = 'P';
        }
    }

    system("cls");
    printf("¡Saliste del juego! Nos vemos en la proxima.\n");
    return 0;
}
