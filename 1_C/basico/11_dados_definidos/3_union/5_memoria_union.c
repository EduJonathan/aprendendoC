#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

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

/**
 * @brief Exibe os bytes de um bloco de memória em formato hexadecimal.
 *
 * Percorre um buffer de memória byte a byte e imprime cada valor
 * em hexadecimal (duas casas, letras maiúsculas).
 * A ordem de exibição depende da endianness da máquina:
 * - Em sistemas little-endian, o byte menos significativo é impresso primeiro.
 * - Em sistemas big-endian, o mais significativo vem primeiro.
 *
 * @param ptr  Ponteiro para o início do bloco de memória a ser exibido.
 * @param size Número de bytes a serem impressos.
 *
 * @note A função não altera o conteúdo de memória apontado por `ptr`.
 *       Certifique-se de que o ponteiro seja válido e o tamanho correto.
 */
void print_bytes(uint8_t *ptr, size_t size)
{
    printf("Bytes em hexadecimal (ordem depende da endianness): ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%02X ", ptr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    // Verifica se int e float têm o mesmo tamanho
    static_assert(sizeof(int) == sizeof(float), "Este código assume que int e float têm 4 bytes");

    union Exemplo x = {0};

    x.i = 1065353216; // 0x3F800000, corresponde a 1.0f em IEEE 754
    printf("Como int: %d\n", x.i);
    printf("Como float: %f\n", x.f);
    print_bytes((uint8_t *)&x, sizeof(x));
    printf("\n");

    x.f = 1.0f;
    printf("Interpretando como float: %f\n", x.f);
    print_bytes((uint8_t *)&x, sizeof(x));

    // Exemplo com memcpy (alternativa mais segura para type punning)
    int i = 1065353216;
    float f;
    memcpy(&f, &i, sizeof(int));
    printf("Usando memcpy - Como float: %f\n", f);

    // Exemplo com outro tipo na union
    union Exemplo y = {.f = 2.0f}; // Inicializa como float
    
    printf("\nOutro exemplo:\n");
    printf("Como float: %f\n", y.f);
    printf("Como int: %d\n", y.i); // Interpretação dos bits como int
    print_bytes((uint8_t *)&y, sizeof(y));

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
    return 0;
}
