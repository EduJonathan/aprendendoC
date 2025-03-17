#include <stdio.h>

/**
 * @brief Função para trocar dois elementos do array.
 *
 * @param a Ponteiro para o primeiro elemento.
 * @param b Ponteiro para o segundo elemento.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Função de ordenação rápida (Quick Sort).
 *
 * Algoritmo de ordenação Quick Sort utilizando o método de partição.
 * O algoritmo seleciona um pivô e organiza os elementos de modo que os valores
 * menores que o pivô fiquem à esquerda, e os valores maiores fiquem à direita.
 * A função é chamada recursivamente para as sublistas à esquerda e à direita
 * do pivô.
 */
void quick_sort(int *array, int low, int high)
{
    static int comparacoes = 0; // Contador de comparações (variável estática)
    static int trocas = 0;      // Contador de trocas (variável estática)

    int pivot = 0;
    int i = 0;
    int j = 0;

    // Verifica se a lista contém mais de um elemento
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;

        // Loop de partição
        while (i < j)
        {
            // Move i para a direita até encontrar um valor maior que o pivô
            while (array[i] <= array[pivot] && i < high)
            {
                i++;
                comparacoes++; // Contagem de comparações
            }

            // Move j para a esquerda até encontrar um valor menor que o pivô
            while (array[j] > array[pivot] && j >= low)
            {
                j--;
                comparacoes++; // Contagem de comparações
            }

            // Se i ainda for menor que j, troca os valores
            if (i < j)
            {
                swap(&array[i], &array[j]);
                trocas++; // Contagem de trocas
            }
        }

        // Coloca o pivô na posição correta com o swap
        swap(&array[pivot], &array[j]);
        trocas++; // Contagem de trocas

        // Chama recursivamente para as sublistas à esquerda e à direita do pivô
        quick_sort(array, low, j - 1);
        quick_sort(array, j + 1, high);
    }

    // Ao final da execução, exibe as contagens de comparações e trocas
    if (low == 0 && high == 11) // Verifica se a ordenação foi concluída
    {
        printf("Número de comparações: %d\n", comparacoes);
        printf("Número de trocas: %d\n", trocas);
    }
}

int main(int argc, char **argv)
{
    // Array de exemplo
    int arr[] = {12, 4, 7, 9, 2, 6, 3, 11, 5, 10, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original
    printf("Original array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Chama a função quick_sort para ordenar o array
    quick_sort(arr, 0, n - 1);

    // Exibe o array ordenado
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
