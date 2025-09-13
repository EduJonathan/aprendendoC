#include <stdio.h>
#include <string.h>

/**
 * FILENAMEMAX: É uma constante definida na biblioteca padrão. Ela representa o tamanho
 * máximo permitido para um nome de arquivo, incluindo seu caminho completo. Assim como,
 * o valor de pode variar dependendo do sistema operacional e da implementação do compilador.
 */

int main(int argc, char **argv)
{
    printf("FILENAME_MAX: %d\n", FILENAME_MAX);

    char nomeArquivo[FILENAME_MAX] = {0}; // Array para armazenar o nome do arquivo

    printf("Digite o caminho do arquivo: ");
    fgets(nomeArquivo, FILENAME_MAX, stdin);

    // Remover a quebra de linha gerada pelo fgets
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    printf("Arquivo aberto com sucesso: %s\n", nomeArquivo);
    fclose(arquivo);

    return 0;
}
