#include <stdio.h>
#include <stdbool.h>

/*
 * As expressões de condições múltiplas ajudam a evitar a repetição de blocos de código,
 * permitindo combinar várias verificações em uma única instrução `if`. Ao simplificar as
 * condições, é importante garantir que elas não sejam mutuamente exclusivas e que a lógica
 * do programa permaneça correta.
 *
 * Para isso, as condições devem ser formuladas de forma que cubram casos distintos sem
 * sobreposições, representando corretamente o comportamento desejado. Isso possibilita a
 * redução do código, mantendo a clareza e a funcionalidade.
 */

int main(int argc, char **argv)
{
    printf("\n\t>>IF SEM CONDICIONAL<<\n");

    int valor = 6; // Valor que será utilizado para os procedimentos de

    // Apenas uma expressão que valor % 2 calcula o resto da divisão de valor por 2.
    // Se valor for um número ímpar, o resultado de valor % 2 será 1.
    // Se valor for um número par, o resultado de valor % 2 será 0.
    bool eImpar = (valor % 2);

    if (eImpar)
    {
        printf("A CONDIÇÃO 'eImpar' é? %d\n", eImpar);
    }

    // Essa parte da expressão verifica comparando se o resultado de valor % 2 é igual a 0.
    // Se valor % 2 for 0, significa que valor é par.
    // Se valor % 2 for 1, significa que valor é ímpar.
    bool ePar = (valor % 2) == 0;

    if (ePar)
    {
        // Corrigido o texto para "A CONDIÇÃO 'ePar'"
        printf("A CONDIÇÃO 'ePar' é? %d\n", ePar);
    }

    // Qual o valor da saída?
    bool saida = (!(valor % 2));

    if (saida)
    {
        // Se a condição for verdadeira, imprime.
        // printf("A CONDIÇÃO 'saida' é? %d\n", saida);
    }

    printf("\n=======================================================\n");
    printf("\n\t>>IF COM EXPRESSÕES LÓGICA<<\n");

    int x = 5;
    int y = 10;

    if (x > 0 && y < 20)
    {
        printf("A condição é verdadeira!\n");
    }
    else
    {
        printf("A condição é falsa!\n");
    }
    // if (x > 0 && y < 20)
    // 5 > 0 && y < 20
    // true && true
    // true

    printf("\n=======================================================\n");
    printf("\n\t>>IF COM EXPRESSÕES LÓGICAS MULTIPLAS<<\n");

    int condition_mult0 = 56;
    int condition_mult1 = 23;

    if (condition_mult0 == condition_mult1 && condition_mult1 != condition_mult0)
    {
        printf("Condição Verdadeira\n");
    }
    else
    {
        printf("Condição Falsa\n");
    }
    // if (condition_mult0 == condition_mult1 && condition_mult1 != condition_mult0)
    // (56 == 23 && 23 != 56)
    // (false && true)
    // false

    printf("\n=======================================================\n");
    printf("\n\t>>EXPRESSÕES LÓGICA COM BITWISE<<\n");

    int a = 5;
    int b = 10;
    int c = 3;

    if ((a & b) || (c << 2))
    {
        printf("A condição é verdadeira!\n");
    }
    else
    {
        printf("A condição é falsa!\n");
    }
    // if ((a & b) || (c << 2))
    // (12) || (12)
    // (true) || (true)
    // true
    /// @note Qualquer número maior que zero é true

    printf("\n=======================================================\n");
    printf("\n\t>>A EXPRESSÃO É<<\n");

    int mult = 10;
    int condition3 = mult >> 1; // Valor de condition3 é : 5

    if ((condition3 == 5 || mult == 5) && (condition3 >> 3) == 1)
    {
        printf("Condição multipla é Verdadeira\n");
    }
    else
    {
        printf("Condição multipla é Falsa\n");
    }
    // if ((condition3 == 5 || mult == 5) && (condition3 >> 3) == 1)
    // (10 == 5 || 10 == 5) && (5 >> 3) == 1)
    // (false || false) && (false) == true
    // (false && false) == true
    // false
    return 0;
}
