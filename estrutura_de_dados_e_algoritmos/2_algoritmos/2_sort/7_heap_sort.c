#include <stdio.h>
#include <stdlib.h>

/* Realiza a troca de valores */
void swap(int *valor1, int *valor2)
{
    int temp;
    temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

/**
 * @brief Refaz a estrutura do heap a partir de um nó específico, garantindo a propriedade do heap.
 *
 * @param arr O array a ser transformado em um heap.
 * @param index O índice do nó a partir do qual deve ser feita a reestruturação.
 * @param size O tamanho do array.
 */
void heapify(int *arr, int index, size_t size)
{
    int left = (2 * index) + 1; // Índice do filho esquerdo
    int right = left + 1;       // Índice do filho direito
    int max = index;            // Assume-se que o nó atual seja o maior

    // Verifica se o filho esquerdo existe e é maior que o nó atual
    if (left < size && arr[left] > arr[max])
    {
        max = left;
    }

    // Verifica se o filho direito existe e é maior que o nó atual
    if (right < size && arr[right] > arr[max])
    {
        max = right;
    }

    // Se o maior não é o nó atual, troca e chama recursivamente
    if (index != max)
    {
        swap(&arr[max], &arr[index]);
        heapify(arr, max, size); // Chama recursivamente para reestruturar o heap
    }
}

/**
 * @brief Constrói um heap a partir do array.
 *
 * @param arr O array a ser transformado em um heap.
 * @param size O tamanho do array.
 */
void construirHeap(int *arr, size_t size)
{
    // Começa do meio do array até o início (para construir o heap)
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, size); // Constrói o heap a partir do nó i
    }
}

/**
 * @brief Ordena o array utilizando o algoritmo Heap Sort.
 *
 * @param arr O array a ser ordenado.
 * @param size O tamanho do array.
 * @note O Heap Sort usa a estrutura de um heap para garantir que o maior (ou menor,
 * dependendo do tipo de heap) elemento seja removido e colocado na posição correta do array,
 * repetindo esse processo até que todo o array esteja ordenado. tem uma complexidade de tempo de
 * O(n log n) tanto no pior quanto no melhor caso.
 */
void heapSort(int *arr, size_t size)
{
    // Constrói o heap
    construirHeap(arr, size);

    // Ordena o array utilizando o heap
    while (size > 1)
    {
        swap(&arr[0], &arr[size - 1]); // Troca o maior elemento (raiz do heap) com o último elemento
        size--;                        // Reduz o tamanho do heap
        heapify(arr, 0, size);         // Reestrutura o heap com o novo tamanho
    }
}

int main(int argc, char **argv)
{
    size_t n;
    int arr[10];

    printf("Insira o tamanho do array: ");
    scanf("%zu", &n); // Corrigido para ler 'size_t'

    printf("Insira os valores do array\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%zu valor: ", i);
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n); // Passa o tamanho correto

    printf("\nOrdenando com o heap sort\n");

    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
