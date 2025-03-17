#include <stdio.h>

// Definições iniciais
#define FALSE 1
#define TRUE 0

// Aqui temos uma condição dentro da diretiva #if que é uma expressão que será
// avaliada como verdadeira (não zero) ou falsa (zero).
// OBS.: NÃO ESTAMOS REALIZANDO COMPARAÇÃO E SIM UMA EXPRESSÃO DIRETA se tratando
// se o valor da expressão é verdadeira ou falsa.
#if TRUE

/* Não será atingido */
#undef TRUE
#define TRUE 1

#else
/* Será atingido */
#undef FALSE
#define FALSE 0
#endif

// Definição da macro VALOR_ATINGIDO
#define VALOR_ATINGIDO() printf("VALOR ATINGIDO FOI: %d\n", (TRUE || FALSE) ? TRUE : FALSE);

/**
 * @brief Função que usa a macro VALOR_ATINGIDO para informar qual o valor que
 * foi atingido primeiramente.
 */
void imprimeOprimeiroValorAtingido(void)
{
    VALOR_ATINGIDO();
}

// Redefinições de FALSE e TRUE
#undef FALSE
#undef TRUE

// Declarando as constantes novamentes
#define FALSE 1
#define TRUE 0

/* Dessa vez a diretiva #if se encontra realizando uma comparação. */
#if TRUE != 1

/* Redefina TRUE */
#undef TRUE

/* Declare novamente o valor simbólico. */
#define TRUE 1

/* Redefina a macro VALOR_ATINGIDO() */
#undef VALOR_ATINGIDO

/* Declare novamente para realizar a operação do valor que foi atingido na condicional.*/
#define VALOR_ATINGIDO() printf("VALOR ATINGIDO FOI: %d\n", (TRUE || FALSE) ? TRUE : FALSE);
#else
// Não executado porque a condição #if é 'true'
#undef FALSE
#define FALSE 0
#endif

int main(int argc, char **argv)
{
    // Chama a função que usa a macro VALOR_ATINGIDO
    imprimeOprimeiroValorAtingido();

    // Chama a macro VALOR_ATINGIDO diretamente
    VALOR_ATINGIDO();
    return 0;
}
