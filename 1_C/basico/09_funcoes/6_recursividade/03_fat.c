#include <stdio.h>

/**
 * @brief Função recursiva para calcular o fatorial de um número.
 *
 * Calcula o fatorial de um número usando recursão.
 *
 * @param n O número para o qual o fatorial será calculado.
 * @return O fatorial de n.
 * 
 * @note A função assume que n é um número inteiro não negativo.
 */
unsigned int fator(int n)
{
    if (n == 0)
    {
        // Caso base: o fatorial de 0 é 1
        return 1;
    }

    // Chamada recursiva: fatorial de n é n * fatorial de (n-1)
    return fator(n - 1) * n;
}

int main(int argc, char **argv)
{
    unsigned int res = 0;
    unsigned int num = 0;

    // Pede ao usuario o número para calcular o fatorial
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);

    // Armazena o valor do retorno na variável "res"
    res = fator(num);

    printf("O fatorial do número %d! = %d\n", num, res);
    return 0;
}
