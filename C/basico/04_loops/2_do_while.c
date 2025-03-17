#include <stdio.h>

/**
 * DOWHILE: Ou faça enquanto é uma estrutura de controle de fluxo semelhante à instrução
 * "while", mas com uma diferença importante: o código dentro do loop é executado pelo
 * menos uma vez, O laço é útil para situações onde você precisa garantir que o código
 * dentro do loop seja executado pelo menos uma vez, independentemente da condição.

 * SINTAXE:
 * do
 * {
 *    // instrução
 * } while (// condição);
 */

int main(int argc, char **argv)
{
    printf("\n\tEXEMPLO 01: DO-WHILE<<\n");

    // Declarando uma variavel inicializada com 4
    int number = 4;

    // Aqui temos o do-while, a qual dentro de seu escopo, temos:
    do
    {
        number--; // A variável number que está sendo decrementada e ela irá.
        if (number % 2 == 0)
        {
            continue; // Se 'number' for par, continua para a próxima iteração
        }
        printf("Number é >> %d\n", number); // Se 'number' for ímpar, imprime seu valor
    } while (number >= 0);

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 02: DO-WHILE SIMPLES<<\n");

    // Variável `i` declarada com valor 0 e esse valor será incrementado até
    int i = 0;

    do
    {
        printf("%d ", i); // Imprima o valor a cada iteração
        i++;              // Incremente 'i' enquanto o valor não for menor que 10
    } while (i < 10);

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 03: DO-WHILE SIMPLES COM OPERADORES BITWISE<<\n");

    int numero = 1;    // Começa com um número inicial que não é múltiplo de 16
    int multiplo = 16; // O múltiplo que queremos verificar

    // O loop continuará enquanto o número não for múltiplo de 16
    do
    {
        // Verifica se 'numero' é múltiplo de 16 usando o operador bitwise AND
        if ((numero & (multiplo - 1)) == 0)
        {
            printf("%d é múltiplo de %d\n", numero, multiplo);
        }
        else
        {
            printf("%d não é múltiplo de %d\n", numero, multiplo);
        }
        numero++; // Incrementa o número
    } while ((numero & (multiplo - 1)) != 0); // Continua até que 'numero' seja múltiplo de 16

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 04: DO-WHILE ANINHADO<<\n");

    // Inicializa a variável `linhas` com 1. Esta variável controlará o número da
    // linha na tabela de multiplicação.
    int linhas = 1;

    do
    {
        // Inicializa a variável 'colunas' com 1 dentro do loop externo. Esta variável
        // controlará o número da coluna na tabela de multiplicação.
        int colunas = 1;

        do
        {
            printf("%d\t", linhas * colunas); // Imprime o produto de 'linhas' e 'colunas'.

            colunas++; // Incrementa 'colunas' para o próximo valor na linha atual.
        } while (colunas <= 5); // Continua o loop interno enquanto 'colunas' for menor ou igual a 5.

        printf("\n"); // Imprima nova linha

        // Incrementa 'linhas' para o próximo valor na tabela, preparando para a próxima linha.
        linhas++;

    } while (linhas <= 5); // Continua o loop externo enquanto 'linhas' for menor ou igual a 5.

    /*
     * Neste exemplo, o uso do do-while garante que o corpo do loop é executado pelo menos
     * uma vez, mesmo que a condição seja falsa inicialmente. O loop externo (linhas)
     * controla as linhas, enquanto o loop interno (colunas) controla as colunas.
     * O programa imprime os produtos linhas colunas na forma de uma tabela 5x5.
     */
    return 0;
}
