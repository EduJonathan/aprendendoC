#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Função que calcula dois números inteiros
 *
 * @param valor1 O primeiro valor inteiro a ser somado.
 * @param valor2 O segundo valor inteiro a ser somado.
 * @param resultado Um ponteiro para um ponteiro de inteiro, onde o valor armazenado
 * é a soma dos dois números.
 */
void calculaSomaDeDoisNumeros(int valor1, int valor2, int **resultado)
{
    // Aloca memória para armazenar o resultado
    *resultado = (int *)malloc(sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (*resultado == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Calcula a soma e armazena no espaço de memória alocado
    **resultado = valor1 + valor2;
}

/**
 * @brief Função que multiplica dois valores e retorna o resultado através de um ponteiro duplo
 *
 * @param valor1 O primeiro valor a ser multiplicado.
 * @param valor2 O segundo valor a ser multiplicado.
 * @return Um ponteiro para um ponteiro de double, onde o valor armazenado é o resultado
 * da multiplicação.
 */
double **multiplica(double *valor1, double *valor2)
{
    // Aloca memória para o ponteiro duplo
    double **resultado = (double **)malloc(sizeof(double *));

    // Verifica se a alocação de memória foi bem-sucedida
    if (resultado == NULL)
    {
        return NULL;
    }

    // Aloca memória para o valor de resultado
    *resultado = malloc(sizeof(double));

    // Verifica se a alocação de memória foi bem-sucedida
    if (*resultado == NULL)
    {
        free(resultado); // Libera a memória do ponteiro
        return NULL;     // Retorna NULL
    }

    // Realiza a multiplicação
    **resultado = (*valor1) * (*valor2) + (*valor1 - *valor2);
    return resultado;
}

int main(int argc, char **argv)
{
    int valor1 = 5;
    int valor2 = 10;
    int *result = NULL; // Ponteiro para armazenar o endereço do resultado

    // Chama a função que calcula a soma e passa um ponteiro para o ponteiro do resultado
    calculaSomaDeDoisNumeros(valor1, valor2, &result);

    // Imprime o result
    printf("A soma de %d e %d é: %d\n", valor1, valor2, *result);

    // Libera a memória alocada
    free(result);

    printf("\n-------------------------------------------\n");

    double a = 0.0, b = 0.0;
    double **resultado = NULL;

    // Entrada dos valores
    printf("Digite o primeiro valor: ");
    scanf("%lf", &a);

    printf("Digite o segundo valor: ");
    scanf("%lf", &b);

    // Chama a função de multiplicação
    resultado = multiplica(&a, &b);

    // Verifica se a alocação de memória foi bem-sucedida
    if (resultado != NULL && *resultado != NULL)
    {
        // Exibe o resultado
        printf("Resultado da multiplicação: %.2f\n", **resultado);

        // Libera a memória alocada
        free(*resultado);
        free(resultado);
    }
    else
    {
        printf("Erro ao alocar memória.\n");
    }
    return 0;
}
