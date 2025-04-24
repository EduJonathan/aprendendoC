#include <stdio.h>

/**
 * CHAINSOFPOINTER: Se um ponteiro armazena um endereço de memória de uma variável,
 * quais as chances de um ponteiro guardar o endereço de outro ponteiro, aliás um ponteiro
 * é nada mais, nada menos que uma variável, com a diferença que ao invés de armazenar um valor
 * ele armazena um endereço de memória de uma varíavel que nesta varíavel se guarda um contéudo
 * (um valor) e o ponteiros recebe os mesmos atributos de uma varíavel. sendo eles:
 *  -> um endereço de memória alocado,
 *  -> um nome (identificador/variável),
 *  -> um valor (endereço de memória).
 * Este é o conceito de "chains of pointers", correntes de ponteiros, ou ponteiros para ponteiros.
 * O perigo está quando você perde a referência do endereço, usado em situações complexas como
 * endereçamento e alocação de matrizes e listas encadeadas
 */

int main(int argc, char **argv)
{
    printf("\t>>CHAINS OF POINTERS<<\n");

    /* Variável comum */
    int var = 10;
    printf(" CONTEÚDO DE var: %d\tENDEREÇO DE MEMÓRIA DE var: %p\n", var, &var);

    /* Ponteiros de diferentes níveis */
    int *pointer1 = NULL;    // Ponteiro Simples
    int **pointer2 = NULL;   // Ponteiro Duplo
    int ***pointer3 = NULL;  // Ponteiro Triplo
    int ****pointer4 = NULL; // Ponteiro Quadruplo

    printf("\n=============================================================================\n");
    printf("\t>>ENDEREÇO DE CADA PONTEIRO<<\n");

    printf(" ENDEREÇO DE MEMÓRIA DE POINTER1 : %p\n", &pointer1); // Endereço de pointer1
    printf(" ENDEREÇO DE MEMÓRIA DE POINTER2 : %p\n", &pointer2); // Endereço de pointer2
    printf(" ENDEREÇO DE MEMÓRIA DE POINTER3 : %p\n", &pointer3); // Endereço de pointer3
    printf(" ENDEREÇO DE MEMÓRIA DE POINTER4 : %p\n", &pointer4); // Endereço de pointer4

    printf("\n=============================================================================\n");
    printf("\t>>POINTER1<<\n");

    /* Demonstração do Ponteiro Simples (POINTER1) */
    pointer1 = &var;
    // pointer1 aponta para endereço de var

    // Acessa e exibe o endereço de var armazenado em pointer1
    printf(" POINTER1->END. DE MEMÓRIA DE var: %p\n", pointer1);

    // Acessa e exibe o valor de var através de pointer1
    printf(" POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", *pointer1);

    printf("\n=============================================================================\n");
    printf("\t>>POINTER2<<\n");

    /* Demonstração do Ponteiro Duplo (POINTER2) */
    pointer2 = &pointer1;
    // pointer2 aponta endereço de pointer1

    // Acessa e exibe o endereço de pointer1 armazenado em pointer2
    printf(" POINTER2->POINTER1: %p\n", pointer2);

    // Acessa e exibe o endereço de var armazenado em pointer1 através de pointer2
    printf(" POINTER2->POINTER1->END. DE MEMÓRIA DE var: %p\n", *pointer2);

    // Acessa e exibe o valor de var através de pointer1 e pointer2
    printf(" POINTER2->POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", **pointer2);

    printf("\n=============================================================================\n");
    printf("\t>>POINTER3<<\n");

    /* Demonstração do Ponteiro Triplo (POINTER3) */
    pointer3 = &pointer2;
    // pointer3 aponta para o endereço de pointer2

    // Acessa e exibe o endereço de pointer2 armazenado em pointer3
    printf(" POINTER3->POINTER2: %p\n", pointer3);

    // Acessa e exibe o endereço de pointer1 armazenado em pointer2 através de pointer3
    printf(" POINTER3->POINTER2->POINTER1: %p\n", *pointer3);

    // Acessa e exibe o endereço de var armazenado em pointer1 através de pointer2 e pointer3
    printf(" POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var: %p\n", **pointer3);

    // Acessa e exibe o valor de var através de pointer1, pointer2 e pointer3
    printf(" POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", ***pointer3);

    printf("\n=============================================================================\n");
    printf("\t>>POINTER4<<\n");

    /* Demonstração do Ponteiro Quadruplo (POINTER4) */
    pointer4 = &pointer3;
    // pointer4 aponta para endereço de pointer3

    // Acessa e exibe o endereço de pointer3 armazenado em pointer4
    printf(" POINTER4->POINTER3: %p\n", pointer4);

    // Acessa e exibe o endereço de pointer2 armazenado em pointer3 através de pointer4
    printf(" POINTER4->POINTER3->POINTER2: %p\n", *pointer4);

    // Acessa e exibe o endereço de pointer1 armazenado em pointer2 através de pointer3 e pointer4
    printf(" POINTER4->POINTER3->POINTER2->POINTER1: %p\n", **pointer4);

    // Acessa e exibe o endereço de var armazenado em pointer1 através de pointer2, pointer3 e pointer4
    printf(" POINTER4->POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var: %p\n", ***pointer4);

    // Acessa e exibe o valor de var através de pointer1, pointer2, pointer3 e pointer4
    printf(" POINTER4->POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", ****pointer4);

    /**
     * @note para quem desejar a especialização de C/C++, ponteiros e uso dos chains of pointers
     * é de entendimento bastante desejado, para o tratamento e segurança do endereçamento da
     * memória e evitar brechas de invasão ou de overflow, uma ressalva sobre chains of pointers
     * é que dificilmente você irá passar dos ponteiros duplos "**", podendo chegar no máximo
     * ao ponteiro triplo "***".
     */
    return 0;
}
