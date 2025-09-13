#include <stdio.h>

/**
 * @brief Realiza a soma de dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Resultado da soma de a e b.
 */
int soma(int a, int b)
{
    return a + b;
}

/**
 * @brief Realiza a subtração de dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Resultado da subtração de a e b.
 */
int subtracao(int a, int b)
{
    return a - b;
}

/**
 * @brief Realiza a multiplicação de dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Resultado da multiplicação de a e b.
 */
int multiplicacao(int a, int b)
{
    return a * b;
}

/**
 * @brief Realiza a divisão de dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Resultado da divisão de a por b. Se b for zero, retorna 0 e exibe mensagem de erro.
 */
int divisao(int a, int b)
{
    if (b == 0)
    {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return a / b;
}

/**
 * @brief Calcula o módulo da divisão de dois números inteiros.
 * 
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Resultado do módulo de a por b. Se b for zero, retorna 0 e exibe mensagem de erro.
 */
int modulo(int a, int b)
{
    if (b == 0)
    {
        printf("Erro: Módulo por zero!\n");
        return 0;
    }
    return a % b;
}

int main(int argc, char **argv)
{
    // Valores pré-definidos
    int a = 10, b = 4;

    // Array de ponteiros para funções
    int (*operacoes[5])(int, int) = {soma, subtracao, multiplicacao, divisao, modulo};

    // Nomes das operações
    char *nomes[5] = {"Soma", "Subtração", "Multiplicação", "Divisão", "Módulo"};

    // Executa cada operação e imprime o resultado
    for (int i = 0; i < 5; i++)
    {
        int resultado = operacoes[i](a, b); // Chama a função através do ponteiro
        printf("%s: %d %c %d = %d\n", nomes[i], a, "+-*/%%"[i], b, resultado);
    }

    return 0;
}
