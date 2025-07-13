#include <stdio.h>
#include <stdlib.h>

/**
 * Algoritmo de Union-Find: O algoritmo Union-Find, também conhecido como algoritmo de
 * "conjunto disjunto" ou "Disjoint Set Union" (DSU), uma estrutura de dados utilizada
 * para gerenciar e combinar conjuntos disjuntos de elementos armazenando árvores
 * disjuntas e permite que sejam unidas duas árvores. Bastante útil para resolver problemas
 * que envolvem união e busca de elementos em subconjuntos, como em grafos e redes.
 *
 * COMPLEXIDADE:
 * TEMPO: O(n)
 *
 * ESPAÇO: O(1)
 */

/**
 * @brief Estrutura que representa o Union-Find com arrays de pais e ranks.
 */
typedef struct
{
    int *parent; /**< Array que armazena o pai de cada elemento */
    int *rank;   /**< Array que armazena o rank (altura aproximada da árvore) */
    int n;       /**< Número total de elementos no conjunto */
} UnionFind;

/**
 * @brief Cria e inicializa a estrutura Union-Find.
 *
 * @param size Número de elementos.
 * @return Ponteiro para a estrutura UnionFind inicializada.
 */
UnionFind *uf_create(int size)
{
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    uf->n = size;
    uf->parent = (int *)malloc(size * sizeof(int));
    uf->rank = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }

    return uf;
}

/**
 * @brief Encontra o representante do conjunto do elemento x.
 *
 * Utiliza path compression para otimizar a árvore.
 *
 * @param uf Ponteiro para a estrutura UnionFind.
 * @param x Elemento a ser encontrado.
 * @return Índice do representante (raiz) ou -1 se inválido.
 */
int uf_find(UnionFind *uf, int x)
{
    if (x < 0 || x >= uf->n)
    {
        fprintf(stderr, "Erro: índice %d fora dos limites.\n", x);
        return -1;
    }

    if (uf->parent[x] != x)
    {
        uf->parent[x] = uf_find(uf, uf->parent[x]);
    }
    return uf->parent[x];
}

/**
 * @brief Une os conjuntos dos elementos x e y.
 *
 * Usa a técnica de union by rank para manter a árvore equilibrada.
 *
 * @param uf Ponteiro para a estrutura UnionFind.
 * @param x Primeiro elemento.
 * @param y Segundo elemento.
 */
void uf_union(UnionFind *uf, int x, int y)
{
    int rootX = uf_find(uf, x);
    int rootY = uf_find(uf, y);

    if (rootX == -1 || rootY == -1)
        return;

    if (rootX == rootY)
        return;

    if (uf->rank[rootX] < uf->rank[rootY])
    {
        uf->parent[rootX] = rootY;
    }
    else if (uf->rank[rootX] > uf->rank[rootY])
    {
        uf->parent[rootY] = rootX;
    }
    else
    {
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++;
    }
}

/**
 * @brief Verifica se dois elementos pertencem ao mesmo conjunto.
 *
 * @param uf Ponteiro para a estrutura UnionFind.
 * @param x Primeiro elemento.
 * @param y Segundo elemento.
 * @return 1 se estão conectados, 0 caso contrário.
 */
int uf_connected(UnionFind *uf, int x, int y)
{
    int rootX = uf_find(uf, x);
    int rootY = uf_find(uf, y);
    
    if (rootX == -1 || rootY == -1)
        return 0;
    return rootX == rootY;
}

/**
 * @brief Libera toda a memória alocada pela estrutura Union-Find.
 *
 * @param uf Ponteiro para a estrutura a ser destruída.
 */
void uf_destroy(UnionFind *uf)
{
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

int main(int argc, char **argv)
{
    int n = 10;
    UnionFind *uf = uf_create(n);

    // União entre elementos
    uf_union(uf, 1, 2);
    uf_union(uf, 2, 3);
    uf_union(uf, 4, 5);
    uf_union(uf, 6, 7);
    uf_union(uf, 5, 6);
    uf_union(uf, 3, 7);

    // Verificações
    printf("1 e 7 conectados? %s\n", uf_connected(uf, 1, 7) ? "Sim" : "Não");
    printf("0 e 4 conectados? %s\n", uf_connected(uf, 0, 4) ? "Sim" : "Não");
    printf("4 e 7 conectados? %s\n", uf_connected(uf, 4, 7) ? "Sim" : "Não");

    // Casos adicionais
    printf("Unindo 8 com ele mesmo...\n");
    uf_union(uf, 8, 8);
    printf("8 e 8 conectados? %s\n", uf_connected(uf, 8, 8) ? "Sim" : "Não");

    printf("Tentando unir elementos fora do intervalo (10 e 11)...\n");
    uf_union(uf, 10, 11); // Fora dos limites, deve imprimir erro

    uf_destroy(uf);
    return 0;
}
