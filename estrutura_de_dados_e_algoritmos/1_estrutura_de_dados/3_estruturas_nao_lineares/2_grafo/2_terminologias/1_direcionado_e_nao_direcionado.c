#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Função que verifica se o grafo é direcionado ou não direcionado.
 *
 * A função verifica se a matriz de adjacência é simétrica. Se for simétrica,
 * o grafo é não direcionado. Caso contrário, o grafo é direcionado.
 *
 * @param grafo Matriz de adjacência representando o grafo.
 * @param numVertices Número de vértices do grafo.
 * @return Verdadeiro se o grafo for não direcionado, falso se for direcionado.
 */
bool grafoNaoDirecionadoOuDirecionado(int grafo[][5], int numVertices)
{
    // Percorre a matriz de adjacência
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            // Se a matriz não for simétrica
            if (grafo[i][j] != grafo[j][i])
            {
                // Grafo direcionado
                return false;
            }
        }
    }

    // Grafo não direcionado
    return true;
}

int main(int argc, char **argv)
{
    // Exemplo de um grafo não direcionado com 5 vértices
    int grafoNaoDirecionado[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}};

    // Exemplo de um grafo direcionado com 5 vértices
    int grafoDirecionado[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    // Uso do operador ternário para verificar e imprimir o tipo de grafo
    printf("O grafo é %s.\n", grafoNaoDirecionadoOuDirecionado(grafoNaoDirecionado, 5) ? "não direcionado" : "direcionado");
    printf("O grafo é %s.\n", grafoNaoDirecionadoOuDirecionado(grafoDirecionado, 5) ? "não direcionado" : "direcionado");

    return 0;
}
