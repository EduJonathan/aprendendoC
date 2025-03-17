#include <stdio.h>

/**
 * FUNCTIONS: Funções são blocos de código que realizam tarefas através de um bloco
 * separado a qual pode retornar ou não o valor de um tipo de dado, aqueles que não
 * retornam valor são conhecidos como void ou tipo genérico, ele realiza procedimentos
 * através de instruções não retornando nenhum valor. Nos ajudando a organizar, estruturar
 * o código e ter facilidade na leitura e compreensão do mesmo.
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
    // Valor a ser comparado na operação do retorno
    int n1 = 10;

    // Valor a ser comparado na operação do retorno
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
