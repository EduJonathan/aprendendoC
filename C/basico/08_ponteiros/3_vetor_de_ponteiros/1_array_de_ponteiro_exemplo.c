#include <stdio.h>

/*
 * Vetor de ponteiros: Um vetor de ponteiros é um array onde cada elemento é um ponteiro,
 * ou seja, cada posição do vetor armazena o endereço de memória de uma variável ou estrutura
 * de dados. Em C, isso significa que o vetor pode apontar para diferentes locais de memória,
 * como outros arrays, strings, ou qualquer outra variável ou estrutura que possa ser referenciada
 * por ponteiros.
 *
 * Vetores de ponteiros são úteis em situações onde você precisa manipular ou acessar um conjunto
 * de dados de forma dinâmica, ou quando há a necessidade de manipular diferentes tipos de dados
 * de forma eficiente. Eles são frequentemente utilizados em:
 *
 *   - Manipulação de strings (onde cada elemento do vetor aponta para uma string),
 *   - Alocação dinâmica de matrizes (em que cada ponteiro pode apontar para um array de tamanho variável),
 *   - Estruturas de dados complexas, como listas encadeadas e árvores, onde os ponteiros referenciam
 *     nós ou elementos em diferentes partes da memória.
 *
 * Usar um vetor de ponteiros oferece flexibilidade ao trabalhar com dados dinâmicos e estruturados,
 * permitindo acessar e modificar dados de maneira eficiente.
 */

int main(int argc, char **argv)
{
    // Declarando um vetor de inteiros
    int valores[5] = {10, 20, 30, 40, 50};

    // Obtém o tamanho do vetor de valores
    size_t tamArrayValores = sizeof(valores) / sizeof(valores[0]);

    // Seção: Imprimindo os endereços dos elementos no vetor de inteiros
    printf("\n\t=== Vetor de Inteiros ===\n");

    for (int i = 0; i < tamArrayValores; i++)
    {
        printf("Elemento [%d]\tEndereço: %p\n", i, (void *)&valores[i]);
    }

    printf("\n=============================================================================\n");

    // Declarando um vetor de ponteiros para inteiros
    int *ponteiros[5];

    // Obtém o tamanho do vetor de ponteiros
    size_t tamanhoDoVetorDePonteiros = sizeof(ponteiros) / sizeof(ponteiros[0]);

    // Preenchendo o vetor de ponteiros com os endereços dos elementos do vetor de inteiros
    for (int i = 0; i < tamanhoDoVetorDePonteiros; i++)
    {
        ponteiros[i] = &valores[i];
    }

    // Seção: Imprimindo os endereços armazenados no vetor de ponteiros
    printf("\n\t=== Vetor de Ponteiros ===\n");

    for (int i = 0; i < tamanhoDoVetorDePonteiros; i++)
    {
        printf("Endereço do Ponteiro: %p\tEndereço Apontado: %p\n", (void *)&ponteiros[i], (void *)ponteiros[i]);
    }

    printf("\n=============================================================================\n");

    // Seção: Imprimindo formas diferentes de vetores de ponteiros
    printf("\n\t=== Imprimindo Formas Diferentes os Vetores de Ponteiros ===\n");

    for (int i = 0; i < tamanhoDoVetorDePonteiros; i++)
    {
        printf("Elemento [%d]: %d\t", i, *ponteiros[i]);
        printf("Elemento [%d]: %d\t", i, *(ponteiros[i]));
        printf("Elemento [%d]: %p-%d\t", i, (void *)&ponteiros[i], *(ponteiros + i));
        printf("Elemento [%d]: %d\n", i, *(*ponteiros + i));
    }
    return 0;
}
