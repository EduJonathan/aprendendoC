#include <stdio.h>
#include "operacoes_aritmeticas.h"

// "": quando uma biblioteca .h está em "", significa que é diretório de projeto de sua máquina.
// <>: quando se encontra em abre '<' e fecha '>', significa que é uma biblioteca do compilador.

int main(int argc, char **argv)
{
    // Definindo valores
    float n1 = 30.0F;
    float n2 = 20.0F;

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_soma = add(n1, n2);
    printf("Resultado de %.2f + %.2f = %.2f\n", n1, n2, res_soma);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_sub = subtract(n1, n2);
    printf("Resultado de %.2f - %.2f = %.2f\n", n1, n2, res_sub);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_mult = multiply(n1, n2);
    printf("Resultado de %.2f * %.2f = %.2f\n", n1, n2, res_mult);

    // Criando variáveis para guardar o valor do retorno de cada operação.
    float res_div = divide(n1, n2);
    printf("Resultado de %.2f / %.2f = %.2f\n", n1, n2, res_div);
    return 0;
}
