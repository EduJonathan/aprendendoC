#include <stdio.h>

/**
 * @brief Função de busca binária para encontrar o menor número em um array ordenado.
 *
 * @param array O array ordenado.
 * @param tamanho O tamanho do array.
 * @return O menor número (primeiro elemento) do array.
 */
int encontrarMenorNumero(int array[], int tamanho)
{
    // Em um array ordenado, o menor número está no primeiro índice
    return array[0];
}

/**
 * @brief Função de busca binária para encontrar o maior número em um array ordenado.
 *
 * @param array O array ordenado.
 * @param tamanho O tamanho do array.
 * @return O maior número (último elemento) do array.
 */
int encontrarMaiorNumero(int array[], int tamanho)
{
    // Em um array ORDENADO, pela lógica é o maior número por está no último índice.
    return array[tamanho - 1];
}

/**
 * @brief Função de ordenação Bubble Sort para ordenar um array.
 *
 * @param array O array a ser ordenado.
 * @param tamanho O tamanho do array.
 */
void bubbleSort(int array[], int tamanho)
{
    // Loop para percorrer o array
    for (int i = 0; i < tamanho - 1; i++)
    {
        // A cada passagem, o maior elemento "bolha" para o final
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            // Se o elemento da esquerda for maior que o da direita
            if (array[j] > array[j + 1])
            {
                // Troca os elementos
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    // Exemplo de um array ordenado
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(array) / sizeof(array[0]);

    // Encontrando o menor e maior número usando as funções
    int menor = encontrarMenorNumero(array, tamanho);
    int maior = encontrarMaiorNumero(array, tamanho);

    // Exibindo o resultado
    printf("Menor número: %d\n", menor);
    printf("Maior número: %d\n", maior);

    printf("-----------------------------------\n");

    // Exemplo em um array arrayDesordenado
    int arrayDesordenado[] = {9, 7, 5, 3, 1, 15, 13, 11};
    tamanho = sizeof(arrayDesordenado) / sizeof(arrayDesordenado[0]);

    // Encontrando o menor e maior número usando as funções
    menor = encontrarMenorNumero(arrayDesordenado, tamanho);
    maior = encontrarMaiorNumero(arrayDesordenado, tamanho);

    // Exibindo o resultado: ERRO
    printf("Menor número: %d\n", menor);
    printf("Maior número: %d\n", maior);

    printf("-----------------------------------\n");

    // Ordenando o array arrayDesordenado, pois a busca binária depende de um array ordenado
    // Se o array não estiver ordenado, use a função de ordenação Bubble Sort
    // pois se o array NÃO estiver ordenado, a busca binária falhará
    bubbleSort(arrayDesordenado, tamanho);

    // Encontrando o menor e maior número usando as funções
    menor = encontrarMenorNumero(arrayDesordenado, tamanho);
    maior = encontrarMaiorNumero(arrayDesordenado, tamanho);

    // Exibindo o resultado
    printf("Menor número: %d\n", menor);
    printf("Maior número: %d\n", maior);

    return 0;
}
