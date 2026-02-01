#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_NOME 40
#define MAX_FEST 32

/**
 * mktime(): Converte uma estrutura `tm` (contendo data e hora) para um valor do tipo
 * `time_t`, que representa o número de segundos desde a "época" (1º de janeiro de 1970,
 * 00:00:00 UTC). Útil para cálculos de data e hora ou manipulação flexível de tempo.
 *
 * SINTAXE: time_t mktime(struct tm *timeptr);
 *
 * @param timeptr: Ponteiro para a estrutura `tm` com a data e hora a serem convertidas.
 * @return: Retorna o número de segundos desde a "época" ou `-1` se a data for inválida.
 *
 * @note Importante:
 * - A função `mktime()` ajusta automaticamente os campos inválidos da estrutura `tm`.
 *   Por exemplo, se o campo `tm_mon` (mês) for maior que 11 (mês inválido), a função
 *   ajustará o valor do mês e o ano de acordo com a necessidade.
 *
 * - A função `mktime()` pode alterar os valores dos campos da estrutura `tm` após a
 *   conversão, especialmente o campo `tm_wday` (dia da semana) e `tm_yday` (dia do ano),
 *   que são recalculados com base na data fornecida.
 *
 * - O valor retornado é o número de segundos desde a "época", podendo ser utilizado
 *   para cálculos de tempo, comparações e manipulação de data e hora.
 */

static int calcula_pascoa(int ano, int *mes_out, int *dia_out);
static int calcula_carnaval(int ano, int *mes_out, int *dia_out);

// Definindo um enum para as festividades
typedef struct
{
    const char *nome; // usado na comparação (minúsculo)
    int mes;          // 0..11    (-1 = móvel)
    int dia;          // 1..31    (-1 = móvel)

    // Para feriados móveis: função que calcula a data no ano desejado
    int (*calcula_movel)(int ano, int *mes_out, int *dia_out);
} Festividade;

static const Festividade tabela[] = {
    {"halloween",  9,  31,  NULL},
    {"natal",      11, 25,  NULL},
    {"ano novo",   0,  1,   NULL},
    {"tiradentes", 3,  21,  NULL},
    {"carnaval",   -1, -1,  calcula_carnaval},
    // { "corpus christi", -1, -1, calcula_corpus_christi },
    // { "dia das maes",   -1, -1, calcula_dia_das_maes },
};

static const int NUM_FEST = sizeof(tabela) / sizeof(tabela[0]);

/**
 * @brief Encontra uma festividade na tabela pelo nome.
 *
 * @param nome Nome da festividade (case insensitive).
 * @return Ponteiro para a estrutura Festividade correspondente ou NULL se não encontrada.
 */
const Festividade *encontrar_festividade(const char *nome)
{
    if (!nome || !*nome)
        return NULL;

    char nome_lower[MAX_NOME];
    strncpy(nome_lower, nome, MAX_NOME - 1);
    nome_lower[MAX_NOME - 1] = '\0';

    for (char *p = nome_lower; *p; p++)
        *p = tolower(*p);

    for (int i = 0; i < NUM_FEST; i++)
    {
        if (strcmp(nome_lower, tabela[i].nome) == 0)
        {
            return &tabela[i];
        }
    }
    return NULL;
}

/**
 * @brief Algoritmo simplificado de Meeus/Butcher para Páscoa gregoriana (1900–2100+)
 *
 * @param ano Ano para o qual calcular a Páscoa.
 * @param mes_out Ponteiro para armazenar o mês (0-11).
 * @param dia_out Ponteiro para armazenar o dia (1-31).
 * @return 1 se o cálculo foi bem-sucedido, 0 caso contrário.
 */
static int calcula_pascoa(int ano, int *mes_out, int *dia_out)
{
    if (ano < 1900 || ano > 2200)
        return 0;

    int a = ano % 19;                         // Ano dentro do ciclo Metônico
    int b = ano / 100;                        // Século
    int c = ano % 100;                        // Ano dentro do século
    int d = b / 4;                            // Correção do século
    int e = b % 4;                            // Resto da correção do século
    int f = (b + 8) / 25;                     // Correção do século para o calendário gregoriano
    int g = (b - f + 1) / 3;                  // Correção do século para o calendário gregoriano
    int h = (19 * a + b - d - g + 15) % 30;   // Epacta
    int i = c / 4;                            // Correção do ano dentro do século
    int k = c % 4;                            // Resto da correção do ano dentro do século
    int l = (32 + 2 * e + 2 * i - h - k) % 7; // Dia da semana da Lua cheia pascal
    int m = (a + 11 * h + 22 * l) / 451;      // Correção para o mês

    int mes = (h + l - 7 * m + 114) / 31; // 3 = março, 4 = abril
    int dia = ((h + l - 7 * m + 114) % 31) + 1;

    *mes_out = mes - 1; // struct tm usa 0-11
    *dia_out = dia;
    return 1;
}

