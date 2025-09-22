#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * localtime(): Converte um valor de tempo `time_t` (segundos desde a "época" - 1º de janeiro de 1970)
 * para uma representação de tempo local, ajustada para o fuso horário e o horário de verão, se aplicável.
 *
 * SINTAXE: struct tm *localtime(const time_t *time);
 *
 * @param time Ponteiro para um valor `time_t` representando o tempo em segundos desde a "época".
 *
 * @return Retorna um ponteiro para uma estrutura `struct tm` com a data e hora local, incluindo:
 * - `tm_sec` (segundos), `tm_min` (minutos), `tm_hour` (hora), `tm_mday` (dia do mês),
 * - `tm_mon` (mês), `tm_year` (ano desde 1900), `tm_wday` (dia da semana), `tm_yday` (dia do ano),
 * - `tm_isdst` (indicador de horário de verão).
 *
 * A função ajusta automaticamente os valores de acordo com a localização geográfica do sistema.
 *
 * @note Importante:
 * - A função `localtime()` converte o tempo em UTC para o tempo local, ajustando para o
 *   fuso horário e horário de verão.
 * 
 * - A estrutura retornada contém valores que representam o tempo local de acordo com a
 *   configuração do sistema operacional.
 * 
 * - A estrutura `struct tm` é útil para manipulação de datas e horas em formato legível.
 * 
 * - A função `localtime()` não deve ser usada de maneira simultânea em múltiplas threads
 *   sem sincronização, pois a estrutura `struct tm` retornada é compartilhada entre as chamadas.
 */

/**
 * @brief Função que retorna a data e hora local formatada.
 *
 * Esta função obtém o tempo atual do sistema, converte para a hora local
 * e retorna a data e hora no formato de string, utilizando a função asctime().
 *
 * @return Ponteiro para uma string formatada contendo a data e hora local,
 * ou NULL em caso de falha na alocação de memória.
 */
char *get_local_time(void)
{
    time_t rawtime = 0; // Variável do tipo time_t para armazenar o tempo em segundos
    struct tm *info = NULL;

    // Obtém o tempo atual
    time(&rawtime);

    // Converte para hora local
    info = localtime(&rawtime);

    // Aloca memória para armazenar a string formatada
    char *formatted_time = (char *)malloc(26 * sizeof(char));
    // "Thu Oct  3 17:15:09 2024" tem 26 caracteres

    if (formatted_time != NULL)
    {
        // Converte a estrutura tm para uma string formatada
        // Asctime retorna uma string com o formato: "Thu Oct  3 17:15:09 2024\n"
        snprintf(formatted_time, 26, "%s", asctime(info));
        // A função asctime já inclui o '\n' no final, além de converter essa estrutura
        // tm em uma string legível.
    }
    return formatted_time; // Retorna o ponteiro para a string formatada
}

/**
 * @brief Função que imprime as informações detalhadas de data e hora.
 *
 * Esta função recebe uma estrutura `tm` que contém informações sobre a data e hora
 * e imprime esses valores de forma legível. Também imprime a data formatada (dia/mês/ano).
 *
 * @param data_hora_atual Ponteiro para uma estrutura `tm` contendo a data e hora local.
 */
void print_time(struct tm *data_hora_atual)
{
    // Definindo os labels para cada valor na estrutura tm
    const char *labels[] = {
        "DIA",           // tm_mday
        "MES",           // tm_mon
        "MES corrigido", // tm_mon + 1
        "ANO",           // tm_year
        "ANO corrigido", // tm_year + 1900
        "Dia do ano",    // tm_yday
        "Dia da semana", // tm_wday
        "HORA",          // tm_hour
        "MINUTO",        // tm_min
        "SEGUNDO",       // tm_sec
    };

    // Usando um loop para imprimir os valores
    printf("\n===============================================\n\n");

    // Imprime os dados em sequência com 10 campos a serem impressos
    for (int i = 0; i < 10; i++)
    {
        if (i == 2)
        {
            // Imprime a data formatada
            printf("%s ==============> %d/%d/%d\n", labels[i], data_hora_atual->tm_mday,
                   data_hora_atual->tm_mon + 1,
                   data_hora_atual->tm_year + 1900);
        }
        else
        {
            // Imprime os outros valores
            printf("%s ==============> %d\n", labels[i], *((int *)data_hora_atual + i));
        }
    }
}

int main(int argc, char **argv)
{
    // Chama a função e obtém a data e hora local formatada
    char *local_time = get_local_time();

    if (local_time != NULL)
    {
        // Exibe a data e hora local
        printf("Data e hora local: %s", local_time);

        // Libera a memória alocada
        free(local_time);
    }
    else
    {
        printf("Erro ao obter a data e hora local.\n");
    }

    // Ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual = NULL;

    // Varíavel do tipo time_t para armazenar o tempo em segundo
    time_t seconds;

    // Obter o tempo de segundos
    time(&seconds);

    // Conversão de data e hora para o tempo local utilizamos a função localtime
    data_hora_atual = localtime(&seconds);

    // Imprimindo data e hora
    print_time(data_hora_atual);
    return 0;
}
