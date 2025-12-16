#include "../include/log_reader.h"
#include "../include/util.h"

void *read_log_file(const char *file_path, size_t *out_size)
{
    if (file_path == NULL || out_size == NULL)
    {
        return NULL;
    }

    // Verifica existência
    if (!file_exists(file_path))
    {
        fprintf(stderr, "Erro: Arquivo '%s' não existe.\n", file_path);
        return NULL;
    }

    // Verifica permissão de leitura
    if (!has_read_permission(file_path))
    {
        fprintf(stderr, "Erro: Sem permissão de leitura no arquivo '%s'.\n", file_path);
        return NULL;
    }

    FILE *file = fopen(file_path, "rb");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    // Obtém o tamanho do arquivo
    if (fseek(file, 0, SEEK_END) != 0)
    {
        perror("Erro ao buscar fim do arquivo");
        fclose(file);
        return NULL;
    }

    long file_size = ftell(file);
    if (file_size < 0)
    {
        perror("Erro ao obter posição no arquivo");
        fclose(file);
        return NULL;
    }

    if (fseek(file, 0, SEEK_SET) != 0)
    {
        perror("Erro ao voltar ao início do arquivo");
        fclose(file);
        return NULL;
    }

    // Aloca memória + 1 para possível terminador nulo (útil se for texto)
    void *buffer = malloc((size_t)file_size + 1);
    if (buffer == NULL)
    {
        perror("Erro ao alocar memória");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, (size_t)file_size, file);
    if (bytes_read != (size_t)file_size)
    {
        fprintf(stderr, "Erro: Leitura incompleta do arquivo.\n");
        safe_free(&buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);

    // Opcional: adicionar terminador nulo se for texto
    ((char *)buffer)[file_size] = '\0';

    *out_size = (size_t)file_size;
    return buffer;
}
