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
 * @brief Retorna uma string com data e hora local no formato desejado.
 * Usa strftime (mais seguro e flexível que asctime).]
 *
 * @param format Formato desejado (padrão: "%c" - data e hora local completa)
 * @return Ponteiro para string alocada dinamicamente (deve ser liberada pelo
 */
char *get_local_time_str(const char *format)
{
    time_t agora;
    if (time(&agora) == (time_t)-1)
    {
        return NULL;
    }

    struct tm *local = localtime(&agora);
    if (!local)
    {
        return NULL;
    }

    // Buffer grande o suficiente para a maioria dos formatos
    char *buffer = malloc(128);
    if (!buffer)
    {
        return NULL;
    }

    if (strftime(buffer, 128, format ? format : "%c", local) == 0)
    {
        free(buffer);
        return NULL;
    }

    return buffer;
}

/**
 * @brief Imprime os principais campos da struct tm de forma clara e segura
 *
 * @param tm Ponteiro para a struct tm a ser impressa
 */
void print_tm_info(const struct tm *tm)
{
    if (!tm)
    {
        printf("Estrutura tm inválida.\n");
        return;
    }

    static const char *dias_semana_pt[] = {
        "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira",
        "Quinta-feira", "Sexta-feira", "Sábado"};

    static const char *meses_pt[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    puts("\n=== Informações da data/hora atual (horário local) ===\n");

    printf("Data ............: %02d/%02d/%04d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    printf("Dia da semana ...: %s (%d)\n", dias_semana_pt[tm->tm_wday], tm->tm_wday);
    printf("Mês .............: %s (%d)\n", meses_pt[tm->tm_mon], tm->tm_mon + 1);
    printf("Dia do ano ......: %d (de 0 a 365/366)\n", tm->tm_yday);
    printf("Hora ............: %02d:%02d:%02d\n", tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf("Horário de verão.: %s (%d)\n", tm->tm_isdst > 0 ? "Ativo" : (tm->tm_isdst < 0 ? "Indeterminado" : "Inativo"), tm->tm_isdst);

    puts("==================================================\n");
}

int main(int argc, char **argv)
{
    // Forma 1 – usando nossa função com strftime
    char *tempo_str = get_local_time_str(NULL); // usa %c por padrão
    if (tempo_str)
    {
        printf("Data/hora local (asctime-like): %s\n", tempo_str);
        free(tempo_str);
    }
    else
    {
        printf("Falha ao obter data/hora local.\n");
    }

    // Forma 2 – formatos personalizados
    char *iso = get_local_time_str("%Y-%m-%d %H:%M:%S %Z");
    if (iso)
    {
        printf("Formato ISO + fuso: %s\n", iso);
        free(iso);
    }

    // Forma 3 – acesso direto e impressão detalhada
    time_t segundos;
    if (time(&segundos) == (time_t)-1)
    {
        printf("Erro ao obter tempo do sistema.\n");
        return 1;
    }

    struct tm *local = localtime(&segundos);
    if (!local)
    {
        printf("Erro na conversão para horário local.\n");
        return 1;
    }

    print_tm_info(local);

    // Exemplo extra: data por extenso (depende do locale do sistema)
    char buf[128];
    strftime(buf, sizeof(buf), "%A, %d de %B de %Y – %H:%M:%S", local);
    printf("Por extenso: %s\n", buf);
    return 0;
}
