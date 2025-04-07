#include <stdio.h>

/**
 * SSCANF: É uma função da biblioteca padrão de C que permite ler e interpretar dados
 * de uma string, funcionando como o , mas operando diretamente sobre uma cadeia de caracteres
 * em vez da entrada padrão. Essa abordagem é útil para processar entrada formatada, como logs,
 * configurações e mensagens
 */

int main(int argc, char **argv)
{
    char entrada[] = "42 3.14 exemplo";
    int numero;
    float decimal;
    char palavra[20];

    // Interpretando valores da string
    sscanf(entrada, "%d %f %s", &numero, &decimal, palavra);

    printf("Número inteiro: %d\n", numero);
    printf("Número decimal: %.2f\n", decimal);
    printf("Palavra: %s\n", palavra);

    return 0;
}
