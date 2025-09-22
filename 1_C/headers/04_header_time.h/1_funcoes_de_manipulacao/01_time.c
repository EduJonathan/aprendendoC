#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

/**
 * time(): Retorna o tempo atual em segundos desde a "época" (1º de janeiro de 1970, 00:00:00 UTC).
 * Pode ser usada para obter o tempo atual ou preencher uma variável do tipo `time_t`.
 *
 * SINTAXE: time_t time(time_t *_Time);
 *
 * @param _Time Ponteiro para um valor `time_t` onde o tempo atual pode ser armazenado (opcional).
 * Se for `NULL`, a função retorna o tempo atual sem modificar nenhum valor.
 *
 * @return Retorna o tempo atual em segundos desde a "época". Se `_Time` não for `NULL`,
 * o valor também é armazenado na variável apontada por `_Time`.
 *
 * @note Importante:
 * - A "época" (ou *epoch*) é um ponto de referência usado para medir o tempo e é fixada
 *   em 1º de janeiro de 1970, 00:00:00 UTC.
 *
 * - O valor retornado representa o número de segundos desde esse ponto de referência.
 *
 * - A função é comumente usada em aplicações que exigem timestamps, como logging ou
 *   comparação de tempos.
 *
 * - O tipo `time_t` é um tipo aritmético inteiro, mas sua representação exata pode variar
 *   dependendo da plataforma (geralmente é um número inteiro de 32 bits ou 64 bits).
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
    tempo = time(NULL);

    if (tempo != (time_t)(-1))
        printf("O tempo atual é %s(%lld segundos desde a 'época')\n",
               asctime(gmtime(&tempo)), (long long)tempo);
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
    time_t agora = time(NULL);
    struct tm data_atual = *localtime(&agora);

    // --- ZERA horas/min/seg para considerar só a data ---
    data_atual.tm_hour = 0;
    data_atual.tm_min = 0;
    data_atual.tm_sec = 0;
    time_t hoje_meia_noite = mktime(&data_atual);

    // Estrutura para armazenar a data fornecida pelo usuário
    struct tm data_informada = {0};
    int dia = 0, mes = 0, ano = 0;

    if (sscanf(data_usuario, "%d/%d/%d", &dia, &mes, &ano) != 3)
    {
        printf("Formato de data inválido! Use dd/mm/aaaa.\n");
        return;
    }

    data_informada.tm_mday = dia;
    data_informada.tm_mon = mes - 1;
    data_informada.tm_year = ano - 1900;

    time_t tempo_informado = mktime(&data_informada);
    if (tempo_informado == -1)
    {
        printf("Erro ao calcular o tempo da data.\n");
        return;
    }

    // Se a data já passou, avisa
    if (difftime(tempo_informado, hoje_meia_noite) < 0)
    {
        printf("Esta data já passou. Tente uma data futura.\n");
        return;
    }

    // Diferença em dias corridos
    double segundos_diferenca = difftime(tempo_informado, hoje_meia_noite);
    int dias_faltando = (int)(segundos_diferenca / (60 * 60 * 24));
    // ou, se quiser contar qualquer fração como 1 dia:
    // int dias_faltando = (int)ceil(segundos_diferenca / (60*60*24));

    printf("Faltam %d dias para a data informada, que é no dia %02d/%02d/%04d.\n",
           dias_faltando,
           data_informada.tm_mday,
           data_informada.tm_mon + 1,
           data_informada.tm_year + 1900);
}

int main(int argc, char **argv)
{
    // Criando uma variável para armazenar o tempo atual
    time_t now = 0;

    // Obtendo o tempo atual
    time(&now);
    printf("Tempo atual em segundos: %lld\n", (long long)now);

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
