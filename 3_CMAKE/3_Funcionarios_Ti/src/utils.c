#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Assumindo que 'Pessoa' e 'NivelExperiencia' estão em "utils.h" e incluídos aqui.

void string_segura_copiar(char *destino, size_t tamanho_destino, const char *origem)
{
    if (!destino || tamanho_destino == 0 || !origem)
        return;

    size_t i = 0ull;
    for (; i < tamanho_destino - 1 && origem[i] != '\0'; i++)
    {
        destino[i] = origem[i];
    }
    destino[i] = '\0';
}

void log_info(const char *mensagem)
{
    // 1. time_t é usado para armazenar o tempo atual.
    time_t agora = time(NULL);
    char *timestamp_str;

    // 2. ctime() recebe &agora (ponteiro para time_t) e retorna a string formatada.
    // O retorno (timestamp_str) é um ponteiro para uma string estática interna.
    timestamp_str = ctime(&agora);

    if (timestamp_str != NULL)
    {
        // 3. Verifica se a string tem pelo menos 1 caractere antes de remover o '\n'.
        size_t len = strlen(timestamp_str);
        if (len > 0)
        {
            timestamp_str[len - 1] = '\0'; // Remover nova linha
        }
        printf("[INFO] [%s] %s\n", timestamp_str, mensagem);
    }
    else
    {
        // Fallback se ctime falhar
        printf("[INFO] %s\n", mensagem);
    }
}

void log_erro(const char *mensagem)
{
    time_t agora = time(NULL);
    char *timestamp_str;

    timestamp_str = ctime(&agora);

    if (timestamp_str != NULL)
    {
        size_t len = strlen(timestamp_str);
        if (len > 0)
        {
            timestamp_str[len - 1] = '\0';
        }
        // Usa fprintf com stderr para logs de erro
        fprintf(stderr, "[ERRO] [%s] %s\n", timestamp_str, mensagem);
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
    char *timestamp_str;

    timestamp_str = ctime(&agora);

    if (timestamp_str != NULL)
    {
        size_t len = strlen(timestamp_str);
        if (len > 0)
        {
            timestamp_str[len - 1] = '\0';
        }
        printf("[DEBUG] [%s] %s\n", timestamp_str, mensagem);
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
