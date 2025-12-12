#include <stdio.h>

/*
 * Os operadores aritmeticos: São reponsáveis por realizar as operações matemáticas
 * sendo elas soma, subtração, multiplicação, divisão e resto da divisão, seus símbolos são:
 *
 * +----------+------------------+
 * | OPERADOR |  OPERAÇÃO        |
 * +----------+------------------+
 * |    +     | SOMA             |
 * +----------+------------------+
 * |    -     | SUBTRAÇÃO        |
 * +----------+------------------+
 * |    *     | MULTIPLICAÇÃO    |
 * +----------+------------------+
 * |    /     | DIVISÃO          |
 * +----------+------------------+
 * |    %     | RESTO DA DIVISÃO |
 * +----------+------------------+
 */

int main(int argc, char **argv)
{
    // Variáveis `x` e `y` inicializadas para cada operação que irão realizar as operações
    int x = 5, y = 6;

    // Declarando variáveis de acordo com cada operação que ela vai resultar
    int soma = 0, subtracao = 0, multiplicacao = 0, divisao, modulo = 0;
    float divisao_nao_exata = 0.0F;

    // E logo em seguida atribuindo valores para cada operação com as variáveis x e y
    soma = x + y;                     // Soma de 5 + 6 = 11
    subtracao = x - y;                // Subtração de 5 - 6 = -1
    multiplicacao = x * y;            // Multiplicação de 5 * 6 = 30
    divisao = x / y;                  // Divisão de 5 + 6 = 0
    divisao_nao_exata = (float)x / y; // Resto de 5 / 6 = 0.8333...
    /**
     * Casting (ou cast): É a conversão explícita de um tipo de dado para outro, realizada
     * pelo programador. É útil quando queremos garantir que operações entre tipos diferentes
     * sejam feitas corretamente, sem perda de dados.
     *
     * Exemplo: Se dividirmos duas variáveis inteiras `x` e `y` diretamente, o resultado
     * será um número inteiro:
     *
     * ```
     * int x = 5, y = 6;
     * float divisao = x / y;  // Resultado incorreto (0)
     * Isso acontece porque `x / y` realiza uma divisão inteira.
     *
     * Para corrigir, usamos o cast:
     * ```
     * divisao = (float)x / (float)y;  // Cast para float antes da operação
     * printf("Resultado: %f\n", divisao);  // Resultado correto (0.833333)
     * ```
     *
     * O cast explícito (`(float)`) converte `x` e `y` para `float`, permitindo uma divisão
     * precisa com ponto flutuante.
     *
     * **Tipos de casting**:
     * - **Implícito**: O compilador converte tipos automaticamente (ex. de `int` para `float`).
     * - **Explícito**: O programador faz a conversão manual usando parênteses, como `(float)x`.
     *
     * O casting é fundamental para controlar a precisão e evitar perda de dados em operações.
     */
    modulo = x % y; // Resto de 5 % 6 = 5

    printf("\n\t>>EXIBINDO RESULTADOS DE CADA OPERAÇÃO<\n");

    printf(" O VALOR DA VARIÁVEL 'soma'              É : %d\n", soma);
    printf(" O VALOR DA VARIÁVEL 'subtracao'         É : %d\n", subtracao);
    printf(" O VALOR DA VARIÁVEL 'multiplicacao'     É : %d\n", multiplicacao);
    printf(" O VALOR DA VARIÁVEL 'divisão'           É : %d\n", divisao);
    printf(" O VALOR DA VARIÁVEL 'divisão_nao_exata' É : %f\n", divisao_nao_exata);
    printf(" O VALOR DA VARIÁVEL 'modulo'            É : %d\n", modulo);

    printf("\n=========================================================\n");
    printf("\n\t>>EXPRESSÕES MATEMÁTICAS<<\n");

    /**
     * ORDEM DE PROCEDÊNCIA: Assim como na matemática, na programação temos a precedência
     * de operadores que define a ordem de uma execução. A ordem de execução é determinada
     * pela seguinte prioridade:
     *
     * 1. ( ) => Operações dentro de parênteses
     * 2. +, - => Operações unárias (como -x, +x)
     * 3. *, /, % => Multiplicação, Divisão, Resto (são de mesma prioridade)
     * 4. +, - => Soma e Subtração (são de mesma prioridade)
     *
     * OBS: As operações binárias envolvem exatamente dois operandos (ex: x + y),
     * enquanto as operações unárias envolvem apenas um operando (ex: -x).
     */

    int expressao_aritmetica = 5 + 6 / 2;
    printf("O VALOR DA VARIÁVEL 'expressao_aritmetica' É: %d\n", expressao_aritmetica);
    // Expressão sem parênteses: a divisão tem precedência sobre a soma.
    // Resultado será 8, pois 6 / 2 é calculado primeiro (resultado 3), e
    // depois 5 + 3 resulta em 8.

    expressao_aritmetica = (5 + 6) / 2;
    printf("O VALOR DA VARIÁVEL 'expressao_aritmetica' COM PARENTÊSES É: %d\n", expressao_aritmetica);
    // Expressão com parênteses: a soma é realizada antes da divisão.
    // Resultado será 5, pois (5 + 6) é calculado primeiro (resultado 11),
    // e depois 11 / 2 resulta em 5.

    expressao_aritmetica = (5 + 6) / 2 * (-x);
    // (5 + 6) / 2 * (-5),
    // 11 / 2 * -5
    // 5 * -5
    // -25
    printf("O VALOR DA VARIÁVEL 'expressao_aritmetica' É : %d\n", expressao_aritmetica);
    return 0;
}
