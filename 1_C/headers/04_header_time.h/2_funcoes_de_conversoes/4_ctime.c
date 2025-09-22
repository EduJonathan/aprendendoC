#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * ctime(): Converte um valor de tipo `time_t` para uma string representando a data e hora legível em formato ASCII.
 *
 * SINTAXE: char *ctime(const time_t *timeptr);
 *
 * @param timeptr: Ponteiro para um valor `time_t` (segundos desde a "época").
 * @return: Retorna uma string representando a data e hora legível.
 *
 * ------------------------------------------------------------------------------------------
 *
 * ctime_s(): Versão segura de `ctime()`, evitando riscos de segurança como overflows de buffer.
 *
 * SINTAXE: errno_t ctime_s(char *str, rsize_t maxsize, const time_t *timeptr);
 *
 * @param str: Ponteiro para o buffer onde a string formatada será armazenada.
 * @param maxsize: Tamanho máximo do buffer para evitar overflow.
 * @param timeptr: Ponteiro para um valor `time_t`.
 * @return: Retorna 0 em caso de sucesso ou código de erro (`errno_t`).
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
    time_t tempo = 0;              // Variável do tipo time_t para armazenar o tempo em segundos
    char data_formatada[26] = {0}; // Para armazenar a string formatada da data

    // Usando sscanf para ler a data no formato DD/MM/YYYY
    sscanf(data_input, "%d/%d/%d", &data_tm.tm_mday, &data_tm.tm_mon, &data_tm.tm_year);

    // Ajustando o mês (0-11) e o ano (desde 1900)
    data_tm.tm_mon -= 1;
    data_tm.tm_year -= 1900;

    // Convertendo para time_t
    tempo = mktime(&data_tm);

    // Verificando se a data é válida
    if (tempo == -1)
    {
        printf("Erro ao converter a data.\n");
        return;
    }

    // Usando ctime_s para formatar a data
    ctime_s(data_formatada, sizeof(data_formatada), &tempo);

    // Exibindo o resultado
    printf("Data fornecida: %s\n", data_formatada);
    printf("Dia da semana: %s\n", (data_tm.tm_wday == 0) ? "Domingo" : (data_tm.tm_wday == 1) ? "Segunda-feira"
                                                                   : (data_tm.tm_wday == 2)   ? "Terça-feira"
                                                                   : (data_tm.tm_wday == 3)   ? "Quarta-feira"
                                                                   : (data_tm.tm_wday == 4)   ? "Quinta-feira"
                                                                   : (data_tm.tm_wday == 5)   ? "Sexta-feira"
                                                                                              : "Sábado");

    printf("Mês: %s\n", (data_tm.tm_mon == 0) ? "Janeiro" : (data_tm.tm_mon == 1) ? "Fevereiro"
                                                        : (data_tm.tm_mon == 2)   ? "Março"
                                                        : (data_tm.tm_mon == 3)   ? "Abril"
                                                        : (data_tm.tm_mon == 4)   ? "Maio"
                                                        : (data_tm.tm_mon == 5)   ? "Junho"
                                                        : (data_tm.tm_mon == 6)   ? "Julho"
                                                        : (data_tm.tm_mon == 7)   ? "Agosto"
                                                        : (data_tm.tm_mon == 8)   ? "Setembro"
                                                        : (data_tm.tm_mon == 9)   ? "Outubro"
                                                        : (data_tm.tm_mon == 10)  ? "Novembro"
                                                                                  : "Dezembro");
    printf("Dia do mês: %d\n", data_tm.tm_mday);
}

int main(int argc, char **argv)
{
    char data_input[11] = {0}; // Formato de data: DD/MM/AAAA

    // Pedindo a data ao usuário
    printf("Digite a sua data (DD/MM/AAAA): ");
    scanf("%10s", data_input);

    // Chamando a função para calcular o dia da semana, mês e dia do mês
    calcular_dia_da_semana(data_input);
    return 0;
}
