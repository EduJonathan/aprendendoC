#ifndef EVENTOS_H
#define EVENTOS_H

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
No *criarNo(TipoEvento tipo, void *dados, int diaSemana);

/**
 * @brief Insere um nó na lista circular, mantendo a estrutura circular.
 * 
 * @param cabeca Ponteiro para o ponteiro da cabeça da lista.
 * @param novo Nó a ser inserido.
 */
void inserirCircular(No **cabeca, No *novo);

/**
 * @brief Imprime a agenda percorrendo a lista circular uma vez.
 * 
 * @param cabeca Ponteiro para a cabeça da lista.
 */
void imprimirAgenda(No *cabeca);

/**
 * @brief Libera a memória da lista circular.
 * 
 * @param cabeca Ponteiro para a cabeça da lista.
 */
void liberarAgenda(No *cabeca);

#endif // EVENTOS_H
