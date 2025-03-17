#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * As funções ctime e ctime_s são ambas usadas em C para converter um valor de
 * tempo (geralmente representado como time_t) em uma string que representa esse tempo em
 * formato legível.
 *
 * DIFERENÇA ENTRE CTIME E CTIME_S:
 * ctime(): A função ctime é uma função padrão de C, definida na biblioteca <time.h>,
 * que converte um valor de tipo time_t (que geralmente representa o número de segundos
 * desde o "Epoch" - 1º de janeiro de 1970) para uma string formatada como uma data e hora
 * legível.
 *
 * SINTAXE: char *ctime(const time_t *timeptr);
 *
 * @param timeptr: Ponteiro para um objeto do tipo time_t que representa o tempo em segundos.
 * @return Retorna um ponteiro para uma string que representa a data e hora em formato ASCII.
 *
 * ------------------------------------------------------------------------------------------
 *
 * ctime_s(): é uma versão segura de ctime, introduzida para evitar problemas de segurança,
 * como vazamento de memória ou sobrescrição acidental de buffers. Ela faz parte da
 * especificação do C11 e é amplamente usada em compiladores que priorizam segurança,
 * como o MSVC (Microsoft Visual C++).
 *
 * SINTAXE: errno_t ctime_s(char *str, rsize_t maxsize, const time_t *timeptr);
 * @param str: O ponteiro para o buffer onde a string formatada será armazenada.
 * @param maxsize: O tamanho máximo do buffer (em bytes), para garantir que a função
 * não cause overflow de buffer.
 * @param timeptr: Um ponteiro para a variável do tipo time_t que contém o tempo a ser convertido.
 * @return A função retorna 0 em caso de sucesso ou um código de erro (errno_t) se algo der
 * errado, como um buffer muito pequeno para armazenar a string.
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
    char data_formatada[26]; // Para armazenar a string formatada da data

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
    char data_input[11]; // Formato de data: DD/MM/AAAA

    // Pedindo a data ao usuário
    printf("Digite a sua data (DD/MM/AAAA): ");
    scanf("%10s", data_input);

    // Chamando a função para calcular o dia da semana, mês e dia do mês
    calcular_dia_da_semana(data_input);
    return 0;
}
