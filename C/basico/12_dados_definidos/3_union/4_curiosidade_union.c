#include <stdio.h>

/**
 * @union Union
 *
 * @brief Definição de uma união chamada `Union`. Esta união permite armazenar diferentes
 * tipos de dados na mesma localização de memória. Somente um dos membros da união pode ter
 * um valor válido de cada vez. A union tem quatro membros: um char, um char, um int e um float.
 */
union Union
{
    char type; /**< Membro char */
    char a;    /**< Membro char */
    int b;     /**< Membro inteiro */
    float c;   /**< Membro float */
};

int main(int argc, char **argv)
{
    // Declaração da união
    union Union u;

    // Marca 'a' como em uso e atribuição
    u.type = 'a'; // Define o tipo para 'a'
    u.a = 'A';    // Atribui o valor 'A' ao membro 'a'

    // Imprime o valor de 'a'
    printf("u.a: %c\n", u.type);
    printf("u.a: %c\n", u.a);

    // Marca 'b' como em uso e atribuição
    u.type = 'b'; // Define o tipo para 'b'
    u.b = 56;     // Atribui o valor 56 ao membro 'b'

    // Imprime o valor de 'b'
    printf("u.a: %c\n", u.type);
    printf("u.b: %d\n", u.b);

    // Marca 'c' como em uso e atribuição
    u.type = 'c';  // Define o tipo para 'c'
    u.c = 14.514F; // Atribui o valor 14.514 ao membro 'c'

    // Imprime o valor de 'c'
    printf("u.a: %c\n", u.type);
    printf("u.c: %f\n", u.c);

    /*
     * Embora `type` seja usado para identificação, ele não altera diretamente
     * o valor dos outros membros e é mais uma convenção para manter controle sobre qual
     * membro da união está em uso.
     */
    return 0;
}
