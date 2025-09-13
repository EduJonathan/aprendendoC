#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// @brief Estrutura de um pedido na fila.
typedef struct Pedido
{
    int id;              ///< Identificador do pedido
    char cliente[50];    ///< Nome do cliente
    bool eh_vip;         ///< 1 para VIP, 0 para comum
    struct Pedido *prox; ///< Próximo pedido na fila
    struct Pedido *ant;  ///< Pedido anterior na fila
} Pedido;

/// @brief Estrutura do deque (fila dupla).
typedef struct
{
    Pedido *inicio; ///< Ponteiro para o primeiro pedido
    Pedido *fim;    ///< Ponteiro para o último pedido
    int tamanho;    ///< Número total de pedidos na fila
} Deque;

/**
 * @brief Inicializa um deque vazio.
 *
 * @param dq Ponteiro para o deque a ser inicializado.
 */
void inicializar(Deque *dq)
{
    dq->inicio = NULL;
    dq->fim = NULL;
    dq->tamanho = 0;
}

/**
 * @brief Verifica se o deque está vazio.
 *
 * @param dq Ponteiro para o deque.
 * @return 1 se estiver vazio, 0 caso contrário.
 */
int esta_vazio(Deque *dq)
{
    return (dq->inicio == NULL);
}

/**
 * @brief Cria um novo pedido.
 *
 * @param id Identificador do pedido.
 * @param cliente Nome do cliente.
 * @param eh_vip 1 para VIP, 0 para comum.
 * @return Ponteiro para o novo pedido criado.
 */
Pedido *criar_pedido(int id, char *cliente, bool eh_vip)
{
    Pedido *novo = (Pedido *)malloc(sizeof(Pedido));
    if (novo == NULL)
    {
        perror("Erro ao alocar memória para o pedido");
        exit(EXIT_FAILURE);
    }
    novo->id = id;
    strcpy(novo->cliente, cliente);
    novo->eh_vip = eh_vip;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

/**
 * @brief Insere um pedido no início do deque (usado para pedidos VIP).
 *
 * @param dq Ponteiro para o deque.
 * @param id ID do pedido.
 * @param cliente Nome do cliente.
 * @param eh_vip Flag de VIP (1 para VIP).
 */
void inserir_inicio(Deque *dq, int id, char *cliente, int eh_vip)
{
    Pedido *novo = criar_pedido(id, cliente, eh_vip);
    novo->prox = dq->inicio;

    if (esta_vazio(dq))
    {
        dq->fim = novo;
    }
    else
    {
        dq->inicio->ant = novo;
    }
    dq->inicio = novo;
    dq->tamanho++;
}

/**
 * @brief Insere um pedido no final do deque (usado para pedidos comuns).
 *
 * @param dq Ponteiro para o deque.
 * @param id ID do pedido.
 * @param cliente Nome do cliente.
 * @param eh_vip Flag de VIP (0 para comum).
 */
void inserir_fim(Deque *dq, int id, char *cliente, int eh_vip)
{
    Pedido *novo = criar_pedido(id, cliente, eh_vip);
    novo->ant = dq->fim;

    if (esta_vazio(dq))
    {
        dq->inicio = novo;
    }
    else
    {
        dq->fim->prox = novo;
    }
    dq->fim = novo;
    dq->tamanho++;
}

/**
 * @brief Remove e retorna o primeiro pedido da fila.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido removido, ou NULL se estiver vazio.
 */
Pedido *remover_inicio(Deque *dq)
{
    if (esta_vazio(dq))
        return NULL;

    Pedido *temp = dq->inicio;
    dq->inicio = dq->inicio->prox;

    if (dq->inicio == NULL)
    {
        dq->fim = NULL;
    }
    else
    {
        dq->inicio->ant = NULL;
    }

    dq->tamanho--;
    return temp;
}

/**
 * @brief Remove e retorna o último pedido da fila.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido removido, ou NULL se estiver vazio.
 */
Pedido *remover_fim(Deque *dq)
{
    if (esta_vazio(dq))
        return NULL;

    Pedido *temp = dq->fim;
    dq->fim = dq->fim->ant;

    if (dq->fim == NULL)
    {
        dq->inicio = NULL;
    }
    else
    {
        dq->fim->prox = NULL;
    }

    dq->tamanho--;
    return temp;
}

/**
 * @brief Libera todos os elementos do deque.
 *
 * @param dq Ponteiro para o deque.
 */
void limpar_deque(Deque *dq)
{
    while (!esta_vazio(dq))
    {
        Pedido *p = remover_inicio(dq);
        free(p);
    }
}

int main(int argc, char **argv)
{
    Deque pedidos = {0}; // Inicializa o deque de pedidos
    inicializar(&pedidos);

    // Adicionando pedidos
    inserir_fim(&pedidos, 1, "João", 0);      // Comum
    inserir_fim(&pedidos, 2, "Maria", 0);     // Comum
    inserir_inicio(&pedidos, 3, "Carlos", 1); // VIP
    inserir_fim(&pedidos, 4, "Ana", 0);       // Comum

    // Atendendo pedidos (VIPs primeiro)
    printf("Ordem de atendimento:\n");
    while (!esta_vazio(&pedidos))
    {
        Pedido *proximo = remover_inicio(&pedidos);
        printf("Pedido %d: %s (%s)\n", proximo->id, proximo->cliente,
               proximo->eh_vip ? "VIP" : "Comum");
        free(proximo);
    }
    return 0;
}
