#include <stdio.h>
#include <string.h>

/**
 * @brief Função para ordenar um array usando o Selection Sort
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 */
void selectionSort(int *arr, size_t n)
{
    int comparacoes = 0; // Contador de comparações
    int swaps = 0;       // Contador de trocas

    // Loop externo que percorre o array até o penúltimo elemento
    for (size_t i = 0; i < n - 1; i++)
    {
        int minIndex = i; // Assume que o menor elemento é inicialmente o elemento atual

        // Loop interno para encontrar o menor elemento não ordenado à direita de i
        for (size_t j = i + 1; j < n; j++)
        {
            comparacoes++; // Conta a comparação feita

            // Se o elemento atual é menor que o menor encontrado até agora, atualiza minIndex
            if (arr[j] < arr[minIndex])
            {
                // Atualiza minIndex
                minIndex = j;
            }
        }

        // Se minIndex for diferente de i, troca os elementos nas posições i e minIndex
        if (minIndex != i)
        {
            int temp = arr[i];      // Atribui o valor de arr[i] a temp
            arr[i] = arr[minIndex]; // Atribui o valor de arr[minIndex] a arr[i]
            arr[minIndex] = temp;   // Atribui o valor de temp a arr[minIndex]
            swaps++;                // Conta as trocas
        }
    }

    // Agora você pode usar 'comparacoes' e 'swaps' para exibir os resultados ou usá-los
    printf("Comparações: %d\n", comparacoes);
    printf("Trocas: %d\n", swaps);
}

/**
 * @brief Função para ordenar uma string usando o Selection Sort.
 *
 * Divide a lista em duas partes: uma ordenada e uma não ordenada. A cada iteração,
 * encontra o menor (ou maior, dependendo da ordem desejada) elemento na parte não
 * ordenada e o coloca na posição correta.
 *
 * @param items Ponteiro para a string a ser ordenada.
 * @param count Tamanho da string.
 */
void selectionSortString(char *items, int count)
{
    // Loop externo que percorre a string até o penúltimo caractere
    for (int a = 0; a < count - 1; a++)
    {
        // Encontra o menor caractere restante
        int c = a;

        // Encontra o menor caractere restante
        char t = items[a];

        // Loop interno para encontrar o menor caractere restante
        for (int b = a + 1; b < count; b++)
        {
            // Encontra o menor caractere restante
            if (items[b] < t)
            {
                c = b;        // Encontra o menor caractere restante
                t = items[b]; // Adiciona o menor caractere restante
            }
        }

        // Se o menor caractere restante for diferente do caractere atual, troca-os
        if (c != a)
        {
            items[c] = items[a]; // Troca os caracteres
            items[a] = t;        // Troca os caracteres
        }
    }
}

int main(int argc, char **argv)
{
    // Array de exemplo a ser ordenado
    int arr[] = {4, 2, 1, 3, 6, 5};

    // Calcula o número de elementos no array
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função de ordenação passando o array, o tamanho do array, e os contadores
    selectionSort(arr, n);

    // Imprime o array ordenado
    printf("Sequencia de arr ordenada: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n-----------------------------------------------\n");

    // Array de caracteres (string mutável) para ordenar
    char str[] = "HELLO WORLD";

    // Obtém o comprimento da string
    int length = strlen(str);

    // Ordena a string
    selectionSortString(str, length);

    // Exibe a string ordenada
    printf("String ordenada é: %s\n", str);
    return 0;
}
