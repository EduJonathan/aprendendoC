#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Função de ordenação utilizando o Bubble Sort
 *
 * O algoritmo de ordenação **Bubble Sort** compara elementos adjacentes no array e os troca
 * caso estejam na ordem errada. Esse processo é repetido várias vezes até que a lista esteja
 * ordenada. A cada iteração, o maior (ou menor, dependendo da ordem) elemento "bubla" para
 * sua posição final.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor caso: O(n) -> quando o array já está ordenado, a ordenação faz apenas uma passada.
 *
 * - Pior caso: O(n^2) -> quando o array está em ordem inversa, é necessário percorrer
 * todo o array em cada iteração.
 *
 * - Caso médio: O(n^2) -> em média, o algoritmo faz várias comparações e trocas.
 *
 * Espaço:
 *
 * - O(1) -> utiliza apenas algumas variáveis auxiliares para as trocas, não dependente do tamanho do array.
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 */
void bubbleSort(int *arr, size_t n)
{
    // Variáveis para contar comparações e trocas
    size_t comparacoes = 0;
    size_t trocas = 0;

    // Loop externo que percorre o array até o penúltimo elemento
    for (size_t i = 0ull; i < n; i++)
    {
        // Variável para indicar se houve troca nesta passagem
        bool troca = false;

        // Loop para percorrer o array até o último elemento não ordenado
        for (size_t j = 0ull; j < n - i - 1; j++)
        {
            comparacoes++; // Incrementa o contador de comparações

            // Comparação de elementos adjacentes
            if (arr[j] > arr[j + 1])
            {
                // Trocar Elementos
                int temp = arr[j];   // Armazena o elemento atual
                arr[j] = arr[j + 1]; // Coloca o elemento seguinte na posição do elemento atual
                arr[j + 1] = temp;   // Coloca o elemento atual na posição do elemento seguinte

                trocas++;     // Incrementa o contador de trocas
                troca = true; // Indica que houve pelo menos uma troca nesta passagem
            }
        }

        // Verificar se houve troca nesta passagem
        if (!troca)
        {
            break; // Se não houve troca, o array já está ordenado
        }
    }

    // Exibe a quantidade de comparações e trocas
    printf("Número de comparações: %zu\n", comparacoes);
    printf("Número de trocas: %zu\n", trocas);
}

int main(int argc, char **argv)
{
    // Array de exemplo a ser ordenado
    int arr[] = {4, 2, 1, 3, 6, 5};

    // Calcula o número de elementos no array
    size_t n = sizeof(arr) / sizeof(arr[0]);

    // Chama a função de ordenação passando o array e o número de elementos
    bubbleSort(arr, n);

    // Imprime o array ordenado
    printf("Sequência de arr ordenada: ");
    for (size_t i = 0ull; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
