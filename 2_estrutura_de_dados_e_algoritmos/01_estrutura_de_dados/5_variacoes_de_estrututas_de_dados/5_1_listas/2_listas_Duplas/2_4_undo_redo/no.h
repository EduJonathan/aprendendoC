#ifndef NO_H
#define NO_H

#include "estado.h"

/**
 * @brief Estrutura do nó da lista duplamente encadeada
 */
typedef struct no
{
    Estado estado;       ///< Estado do documento armazenado no nó
    struct no *anterior; ///< Ponteiro para o nó anterior
    struct no *proximo;  ///< Ponteiro para o nó seguinte
} No;

/**
 * @brief Cria um novo nó com o texto especificado
 * 
 * @param texto Texto a ser armazenado no nó
 * @return Ponteiro para o novo nó alocado
 */
No *criarNo(const char *texto);

#endif /* NO_H */
