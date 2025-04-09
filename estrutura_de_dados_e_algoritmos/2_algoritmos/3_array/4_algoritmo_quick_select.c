#include <stdio.h>

/**
 * O Quickselect é um algoritmo de seleção que encontra o k-ésimo menor (ou maior)
 * elemento em um vetor sem ordenar completamente o vetor. É uma versão simplificada do
 * Quicksort (onde se seleciona apenas a parte relevante do vetor, em vez de ordenar todo o vetor).
 *
 * COMPLEXIDADE:
 * TEMPO: O(n) em média, onde n é o número de elementos no vetor. Isso ocorre porque,
 * em cada chamada recursiva, o algoritmo corta pela metade a busca.
 * O(n²) no pior caso, mas isso pode ser evitado com boas escolhas de pivô.
 *
 * ESPAÇO: O(log n) devido à recursão (no pior caso, a profundidade de recursão será
 * proporcional ao número de elementos).
 */

/**
 * @brief Particiona o vetor e retorna o índice do pivô.
 *
 * @param arr Vetor de inteiros.
 * @param low Índice de início do intervalo.
 * @param high Índice final do intervalo.
 * @return O índice do pivô após a partição.
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;       // Índice do menor elemento

    // Reorganiza o vetor para que os elementos menores que o pivô
    // fiquem à esquerda e os maiores fiquem à direita
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            // Troca arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Coloca o pivô na posição correta
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

/**
 * @brief Função recursiva para encontrar o k-ésimo menor elemento do vetor.
 *
 * @param arr Vetor de inteiros.
 * @param low Índice de início do intervalo a ser considerado.
 * @param high Índice final do intervalo a ser considerado.
 * @param k Índice (1-based) do elemento desejado.
 * @return O k-ésimo menor elemento do vetor.
 */
int quickSelection(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        // Particiona o vetor e obtém o índice do pivô.
        int pi = partition(arr, low, high);

        if (pi == k - 1)
        {
            // Verifica se o pivô está na posição desejada
            return arr[pi];
        }
        else if (pi > k - 1)
        {
            // Se o k-ésimo elemento está à esquerda do pivô, busca recursivamente à esquerda
            return quickSelection(arr, low, pi - 1, k);
        }
        else
        {
            // Se o k-ésimo elemento está à direita do pivô, busca recursivamente à direita
            return quickSelection(arr, pi + 1, high, k);
        }
    }
    return -1; // Caso de erro, caso o valor de k seja inválido.
}

int main(int argc, char **argv)
{
    int arr[] = {12, 3, 5, 7, 19, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = quickSelection(arr, 0, n - 1, k);
    printf("O %d-ésimo menor elemento é: %d\n", k, result);

    return 0;
}
