#include <stdio.h>
#include <stdlib.h>
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
    struct tm nascimento_tm = {0};
    struct tm hoje_tm = {0};
    time_t nascimento_time = 0, hoje_time = 0;

    // timespec struct que armazena a diferença em intervalos de segundos e nanosegundos
    struct timespec tempo_diferenca = {0};

    // Convertendo data de nascimento (25/09/2000) para struct tm
    sscanf(data_nascimento, "%d/%d/%d", &nascimento_tm.tm_mday, &nascimento_tm.tm_mon, &nascimento_tm.tm_year);

    nascimento_tm.tm_mon -= 1;     // Meses começam em 0
    nascimento_tm.tm_year -= 1900; // Anos começam a partir de 1900

    // Pegando a data de hoje
    time_t agora = time(NULL);
    hoje_tm = *localtime(&agora);

    // Convertendo as duas datas para time_t
    nascimento_time = mktime(&nascimento_tm);
    hoje_time = mktime(&hoje_tm);

    if (nascimento_time == -1 || hoje_time == -1)
    {
        printf("Erro ao converter as datas.\n");
        return;
    }

    // Calculando a diferença em segundos e nanosegundos
    tempo_diferenca.tv_sec = difftime(hoje_time, nascimento_time); // Diferença em segundos
    tempo_diferenca.tv_nsec = 0;                                   // Não estamos lidando com nanosegundos neste caso

    // Calculando a diferença em dias
    long dias = tempo_diferenca.tv_sec / (60 * 60 * 24);

    // Calculando a idade em anos
    int anos = dias / 365;

    // Exibindo a idade e a quantidade de dias
    printf("Você nasceu em %s e tem:\n", data_nascimento);
    printf("%d anos (aproximadamente)\n", anos);
    printf("%ld dias completos\n", dias);
}

int main(int argc, char **argv)
{
    // Formato de data: DD/MM/AAAA
    char data_nascimento[11] = {0};

    // Pedindo a data de nascimento ao usuário
    printf("Digite a sua data de nascimento (DD/MM/AAAA): ");
    scanf("%10s", data_nascimento);

    // Chamando a função para calcular idade
    calcular_idade(data_nascimento);
    return 0;
}
