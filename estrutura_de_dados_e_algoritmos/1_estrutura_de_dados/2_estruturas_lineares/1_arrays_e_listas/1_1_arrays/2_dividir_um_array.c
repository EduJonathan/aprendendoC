#include <stdio.h>

/**
 * @brief Função que divide um array em duas partes.
 *
 * @param array O array original a ser dividido.
 * @param tamanho O tamanho total do array original.
 * @param array1 O array que armazenará a primeira metade.
 * @param array2 O array que armazenará a segunda metade.
 */
void dividirArray(int array[], int tamanho, int array1[], int array2[])
{
    int meio = tamanho / 2;

    // Copia a primeira metade para array1
    for (int i = 0; i < meio; i++)
    {
        array1[i] = array[i];
    }

    // Copia a segunda metade para array2
    for (int i = meio; i < tamanho; i++)
    {
        array2[i - meio] = array[i];
    }
}

int main(int argc, char **argv)
{
    printf("Teste com array de 10 elementos:\n");

    // Teste com array de 10 elementos (par)
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    // Array de 10 elementos
    int tamanho1 = sizeof(array1) / sizeof(array1[0]); // Tamanho do array1
    int meio1 = tamanho1 / 2;                          // Dividindo o array em duas partes
    int array1[meio1];                                 // Array para armazenar a primeira parte
    int array1[tamanho1 - meio1];                      // Array para armazenar a segunda parte

    printf("Array original: ");
    for (int i = 0; i < tamanho1; i++)
    {
        printf("%d ", array1[i]);
    }

    dividirArray(array1, tamanho1, array1, array1);

    printf("\nPrimeira parte: ");
    for (int i = 0; i < meio1; i++)
    {
        printf("%d ", array1[i]);
    }

    printf("\nSegunda parte: ");
    for (int i = 0; i < tamanho1 - meio1; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("-------------------------------\n");

    printf("Teste com array de 7 elementos:\n");

    // Teste com array de 7 elementos (ímpar)
    int array2[] = {1, 2, 3, 4, 5, 6, 7};              // Array de 7 elementos
    int tamanho2 = sizeof(array2) / sizeof(array2[0]); // Tamanho do array2
    int meio2 = tamanho2 / 2;                          // Dividindo o array em duas partes
    int array2[meio2];                                 // Array para armazenar a primeira parte
    int array2[tamanho2 - meio2];                      // Array para armazenar a segunda parte

    printf("Array original: ");
    for (int i = 0; i < tamanho2; i++)
    {
        printf("%d ", array2[i]);
    }

    dividirArray(array2, tamanho2, array2, array2);

    printf("\nPrimeira parte: ");
    for (int i = 0; i < meio2; i++)
    {
        printf("%d ", array2[i]);
    }

    printf("\nSegunda parte: ");
    for (int i = 0; i < tamanho2 - meio2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    return 0;
}
