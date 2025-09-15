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
int algoEuclids(int num1, int num2)
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
int euclidRecursivo(int num1, int num2)
{
    num1 = abs(num1); // Garantir números positivos
    num2 = abs(num2); // Garantir números positivos

    if (num2 == 0)
    {
        return num1;
    }
    return euclidRecursivo(num2, num1 % num2);
}

int main(int argc, char **argv)
{
    int numero1 = 0;
    int numero2 = 0;

    // Solicita os números ao usuário
    printf("Digite o primeiro numero inteiro: ");
    scanf("%d", &numero1);

    printf("Digite o segundo numero inteiro: ");
    scanf("%d", &numero2);

    // Exibe o resultado do MDC calculado pelas duas versões
    printf("O MDC de %d e %d (versão iterativa) é: %d\n", numero1, numero2, algoEuclids(numero1, numero2));
    printf("O MDC de %d e %d (versão recursiva) é: %d\n", numero1, numero2, euclidRecursivo(numero1, numero2));
    return 0;
}
