global contar_caracteres

section .text

; valores recibidos desde C 
; RCX = dirección inicial del mapa 
; RDX = numero total de celdas 
; R8  = caracter que se desea contar 
; Retorno:
; RAX = numero de veces que aparece el carácter

contar_caracteres:
    xor rax, rax          ; Limpiar RAX (nuestro contador inicia en 0)
    test rdx, rdx         ; Comprobar si el total de celdas es 0 o menor
    jle fin_conteo        ; Si es 0, terminamos de inmediato

bucle_conteo:
    mov r9b, byte [rcx]   ; Leer 1 byte (un caracter) del mapa apuntado por RCX
    cmp r9b, r8b          ; Comparar el carácter leído con el que buscamos
    jne siguiente_celda   ; Si no son iguales, saltamos a la siguiente celda
    inc rax               ; Si son iguales, sumamos 1 a nuestro contador (RAX)

siguiente_celda:
    inc rcx               ; Avanzar el puntero a la siguiente celda de memoria
    dec rdx               ; Restar 1 al total de celdas por revisar
    jnz bucle_conteo      ; Si aun quedan celdas (RDX no es 0), repetir el bucle

fin_conteo:
    ret                   ; Retornar a C. El resultado ya está guardado en RAX.