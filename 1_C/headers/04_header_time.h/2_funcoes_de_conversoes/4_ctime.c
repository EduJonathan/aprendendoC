#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * ctime(): Converte um valor de tipo `time_t` para uma string representando a data e hora legível em formato ASCII.
 *
 * SINTAXE: char *ctime(const time_t *timeptr);
 *
 * @param timeptr: Ponteiro para um valor `time_t` (segundos desde a "época").
 * @return: Retorna uma string representando a data e hora legível.
 */

/**
 * @brief Calcula o dia da semana de uma data fornecida no formato DD/MM/YYYY.
 *
 * calcular_dia_da_semana: Função que recebe uma data no formato DD/MM/YYYY e
 * calcula o dia da semana correspondente.
 *
 * @param data_input Data fornecida no formato DD/MM/YYYY.
 */
void calcular_dia_da_semana(const char *data_input)
{
    struct tm data_tm = {0};
    time_t tempo;

    // Deixar o sistema decidir sobre horário de verão
    data_tm.tm_isdst = -1;

    int dia, mes, ano;
    if (sscanf(data_input, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        printf("Formato inválido! Use exatamente DD/MM/AAAA (ex: 25/12/2024)\n");
        return;
    }

    // Validação básica
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 9999)
    {
        printf("Valores da data estão fora do intervalo razoável.\n");
        return;
    }

    data_tm.tm_mday = dia;
    data_tm.tm_mon = mes - 1; // meses: 0 = Janeiro, 11 = Dezembro
    data_tm.tm_year = ano - 1900;

    tempo = mktime(&data_tm);
    if (tempo == (time_t)-1)
    {
        printf("Data inválida ou fora do alcance suportado.\n");
        return;
    }

    // Usando ctime()
    char *str_data = ctime(&tempo);
    if (str_data == NULL)
    {
        printf("Erro ao formatar a data com ctime().\n");
        return;
    }

    // ctime() retorna string com \n no final → podemos remover se quiser
    char data_limpa[32];
    strncpy(data_limpa, str_data, sizeof(data_limpa) - 1);
    data_limpa[sizeof(data_limpa) - 1] = '\0';
    char *p = strchr(data_limpa, '\n');

    // verifica e remove o newline
    if (p)
        *p = '\0';

    // Nomes em português (independente do locale do sistema)
    static const char *dias_pt[] = {
        "Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira",
        "Quinta-feira", "Sexta-feira", "Sábado"};

    static const char *meses_pt[] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    printf("\n");
    printf("Data digitada ........: %02d/%02d/%04d\n", dia, mes, ano);
    printf("Data por extenso ......: %s\n", data_limpa);
    printf("Dia da semana .........: %s\n", dias_pt[data_tm.tm_wday]);
    printf("Mês ...................: %s\n", meses_pt[data_tm.tm_mon]);
    printf("Dia do mês ............: %d\n", data_tm.tm_mday);
    printf("Número do dia (0=Domingo): %d\n", data_tm.tm_wday);
}

int main(int argc, char **argv)
{
    char data_input[32] = {0};

    printf("Digite a data (DD/MM/AAAA): ");
    if (fgets(data_input, sizeof(data_input), stdin) == NULL)
    {
        printf("Erro ao ler a entrada.\n");
        return 1;
    }

    // Remove \n do final
    data_input[strcspn(data_input, "\n")] = '\0';

    // Remove espaços extras (opcional, mas ajuda)
    char *p = data_input;
    while (*p == ' ')
        p++;
        
    if (p != data_input)
        memmove(data_input, p, strlen(p) + 1);

    calcular_dia_da_semana(data_input);
    return 0;
}
