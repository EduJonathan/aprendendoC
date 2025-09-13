#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void string_segura_copiar(char *destino, size_t tamanho_destino, const char *origem)
{
    if (!destino || tamanho_destino == 0 || !origem)
        return;

    size_t i;
    for (i = 0; i < tamanho_destino - 1 && origem[i] != '\0'; i++)
    {
        destino[i] = origem[i];
    }
    destino[i] = '\0';
}

void log_info(const char *mensagem)
{
    time_t agora = time(NULL);
    char timestamp[26];

    // Usando a versão segura do ctime
    if (ctime_s(timestamp, sizeof(timestamp), &agora) == 0)
    {
        timestamp[strlen(timestamp) - 1] = '\0'; // Remover nova linha
        printf("[INFO] [%s] %s\n", timestamp, mensagem);
    }
    else
    {
        printf("[INFO] %s\n", mensagem);
    }
}

void log_erro(const char *mensagem)
{
    time_t agora = time(NULL);
    char timestamp[26];

    if (ctime_s(timestamp, sizeof(timestamp), &agora) == 0)
    {
        timestamp[strlen(timestamp) - 1] = '\0';
        fprintf(stderr, "[ERRO] [%s] %s\n", timestamp, mensagem);
    }
    else
    {
        fprintf(stderr, "[ERRO] %s\n", mensagem);
    }
}

void log_debug(const char *mensagem)
{
#ifdef DEBUG
    time_t agora = time(NULL);
    char timestamp[26];

    if (ctime_s(timestamp, sizeof(timestamp), &agora) == 0)
    {
        timestamp[strlen(timestamp) - 1] = '\0';
        printf("[DEBUG] [%s] %s\n", timestamp, mensagem);
    }
    else
    {
        printf("[DEBUG] %s\n", mensagem);
    }
#else
    // Evita warning de parâmetro não utilizado quando DEBUG não está definido
    (void)mensagem;
#endif
}

bool validar_pessoa(const Pessoa *p)
{
    if (!p)
    {
        log_erro("Pessoa é nula");
        return false;
    }

    if (p->nome[0] == '\0')
    {
        log_erro("Pessoa com nome vazio");
        return false;
    }

    if (p->idade < 0 || p->idade > 150)
    {
        log_erro("Pessoa com idade inválida");
        return false;
    }

    if (p->salario < 0)
    {
        log_erro("Pessoa com salário negativo");
        return false;
    }

    // dados_processador pode ser NULL, não precisa validar
    return true;
}

/**
 * @brief Converte um nível de experiência para string legível.
 *
 * @param nivel Nível de experiência (JUNIOR, PLENO, SENIOR).
 * @return const char* String correspondente.
 */
const char *nivel_para_string(NivelExperiencia nivel)
{
    switch (nivel)
    {
    case JUNIOR:
        return "Júnior";

    case PLENO:
        return "Pleno";

    case SENIOR:
        return "Sênior";

    default:
        return "Desconhecido";
    }
}

void print_int(int x) { printf("Inteiro: %d\n", x); }
void print_float(float x) { printf("Float: %.2f\n", x); }
void print_double(double x) { printf("Double: %.2f\n", x); }
void print_string(const char *x) { printf("String: %s\n", x); }
