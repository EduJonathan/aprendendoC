#ifndef LOG_READER_H
#define LOG_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>

/**
 * @brief Lê o conteúdo completo de um arquivo de log de forma segura e retorna os dados brutos.
 *
 * A função verifica existência e permissão de leitura antes de abrir o arquivo.
 * Em caso de sucesso, aloca memória dinamicamente para os dados e atualiza out_size.
 * O caller é responsável por liberar a memória com safe_free().
 *
 * @param file_path Caminho do arquivo de log a ser lido.
 * @param out_size  Ponteiro para armazenar o tamanho dos dados lidos (em bytes).
 * @return Ponteiro para os dados lidos (alocados dinamicamente). Retorna NULL em caso de falha.
 */
void *read_log_file(const char *file_path, size_t *out_size);

#endif // LOG_READER_H
