#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief Enumeração para tipos de eventos na agenda.
 */
typedef enum
{
    TIPO_REUNIAO,            /**< Evento do tipo Reunião. */
    TIPO_LEMBRETE_PAGAMENTO, /**< Evento do tipo Lembrete de Pagamento. */
    TIPO_ANIVERSARIO         /**< Evento do tipo Aniversário. */
} TipoEvento;

/**
 * @brief Struct para eventos do tipo Reunião.
 */
typedef struct
{
    char *titulo;  /**< Título da reunião. */
    char *horario; /**< Horário da reunião. */
} Reuniao;

/**
 * @brief Struct para eventos do tipo Lembrete de Pagamento.
 */
typedef struct
{
    double valor;    /**< Valor do pagamento. */
    char *descricao; /**< Descrição do pagamento. */
} LembretePagamento;

/**
 * @brief Struct para eventos do tipo Aniversário.
 */
typedef struct
{
    char *nome; /**< Nome da pessoa. */
    char *data; /**< Data do aniversário. */
} Aniversario;

/**
 * @brief Struct para nó da lista circular.
 */
typedef struct No
{
    TipoEvento tipo;    /**< Tipo do evento (Reunião, Lembrete, Aniversário). */
    void *dados;        /**< Ponteiro genérico para os dados do evento. */
    int diaSemana;      /**< Dia da semana (0=segunda, 1=terça, ..., 6=domingo). */
    struct No *proximo; /**< Ponteiro para o próximo nó. */
} No;


/**
 * @brief Cria um novo nó para a lista circular.
 *
 * @param tipo Tipo do evento (Reunião, Lembrete, Aniversário).
 * @param dados Ponteiro para os dados do evento.
 * @param diaSemana Dia da semana (0 a 6).
 * @return Ponteiro para o novo nó criado.
 */
No *criarNo(TipoEvento tipo, void *dados, int diaSemana)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Erro: falha na alocação de memória.\n");
        exit(1);
    }
    novo->tipo      = tipo;
    novo->dados     = dados;
    novo->diaSemana = diaSemana;
    novo->proximo   = NULL;
    return novo;
}

/**
 * @brief Insere um nó na lista circular, mantendo a estrutura circular.
 *
 * @param cabeca Ponteiro para o ponteiro da cabeça da lista.
 * @param novo Nó a ser inserido.
 */
void inserirCircular(No **cabeca, No *novo)
{
    if (*cabeca == NULL)
    {
        *cabeca = novo;
        novo->proximo = *cabeca; // Circular: aponta para si mesmo
        return;
    }

    No *temp = *cabeca;

    while (temp->proximo != *cabeca)
    {
        temp = temp->proximo;
    }
    temp->proximo = novo;
    novo->proximo = *cabeca; // Fecha o ciclo
}

/**
 * @brief Imprime a agenda percorrendo a lista circular uma vez.
 *
 * @param cabeca Ponteiro para a cabeça da lista.
 */
void imprimirAgenda(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Agenda vazia.\n");
        return;
    }

    No *temp = cabeca;

    do
    {
        printf("Dia %d: ", temp->diaSemana);
        switch (temp->tipo)
        {
            case TIPO_REUNIAO:
            {
                Reuniao *r = (Reuniao *)temp->dados;
                printf("Reunião - Título: %s, Horário: %s\n", r->titulo, r->horario);
                break;
            }
            case TIPO_LEMBRETE_PAGAMENTO:
            {
                LembretePagamento *lp = (LembretePagamento *)temp->dados;
                printf("Lembrete Pagamento - Valor: %.2f, Descrição: %s\n", lp->valor, lp->descricao);
                break;
            }
            case TIPO_ANIVERSARIO:
            {
                Aniversario *a = (Aniversario *)temp->dados;
                printf("Aniversário - Nome: %s, Data: %s\n", a->nome, a->data);
                break;
            }
        }
        temp = temp->proximo;
    } while (temp != cabeca);
}

/**
 * @brief Libera a memória da lista circular.
 *
 * @param cabeca Ponteiro para a cabeça da lista.
 */
void liberarAgenda(No *cabeca)
{
    if (cabeca == NULL)
        return;

    No *atual   = cabeca;
    No *proximo = NULL;

    // Quebra o ciclo para evitar loop infinito
    No *temp = cabeca;
    while (temp->proximo != cabeca)
    {
        temp = temp->proximo;
    }
    temp->proximo = NULL;

    // Libera cada nó
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(int argc, char **argv)
{
    // Configurar locale para caracteres em português
    setlocale(LC_ALL, "pt_BR.UTF-8");

    No *agenda = NULL;

    // Criar eventos (alocando memória para strings)
    Reuniao *r1 = (Reuniao *)malloc(sizeof(Reuniao));
    r1->titulo  = strdup("Reunião Equipe");
    r1->horario = strdup("09:00");

    LembretePagamento *lp1 = (LembretePagamento *)malloc(sizeof(LembretePagamento));
    lp1->valor             = 100.50;
    lp1->descricao         = strdup("Conta de luz");

    Aniversario *a1 = (Aniversario *)malloc(sizeof(Aniversario));
    a1->nome = strdup("João");
    a1->data = strdup("21/09");

    // Inserir eventos na lista circular
    inserirCircular(&agenda, criarNo(TIPO_REUNIAO, r1, 0));             // Segunda
    inserirCircular(&agenda, criarNo(TIPO_LEMBRETE_PAGAMENTO, lp1, 2)); // Quarta
    inserirCircular(&agenda, criarNo(TIPO_ANIVERSARIO, a1, 6));         // Domingo

    // Imprimir a agenda
    imprimirAgenda(agenda);

    // Liberar memória
    liberarAgenda(agenda);
    free(r1->titulo);
    free(r1->horario);
    free(r1);
    free(lp1->descricao);
    free(lp1);
    free(a1->nome);
    free(a1->data);
    free(a1);

    return 0;
}
