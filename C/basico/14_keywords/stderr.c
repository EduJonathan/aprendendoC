#include <stdio.h>

/**
 * STDERR: (standard error) é um fluxo usado para exibir mensagens de erro ou alertas em C
 * e outras linguagens. Diferente do stdout, o stderr normalmente não é afetado por
 * redirecionamentos padrão, garantindo que mensagens críticas apareçam no console.
 * Escreve a mensagem de erro no stderr.
 */

int main(int argc, char **argv)
{
    int numero;

    printf("Digite um número positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
    {
        fprintf(stderr, "Erro: número negativo digitado!\n");
    }
    else
    {
        printf("Número válido: %d\n", numero);
    }
    return 0;
}
