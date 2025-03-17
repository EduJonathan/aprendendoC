#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que mescla dois arrays concatenando seus elementos em um único array.
 *
 * @param array1 O primeiro array a ser mesclado.
 * @param array2 O segundo array a ser mesclado.
 * @param tamanho1 O tamanho do primeiro array.
 * @param tamanho2 O tamanho do segundo array.
 * @param arrayMesclado O array resultante da mesclagem dos dois arrays.
 */
void mesclarArrays(int array1[], int array2[], int tamanho1, int tamanho2, int arrayMesclado[])
{
    int i = 0; ///< Índice para percorrer o primeiro array.
    int j = 0; ///< Índice para percorrer o segundo array.

    // Copia os elementos de array1 para arrayMesclado
    for (i = 0; i < tamanho1; i++)
    {
        arrayMesclado[i] = array1[i];
    }

    // Copia os elementos de array2 para arrayMesclado, após os elementos de array1
    for (j = 0; j < tamanho2; j++)
    {
        arrayMesclado[i + j] = array2[j];
    }
}

/**
 * @brief Função auxiliar que ordena duas metades de um array.
 *
 * @param array O array a ser ordenado.
 * @param esq O índice da extremidade esquerda do array.
 * @param meio O índice do meio do array.
 * @param dir O índice da extremidade direita do array.
 */
void merge(int array[], int esq, int meio, int dir)
{
    int tamanhoEsq = meio - esq + 1; ///< Tamanho da subarray à esquerda
    int tamanhoDir = dir - meio;     ///< Tamanho da subarray à direita

    int arrayEsq[tamanhoEsq]; ///< Subarray à esquerda
    int arrayDir[tamanhoDir]; ///< Subarray à direita

    // Copia os dados para os arrays temporários
    for (int i = 0; i < tamanhoEsq; i++)
    {
        arrayEsq[i] = array[esq + i];
    }

    for (int i = 0; i < tamanhoDir; i++)
    {
        arrayDir[i] = array[meio + 1 + i];
    }

    int i = 0;   ///< Índice para os arrays temporários
    int j = 0;   ///< Índice para os arrays temporários
    int k = esq; ///< Índice para o array original

    // Mescla os dois arrays temporários de volta para o array original
    while (i < tamanhoEsq && j < tamanhoDir)
    {
        if (arrayEsq[i] <= arrayDir[j])
        {
            array[k] = arrayEsq[i]; // Copia o elemento do arrayEsq
            i++;                    // Incrementa o Índice do arrayEsq
        }
        else
        {
            array[k] = arrayDir[j]; // Copia o elemento do arrayDir
            j++;                    // Incrementa o Índice do arrayDir
        }
        k++;
    }

    // Copia os elementos restantes do arrayEsq, se houver
    while (i < tamanhoEsq)
    {
        array[k] = arrayEsq[i]; // Copia o elemento
        i++;                    // Incrementa o Índice
        k++;                    // Incrementa o Índice
    }

    // Copia os elementos restantes do arrayDir, se houver
    while (j < tamanhoDir)
    {
        array[k] = arrayDir[j]; // Copia o elemento
        j++;                    // Incrementa o Índice
        k++;                    // Incrementa o Índice
    }
}

/**
 * @brief Função que ordena um array utilizando o algoritmo Merge Sort.
 *
 * @param array O array a ser ordenado.
 * @param esquerda O índice inicial do array.
 * @param direita O índice final do array.
 */
void mergeSort(int array[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = (esquerda + direita) / 2;   ///< Índice do meio do array
        mergeSort(array, esquerda, meio);      ///< Ordena a primeira metade
        mergeSort(array, meio + 1, direita);   ///< Ordena a segunda metade
        merge(array, esquerda, meio, direita); ///< Mescla as duas metades ordenadas
    }
}

int main(int argc, char **argv)
{
    // Definição dos dois arrays a serem mesclados e ordenados
    int array1[] = {1, 3, 5};
    int array2[] = {2, 4, 6, 7};

    // Tamanho de cada array e o tamanho total após mesclagem
    int tamanho1 = sizeof(array1) / sizeof(array1[0]);
    int tamanho2 = sizeof(array2) / sizeof(array2[0]);
    size_t tamanhoTotal = tamanho1 + tamanho2;

    // Array para armazenar o array mesclado
    int arrayMesclado[tamanhoTotal];

    // Mescla os dois arrays sem ordenar
    mesclarArrays(array1, array2, tamanho1, tamanho2, arrayMesclado);

    // Exibe o array mesclado
    printf("Array mesclado: ");
    for (size_t i = 0; i < tamanhoTotal; i++)
    {
        printf("%d ", arrayMesclado[i]);
    }
    printf("\n");

    // Ordena o array mesclado
    mergeSort(arrayMesclado, 0, tamanhoTotal - 1);

    // Exibe o array mesclado e ordenado
    printf("Array mesclado e ordenado: ");
    for (size_t i = 0; i < tamanhoTotal; i++)
    {
        printf("%d ", arrayMesclado[i]);
    }
    printf("\n");
    return 0;
}
