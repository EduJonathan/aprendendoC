section .text
    global _println

_println:
    push rbp
    mov rbp, rsp

    push rdi            ; salva ponteiro da string

    ; strlen
    mov rsi, rdi
    xor rcx, rcx

.len_loop:
    cmp byte [rsi + rcx], 0
    je .len_done
    inc rcx
    jmp .len_loop

.len_done:
    ; rcx = len

    ; write(1, str, len)
    mov rax, 1          ; sys_write
    mov rdi, 1          ; stdout
    pop rsi             ; rsi = str
    mov rdx, rcx        ; len
    syscall

    ; write(1, "\n", 1)
    mov rax, 1
    mov rdi, 1
    lea rsi, [rel newline]
    mov rdx, 1
    syscall

    ; return len + 1
    lea rax, [rcx + 1]

    pop rbp
    ret

section .rodata
newline: db 10