/**
 * @brief Calcula a data do Carnaval com base na Páscoa.
 *
 * @param ano Ano para o qual calcular o Carnaval.
 * @param mes_out Ponteiro para armazenar o mês (0-11).
 * @param dia_out Ponteiro para armazenar o dia (1-31).
 * @return 1 se o cálculo foi bem-sucedido, 0 caso contrário.
 */
static int calcula_carnaval(int ano, int *mes_out, int *dia_out)
{
    int mes_p, dia_p;
    if (!calcula_pascoa(ano, &mes_p, &dia_p))
        return 0;

    // Carnaval = Páscoa - 47 dias
    struct tm data = {0};
    data.tm_year = ano - 1900;
    data.tm_mon = mes_p;
    data.tm_mday = dia_p;
    data.tm_hour = 12; // meio-dia para evitar problemas de horário de verão
    data.tm_isdst = -1;

    time_t t = mktime(&data);
    if (t == (time_t)-1)
        return 0;

    t -= 47LL * 86400; // 47 dias antes

    struct tm *res = localtime(&t);
    if (!res)
        return 0;

    *mes_out = res->tm_mon;
    *dia_out = res->tm_mday;
    return 1;
}

/**
 * @brief Calcula a próxima ocorrência de uma festividade e quantos dias faltam.
 *
 * @param nome Nome da festividade.
 */
void calcular_proxima(const char *nome)
{
    const Festividade *f = encontrar_festividade(nome);
    if (!f)
    {
        printf("Festividade não encontrada: %s\n", nome);
        printf("Disponíveis: ");
        for (int i = 0; i < NUM_FEST; i++)
        {
            printf("%s%s", tabela[i].nome, (i < NUM_FEST - 1) ? ", " : "\n");
        }
        return;
    }

    time_t agora = time(NULL);
    struct tm hoje = *localtime(&agora);
    hoje.tm_hour = hoje.tm_min = hoje.tm_sec = 0;
    hoje.tm_isdst = -1;
    mktime(&hoje); // normaliza

    struct tm evento = hoje; // copia ano, etc.

    int ano_base = hoje.tm_year + 1900;

    int ok = 0;
    if (f->dia > 0)
    {
        // Fixo
        evento.tm_mon = f->mes;
        evento.tm_mday = f->dia;
        ok = 1;
    }
    else if (f->calcula_movel)
    {
        // Móvel
        ok = f->calcula_movel(ano_base, &evento.tm_mon, &evento.tm_mday);
    }

    if (!ok)
    {
        printf("Erro ao calcular data para %s\n", f->nome);
        return;
    }

    evento.tm_hour = 12;
    evento.tm_min = evento.tm_sec = 0;
    evento.tm_isdst = -1;
    mktime(&evento);

    // Se já passou → próximo ano
    if (difftime(mktime(&evento), agora) < 0)
    {
        int proximo_ano = ano_base + 1;
        if (f->dia > 0)
        {
            evento.tm_year = proximo_ano - 1900;
            evento.tm_mon = f->mes;
            evento.tm_mday = f->dia;
        }
        else if (f->calcula_movel)
        {
            f->calcula_movel(proximo_ano, &evento.tm_mon, &evento.tm_mday);
            evento.tm_year = proximo_ano - 1900;
        }
        evento.tm_hour = 12;
        evento.tm_isdst = -1;
        mktime(&evento);
    }

    double segs = difftime(mktime(&evento), agora);
    int dias = (int)(segs / 86400.0 + 0.5); // arredonda

    printf("\nPróxima %s: %02d/%02d/%04d  →  faltam %d dias\n", f->nome,
           evento.tm_mday, evento.tm_mon + 1, evento.tm_year + 1900, dias);
}

int main(int argc, char **argv)
{
    char entrada[80];
    printf("Digite o nome da festividade (ex: carnaval, natal, halloween): ");
    if (fgets(entrada, sizeof(entrada), stdin))
    {
        entrada[strcspn(entrada, "\n")] = '\0';
        calcular_proxima(entrada);
    }
    return 0;
}
