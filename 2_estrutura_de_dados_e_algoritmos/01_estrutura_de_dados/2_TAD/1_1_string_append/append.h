#ifndef APPEND_H
#define APPEND_H

#define STRING_MAX_LENGTH 255 // Tamanho máximo da string

#include <string.h>
#include <stdio.h>

#ifndef _APPEND_
#define _APPEND_

/**
 * @brief Estrutura que representa uma string
 *
 * Esta estrutura armazena uma string, incluindo o tamanho e a capacidade.
 */
typedef struct append
{
    unsigned char data[STRING_MAX_LENGTH]; /**< Armazena os caracteres da string */
    unsigned int length;                   /**< Armazena o tamanho da string */
    unsigned int capacity;                 /**< Armazena a capacidade da string */
} string;

#endif

/**
 * @brief Inicializa uma string
 *
 * Macro que inicia uma string, limpando o array de caracteres
 * e iniciando o tamanho e a capacidade da string.
 *
 * - `string` Estrutura que representa a string
 */
#define string_init(string)                              \
    do                                                   \
    {                                                    \
        /* Limpa o array de caracteres */                \
        memset((string).data, 0, sizeof((string).data)); \
                                                         \
        /* Inicia o tamanho e a capacidade da string */  \
        (string).length = 0;                             \
                                                         \
        /* Inicia a capacidade da string */              \
        (string).capacity = STRING_MAX_LENGTH;           \
    } while (0)

/**
 * @brief Adiciona um caractere na string
 *
 * Macro que adiciona um caractere na string, verificando se a
 * capacidade da string foi atingida.
 *
 * - `string` Estrutura que representa a string
 *
 * - `caractere` Caractere a ser adicionado
 */
#define string_append(string, caractere)                        \
    do                                                          \
    {                                                           \
        /* Se o tamanho da string for menor que a capacidade */ \
        if ((string).length < (string).capacity - 1)            \
        {                                                       \
            /* Copia o caractere para a string */               \
            (string).data[(string).length++] = (caractere);     \
        }                                                       \
    } while (0)

/**
 * @brief Imprime a string
 *
 * Macro que imprime a string na tela.
 *
 * - `string` Estrutura que representa a string
 */
#define string_print(string)                   \
    do                                         \
    {                                          \
        /* Imprime o conjunto de caracteres */ \
        printf("%s\n", (string).data);         \
    } while (0)

#endif
