#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * localtime(): Função da biblioteca de manipulação de tempo (time.h) que converte um
 * tempo representado em segundos desde a "época" (1º de janeiro de 1970 também 00:00:00 UTC)
 * para uma representação de tempo local.
 *
 * SINTAXE: struct tm *localtime(const time_t *time);
 *
 * @param time: Ponteiro para um objeto do tipo time_t que representa o tempo em segundos.
 * @return Retorna um ponteiro para uma estrutura struct tm que contém informações sobre a
 * data e hora.
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
    time_t rawtime;
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

    // Retorna o ponteiro para a string formatada
    return formatted_time;
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
    struct tm *data_hora_atual;

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
