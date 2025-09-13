#include <stdio.h>
#include <stdbool.h>

/**
 * sets (ou conjunto): É uma estrutura de dados que armazena elementos únicos e permite
 * operações como união, interseção e diferença. Ele é frequentemente usado quando a unidade
 * de dados importa, mas a ordem e duplicação não são importantes.
 * É uma estrutura útil em várias aplicações, como quando é necessário garantir que não
 * haja elementos repetidos ou ao realizar operações envolvendo conjuntos de dados.
 * Os conjuntos podem ser representados por arrays ou listas encadeadas.
 * Conjuntos também podem ser implementados usando estruturas de dados como hash tables.
 *
 * OPERAÇÕES
 * (inserção: Adicionar um elemento ao conjunto,
 * exclusão: Remover um elemento do conjunto,
 * busca: Verificar se um determinado elemento existe no conjunto,
 * união: Combina os elementos de dois conjuntos,
 * interseção: Retorna os elementos que estão em ambos os conjuntos,
 * diferença: Retorna os elementos que estão em um conjunto mas não no outro.
 * e diferença simetrica: Retorna os elementos que estão em um dos conjuntos, mas não em ambos).
 */

#define MAX_ELEMENTOS 10

#ifndef SET_H
#define SET_H

/**
 * @struct set
 * @brief Estrutura que representa um conjunto (set) de inteiros.
 *
 * O conjunto é limitado a um tamanho máximo de elementos definidos pela constante MAX_ELEMENTOS.
 * Ele armazena os elementos de maneira não ordenada e não permite duplicatas.
 */
typedef struct set
{
    int elementos[MAX_ELEMENTOS]; /**< Array que armazena os elementos do conjunto. */
    size_t tamanho;               /**< Número de elementos atualmente no conjunto. */
} Set;

#endif

/**
 * @brief Inicializa o conjunto, configurando o tamanho para 0.
 *
 * Esta função prepara o conjunto para ser usado, inicializando o tamanho do conjunto como 0.
 *
 * @param s Ponteiro para o conjunto a ser inicializado.
 */
void inicializar(Set *s)
{
    s->tamanho = 0;
}

/**
 * @brief Adiciona um novo elemento ao conjunto.
 *
 * Se o elemento já existir no conjunto, a função retorna `false` (não adiciona).
 * Se o conjunto não estiver cheio e o elemento não existir, ele é adicionado ao
 * conjunto e a função retorna `true`.
 *
 * @param s Ponteiro para o conjunto onde o elemento será adicionado.
 * @param elemento O elemento a ser adicionado ao conjunto.
 * @return `true` se o elemento foi adicionado com sucesso, `false` caso contrário.
 */
bool adicionar(Set *s, int elemento)
{
    // Verifica se o elemento já está presente no conjunto
    for (int i = 0; i < s->tamanho; i++)
    {
        if (s->elementos[i] == elemento)
        {
            return false;
        }
    }

    // Verifica se o conjunto não está cheio
    if (s->tamanho < MAX_ELEMENTOS)
    {
        s->elementos[s->tamanho] = elemento;
        s->tamanho++;
        return true;
    }
    return false;
}

/**
 * @brief Verifica se um elemento está presente no conjunto.
 *
 * A função percorre os elementos do conjunto e retorna `true` se o elemento for encontrado.
 * Caso contrário, retorna `false`.
 *
 * @param s Ponteiro para o conjunto onde a busca será realizada.
 * @param elemento O elemento a ser buscado no conjunto.
 * @return `true` se o elemento estiver presente no conjunto, `false` caso contrário.
 */
bool contem(Set *s, int elemento)
{
    for (int i = 0; i < s->tamanho; i++)
    {
        if (s->elementos[i] == elemento)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Imprime os elementos do conjunto.
 *
 * A função imprime todos os elementos do conjunto no formato de um conjunto matemático,
 * com os elementos separados por vírgula e espaços.
 *
 * @param s Ponteiro para o conjunto a ser impresso.
 */
void imprimir(Set *s)
{
    printf("{");

    for (int i = 0; i < s->tamanho; i++)
    {
        printf("%d", s->elementos[i]);

        if (i < s->tamanho - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(int argc, char **argv)
{
    Set set = {0}; // Declara e inicializa o conjunto

    // Inicializa o conjunto
    inicializar(&set);

    // Adiciona elementos ao conjunto
    adicionar(&set, 1);
    adicionar(&set, 2);
    adicionar(&set, 3);

    // Imprime o conjunto
    imprimir(&set);

    // Verifica a presença de elementos no conjunto
    printf("Contem 1? %s\n", contem(&set, 1) ? "Sim" : "Nao");
    printf("Contem 10? %s\n", contem(&set, 10) ? "Sim" : "Nao");
    printf("Contem 3? %s\n", contem(&set, 3) ? "Sim" : "Nao");

    return 0;
}
