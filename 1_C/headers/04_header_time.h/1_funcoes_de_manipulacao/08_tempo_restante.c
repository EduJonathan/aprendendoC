#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief Calcula o tempo restante até um horário-alvo (hoje ou amanhã).
 *
 * @param hora_alvo   Hora desejada (0-23)
 * @param minuto_alvo Minuto desejado (0-59)
 * @param diff_horas  Ponteiro para receber as horas restantes
 * @param diff_minutos Ponteiro para receber os minutos restantes
 * @return true se cálculo bem-sucedido, false se entrada inválida
 */
bool calculaTempoRestante(int hora_alvo, int minuto_alvo, int *diff_horas, int *diff_minutos)
{
    if (hora_alvo < 0 || hora_alvo > 23 || minuto_alvo < 0 || minuto_alvo > 59)
    {
        return false;
    }

    time_t agora = time(NULL);
    if (agora == (time_t)-1)
    {
        return false;
    }

    struct tm *local = localtime(&agora);
    if (!local)
    {
        return false;
    }

    struct tm alvo = *local;
    alvo.tm_hour = hora_alvo;
    alvo.tm_min = minuto_alvo;
    alvo.tm_sec = 0;
    alvo.tm_isdst = -1; // deixa mktime decidir sobre horário de verão

    time_t tempo_alvo = mktime(&alvo);
    if (tempo_alvo == (time_t)-1)
    {
        return false;
    }

    double diferenca = difftime(tempo_alvo, agora);

    // Se já passou hoje → considera amanhã
    if (diferenca < 0)
    {
        diferenca += 86400.0; // 24 horas em segundos
    }

    // Converte para horas e minutos
    *diff_horas = (int)(diferenca / 3600.0);
    *diff_minutos = (int)((diferenca - (*diff_horas * 3600.0)) / 60.0);

    return true;
}

int main(int argc, char **argv)
{
    int hora = 0, minuto = 0; 
    int diff_h = 0, diff_m = 0;

    printf("Digite a hora desejada (0-23): ");
    if (scanf("%d", &hora) != 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }

    printf("Digite o minuto desejado (0-59): ");
    if (scanf("%d", &minuto) != 1)
    {
        printf("Entrada inválida.\n");
        return 1;
    }

    // Limpa o buffer (boa prática após scanf)
    while (getchar() != '\n' && getchar() != EOF);

    if (!calculaTempoRestante(hora, minuto, &diff_h, &diff_m))
    {
        printf("Horário inválido ou erro ao calcular.\n");
        return 1;
    }

    printf("\n");
    printf("Agora são aproximadamente %02d:%02d\n",
           localtime(&((time_t){time(NULL)}))->tm_hour,
           localtime(&((time_t){time(NULL)}))->tm_min);
           
    printf("Tempo restante até %02d:%02d:\n", hora, minuto);
    printf("→ %d hora(s) e %d minuto(s)\n", diff_h, diff_m);

    if (diff_h >= 24)
    {
        printf("  (será amanhã)\n");
    }
    return 0;
}
