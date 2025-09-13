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
    return ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
}

/**
 * @brief Retorna o número de dias em um mês, considerando anos bissextos.
 *
 * @param ano Ano para verificação de fevereiro (bissexto).
 * @param mes Mês (1-12).
 * @return Número de dias no mês (28-31).
 */
int diasEmMeses(int ano, int mes)
{
    if (mes == 2)
    {
        return isAnoBissexto(ano) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

int main(int argc, char **argv)
{
    int ano = 0, mes = 0;

    printf("Digite o ano: ");
    scanf("%d", &ano);

    printf("Digite o mes entre (1-12): ");
    scanf("%d", &mes);

    int dias = diasEmMeses(ano, mes);

    printf("\n**********************************\n");
    printf("\t %d - %02d\n", ano, mes); // %02d garante 2 dígitos (ex: 01, 12)
    printf("**********************************\n");

    printf("Dom Seg Ter Qua Qui Sex Sab\n"); // Cabeçalho dos dias da semana

    struct tm tm_in = {0};
    tm_in.tm_year = ano - 1900; // Ano em formato struct tm (anos desde 1900)
    tm_in.tm_mon = mes - 1;     // Mês em formato struct tm (0-11)
    tm_in.tm_mday = 1;          // Primeiro dia do mês
    mktime(&tm_in);             // Normaliza a struct tm e calcula tm_wday

    int inicioDoDia = tm_in.tm_wday; // Dia da semana do 1º dia (0=Dom, 6=Sab)

    // Imprime espaços para alinhar o primeiro dia
    for (int i = 0; i < inicioDoDia; i++)
    {
        printf("    "); // 4 espaços por dia (para alinhar com "DD ")
    }

    // Imprime os dias do mês
    for (int dia = 1; dia <= dias; dia++)
    {
        printf("%2d  ", dia); // %2d garante alinhamento para 1 ou 2 dígitos
        if ((dia + inicioDoDia) % 7 == 0 || dia == dias)
        {
            printf("\n"); // Quebra de linha a cada semana ou no último dia
        }
    }

    return 0;
}
