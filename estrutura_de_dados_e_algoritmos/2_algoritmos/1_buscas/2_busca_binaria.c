#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Função de ordenação utilizando bubble sort.
 *
 * O bubble sort é um algoritmo de ordenação simples que compara
 * os elementos adjacentes e os troca se estiverem na ordem errada.
 *
 * @param array Array a ser ordenado
 * @param size Tamanho do array
 */
void bubble_sort(int *array, size_t size)
{
    // Percorrendo o array
    for (size_t i = 0; i < size - 1; i++)
    {
        // Percorrendo o array
        for (size_t j = 0; j < size - i - 1; j++)
        {
            // Verificando se o elemento atual é maior que o elemento seguinte
            if (array[j] > array[j + 1])
            {
                // Troca os elementos
                int temp = array[j];

                // Colocando o elemento seguinte na posição do elemento atual
                array[j] = array[j + 1];

                // Colocando o elemento atual na posição do elemento seguinte
                array[j + 1] = temp;
            }
        }
    }
}

/**
 * @brief Função de busca binária com contagem de comparações
 *
 * O algoritmo de busca binária utiliza a teoria de divisão e
 * conquista para encontrar um elemento em um array ordenado.
 *
 * A função também conta o número de comparações feitas.
 *
 * @param array Array a ser buscado
 * @param size Tamanho do array
 * @param alvo Alvo a ser buscado
 * @return true Se o valor for encontrado
 * @return false Se o valor não for encontrado
 */
bool binary_search(int *array, size_t size, int alvo)
{
    // Variável local para contar as comparações
    int comparacoes = 0;

    // Inicializando as variáveis
    int left = 0;
    int right = size - 1;

    // Enquanto o left for menor ou igual ao right
    while (left <= right)
    {
        // Calculando o meio
        int middle = left + (right - left) / 2;

        // Incrementando a contagem de comparações
        comparacoes++;

        if (array[middle] == alvo)
        {
            // Verificando se o alvo foi encontrado
            // Imprime o número de comparações feitas
            printf("Número de comparações: %d\n", comparacoes);
            return true; // Retorne true
        }
        else if (array[middle] < alvo)
        {
            // Verificando se o alvo é maior que o meio
            // Atualiza o left, que representa o início do array
            // recursivamente ficaria binary_search(array, middle + 1, alvo);
            left = middle + 1;
        }
        else
        {
            // Verificando se o alvo é menor que o meio
            // Atualiza o right, que representa o fim do array
            // recursivamente ficaria binary_search(array, middle - 1, alvo);
            right = middle - 1;
        }
    }

    // Imprime o número de comparações feitas
    printf("Número de comparações: %d\n", comparacoes);

    // Se chegou aqui, significa que o alvo não foi encontrado
    return false;
}

int main(int argc, char **argv)
{
    // Declarando o array
    int array[6] = {1, 4, 9, 75, 6, 10};

    // Definindo o tamanho do array
    size_t size = sizeof(array) / sizeof(array[0]);

    // Valor a ser encontrado no array
    int alvo = 75;

    /**
     * OBS: É importante que o array seja ordenado primeiramente para que depois
     * seja possível realizar a busca binária. Utilizamos o bubble sort para ordenar o array,
     * mas podem utilizar outras funções de ordenação (mergesort, quicksort, etc...).
     */
    bubble_sort(array, size);

    // Variável `encontrado` para guardar o valor retornado e imprimir o resultado
    bool encontrado = binary_search(array, size, alvo);

    printf("%s\n", encontrado ? "Alvo encontrado" : "Alvo não encontrado");
    return 0;
}
