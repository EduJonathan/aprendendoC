#include <stdio.h>
#include <stdlib.h> // Necessário para alocação dinâmica com malloc

/**
 * A alocação dinâmica é o processo de solicitar memória para armazenar dados enquanto
 * o programa está sendo executado e neste código demonstra como alocar memória para
 * uma matriz 2D de inteiros de forma dinâmica e preencher, acessar e liberar a memória.
 */

int main(int argc, char **argv)
{
    int n = 4, m = 5; // Definindo o tamanho da matriz 4x5 (n linhas e m colunas)

    // A alocação dinâmica ocorre aqui:
    // Primeiro, alocamos um ponteiro para um array de ponteiros (linhas da matriz).
    // Cada ponteiro da matriz irá apontar para uma linha de inteiros.
    int **matriz = (int **)malloc(n * sizeof(int *)); // Aloca um array de ponteiros (linhas)

    // Verifica se a alocação para o array de ponteiros falhou
    if (matriz == NULL)
    {
        printf("Erro ao alocar memória para as linhas!\n");
        exit(1); // Encerra o programa em caso de falha na alocação
    }

    // Agora, para cada linha da matriz, alocamos memória para armazenar os inteiros das colunas.
    // Cada linha será um array de inteiros com m colunas.
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *)malloc(m * sizeof(int)); // Aloca m inteiros para cada linha

        // Verifica se a alocação para a linha i falhou
        if (matriz[i] == NULL)
        {
            printf("Erro ao alocar memória para a linha %d!\n", i);
            exit(1); // Encerra o programa em caso de falha na alocação
        }
    }

    // Preenchendo a matriz com valores sequenciais, começando de 1
    int valor = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matriz[i][j] = valor++; // Atribui um valor sequencial à célula [i][j]
        }
    }

    // Impressão da matriz usando aritmética de ponteiros
    printf("Matriz 2D (usando aritmética de ponteiros):\n");

    for (int i = 0; i < n; i++)
    {
        // Usando aritmética de ponteiros para acessar os elementos
        for (int j = 0; j < m; j++)
        {
            // A aritmética de ponteiros é usada para acessar a célula [i][j]
            // *(matriz + i) aponta para a i-ésima linha da matriz
            // *(matriz + i) + j aponta para a j-ésima coluna da linha i
            printf("%d ", *(*(matriz + i) + j)); // Acessa o elemento da matriz com aritmética de ponteiros
        }
        printf("\n");
    }

    // Liberando a memória alocada
    // Primeiro, liberamos a memória alocada para cada linha da matriz
    for (int i = 0; i < n; i++)
    {
        free(matriz[i]); // Libera cada linha da matriz (array de inteiros)
    }

    // Depois, liberamos o array de ponteiros (matriz)
    free(matriz); // Libera o array de ponteiros para as linhas
    return 0;
}
