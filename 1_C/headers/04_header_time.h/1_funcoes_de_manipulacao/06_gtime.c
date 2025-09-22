#include <stdio.h>
#include <time.h>

/**
 * gmtime(): Função da biblioteca de manipulação de tempo (time.h) que converte um valor
 * de tempo, expresso em segundos desde a "época" (1º de janeiro de 1970, 00:00:00 UTC),
 * para uma estrutura `tm` que representa a data e hora no formato UTC (Tempo Universal
 * Coordenado).
 *
 * SINTAXE: struct tm *gmtime(const time_t *timep);
 *
 * @param timep: Ponteiro para um valor do tipo `time_t`, que representa o número de segundos
 *               desde a "época" (1º de janeiro de 1970). Esse valor é geralmente obtido com
 *               funções como `time()` ou calculado de outras formas.
 *
 * @return Retorna um ponteiro para uma estrutura `tm` preenchida com a data e hora correspondente
 * ao tempo fornecido, mas no formato UTC. Essa estrutura contém os seguintes campos:
 * - `tm_sec`: Segundo (0 a 59)
 * - `tm_min`: Minuto (0 a 59)
 * - `tm_hour`: Hora (0 a 23)
 * - `tm_mday`: Dia do mês (1 a 31)
 * - `tm_mon`: Mês (0 a 11, sendo 0 janeiro e 11 dezembro)
 * - `tm_year`: Ano desde 1900
 * - `tm_wday`: Dia da semana (0 a 6, onde 0 é domingo)
 * - `tm_yday`: Dia do ano (0 a 365)
 * - `tm_isdst`: Indicador de horário de verão (0 ou 1)
 *
 * @note Importante:
 * - A estrutura retornada pela função contém a data e hora no formato UTC, ou seja, sem
 *   ajustes de fuso horário local ou hora de verão.
 * 
 * - Para obter a data e hora local, deve-se usar funções como `localtime()` ou `asctime()`.
 * 
 * - A estrutura `tm` retornada é comumente usada por outras funções de manipulação de data
 *   e hora, como `mktime()` e `strftime()`.
 */

// Função para obter a data e hora UTC formatada
char *get_utc_time()
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
