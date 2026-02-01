#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * TIMESPEC: A estrutura `timespec` é usada em C para representar intervalos de tempo de
 * alta precisão, permitindo a manipulação de tempos com uma resolução muito maior que
 * a de `time_t`. Ela é particularmente útil em situações que exigem medições de tempo
 * de alta precisão, como temporização em sistemas de tempo real ou medições de desempenho
 * com frações de segundo (como nanossegundos).
 *
 * A estrutura é comumente utilizada em funções que exigem controle detalhado do tempo,
 * como `nanosleep()`, `clock_gettime()`, entre outras.
 *
 * DIFERENÇA PARA:
 * `time_t`: A principal diferença entre `time_t` e `timespec` é que `time_t` representa o
 * tempo em segundos desde a "época" (1º de janeiro de 1970, 00:00:00 UTC).
 *
 * Enquanto `timespec` pode representar o tempo com uma resolução muito maior,
 * incluindo frações de segundo, como nanossegundos, proporcionando uma maior precisão.
 */

/**
 * @brief Calcula a idade a partir da data de nascimento fornecida.
 *
 * calcular_idade: Função que calcula a idade a partir da data de nascimento fornecida.
 *
 * @param data_nascimento Data de nascimento no formato "DD/MM/AAAA".
 */
void calcular_idade(const char *data_nascimento)
{
    struct tm nascimento = {0};
    int d = 0, m = 0, a = 0;

    // Lê e valida formato básico
    if (sscanf(data_nascimento, "%d/%d/%d", &d, &m, &a) != 3 || d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 9999)
    {
        printf("Formato ou valores inválidos. Use DD/MM/AAAA (ex: 25/09/2000)\n");
        return;
    }

    nascimento.tm_mday = d;
    nascimento.tm_mon = m - 1; // 0 = janeiro
    nascimento.tm_year = a - 1900;
    nascimento.tm_hour = 0;
    nascimento.tm_min = 0;
    nascimento.tm_sec = 0;
    nascimento.tm_isdst = -1; // deixa mktime decidir horário de verão

    time_t t_nasc = mktime(&nascimento);
    if (t_nasc == (time_t)-1)
    {
        printf("Data de nascimento inválida ou fora do intervalo suportado.\n");
        return;
    }

    // Data atual (meia-noite)
    time_t agora = time(NULL);
    if (agora == (time_t)-1)
    {
        printf("Erro ao obter data atual.\n");
        return;
    }

    struct tm hoje = *localtime(&agora);
    hoje.tm_hour = hoje.tm_min = hoje.tm_sec = 0;
    hoje.tm_isdst = -1;
    time_t t_hoje = mktime(&hoje);

    if (t_hoje == (time_t)-1)
    {
        printf("Erro ao normalizar data atual.\n");
        return;
    }

    // Cálculo preciso da idade
    int anos = hoje.tm_year - nascimento.tm_year;
    int mes_atual = hoje.tm_mon;
    int mes_nasc = nascimento.tm_mon;

    // Ainda não fez aniversário este ano?
    if (mes_atual < mes_nasc ||
        (mes_atual == mes_nasc && hoje.tm_mday < nascimento.tm_mday))
    {
        anos--;
    }

    // Cálculo de dias totais (opcional, mas interessante)
    double segs = difftime(t_hoje, t_nasc);
    long dias_totais = (long)(segs / 86400.0);

    // Mostra resultado
    printf("\nData de nascimento: %02d/%02d/%04d\n", d, m, a);
    printf("Idade atual .........: %d anos\n", anos);
    printf("Dias vividos .........: %ld dias\n", dias_totais);

    // Mostra data por extenso (opcional)
    char buf[64];
    strftime(buf, sizeof(buf), "%A, %d de %B de %Y", &nascimento);
    printf("Nascido em ..........: %s\n", buf);
}

int main(int argc, char **argv)
{
    char entrada[32] = {0};

    printf("Digite sua data de nascimento (DD/MM/AAAA): ");
    if (fgets(entrada, sizeof(entrada), stdin) == NULL)
    {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    // Remove \n e espaços extras
    entrada[strcspn(entrada, "\n")] = '\0';
    char *p = entrada;

    while (*p == ' ')
        p++;

    if (p != entrada)
        memmove(entrada, p, strlen(p) + 1);

    if (strlen(entrada) < 8)
    {
        printf("Data muito curta.\n");
        return 1;
    }

    calcular_idade(entrada);

    return 0;
}