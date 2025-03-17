#include <stdio.h>

/**
 * @struct ExemploStructAninhadaComUnion
 *
 * @brief Estrutura contendo um membro aninhado de uma união. Esta estrutura exemplifica
 * o uso de uma união dentro de uma estrutura. A união pode conter diferentes tipos de dados,
 * mas somente um membro pode ter um valor válido de cada vez. A estrutura tem dois membros:
 * um caractere e uma união aninhada.
 */
struct ExemploStructAninhadaComUnion
{
    char a; /**< Membro char */
    
    union
    {
        int b;    /**< Membro int */
        double c; /**< Membro double */
    } u;          /**< União aninhada */
};

int main(int argc, char **argv)
{
    printf("Tamanho da 'struct aninhada com a union': %zu\n", sizeof(struct ExemploStructAninhadaComUnion));
    /*
     * Neste exemplo, o compilador pode inserir bytes de preenchimento após o campo `a`
     * para garantir que o campo `u` comece em um endereço alinhado corretamente, dependendo
     * dos requisitos de alinhamento para `int` ou `double` em sua arquitetura específica.
     * Embora o conceito de padding seja aplicado a membros dentro de uma struct, não é aplicado
     * diretamente à union.
     */
    return 0;
}
