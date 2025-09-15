#include <stdio.h>
#include <stdlib.h>

/**
 * @brief O Counting Sort é um algoritmo de ordenação baseado em contagem.
 *
 * O **Counting Sort** é um algoritmo de ordenação que funciona contando o número de
 * ocorrências de cada valor no array. Com base nas contagens, ele determina a posição
 * de cada valor no array ordenado. Esse algoritmo é eficiente quando os valores do array
 * estão em um intervalo restrito, pois evita comparações diretas entre os elementos.
 *
 * O Counting Sort não é um algoritmo de comparação. Em vez disso, ele usa uma estrutura
 * auxiliar (geralmente um array de contagem) para registrar quantas vezes cada valor aparece
 * no array de entrada e depois reconstrói o array ordenado com base nesses contadores.
 *
 * **Limitações**:
 * - O algoritmo é eficiente quando os valores são inteiros não negativos e estão dentro
 *   de um intervalo restrito.
 *
 * - Não é adequado para arrays com valores muito grandes ou para dados não inteiros,
 *   pois o espaço de memória necessário para armazenar a contagem pode ser muito grande.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor, pior e caso médio: O(n + k) -> onde \(n\) é o número de elementos no array
 *   e \(k\) é o valor máximo possível no array (a chave). A contagem e a reconstrução
 *   do array são feitas em tempo linear.
 *
 * Espaço:
 *
 * - O(n + k) -> o espaço adicional necessário é proporcional ao tamanho do array de entrada
 *   e ao valor máximo \(k\).
 *
 * @param arr Array de inteiros a ser ordenado.
 * @param key O maior valor possível no array.
 * @param size Tamanho do array.
 */
void countingSort(int *arr, int key, size_t size)
{
    int comparacoes = 0; // Contador de comparações
    int trocas = 0;      // Contador de trocas

    // Inicializa os arrays de contagem e resultado
    int *arr2 = (int *)calloc(key + 1, sizeof(int)); // Armazenar as contagens
    int *arr1 = (int *)malloc(size * sizeof(int));   // Armazenar o array ordenado

    if (arr2 == NULL || arr1 == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    // Passo 1: Conta a frequência de cada elemento em arr
    for (size_t i = 0ull; i < size; i++)
    {
        arr2[arr[i]]++; // Contagem da frequência
        comparacoes++;  // Cada operação de contagem é uma comparação
    }

    // Passo 2: Soma acumulada para encontrar as posições finais
    for (int i = 1; i <= key; i++)
    {
        arr2[i] += arr2[i - 1]; // Soma acumulada
        comparacoes++;          // Cada soma é uma comparação
    }

    // Passo 3: Preenche o arr1 com os valores ordenados
    for (int i = size - 1; i >= 0; i--)
    {
        arr1[arr2[arr[i]] - 1] = arr[i];
        arr2[arr[i]]--; // Diminui o contador para garantir a posição correta
        trocas++;       // Cada movimentação de valor é considerada uma troca
    }

    // Passo 4: Copia o array ordenado de volta para o original
    for (size_t i = 0ull; i < size; i++)
    {
        arr[i] = arr1[i]; // Copia o valor
        trocas++;         // Cada cópia é considerada uma troca
    }

    // Libera a memória alocada
    free(arr2);
    free(arr1);

    // Exibe o array ordenado
    printf("O array ordenado é: \n");
    for (size_t i = 0ull; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Exibe o número de comparações e trocas
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);
}

int main(int argc, char **argv)
{
    int arr[] = {12, 4, 7, 9, 2, 6, 3, 11, 5, 10, 8, 1};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // O valor de "key" é o maior valor do array
    countingSort(arr, 12, n);

    return 0;
}
