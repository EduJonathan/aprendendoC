#include "../include/log_reader.h"
#include "../include/parser.h"
#include "../include/report.h"
#include "../include/util.h"
#include <stdio.h>

/**
 * Para Compilar e Executar o programa no terminal linux
 *
 * Estando dentro da pasta 2_Gerenciador_de_Arquivos_Log(~/Documentos/aprendendoC/3_CMake/2_Gerenciador_de_Arquivos_Log):
 *
 * Criar a pasta build e entrar nela:
 * > mkdir build && cd build
 *
 * Gerar os arquivos de build com o make:
 * > make
 *
 * Compilar o programa:
 * > ./gerenciador_log caminho/para/seu.log relatorio.txt
 * > ./gerenciador_log /home/eduardo/Documentos/aprendendoC/1_C/basico/01_comeco/Comentarios.txt meu_relatorio.txt
 *
 * O log pode ser qualquer arquivo légivel, como um .txt ou .log
 * > ./gerenciador_log teste.log relatorio_final.txt
 */

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Uso: %s <arquivo_log_entrada> <arquivo_relatorio_saida>\n", argv[0]);
        return 1;
    }

    const char *input_path = argv[1];
    const char *output_path = argv[2];

    size_t data_size;
    void *raw_data = read_log_file(input_path, &data_size);

    if (raw_data == NULL)
    {
        fprintf(stderr, "Falha ao ler o arquivo de log.\n");
        return 1;
    }

    void *parsed_data = NULL;
    int parse_result = parse_log_data(raw_data, data_size, &parsed_data);

    if (parse_result != 0)
    {
        fprintf(stderr, "Falha ao parsear os dados (código: %d).\n", parse_result);
        safe_free(&raw_data);
        return 1;
    }

    int report_result = generate_report(parsed_data, output_path);

    if (report_result != 0)
    {
        fprintf(stderr, "Falha ao gerar o relatório (código: %d).\n", report_result);
    }
    else
    {
        printf("Relatório gerado com sucesso em: %s\n", output_path);
    }

    // Limpeza
    safe_free(&parsed_data);
    safe_free(&raw_data);

    return report_result != 0 ? 1 : 0;
}
