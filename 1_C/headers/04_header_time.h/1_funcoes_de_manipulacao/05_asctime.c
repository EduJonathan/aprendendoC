#include <stdio.h>
#include <time.h>

/**
 * asctime(): Função da biblioteca de manipulação de tempo (time.h) que converte
 * uma estrutura de tempo (struct tm) em uma string formatada representando a data
 * e hora local de forma legível.
 *
 * A função retorna uma string no formato "Dia Mês DD HH:MM:SS AAAA\n", onde:
 * - Dia: Nome do dia da semana (ex: "Sun", "Mon", etc.)
 * - Mês: Nome do mês (ex: "Jan", "Feb", etc.)
 * - DD: Dia do mês (de 01 a 31)
 * - HH:MM:SS: Hora, minuto e segundo (24 horas)
 * - AAAA: Ano (por exemplo, 2021)
 *
 * SINTAXE: char *asctime(const struct tm *timeptr);
 *
 * @param timeptr: Ponteiro para uma estrutura `struct tm` que contém informações sobre
 *                 a data e hora (ano, mês, dia, hora, minuto, segundo, etc.), geralmente
 *                 preenchida por funções como `localtime()` ou `gmtime()`.
 *
 * @return Retorna um ponteiro para uma string no formato ASCII representando a data e hora
 *         em formato legível. A string retornada é estática e não deve ser modificada.
 *
 * @note Importante:
 * - O valor da string retornada considera o fuso horário local, ou seja, ela é ajustada
 *   conforme o fuso horário e a hora de verão (se aplicável).
 * 
 * - A função é útil para imprimir a data e hora em um formato legível para o usuário.
 */

// Função para obter a data e hora UTC formatada
char *get_utc_time(void)
{
    // Obtém o tempo atual em segundos desde a época (1º de janeiro de 1970)
    time_t rawtime;
    time(&rawtime);

    // Converte o tempo para a estrutura tm no formato UTC
    struct tm *timeinfo = gmtime(&rawtime);

    // Retorna a data e hora UTC em formato legível
    return asctime(timeinfo);
}

int main(int argc, char **argv)
{
    // Chama a função para obter a data e hora no formato UTC
    printf("Data e hora UTC: %s", get_utc_time());

    return 0;
}
