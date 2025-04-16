#include <stdio.h>
#include <stdbool.h>

#define N 5

/**
 * @brief Função para imprimir o grau de todos os vertices do grafo
 *
 * @param matriz Matriz representando o grafo
 * 
 * grau de um vértice é o número de arestas que incidem sobre ele.
 * Em um grafo não direcionado, o grau de um vértice é igual ao número de arestas que o conectam.
 * Em um grafo direcionado, o grau de entrada é o número de arestas que chegam ao vértice,
 * e o grau de saída é o número de arestas que saem do vértice.
 */
void imprimeGrauDosVertices(int matriz[N][N])
{
    // Percorrendo a matriz
    for (int i = 0; i < N; i++)
    {
        // Contando o grau de cada vertice
        int grau = 0;

        // Percorrendo a linha
        for (int j = 0; j < N; j++)
        {
            // Verificando se o elemento da matriz eh 1
            if (matriz[i][j] == 1)
            {
                // Incrementando o grau
                grau++;
            }
        }
        printf("O vértice %d tem grau %d.\n", i + 1, grau);
    }
}

int main(int argc, char **argv)
{
    // Matriz de adjacência
    int G[N][N] = {
        {false, false, true, false, false},
        {false, false, true, false, false},
        {true, true, false, true, true},
        {false, false, true, false, true},
        {false, false, true, true, true}};

    // Imprimindo o grau de todos os vertices
    imprimeGrauDosVertices(G);
    return 0;
}
