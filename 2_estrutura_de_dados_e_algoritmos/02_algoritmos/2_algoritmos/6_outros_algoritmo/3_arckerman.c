#include <stdio.h>

/**
 * A função de Ackermann é uma função recursiva que cresce de maneira extremamente rápida,
 * o que a torna um excelente exemplo em matemática e ciência da computação para mostrar
 * a complexidade da recursão e o comportamento de funções com crescimento super-exponencial.
 * Esta função tem implicações em diversos campos da teoria da computação, como análise de
 * algoritmos e computabilidade.
 *
 * COMPLEXIDADE:
 * TEMPO: O(2^n), onde n é o número de chamadas recursivas.
 *
 * ESPAÇO: O(n), onde n é o número de chamadas recursivas.
 */

/**
 * @brief Calcula a função de Ackermann de forma iterativa.
 *
 * Esta implementação utiliza uma pilha (com um vetor) para simular a recursão.
 *
 * @param m Valor de entrada m.
 * @param n Valor de entrada n.
 * @return O valor resultante da função de Ackermann.
 */
long long ackermannIterativa(int m, int n)
{
    // Usamos long long porque os valores crescem extremamente rápido
    long long pilha[10000]; // Tamanho maior (ainda limitado)
    int topo = -1;

    // Empilha o par inicial (m, n)
    pilha[++topo] = m;
    pilha[++topo] = n;

    while (topo >= 0)
    {
        n = pilha[topo--]; // Desempilha n
        m = pilha[topo--]; // Desempilha m

        if (m == 0)
        {
            // Caso base: A(0, n) = n + 1
            // Mas como estamos simulando, precisamos "retornar" o valor
            // para a chamada anterior. Aqui simplificamos retornando diretamente
            // quando chegamos ao caso base principal.
            if (topo == -1)
            {
                return n + 1;
            }
            // Caso contrário, "retorna" o valor para a chamada anterior
            pilha[++topo] = n + 1;
        }
        else if (n == 0)
        {
            // A(m, 0) = A(m-1, 1)
            pilha[++topo] = m - 1;
            pilha[++topo] = 1;
        }
        else
        {
            // A(m, n) = A(m-1, A(m, n-1))
            // Precisamos empilhar: primeiro calcular A(m, n-1), depois usar esse resultado em A(m-1, ...)
            pilha[++topo] = m - 1; // Será usado depois
            pilha[++topo] = n - 1; // Calcular A(m, n-1) primeiro
            // Nota: Esta implementação iterativa simplificada ainda tem limitações
        }
    }
    return -1; // Não deve chegar aqui
}

/**
 * @brief Calcula a função de Ackermann recursivamente.
 *
 * A função de Ackermann é uma função matemática definida recursivamente que
 * cresce muito rápido.
 *
 * @param m Valor de entrada m.
 * @param n Valor de entrada n.
 * @return O valor resultante da função de Ackermann.
 */
int ackermannRecursiva(int m, int n)
{
    if (m == 0)
        return n + 1;

    if (n == 0)
        return ackermannRecursiva(m - 1, 1);

    return ackermannRecursiva(m - 1, ackermannRecursiva(m, n - 1));
}

int main(int argc, char **argv)
{
    int m = 0, n = 0;

    printf("=== Função de Ackermann A(m, n) ===\n\n");
    printf("Digite o valor de m: ");
    if (scanf("%d", &m) != 1 || m < 0)
    {
        printf("Erro: m deve ser um inteiro não-negativo.\n");
        return 1;
    }

    printf("Digite o valor de n: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Erro: n deve ser um inteiro não-negativo.\n");
        return 1;
    }

    printf("\nCalculando A(%d, %d)...\n\n", m, n);

    // ====================== AVISO ======================
    if (m >= 4 || (m == 3 && n >= 5))
    {
        printf("AVISO: Valores altos de m e n podem causar estouro de pilha ou tempo excessivo.\n");
        printf("Recomenda-se valores pequenos (m <= 3 e n <= 10).\n\n");
    }

    // Versão Recursiva (mais simples e clara)
    printf("Versão Recursiva:\n");
    long long resultadoRec = ackermannRecursiva(m, n);
    printf("A(%d, %d) = %lld\n\n", m, n, resultadoRec);

    /**
     * @note A complexidade do Ackermann pode ser calculada como O(2^n), tendo um crescimento
     * exponencial, onde `n` é o número de chamadas recursivas. Então caso você queira calcular
     * o Ackermann para um `n` grande, isso pode ser muito lento e pode exigir muita memória
     * causando um overflow. aconselho o uso de valores `n` menores, como (1 a 3).
     */
    return 0;
}
