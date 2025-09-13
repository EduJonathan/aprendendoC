#include <stdio.h>
#include <string.h>

/**
 * strrev(string reverse): Função que inverte a string.
 *
 * SINTAXE: char *strrev(char *_Str);
 *
 * @param _Str Informar (string) ponteiro para char
 * @return Retorna a string invertida
 */

/**
 * @brief Imprime o uma string reversa.
 *
 * @param str Ponteiro para a string para ser informada.
 * @return Retorna a função que tem como objetivo retornar a string revertida
 */
char *printStringReversa(char *string)
{
    return strrev(string);
}

int main(int argc, char **argv)
{
    char text[] = {"Language Programming"};
    printf(" Quando invertida a string reversa fica: %s\n", printStringReversa(text));
    return 0;
}
