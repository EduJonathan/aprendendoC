#include <stdio.h>

/*
 * __STDC_VERSION__: A constante inteira 199901L se a implementação estiver em conformidade
 * com C99, o padrão ANSI C de janeiro de 1999, a constate fornece a versão do padrão ANSI C
 * (ou ISO C) que o compilador segue, retonando um número inteiro.
 */

int main(int argc, char **argv)
{
#ifdef __STDC_VERSION__
    printf("O compilador está em conformidade com o padrão ANSI C %ld\n", __STDC_VERSION__);
#else
    printf("O compilador não está em conformidade com o padrão ANSI C\n");
#endif
    return 0;
}
