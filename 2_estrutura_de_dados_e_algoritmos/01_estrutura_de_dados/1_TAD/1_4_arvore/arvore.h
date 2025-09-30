#ifndef ARVORE_H
#define ARVORE_H

/**
 * @brief Estrutura que representa um nó da árvore
 */
struct no
{
    int valor;           /**< Valor armazenado no nó */
    struct no *esquerda; /**< Ponteiro para o filho esquerdo */
    struct no *direita;  /**< Ponteiro para o filho direito */
};

/**
 * @brief Estrutura wrapper para a árvore
 */
struct arvore
{
    struct no **raiz; /**< Ponteiro para o ponteiro da raiz */
};

// Protótipos das funções

/**
 * @brief Cria um novo nó
 * @param valor Valor a ser armazenado no nó
 * @return Ponteiro para o nó criado ou NULL em caso de erro
 */
struct no *criar_no(int valor);

/**
 * @brief Inicializa uma árvore
 * @param a Ponteiro para a estrutura arvore
 * @return 0 em caso de sucesso, -1 em caso de erro
 */
int inicializar_arvore(struct arvore *a);

/**
 * @brief Libera toda a memória da árvore
 * @param raiz Ponteiro para a raiz da árvore
 */
void liberar_arvore(struct no *raiz);

/**
 * @brief Insere um valor na árvore
 * @param raiz Ponteiro para o ponteiro da raiz
 * @param valor Valor a ser inserido
 * @return 0 em caso de sucesso, -1 em caso de erro
 */
int inserir(struct no **raiz, int valor);

/**
 * @brief Remove um valor da árvore
 * @param raiz Ponteiro para o ponteiro da raiz
 * @param valor Valor a ser removido
 * @return 0 em caso de sucesso, -1 se valor não encontrado
 */
int remover(struct no **raiz, int valor);

/**
 * @brief Busca um valor na árvore
 * @param raiz Raiz da árvore
 * @param valor Valor a ser buscado
 * @return Ponteiro para o nó encontrado ou NULL se não encontrado
 */
struct no *buscar(struct no *raiz, int valor);

/**
 * @brief Encontra o nó com valor mínimo na subárvore
 * @param raiz Raiz da subárvore
 * @return Ponteiro para o nó com valor mínimo
 */
struct no *encontrar_minimo(struct no *raiz);

/**
 * @brief Imprime a árvore em ordem
 * @param raiz Raiz da árvore
 */
void imprimir_em_ordem(struct no *raiz);

/**
 * @brief Imprime a árvore em pré-ordem
 * @param raiz Raiz da árvore
 */
void imprimir_pre_ordem(struct no *raiz);

/**
 * @brief Imprime a árvore em pós-ordem
 * @param raiz Raiz da árvore
 */
void imprimir_pos_ordem(struct no *raiz);

#endif // ARVORE_H
