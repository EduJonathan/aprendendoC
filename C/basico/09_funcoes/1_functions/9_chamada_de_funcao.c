#include <stdio.h>

/*
 * Funções chamadas em outras funções, são utéis para que o código possa realizar
 * determinada instrução, fazendo somente e única dentro daquele bloco de código.
 */

/**
 * @brief Imprime uma mensagem indicando que este é o procedimento filha.
 *
 * Esta função é um exemplo de um procedimento que simplesmente imprime uma mensagem
 * indicando que é o procedimento filha.
 */
void funcaoFilha(void) { printf(" Esta é o Procedimento filha!\n"); }

/**
 * @brief Imprime uma mensagem e chama o procedimento filha.
 *
 * Esta função é um exemplo de um procedimento pai que imprime uma mensagem e então
 * chama o procedimento filha `funcaoFilha()`.
 */
void funcaoPai(void)
{
    printf(" Este é o Procedimento pai. Agora chamando o Procedimento filha...\n");
    funcaoFilha();
}

/**
 * @brief Calcula o fatorial de um número inteiro positivo.
 *
 * Esta função calcula o fatorial de um número inteiro positivo `n` usando um loop `for`.
 * O fatorial de um número `n` é o produto de todos os números inteiros de 1 até `n`.
 *
 * @param n Valor inteiro positivo para calcular o fatorial.
 * @return Resultado do cálculo do fatorial de `n`.
 */
int fatorial(int n)
{
    // fator guarda o fatorial de 'n'
    int fator = 1;

    // Loop para calcular o fatorial
    for (int i = 1; i <= n; i++)
    {
        // Multiplica 'fator' por 'i'
        fator *= i;
    }

    // Retorna o fatorial
    return fator;
}

/**
 * @brief Solicita um número ao usuário e calcula seu fatorial.
 *
 * Esta função solicita ao usuário que digite um número inteiro para calcular o fatorial.
 * Em seguida, chama a função `fatorial` para calcular o resultado e o imprime.
 *
 * @return Resultado do cálculo do fatorial do número fornecido pelo usuário.
 */
int calculaFatorial(void)
{
    int n = 0;

    printf(" Digite o número para calcular o fatorial: ");
    scanf("%d", &n);

    // resultado guarda o resultado do fatorial de 'n'
    int resultado = fatorial(n);

    printf(" Resultado do fatorial: %d\n", resultado);
    return resultado;
}

int main(int argc, char **argv)
{
    // Chama a função pai a partir da função principal
    funcaoPai();

    // Chama a função que calcula o fatorial
    calculaFatorial();
    return 0;
}
