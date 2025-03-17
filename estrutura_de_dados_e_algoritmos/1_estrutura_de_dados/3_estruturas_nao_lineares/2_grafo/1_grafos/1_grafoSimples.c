#include <stdio.h>
#include <stdbool.h>

#define true 1
#define false 0

/**
 * @brief Função para checar se houver conexão entre dois pontos
 *
 * @param pontoX ponto de origem
 * @param pontoY ponto de destino
 * @return true se houver conexão
 * @return false se não houver conexão
 */
bool VerticeConectados(int pontoX, int pontoY)
{
    // Matriz de adjacência
    int G[5][5] =
        {
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1},
            {0, 0, 1, 1, 1}};

    // Checa se há conexões entre os ponto dos vértices
    if (G[pontoX][pontoY] == true || G[pontoY][pontoX] == true)
    {
        // Há conexão
        return true;
    }

    // Não há conexão
    return false;
}

int main(int argc, char **argv)
{
    // Ponto de origem e destino
    int x = 0;
    int y = 2;

    // Imprime se houver ou não conexão
    if (VerticeConectados(x, y))
    {
        printf("Há connexão entre o ponto %d e ponto %d\n", x, y);
    }
    else
    {
        printf("Não há connexão entre o ponto %d e ponto %d\n", x, y);
    }
    return 0;
}
