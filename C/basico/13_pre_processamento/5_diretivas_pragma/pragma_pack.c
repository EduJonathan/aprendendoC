#include <stdio.h>

/**
 * #pragma pack: Desativa o alinhamento de memória é comumente usada para controlar o alinhamento
 * de memória das estruturas em C, especialmente útil quando se trabalha com dados binários ou
 * quando a estrutura de dados precisa ter um tamanho específico e controlado.
 * NÃO POSSUEM FLAGS, mas podem ter umas que possam forçar
 *
 * Em alguns compiladores, essa flag pode ser usada para forçar o empacotamento
 * de todas as estruturas.
 * gcc -fpack-struct -o programa programa.c
 * gcc -fno-packed-struct: Desativa o empacotamento forçado.
 */

#pragma pack(1)

struct Exemplo
{
    char x;  // 1 byte
    int y;   // 4 bytes
    float z; // 4 bytes
};

#pragma pack() // Restaura o alinhamento de memória padrão

int main(int argc, char **argv)
{
    printf("TAMANHO DA STRUCT SEM PADDING: %zu\n", sizeof(struct Exemplo));
    return 0;
}
