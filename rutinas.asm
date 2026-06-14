section .text

global contar_caracteres
global validar_movimiento
global calcular_puntaje
global detectar_objeto
global contar_celdas_libres

; FUNCION 1: CONTAR CARACTERES 
contar_caracteres:
    xor rax, rax            ; Limpiamos el contador (empieza en 0)
    xor r9, r9              ; Indice para el ciclo (i = 0)

bucle_conteo:
    cmp r9d, edx            ; Ver si ya llegamos al final de las celdas
    jge fin_conteo
    
    mov r10b, [rcx + r9]    ; Agarramos el caracter actual
    cmp r10b, r8b           ; Ver si es el que buscamos
    jne siguiente_celda
    inc rax                 ; Si coincide, sumamos 1

siguiente_celda:
    inc r9                  ; i++
    jmp bucle_conteo

fin_conteo:
    ret


; FUNCION 2: VALIDAR MOVIMIENTO
validar_movimiento:
    ; Formula para movernos en la matriz: (fila * columnas) + columna
    mov eax, r8d            ; Pasamos nueva_fila a EAX
    imul eax, edx           ; Multiplicamos por columnas_mapa (60)
    add eax, r9d            ; Sumamos la nueva_columna
    
    movsxd rax, eax         ; Ajustamos el tamaño a 64 bits para la direccion
    
    mov r10b, [rcx + rax]   ; Buscamos que caracter hay en esa posicion del mapa
    
    cmp r10b, '#'           ; ¿Es una pared?
    je es_pared
    
    mov rax, 1              ; Si no es pared, regresamos 1 (libre)
    ret

es_pared:
    mov rax, 0              ; Si es pared, regresamos 0 (bloqueado)
    ret


;FUNCION 3: CALCULAR PUNTAJE 
calcular_puntaje:
    ; Formula facil: (monedas * 100) - (pasos * 2) + (niveles * 500)
    mov rax, rcx            ; Cargamos monedas
    imul rax, 100           ; Monedas por 100

    mov r10, rdx            ; Cargamos pasos
    shl r10, 1              ; Multiplicamos pasos por 2 usando un shift a la izquierda

    sub rax, r10            ; Restamos los pasos al puntaje que llevamos

    movsxd r11, r8d         ; Cargamos niveles completados
    imul r11, 500           ; Cada nivel da 500 puntos extra

    add rax, r11            ; Sumamos el bono de los niveles
    ret


; FUNCION 4: DETECTAR OBJETO 
detectar_objeto:
    ; Haz esta funcion
    xor rax, rax            ; mientras regresa 0 para que no truene el compilador
    ret


; FUNCION 5: CONTAR CELDAS LIBRES 
contar_celdas_libres:
    ; Falta meter el ciclo para buscar los puntos '.'
    xor rax, rax            ; Regresa 0 temporalmente
    ret
