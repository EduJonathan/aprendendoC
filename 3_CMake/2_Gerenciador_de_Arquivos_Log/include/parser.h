#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief Analisa os dados brutos lidos de um arquivo de log e converte-os em uma estrutura interna.
 *
 * A função aloca memória para a estrutura parseada e atribui o ponteiro em parsed_output.
 * O caller é responsável por liberar essa memória após o uso (com safe_free() ou função específica).
 *
 * @param raw_data      Ponteiro para os dados brutos lidos do arquivo.
 * @param data_size     Tamanho dos dados brutos em bytes.
 * @param parsed_output Ponteiro para ponteiro que receberá o endereço da estrutura parseada.
 * @return 0 em caso de sucesso, ou código de erro negativo em caso de falha.
 */
int parse_log_data(const void *raw_data, size_t data_size, void **parsed_output);

#endif // PARSER_H