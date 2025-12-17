#include <stdio.h>
#include <stdlib.h>
#include "file_ops.h"

/**
 * @brief Copia o conteúdo de um arquivo para um novo destino.
 *
 * Abre o arquivo de origem em modo leitura binária e o destino em escrita binária.
 * Utiliza um buffer de 8KB para otimizar a transferência de dados.
 *
 * @param source Caminho do arquivo de origem.
 * @param dest Caminho do arquivo de destino.
 * @return int Retorna 1 em caso de sucesso, 0 em caso de erro.
 */
int copy_file(const char *source, const char *dest)
{
    FILE *src = fopen(source, "rb");
    FILE *dst = fopen(dest, "wb");

    if (!src)
    {
        perror("Erro ao abrir arquivo de origem");
        return 0;
    }

    if (!dst)
    {
        perror("Erro ao abrir arquivo de destino");
        fclose(src);
        return 0;
    }

    char buffer[8192];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        if (fwrite(buffer, 1, bytes, dst) != bytes)
        {
            perror("Erro ao escrever no destino");
            fclose(src);
            fclose(dst);
            return 0;
        }
    }

    fclose(src);
    fclose(dst);
    return 1;
}

/**
 * @brief Move um arquivo de um local para outro.
 *
 * Tenta renomear o arquivo diretamente. Caso os arquivos estejam em
 * sistemas de arquivos diferentes, realiza a cópia seguida da remoção do original.
 *
 * @param source Caminho atual do arquivo.
 * @param dest Novo caminho do arquivo.
 * @return int Retorna 1 em caso de sucesso, 0 em caso de falha.
 */
int move_file(const char *source, const char *dest)
{
    if (rename(source, dest) == 0)
    {
        return 1;
    }

    if (copy_file(source, dest))
    {
        if (remove(source) == 0)
        {
            return 1;
        }
        else
        {
            perror("Erro ao remover arquivo original");
            remove(dest);
        }
    }

    return 0;
}
