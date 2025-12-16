#ifndef UTIL_H
#define UTIL_H

#include <sys/stat.h>
#include <unistd.h>

/**
 * @brief Verifica se um arquivo existe no caminho especificado.
 *
 * @param path Caminho do arquivo a ser verificado.
 * @return 1 se o arquivo existir, 0 caso contrário.
 */
int file_exists(const char *path);

/**
 * @brief Verifica se o processo atual tem permissão de leitura no arquivo especificado.
 *
 * @param path Caminho do arquivo a ser verificado.
 * @return 1 se tiver permissão de leitura, 0 caso contrário.
 */
int has_read_permission(const char *path);

/**
 * @brief Libera a memória apontada por um ponteiro e define o ponteiro como NULL.
 *
 * Evita double-free e uso de ponteiro pendente.
 *
 * @param ptr Ponteiro para o ponteiro a ser liberado.
 */
void safe_free(void **ptr);

#endif // UTIL_H