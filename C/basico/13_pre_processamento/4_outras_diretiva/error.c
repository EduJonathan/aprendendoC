#include <stdio.h>

/**
 * Diretiva #erro: impede o programa continuar com a execução devido há um erro de lógica,
 * gerando uma mensagem de erro, se a codição especificada não for atingida.
 */

// Define a constante VALOR com o valor 7
#define VALOR 7

// Verifica se VALOR é igual a 8
#if VALOR == 8

// Se VALOR for 8, define a macro EXIBE_VALOR() para imprimir o valor de VALOR
#define EXIBE_VALOR() printf("A constante de valor é: %d\n", VALOR);

// Se VALOR não for 8, verifica se VALOR é igual a 10
#elif VALOR == 10

// Se VALOR for 10, define a macro EXIBE_VALOR() para imprimir o valor de VALOR
#define EXIBE_VALOR() printf("A constante de valor é: %d\n", VALOR);

// Se VALOR não for 8 nem 10, verifica se VALOR é igual a 9
#elif VALOR == 9

// Se VALOR for 9, define a macro EXIBE_VALOR() para imprimir o valor de VALOR
#define EXIBE_VALOR() printf("A constante de valor é: %d\n", VALOR);

// Se VALOR não for igual a 8, 9 ou 10
#else

// Gera um erro de compilação com a mensagem "Valor constante não atingido!", tão tal que o código não
// será compilado e muito menos executado no terminal
#error Valor constante não comparado com sucesso!

#define VALUE1 1
#define VALUE2 1

#if (!defined(VALUE1) && !defined(VALUE2))
#error ERROR
#endif

#endif
