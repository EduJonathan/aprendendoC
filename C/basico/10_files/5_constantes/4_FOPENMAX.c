#include <stdio.h>

/**
 * FOPENMAX: É uma constante definida na biblioteca padrão  da linguagem C. Ela representa o
 * número máximo de arquivos que um programa pode ter abertos simultaneamente.
 */

int main(int argc, char **argv)
{
    printf("FOPEN_MAX: %d\n", FOPEN_MAX);

    FILE *arquivos[FOPEN_MAX] = {NULL}; // Array para armazenar ponteiros de arquivos
    char nomeArquivo[20] = {0};         // Array para armazenar o nome do arquivo

    // Tentando abrir o número máximo de arquivos permitidos
    for (int i = 0; i < FOPEN_MAX; i++)
    {
        snprintf(nomeArquivo, sizeof(nomeArquivo), "arquivo_%d.txt", i);
        arquivos[i] = fopen(nomeArquivo, "w");

        if (!arquivos[i])
        {
            printf("Não foi possível abrir mais arquivos. Limite atingido em %d arquivos.\n", i);
            break;
        }

        fprintf(arquivos[i], "Este é o arquivo %d\n", i);
    }

    // Fechando todos os arquivos abertos
    for (int i = 0; i < FOPEN_MAX; i++)
    {
        if (arquivos[i])
        {
            fclose(arquivos[i]);
        }
    }

    printf("Arquivos criados e fechados corretamente.\n");

    return 0;
}
