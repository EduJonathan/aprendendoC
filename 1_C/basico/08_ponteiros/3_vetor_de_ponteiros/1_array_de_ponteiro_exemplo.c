#include <stdio.h>

/*
 * Vetor de ponteiros:
 *
 * Um vetor de ponteiros é um array cujos elementos são ponteiros. Cada posição armazena
 * um endereço de memória, podendo apontar para variáveis, strings, arrays ou estruturas.
 * Isso permite que cada elemento do vetor referencie diferentes regiões da memória.
 *
 * Vetores de ponteiros são úteis quando é necessário manipular dados de forma flexível
 * e dinâmica. Eles permitem que cada elemento tenha tamanhos ou estruturas diferentes,
 * já que cada ponteiro pode apontar para áreas distintas.
 *
 * Exemplos de uso comuns:
 * - Manipulação de strings: cada elemento aponta para uma string diferente.
 * - Matrizes dinâmicas: cada ponteiro pode apontar para um array de tamanho variável.
 * - Estruturas de dados complexas (listas, árvores, grafos): ponteiros para nós espalhados
 *   pela memória.
 *
 * Em resumo, vetores de ponteiros fornecem flexibilidade e eficiência ao lidar com dados
 * dinâmicos e estruturas heterogêneas.
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
    int *ponteiros[5] = {NULL, NULL, NULL, NULL, NULL};

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
