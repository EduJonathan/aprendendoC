#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Função que calcula a soma de dois números inteiros e retorna um ponteiro para ponteiro
 * contendo o resultado da soma.
 *
 * @param valor1 O primeiro valor inteiro a ser somado.
 * @param valor2 O segundo valor inteiro a ser somado.
 * @return Um ponteiro para um ponteiro de inteiro, onde o valor armazenado
 * é a soma dos dois números.
 */
int **calculaSomaDeDoisNumeros(int valor1, int valor2)
{
    // Aloca memória para armazenar o resultado da soma
    int *resultado = (int *)malloc(sizeof(int));

    // Verifica se a alocação de memória foi bem-sucedida
    if (resultado == NULL)
    {
        printf("Erro ao alocar memória para o resultado.\n");
        exit(EXIT_FAILURE);
    }

    // Calcula a soma e armazena no espaço de memória alocado
    *resultado = valor1 + valor2;

    // Aloca memória para armazenar o ponteiro para o resultado
    int **pResultado = (int **)malloc(sizeof(int *));

    // Verifica se a alocação de memória foi bem-sucedida
    if (pResultado == NULL)
    {
        printf("Erro ao alocar memória para o ponteiro de ponteiros.\n");
        free(resultado); // Libera a memória do resultado já alocado
        exit(EXIT_FAILURE);
    }

    // Armazena o endereço do ponteiro resultado no ponteiro para ponteiro
    *pResultado = resultado;

    // Retorna o ponteiro para ponteiro
    return pResultado;
}

int main(int argc, char **argv)
{
    int valor1 = 5;  // Primeiro valor a ser somado
    int valor2 = 10; // Segundo valor a ser somado

    // Chama a função para calcular a soma e obtém um ponteiro para ponteiro
    int **soma = calculaSomaDeDoisNumeros(valor1, valor2);

    // Imprime o resultado da soma, acessando o valor através do ponteiro para ponteiro
    printf("A soma é: %d\n", **soma);

    // Libera a memória alocada para o resultado e para o ponteiro de ponteiros
    free(*soma);
    free(soma);
    return 0;
}
