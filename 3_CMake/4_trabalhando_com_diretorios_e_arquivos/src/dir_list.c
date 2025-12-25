#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "../includes/dir_list.h"

/**
 * @brief Lista os arquivos do diretório atual.
 * Percorre as entradas do diretório ".", ignorando os links ocultos "." e "..".
 * Implementa uma paginação simples a cada 20 arquivos encontrados.
 * 
 * @note Requer suporte a POSIX (dirent.h).
 * @return void
 */
void list_files(void)
{
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    int count = 0;

    dir = opendir(".");
    if (dir == NULL)
    {
        perror("Não foi possível abrir o diretório");
        return;
    }

    printf("\nArquivos no diretório atual:\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        printf("%s\n", entry->d_name);
        count++;

        if (count % 20 == 0)
        {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    }

    closedir(dir);

    if (count == 0)
    {
        printf("(diretório vazio)\n");
    }
}
