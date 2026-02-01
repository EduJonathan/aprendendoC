#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define SEGUNDOS_POR_DIA 86400

/**
 * difftime(): Calcula a diferença em segundos entre dois valores do tipo `time_t`, representando
 * dois instantes de tempo. Retorna o resultado como um valor `double`, permitindo precisão
 * até frações de segundo.
 *
 * SINTAXE: double difftime(time_t time1, time_t time2);
 *
 * @param time_beg: Primeiro instante de tempo (tempo inicial) em segundos desde a "época".
 * @param time_end: Segundo instante de tempo (tempo final) em segundos desde a "época".
 *
 * @return: Retorna a diferença em segundos entre `time_end` e `time_beg`, com precisão
 * de frações de segundo. A fórmula é: `difftime = time_end - time_beg`.
 *
 * @note Importante:
 * - O valor retornado é a diferença entre os dois instantes de tempo, ou seja,
 *   `time_end - time_beg`. Se `time_end` for maior que `time_beg`, o valor retornado
 *   será positivo; caso contrário, será negativo.
 *
 * - A função é útil para medir intervalos de tempo entre dois eventos em segundos.
 *
 * - A precisão do cálculo é garantida pela representação do tipo `double`.
 *
 * - Para comparar intervalos de tempo ou determinar a duração de um evento, `difftime()`
 *   é uma função bastante comum.
 */

/**
 * @brief Calcula a diferença entre a data de referência (25 de setembro) e a data atual.
 *
 * Esta função calcula a quantidade de meses e dias que passaram desde o dia 25 de setembro
 * até a data atual. A data de referência é ajustada para o ano atual, e a diferença é calculada
 * utilizando a função `difftime` para obter a diferença em segundos, convertendo-a em dias.
 *
 * Aproxima o cálculo dos meses para 30 dias por mês e exibe a quantidade de meses e dias passados.
 *
 * @param data_referencia Ponteiro para uma estrutura `tm` contendo a data de referência (25 de setembro do ano atual).
 */
void calcular_diferenca_25_setembro(void)
{
    time_t agora = time(NULL);
    if (agora == (time_t)-1)
    {
        printf("Erro ao obter hora atual.\n");
        return;
    }

    struct tm hoje = *localtime(&agora);
    hoje.tm_hour = hoje.tm_min = hoje.tm_sec = 0;
    hoje.tm_isdst = -1;
    time_t hoje_meia_noite = mktime(&hoje);

    // Data de referência: 25 de setembro do ano atual
    struct tm ref = {0};
    ref.tm_isdst = -1;
    ref.tm_year = hoje.tm_year;
    ref.tm_mon = 8; // setembro = 8
    ref.tm_mday = 25;
    ref.tm_hour = 0;
    ref.tm_min = 0;
    ref.tm_sec = 0;

    time_t tempo_ref = mktime(&ref);
    if (tempo_ref == (time_t)-1)
    {
        printf("Erro ao normalizar 25 de setembro.\n");
        return;
    }

    // Se 25/09 já passou → não ajustamos para o próximo ano aqui (só informamos)
    double segundos = difftime(agora, tempo_ref);
    int dias_totais = (int)(segundos / SEGUNDOS_POR_DIA);

    if (dias_totais >= 0)
    {
        // Já passou
        int meses = dias_totais / 30;
        int dias = dias_totais % 30;
        printf("O dia 25 de setembro de %d foi há %d meses e %d dias.\n", ref.tm_year + 1900, meses, dias);
    }
    else
    {
        // Ainda vai chegar este ano
        int dias_faltam = -dias_totais;
        int meses = dias_faltam / 30;
        int dias = dias_faltam % 30;
        printf("Faltam %d meses e %d dias para 25 de setembro de %d.\n", meses, dias, ref.tm_year + 1900);
    }

    // Mostra data por extenso (opcional, mas ajuda a entender)
    char buf[64];
    strftime(buf, sizeof(buf), "%A, %d de %B de %Y", &ref);
    printf("Referência: %s\n", buf);
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * Esta função calcula a quantidade de dias que passaram entre duas datas.
 *
 * @param dataAtual Estrutura tm contendo a data atual.
 * @param dataDestino Estrutura tm contendo a data de destino.
 * @return Retorna a diferença em dias entre as duas datas.
 */
int calcular_dias_entre(struct tm *atual, struct tm *destino)
{
    atual->tm_hour = atual->tm_min = atual->tm_sec = 0;
    destino->tm_hour = destino->tm_min = destino->tm_sec = 0;
    atual->tm_isdst = destino->tm_isdst = -1;

    time_t t_atual = mktime(atual);
    time_t t_destino = mktime(destino);

    if (t_atual == (time_t)-1 || t_destino == (time_t)-1)
    {
        return -999999; // código de erro
    }

    double diff_seg = difftime(t_destino, t_atual);
    return (int)(diff_seg / SEGUNDOS_POR_DIA);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    time_t now = time(NULL);
    if (now == (time_t)-1)
    {
        printf("Erro ao obter hora atual.\n");
        return 1;
    }

    struct tm hoje = *localtime(&now);
    char buf[64] = {0}; // ← corrigido aqui

    // 1. Tempo desde o início do mês
    struct tm inicio_mes = hoje;
    inicio_mes.tm_mday = 1;
    inicio_mes.tm_hour = inicio_mes.tm_min = inicio_mes.tm_sec = 0;
    inicio_mes.tm_isdst = -1;
    time_t t_inicio = mktime(&inicio_mes);
    double segs_mes = difftime(now, t_inicio);

    strftime(buf, sizeof(buf), "%B", &hoje);
    printf("Segundos desde 1º de %s: %.0f s (~ %d dias e %02d:%02d:%02d)\n",
           buf, segs_mes,
           (int)(segs_mes / SEGUNDOS_POR_DIA),
           (int)(segs_mes / 3600) % 24,
           (int)(segs_mes / 60) % 60,
           (int)segs_mes % 60);

    printf("\n===============================================\n");

    calcular_diferenca_25_setembro();

    printf("\n===============================================\n");

    char entrada[32];
    int d = 0, m = 0, a = 0;
    printf("Digite a data de destino (DD MM AAAA): ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL)
    {
        printf("Erro na leitura.\n");
        return 1;
    }

    if (sscanf(entrada, "%d %d %d", &d, &m, &a) != 3 ||
        d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 9999)
    {
        printf("Formato ou valores inválidos.\n");
        return 1;
    }

    struct tm destino = {0};
    destino.tm_mday = d;
    destino.tm_mon = m - 1;
    destino.tm_year = a - 1900;
    destino.tm_isdst = -1;

    int dias = calcular_dias_entre(&hoje, &destino);

    if (dias == -999999)
    {
        printf("Erro ao processar uma das datas.\n");
    }
    else if (dias > 0)
    {
        printf("Faltam %d dias até %02d/%02d/%04d.\n", dias, d, m, a);
    }
    else if (dias < 0)
    {
        printf("A data %02d/%02d/%04d já passou há %d dias.\n", d, m, a, -dias);
    }
    else
    {
        printf("Hoje é exatamente a data informada!\n");
    }

    return 0;
}
