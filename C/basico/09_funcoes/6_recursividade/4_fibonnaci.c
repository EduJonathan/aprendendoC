#include <stdio.h>

/**
 * @brief Calcula o número de Fibonacci para um dado número.
 *
 * @param number O número para o qual o Fibonacci será calculado.
 * @return O número de Fibonacci correspondente a "number".
 * @note A função assume que "number" é um número inteiro maior ou igual a 1.
 */
long fibonacci(long number)
{
    if (number < 1)
    {
        // Retorna 0 se "number" for menor que 1
        return 0;
    }
    if (number == 1)
    {
        // Retorna 1 se "number" for igual a 1
        return 1;
    }

    // Caso geral: Fibonacci de "number" é a soma dos Fibonacci de "number-1" e "number-2"
    return fibonacci(number - 1) + fibonacci(number - 2);
}

int main(int argc, char **argv)
{
    // Define o número para o qual será calculado o Fibonacci
    long n = 4L;

    // Imprime o Fibonacci de `n`
    printf("Fibonacci of %ld is: %ld\n", n, fibonacci(n));
    return 0;
}
