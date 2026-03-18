#include "../include/report.h"
#include "../include/parser.h"
#include <stdio.h>

int generate_report(const void *parsed_data, const char *output_path)
{
    if (!parsed_data || !output_path)
        return -1;

    const LogSummary *s = parsed_data;

    FILE *f = fopen(output_path, "w");
    if (!f)
        return -2;

    fprintf(f, "Relatório de Log\n");
    fprintf(f, "================\n\n");
    fprintf(f, "Total de linhas:          %zu\n", s->total_lines);
    fprintf(f, "Linhas com 'error/ERROR': %zu (%.2f%%)\n",
            s->error_lines,
            s->total_lines > 0 ? (s->error_lines * 100.0 / s->total_lines) : 0.0);

    fclose(f);
    return 0;
}
