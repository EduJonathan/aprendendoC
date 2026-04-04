#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Este programa implementa e compara o desempenho de diferentes algoritmos:
 * - Buscas: Linear e Binária
 * - Ordenação: Bubble Sort e Quick Sort
 *
 * Demonstra como o tempo de execução varia com o tamanho da entrada (n) e a importância de escolher algoritmos eficientes.
 */

/**
 * @brief Realiza busca linear em um array
 *
 * Percorre sequencialmente todo o array até encontrar o elemento ou chegar ao final.
 *
 * @param arr Ponteiro para o array de inteiros
 * @param n Tamanho do array
 * @param k Chave a ser buscada
 *
 * @return 1 se o elemento foi encontrado, 0 caso contrário
 *
 * @note Complexidade: O(n) no pior caso
 * @note Funciona em arrays ordenados ou desordenados
 */
int busca_linear(int *arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return 1;
    }
    return 0;
}

/**
 * @brief Realiza busca binária em um array ordenado
 *
 * Divide o array pela metade repetidamente, descartando a metade que não contém
 * o elemento procurado, até encontrá-lo ou determinar sua ausência.
 *
 * @param arr Ponteiro para o array de inteiros (DEVE estar ordenado)
 * @param n Tamanho do array
 * @param k Chave a ser buscada
 *
 * @return 1 se o elemento foi encontrado, 0 caso contrário
 *
 * @note Complexidade: O(log n)
 * @pre O array deve estar ordenado em ordem crescente
 * @see busca_linear para comparação com busca sequencial
 */
int busca_binaria(int *arr, int n, int k)
{
    int inicio = 0, fim = n - 1;
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        if (arr[meio] == k)
            return 1;

        if (arr[meio] < k)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return 0;
}

// ====================== ORDENAÇÃO ======================

/**
 * @brief Ordena um array usando o algoritmo Bubble Sort
 *
 * Compara elementos adjacentes e os troca se estiverem na ordem errada.
 * Repete esse processo até que o array esteja completamente ordenado.
 *
 * @param arr Ponteiro para o array de inteiros a ser ordenado
 * @param n Tamanho do array
 *
 * @return void (modifica o array in-place)
 *
 * @note Complexidade: O(n²) no pior e caso médio, O(n) no melhor caso
 * @note Espaço: O(1) - ordenação in-place
 * @warning Muito ineficiente para arrays grandes
 * @see quick_sort para uma alternativa mais eficiente
 */
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp   = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Ordena um array usando o algoritmo Quick Sort (recursivo)
 *
 * Utiliza a estratégia divide-and-conquer: seleciona um pivô, particiona o array
 * em torno do pivô, e recursivamente ordena as sub-arrays.
 *
 * @param arr Ponteiro para o array de inteiros a ser ordenado
 * @param low Índice inicial do intervalo a ser ordenado
 * @param high Índice final do intervalo a ser ordenado
 *
 * @return void (modifica o array in-place)
 *
 * @note Complexidade: O(n log n) no caso médio e melhor, O(n²) no pior caso
 * @note Espaço: O(log n) no caso médio (pilha de recursão)
 * @note Muito mais eficiente que Bubble Sort para arrays grandes
 * @see bubble_sort para comparação com algoritmo O(n²)
 */
void quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        // Particionamento
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i]   = arr[j];
                arr[j]   = temp;
            }
        }

        int temp   = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high]  = temp;

        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

/**
 * @brief Função principal - executa comparação de algoritmos
 *
 * Cria um array com valores aleatórios e compara o tempo de execução de:
 * - Busca Linear em array desordenado
 * - Quick Sort
 * - Busca Binária em array ordenado
 * - Bubble Sort
 *
 * @param argc Número de argumentos da linha de comando (não utilizado)
 * @param argv Argumentos da linha de comando (não utilizado)
 *
 * @return 0 se executado com sucesso, 1 em caso de erro de alocação de memória
 *
 * @note Para testar com diferentes tamanhos, modifique o valor de 'n'
 * @note Valores sugeridos: 50000, 100000, 200000, 1000000
 * @note A chave buscada é o elemento no meio do array
 */
int main(int argc, char **argv)
{
    int n = 100000; // mude para 50000, 200000, 1000000 para testar
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
        printf("Erro de alocação!\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000000; // valores até 10 milhões
    }

    int chave = arr[n / 2]; // chave que existe

    printf("=== Comparação com array de %d elementos ===\n\n", n);

    // 1. Busca Linear (array desordenado)
    clock_t start = clock();
    int found_lin = busca_linear(arr, n, chave);
    clock_t end = clock();

    printf("Busca Linear:     %.6f seg  (encontrado: %s)\n",
           (double)(end - start) / CLOCKS_PER_SEC, found_lin ? "Sim" : "Não");

    // 2. Ordenação + Busca Binária
    int *arr_ord = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr_ord[i] = arr[i];

    start = clock();
    quick_sort(arr_ord, 0, n - 1);
    end = clock();
    double tempo_quick = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort:       %.6f seg\n", tempo_quick);

    start = clock();
    int found_bin = busca_binaria(arr_ord, n, chave);
    end = clock();
    printf("Busca Binária:    %.6f seg  (encontrado: %s)\n",
           (double)(end - start) / CLOCKS_PER_SEC, found_bin ? "Sim" : "Não");

    // 3. Bubble Sort (para ver a diferença brutal)
    for (int i = 0; i < n; i++)
        arr_ord[i] = arr[i]; // reset

    start = clock();
    bubble_sort(arr_ord, n);
    end = clock();
    printf("Bubble Sort:      %.6f seg\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    free(arr_ord);
    return 0;
}
