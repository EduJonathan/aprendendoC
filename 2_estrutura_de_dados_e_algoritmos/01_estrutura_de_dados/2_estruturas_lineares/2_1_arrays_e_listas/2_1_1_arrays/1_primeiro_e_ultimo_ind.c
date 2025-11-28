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
void elementos(int array[], size_t tamanho, int *primeiroElemento, int *ElementoMeio, int *ultimoElemento)
{
    *primeiroElemento = array[0];         // Primeiro elemento
    *ElementoMeio = array[tamanho / 2];   // Elemento do meio
    *ultimoElemento = array[tamanho - 1]; // Ultimo elemento
}

int soma_extremidades(int arr[], size_t tam, size_t first_extremo, size_t second_extremo)
{
    if (first_extremo >= tam || second_extremo >= tam)
    {
        fprintf(stderr, "ERROR: índice fora do range do array!");
    }

    // Soma os elementos em posições específicas
    int soma_extremos = arr[first_extremo] + arr[second_extremo];
    return soma_extremos;
}

int main(int argc, char **argv)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t tamanho = sizeof(array) / sizeof(array[0]);

    int primeiro = 0;
    int meio = 0;
    int ultimo = 0;

    elementos(array, tamanho, &primeiro, &meio, &ultimo);

    printf("Primeiro elemento: %d\n", primeiro);

    // Resulta 6 por conta que lembrando que array começa em 0,
    // correspondendo o sexto elemento do array a posição 5
    printf("Elemento do meio: %d\n", meio);
    printf("Ultimo elemento: %d\n", ultimo);

    int soma_extremos1 = soma_extremidades(array, tamanho, 0, 9);
    printf("Soma dos extremos (array[0] = 1 + array[9] = 10) = %d\n", soma_extremos1);

    int soma_fora_do_range = soma_extremidades(array, tamanho, 0, 10);
    printf("Soma dos extremos fora do range (array[0] = 1 + array[10] = indefinido) = %d\n", soma_fora_do_range);
    return 0;
}
