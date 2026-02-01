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
 * @brief Imprime o tempo atual em formato legível + segundos desde a época
 * @param tempo Valor time_t a ser impresso
 */
void imprimirTempo(time_t tempo)
{
    if (tempo == (time_t)-1)
    {
        printf("Erro: tempo inválido.\n");
        return;
    }

    char *str = asctime(gmtime(&tempo));
    if (str)
    {
        // Remove \n final do asctime
        char buf[64];
        strncpy(buf, str, sizeof(buf) - 1);
        buf[sizeof(buf) - 1] = '\0';
        char *p = strchr(buf, '\n');
        if (p)
            *p = '\0';

        printf("Tempo UTC: %s  (%lld segundos desde 1970-01-01)\n",
               buf, (long long)tempo);
    }
    else
    {
        printf("Erro ao formatar tempo.\n");
    }
}

/**
 * @brief Calcula quantos dias faltam até a data informada
 *        - Se a data for no passado → avisa
 *        - Se for no futuro (mesmo ano ou próximo) → calcula dias
 *        - Usa mktime para validar a data e lidar com anos bissextos
 */
void calcular_dias_para_data(const char *data_usuario)
{
    time_t agora = time(NULL);
    if (agora == (time_t)-1)
    {
        printf("Erro ao obter hora atual.\n");
        return;
    }

    struct tm hoje = *localtime(&agora);
    hoje.tm_hour = 0;
    hoje.tm_min = 0;
    hoje.tm_sec = 0;
    hoje.tm_isdst = -1; // Deixa mktime decidir horário de verão
    time_t hoje_meia_noite = mktime(&hoje);

    if (hoje_meia_noite == (time_t)-1)
    {
        printf("Erro ao normalizar data atual.\n");
        return;
    }

    struct tm data_tm = {0};
    data_tm.tm_isdst = -1;

    int d, m, a;
    if (sscanf(data_usuario, "%d/%d/%d", &d, &m, &a) != 3 ||
        d < 1 || d > 31 || m < 1 || m > 12 || a < 1900 || a > 9999)
    {
        printf("Formato ou valores inválidos. Use dd/mm/aaaa (ex: 25/12/2025)\n");
        return;
    }

    data_tm.tm_mday = d;
    data_tm.tm_mon = m - 1;
    data_tm.tm_year = a - 1900;

    time_t alvo = mktime(&data_tm);
    if (alvo == (time_t)-1)
    {
        printf("Data inválida ou fora do intervalo suportado.\n");
        return;
    }

    // Ajusta ano se a data já passou no ano atual → considera próximo ano
    if (difftime(alvo, hoje_meia_noite) < 0)
    {
        // Data já passou → tenta próximo ano
        data_tm.tm_year += 1;
        alvo = mktime(&data_tm);
        if (alvo == (time_t)-1)
        {
            printf("Não foi possível calcular para o próximo ano.\n");
            return;
        }

        // Se mesmo assim estiver no passado (improvável), avisa
        if (difftime(alvo, hoje_meia_noite) < 0)
        {
            printf("Data muito no passado. Não é possível calcular.\n");
            return;
        }
    }

    double segs = difftime(alvo, hoje_meia_noite);
    int dias = (int)(segs / (24.0 * 3600.0));

    printf("\n");
    printf("Data alvo ............: %02d/%02d/%04d\n", d, m, a);
    printf("Faltam ...............: %d dias\n", dias);
    printf("Data por extenso .....: %.24s\n", asctime(&data_tm)); // 24 chars sem \n
}

int main(int argc, char **argv)
{
    time_t now = time(NULL);
    if (now != (time_t)-1)
    {
        printf("Segundos desde 1970 ........: %lld\n", (long long)now);
        imprimirTempo(now);
    }

    printf("\n===============================================\n");

    char buffer[BUFFER_SIZE];
    char opcao = '\0';

    do
    {
        printf("\nDigite uma data (dd/mm/aaaa): ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        // Remove espaços extras (opcional)
        char *p = buffer;
        while (*p == ' ')
            p++;

        if (p != buffer)
            memmove(buffer, p, strlen(p) + 1);

        if (strlen(buffer) < 8)
        {
            printf("Entrada muito curta.\n");
            continue;
        }

        calcular_dias_para_data(buffer);

        printf("\nVerificar outra data? (s/n): ");
        opcao = getchar();
        while (getchar() != '\n'); // limpa resto da linha

    } while (opcao == 's' || opcao == 'S');
    return 0;
}
