#ifndef FUNCOES_IMPRESSORAS_H
#define FUNCOES_IMPRESSORAS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para a função sleep()

/**
 * @brief Estrutura para representar um trabalho de impressão.
 *
 * Esta estrutura armazena as informações relacionadas a um trabalho de impressão,
 * incluindo o tipo do documento, o número total de páginas, o intervalo de páginas
 * a serem impressas e um ponteiro para o próximo trabalho na fila.
 */
typedef struct trabalho
{
    char tipo[50];         /**< Tipo do documento (livro, pdf, foto, etc.) */
    int total_paginas;     /**< Número total de páginas do documento */
    int inicio;            /**< Página inicial a ser impressa */
    int fim;               /**< Página final a ser impressa */
    struct Trabalho *prox; /**< Ponteiro para o próximo trabalho na fila */
} Trabalho;

/**
 * @brief Estrutura para representar a fila de impressão.
 *
 * Esta estrutura contém dois ponteiros, um para a frente e outro para o final da fila,
 * facilitando a manipulação dos trabalhos na fila de impressão.
 */
typedef struct fila
{
    Trabalho *frente; /**< Ponteiro para o trabalho na frente da fila */
    Trabalho *tras;   /**< Ponteiro para o trabalho no final da fila */
} Fila;

/**
 * @brief Função para inicializar a fila de impressão.
 *
 * Inicializa a fila de impressão, configurando os ponteiros de frente e trás como NULL,
 * indicando que a fila está vazia.
 *
 * @param fila Ponteiro para a fila de impressão a ser inicializada.
 */
void inicializarFila(Fila *fila)
{
    fila->frente = NULL;
    fila->tras = NULL;
}

/**
 * @brief Função para adicionar um trabalho à fila de impressão.
 *
 * Adiciona um novo trabalho à fila de impressão, configurando as informações do
 * trabalho, como tipo do documento, número de páginas e intervalo de páginas a serem
 * impressas.
 *
 * @param fila Ponteiro para a fila de impressão.
 * @param tipo Tipo do documento (livro, pdf, foto, etc.).
 * @param total_paginas Número total de páginas do documento.
 * @param inicio Página inicial a ser impressa.
 * @param fim Página final a ser impressa.
 */
void adicionarTrabalho(Fila *fila, char *tipo, int total_paginas, int inicio, int fim)
{
    Trabalho *novo = (Trabalho *)malloc(sizeof(Trabalho));

    if (!novo)
    {
        printf("Erro ao alocar memória!\n");
        return;
    }

    snprintf(novo->tipo, sizeof(novo->tipo), "%s", tipo);
    novo->total_paginas = total_paginas;
    novo->inicio = inicio;
    novo->fim = fim;
    novo->prox = NULL;

    if (fila->tras == NULL)
    {
        fila->frente = novo;
        fila->tras = novo;
    }
    else
    {
        fila->tras->prox = novo;
        fila->tras = novo;
    }
    printf("Trabalho de impressão adicionado: %s (%d páginas)\n", tipo, total_paginas);
}

/**
 * @brief Função para imprimir um intervalo de páginas de um trabalho.
 *
 * Esta função imprime as páginas de um trabalho dentro do intervalo especificado
 * (inicio até fim), simulando o tempo de impressão com a função `sleep`.
 *
 * @param fila Ponteiro para a fila de impressão.
 */
void imprimir_intervalo(Fila *fila)
{
    if (fila->frente == NULL)
    {
        printf("Fila de impressão vazia!\n");
        return;
    }

    Trabalho *atual = fila->frente;

    printf("\nImprimindo: %s\n", atual->tipo);
    for (int i = atual->inicio; i <= atual->fim; i++)
    {
        printf("Imprimindo página %d...\n", i);
        sleep(2); // Simula tempo de impressão
    }

    printf("Impressão concluída!\n");

    fila->frente = atual->prox;
    if (fila->frente == NULL)
    {
        fila->tras = NULL;
    }
    free(atual);
}

/**
 * @brief Função para imprimir o documento completo de um trabalho.
 *
 * Esta função imprime todas as páginas de um documento, simulando o tempo de impressão
 * com a função `sleep`.
 *
 * @param fila Ponteiro para a fila de impressão.
 */
void imprimir_tudo(Fila *fila)
{
    if (fila->frente == NULL)
    {
        printf("Fila de impressão vazia!\n");
        return;
    }

    Trabalho *atual = fila->frente;

    printf("\nImprimindo documento completo: %s\n", atual->tipo);
    for (int i = 1; i <= atual->total_paginas; i++)
    {
        printf("Imprimindo página %d...\n", i);
        sleep(2); // Simula tempo de impressão
    }

    printf("Impressão completa!\n");

    fila->frente = atual->prox;
    if (fila->frente == NULL)
    {
        fila->tras = NULL;
    }
    free(atual);
}

#endif
