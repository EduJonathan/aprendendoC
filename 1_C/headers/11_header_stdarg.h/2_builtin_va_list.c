#include <stdio.h>

/*
 * __builtin_va_list: Tipo de dado usado em código C e C++ para representar uma lista
 * de argumentos de comprimento variável. Ele é geralmente usado em conjunto com macros
 * e funções que lidam com um número variável de argumentos.
 */

void minha_funcao(int num_args, ...)
{
    // Declarando uma lista de argumentos variáveis
    __builtin_va_list args;

    /*
     * __builtin_va_start é uma construção interna do compilador que implementa
     * o que va_start faz, mas de maneira mais direta, aproveitando as capacidades internas
     * do compilador.
     */
    __builtin_va_start(args, num_args);

    for (int i = 0; i < num_args; ++i)
    {
        // Usando a macro __builtin_va_arg para acessar os argumentos variáveis
        int value = __builtin_va_arg(args, int);

        // Imprimindo os argumentos
        printf("%d ", value);
    }

    // Finalizando a lista de argumentos
    __builtin_va_end(args);
}

int main(int argc, char **argv)
{
    minha_funcao(3, 1, 2, 3); // Chamando a função com três argumentos inteiros
    return 0;
}
