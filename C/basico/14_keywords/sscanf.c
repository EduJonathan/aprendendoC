#include <stdio.h>
#include <stdbool.h>

/**
 * SSCANF: É uma função da biblioteca padrão de C que permite ler e interpretar dados
 * de uma string, funcionando como o scanf, mas operando diretamente sobre uma cadeia de caracteres
 * em vez da entrada padrão. Essa abordagem é útil para processar entrada formatada, como logs,
 * configurações e mensagens
 */

bool validar_data(int dia, int mes, int ano)
{
    // Verifica se o mês é válido (1-12)
    if (mes < 1 || mes > 12)
    {
        return false;
    }

    // Verifica os dias de cada mês
    int dias_no_mes;
    switch (mes)
    {
    case 2: // Fevereiro
        // Verificação simplificada para ano bissexto
        dias_no_mes = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11: // Abril, Junho, Setembro, Novembro
        dias_no_mes = 30;
        break;
    default: // Outros meses
        dias_no_mes = 31;
        break;
    }

    return (dia >= 1 && dia <= dias_no_mes);
}

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

    printf("\n-------------------------------------\n");

    char input[50];
    int dia, mes, ano;

    printf("Digite uma data no formato dd/mm/aaaa: ");
    fgets(input, sizeof(input), stdin);

    // Usando sscanf para extrair os valores
    int itens_lidos = sscanf(input, "%d/%d/%d", &dia, &mes, &ano);

    if (itens_lidos != 3)
    {
        printf("Formato inválido! Use dd/mm/aaaa.\n");
        return 1;
    }

    if (validar_data(dia, mes, ano))
    {
        printf("Data válida: %02d/%02d/%04d\n", dia, mes, ano);
    }
    else
    {
        printf("Data inválida!\n");
    }

    return 0;
}
