#ifndef DEFINICOES_LISTA_H
#define DEFINICOES_LISTA_H

/**
 * @struct No
 *
 * @brief Estrutura para representar um nó da lista encadeada.
 *
 * Esta estrutura armazena informações sobre um aluno, como sua matrícula e sua nota.
 */
typedef struct No
{
    int mat;         /**< Matrícula do aluno */
    float nota;      /**< Nota do aluno */
    struct No *prox; /**< Ponteiro para o próximo nó na lista */
} no;

no *iniciar_lista(void);
no *insere_lista(no *lista, int matricula, float notas);
void imprime_lista(no *lista);
no *busca(no *lista, int matricula);
no *libera(no *lista);
no *remover(no *lista, int matricula);

#endif
