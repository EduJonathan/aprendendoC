#include <stdio.h>
#include <stdlib.h>

/**
 * CURIOSIDADES: A diretiva `#define` permite criar *macros* que realizam substituição
 * textual durante a fase de pré-processamento. Isso significa que, antes da compilação,
 * o pré-processador substitui cada ocorrência do identificador definido pelo conteúdo
 * especificado na macro.
 *
 * Com `#define`, é possível:
 *   - criar constantes simbólicas,
 *   - definir expressões reutilizáveis,
 *   - renomear tipos e funções,
 *   - criar macros com parâmetros que se comportam como funções inline,
 *   - calcular valores em tempo de pré-processamento (ex: número de elementos de um array).
 *
 * Um exemplo clássico é criar uma macro para determinar o tamanho de um array estático:
 *
 *     #define SIZE(array) (sizeof(array) / sizeof((array)[0]))
 *
 * É importante lembrar que o pré-processador não interpreta regras da linguagem C:
 * ele apenas realiza substituições textuais. Portanto, o uso de macros deve ser feito
 * com cuidado para evitar comportamentos inesperados, ambiguidades ou conflitos.
 */

/* Renomeia o tipo long long para LLONG, possivel em uso em funções e declarações. */
#define LLONG long long

// Redireciona todas as chamadas de `printf` para `__mingw_printf`.
// Embora funcional, isso pode dificultar depuração, reduzir portabilidade e gerar confusão,
// por isso é uma prática desencorajada.
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
