#include <stdio.h>
#include <stdbool.h>

/**
 * Algoritmos de ordenação (sort): São algoritmos responsáveis por organizar os elementos
 * de uma estrutura de dados (como arrays, listas, etc.) em uma sequência definida
 * (crescente, decrescente, ou outro critério). Assim como os algoritmos de busca,
 * os de ordenação também têm peculiaridades quanto à eficiência, dependendo da estrutura
 * de dados e do caso específico de uso.
 *
 * @note Parâmetros principais para análise de algoritmos de ordenação:
 * 
 * 1. O número de elementos na estrutura (denotado por 'n'): Define o tamanho da entrada
 * e afeta a complexidade.
 * 2. A complexidade do algoritmo: Relacionada ao tempo de execução do algoritmo.
 *
 * 3. Principais tarefas de ordenação:
 * ● Comparações: Determinam se dois elementos estão na ordem correta. A quantidade de
 * comparações afeta a eficiência (exemplo: Bubble Sort, Quick Sort).
 *
 * ● Trocas: Alguns algoritmos trocam elementos de posição (exemplo: Bubble Sort, Quick Sort).
 * O número de trocas impacta o desempenho.
 *
 * ● Inserções: Algoritmos como Insertion Sort inserem elementos na posição correta dentro
 * de uma parte já ordenada.
 *
 * ● Divisão e Conquista: Algoritmos como Merge Sort e Quick Sort dividem a lista e a
 * reorganizam de maneira eficiente.
 *
 * Em geral, os algoritmos de ordenação têm uma grande importância em áreas como
 * busca binária, análise de dados e otimização, devido à sua relação com a organização dos dados.
 */

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
    for (size_t i = 0; i < n; i++)
    {
        // Variável para indicar se houve troca nesta passagem
        bool troca = false;

        // Loop para percorrer o array até o último elemento não ordenado
        for (size_t j = 0; j < n - i - 1; j++)
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
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
