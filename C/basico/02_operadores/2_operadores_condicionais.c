#include <stdio.h>

/*
 * Operadores condicionais: São responsáveis por comparar valores e gerar
 * resultados booleanos (1: true) ou (0: false). sendo eles:
 *
 * -------------------------------------
 * | OPERADORES |   OPERAÇÃO           |
 * -------------------------------------
 * |    >       |  MAIOR QUE           |
 * -------------------------------------
 * |    >=      |  MAIOR OU IGUAL      |
 * -------------------------------------
 * |    <       |  MENOR QUE           |
 * -------------------------------------
 * |    <=      |  MENOR OU IGUAL      |
 * -------------------------------------
 * |    ==      |  IGUAL A (IGUALDADE) |
 * -------------------------------------
 * |    !=      |  DIFERENTE DE        |
 * -------------------------------------
 */

int main(int argc, char **argv)
{
    // Inicializando variáveis para realizar as comparações de valores de `number1` e `number2`
    int number1 = 10, number2 = 35;

    // Executando as operações condicionais comparando os valores das variáveis `number1` e `number2`
    printf(" O VALOR DE 'number1' É MAIOR QUE O VALOR DE 'number2'      : %d\n", number1 > number2);
    printf(" O VALOR DE 'number1' É MAIOR OU IGUAL O VALOR DE 'number2' : %d\n", number1 >= number2);
    printf(" O VALOR DE 'number1' É MENOR QUE O VALOR DE 'number2'      : %d\n", number1 < number2);
    printf(" O VALOR DE 'number1' É MENOR OU IGUAL O VALOR DE 'number2' : %d\n", number1 <= number2);
    printf(" O VALOR DE 'number1' É IGUAL A O VALOR DE 'number2'        : %d\n", number1 == number2);
    printf(" O VALOR DE 'number1' É DIFERENTE DO VALOR DE 'number2'     : %d\n", number1 != number2);
    return 0;
}
