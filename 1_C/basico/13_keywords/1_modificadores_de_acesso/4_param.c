#include <stdio.h>

/**
 * PARÂMETROS:
 * São variáveis declaradas na definição de uma função e servem para receber os valores
 * enviados no momento da chamada da função (esses valores são chamados de ARGUMENTOS).
 *
 * Os parâmetros tornam a função flexível e reutilizável, pois permitem que dados externos
 * sejam utilizados dentro dela.
 *
 * Cada parâmetro possui escopo local: existe apenas dentro da função onde foi declarado e
 * é destruído quando a função termina. Caso tenha o mesmo nome de uma variável externa,
 * ocorre sombreamento (shadowing): o parâmetro esconde a variável externa dentro da função.
 */

/**
 * @brief Exibe informações sobre parâmetros recebidos.
 *
 * @param param1 Primeiro parâmetro inteiro.
 * @param param2 Segundo parâmetro inteiro.
 */
void param(int param1, int param2)
{
    printf("\n Endereço de param1         : %p\n", (void *)&param1);
    printf(" Endereço de param2         : %p\n", (void *)&param2);
    printf(" Valor de param1            : %d\n", param1);
    printf(" Valor de param2            : %d\n", param2);
    printf(" Soma de param1 + param2    : %d\n", param1 + param2);
}

/**
 * @brief Calcula a soma dos primeiros cinco elementos de um array de floats.
 *
 * @param ptr Ponteiro para o início do array.
 * @return A soma dos cinco primeiros elementos.
 */
float somaDeArrays(float *ptr)
{
    float total = 0;

    for (int indice = 0; indice < 5; indice++)
    {
        total += ptr[indice];
    }

    return total;
}

int main(int argc, char **argv)
{
    int n = 56;
    int soma = 1 + n;

    printf(" soma = 1 + n : %d\n", soma);
    param(soma, 5);

    printf("\n===============================================\n");

    float array[6] = {200, 400, 87, 89, 90, 100};
    float total = somaDeArrays(array);
    printf("Total dos 5 primeiros elementos: %.2f\n", total);

    return 0;
}
