#include <stdio.h>
#include <time.h>

/**
 * difftime(): É função da biblioteca de manipulação de tempo (time.h) que calcula
 * a diferença em segundos entre dois intervalos de valores do tipo time_t. *
 *
 * SINTAXE: double difftime(time_t time1, time_t time2);
 *
 * @param time_beg: Tempo inicial em segundos.
 * @param time_end: Tempo final em segundos.
 * @return retorna a diferença em segundos entre dois instantes de tempo.
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
 * @param data_referencia Ponteiro para uma estrutura `tm` contendo a data de referência
 * (25 de setembro do ano atual).
 */
void calcular_diferenca_data(struct tm *data_referencia)
{
    // Obtém a data e hora atual
    time_t agora;
    time(&agora);

    // Converte a data e hora atual para uma estrutura tm
    struct tm *data_atual = localtime(&agora);

    // Cria a data de referência (25 de setembro do ano atual)
    data_referencia->tm_year = data_atual->tm_year; // Ano atual
    data_referencia->tm_mon = 8;                    // Setembro (mês 8, porque começa de 0)
    data_referencia->tm_mday = 25;                  // Dia 25

    // Converte a data de referência para time_t (segundos desde a época)
    time_t tempo_referencia = mktime(data_referencia);

    if (tempo_referencia == -1)
    {
        printf("Erro ao calcular o tempo da data de referência.\n");
        return;
    }

    // Calcula a diferença entre as datas em segundos
    double segundos_diferenca = difftime(agora, tempo_referencia);

    // Converte a diferença de segundos para dias
    int dias_diferenca = segundos_diferenca / (60 * 60 * 24);

    // Calcula os meses e dias
    int meses_diferenca = dias_diferenca / 30; // Aproximação de meses (30 dias por mês)
    int dias_restantes = dias_diferenca % 30;

    // Exibe a diferença
    printf("O dia 25 de setembro foi há %d meses e %d dias!\n", meses_diferenca, dias_restantes);

    /// OBS: Desafio você a programar para que o usuário digite a data de referência?
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
int calcularDiasFaltando(struct tm dataAtual, struct tm dataDestino)
{
    // Converter as duas estruturas tm para time_t
    time_t tempoAtual = mktime(&dataAtual);
    time_t tempoDestino = mktime(&dataDestino);

    // Calcular a diferença em segundos
    double diferencaSegundos = difftime(tempoDestino, tempoAtual);

    // Converter de segundos para dias
    return diferencaSegundos / (60 * 60 * 24); // 60 segundos * 60 minutos * 24 horas
}

int main(int argc, char **argv)
{
    // Obtém o tempo atual
    time_t now;
    time(&now);

    // Cria uma estrutura tm representando o início do mês corrente
    struct tm beg = {0};

    beg = *localtime(&now);
    beg.tm_hour = 0;
    beg.tm_min = 0;
    beg.tm_sec = 0;
    beg.tm_mday = 1;

    // Calcula a diferença de tempo em segundos entre agora e o início do mês
    double seconds = difftime(now, mktime(&beg));

    // Imprime a quantidade de segundos que se passaram desde o início do mês
    printf("%f segundos têm passado desde o início do mês\n", seconds);

    printf("\n===============================================\n");

    calcular_diferenca_data(&beg);

    printf("\n===============================================\n");

    // Data atual (07/12/2024)
    struct tm dataAtual = {0};
    dataAtual.tm_year = 2024 - 1900; // Ano desde 1900
    dataAtual.tm_mon = 11;           // Dezembro (0-11)
    dataAtual.tm_mday = 7;           // 7 de Dezembro

    // Variáveis para a data de destino
    struct tm dataDestino = {0};
    int dia = 0, mes = 0, ano = 0;

    // Solicitar ao usuário para digitar a data de destino
    printf("Digite a data de destino (formato DD MM AAAA): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    // Preencher a estrutura tm com a data fornecida
    dataDestino.tm_mday = dia;        // Dia do mês
    dataDestino.tm_mon = mes - 1;     // Meses em tm são de 0 a 11, então subtrai 1
    dataDestino.tm_year = ano - 1900; // Ano desde 1900

    // Calcular os dias faltando
    int diasFaltando = calcularDiasFaltando(dataAtual, dataDestino);

    // Exibir o resultado
    if (diasFaltando >= 0)
    {
        printf("Faltam %d dias até a data fornecida.\n", diasFaltando);
    }
    else
    {
        printf("A data fornecida já passou.\n");
    }
    return 0;
}
