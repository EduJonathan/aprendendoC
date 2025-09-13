#include <stdio.h>

/**
 * BREAK: O comando `break` é usado para forçar a saída de um loop,
 * independentemente de sua condição de continuidade. Ele é útil quando
 * queremos interromper um laço antes que ele complete todas as iterações.
 *
 * CONTINUE: O comando `continue` é usado para pular o restante do corpo
 * do loop atual e ir diretamente para a próxima iteração do loop,
 * sem executar o que vem após ele na iteração.
 */

int main(int argc, char **argv)
{
    printf("\n\t>>BREAK<<\n");

    int v = 0;    // Variável para armazenar o número inserido pelo usuário
    int soma = 0; // Variável para acumular a soma dos números

    // Laço do-while que continua até o usuário inserir 0
    do
    {
        printf("DIGITE UM NÚMERO! (0 PARA SAIR): ");
        scanf("%d", &v); // Recebe um número do usuário

        // Se o número for 0, interrompe o laço com o comando break
        if (v == 0)
        {
            break; // Sai do laço imediatamente
        }

        // Se o número for diferente de 0, soma ao total acumulado
        soma += v;
    } while (1); // O laço continua enquanto a condição for verdadeira (sempre)

    // Exibe a soma dos números inseridos pelo usuário
    printf("Soma total: %d\n", soma);

    printf("\n===============================================\n");
    printf("\n\t>>CONTINUE<<\n");

    int n = 0;   // Variável para armazenar a quantidade de números a serem inseridos
    int V = 0;   // Variável para armazenar cada número inserido
    int sum = 0; // Variável para acumular a soma dos números ímpares

    // Pergunta ao usuário quantos números ele deseja inserir
    printf("VOCÊ DESEJA INSERIR QUANTOS NÚMEROS? ");
    scanf("%d", &n); // Recebe a quantidade de números

    // Laço para percorrer os números inseridos pelo usuário
    for (int i = 0; i < n; i++)
    {
        printf("Digite o %dº número: ", i + 1); // Solicita o número ao usuário
        scanf("%d", &V);                        // Recebe o número inserido

        // Se o número for par, o laço continua sem somá-lo
        // Verifica se o número é par
        if (!(V % 2))
        {
            // Pula a iteração atual e vai para a próxima
            continue;
        }

        // Se o número for ímpar, soma ao total
        sum += V;
    }

    // Exibe a soma dos números ímpares inseridos
    printf("Soma dos números ímpares: %d\n", sum);
    return 0;
}
