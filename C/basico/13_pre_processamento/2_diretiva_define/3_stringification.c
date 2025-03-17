#include <stdio.h>

/**
 * O operador '#' (stringification), converte o argumento de uma macro em uma string literal.
 * No caso, #a e #b convertem os parâmetros a e b em strings, independente seja número ou não,
 * são então concatenadas sendo string com outras strings na função printf.
 */
#define STRINGIFICATION(a, b) \
    printf(#a " e " #b ": Nós te amamos!\n")

int main(int argc, char **argv)
{
    STRINGIFICATION("Carol", "Debora");
    return 0;
}
