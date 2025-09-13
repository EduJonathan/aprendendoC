#include <stdio.h>

// Este código visa explicar o funcionamento dos operadores de deslocamento de bits em C,
// tanto o deslocamento à esquerda (<<) quanto à direita (>>), demonstrando como esses
// operadores afetam os valores de uma variável.

int main(int argc, char **argv)
{
    // Operador de deslocamento de bits à esquerda (<<):
    // Desloca os bits de um número para a esquerda. Isso é equivalente a multiplicar
    // o número por 2 elevado ao número de posições que os bits são deslocados.
    printf(" 4 << 1: %4d\n", 4 << 1); // 4 * (2^1) = 8
    printf(" 4 << 2: %4d\n", 4 << 2); // 4 * (2^2) = 16
    printf(" 4 << 3: %4d\n", 4 << 3); // 4 * (2^3) = 32
    printf(" 4 << 4: %4d\n", 4 << 4); // 4 * (2^4) = 64
    printf(" 4 << 5: %4d\n", 4 << 5); // 4 * (2^5) = 128
    printf(" ...\n");
    printf(" 4 << 20: %4d\n", 4 << 20); // 4 * (2^20) = 4194304

    puts("\n");

    // Operador de deslocamento de bits à direita (>>):
    // Desloca os bits de um número para a direita. Isso é equivalente a dividir o número
    // por 2 elevado ao número de posições que os bits são deslocados.
    printf(" 16 >> 1: %4d\n", 16 >> 1); // 16 / (2^1) = 8
    printf(" 16 >> 2: %4d\n", 16 >> 2); // 16 / (2^2) = 4
    printf(" 16 >> 3: %4d\n", 16 >> 3); // 16 / (2^3) = 2
    printf(" 16 >> 4: %4d\n", 16 >> 4); // 16 / (2^4) = 1
    printf(" ...\n");
    printf(" 16 >> 20: %4d\n", 16 >> 20); // 16 / (2^20) = 0

    puts("\n");

    printf("-----------------------------\n");
    printf("QUAL A SAÍDA DE\n");

    // Exemplos com operadores de deslocamento compostos (<<= e >>=):
    // O operador <<= realiza o deslocamento à esquerda e, em seguida, atribui o
    // valor resultante à variável.

    int valor1 = 8;
    valor1 <<= 2; // Desloca 8 para a esquerda por 2 posições: 8 * (2^2) = 32
    printf("8 <<= 2: %d  // 8 * (2^2) = 32\n", valor1);

    int valor2 = 8;
    valor2 >>= 2; // Desloca 8 para a direita por 2 posições: 8 / (2^2) = 2
    printf("8 >>= 2: %d  // 8 / (2^2) = 2\n", valor2);
    return 0;
}
