#include <stdio.h>

/**
 * PARAMETROS: (ou argumentos) São variáveis utilizadas para passar valores para uma
 * função durante sua chamada. São declarados entre parênteses na definição da função e
 * podem ser usados dentro do corpo da função para realizar operações. Os parâmetros
 * tornam a função mais flexível e reutilizável. Seu escopo é local, ou seja, só existem
 * dentro da função e são destruídos após a execução. Não são acessíveis fora da função,
 * a menos que haja conflito de nomes com variáveis de escopo mais amplo.
 */

/**
 * @brief Função para exibir informações sobre parâmetros
 *
 * Função com parâmetros
 *
 * @param param1 Primeiro parâmetro
 * @param param2 Segundo parâmetro
 */
void param(int param1, int param2)
{
    printf("\n Endereço de param1 : %p\n", &param1);
    printf(" Endereço de param2  : %p\n", &param2);
    printf(" Valor de param1          : %d\n", param1);
    printf(" Valor de param2          : %d\n", param2);
    printf(" Valor de param1 + param2 : %d\n", param1 + param2);
}

/**
 * @brief Calcula a soma dos elementos de um array.
 *
 * Esta função recebe um ponteiro para um array de inteiros e
 * calcula a soma dos primeiros cinco elementos desse array.
 *
 * @param ptr Ponteiro para o início do array de inteiros.
 * @return A soma dos primeiros cinco elementos do array.
 */
float somaDeArrays(float *ptr)
{
    int indice = 0;
    float total = 0;

    for (; indice < 5; indice++)
    {
        total += *(ptr + indice);
    }
    return total;
}

int main(int argc, char **argv, int soma)
{
    int n = 56;
    soma = 1 + n;
    printf(" soma = 1 + n : %d\n", soma);
    param(soma, 5);

    printf("\n===============================================\n");

    int array[6] = {200, 400, 87, 89, 90, 100}; // Array de inteiros com 6 elementos

    // int soma = 0; A variável "soma" foi declarada no parametro da função "main"

    float total = somaDeArrays(array);
    printf("Total da soma dos primeiros cinco elementos do array: %.2f\n", total);
    return 0;
}
