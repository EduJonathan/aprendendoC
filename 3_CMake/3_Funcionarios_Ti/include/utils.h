#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdbool.h>
#include "pessoa.h"

/**
 * @brief Obtém o número de elementos de um array estático.
 */
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/**
 * @brief Retorna o menor entre dois valores.
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * @brief Retorna o maior entre dois valores.
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * @brief Copia uma string de forma segura para o destino.
 *
 * @param destino Buffer de destino.
 * @param tamanho_destino Tamanho máximo do buffer de destino.
 * @param origem String de origem.
 */
void string_segura_copiar(char *destino, size_t tamanho_destino, const char *origem);

/**
 * @brief Exibe uma mensagem de log informativa.
 *
 * @param mensagem Texto da mensagem.
 */
void log_info(const char *mensagem);

/**
 * @brief Exibe uma mensagem de log de erro.
 *
 * @param mensagem Texto da mensagem.
 */
void log_erro(const char *mensagem);

/**
 * @brief Exibe uma mensagem de log para depuração.
 *
 * @param mensagem Texto da mensagem.
 */
void log_debug(const char *mensagem);

/**
 * @brief Valida os dados de uma pessoa.
 *
 * @param p Ponteiro para a pessoa.
 * @return true se a pessoa for válida, false caso contrário.
 */
bool validar_pessoa(const Pessoa *p);

/**
 * @brief Converte um nível de experiência para string legível.
 *
 * @param nivel Valor do enum NivelExperiencia.
 * @return String representando o nível.
 */
const char *nivel_para_string(NivelExperiencia nivel);

/**
 * @brief Macro para imprimir valores de forma genérica (C11).
 *
 * Usa `_Generic` para escolher a função correta com base no tipo.
 */
#define PRINT_VALUE(x) _Generic((x), \
    int: print_int,                  \
    float: print_float,              \
    double: print_double,            \
    char *: print_string,            \
    const char *: print_string)(x)

/**
 * @brief Imprime um valor inteiro.
 *
 * @param x Valor inteiro.
 */
void print_int(int x);

/**
 * @brief Imprime um valor float.
 *
 * @param x Valor float.
 */
void print_float(float x);

/**
 * @brief Imprime um valor double.
 *
 * @param x Valor double.
 */
void print_double(double x);

/**
 * @brief Imprime uma string.
 *
 * @param x Ponteiro para a string.
 */
void print_string(const char *x);

#endif // UTILS_H
