#include <stdio.h>

/*
 * __LINE__: É o número da linha (dentro do arquivo fonte fornecido) na qual a macro__LINE__ é exibido.
 */

// Definição da macro PRINT_MACRO
#define PRINT_MACRO(str) \
    printf(" Mensagem DEBUGADA:\n %s a partir da linha %d\n", str, __LINE__)

int main(int argc, char const **argv)
{
    // Declaração e inicialização da variável `c`
    int c = 42;

    // Chamada da macro PRINT_MACRO com o argumento "Programa Iniciado"
    PRINT_MACRO("Programa Iniciado");

    // Impressão do valor da variável `c`
    printf(" Valor de c = %d\n", c);

    // Chamada da macro PRINT_MACRO com o argumento "Programa Terminado"
    PRINT_MACRO("Programa Terminado");
    return 0;
}
