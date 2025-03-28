#include <stdio.h>

/**
 * @brief Calcula a soma dos números entre a e b (excluindo a e b).
 *
 * Função recursiva para calcular a soma dos números entre a e b (excluindo a e b)
 *
 * @param a O primeiro número do intervalo.
 * @param b O segundo número do intervalo.
 * @return A soma dos números entre a e b (excluindo a e b).
 */
int somaIntervalo(int a, int b)
{
    // Caso base: quando a se torna maior ou igual a b, retorna 0
    if (a >= b - 1)
    {
        return 0;
    }

    // Caso recursivo: soma o número a + chama a função com o próximo número
    return a + somaIntervalo(a + 1, b);
}

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;

    // Solicita ao usuário os valores de a e b
    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    // Verifica se a e b são válidos
    if (a >= b)
    {
        printf("O valor de a deve ser menor que b.\n");
        return 1;
    }

    // Chama a função recursiva e exibe o resultado
    int resultado = somaIntervalo(a, b);
    printf("A soma dos números entre %d e %d (excluindo) é: %d\n", a, b, resultado);

    return 0;
}
