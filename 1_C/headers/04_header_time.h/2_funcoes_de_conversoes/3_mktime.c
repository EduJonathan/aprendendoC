#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

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

// Definindo um enum para as festividades
typedef enum datasComemorativas
{
    HALLOWEEN,
    NATAL,
    CARNAVAL,
    FESTIVIDADE_INVALIDA
} Festividade;

/**
 * @brief Converte uma string para o enum Festividade.
 *
 * Função para converter string para enum Esta função recebe o nome de uma
 * festividade e retorna o enum correspondente.
 *
 * @param festividade Nome da festividade (como "Halloween", "Natal", etc.).
 * @return Festividade correspondente ao nome fornecido.
 */
Festividade get_festividade_enum(const char *festividade)
{
    if (strcasecmp(festividade, "Halloween") == 0)
    {
        return HALLOWEEN;
    }
    else if (strcasecmp(festividade, "Natal") == 0)
    {
        return NATAL;
    }
    else if (strcasecmp(festividade, "Carnaval") == 0)
    {
        return CARNAVAL;
    }
    return FESTIVIDADE_INVALIDA;
}

/**
 * @brief Converte a data fornecida para a estrutura tm e calcula o tempo até o próximo evento.
 *
 * Esta função recebe o nome de uma festividade e calcula a data do evento para
 * o próximo ano, informando o número de dias que faltam para o evento. Se a festividade
 * já passou neste ano, ela calculará a data para o próximo ano.
 *
 * @param festividade Nome da festividade (como "Halloween", "Natal", etc.).
 */
void calcular_data_comemorativa(const char *festividade)
{
    // Obtém a data e hora atual
    time_t agora = 0;
    time(&agora);

    // Converte a data e hora atual para uma estrutura tm
    struct tm *data_atual = localtime(&agora);

    // Estrutura tm para armazenar a data da festividade
    struct tm data_evento = {0};

    // Obtém o valor do enum para a festividade
    Festividade fest = get_festividade_enum(festividade);

    // Inicializa o ano da festividade para o ano atual
    data_evento.tm_year = data_atual->tm_year; // Começa com o ano atual

    switch (fest)
    {
    case HALLOWEEN:
        data_evento.tm_mon = 9;   // Outubro
        data_evento.tm_mday = 31; // 31 de Outubro
        break;

    case NATAL:
        data_evento.tm_mon = 11;  // Dezembro
        data_evento.tm_mday = 25; // 25 de Dezembro
        break;

    case CARNAVAL:
        // Para simplificação, o Carnaval de 2025 será em 17 de fevereiro
        data_evento.tm_year = data_atual->tm_year + 1; // Próximo ano
        data_evento.tm_mon = 1;                        // Fevereiro
        data_evento.tm_mday = 17;                      // 17 de Fevereiro
        break;

    default:
        printf("Data comemorativa não reconhecida!\n");
        return;
    }

    // Verifica se a data já passou neste ano
    if (difftime(mktime(&data_evento), agora) < 0)
    {
        // Se a festividade já passou no ano atual, ajusta para o próximo ano
        data_evento.tm_year = data_atual->tm_year + 1; // Ano seguinte
    }

    // Converte a data do evento para time_t (segundos desde a "época")
    time_t tempo_evento = mktime(&data_evento);

    if (tempo_evento == -1)
    {
        printf("Erro ao calcular o tempo da festividade.\n");
        return;
    }

    // Calcula a diferença entre a data do evento e a data atual em segundos
    double segundos_diferenca = difftime(tempo_evento, agora);

    // Converte a diferença de segundos para dias
    int dias_faltando = segundos_diferenca / (60 * 60 * 24);

    // Exibe o resultado
    printf("A festividade %s irá ocorrer em %d dias (%d/%d/%d).\n",
           festividade, dias_faltando, data_evento.tm_mday,
           data_evento.tm_mon + 1, data_evento.tm_year + 1900);
}

int main(int argc, char **argv)
{
    char festividade[BUFFER_SIZE] = {0};

    // Solicita o nome da festividade
    printf("Digite o nome da festividade (Halloween, Natal, Carnaval, etc.): ");
    fgets(festividade, sizeof(festividade), stdin);

    // Remove o caractere de nova linha
    festividade[strcspn(festividade, "\n")] = 0;

    // Chama a função para calcular a data da festividade
    calcular_data_comemorativa(festividade);
    return 0;
}
