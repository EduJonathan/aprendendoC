#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief Verifica se um ano é bissexto.
 *
 * Um ano é bissexto se:
 * - For divisível por 4, mas não por 100 **OU**
 * - For divisível por 400.
 *
 * @param ano Ano a ser verificado.
 * @return `true` se o ano for bissexto, `false` caso contrário.
 */
bool isAnoBissexto(int ano)
{
    if (ano <= 0)
        return false;
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

/**
 * @brief Retorna o número de dias em um mês, considerando anos bissextos.
 *
 * @param ano Ano para verificação de fevereiro (bissexto).
 * @param mes Mês (1-12).
 * @return Número de dias no mês (28-31).
 */
int diasEmMes(int ano, int mes)
{
    if (mes < 1 || mes > 12)
        return -1; // erro

    static const int dias_por_mes[13] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dias = dias_por_mes[mes];
    if (mes == 2 && isAnoBissexto(ano))
        dias = 29;

    return dias;
}

int main(int argc, char **argv)
{
    int ano = 0, mes = 0;

    printf("Digite o ano (ex: 2024, 2025): ");
    if (scanf("%d", &ano) != 1 || ano < 1 || ano > 9999)
    {
        printf("Ano inválido.\n");
        return 1;
    }

    printf("Digite o mes (1-12): ");
    if (scanf("%d", &mes) != 1 || mes < 1 || mes > 12)
    {
        printf("Mês inválido (deve ser entre 1 e 12).\n");
        return 1;
    }

    int dias = diasEmMes(ano, mes);
    if (dias < 0)
    {
        printf("Erro interno ao calcular dias do mês.\n");
        return 1;
    }

    // Preparar struct tm para o dia 1º do mês
    struct tm tm_in = {0};
    tm_in.tm_year = ano - 1900;
    tm_in.tm_mon = mes - 1;
    tm_in.tm_mday = 1;
    tm_in.tm_hour = 12;  // hora do meio-dia evita problemas de horário de verão
    tm_in.tm_isdst = -1; // deixa mktime decidir

    if (mktime(&tm_in) == (time_t)-1)
    {
        printf("Não foi possível normalizar a data.\n");
        return 1;
    }

    int primeiro_dia_semana = tm_in.tm_wday; // 0=domingo, 1=segunda, ..., 6=sábado

    printf("\n");
    printf("         %d - %02d         \n", ano, mes);
    printf("===========================\n");
    printf("Dom Seg Ter Qua Qui Sex Sab\n");
    printf("---------------------------\n");

    // Espaços iniciais (cada coluna tem 4 caracteres de largura)
    for (int i = 0; i < primeiro_dia_semana; i++)
    {
        printf("    "); // 4 espaços
    }

    // Imprime os dias
    for (int dia = 1; dia <= dias; dia++)
    {
        printf("%3d ", dia); // 3 caracteres por dia (espaço + número alinhado à direita)

        // Quebra de linha no sábado ou no último dia
        if ((dia + primeiro_dia_semana) % 7 == 0 || dia == dias)
        {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}
