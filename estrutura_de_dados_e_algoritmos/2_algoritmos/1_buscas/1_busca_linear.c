#include <stdio.h>
#include <stdbool.h>

/**
 * Algoritmos de buscas(search): São algoritmos que logicamente realizam a busca de
 * um determinado valor dentro de uma estrutura(seja array, matriz, listas, dentre outras)
 * Existem diferentes tipos de algoritmos, cada um com suas peculiaridades, complexidades
 * de tempo e espaço de execução.
 *
 * @note Para todos os algoritmos de busca, existem parâmetros principais:
 * 
 * 1. O valor a ser buscado (o alvo). *
 * 2. O tamanho da estrutura de dados (denotado por 'n').
 * 3. A complexidade do algoritmo: Relacionada ao tempo de execução da busca
 *
 * 4. Principais tarefas de busca:
 * ● Comparações: A busca normalmente envolve comparar o valor alvo com os elementos
 * da estrutura de dados. Exemplo: Na Busca Linear, cada elemento é comparado até
 * encontrar o alvo.
 *
 * ● Divisão (Busca Binária): Em buscas em estruturas ordenadas, a lista é dividida
 * recursivamente para reduzir a área de pesquisa. Exemplo: Busca Binária, onde a lista
 * é dividida ao meio em cada iteração.
 *
 * ● Acesso direto (Busca Hash): Algoritmos de busca em tabelas hash utilizam uma função
 * de hash para acessar diretamente o valor alvo.
 *
 * Cada algoritmo tem suas vantagens e desvantagens dependendo da situação e
 * da estrutura de dados utilizada.
 */

/**
 * @brief Função de busca linear com contagem de comparações
 *
 * O algoritmo de busca linear percorre todos os elementos do array,
 * verificando cada um até encontrar o valor alvo ou terminar a busca,
 * contabilizando o número de comparações realizadas.
 *
 * Complexidade:
 * Tempo:
 *
 * - Melhor caso: O(1) -> quando o alvo está na primeira posição.
 *
 * - Pior caso:   O(n) -> quando o alvo está na última posição ou não está presente.
 *
 * - Caso médio:  O(n) -> em média, o alvo está no meio do array.
 *
 * Espaço:
 *
 * - O(1) -> usa apenas variáveis auxiliares; não depende do tamanho do array.
 *
 * @param array Informar um array
 * @param size Informar o tamanho do array
 * @param alvo Informar o valor a ser encontrado no array
 * @return true Se o valor for encontrado
 * @return false Se o valor não for encontrado
 */
bool linear_search(int *array, size_t size, int alvo)
{
    // Variável local para contar as comparações
    int comparacoes = 0;

    // Percorrendo o array
    for (size_t i = 0; i < size; i++)
    {
        // Incrementando a contagem de comparações
        comparacoes++;

        // Verificando se o alvo foi encontrado
        if (array[i] == alvo)
        {
            // Imprime o número de comparações feitas
            printf("Número de comparações: %d\n", comparacoes);
            return true;
        }
    }

    // Imprime o número de comparações feitas
    printf("Número de comparações: %d\n", comparacoes);

    // Se não for encontrado, retornar false
    return false;
}

int main(int argc, char **argv)
{
    // Declarando o array
    int array[5] = {1, 4, 9, 75, 6};

    // Definindo o tamanho do array
    size_t size = sizeof(array) / sizeof(array[0]);

    // Valor a ser encontrado no array
    int alvo = 7;

    // Variável para armazenar o resultado da busca
    bool encontrado = linear_search(array, size, alvo);

    // Imprimindo o resultado da busca
    printf("%s\n", encontrado ? "Alvo encontrado" : "Alvo não encontrado");

    return 0;
}
