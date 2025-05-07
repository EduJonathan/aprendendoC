#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que implementa o algoritmo de ordenação Insertion Sort.
 *
 * O **Insertion Sort** é um algoritmo de ordenação simples que funciona construindo uma
 * sequência ordenada de elementos um a um. Em cada iteração, ele "insere" o próximo
 * elemento na posição correta dentro da sequência já ordenada, movendo os elementos
 * maiores para a direita, até encontrar o local adequado.
 *
 * Este algoritmo é eficiente para arrays pequenos ou parcialmente ordenados, mas não
 * é eficiente para grandes volumes de dados, pois seu tempo de execução é quadrático.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor caso: O(n) -> ocorre quando o array já está ordenado, ou seja, não há
 * necessidade de realizar trocas.
 *
 * - Pior caso: O(n²) -> ocorre quando o array está ordenado de forma inversa, ou seja,
 * a cada iteração será necessário deslocar todos os elementos para a direita.
 *
 * - Caso médio: O(n²) -> em média, o algoritmo irá precisar de um número de comparações
 * proporcional a \(n^2\), pois ele compara e desloca os elementos repetidamente.
 *
 * Espaço:
 * 
 * - O(1) -> o algoritmo é in-place, ou seja, ele não requer espaço adicional significativo
 * além da memória usada para armazenar os dados de entrada.
 *
 * @param arr Array a ser ordenado.
 * @param n Tamanho do array (número de elementos).
 */
void insertionSort(int *arr, size_t n)
{
    int comparacoes = 0; // Contador de comparações
    int trocas = 0;      // Contador de trocas

    if (arr == NULL || n <= 1)
    {
        return; // Array vazio ou de tamanho 1 já está ordenado
    }

    int temp = 0;
    int j = 0;

    // Itera sobre o array a partir do segundo elemento
    for (size_t i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;

        // Move os elementos maiores que 'temp' uma posição à frente
        while (j >= 0 && arr[j] > temp)
        {
            comparacoes++;       // Incrementa o contador de comparações
            arr[j + 1] = arr[j]; // Move o elemento para a frente
            j--;                 // Decrementa o contador de iterações
            trocas++;            // Incrementa o contador de trocas
        }

        // Insere o valor 'temp' na posição correta
        arr[j + 1] = temp;

        // Se houver comparações no laço anterior
        if (j >= 0)
        {
            // Incrementa a última comparação
            comparacoes++;
        }
    }

    // Exibe o número de comparações e trocas
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);
}

int main(int argc, char **argv)
{
    // Criação do array e obtenção do seu tamanho
    int arr[] = {12, 4, 7, 9, 2, 6, 3, 11, 5, 10, 8, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordena o array utilizando o Insertion Sort
    insertionSort(arr, n);

    printf("Array ordenado: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
