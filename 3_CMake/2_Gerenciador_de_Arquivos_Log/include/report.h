#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>

/**
 * @brief Gera um relatório formatado a partir dos dados já parseados e salva em um arquivo.
 *
 * @param parsed_data Ponteiro para os dados já analisados/parseados.
 * @param output_path Caminho do arquivo onde o relatório será salvo (será sobrescrito se existir).
 * @return 0 em caso de sucesso, ou código de erro negativo em caso de falha.
 */
int generate_report(const void *parsed_data, const char *output_path);

#endif // REPORT_H