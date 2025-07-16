#include <stdio.h>
#include <stdlib.h>

/**
 * CURIOSIDADES: A diretiva #define em C pode ser usada para criar **macros** que
 * permitem renomear tipos, variáveis e até funções. Ela substitui um nome por um valor
 * ou expressão durante a pré-compilação do código. Isso pode ser útil para tornar o código
 * mais legível e reutilizável, além de facilitar manutenções e alterações.
 *
 * #define não apenas pode definir simples valores ou expressões, mas também pode envolver
 * operações, como calcular o tamanho de um vetor. Um exemplo comum é a definição de uma
 * macro para calcular o número de elementos de um array.
 *
 * EXEMPLO:
 * #define SIZE(array) (sizeof(array) / sizeof(array[0])
 */

/* Renomeia o tipo long long para LLONG, possivel em uso em funções e declarações. */
#define LLONG long long

/**
 * Renomeia a função printf para que ela seja chamada como __mingw_printf, permitindo
 * então uma sobrecarga da função. Pois ela irá chamar o printf, com o mesmo poder de
 * processamento que o __mingw_printf possui. NÃO é muito recomendável.
 */
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
    LLONG size = 0ll;          // Variável para armazenar o tamanho do array
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
