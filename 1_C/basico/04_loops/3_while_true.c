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
        printf(" Digite: \n[1] -> Para sim\n[0] -> Para não: ");
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
    printf("\n\t>>EXEMPLO 02: WHILE-TRUE ANINHADO - SOMA DOS NÚMEROS<<\n");

    // Inicializa a variável 'loop_externo' com 1. Esta variável controlará o número da linha.
    int loop_externo = 1;

    // Loop externo infinito que será controlado pelos comandos 'break' internos.
    do
    {
        // Inicializa a variável 'loop_interno' com 1 dentro do loop externo.
        // Esta variável controlará a soma até o número 'loop_externo'.
        int loop_interno = 1;
        int soma = 0; // Variável para armazenar a soma dos números

        // Loop interno infinito que será controlado pelo comando 'break' quando
        // 'loop_interno' for maior que 'loop_externo'.
        do
        {
            // Adiciona 'loop_interno' à soma
            soma += loop_interno;

            // Incrementa 'loop_interno' para o próximo número na soma.
            loop_interno++;

            // Verifica se 'loop_interno' é maior que 'loop_externo'.
            if (loop_interno > loop_externo)
            {
                // Sai do loop interno quando 'loop_interno' for maior que 'loop_externo'
                break;
            }
        } while (1);

        // Imprime o resultado da soma para a linha atual
        printf("Soma dos números de 1 até %d: %d\n", loop_externo, soma);

        // Incrementa 'loop_externo' para o próximo valor.
        loop_externo++;

        // Verifica se 'loop_externo' é maior que 5.
        if (loop_externo > 5)
        {
            // Sai do loop externo quando 'loop_externo' for maior que 5
            break;
        }
    } while (1);
    return 0;
}
