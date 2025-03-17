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
int ackermannIterativa(int m, int n)
{
    int pilha[100]; // Usando uma pilha para simular o problema de ackermann
    int topo = -1;  // Inicializando o topo da pilha como -1

    pilha[++topo] = m; // Inserindo os valores m e n na pilha
    pilha[++topo] = n; // Inserindo os valores m e n na pilha

    // Enquanto o topo da pilha for maior ou igual a 0
    while (topo >= 0)
    {
        n = pilha[topo--]; // Decrementando o topo da pilha
        m = pilha[topo--]; // Decrementando o topo da pilha

        if (m == 0)
        {
            // Se m == 0, retorna n + 1
            return n + 1;
        }
        else if (n == 0)
        {
            pilha[++topo] = m - 1; // Se n == 0, insere m - 1 na pilha
            pilha[++topo] = 1;     // Insere 1 na pilha
        }
        else
        {
            pilha[++topo] = m - 1; // Insere m - 1 na pilha
            pilha[++topo] = n - 1; // Insere n - 1 na pilha
        }
    }

    // Caso final se m == 0, retorna n + 1
    return n + 1;
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
int ackermannRecursiva(int mValor, int nValor)
{
    if (mValor == 0)
    {
        return nValor + 1;
    }
    else if (nValor == 0 && mValor > 0)
    {
        return ackermannRecursiva(mValor - 1, 1);
    }

    return ackermannRecursiva(mValor - 1, ackermannRecursiva(mValor, nValor - 1));
}

int main(int argc, char **argv)
{
    int valorM = 0;
    int valorN = 0;

    printf("Digite o valor de m: ");
    scanf("%d", &valorM);

    printf("Digite o valor de n: ");
    scanf("%d", &valorN);

    // Calcula e imprime o resultado usando a versão recursiva
    int resultadoRecursivo = ackermannRecursiva(valorM, valorN);
    printf("Resultado da função de Ackermann (recursiva): %d\n", resultadoRecursivo);

    // Calcula e imprime o resultado usando a versão iterativa
    int resultadoIterativo = ackermannIterativa(valorM, valorN);
    printf("Resultado da função de Ackermann (iterativa): %d\n", resultadoIterativo);

    /**
     * @note A complexidade do Ackermann pode ser calculada como O(2^n), tendo um crescimento
     * exponencial, onde `n` é o número de chamadas recursivas. Então caso você queira calcular
     * o Ackermann para um `n` grande, isso pode ser muito lento e pode exigir muita memória
     * causando um overflow. aconselho o uso de valores `n` menores, como (1 a 3).
     */
    return 0;
}
