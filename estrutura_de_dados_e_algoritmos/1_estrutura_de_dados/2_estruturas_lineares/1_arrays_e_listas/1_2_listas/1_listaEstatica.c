#include <stdio.h>
#include <stdbool.h>

#define MAXLISTA 10

/**
 * @brief Estrutura da lista estática.
 */
typedef struct list
{
    int dados[MAXLISTA]; ///< Array para armazenar os dados da lista.
    size_t tamanho;      ///< Quantidade de elementos na lista.
} lista;

/**
 * @brief Inicializa a lista, definindo seu tamanho como 0.
 *
 * @param l Ponteiro para a lista a ser inicializada.
 */
void iniciarLista(lista *l) { l->tamanho = 0; }

/**
 * @brief Adiciona um elemento à lista.
 *
 * @param l Ponteiro para a lista.
 * @param elemento Valor a ser adicionado.
 * @note Se a lista estiver cheia, uma mensagem de erro é exibida.
 */
void adicionarElemento(lista *l, int elemento)
{
    if (l->tamanho < MAXLISTA)
    {
        l->dados[l->tamanho++] = elemento;
    }
    else
    {
        printf("Erro: Lista cheia. Não é possível adicionar mais elementos.\n");
    }
}

/**
 * @brief Remove um elemento da lista pelo índice.
 *
 * @param l Ponteiro para a lista.
 * @param indice Índice do elemento a ser removido.
 * @note Se o índice for inválido, uma mensagem de erro é exibida.
 */
void removerElemento(lista *l, size_t indice)
{
    if (indice >= l->tamanho)
    {
        printf("\nErro: Índice fora dos limites. Não é possível remover o elemento.\n");
        return;
    }

    // Desloca os elementos posteriores para preencher o espaço
    for (size_t i = indice; i < l->tamanho - 1; i++)
    {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
}

/**
 * @brief Busca um elemento na lista por busca linear.
 *
 * @param l Ponteiro para a lista.
 * @param elemento Valor a ser buscado.
 * @return true se o elemento for encontrado, false caso contrário.
 */
bool buscarElemento(lista *l, int elemento)
{
    for (size_t i = 0; i < l->tamanho; i++)
    {
        if (l->dados[i] == elemento)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Exibe os elementos da lista.
 *
 * @param l Ponteiro para a lista.
 */
void exibirLista(lista *l)
{
    printf("[");
    for (size_t i = 0; i < l->tamanho; i++)
    {
        printf("%d ", l->dados[i]);
    }
    printf("]\n");
}

int main(int argc, char **argv)
{
    lista l;

    // Inicializa a lista
    iniciarLista(&l);

    // Adiciona elementos à lista
    adicionarElemento(&l, 10);
    adicionarElemento(&l, 12);
    adicionarElemento(&l, 14);
    adicionarElemento(&l, 16);
    adicionarElemento(&l, 18);
    adicionarElemento(&l, 20);
    adicionarElemento(&l, 22);
    adicionarElemento(&l, 24);
    adicionarElemento(&l, 26);
    adicionarElemento(&l, 28);

    // Exibe a lista após adicionar elementos
    printf("Lista após adicionar elementos:\n");
    exibirLista(&l);

    // Remove um elemento da lista (índice 2)
    removerElemento(&l, 2);

    printf("\nLista após remover o elemento no índice 2:\n");
    exibirLista(&l);

    // Testando a busca por elementos
    printf("\n1º Busca por elementos:\n");
    printf("Elemento 16 encontrado? %s\n", buscarElemento(&l, 16) ? "Sim" : "Não");
    printf("Elemento 30 encontrado? %s\n", buscarElemento(&l, 30) ? "Sim" : "Não");

    // Tenta adicionar um elemento a mais (lista cheia)
    adicionarElemento(&l, 30);

    printf("\n2º Busca por elementos:\n");
    printf("Elemento 16 encontrado? %s\n", buscarElemento(&l, 16) ? "Sim" : "Não");
    printf("Elemento 30 encontrado? %s\n", buscarElemento(&l, 30) ? "Sim" : "Não");

    // Tenta remover um elemento com índice inválido
    removerElemento(&l, 20);
    return 0;
}
