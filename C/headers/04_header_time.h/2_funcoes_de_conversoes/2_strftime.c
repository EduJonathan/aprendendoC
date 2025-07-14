#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

/**
 * STRFTIME: Função usada para formatar a data e hora em uma string de caracteres.
 * strftime ("string format time") Essa função é geralmente utilizada em conjunto com
 * a função localtime para obter informações sobre o tempo local.
 *
 * SINTAXE: size_t strftime(char *str, size_t max, const char *format, const struct tm *timeptr);
 *
 * @param str Ponteiro para um array de caracteres onde a string formatada será armazenada.
 *
 * @param max Número máx. de caracteres que podem ser armazenados em str, incluindo o caractere nulo ('\0').
 *
 * @param format String de formato que especifica como a data e hora devem ser formatadas na string resultante.
 *
 * @param timeptr ponteiro para uma estrutura struct tm que contém informações sobre a data e hora.
 */

/**
 * @brief Calcula quantos dias faltam para o próximo aniversário do usuário em UTC e exibe a
 * data em formato UTC.
 *
 * O programa recebe a data de aniversário do usuário e calcula o número de dias até o próximo
 * aniversário em horário UTC, levando em consideração se o aniversário já passou no ano atual.
 * Exibe a data do próximo aniversário no formato "Dia da Semana Mês Dia Ano"
 * (por exemplo, "Sat Dec 07 2024").
 *
 * @param aniversario Data de aniversário do usuário no formato "dd/mm/yyyy".
 */
void calcular_dias_para_aniversario(const char *aniversario)
{
    // Obtém a data e hora atual
    time_t agora;
    time(&agora);

    // Converte a data e hora atual para uma estrutura tm em UTC
    struct tm *data_atual = gmtime(&agora);

    // Estrutura tm para armazenar a data do aniversário
    struct tm data_aniversario = {0};

    // Lê a data de aniversário no formato "dd/mm/yyyy"
    int dia = 0, mes = 0, ano = 0;
    if (sscanf(aniversario, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        printf("Formato de data inválido! Use dd/mm/aaaa.\n");
        return;
    }

    // Ajusta a data do aniversário
    data_aniversario.tm_mday = dia;
    data_aniversario.tm_mon = mes - 1;     // Meses começam do 0, então subtraímos 1
    data_aniversario.tm_year = ano - 1900; // Anos começam de 1900, então subtraímos 1900

    // Verifica se o aniversário já passou neste ano
    if (data_aniversario.tm_mon < data_atual->tm_mon ||
        (data_aniversario.tm_mon == data_atual->tm_mon && data_aniversario.tm_mday < data_atual->tm_mday))
    {
        // Se o aniversário já passou, ajusta para o próximo ano
        data_aniversario.tm_year = data_atual->tm_year + 1;
    }
    else
    {
        // Caso o aniversário não tenha passado, mantemos o ano atual
        data_aniversario.tm_year = data_atual->tm_year;
    }

    // Converte a data do aniversário para time_t (segundos desde a "época")
    time_t tempo_aniversario = mktime(&data_aniversario);

    if (tempo_aniversario == -1)
    {
        printf("Erro ao calcular o tempo do aniversário.\n");
        return;
    }

    // Calcula a diferença entre a data do aniversário e a data atual em segundos
    double segundos_diferenca = difftime(tempo_aniversario, agora);

    // Converte a diferença de segundos para dias
    int dias_faltando = segundos_diferenca / (60 * 60 * 24);

    // Exibe o próximo aniversário no formato "Dia da Semana Mês Dia Ano" em UTC
    char aniversario_utc[BUFFER_SIZE];
    strftime(aniversario_utc, sizeof(aniversario_utc), "%a %b %d %Y", &data_aniversario);

    // Exibe o resultado
    printf("Faltam %d dias para o seu aniversário, que ocorrerá em %s em UTC.\n",
           dias_faltando, aniversario_utc);
}

int main(int argc, char **argv)
{
    // Declaração de variáveis
    time_t tempo;
    struct tm *infotempo = NULL;
    char texto[80] = {0}; // Buffer para armazenar a string formatada

    // Imprimindo endereços de memória
    printf("Endereço de 'tempo': %p\n", (void *)&tempo);

    // Obtendo o tempo atual
    time(&tempo);

    // Obtendo informações sobre o tempo local
    infotempo = localtime(&tempo);

    // Imprimindo endereço de memória após a inicialização
    printf("Endereço de 'infotempo': %p\n", (void *)infotempo);

    // Formatando e imprimindo a hora atual
    strftime(texto, 80, "Hora atual: %I:%M %p.", infotempo);
    puts(texto);

    // Formatando e imprimindo a data atual
    strftime(texto, 80, "Data: %A, %d/%b/%Y", infotempo);
    puts(texto);

    time_t rawtime;
    char limit[80] = {0}; // Buffer para armazenar a string formatada

    time(&rawtime);
    infotempo = localtime(&rawtime);

    strftime(limit, sizeof(limit), "Data: %Y-%m-%d Hora: %H:%M:%S", infotempo);
    printf("Data formatada: %s\n", limit);

    printf("\n===============================================\n");

    char aniversario[BUFFER_SIZE];

    // Solicita o nome da festividade
    printf("Digite a sua data de aniversário (dd/mm/aaaa): ");
    fgets(aniversario, sizeof(aniversario), stdin);

    // Remove o caractere de nova linha
    aniversario[strcspn(aniversario, "\n")] = 0;

    // Chama a função para calcular a quantidade de dias para o aniversário
    calcular_dias_para_aniversario(aniversario);
    return 0;
}
