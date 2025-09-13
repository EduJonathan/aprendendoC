#include <stdio.h>
#include <stdbool.h>

/**
 * IF: Controles de fluxo que permitem a execução condicional de um bloco de código
 * com base em uma condição booleana (verdadeira ou falsa), executando a instrução se for true.
 *
 * SINTAXE:
 * if (condição)
 * {
 *    // instruções
 * }
 */

int main(int argc, char **argv)
{
    /* Declarando e inicializando duas variáveis. */
    int number0 = 10, number1 = 5;

    printf("\n\t>>IF UNIDIRECIONAL (IF)<<\n");

    // Exemplo de IF simples (unidirecional)
    if (number0 > number1)
        printf("O VALOR DE 'number0' É MAIOR QUE O VALOR DE 'number1'\n");
    if (number1 < number0)
        printf("O VALOR DE 'number1' É MENOR QUE O VALOR DE 'number0'\n");
    if (number0 == number1)
        printf("O VALOR DE 'number0' É IGUAL AO VALOR DE 'number1'\n");

    /**
     * O "IF UNIDIRECIONAL" executa uma instrução apenas se a condição for verdadeira.
     * Caso contrário, ele ignora a instrução. Se a condição não for satisfeita,
     * nenhuma instrução será executada.
     */

    printf("\n====================================================\n");
    printf("\n\t>>IF BIDIRECIONAL (ELSE)<<\n");

    // Exemplo de IF com ELSE (bidirecional)
    if (number0 < number1)
        printf("O VALOR DE 'number0' É MENOR QUE O VALOR DE 'number1'\n");
    else
        printf("O VALOR DE 'number0' NÃO É MENOR QUE O VALOR DE 'number1'\n");

    /**
     * O "IF BIDIRECIONAL" tem duas opções: se a condição for verdadeira,
     * executa o bloco do "if", caso contrário, executa o bloco do "else".
     */

    printf("\n====================================================\n");
    printf("\n\t>>IF MULTIDIRECIONAL (ELSE-IF)<<\n");

    int current_year = 2023;                    // Ano atual
    int last_year = 2022;                       // Último ano
    bool condition1 = current_year > last_year; // Verifica se current_year é maior
    bool condition2 = last_year > current_year; // Verifica se last_year é maior

    // Usando negação (!) para inverter a condição
    if (!condition1) // Nega de condition1, fazendo com que condition1 seja falsa
    {
        printf("O VALOR DA VARIÁVEL 'current_year' NÃO É MAIOR QUE 'last_year'\n");
        printf("Condição 'condition1' está correta? %s\n", condition1 ? "true" : "false");
    }
    else if (condition2) // Caso condition1 seja falsa, verifica condition2
    {
        printf("O VALOR DA VARIÁVEL 'last_year' É MAIOR QUE 'current_year'\n");
        printf("Condição 'condition2' está correta? %s\n", condition2 ? "true" : "false");
    }
    else
    {
        printf("Nenhuma das condições anteriores é verdadeira.\n");
    }

    /**
     * "ELSE-IF": Permite verificar múltiplas condições. Se uma das condições for verdadeira,
     * a instrução associada será executada. Caso nenhuma condição seja verdadeira, o bloco
     * "else" será executado.
     */

    printf("\n====================================================\n");
    printf("\n\t>>IF ANINHADOS<<\n");

    /**
     * IF ANINHADO: Permite fazer verificações dentro de outras verificações. No exemplo a
     * seguir, o segundo "if" verifica se o número é menor que 15, enquanto o terceiro "if"
     * verifica se o número é maior que 12, com um "else" associado ao último "if".
     */

    int number = 10; // Variável para comparação

    if (number == 10)
    {
        number += 20; // number = number(10) + 20 => 30
        if (number < 15)
        {
            printf("A VARIÁVEL 'number' é MENOR QUE 15\n");
        }
        if (number > 12)
        {
            printf("A VARIÁVEL 'number' É MAIOR QUE 12 também\n");
        }
        else
        {
            printf("A VARIÁVEL 'number' É MENOR QUE OS VALORES COMBINADOS\n");
        }
    }
    return 0;
}
