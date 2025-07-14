#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

/**
 * time: Função da biblioteca de manipulação de tempo (time.h)
 *
 * SINTAXE: time_t time(time_t *_Time);
 *
 * Sua sintaxe é criada através do time_t, que é criado através de um estrutura time_t
 * para representar o tempo.
 *
 * @param _Time: Ponteiro para um objeto do tipo time_t que representa o tempo em segundos.
 * @return Retorna o tempo atual em segundos desde a "época"
 * (que é 1º de janeiro de 1970 às 00:00:00 UTC).
 */

/**
 * @brief Função para imprimir o tempo atual
 *
 * imprimirTempo(): Função para imprimir o tempo atual
 *
 * @param tempo: Tempo atual em segundos
 */
void imprimirTempo(time_t tempo)
{
    // Obtendo o tempo atual
    tempo = time(NULL);

    // Imprimindo o tempo atual
    if (tempo != (time_t)(-1))
    {
        printf("O tempo atual é %s(%lld segundos desde a 'época')\n", asctime(gmtime(&tempo)), tempo);
    }

    /**
     * asctime(): Função da biblioteca de manipulação de tempo (time.h) que converte um tempo
     * representado em segundos desde a "época" (que é 1º de janeiro de 1970 às 00:00:00 UTC)
     * para uma representação de tempo local
     *
     * SINTAXE: char *asctime(const struct tm *timeptr);
     *
     * @param timeptr: Ponteiro para uma estrutura struct tm que contém informações sobre a data e hora.
     * @return Retorna um ponteiro para uma string que representa a data e hora em formato ASCII.
     */

    /**
     * gtime(): Função da biblioteca de manipulação de tempo (time.h), é usada para converter
     * um valor de tempo, expresso em segundos desde a "época" (o tempo 0, geralmente 1 de
     * janeiro de 1970), para uma estrutura tm que representa uma data e hora no formato UTC
     * (Tempo Universal Coordenado).
     *
     * SINTAXE: struct tm *gmtime(const time_t *_Time);
     *
     * @param _Time: Ponteiro para um objeto do tipo time_t que representa o tempo em segundos.
     * @return A função retorna um ponteiro para uma estrutura tm, que contém os valores de
     * data e hora em formato UTC (ano, mês, dia, hora, minuto, segundo, etc.).
     */
}

/**
 * @brief Calcula quantos dias faltam para uma data informada pelo usuário.
 *
 * O programa recebe uma data no formato "dd/mm/yyyy" e calcula a quantidade de
 * dias que faltam até essa data. Se a data já passou no ano atual, ela considera o próximo
 * ano. Se a data informada for no passado (ano anterior), ele informa que a data já passou.
 *
 * @param data_usuario Data informada pelo usuário no formato "dd/mm/yyyy".
 */
void calcular_dias_para_data(const char *data_usuario)
{
    // Obtém a data e hora atual
    time_t agora;
    time(&agora);

    // Converte a data e hora atual para uma estrutura tm
    struct tm *data_atual = localtime(&agora);

    // Estrutura tm para armazenar a data fornecida pelo usuário
    struct tm data_informada = {0};

    // Lê a data informada pelo usuário no formato "dd/mm/yyyy"
    int dia = 0, mes = 0, ano = 0;
    if (sscanf(data_usuario, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        printf("Formato de data inválido! Use dd/mm/aaaa.\n");
        return;
    }

    // Ajusta a estrutura tm para a data informada
    data_informada.tm_mday = dia;        // Dia ajusta-se para a data informada
    data_informada.tm_mon = mes - 1;     // Meses começam de 0, então subtraímos 1
    data_informada.tm_year = ano - 1900; // Anos começam de 1900, então subtraímos 1900

    // Verifica se a data informada é no passado
    if (difftime(mktime(&data_informada), agora) < 0)
    {
        printf("Esta data já passou. Tente uma data futura.\n");
        return;
    }

    // Verifica se a data informada já passou neste ano
    if (difftime(mktime(&data_informada), agora) < 0)
    {
        // Se a data já passou, ajusta para o próximo ano
        data_informada.tm_year = data_atual->tm_year + 1;
    }

    // Converte a data informada para time_t (segundos desde a "época")
    time_t tempo_informado = mktime(&data_informada);

    if (tempo_informado == -1)
    {
        printf("Erro ao calcular o tempo da data.\n");
        return;
    }

    // Calcula a diferença entre a data informada e a data atual em segundos
    double segundos_diferenca = difftime(tempo_informado, agora);

    // Converte a diferença de segundos para dias
    int dias_faltando = segundos_diferenca / (60 * 60 * 24);

    // Exibe o resultado
    printf("Faltam %d dias para a data informada, que é no dia %02d/%02d/%04d.\n",
           dias_faltando, data_informada.tm_mday,
           data_informada.tm_mon + 1,
           data_informada.tm_year + 1900);
}

int main(int argc, char **argv)
{
    // Criando uma variável para armazenar o tempo atual
    time_t now;

    // Obtendo o tempo atual
    time(&now);

    printf("Tempo atual em segundos: %lld\n", now);

    // Imprimindo o tempo atual em string
    imprimirTempo(now);

    printf("\n===============================================\n");

    char data_usuario[BUFFER_SIZE] = {0};

    while (1)
    {
        // Solicita que o usuário insira a data
        printf("Digite uma data no formato dd/mm/aaaa: ");
        fgets(data_usuario, sizeof(data_usuario), stdin);

        // Remove o caractere de nova linha
        data_usuario[strcspn(data_usuario, "\n")] = 0;

        // Chama a função para calcular a quantidade de dias para a data informada
        calcular_dias_para_data(data_usuario);

        // Pergunta ao usuário se deseja continuar ou encerrar
        char continuar = '\0';
        printf("\nDeseja verificar outra data? (s/n): ");
        scanf(" %c", &continuar);

        // Limpa o buffer de entrada de dados após o scanf
        getchar();

        if (continuar == 'n' || continuar == 'N')
        {
            break;
        }
    }
    return 0;
}
