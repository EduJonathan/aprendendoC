#include <stdio.h>
#include <string.h>
// #include <malloc.h>
#include <stdlib.h>

/**
 * SINTAXE: void *malloc(size_t _Size);
 *
 * @param _Size Tamanho da memória a ser alocada.
 * @return Um ponteiro para a memória alocada. Caso a alocação falhe, ela retorna NULL.
 * A função malloc() retorna um tipo void* e alocando um número N de bytes para determinado
 * dado é recebido como parâmetros o quanto é desejado a alocando, e depois retornando o
 * endereço inicial do bloco de bytes que foi alocado, um bloco recém-alocada.
 */

/**
 * @brief Aloca memória para um único caractere.
 * Esta função aloca memória para um único caractere usando `malloc`.
 *
 * @return Um ponteiro para a memória alocada. Se a alocação falhar, retorna `NULL`.
 */
char *AlocandoComMalloc(void)
{
    // Aloca memória para um único caractere
    char *caractere = malloc(sizeof(char));
    if (caractere == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória para caractere\n");
        return NULL;
    }
    printf("Memória alocada para caractere com sucesso\n");
    return caractere;
}

/**
 * @brief Aloca memória para um array de inteiros e preenche com valores fornecidos
 * pelo usuário. Esta função aloca memória para um array de inteiros usando `malloc`,
 * preenche o array com valores fornecidos pelo usuário, e exibe os valores e suas posições
 * na memória.
 *
 * @param tamanho O número de elementos no array.
 */
void alocarArrayComMalloc(size_t tamanho)
{
    if (tamanho == 0)
    {
        fprintf(stderr, "Tamanho do array deve ser maior que zero\n");
        return;
    }

    // Aloca memória para um array de inteiros
    int *ptr = malloc(tamanho * sizeof(int));
    // chamada da função malloc para reservar espaço de acordo com o valor que
    // será o parâmetro tamanho

    if (ptr == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória\n");
        return;
    }

    printf("Memória alocada para %zu inteiros\n", tamanho);
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("Insira o valor de ptr[%zu]: ", i);
        scanf("%d", &ptr[i]);
    }

    printf("\nValores e endereços do array:\n");
    for (size_t i = 0; i < tamanho; i++)
    {
        printf("ptr[%zu] = %d, endereço: %p\n", i, ptr[i], (void *)&ptr[i]);
    }
    free(ptr);
}

/**
 * @brief Aloca memória para uma matriz de inteiros e preenche com valores fornecidos
 * pelo usuário. Esta função aloca memória para uma matriz de inteiros usando `malloc`,
 * preenche a matriz com valores fornecidos pelo usuário, e exibe a matriz.
 *
 * @param linhas O número de linhas da matriz.
 * @param colunas O número de colunas da matriz.
 * @return int** Um ponteiro para a matriz alocada ou NULL em caso de falha.
 */
int **alocandoMatrizComMalloc(size_t linhas, size_t colunas)
{
    if (linhas == 0 || colunas == 0)
    {
        fprintf(stderr, "Linhas e colunas devem ser maiores que zero\n");
        return NULL;
    }

    // Aloca memória para um array de ponteiros para linhas
    int **matriz = malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória para linhas\n");
        return NULL;
    }

    // Aloca memória para cada linha da matriz
    for (size_t i = 0; i < linhas; i++)
    {
        // Aloca memória para um array de inteiros para colunas
        matriz[i] = malloc(colunas * sizeof(int));

        // Verifica se a alocação falhou
        if (matriz[i] == NULL)
        {
            fprintf(stderr, "Falha na alocação de memória para linha %zu\n", i);

            // Libera a memória já alocada para linhas anteriores
            for (size_t j = 0; j < i; j++)
            {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }

    // Preenche a matriz com valores fornecidos pelo usuário
    printf("Insira os valores para a matriz %zu x %zu:\n", linhas, colunas);
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("matriz[%zu][%zu]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibe a matriz
    printf("\nMatriz %zu x %zu:\n", linhas, colunas);
    for (size_t i = 0; i < linhas; i++)
    {
        for (size_t j = 0; j < colunas; j++)
        {
            printf("%4d ", matriz[i][j]); // Alinhamento para melhor legibilidade
        }
        printf("\n");
    }
    return matriz; // Retorna a matriz alocada
}

/**
 * @brief Libera a memória alocada para a matriz.
 *
 * @param matriz A matriz a ser liberada.
 * @param linhas O número de linhas da matriz.
 */
void liberarMatriz(int **matriz, size_t linhas)
{
    if (matriz == NULL)
        return;
    for (size_t i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

/**
 * @brief Aloca dinamicamente memória para uma cópia da string fornecida.
 *
 * Esta função aloca memória suficiente para armazenar uma cópia da string fornecida,
 * incluindo o caractere nulo terminador. Ela copia o conteúdo da string original para a
 * nova área de memória alocada e retorna um ponteiro para essa nova string.
 *
 * @param string Ponteiro para a string a ser copiada. Esta string não deve ser alterada e
 * deve estar terminada por um caractere nulo ('\0').
 * @return Ponteiro para a nova string alocada com a cópia da string original. Retorna NULL
 * se a alocação de memória falhar.
 */
char *alocandoStringComMalloc(const char *string)
{
    if (string == NULL)
    {
        fprintf(stderr, "String de entrada é NULL\n");
        return NULL;
    }

    // Determina o comprimento da string de entrada
    size_t length = strlen(string);

    // Aloca memória para a nova string, incluindo o caractere nulo terminador
    char *alocaString = malloc((length + 1) * sizeof(char));
    if (alocaString == NULL)
    {
        fprintf(stderr, "Falha na alocação de memória para string\n");
        return NULL;
    }

    // Copia a string para a nova memória alocada
    strcpy(alocaString, string);

    // Retorna o ponteiro para a nova string alocada
    return alocaString;
}

int main(int argc, char **argv)
{
    printf("\n=== Alocação Dinâmica de Memória ===\n");

    // Alocação de um caractere
    printf("\n1. Alocando um caractere:\n");

    char *pointer = AlocandoComMalloc();
    if (pointer != NULL)
    {
        *pointer = 'A';
        printf("Valor armazenado: %c (ASCII: %d)\n", *pointer, *pointer);
        free(pointer);
    }

    // Alocação de um array
    printf("\n2. Alocando um array de inteiros:\n");
    alocarArrayComMalloc(10);

    // Alocação de uma matriz
    printf("\n3. Alocando uma matriz 3x3:\n");

    int **matriz = alocandoMatrizComMalloc(3, 3);
    if (matriz != NULL)
    {
        liberarMatriz(matriz, 3);
    }

    // Alocação de uma string
    printf("\n4. Alocando uma string:\n");

    const char *originalString = "Hello, World!";
    char *novaString = alocandoStringComMalloc(originalString);
    if (novaString != NULL)
    {
        printf("String copiada: %s\n", novaString);
        free(novaString);
    }
    return 0;
}
