#include <stdio.h>

/**
 * @brief Função que reverte um array.
 *
 * @param array O array a ser revertido.
 * @param tamanho O tamanho do array.
 */
void reverterArray(int array[], size_t tamanho)
{
    int temp = 0;

    // Loop para inverter o array até a metade
    for (int i = 0; i < tamanho / 2; i++)
    {
        // Troca de elementos opostos para inverter o array
        temp = array[i]; // Armazena temporariamente o elemento atual

        // Substitui o elemento atual pelo correspondente no final do array
        array[i] = array[tamanho - i - 1];

        // Substitui o elemento no final do array pelo armazenado temporariamente
        array[tamanho - i - 1] = temp;
    }
}

int main(int argc, char **argv)
{
    // Inicializando um array
    int array[5] = {0, 1, 2, 3, 4};
    size_t tamanho = sizeof(array) / sizeof(array[0]);

    // Imprimindo o array original
    printf("Array Original fica: ");
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }

    // Chamando a função para reverter o array
    reverterArray(array, tamanho);

    // Imprimindo o array invertido
    printf("Array Reverso fica: ");
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
