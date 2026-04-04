#include <stdio.h>
#include <stdlib.h>

/**
 * Euclid's Algorithm: implementação do cálculo do Máximo Divisor Comum (MDC) entre dois
 * números inteiros usando duas versões do Algoritmo de Euclides: uma iterativa e outra recursiva.
 *
 * COMPLEXIDADE:
 * TEMPO:
 * O Algoritmo de Euclides tem complexidade 𝑂(log(min(𝑚, 𝑛))), onde 𝑚 e 𝑛 são os números
 * para os quais o MDC está sendo calculado. Isso ocorre porque a cada iteração ou chamada
 * recursiva o valor de um dos números diminui substancialmente.
 *
 * ESPAÇO:
 * Versão Iterativa: O espaço utilizado é 𝑂(1), pois não há armazenamento adicional
 * além das variáveis necessárias.
 * Versão Recursiva: O espaço utilizado é 𝑂(log⁡(min(𝑚, 𝑛))) devido à pilha de chamadas recursivas.
 */

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) entre dois números inteiros
 *        usando o Algoritmo de Euclides de forma iterativa.
 *
 * O Algoritmo de Euclides calcula o MDC entre dois números através de
 * iterações sucessivas utilizando a fórmula: MDC(m, n) = MDC(n, m % n)
 * O processo continua até que o valor de n se torne zero, quando o valor
 * de m será o MDC.
 *
 * @param num1 O primeiro número inteiro.
 * @param num2 O segundo número inteiro.
 * @return O valor do MDC entre num1 e num2.
 */
int mdcIterativo(int num1, int num2)
{
    num1 = abs(num1); // Garantir números positivos
    num2 = abs(num2); // Garantir números positivos

    while (num2 > 0)
    {
        int resto = num1 % num2;
        num1 = num2;
        num2 = resto;
    }
    return num1;
}

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) entre dois números inteiros
 *        usando o Algoritmo de Euclides de forma recursiva.
 *
 * A versão recursiva do Algoritmo de Euclides chama a si mesma até que
 * o segundo número se torne zero. A recursão ocorre utilizando a
 * fórmula: MDC(m, n) = MDC(n, m % n).
 *
 * @param num1 O primeiro número inteiro.
 * @param num2 O segundo número inteiro.
 * @return O valor do MDC entre num1 e num2.
 */
int mdcRecursivo(int num1, int num2)
{
    num1 = abs(num1); // Garantir números positivos
    num2 = abs(num2); // Garantir números positivos

    if (num2 == 0)
    {
        return num1;
    }
    return mdcRecursivo(num2, num1 % num2);
}

/**
 * @brief Exibe o resultado de forma formatada
 *
 * @param num1 Informa o primeiro valor
 * @param num2 Informa o primeiro valor
 */
void exibirResultado(int num1, int num2)
{
    printf("\n=== Resultado do Algoritmo de Euclides ===\n");
    printf("Números: %d e %d\n\n", num1, num2);

    printf("MDC (versão iterativa)  : %d\n", mdcIterativo(num1, num2));
    printf("MDC (versão recursiva) : %d\n", mdcRecursivo(num1, num2));

    // Verificação extra (opcional)
    if (mdcIterativo(num1, num2) == mdcRecursivo(num1, num2))
    {
        printf("\nAs duas implementações retornaram o mesmo resultado.\n");
    }
    else
    {
        printf("\nErro: as implementações divergem!\n");
    }
}

int main(int argc, char **argv)
{
    int numero1 = 0, numero2 = 0;

    printf("=== Algoritmo de Euclides - MDC (GCD) ===\n\n");

    // Entrada do usuário
    printf("Digite o primeiro número inteiro : ");
    if (scanf("%d", &numero1) != 1)
    {
        printf("Erro: Entrada inválida.\n");
        return 1;
    }

    printf("Digite o segundo número inteiro  : ");
    if (scanf("%d", &numero2) != 1)
    {
        printf("Erro: Entrada inválida.\n");
        return 1;
    }

    // Proteção contra divisão por zero (embora o algoritmo já trate)
    if (numero1 == 0 && numero2 == 0)
    {
        printf("\nMDC(0, 0) não está definido.\n");
        return 0;
    }

    exibirResultado(numero1, numero2);

    // Exemplos adicionais para demonstração
    printf("\n=== Exemplos adicionais ===\n");
    printf("MDC(48, 18)     = %d\n", mdcIterativo(48, 18));
    printf("MDC(1071, 462)  = %d\n", mdcIterativo(1071, 462));
    printf("MDC(0, 25)      = %d\n", mdcIterativo(0, 25));
    printf("MDC(-56, 32)    = %d\n", mdcIterativo(-56, 32));
    return 0;
}
