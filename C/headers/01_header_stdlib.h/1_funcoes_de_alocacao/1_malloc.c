#include <stdio.h>
#include <string.h>
// #include <malloc.h>
#include <stdlib.h>

/**
 * Começando a partir agora a usar uma biblioteca mais utilizada a <stdlib.h>,
 * é uma biblioteca que permite usarmos funções para o sistema e nela se encontra também as
 * funções de alocações de memória sendo elas: Se encontra tanto na stdlib.h ou malloc.h
 * malloc (memory allocation)
 * realloc (realocation memory)
 * calloc
 * free (liberar)
 *
 * Alocações dinâmicas se consistem na alocação dinâmica podemos alocar espaços durante
 * a execução de um programa, ou seja, a alocação dinâmica é feita em tempo de execução.
 * permitindo que o espaço em memória seja alocado apenas quando necessário.
 * Além disso, a alocação dinâmica permite aumentar, diminuir a quantidade de memória
 * alocada. A mais utilizada nesse concenso é o malloc:
 *
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
    char *caractere = (char *)malloc(sizeof(char));

    if (caractere == NULL)
    {
        printf("O ponteiro está vazio (alocação falhou)\n");
    }
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
    // Aloca memória para um array de inteiros
    int *ptr = (int *)malloc(tamanho * sizeof(int));
    // chamada da função malloc para reservar espaço de acordo com o valor que
    // será o parâmetro tamanho

    if (ptr == NULL)
    {
        printf("Memória não alocada\n");
    }
    else
    {
        printf("Memória alocada\n");

        // Insere valores no array
        for (int i = 0; i < tamanho; i++)
        {
            printf("\nInsira o valor de ptr[%d]: ", i);
            scanf("%d", &ptr[i]);
        }

        // Exibe valores e informações de alocação
        for (int i = 0; i < tamanho; i++)
        {
            printf("\nO valor de ptr[%d] é: %d", i, ptr[i]);
            printf("\n Posição da memória ptr[%d] e: %p\tConversao do hexa em decimal: %d\n", i, &ptr[i], &ptr[i]);
        }
        free(ptr); // Libera a memória alocada
    }
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
    // Aloca memória para um array de ponteiros para linhas
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Memória não alocada para as linhas da matriz\n");
        return NULL;
    }

    // Aloca memória para cada linha da matriz
    for (size_t i = 0; i < linhas; i++)
    {
        // Aloca memória para um array de inteiros para colunas
        matriz[i] = (int *)malloc(colunas * sizeof(int));

        // Verifica se a alocação falhou
        if (matriz[i] == NULL)
        {
            printf("Memória não alocada para a linha %zu da matriz\n", i);

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
            printf("%d ", matriz[i][j]);
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
    if (matriz != NULL)
    {
        for (size_t i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }
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
    // Determina o comprimento da string de entrada
    int length = strlen(string);

    // Aloca memória para a nova string, incluindo o caractere nulo terminador
    char *alocaString = (char *)malloc((length + 1) * sizeof(char));

    // Verifica se a alocação falhou
    if (alocaString == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return NULL;
    }

    // Copia a string para a nova memória alocada
    strcpy(alocaString, string);

    // Retorna o ponteiro para a nova string alocada
    return alocaString;
}

int main(int argc, char **argv)
{
    printf("\n\tALOCANDO MEMÓRIA PARA UM PONTEIRO:\n");

    char *pointer = NULL;

    // Aloca memória e obtém o ponteiro
    pointer = AlocandoComMalloc();

    // Verifica se a alocação foi bem-sucedida antes de usar o ponteiro
    if (pointer != NULL)
    {
        *pointer = 'A';
        printf("Valor armazenado após atribuição: %d-%c\n", *pointer, *pointer);

        // Libera a memória alocada e define o ponteiro como NULL
        free(pointer);
        pointer = NULL;
    }

    printf("\n-------------------------------------------\n");
    printf("\n\tALOCANDO A MEMÓRIA PARA UM ARRAY COM O MALLOC:\n");

    // Define o tamanho do array
    size_t tamanho = 10U;

    // Chama a função para alocar, inserir e exibir o array
    alocarArrayComMalloc(tamanho);

    printf("\n-------------------------------------------\n");

    size_t linhas = 3U;
    size_t colunas = 3U;
    int **matriz = alocandoMatrizComMalloc(linhas, colunas);

    // Verifica se a alocação foi bem-sucedida
    if (matriz != NULL)
    {
        // Libera a memória da matriz
        liberarMatriz(matriz, linhas);
    }

    printf("\n-------------------------------------------\n");

    const char *originalString = "Hello, World!";
    char *novaString = alocandoStringComMalloc(originalString);

    if (novaString != NULL)
    {
        printf("Nova string: %s\n", novaString);

        // Não se esqueça de liberar a memória quando não for mais necessária
        free(novaString);
    }
    return 0;
}
