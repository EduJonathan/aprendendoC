#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "dir_list.h"
#include "file_ops.h"

/**
 * Este projeto demonstra o uso de dirent.h para manipulação de sistemas de arquivos em C.
 * fazendo parte da API POSIX (Portable Operating System Interface), o include <dirent.h> permite
 * listar e manipular conteúdos de diretórios de forma portável em sistemas Unix-like (Linux, macOS, BSD, etc.).
 * Ele define funções para abrir um diretório, ler as suas entradas uma a uma e fechá-lo.
 *
 * #include <stdio.h>
 * #include <dirent.h>
 * #include <errno.h>
 *
 * int main(void) {
 * DIR *dir;
 * struct dirent *entry;
 *
 * dir = opendir(".");  // "." = diretório atual
 * if (dir == NULL) {
 *      perror("Erro ao abrir diretório");
 *      return 1;
 * }
 *
 * while ((entry = readdir(dir)) != NULL)
 * {
 *      // Ignora as entradas "." (atual) e ".." (pai)
 *      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
 *          continue;
 *
 *      printf("%s\n", entry->d_name);
 * }
 * closedir(dir);
 * return 0;
 * }
 *
 * dirent.h no Windows, Problema: dirent.h não existe nativamente no Windows (MSVC)
 */

#define MAX_NAME 256

int main(int argc, char **argv)
{
    int choice = 0;
    int show_list = 0;
    char source[MAX_NAME];
    char dest[MAX_NAME];

    do
    {
        clear_screen();
        printf("\n\t\tMenu Principal\n");
        printf("--------------------------------\n");
        printf("1. Copiar um arquivo\n");
        printf("2. Mover um arquivo\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }
        while (getchar() != '\n');

        switch (choice)
        {
        case 1:
        case 2:
            printf("\nDeseja ver a lista de arquivos (1=sim / 0=não)? ");
            scanf("%d", &show_list);
            while (getchar() != '\n');

            if (show_list)
            {
                list_files();
                printf("\nPressione Enter para continuar...");
                getchar();
            }

            printf("Arquivo de origem: ");
            fgets(source, MAX_NAME, stdin);
            source[strcspn(source, "\n")] = '\0';

            printf("Arquivo de destino: ");
            fgets(dest, MAX_NAME, stdin);
            dest[strcspn(dest, "\n")] = '\0';

            if (choice == 1)
            {
                copy_file(source, dest)
                    ? printf("\nArquivo copiado com sucesso!\n")
                    : printf("\nErro ao copiar arquivo.\n");
            }
            else
            {
                move_file(source, dest)
                    ? printf("\nArquivo movido com sucesso!\n")
                    : printf("\nErro ao mover arquivo.\n");
            }

            printf("\nPressione Enter para voltar ao menu...");
            getchar();
            break;

        case 3:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpção inválida! Pressione Enter...");
            getchar();
        }
    } while (choice != 3);

    return 0;
}
