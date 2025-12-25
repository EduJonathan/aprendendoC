#include <stdio.h>
#include "../include/println.h"

/**
 * Para compilar, esteja dentro do diretório raiz do projeto(no caso projeto_println):
 *
 * Certifique-se de ter instalado o compilador para assembly x86_64 (ex: nasm) e o gcc, em sua máquina.
 *
 * # 1. Criar objeto assembly
 * - nasm -f elf64 assembly/println.asm -o lib/println.o
 *
 * # 2. Criar biblioteca estática
 * - ar rcs lib/libprintln.a lib/println.o
 *
 * # 3. Compilar main com header
 * - gcc -c -I./include src/main.c -o src/main.o
 *
 * # 4. Linkar tudo junto
 * - gcc src/main.o lib/libprintln.a -o programa
 *
 * # Executar
 * ./programa
 */

int main(int argc, char **argv)
{
    _println("Testando a função _println()");
    
    // Testes básicos
    _println("Hello, Assembly World");
    _println("Sem libc");
    _println("Syscall direto");

    // Comparação com printf normal
    printf("printf normal\n");
    _println("\nHello, Assembly World");
    _println("Sem libc");
    _println("Syscall direto");

    return 0;
}
