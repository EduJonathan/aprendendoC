#include <stdio.h>
#include <stdint.h>

/**
 * Em uma union, todos os membros compartilham o mesmo bloco de memória, então não existe
 * "qual tipo de dado está usando os bytes" — os mesmos bytes são usados por todos os membros,
 * e o tipo que você acessar determina como esses bytes serão interpretados.
 */

/**
 * "Qual byte ele está utilizando: os 4 bytes do float ou os 4 bytes do int?"
 * A union usa os mesmos 4 bytes para ambos. O conteúdo da memória é único, mas dependendo
 * de qual campo você acessar (int ou float), o compilador interpreta aqueles mesmos bits
 * como um número inteiro ou um número decimal.
 */
union Exemplo
{
    int i;   // 4 bytes
    float f; // 4 bytes
};

int main(int argc, char **argv)
{
    union Exemplo x = {0};

    x.i = 1065353216; // Binário correspondente a 1.0f em float
    printf("Como int: %d\n", x.i);
    printf("Como float: %f\n", x.f);
    printf("\n");

    /**
     * O que está acontecendo aqui?
     * A union tem 4 bytes de memória.
     * Você armazena um valor como int, e depois o lê como float.
     * O valor não muda na memória — apenas a interpretação dos bits muda.
     *
     * Isso é chamado de type punning(técnica de programação onde você interpreta os
     * mesmos dados binários (mesmos bytes na memória) como tipos diferentes)
     * sem converter os valores, apenas mudando a forma como os bits são interpretados.
     * CUIDADO: Ele pode quebrar a portabilidade do código e levar a comportamento indefinido
     */

    x.f = 1.0f;

    uint8_t *ptr = (uint8_t *)&x;

    printf("Interpretando como float: %f\n", x.f);
    printf("Bytes em hexadecimal: ");
    for (int i = 0; i < sizeof(x); i++)
    {
        printf("%02X ", ptr[i]);
    }
    printf("\n");
    return 0;
}
