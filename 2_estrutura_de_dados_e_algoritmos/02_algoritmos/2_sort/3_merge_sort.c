#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Variáveis globais para contar comparações e trocas
static long long comparacoes = 0;
static long long trocas = 0;

/**
 * @brief Função que combina dois subarrays ordenados em um array ordenado.
 *
 * @param arr Array a ser ordenado.
 * @param esquerda Indice do primeiro elemento do subarray esquerdo.
 * @param middle Indice do primeiro elemento do subarray direito.
 * @param direita Indice do primeiro elemento do subarray direito.
 */
void merge(int *arr, int esquerda, int middle, int direita)
{
    int n1 = middle - esquerda + 1; // Tamanho do subarray da esquerda
    int n2 = direita - middle;      // Tamanho do subarray da direita

    // Aloca arrays temporários dinamicamente
    int *left = (int *)malloc((n1 + 1) * sizeof(int));
    int *right = (int *)malloc((n2 + 1) * sizeof(int));

    if (left == NULL || right == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        free(left);
        free(right);
        return;
    }

    // Copia os elementos para os subarrays temporários
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[esquerda + i];
    }

    left[n1] = INT_MAX; // Sentinela
    
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[middle + 1 + j];
    }
    right[n2] = INT_MAX; // Sentinela

    // Combina os subarrays temporários
    for (int i = 0, j = 0, k = esquerda; k <= direita; k++)
    {
        comparacoes++; // Conta a comparação

        if (left[i] <= right[j])
        {
            arr[k] = left[i++];
            trocas++; // Conta a cópia como uma "troca"
        }
        else
        {
            arr[k] = right[j++];
            trocas++; // Conta a cópia como uma "troca"
        }
    }

    // Libera memória alocada
    free(left);
    free(right);
}

/**
 * @brief Função de ordenação Merge Sort.
 *
 * **Merge Sort** é um algoritmo de ordenação baseado na técnica **"dividir e conquistar"**.
 * A lista é dividida recursivamente em duas metades até que cada sublista tenha um único elemento.
 * Em seguida, as sublistas são combinadas (mescladas) de forma ordenada, criando uma lista
 * ordenada final.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor caso: O(n log n) -> mesmo quando o array já está parcialmente ordenado,
 * a divisão e a mesclagem ocorrem em O(n log n).
 *
 * - Pior caso: O(n log n) -> o tempo de execução é sempre O(n log n), independentemente
 * da distribuição dos dados.
 *
 * - Caso médio: O(n log n) -> o desempenho é consistente, pois a divisão ocorre em O(log n)
 * e a mesclagem em O(n).
 *
 * Espaço:
 *
 * - O(n) -> o algoritmo necessita de espaço adicional para armazenar as sublistas enquanto
 * realiza a mesclagem.
 *
 * @param arr Array a ser ordenado.
 * @param left Índice do primeiro elemento do subarray.
 * @param right Índice do último elemento do subarray.
 */
void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int meio = left + (right - left) / 2;
        mergeSort(arr, left, meio);
        mergeSort(arr, meio + 1, right);
        merge(arr, left, meio, right);
    }
}

int main(int argc, char **argv)
{
    int n = 0;

    // Solicita o tamanho do array
    printf("Digite o número de elementos: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Erro: O número de elementos deve ser positivo.\n");
        return 1;
    }

    // Aloca o array dinamicamente
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return 1;
    }

    // Solicita os elementos do array
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Erro: Entrada inválida para o elemento %d.\n", i + 1);
            free(arr);
            return 1;
        }
    }

    // Reseta os contadores
    comparacoes = 0;
    trocas = 0;

    // Chama a função de ordenação
    mergeSort(arr, 0, n - 1);

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Imprime as estatísticas
    printf("Número total de comparações: %lld\n", comparacoes);
    printf("Número total de trocas: %lld\n", trocas);

    // Libera memória
    free(arr);
    return 0;
}
