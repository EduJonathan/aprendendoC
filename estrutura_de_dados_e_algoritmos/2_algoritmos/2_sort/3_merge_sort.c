#include <stdio.h>

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
    int left[n1];                   // Subarray temporário para a parte esquerda
    int right[n2];                  // Subarray temporário para a parte direita

    // Copia os elementos para os subarrays temporários
    for (int i = 0; i < n1; i++)
    {
        // Copiando os elementos para o subarray esquerdo
        left[i] = arr[esquerda + i];
    }
    for (int j = 0; j < n2; j++)
    {
        // Copiando os elementos para o subarray direito
        right[j] = arr[middle + 1 + j];
    }

    // Variáveis para contar comparações e trocas
    int comparacoes = 0;
    int trocas = 0;

    // Combina os subarrays temporários de volta ao array original ordenadamente
    for (int i = 0, j = 0, k = esquerda; k <= direita; k++)
    {
        comparacoes++; // Incrementa o contador de comparações

        // Comparando os elementos das partes esquerda e direita
        if (i < n1 && (j >= n2 || left[i] <= right[j]))
        {
            arr[k] = left[i++];
            trocas++; // Incrementa o contador de trocas
        }
        else
        {
            arr[k] = right[j++];
            trocas++; // Incrementa o contador de trocas
        }
    }

    // Exibe a quantidade de comparações e trocas
    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);
}

/**
 * @brief Função de ordenação Merge Sort.
 *
 * Merge Sort é um algoritmo de ordenação baseado na técnica "dividir e conquistar".
 * A lista é dividida recursivamente até que cada sublista tenha um único elemento,
 * depois as sublistas são mescladas em ordem.
 *
 * @param arr Array a ser ordenado.
 * @param left Indice do primeiro elemento do subarray.
 * @param right Indice do último elemento do subarray.
 */
void mergeSort(int *arr, int left, int right)
{
    // Verifica se o subarray tem pelo menos dois elementos
    if (left < right)
    {
        // Calcula o ponto médio
        int meio = left + (right - left) / 2;

        // Chama recursivamente mergeSort para ordenar os subarrays esquerdo e direito
        mergeSort(arr, left, meio);
        mergeSort(arr, meio + 1, right);

        // Une os subarrays ordenados
        merge(arr, left, meio, right);
    }
}

int main(int argc, char **argv)
{
    // Array de exemplo a ser ordenado
    int arr[] = {12, 11, 14, 5, 7, 8};

    // Calcula o número de elementos no array
    int n = 6;

    // Chama a função de ordenação passando o array e o número de elementos
    mergeSort(arr, 0, n - 1);

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
