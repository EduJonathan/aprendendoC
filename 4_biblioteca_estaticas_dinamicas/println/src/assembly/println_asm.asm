section .data
section .text

; Função: _println_internal
; Parâmetro: rdi = ponteiro para string (System V AMD64 ABI)
; Retorno: rax = número de caracteres impressos
global _println_internal

_println_internal:
    ; Salva registradores
    push rbp
    mov rbp, rsp
    
    ; Calcula o tamanho da string
    mov rsi, rdi        ; Salva ponteiro original
    xor rcx, rcx        ; Contador = 0
    
.calc_length:
    mov al, [rdi]       ; Carrega caractere
    test al, al         ; É NULL?
    jz .done_length
    inc rdi
    inc rcx
    jmp .calc_length

.done_length:
    ; RCX agora tem o comprimento da string
    
    ; Chamada de sistema: write
    mov rax, 1          ; sys_write
    mov rdi, 1          ; stdout (file descriptor 1)
    mov rdx, rcx        ; tamanho da string
    mov rsi, rsi        ; ponteiro para string (já em rsi)
    syscall
    
    ; Restaura registradores
    mov rsp, rbp
    pop rbp
    ret