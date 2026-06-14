global contar_caracteres
global validar_movimiento
global calcular_puntaje
global detectar_objeto
global contar_celdas_libres

section .text

; ====================================================================
; 1: contar_caracteres 
; RCX = mapa, RDX = total celdas, R8B = caracter
; ====================================================================
contar_caracteres:
    xor rax, rax          
    test rdx, rdx         
    jle .fin              
.bucle:
    mov r9b, byte [rcx]   
    cmp r9b, r8b          
    jne .siguiente        
    inc rax               
.siguiente:
    inc rcx               
    dec rdx               
    jnz .bucle            
.fin:
    ret                   

; ====================================================================
; 2: validar_movimiento 
; RCX = mapa, RDX = columnas (61), R8 = fila, R9 = columna
; ====================================================================
validar_movimiento:
    mov rax, r8           ; rax = fila
    imul rax, rdx         ; rax = fila * columnas
    add rax, r9           ; rax = (fila * columnas) + columna
    
    mov r10b, byte [rcx + rax]
    cmp r10b, '#'         ; Revisar si es pared
    je .bloqueado
    
    mov rax, 1            ; Permitido avanzar
    ret
.bloqueado:
    mov rax, 0            ; Pared, bloqueado
    ret

; ====================================================================
; 3: calcular_puntaje 
; RCX = monedas, RDX = pasos, R8 = niveles
; ====================================================================
calcular_puntaje:
    mov rax, rcx          
    imul rax, 100         ; rax = monedas * 100
    
    mov r9, rdx           
    shl r9, 1             ; r9 = pasos * 2
    sub rax, r9           ; rax = (monedas * 100) - (pasos * 2)
    
    movsxd r9, r8d        
    imul r9, 500          ; r9 = niveles * 500
    add rax, r9           ; rax = puntaje final
    ret

; ====================================================================
; 4: detectar_objeto 
; RCX = mapa, RDX = cols, R8 = fila, R9 = col, [rsp+40] = objeto
; ====================================================================
detectar_objeto:
    mov rax, r8
    imul rax, rdx
    add rax, r9           ; rax = indice lineal
    
    mov r10b, byte [rcx + rax] 
    mov r11b, byte [rsp + 40]  ; Quinto parametro extraido de la pila
    
    cmp r10b, r11b        
    je .encontrado
    
    mov rax, 0            
    ret
.encontrado:
    mov rax, 1            
    ret

; ====================================================================
; 5: contar_celdas_libres 
; RCX = mapa, RDX = total celdas
; ====================================================================
contar_celdas_libres:
    xor rax, rax          
    test rdx, rdx         
    jle .fin_celdas
.bucle_celdas:
    mov r8b, byte [rcx]
    cmp r8b, '.'          ; Compara directo contra el camino libre
    jne .sig_celda
    inc rax
.sig_celda:
    inc rcx
    dec rdx
    jnz .bucle_celdas
.fin_celdas:
    ret
