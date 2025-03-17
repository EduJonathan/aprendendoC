#include <stdio.h>

// defined: Equivalente ao #ifdef verifica se uma macro está definida
#define MSG 4

#if defined(MSG)
#if MSG == 4

#define MACRO_DEFINIDO() \ 
    printf("A condição é verdadeira");

#endif
#endif

// !defined: Equivalente ao #ifndef Verifica se a macro MESSAGE não estiver definida
// (ou seja, se a condição for verdadeira) !defined(MESSAGE), então a linha #define
// MESSAGE "You wish!" é executada.
#if !defined(MESSAGE)

#define MESSAGE "You wish!"

#endif

// Expressão condicional que combina o uso de defined() e operadores lógicos para determinar
// se um bloco de código deve ser executado. a condição (defined(VALOR1) || !defined(VALOR2))
// será verdadeira. Assim como VALOR1 está definido como 0 e VALOR2 está definido como 1,
// a expressão defined(VALOR1) é verdadeira (porque VALOR1 está definido) e !defined(VALOR2)
// é falso (porque VALOR2 está definido).
#define VALOR1 0
#define VALOR2 1

#if (defined(VALOR1) || !defined(VALOR2))

#define CONDICAO() \ 
    printf("A condição é verdadeira");

#endif

int main(int argc, char **argv)
{
    MACRO_DEFINIDO();
    printf("A mensagem é: %s\n", MESSAGE);
    CONDICAO();
    return 0;
}
