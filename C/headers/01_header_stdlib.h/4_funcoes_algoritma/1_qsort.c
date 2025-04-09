#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para armazenar o nome e o ID.
 *
 * A estrutura `nome` contém o nome (um array de caracteres) e um identificador (ID).
 */
struct nome
{
    char nome[100]; /**< Nome da pessoa, com tamanho fixo de 100 caracteres */
    int id;         /**< ID associado ao nome */
};

/**
 * @brief Função de comparação para ordenar inteiros de forma decrescente.
 *
 * Compara dois inteiros para a função `qsort`. A função retorna um valor negativo,
 * zero ou positivo dependendo da comparação entre os inteiros.
 *
 * @param a1 Ponteiro para o primeiro valor a ser comparado.
 * @param b2 Ponteiro para o segundo valor a ser comparado.
 * @return Um valor negativo, zero ou positivo, conforme os critérios de comparação.
 */
int intCall(const void *a1, const void *b2)
{
    const int *a = (const int *)a1;
    const int *b = (const int *)b2;

    if (*a < *b)
    {
        return 1; /**< Ordem decrescente: primeiro valor é maior */
    }
    else if (*a == *b)
    {
        return 0; /**< Os valores são iguais */
    }
    return -1; /**< Ordem decrescente: segundo valor é maior */
}

/**
 * @brief Função de comparação para ordenar nomes de forma alfabética.
 *
 * Compara dois nomes (strings) para a função `qsort`. A comparação é feita
 * utilizando a função `strcmp`, que retorna um valor baseado na ordem alfabética.
 *
 * @param a1 Ponteiro para o primeiro elemento da estrutura `nome`.
 * @param b2 Ponteiro para o segundo elemento da estrutura `nome`.
 * @return Um valor negativo, zero ou positivo, conforme a ordem alfabética dos nomes.
 */
int stringCall(const void *a1, const void *b2)
{
    const struct nome *a = (const struct nome *)a1;
    const struct nome *b = (const struct nome *)b2;
    return strcmp(a->nome, b->nome); /**< Compara os nomes de forma alfabética */
}

int main(int argc, char **argv)
{
    int array[5] = {50, 40, 30, 60, 20}; /**< Array de inteiros para ordenação */
    struct nome nomes[5];                /**< Array de estruturas `nome` */

    // Usando `strncpy` para copiar os nomes, garantindo que não ocorra overflow
    strncpy(nomes[0].nome, "eduardo", sizeof(nomes[0].nome) - 1);
    nomes[0].nome[sizeof(nomes[0].nome) - 1] = '\0'; /**< Garantir terminação nula */
    nomes[0].id = 1;

    strncpy(nomes[1].nome, "jonathan", sizeof(nomes[1].nome) - 1);
    nomes[1].nome[sizeof(nomes[1].nome) - 1] = '\0';
    nomes[1].id = 2;

    strncpy(nomes[2].nome, "maria", sizeof(nomes[2].nome) - 1);
    nomes[2].nome[sizeof(nomes[2].nome) - 1] = '\0';
    nomes[2].id = 3;

    strncpy(nomes[3].nome, "joao", sizeof(nomes[3].nome) - 1);
    nomes[3].nome[sizeof(nomes[3].nome) - 1] = '\0';
    nomes[3].id = 4;

    strncpy(nomes[4].nome, "pedro", sizeof(nomes[4].nome) - 1);
    nomes[4].nome[sizeof(nomes[4].nome) - 1] = '\0';
    nomes[4].id = 5;

    // Ordenando o array de inteiros de forma decrescente
    qsort(array, 5, sizeof(int), intCall);

    // Ordenando o array de estruturas `nome` em ordem alfabética
    qsort(nomes, 5, sizeof(struct nome), stringCall);

    // Imprimindo o array de inteiros ordenado em ordem decrescente
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n-------------------\n");

    // Imprimindo o array de estruturas `nome` ordenado
    for (int i = 0; i < 5; i++)
    {
        printf("%s | %d\n", nomes[i].nome, nomes[i].id);
    }

    return 0;
}
