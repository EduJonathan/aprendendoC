#include <stdio.h>

/**
 * @brief Calcula o fatorial usando apenas um return com operador ternário.
 *
 * @param n Número inteiro não negativo.
 * @return Fatorial de n.
 */
unsigned int fator(unsigned int n)
{
    return (n == 0 || n == 1) ? 1 : n * fator(n - 1);
}

int main(int argc, char **argv)
{
    unsigned int num = 0;

    printf("Digite um número inteiro não negativo: ");
    if (scanf("%u", &num) != 1)
    {
        fprintf(stderr, "Entrada inválida.\n");
        return 1;
    }

    printf("O fatorial de %u! = %u\n", num, fator(num));
    return 0;
}
