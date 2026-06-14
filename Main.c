#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <juego.h> 

int main() {
    int nivel_actual = 0;
    
    // Bucle principal para transicionar entre los 3 niveles del juego
    while (nivel_actual < NUM_NIVELES) {
        Jugador jugador = {0, 0, 0, 0, 0};
        int nivel_jugando = 1;

        //  Buscar automáticamente la posición inicial del jugador ('P')
        for (int i = 0; i < FILAS_MAPA; i++) {
            for (int j = 0; j < COLUMNAS_MAPA; j++) {
                if (mapas[nivel_actual][i][j] == 'P') {
                    jugador.fila = i;
                    jugador.col = j;
                    break;
                }
            }
        }

        // Calcular el total de monedas del nivel actual usando NASM
        int total_monedas_nivel = 0; 
        for (int i = 0; i < FILAS_MAPA; i++) {
            for (int j = 0; j < COLUMNAS_MAPA; j++) {
                if (mapas[nivel_actual][i][j] == 'M') {
                    total_monedas_nivel++;
                }
            }
        }

        // Bucle del nivel actual
        while (nivel_jugando) {
            system("cls"); // Limpiar pantalla en Windows
            
            // Imprimir el recorte de la ventana visible de 20x20
            imprimir_ventana(mapas[nivel_actual], jugador);
            
            // Estado actual en pantalla
            printf("\n=================================");
            printf("\nNivel: %d | Pasos: %d | Monedas: %d/%d | Llave: %s\n", 
                   nivel_actual + 1, 
                   jugador.pasos, 
                   jugador.monedas_recolectadas, 
                   total_monedas_nivel,
                   jugador.tiene_llave ? "Si" : "No");
            printf("Controles: W (Arriba) S (Abajo) A (Izq) D (Der) | Q (Salir)\n");
            printf("=================================\n");
            
            char tecla = _getch(); // Capturar la tecla del usuario

            int nueva_fila = jugador.fila;
            int nueva_col = jugador.col;

            // Determinar a qué coordenada intenta moverse el jugador 
            if (tecla == 'w' || tecla == 'W') nueva_fila--;
            else if (tecla == 's' || tecla == 'S') nueva_fila++;
            else if (tecla == 'a' || tecla == 'A') nueva_col--;
            else if (tecla == 'd' || tecla == 'D') nueva_col++;
            else if (tecla == 'q' || tecla == 'Q') {
                system("cls");
                printf("¡Saliste del juego! Nos vemos en la proxima.\n");
                return 0; // Finaliza el programa completo
            }

            // Validación de Movimiento y Colisiones
            int puede_caminar = (mapas[nivel_actual][nueva_fila][nueva_col] != '#');

            if (puede_caminar) {
                char celda_destino = mapas[nivel_actual][nueva_fila][nueva_col];

                // Regla: Interacción con la Puerta 'D'
                if (celda_destino == 'D' && !jugador.tiene_llave) {
                    // Si es una puerta y no tiene la llave, se bloquea el movimiento
                    continue; 
                }

                // Regla: Recolección de Monedas 'M'
                // TODO: ENSAMBLADOR - Opcionalmente puedes usar tu función obligatoria 4 aquí para detectar el objeto 'M'
                if (celda_destino == 'M') {
                    jugador.monedas_recolectadas++;
                }

                // Regla: Recolección de la Llave 'K'
                // TODO: ENSAMBLADOR - Opcionalmente puedes usar tu función obligatoria 4 aquí para detectar el objeto 'K'
                if (celda_destino == 'K') {
                    jugador.tiene_llave = 1;
                }

                // Regla: Llegada a la Salida 'E' (Fin del Nivel)
                if (celda_destino == 'E') {
                    nivel_jugando = 0; // Rompe el bucle del nivel actual
                }

                // Actualizar la matriz del mapa en memoria
                mapas[nivel_actual][jugador.fila][jugador.col] = '.'; // Deja camino libre atrás
                jugador.fila = nueva_fila;
                jugador.col = nueva_col;
                jugador.pasos++;
                
                // Si no ha salido del nivel, dibuja al jugador en su nueva posición
                if (celda_destino != 'E') {
                    mapas[nivel_actual][jugador.fila][jugador.col] = 'P';
                }
            }
        }

        // Pantalla de resumen al finalizar cada nivel
        system("cls");
        printf("=================================\n");
        printf("       NIVEL %d COMPLETADO       \n", nivel_actual + 1);
        printf("=================================\n");
        printf("Monedas recolectadas: %d/%d\n", jugador.monedas_recolectadas, total_monedas_nivel);
        printf("Pasos realizados: %d\n", jugador.pasos);
        printf("=================================\n");
        printf("Presiona cualquier tecla para continuar al siguiente nivel");
        _getch();

        nivel_actual++; // Avanzar al siguiente nivel en la matriz de mapas
    }

    // Resumen Final del Juego
    system("cls");
    printf("=================================\n");
    printf("        JUEGO COMPLETADO         \n");
    printf("=================================\n");
    printf("Niveles completados: %d\n", nivel_actual);
    
    // TODO: ENSAMBLADOR - Reemplazar este cálculo por tu función obligatoria 3 de NASM
    // int puntaje_final = calcular_puntaje(monedas_totales, pasos_totales, 3);
    printf("Puntaje final: \n"); 
    printf("=================================\n");

    return 0;
}
