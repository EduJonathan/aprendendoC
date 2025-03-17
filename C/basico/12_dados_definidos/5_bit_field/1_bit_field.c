#include <stdio.h>

/**
 * BIT FIELDS (campos de bits): são uma forma de estruturar dados em nível de bits
 * dentro de uma estrutura (struct) ou união (union). Eles permitem que especifique o
 * número exato de bits que um membro deve ocupar, o que é útil quando você deseja otimizar
 * o uso de memória ou quando precisa manipular dados em nível de bits.
 */

/**
 * SINTAXE:
 * struct ou union
 * {
 *    tipo de dado nome_do_membro : número_de_bits;
 * };
 */

/**
 * @brief Definição de uma estrutura com campos de bits.
 *
 * Esta estrutura demonstra o uso de campos de bits para armazenar informações compactas:
 */
struct BitFieldsExample
{
    unsigned int flag1 : 1; /**< Um campo de 1 bit para armazenar uma bandeira (0 ou 1) */
    unsigned int value : 4; /**< Um campo de 4 bits para armazenar um valor (0 a 15) */
    unsigned int flag2 : 1; /**< Outro campo de 1 bit para armazenar uma segunda bandeira */
};

int main(int argc, char **argv)
{
    // Criando uma instância da estrutura
    struct BitFieldsExample example;

    // Atribuindo valores aos campos de bits
    example.flag1 = 1; // Define flag1 como 1
    example.value = 7; // Define value como 7 (máximo de 15)
    example.flag2 = 0; // Define flag2 como 0

    // Exibindo os valores atribuídos
    printf("flag1: %u\n", example.flag1); // Imprime o valor de flag1
    printf("value: %u\n", example.value); // Imprime o valor de value
    printf("flag2: %u\n", example.flag2); // Imprime o valor de flag2
    return 0;
}
