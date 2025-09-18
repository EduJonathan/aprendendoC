#include <stdio.h>

/**
 * FUNCTIONS: São blocos de código independentes que executam tarefas específicas.
 * Elas podem retornar um valor ou não, dependendo de sua definição. Quando uma função
 * não retorna valor, ela é do tipo void, que indica que o propósito da função é apenas
 * realizar um conjunto de instruções, sem fornecer um resultado.
 *
 * Além de permitir a reutilização de código, as funções ajudam na organização e
 * estruturação do programa, dividindo-o em partes menores e mais compreensíveis.
 * Isso facilita tanto a leitura quanto a manutenção do código, tornando-o mais modular e legível.
 */

/// @brief Procedimento que realiza apenas uma instrução de printf para exibir uma mensagem
void printTitle(void) { printf("\n==>FUNÇÕES<==\n"); }

/// @brief Procedimento que imprime 23 traços ("-")
void printlinhas(void)
{
    for (int i = 0; i < 23; i++)
    {
        printf("-");
    }
}

/// @brief Função que retorna comparando 2 valores se é maior ou menor
/// @return retorno de uma operação ternária entre 2 valores
int maiorOuMenor(void)
{
    // Valores a ser comparado na operação do retorno
    int n1 = 10;
    int n2 = 20;

    // Retorno do maior número entre `n1` e `n2` utilizando o operador térnario
    return (n1 > n2) ? printf("\nO valor é maior\n") : printf("\nO valor é menor\n");
}

/// @brief Função principal (main) para execução do programa e chamada de outras funções
int main(int argc, char **argv)
{
    printlinhas();                // Chama o printlinhas() para exibir os 23 trações
    printTitle();                 // Chama o print() sua exibição deverá ser o printf (sua instrução)
    printlinhas();                // Chama o printlinhas() para exibir os 23 trações
    printf("\nFuncao simples\n"); // Imprima "Funcao simples"
    printlinhas();                // Chama o printlinhas() para exibir os 23 trações
    maiorOuMenor();               // Chama função que retorna indicando quem é maior ou menor número
    return 0;
}
