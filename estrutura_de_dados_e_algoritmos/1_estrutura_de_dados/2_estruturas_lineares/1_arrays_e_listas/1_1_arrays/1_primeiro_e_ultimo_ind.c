#include <stdio.h>

/**
 * @brief Obtém o primeiro e o último elemento de um array.
 *
 * Esta função recebe um array e seu tamanho, e armazena o primeiro
 * e o último elemento do array nos ponteiros fornecidos.
 *
 * @param array O array de inteiros a ser processado.
 * @param tamanho O tamanho do array.
 * @param primeiro Ponteiro para armazenar o primeiro elemento do array.
 * @param ultimo Ponteiro para armazenar o último elemento do array.
 */
void primeiro_ultimo_indice(int array[], size_t tamanho, int *primeiroElemento, int *ultimoElemento)
{
    *primeiroElemento = array[0];         // Primeiro elemento
    *ultimoElemento = array[tamanho - 1]; // Ultimo elemento
}

int main(int argc, char **argv)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t tamanho = sizeof(array) / sizeof(array[0]);

    int primeiro = 0;
    int ultimo = 0;

    primeiro_ultimo_indice(array, tamanho, &primeiro, &ultimo);

    printf("Primeiro elemento: %d\n", primeiro);
    printf("Ultimo elemento: %d\n", ultimo);
    return 0;
}
