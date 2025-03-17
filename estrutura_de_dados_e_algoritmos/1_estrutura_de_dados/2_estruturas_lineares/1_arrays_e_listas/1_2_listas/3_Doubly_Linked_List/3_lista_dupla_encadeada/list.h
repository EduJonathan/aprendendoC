#ifndef LIST_H
#define LIST_H

#ifndef _ELEMENTO
#define _ELEMENTO

/**
 * @brief Estrutura que representa um elemento da lista.
 *
 * Cada elemento contém um valor (dado) e ponteiros para o próximo e o anterior elemento.
 */
typedef struct _elemento
{
    int dado;                   /**< Valor armazenado no elemento */
    struct _elemento *proximo;  /**< Ponteiro para o próximo elemento */
    struct _elemento *anterior; /**< Ponteiro para o elemento anterior */
} Elemento;

#endif

#ifndef _LISTA
#define _LISTA

/**
 * @brief Estrutura que representa a lista duplamente encadeada.
 *
 * A lista possui um ponteiro para o primeiro e o último item,
 * além de controlar a quantidade de elementos.
 */
typedef struct _lista
{
    unsigned int quantidade; /**< Quantidade de elementos na lista */
    Elemento *primeiroItem;  /**< Ponteiro para o primeiro elemento da lista */
    Elemento *ultimoItem;    /**< Ponteiro para o último elemento da lista */
} Lista;

#endif

/**
 * @brief Cria uma nova lista vazia.
 *
 * Aloca memória para a lista e inicializa os seus atributos.
 *
 * @return Ponteiro para a lista recém-criada.
 */
Lista *criarLista(void);

/**
 * @brief Adiciona um novo elemento ao final da lista.
 *
 * Cria um novo elemento e o insere no final da lista. Atualiza os ponteiros
 * para o último item da lista.
 *
 * @param lista Ponteiro para a lista onde o elemento será inserido.
 * @param dado Valor do elemento a ser adicionado.
 */
void add(Lista *lista, int dado);

/**
 * @brief Imprime os elementos da lista da cabeça para a cauda.
 *
 * Percorre a lista do primeiro para o último elemento e imprime seus valores.
 *
 * @param lista Ponteiro para a lista a ser impressa.
 */
void print(Lista *lista);

/**
 * @brief Imprime os elementos da lista da cauda para a cabeça.
 *
 * Percorre a lista do último para o primeiro elemento e imprime seus valores.
 *
 * @param lista Ponteiro para a lista a ser impressa.
 */
void printReverse(Lista *lista);

/**
 * @brief Libera toda a memória alocada para os elementos da lista.
 *
 * Percorre a lista e libera os elementos, em seguida libera a
 * memória da própria estrutura de lista.
 *
 * @param lista Ponteiro para a lista a ser liberada.
 */
void liberarLista(Lista *lista);

#endif
