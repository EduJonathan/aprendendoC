#include <stdio.h>

/**
 * feof(): Utilizada para verificar se o indicador de final de arquivo foi ativado
 * para um arquivo específico.
 *
 * SINTAXE: int feof(FILE *_File);
 *
 * @param File Ponteiro para arquivo
 * @return A função retorna um valor diferente de 0 se o indicador de final de arquivo
 * foi ativado. Se o indicador de final de arquivo não foi ativado, a função retorna 0.
 */

int main(int argc, char **argv)
{
    // Criando um arquivo
    FILE *arquivo = NULL;
    arquivo = fopen("arquivo.txt", "r");

    // Verificando a abertura do arquivo
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê e exibe o conteúdo do arquivo caractere por caractere
    char caractere = '\0';

    // Enquanto não chegar ao final do arquivo
    while ((caractere = fgetc(arquivo)) != EOF)
    {
        putchar(caractere);
    }

    // Verifica se chegou ao final do arquivo
    if (feof(arquivo))
    {
        printf("\nChegou ao final do arquivo.\n");
    }
    else
    {
        printf("\nNão chegou ao final do arquivo.\n");
    }

    // Fechando o arquivo
    fclose(arquivo);
    return 0;
}
