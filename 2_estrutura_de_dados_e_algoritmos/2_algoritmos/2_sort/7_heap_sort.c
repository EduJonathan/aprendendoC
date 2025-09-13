#include <stdio.h>
#include <stdlib.h>

/* Realiza a troca de valores */
void swap(int *valor1, int *valor2)
{
    int temp = 0;
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
void heapify(int *arr, size_t index, size_t size)
{
    size_t left = (2 * index) + 1; // Índice do filho esquerdo
    size_t right = left + 1;       // Índice do filho direito
    size_t max = index;            // Assume-se que o nó atual seja o maior

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
 * O **Heap Sort** é um algoritmo de ordenação que utiliza a estrutura de dados **heap**
 * (uma árvore binária completa) para ordenar os elementos. O algoritmo constrói um heap
 * a partir dos elementos do array e, em seguida, remove o maior (ou menor, dependendo
 * do tipo de heap) elemento do heap, colocando-o na posição correta do array.
 * Esse processo é repetido até que todo o array esteja ordenado.
 *
 * O Heap Sort pode ser implementado com um heap máximo (para ordenação crescente) ou
 * um heap mínimo (para ordenação decrescente). A cada remoção do maior (ou menor)
 * elemento, o heap é reestruturado para manter a propriedade da árvore binária.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor caso: O(n log n) -> o algoritmo tem uma complexidade de tempo de O(n log n)
 *     em qualquer cenário, já que a construção do heap e a remoção do maior elemento
 *     requerem tempo O(log n).
 *
 * - Pior caso: O(n log n) -> o desempenho é o mesmo para o pior caso, já que o
 *     processo de construção e reorganização do heap é eficiente.
 *
 * - Caso médio: O(n log n) -> a complexidade é consistente, já que o algoritmo sempre
 *     realiza O(log n) operações para extrair os elementos e reestruturar o heap.
 *
 * Espaço:
 *
 * - O(1) -> o Heap Sort é um algoritmo in-place, ou seja, ele não necessita de espaço
 *     adicional além do necessário para armazenar os dados de entrada.
 *
 * @param arr O array a ser ordenado.
 * @param size O tamanho do array.
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
    size_t n = 0ull;   // Tamanho do array
    int arr[10] = {0}; // Array a ser ordenado

    printf("Insira o tamanho do array: ");
    scanf("%zu", &n);

    printf("Insira os valores do array\n");
    for (size_t i = 0ull; i < n; i++)
    {
        printf("%zu valor: ", i);
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n); // Passa o tamanho correto

    printf("\nOrdenando com o heap sort\n");
    for (size_t i = 0ull; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
