#ifndef EDITOR_H
#define EDITOR_H

#include "no.h"

/**
 * @brief Estrutura do editor de texto com histórico
 */
typedef struct
{
    No *atual; ///< Nó atual (estado corrente do documento)
} Editor;

/**
 * @brief Cria um novo editor vazio
 * @return Ponteiro para o novo editor alocado
 */
Editor *criarEditor();

/**
 * @brief Adiciona um novo estado ao histórico do editor
 * @param editor Ponteiro para o editor
 * @param texto Texto do novo estado a ser adicionado
 */
void adicionarEstado(Editor *editor, const char *texto);

/**
 * @brief Desfaz a última alteração (undo)
 * @param editor Ponteiro para o editor
 * @return 1 se o undo foi bem-sucedido, 0 caso contrário
 */
int undo(Editor *editor);

/**
 * @brief Refaz a última alteração desfeita (redo)
 * @param editor Ponteiro para o editor
 * @return 1 se o redo foi bem-sucedido, 0 caso contrário
 */
int redo(Editor *editor);

/**
 * @brief Exibe o estado atual do documento
 * @param editor Ponteiro para o editor
 */
void exibirEstado(const Editor *editor);

/**
 * @brief Libera toda a memória alocada para o editor
 * @param editor Ponteiro para o editor a ser liberado
 */
void liberarEditor(Editor *editor);

#endif /* EDITOR_H */
