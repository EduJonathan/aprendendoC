#include <stdio.h>
#include <time.h>

/**
 * @brief Calcula a diferença de tempo até uma hora-alvo.
 *
 * @param hora_alvo Hora desejada (0-23).
 * @param minuto_alvo Minuto desejado (0-59).
 * @return Struct `tm` com a diferença em horas e minutos.
 */
struct tm calculaTempoRestante(int hora_alvo, int minuto_alvo)
{
    time_t agora;
    time(&agora); // Obtém o tempo atual em segundos desde 1970

    struct tm *local = localtime(&agora); // Converte para struct tm (hora local)
    struct tm alvo = *local;              // Cópia da hora atual

    // Define a hora-alvo
    alvo.tm_hour = hora_alvo;
    alvo.tm_min = minuto_alvo;
    alvo.tm_sec = 0;

    // Converte para time_t e calcula a diferença em segundos
    time_t tempo_alvo = mktime(&alvo);
    double diferenca = difftime(tempo_alvo, agora);

    // Se o horário-alvo já passou hoje, adiciona 24 horas
    if (diferenca < 0)
    {
        diferenca += 24 * 60 * 60; // +1 dia em segundos
    }

    // Converte a diferença de segundos para horas e minutos
    struct tm resto = {0};
    resto.tm_hour = (int)(diferenca / 3600);
    resto.tm_min = (int)((diferenca - resto.tm_hour * 3600) / 60);

    return resto;
}

int main(int argc, char **argv)
{
    int hora_alvo = 0, minuto_alvo = 0;

    printf("Digite a hora desejada (0-23): ");
    scanf("%d", &hora_alvo);

    printf("Digite o minuto desejado (0-59): ");
    scanf("%d", &minuto_alvo);

    // Obtém a diferença
    struct tm resto = calculaTempoRestante(hora_alvo, minuto_alvo);

    // Exibe o resultado
    printf("\nTempo restante até %02d:%02d:\n", hora_alvo, minuto_alvo);
    printf("→ %dh %dm\n", resto.tm_hour, resto.tm_min);

    return 0;
}
