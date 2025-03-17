#include <stdio.h>

/*
 * vetor de ponteiros: É um array em que cada elemento é um endereço. Isso significa que
 * cada elemento do vetor armazena o endereço de memória de alguma variável ou dado
 * específico de preferência outro vetor. Em C, um vetor de ponteiros pode ser utilizado
 * para apontar para outros arrays, strings, ou qualquer outra estrutura de dados que pode
 * ser referenciada por meio de ponteiros. Vetores de ponteiros podem ser úteis em situações
 * em que você precisa manusear um conjunto de dados que pode ser referenciado por ponteiros.
 * Eles são comumente usados em manipulação de strings, matrizes dinâmicas, e outras estruturas
 * de dados complexas em C.
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

    /*
     * ponteiros é um vetor de ponteiros para inteiros. Cada elemento de ponteiros é um
     * ponteiro que armazena o endereço de um elemento correspondente no vetor valores.
     * O loop preenche o vetor de ponteiros com os endereços dos elementos do vetor de
     * inteiros, e outro loop imprime os valores dos elementos do vetor de inteiros
     * acessando-os através dos ponteiros.
     */
    return 0;
}
