#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Nó da fila.
 *
 * Cada nó armazena um valor inteiro e um ponteiro para o próximo nó.
 */
typedef struct Node
{
    int valor;         /**< Valor armazenado no nó. */
    struct Node *prox; /**< Ponteiro para o próximo nó. */
} Node;

/**
 * @brief Estrutura que representa a fila.
 *
 * Mantém ponteiros para o primeiro (frente) e o último (trás) elementos.
 */
typedef struct
{
    Node *frente; /**< Ponteiro para o primeiro nó da fila. */
    Node *tras;   /**< Ponteiro para o último nó da fila. */
} Fila;

/**
 * @brief Inicializa uma fila vazia.
 *
 * @param f Ponteiro para a fila a ser inicializada.
 */
void inicializar(Fila *f)
{
    f->frente = f->tras = NULL;
}

/**
 * @brief Insere um elemento no final da fila.
 *
 * @param f Ponteiro para a fila.
 * @param valor Valor inteiro a ser inserido.
 */
void enqueue(Fila *f, int valor)
{
    Node *novo = malloc(sizeof(Node));
    if (!novo)
    {
        printf("Falha ao alocar memória!\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (f->tras == NULL)
    {
        f->frente = f->tras = novo;
    }
    else
    {
        f->tras->prox = novo;
        f->tras = novo;
    }
}

/**
 * @brief Remove um elemento do início da fila.
 *
 * @param f Ponteiro para a fila.
 * @param removido Ponteiro para armazenar o valor removido.
 * @return 1 se um elemento foi removido, 0 se a fila está vazia.
 */
int dequeue(Fila *f, int *removido)
{
    if (f->frente == NULL)
        return 0;
    Node *temp = f->frente;
    *removido = temp->valor;
    f->frente = temp->prox;

    if (f->frente == NULL)
        f->tras = NULL;
    free(temp);
    return 1;
}

/**
 * @brief Exibe os elementos da fila do início ao fim.
 *
 * @param f Cópia da fila a ser exibida (apenas leitura).
 */
void exibir(Fila f)
{
    if (f.frente == NULL)
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila: ");
    for (Node *n = f.frente; n != NULL; n = n->prox)
        printf("%d ", n->valor);
    printf("\n");
}

/**
 * @brief Reverte a ordem dos elementos da fila.
 *
 * @param f Ponteiro para a fila.
 */
void reverter(Fila *f)
{
    Node *prev = NULL, *atual = f->frente, *next = NULL;
    f->tras = f->frente;
    while (atual)
    {
        next = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = next;
    }
    f->frente = prev;
}

/**
 * @brief Ordena a fila em ordem crescente (bubble sort).
 *
 * @param f Ponteiro para a fila.
 */
void ordenar(Fila *f)
{
    if (!f->frente)
        return;
    int trocou = 0;
    do
    {
        trocou = 0;
        Node *a = f->frente;
        while (a->prox)
        {
            if (a->valor > a->prox->valor)
            {
                int tmp = a->valor;
                a->valor = a->prox->valor;
                a->prox->valor = tmp;
                trocou = 1;
            }
            a = a->prox;
        }
    } while (trocou);
}

/**
 * @brief Busca um valor específico na fila.
 *
 * Percorre a fila do início ao fim procurando o valor desejado.
 *
 * @param f Ponteiro para a fila.
 * @param chave Valor a ser procurado.
 * @return 1 se o valor for encontrado, 0 caso contrário.
 */
int buscar(Fila *f, int chave)
{
    for (Node *n = f->frente; n != NULL; n = n->prox)
    {
        if (n->valor == chave)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Libera toda a memória utilizada pela fila.
 *
 * @param f Ponteiro para a fila.
 */
void liberar(Fila *f)
{
    Node *atual = f->frente;
    while (atual)
    {
        Node *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->frente = f->tras = NULL;
}

int main(int argc, char **argv)
{
    Fila f;
    inicializar(&f);
    int opcao = 0, val = 0;

    do
    {
        printf("\n1 - Enqueue\n2 - Dequeue\n3 - Exibir\n4 - Reverter\n5 - Ordenar\n6 - Buscar\n0 - Sair\nEscolha: ");
        if (scanf("%d", &opcao) != 1)
            break;

        switch (opcao)
        {
        case 1:
            printf("Valor a inserir: ");
            scanf("%d", &val);
            enqueue(&f, val);
            break;

        case 2:
            if (dequeue(&f, &val))
                printf("Removido: %d\n", val);
            else
                printf("Fila vazia.\n");
            break;

        case 3:
            exibir(f);
            break;

        case 4:
            reverter(&f);
            printf("Fila revertida.\n");
            break;

        case 5:
            ordenar(&f);
            printf("Fila ordenada.\n");
            break;

        case 6:
            printf("Valor a buscar: ");
            scanf("%d", &val);

            if (buscar(&f, val))
                printf("Valor %d encontrado na fila.\n", val);
            else
                printf("Valor %d NÃO encontrado.\n", val);
            break;

        case 0:
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    liberar(&f);
    return 0;
}
