#ifndef MAPA_H
#define MAPA_H

#define FILAS_MAPA 60
#define COLUMNAS_MAPA 60
#define NUM_NIVELES 3

// Avisamos al compilador que la matriz existe, pero que los datos viven en main.c
extern char mapas[NUM_NIVELES][FILAS_MAPA][COLUMNAS_MAPA + 1];

#endif
