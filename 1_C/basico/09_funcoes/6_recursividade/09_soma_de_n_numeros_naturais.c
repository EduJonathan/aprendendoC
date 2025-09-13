#include <stdio.h>

/**
 * @brief Calcula a soma dos primeiros n números naturais de forma recursiva.
 *
 * Esta função calcula a soma dos primeiros n números naturais utilizando recursão:
 *
 * - Caso base: Quando n é 0, retorna 0.
 *
 * - Caso recursivo: Retorna a soma do número atual n com a chamada recursiva para n-1.
 *
 * @param n O número até o qual calcular a soma dos números naturais.
 * @return A soma dos primeiros n números naturais.
 */
int n_natural(int n)
{
    if (n == 0)
    {
        // Caso base: se n for 0, retorna 0
        return 0;
    }
    return n_natural(n - 1) + n; // Chamada recursiva para somar n com n-1
}

int main(int argc, char **argv)
{
    int n_number = 0;
    int res = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n_number);

    res = n_natural(n_number);

    printf("Soma de %d em numeros naturais é: %d", n_number, res);
    return 0;
}
