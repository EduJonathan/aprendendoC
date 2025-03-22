#include <stdio.h>

/**
 * @brief Procedimento para encontrar o maior e o menor número número de um array
 *
 * Função para encontrar o maior e o menor número de um array
 *
 * @param arr O array de números
 * @param maior O ponteiro para o maior número encontrado
 * @param menor O ponteiro para o menor número encontrado
 */
void maior_e_menor(int *arr, int *maior, int *menor, size_t tamV)
{
    // Inicializando com o primeiro elemento do array
    *maior = arr[0];
    *menor = arr[0];

    // Iterando sobre o array para encontrar o maior e o menor número
    // porque o i começa com 1? por conta dos ponteiros maior e menor que já apontam
    // para o primeiro elemento do índice array `arr`.
    for (int i = 1; i < tamV; i++)
    {
        // Verificando se o elemento atual é maior que o máximo encontrado até agora
        if (arr[i] > *maior)
        {
            *maior = arr[i]; // Atualizando o valor máximo
        }

        // Verificando se o elemento atual é menor que o mínimo encontrado até agora
        if (arr[i] < *menor)
        {
            *menor = arr[i]; // Atualizando o valor mínimo
        }
    }

    printf("Na função: Ender. de Menor: %p\tEnder. de Maior: %p\n", &menor, &maior);
    printf("Na função: Ender. atribuido para Menor: %p\tEnder. atribuido para Maior: %p\n", menor, maior);
    printf("Na função: Menor: %d\tMaior: %d\n", *menor, *maior);
}

int main(int argc, char **argv)
{
    int array[4] = {-9, 0, 36, 45};
    size_t n_Elementos = sizeof(array) / sizeof(array[0]);
    int max;
    int min;

    maior_e_menor(array, &max, &min, n_Elementos);

    printf("\nNa função Main(): Menor: %d\tMaior: %d\n", min, max);
    printf("Na função Main(): Ender. de Menor: %p\tEnder. de Maior: %p\n", &min, &max);
    return 0;
}
