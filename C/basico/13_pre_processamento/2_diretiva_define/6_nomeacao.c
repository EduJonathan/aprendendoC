#include <stdio.h>
#include <stdlib.h>

/**
 * CURIOSIDADES: A diretiva #define consegue renomear tipos, variáveis e funções.
 * Ela permite que vocês defina um nome alternativo para um tipo, variável ou função.
 * e até mesmo uso de funções para realizar uma operação. Como utilizar sizeof para
 * obter o tamanho de um array.
 * EXEMPLO: #define SIZE(array) (sizeof(array) / sizeof(array[0])).
 */

/* Renomeia o tipo long long para LLONG, possivel em uso em funções e declarações. */
#define LLONG long long

/* Renomeia a função printf para que ela seja chamada como __mingw_printf, permitindo
 * então uma sobrecarga da função. Pois ela irá chamar o printf, com o mesmo poder de
 * processamento que o __mingw_printf possui. NÃO é muito recomendável. */
#define printf __mingw_printf

void sizeDoArray(long double **array, LLONG *size)
{
    printf("Insira o tamanho do array: ");
    scanf("%lld", size); // Insere o tamanho do array

    // Aloca dinamicamente o array com o tamanho fornecido
    *array = (long double *)malloc(*size * sizeof(long double));

    if (*array == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1); // Sai do programa se a alocação falhar
    }
}

int main(int argc, char **argv)
{
    LLONG size = 0;
    long double *array = NULL; // Ponteiro para o array

    // Usando a função sizeDoArray para pegar o tamanho e alocar o array
    sizeDoArray(&array, &size);

    // Preenchendo o array manualmente (sem usar scanf)
    for (LLONG i = 0; i < size; i++)
    {
        array[i] = (i + 1) * 10.1; // Atribuindo valores 10.1, 20.1, 30.1, etc.
        // Utilizando o scanf seria: scanf("%Lf", &array[i]);
    }

    // Exibindo os valores do array
    printf("Valores do array:\n");
    for (LLONG i = 0; i < size; i++)
    {
        printf("array[%lld] = %.2Lf\n", i, array[i]);
    }

    // Liberando a memória alocada
    free(array);

    return 0;
}
