#include <stdio.h>
#include <stdlib.h>

/**
 * A função div retorna uma estrutura div_t que contém dois membros.
 * O quot para o quociente e rem para o resto.
 * Nestes exemplos, numerador é dividido por denominador, e os resultados são impressos.
 *
 * SINTAXE: typedef struct _div_t div_t;
 *
 * @param numerador O valor inteiro do numerador.
 * @param denominador O valor inteiro do denominador.
 * @return Uma estrutura div_t contendo o quociente e o resto da divisão.
 * @note Se denominador == 0, o resultado é indefinido.
 * @note Se denominador for negativo, o resultado é indefinido.
 */

/**
 * @brief Calcula e imprime o quociente e o resto de uma divisão inteira.
 *
 * Esta função usa a função `div` para dividir dois números inteiros e imprime
 * o quociente e o resto.
 *
 * @param numerador O valor inteiro do numerador.
 * @param denominador O valor inteiro do denominador.
 */
void print_div_result(int numerador, int denominador)
{
    // Realiza a divisão de dois números inteiros.
    div_t Div = div(numerador, denominador);

    // Imprime o quociente da divisão.
    printf("Quociente: %d\n", Div.quot);

    // Imprime o resto da divisão.
    printf("Resto: %d\n", Div.rem);
}

/**
 * @brief Calcula e imprime o quociente e o resto de uma divisão longa.
 *
 * Esta função usa a função `ldiv` para dividir dois números longos e imprime
 * o quociente e o resto.
 *
 * @param numerador O valor longo do numerador.
 * @param denominador O valor longo do denominador.
 */
void print_ldiv_result(long numerador, long denominador)
{
    // Realiza a divisão de dois números longos.
    ldiv_t LDiv = ldiv(numerador, denominador);

    // Imprime o quociente da divisão.
    printf("Quociente: %ld\n", LDiv.quot);

    // Imprime o resto da divisão.
    printf("Resto: %ld\n", LDiv.rem);
}

/**
 * @brief Calcula e imprime o quociente e o resto de uma divisão long long.
 *
 * Esta função usa a função `lldiv` para dividir dois números long long e imprime
 * o quociente e o resto.
 *
 * @param numerador O valor long long do numerador.
 * @param denominador O valor long long do denominador.
 */
void print_lldiv_result(long long numerador, long long denominador)
{
    // Realiza a divisão de dois números long long.
    lldiv_t LLDiv = lldiv(numerador, denominador);

    // Imprime o quociente da divisão.
    printf("Quociente: %lld\n", LLDiv.quot);

    // Imprime o resto da divisão.
    printf("Resto: %lld\n", LLDiv.rem);
}

int main(int argc, char **argv)
{
    printf("DIV_T\n");
    print_div_result(15, 4);

    printf("\n-------------------------------------------\n");

    printf("LDIV_T\n");
    print_ldiv_result(123456L, 789L);

    printf("\n-------------------------------------------\n");

    printf("LLDIV_T\n");
    print_lldiv_result(5LL, 5LL);
    return 0;
}
