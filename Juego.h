#ifndef JUEGO_H
#define JUEGO_H

#include "mapas.h"

// Dimensiones de la ventana visible requeridas por la rúbrica 
#define VENTANA_FILAS 20
#define VENTANA_COLS 20

// Estructura para agrupar los datos del jugador
typedef struct {
    int fila;
    int col;
    int monedas_recolectadas;
    int tiene_llave;
    int pasos;
} Jugador;

// Prototipos de las funciones en C 
void imprimir_ventana(char mapa[FILAS_MAPA][COLUMNAS_MAPA + 1], Jugador p);

#endif
