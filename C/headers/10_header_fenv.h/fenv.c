/** Em processo... */
#include <stdio.h>
#include <fenv.h>

/**
 * fenv(): É uma biblioteca que fornece um mecanismo para criar funções que
 * aceitam um número variável de argumentos.
 */

int main(int argc, char **argv)
{
    // Variável de ambiente
    fenv_t env;

    // Inicializa a variável de ambiente
    fegetenv(&env);

    // Imprime o status da variável de ambiente de ponto flutuante
    printf("Status da variável de ambiente de ponto flutuante: %s\n", fegetround());

    // Libera a variável de ambiente
    fesetenv(&env);
    return 0;
}
