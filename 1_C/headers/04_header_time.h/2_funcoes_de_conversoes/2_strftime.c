#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define BUFFER_SIZE 100

/**
 * strftime(): Converte e formata a data e hora em uma string de caracteres de acordo com
 * um formato especificado pelo usuário. Comumente utilizada junto com `localtime()` para
 * obter informações sobre o tempo local e apresentá-las de forma legível.
 *
 * SINTAXE: size_t strftime(char *str, size_t max, const char *format, const struct tm *timeptr);
 *
 * @param str Ponteiro para o buffer onde a string formatada será armazenada.
 * @param max Tamanho máximo do buffer (incluindo o caractere nulo `\0`).
 * @param format String de formato que especifica a representação desejada da data e hora.
 * @param timeptr Ponteiro para a estrutura `tm` com informações sobre a data e hora.
 *
 * @return Retorna o número de caracteres escritos, excluindo o caractere nulo de terminação.
 *          Se o buffer for pequeno, o valor será truncado conforme o tamanho `max`.
 *
 * @note Importante:
 * - A função `strftime()` é útil quando você precisa exibir ou manipular datas e horas
 * em um formato específico.
 *
 * - A string de formato pode incluir diferentes especificadores, como `%d` (dia), `%m` (mês),
 * `%Y` (ano), `%H` (hora),`%M` (minuto), `%S` (segundo), e outros, para construir o formato desejado.
 *
 * - A função não adiciona o caractere nulo de terminação, que deve ser incluído no tamanho
 * especificado por `max`.
 *
 * - Caso o formato ou o buffer de saída sejam incompatíveis, a função retornará o número
 * de caracteres que foram efetivamente escritos.
 */

/**
 * @brief Calcula e exibe o número de dias restantes para o próximo aniversário
 *        com base na data de nascimento fornecida em formato "dd/mm/aaaa".
 *
 * @param entrada String contendo a data de nascimento no formato "dd/mm/aaaa".
 */
void calcular_dias_para_aniversario(const char *entrada)
{
    if (!entrada || !*entrada)
    {
        printf("Data não informada.\n");
        return;
    }

    int dia = 0, mes = 0, ano = 0;
    if (sscanf(entrada, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        printf("Formato inválido! Use dd/mm/aaaa (ex: 15/07/1995)\n");
        return;
    }

    // Validação básica
    if (ano < 1900 || ano > 3000 || mes < 1 || mes > 12 || dia < 1 || dia > 31)
    {
        printf("Data inválida (ano, mês ou dia fora do intervalo).\n");
        return;
    }

    time_t agora_utc = time(NULL);
    struct tm hoje_utc = *gmtime(&agora_utc);
    hoje_utc.tm_hour = hoje_utc.tm_min = hoje_utc.tm_sec = 0;
    hoje_utc.tm_isdst = -1;
    mktime(&hoje_utc); // normaliza (geralmente não muda nada em UTC)

    struct tm aniversario = {0};      // inicializa todos os campos com zero
    aniversario.tm_mday = dia;        // dia do mês
    aniversario.tm_mon = mes - 1;     // meses em tm vão de 0 a 11
    aniversario.tm_year = ano - 1900; // ano desde 1900
    aniversario.tm_hour = 0;          // meia-noite
    aniversario.tm_min = 0;           // meia-noite
    aniversario.tm_sec = 0;           // meia-noite
    aniversario.tm_isdst = -1;        // informação de horário de verão desconhecida

    // Define ano do próximo aniversário
    int ano_base = hoje_utc.tm_year + 1900;
    aniversario.tm_year = ano - 1900;

    if (ano < ano_base - 100 || ano > ano_base + 100)
    {
        printf("Ano muito distante (%d). Provavelmente erro de digitação.\n", ano);
        return;
    }

    // Coloca no ano atual ou próximo
    aniversario.tm_year = hoje_utc.tm_year; // tenta ano atual

    mktime(&aniversario); // normaliza (ajusta se 29/02 em ano não bissexto)

    // Se já passou → próximo ano
    if (mktime(&aniversario) < agora_utc)
    {
        aniversario.tm_year++;
        mktime(&aniversario); // normaliza novamente
    }

    // Calcula diferença em dias (arredonda para cima se > 12h, mas aqui usamos floor)
    double diff_segundos = difftime(mktime(&aniversario), agora_utc);
    long dias = (long)(diff_segundos / 86400.0);

    // Formata data em português (ou inglês se preferir)
    char data_formatada[80];

    // strftime em pt_BR pode variar por sistema → usamos formato fixo
    const char *meses[] = {"jan", "fev", "mar", "abr", "mai", "jun",
                           "jul", "ago", "set", "out", "nov", "dez"};

    const char *dias_semana[] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sáb"};

    snprintf(data_formatada, sizeof(data_formatada), "%s, %02d %s %04d",
             dias_semana[aniversario.tm_wday],
             aniversario.tm_mday,
             meses[aniversario.tm_mon],
             aniversario.tm_year + 1900);

    printf("Faltam **%ld dias** para o seu próximo aniversário.\n", dias);
    printf("Data: %s (00:00 UTC)\n", data_formatada);
    printf("Aniversário base: %02d/%02d\n", dia, mes);
}

int main(int argc, char **argv)
{
    char entrada[BUFFER_SIZE] = {0};

    printf("Calculadora de dias para o próximo aniversário (UTC)\n");
    printf("Digite sua data de nascimento (dd/mm/aaaa): ");

    if (!fgets(entrada, sizeof(entrada), stdin))
    {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    entrada[strcspn(entrada, "\n")] = '\0';

    // Remove espaços extras (opcional)
    char *p = entrada;
    while (isspace(*p))
        p++;
    memmove(entrada, p, strlen(p) + 1);

    calcular_dias_para_aniversario(entrada);

    // Exemplo de data atual (apenas informativo)
    time_t agora = time(NULL);
    struct tm *lt = localtime(&agora);
    char buf[80];
    strftime(buf, sizeof(buf), "Hoje (%Y-%m-%d %H:%M %Z)", lt);
    printf("\n%s\n", buf);

    return 0;
}
