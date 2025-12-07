; println_static.asm - Para biblioteca estática
section .text
    global _println
    extern printf

_println:
    push rbp
    mov rbp, rsp
    push rbx
    
    ; Chamar printf com argumentos originais
    xor eax, eax
    call printf wrt ..plt
    mov rbx, rax
    
    ; Imprimir nova linha
    mov rdi, fmt_newline
    xor eax, eax
    call printf wrt ..plt
    
    add rbx, 1
    mov rax, rbx
    
    pop rbx
    mov rsp, rbp
    pop rbp
    ret

section .rodata
fmt_newline: db 10, 0
