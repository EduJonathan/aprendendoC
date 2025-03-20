#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura de um item da lista (armazena um ponteiro para qualquer tipo).
 *
 * Lista: Estrutura de dados usadas para armazenar coleções de elementos, Uma lista
 * geralmente se refere a uma lista dinâmica implementada com um array, Os dados são
 * armazenados em um único bloco contíguo de memória. Isso significa que todos os
 * elementos estão localizados em locais de memória sequenciais.
 */
typedef struct item
{
    void *dado; ///< Ponteiro genérico para o dado.
    char tipo;  ///< Tipo do dado ('i' para int, 'c' para char, 's' para string, 'f' para float).
} Item;

/**
 * @brief Estrutura da lista dinâmica.
 */
typedef struct lista
{
    Item *itens;    ///< Array dinâmico de itens.
    int tamanho;    ///< Quantidade de elementos na lista.
    int capacidade; ///< Capacidade máxima da lista.
} ListaDinamica;

/**
 * @brief Inicializa a lista com uma capacidade inicial.
 *
 * @param lista Ponteiro para a lista a ser inicializada.
 * @param capacidade Capacidade inicial da lista.
 * @note Se a alocação de memória falhar, o programa é encerrado.
 */
void inicializar(ListaDinamica *lista, int capacidade)
{
    lista->itens = (Item *)malloc(capacidade * sizeof(Item));

    if (lista->itens == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    lista->tamanho = 0;
    lista->capacidade = capacidade;
}

/**
 * @brief Redimensiona a lista quando atinge a capacidade máxima.
 *
 * @param lista Ponteiro para a lista a ser redimensionada.
 * @note A capacidade é dobrada. Se a realocação de memória falhar, o programa é encerrado.
 */
void redimensionar(ListaDinamica *lista)
{
    lista->capacidade *= 2;
    lista->itens = (Item *)realloc(lista->itens, lista->capacidade * sizeof(Item));

    if (lista->itens == NULL)
    {
        fprintf(stderr, "Falha na realocação de memória\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Adiciona um inteiro à lista.
 *
 * @param lista Ponteiro para a lista.
 * @param valor Valor inteiro a ser adicionado.
 */
void adicionarInt(ListaDinamica *lista, int valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        redimensionar(lista);
    }

    lista->itens[lista->tamanho].dado = malloc(sizeof(int));

    if (lista->itens[lista->tamanho].dado == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    *((int *)lista->itens[lista->tamanho].dado) = valor;
    lista->itens[lista->tamanho].tipo = 'i';
    lista->tamanho++;
}

/**
 * @brief Adiciona um caractere à lista.
 *
 * @param lista Ponteiro para a lista.
 * @param valor Caractere a ser adicionado.
 */
void adicionarChar(ListaDinamica *lista, char valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        redimensionar(lista);
    }

    lista->itens[lista->tamanho].dado = malloc(sizeof(char));

    if (lista->itens[lista->tamanho].dado == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    *((char *)lista->itens[lista->tamanho].dado) = valor;
    lista->itens[lista->tamanho].tipo = 'c';
    lista->tamanho++;
}

/**
 * @brief Adiciona uma string à lista.
 *
 * @param lista Ponteiro para a lista.
 * @param valor String a ser adicionada.
 */
void adicionarString(ListaDinamica *lista, char *valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        redimensionar(lista);
    }

    lista->itens[lista->tamanho].dado = malloc(strlen(valor) + 1);

    if (lista->itens[lista->tamanho].dado == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    strcpy((char *)lista->itens[lista->tamanho].dado, valor);
    lista->itens[lista->tamanho].tipo = 's';
    lista->tamanho++;
}

/**
 * @brief Adiciona um float à lista.
 *
 * @param lista Ponteiro para a lista.
 * @param valor Valor float a ser adicionado.
 */
void adicionarFloat(ListaDinamica *lista, float valor)
{
    if (lista->tamanho == lista->capacidade)
    {
        redimensionar(lista);
    }

    lista->itens[lista->tamanho].dado = malloc(sizeof(float));

    if (lista->itens[lista->tamanho].dado == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    *((float *)lista->itens[lista->tamanho].dado) = valor;
    lista->itens[lista->tamanho].tipo = 'f';
    lista->tamanho++;
}

/**
 * @brief Remove um item da lista pelo índice.
 *
 * @param lista Ponteiro para a lista.
 * @param indice Índice do item a ser removido.
 * @note Se o índice for inválido, uma mensagem de erro é exibida.
 */
void removerItem(ListaDinamica *lista, int indice)
{
    if (indice < 0 || indice >= lista->tamanho)
    {
        fprintf(stderr, "Índice fora dos limites\n");
        return;
    }

    // Libera a memória do dado do item a ser removido
    free(lista->itens[indice].dado);

    // Desloca os itens posteriores para preencher o espaço
    for (int i = indice; i < lista->tamanho - 1; i++)
    {
        lista->itens[i] = lista->itens[i + 1];
    }

    lista->tamanho--;
}

/**
 * @brief Imprime os itens da lista.
 *
 * @param lista Ponteiro para a lista.
 */
void imprimirLista(ListaDinamica *lista)
{
    printf("[");
    for (int i = 0; i < lista->tamanho; i++)
    {
        switch (lista->itens[i].tipo)
        {
        case 'i':
            printf("%d, ", *((int *)lista->itens[i].dado));
            break;

        case 'c':
            printf("'%c', ", *((char *)lista->itens[i].dado));
            break;

        case 's':
            printf("\"%s\", ", (char *)lista->itens[i].dado);
            break;

        case 'f':
            printf("%.2f, ", *((float *)lista->itens[i].dado));
            break;
        }
    }
    printf("]\n");
}

/**
 * @brief Libera a memória alocada para a lista.
 *
 * @param lista Ponteiro para a lista.
 */
void liberar(ListaDinamica *lista)
{
    for (int i = 0; i < lista->tamanho; i++)
    {
        free(lista->itens[i].dado);
    }
    free(lista->itens);
}

int main(int argc, char **argv)
{
    ListaDinamica lista;
    inicializar(&lista, 2); // Começa com capacidade 2

    adicionarInt(&lista, 12);
    adicionarChar(&lista, 'c');
    adicionarString(&lista, "strings");
    adicionarFloat(&lista, 3.14);
    adicionarString(&lista, "Eduardo");

    printf("Lista após adições:\n");
    imprimirLista(&lista);

    removerItem(&lista, 1); // Remove o item no índice 1 ('c')
    printf("\nLista após remoção do índice 1:\n");
    imprimirLista(&lista);

    removerItem(&lista, 2); // Remove o item no índice 1 ('c')
    printf("\nLista após remoção do índice 1:\n");
    imprimirLista(&lista);

    liberar(&lista); // Libera a memória

    return 0;
}
