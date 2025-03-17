#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Função de busca linear com contagem de comparações
 *
 * O algoritmo de busca linear percorre por todos os elementos do array,
 * e vai verificando cada elemento até o alvo ser encontrado no array,
 * contando o número de comparações feitas.
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
