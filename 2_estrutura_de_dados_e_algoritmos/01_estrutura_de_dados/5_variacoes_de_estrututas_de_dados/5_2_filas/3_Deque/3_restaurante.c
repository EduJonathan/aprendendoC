#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct pedido
{
    int id;
    char cliente[50];
    bool is_vip;
    struct pedido *prox;
    struct pedido *ant;
} Pedido;

typedef struct
{
    Pedido *inicio;
    Pedido *fim;
    int size;
} Deque;

/**
 * @brief Inicializa um deque vazio.
 *
 * @param dq Ponteiro para o deque.
 */
void inicializar(Deque *dq)
{
    if (dq == NULL)
        return;
    dq->inicio = NULL;
    dq->fim = NULL;
    dq->size = 0;
}

/**
 * @brief Verifica se o deque está vazio.
 *
 * @param dq Ponteiro para o deque.
 * @return 1 se vazio, 0 caso contrário.
 */
int esta_vazio(Deque *dq)
{
    if (dq == NULL)
        return 1;
    return dq->size == 0;
}

/**
 * @brief Verifica se um ID já existe no deque.
 *
 * @param dq Ponteiro para o deque.
 * @param id ID a ser verificado.
 * @return true se o ID existe, false caso contrário.
 */
bool id_existe(Deque *dq, int id)
{
    if (dq == NULL || esta_vazio(dq))
        return false;

    Pedido *atual = dq->inicio;
    while (atual != NULL)
    {
        if (atual->id == id)
            return true;
        atual = atual->prox;
    }
    return false;
}

/**
 * @brief Cria um novo pedido.
 *
 * @param id Identificador do pedido.
 * @param cliente Nome do cliente.
 * @param is_vip true para VIP, false para comum.
 * @return Ponteiro para o novo pedido ou NULL em caso de erro.
 */
Pedido *criar_pedido(int id, char *cliente, bool is_vip)
{
    if (cliente == NULL || strlen(cliente) >= 50)
    {
        printf("Erro: Nome do cliente inválido ou muito longo.\n");
        return NULL;
    }

    Pedido *novo = malloc(sizeof(Pedido));
    if (novo == NULL)
    {
        perror("Erro ao alocar memória para o pedido");
        return NULL;
    }
    novo->id = id;
    strncpy(novo->cliente, cliente, 49);
    novo->cliente[49] = '\0';
    novo->is_vip = is_vip;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

/**
 * @brief Insere um pedido no deque (VIP no início, comum no fim).
 *
 * @param dq Ponteiro para o deque.
 * @param id ID do pedido.
 * @param cliente Nome do cliente.
 * @param is_vip true para VIP, false para comum.
 */
void inserir(Deque *dq, int id, char *cliente, bool is_vip)
{
    if (dq == NULL)
    {
        printf("Erro: Ponteiro para deque é NULL.\n");
        return;
    }

    if (id_existe(dq, id))
    {
        printf("Erro: ID %d já existe.\n", id);
        return;
    }

    Pedido *novo = criar_pedido(id, cliente, is_vip);
    if (novo == NULL)
        return;

    if (is_vip)
    {
        Pedido *atual = dq->inicio;
        while (atual != NULL && atual->is_vip)
        {
            atual = atual->prox;
        }

        if (atual == NULL)
        {
            // Inserir no fim
            if (esta_vazio(dq))
            {
                dq->inicio = novo;
                dq->fim = novo;
            }
            else
            {
                novo->ant = dq->fim;
                dq->fim->prox = novo;
                dq->fim = novo;
            }
        }
        else if (atual == dq->inicio)
        {
            // Inserir no início
            novo->prox = dq->inicio;
            dq->inicio->ant = novo;
            dq->inicio = novo;
        }
        else
        { 
            // Inserir antes de atual
            novo->prox = atual;
            novo->ant = atual->ant;
            atual->ant->prox = novo;
            atual->ant = novo;
        }
    }
    else
    {
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
    }
    dq->size++;
}

/**
 * @brief Remove e retorna o primeiro pedido do deque.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido removido ou NULL se vazio.
 */
Pedido *remover_inicio(Deque *dq)
{
    if (dq == NULL || esta_vazio(dq))
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

    dq->size--;
    return temp;
}

/**
 * @brief Remove e retorna o último pedido do deque.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido removido ou NULL se vazio.
 */
Pedido *remover_fim(Deque *dq)
{
    if (dq == NULL || esta_vazio(dq))
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

    dq->size--;
    return temp;
}

/**
 * @brief Consulta o primeiro pedido sem removê-lo.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido ou NULL se vazio.
 */
Pedido *peek_inicio(Deque *dq)
{
    if (dq == NULL || esta_vazio(dq))
    {
        printf("Deque está vazio.\n");
        return NULL;
    }
    return dq->inicio;
}

/**
 * @brief Consulta o último pedido sem removê-lo.
 *
 * @param dq Ponteiro para o deque.
 * @return Ponteiro para o pedido ou NULL se vazio.
 */
Pedido *peek_fim(Deque *dq)
{
    if (dq == NULL || esta_vazio(dq))
    {
        printf("Deque está vazio.\n");
        return NULL;
    }
    return dq->fim;
}

/**
 * @brief Exibe todos os pedidos no deque.
 *
 * @param dq Ponteiro para o deque.
 */
void exibir_deque(Deque *dq)
{
    if (dq == NULL || esta_vazio(dq))
    {
        printf("Deque está vazio.\n");
        return;
    }
    printf("Pedidos no deque:\n");
    Pedido *atual = dq->inicio;
    while (atual != NULL)
    {
        printf("ID: %d, Cliente: %s, Tipo: %s\n",
               atual->id, atual->cliente, atual->is_vip ? "VIP" : "Comum");
        atual = atual->prox;
    }
}

/**
 * @brief Libera todos os elementos do deque.
 *
 * @param dq Ponteiro para o deque.
 */
void limpar_deque(Deque *dq)
{
    if (dq == NULL)
        return;

    while (!esta_vazio(dq))
    {
        Pedido *p = remover_inicio(dq);
        free(p);
    }
}

int main(int argc, char **argv)
{
    Deque pedidos;

    inicializar(&pedidos);
    inserir(&pedidos, 1, "João", false);
    inserir(&pedidos, 2, "Maria", false);
    inserir(&pedidos, 3, "Carlos", true);
    inserir(&pedidos, 4, "Ana", false);

    exibir_deque(&pedidos);

    printf("\nOrdem de atendimento:\n");
    while (!esta_vazio(&pedidos))
    {
        Pedido *proximo = remover_inicio(&pedidos);
        if (proximo != NULL)
        {
            printf("Pedido %d: %s (%s)\n", proximo->id, proximo->cliente,
                   proximo->is_vip ? "VIP" : "Comum");
            free(proximo);
        }
    }
    limpar_deque(&pedidos);
    return 0;
}
