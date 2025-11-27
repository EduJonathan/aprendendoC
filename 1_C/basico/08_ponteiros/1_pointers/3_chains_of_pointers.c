#include <stdio.h>

/**
 * CHAINS OF POINTERS (Cadeias de Ponteiros):
 *
 * Um ponteiro armazena o endereço de memória de uma variável. Mas também é possível
 * que um ponteiro armazene o endereço de outro ponteiro, formando uma “cadeia de
 * ponteiros”.
 *
 * Assim como uma variável comum, um ponteiro possui:
 *  -> Um endereço de memória próprio;
 *  -> Um nome (identificador);
 *  -> Um valor armazenado — que, no caso do ponteiro, é o endereço de outra variável.
 *
 * Quando um ponteiro aponta para outro ponteiro, temos uma cadeia como:
 *
 *      int x = 10;
 *      int *p  = &x;   // p aponta para x
 *      int **pp = &p;  // pp aponta para p
 *
 * Esse mecanismo é útil em várias situações, como:
 *  - Funções que precisam modificar ponteiros passados como argumento;
 *  - Estruturas dinâmicas (listas, árvores, matrizes alocadas dinamicamente);
 *  - Implementação de abstrações genéricas.
 *
 * ATENÇÃO:
 * Cadeias de ponteiros aumentam o risco de perda de referência (dangling pointers),
 * especialmente quando usadas junto com alocação dinâmica. Perder um ponteiro intermediário
 * pode tornar impossível liberar a memória corretamente.
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
    printf("\t>>Demonstração do Ponteiro Simples (POINTER1)<<\n");

    pointer1 = &var; // pointer1 aponta para endereço de var

    // Acessa e exibe o endereço de var armazenado em pointer1
    printf(" POINTER1->END. DE MEMÓRIA DE var: %p\n", pointer1);

    // Acessa e exibe o valor de var através de pointer1
    printf(" POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", *pointer1);

    printf("\n=============================================================================\n");
    printf("\t>>Demonstração do Ponteiro Duplo (POINTER2)<<\n");

    pointer2 = &pointer1; // pointer2 aponta endereço de pointer1

    // Acessa e exibe o endereço de pointer1 armazenado em pointer2
    printf(" POINTER2->POINTER1: %p\n", pointer2);

    // Acessa e exibe o endereço de var armazenado em pointer1 através de pointer2
    printf(" POINTER2->POINTER1->END. DE MEMÓRIA DE var: %p\n", *pointer2);

    // Acessa e exibe o valor de var através de pointer1 e pointer2
    printf(" POINTER2->POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", **pointer2);

    printf("\n=============================================================================\n");
    printf("\t>>Demonstração do Ponteiro Triplo (POINTER3)<<\n");

    pointer3 = &pointer2; // pointer3 aponta para o endereço de pointer2

    // Acessa e exibe o endereço de pointer2 armazenado em pointer3
    printf(" POINTER3->POINTER2: %p\n", pointer3);

    // Acessa e exibe o endereço de pointer1 armazenado em pointer2 através de pointer3
    printf(" POINTER3->POINTER2->POINTER1: %p\n", *pointer3);

    // Acessa e exibe o endereço de var armazenado em pointer1 através de pointer2 e pointer3
    printf(" POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var: %p\n", **pointer3);

    // Acessa e exibe o valor de var através de pointer1, pointer2 e pointer3
    printf(" POINTER3->POINTER2->POINTER1->END. DE MEMÓRIA DE var->CONTEÚDO DE var: %d\n", ***pointer3);

    printf("\n=============================================================================\n");
    printf("\t>>Demonstração do Ponteiro Quadruplo (POINTER4)<<\n");

    pointer4 = &pointer3; // pointer4 aponta para endereço de pointer3

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
     * @note Para quem busca uma especialização em C/C++, o uso de ponteiros
     * e "chains of pointers" é essencial o entendimento para garantir a segurança
     * do endereçamento de memória e evitar vulnerabilidades como overflows e invasões.
     * Vale ressaltar que, na prática, dificilmente se usa ponteiros com mais de dois níveis
     * (ou seja, chegando no máximo a um ponteiro duplo "**" ou triplo "***").
     */
    return 0;
}
