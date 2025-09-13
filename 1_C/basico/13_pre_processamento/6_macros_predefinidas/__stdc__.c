#include <stdio.h>

/* __STDC__: A constante inteira 1 se o compilador estiver em conformidade com o padrão ANSI.*/

/* Definindo a macro que exibe a conformidade com o padrão ANSI C*/
#define CHECA_CONFORMIDADE_DO_COMPILADOR()                                     \
    if (__STDC__)                                                              \
    {                                                                          \
        printf("O compilador está em conformidade com o padrão ANSI C\n");     \
    }                                                                          \
    else                                                                       \
    {                                                                          \
        printf("O compilador não está em conformidade com o padrão ANSI C\n"); \
    }

int main(int argc, char **argv)
{
    // Chamando a Macro para checar o compilador
    CHECA_CONFORMIDADE_DO_COMPILADOR();
    return 0;
}
