#include <stdio.h>

int main(int argc, char **argv)
{
    printf("\n\tINFORMAÇÕES SOBRE VET\n");

    // Declarando e inicializando um vetor de inteiros
    int vet[5] = {5, 3, 4, 0, 7};

    // Obtendo o tamanho do vetor
    size_t tamanho = sizeof(vet) / sizeof(vet[0]);

    // Informações gerais sobre o vetor e seu endereço base
    printf("\n ENDEREÇO DE 'vet' : %p\n", (void *)vet);
    printf(" CONTEÚDO DE 'vet' : %p\n", (void *)vet);

    printf("\n ENDEREÇO DE 'vet' : %p\n", &vet);
    printf(" CONTEÚDO DE 'vet' : %p\n", &vet[0]);
    // 'vet' e '&vet' são equivalentes quando usados em contextos que esperam um endereço
    // de memória Imprime o endereço base do vetor (mesmo que &vet seja tecnicamente o
    // endereço do vetor como um bloco)

    printf("\n=======================================\n");

    // Imprimindo valores e endereços dos elementos do vetor usando o índice
    for (int i = 0; i < tamanho; i++)
    {
        // Imprime o índice, o valor do elemento e o endereço do elemento
        printf(" Elemento [%d]:\tVALOR: %d\tEndereço: %p\n", i, vet[i], (void *)&vet[i]);
    }

    printf("\n=======================================\n");

    // Imprimindo os valores e endereços dos elementos do vetor usando o índice
    printf("\n (vet[i]):\n");
    for (int i = 0; i < tamanho; i++)
    {
        // Imprime o valor do elemento vet[i] e o endereço desse elemento
        // 'vet[i]' acessa o valor do i-ésimo elemento do vetor
        // '(void *)&vet[i]' imprime o endereço do i-ésimo elemento do vetor
        // 'vet[i]' é equivalente a *(vet + i), onde 'vet + i' é o
        // endereço do i-ésimo elemento e '*' acessa o valor
        printf(" %d - %p\n", vet[i], (void *)&vet[i]);
    }

    printf("\n=======================================\n");

    // Imprimindo valores e endereços dos elementos do vetor usando aritmética de ponteiros
    printf("\n *(vet + i):\n");

    for (int i = 0; i < tamanho; i++)
    {
        // *(vet + i) acessa o valor do i-ésimo elemento do vetor
        // vet + i fornece o endereço do i-ésimo elemento do vetor
        printf(" %d - %p\n", *(vet + i), (void *)(vet + i));
    }

    printf("\n=======================================\n");

    // Imprimindo apenas endereços dos elementos do vetor usando aritmética de ponteiros
    printf("\n vet + i:\n");

    for (int i = 0; i < tamanho; i++)
    {
        // vet + i fornece o endereço do i-ésimo elemento do vetor
        printf(" %p\n", (void *)(vet + i));
    }

    printf("\n=======================================\n");

    // Imprimindo valores usando *vet + i
    printf("\n *vet + i:\n");

    for (int i = 0; i < tamanho; i++)
    {
        // *vet + i é a soma do valor do primeiro elemento do vetor com i
        // Este código não imprime o valor correto do vetor, mas demonstra a operação
        printf(" %d - %p\n", *vet + i, (void *)&vet[i]);
    }
    return 0;
}
