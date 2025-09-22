#include <stdio.h>
#include <string.h>

/**
 * A função `strrev()` inverte os caracteres de uma string fornecida, modificando a string original.
 * Ela começa do final da string e troca os caracteres até chegar ao início. O caractere nulo de
 * terminação `'\0'` permanece na posição correta.
 *
 * @param _Str Ponteiro para a string a ser invertida.
 *
 * @return Retorna a mesma string invertida (a string é modificada no local).
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
