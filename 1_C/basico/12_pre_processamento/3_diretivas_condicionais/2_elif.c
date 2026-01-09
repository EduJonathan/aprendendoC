#include <stdio.h>

// #elif: ou else if é a diretiva condicional a mais para outra avaliação de comparação de valor.

/* Constante simbólico definida com #define. */
#define VALUE 7

/* Comparação com a diretiva #if, `VALUE` é maior que 200 se sim. */
#if VALUE > 200

/* Redefina VALUE */
#undef VALUE

/* E defina VALUE para 200 */
#define VALUE 200

/* Caso não, compare se VALUE é menor que 50 se sim. */
#elif VALUE < 50

/* Redefina VALUE.*/
#undef VALUE

/* E defina VALUE para 200. */
#define VALUE 50

/* Se não corresponder a nenhuma condição. */
#else

/* Redefina VALUE.*/
#undef VALUE

/* E defina VALUE para 100.*/
#define VALUE 100
#endif

#define VALOR_DE_VALUE() printf("O VALOR DE 'VALUE' é: %d\n", VALUE);

int main(int argc, char **argv)
{
    // Chamando a macro para exibir o valor de VALUE
    VALOR_DE_VALUE();
    return 0;
}
