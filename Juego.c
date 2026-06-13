#include <stdio.h>
#include "juego.h"

void imprimir_ventana(char mapa[FILAS_MAPA][COLUMNAS_MAPA + 1], Jugador p) {
    // Calcula donde empieza a dibujarse la ventana para que el jugador  quede en el centro
    int inicio_fila = p.fila - (VENTANA_FILAS / 2);
    int inicio_col = p.col - (VENTANA_COLS / 2);

    //  Validar los límites superiores e izquierdos 
    if (inicio_fila < 0) {
        inicio_fila = 0;
    }
    if (inicio_col < 0) {
        inicio_col = 0;
    }

    //  Validar los limites inferiores y derechos 
    if (inicio_fila > FILAS_MAPA - VENTANA_FILAS) {
        inicio_fila = FILAS_MAPA - VENTANA_FILAS;
    }
    if (inicio_col > COLUMNAS_MAPA - VENTANA_COLS) {
        inicio_col = COLUMNAS_MAPA - VENTANA_COLS;
    }

    // 4. Imprimir solo el recorte de 20x20 
    printf("\n--- BITQUEST ---\n\n");
    for (int i = inicio_fila; i < inicio_fila + VENTANA_FILAS; i++) {
        for (int j = inicio_col; j < inicio_col + VENTANA_COLS; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}
