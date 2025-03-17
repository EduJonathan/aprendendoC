#include <stdio.h>
#include <stdlib.h>

// Umas das características sobre o retorno de funções é, não conseguir retornar mais de
// 2 valores, array ou matrizes, Mas com ponteiro para um tipo de dado é possivel sim
// retornar. Neste exemplo estamos retornando um array

/**
 * @brief Aloca um vetor de inteiros e inicializa com valores sequenciais.
 *
 * Esta função aloca dinamicamente um vetor de inteiros com o tamanho especificado por `tam`.
 * O vetor é preenchido com valores sequenciais começando de 1 até `tam`. Se a alocação de
 * memória falhar, a função imprime uma mensagem de erro e encerra o programa.
 *
 * @param tam O número de elementos a serem alocados no vetor.
 * @return Um ponteiro para o início do vetor alocado e inicializado.
 * 
 * @note A função usa `malloc` para alocar memória e `exit` para encerrar o programa em
 * caso de falha. Lembre-se de liberar a memória alocada com `free` quando não for mais
 * necessária para evitar vazamentos de memória.
 */
int *aloca(size_t tam)
{
    // Aloca memória para o vetor de inteiros
    int *arr = (int *)malloc(tam * sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (arr == NULL)
    {
        printf("Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa o vetor com valores sequenciais
    for (int i = 0; i < tam; i++)
    {
        *(arr + i) = i + 1; // Atribui valores ao vetor (por exemplo, 1, 2, 3, ...)
    }

    // Retorna o ponteiro para o início do vetor
    return arr;
}

int main(int argc, char **argv)
{
    size_t tam = 5ULL;
    int *vetor = aloca(tam);

    // Imprimindo os valores do vetor
    printf("Valores do vetor alocado dinamicamente: ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(vetor + i));
    }
    printf("\n");

    free(vetor); // Liberando o bloco de código
    return 0;
}
