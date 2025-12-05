#include "../include/println.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    println("Primeiros testes da função println:");
    println("Olá, mundo!");
    println("Número: %d", 42);
    println("Float: %.2f", 3.14159);
    println("String: %s", "Teste");

    printf("\nTestando diferentes formatos:\n");

    println("Olá, %s!", "Mundo");
    println("Número: %d", 42);
    println("Char: %c", 'A');
    println("Porcento: %%");
    println("Misto: %s tem %d anos e começa com '%c'", "João", 25, 'J');

    printf("\nTestando retorno de println:\n");

    // Chamada à função implementada em Assembly
    int chars_printed = println("O número é: %d", 42);

    printf("\nprintln retornou o total de caracteres impressos: %d\n", chars_printed);

    /**
     * Para compilar e rodar:
     *
     * Estando no diretório
     * ~/Documentos/aprendendoC/4_biblioteca_estaticas_dinamicas/println (linux)
     * ou
     * C:\Users\eduardo\Documentos\aprendendoC\4_biblioteca_estaticas_dinamicas\println (windows)
     *
     * compile com:
     * gcc src/main.c -Iinclude -Llib -lminha -o meu_programa
     * ./meu_programa
     */
    return 0;
}
