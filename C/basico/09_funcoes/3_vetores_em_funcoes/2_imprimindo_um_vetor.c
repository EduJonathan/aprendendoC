#include <stdio.h>

/*
 * Neste código demonstro que o ponteiro aponta para o primeiro endereço de memória
 * de um vetor e o que acontece em derividas formas de pecorrer o vetor utilizando.
 */

/**
 * @brief Imprime informações sobre os elementos de um vetor de inteiros.
 *
 * Este procedimento percorre um vetor de inteiros e imprime o valor e o endereço
 * de cada elemento. A procedimento usa ponteiros para acessar e manipular os elementos
 * do vetor.
 *
 * @param vetor Ponteiro para o início do vetor de inteiros.
 * @param tamanho O número de elementos no vetor.
 *
 * @note Esta procedimento assume que o ponteiro `vetor` não é NULL e que o tamanho
 * é um valor positivo.
 */
void imprime_vetor(int *vetor, size_t tamanho)
{
    // Verifica se o ponteiro para o vetor é NULL
    if (vetor == NULL)
    {
        printf("Erro: ponteiro para o vetor é NULL.\n");
        return;
    }

    // Informações sobre a função e o ponteiro
    printf("\n\tINFORMAÇÕES SOBRE A FUNÇÃO: 'imprime_vetor'\n");
    printf(" ENDEREÇO DE '*vetor' : %p\n", (void *)&vetor);
    printf(" CONTEÚDO DE '*vetor' : %p\n", (void *)vetor);

    // Imprimindo os valores dos elementos do vetor usando vetor[i] e seus endereços
    printf("\n (vetor[i]):\n");

    // Imprimindo através vetor[i] == *(vetor + i)
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d - %p\n", vetor[i], (void *)&vetor[i]);
    }

    // vetor[i]: A forma mais comum de imprimir os endereços de memória

    printf("\n===========================================================\n");

    // Imprimindo os valores dos elementos do vetor usando *(vetor + i) e seus endereços
    printf("\n *(vetor + i):\n");

    // Imprimindo através vetor[i] == *(vetor + i)
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d - %p\n", *(vetor + i), (void *)&vetor[i]);
    }

    // Este trecho está correto e imprime os valores do vetor usando aritmética de ponteiros. Aqui,
    // *(vetor + i) está acessando os elementos do vetor corretamente.

    printf("\n=============================================================\n");

    // Imprimindo os endereços dos elementos do vetor usando vetor + i
    printf("\n vetor + i:\n");

    // Imprimindo vetor[i] = *vetor + i
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d - %p\n", vetor + i, (void *)&vetor[i]);
    }

    // vetor + i: imprimimos o endereço apontado por vetor somado a i. Aqui, vetor aponta
    // para o primeiro elemento do vetor, e ao adicionar i, você está, na verdade,
    // movendo-se pelos endereços dos elementos do vetor. Isso é equivalente a acessar
    // os elementos do vetor usando aritmética de ponteiros.

    printf("\n===============================================================\n");

    // Imprimindo os valores incorretos dos elementos do vetor usando *vetor + i
    printf("\n *vetor + i:\n");

    // Imprimindo através vetor[i] = *vetor + i
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %d - %p\n", *vetor + i, (void *)&vetor[i]);
    }

    // *vetor + i: imprimimos o valor apontado por vetor somado a i. Aqui, *vetor aponta
    // para o primeiro elemento do vetor, e ao adicionar i, você está, na verdade,
    // movendo-se pelos valores, não pelos endereços. Isso não é equivalente a acessar os
    // elementos do vetor.

    printf("\n===============================================================\n");
}

int main(int argc, char **argv)
{
    // Declarando e inicializando um vetor de inteiros
    int vet[5] = {5, 3, 4, 0, 7};

    // Obtendo o tamanho do vetor
    size_t tamanho = sizeof(vet) / sizeof(vet[0]);

    // Imprimindo informações adicionais da main
    printf("\n\tINFORMAÇÕES SOBRE A FUNÇÃO: 'main'\n");

    // Imprimindo atributos do vetor e seus endereços e seus valores
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento [%d]\tVALOR: %d\tEndereço: %p\n", i, vet[i], (void *)&vet[i]);
    }

    // Chamando a função para imprimir as informações sobre o vetor
    imprime_vetor(vet, tamanho);
    return 0;
}
