#include <stdio.h>
#include <stdbool.h>

/**
 * WHILE_TRUE: Como o nome do loop indica, a condição vai se repetir enquanto a
 * condição for verdadeira, devemos ser cuidadoso como se trata de um programa que
 * não vai parar de executar, até que haja uma condição ou escolha, ou uma forçação
 * para quebrar o loop como break.
 *
 * SINTAXE: while(1){} ou while(true){}, true com a biblioteca stdbool.h incluída
 */

int main(int argc, char **argv)
{
    printf("\n\t>>EXEMPLO 01: WHILE-TRUE<<\n");

    int escolha = 0;

    while (1)
    {
        printf("\n\tDeseja fazer login na sua conta\n");
        printf(" Digite: \n[1] -> Para sim\n[0]-> Para não: ");
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            printf("\nDigite seu email\n");
            printf("Digite sua senha\n");
        }
        else
        {
            printf("\nVocê saiu!\n");
            break; // break: garante a quebra do programa após o usuario digitar 0
        }
    }

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 02: WHILE-TRUE ANINHADO<<\n");

    // Inicializa a variável 'loop_externo' com 1. Esta variável controlará o número da
    // linha na tabela de multiplicação.
    int loop_externo = 1;

    // Loop externo infinito que será controlado pelos comandos 'break' internos.
    do
    {
        // Inicializa a variável 'loop_interno' com 1 dentro do loop externo.
        // Esta variável controlará o número da coluna na tabela de multiplicação.
        int loop_interno = 1;

        // Loop interno infinito que será controlado pelo comando 'break' quando
        // 'loop_interno' for maior que 5.
        do
        {
            // Imprime o produto de 'loop_externo' e loop_interno'
            printf("%d\t", loop_externo * loop_interno);

            // Incrementa 'loop_interno' para o próximo valor na linha atual.
            loop_interno++;

            // Verifica se 'loop_interno' é maior que 5.
            if (loop_interno > 5)
            {
                // Sai do loop interno quando loop_interno > 5
                break;
            }
        } while (1);

        printf("\n");

        // Incrementa 'loop_externo' para o próximo valor na tabela, preparando para a próxima linha.
        loop_externo++;

        // Verifica se 'loop_externo' é maior que 5.
        if (loop_externo > 5)
        {
            // Sai do loop externo quando loop_externo > 5
            break;
        }
    } while (true);
    return 0;
}
