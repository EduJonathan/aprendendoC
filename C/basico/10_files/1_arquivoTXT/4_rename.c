#include <stdio.h>

/**
 * rename(): Altera o nome de um arquivo ou move um arquivo para um novo diretório.
 * Se o novo nome estiver em um diretório diferente, a função também moverá o arquivo
 * para o novo diretório.
 *
 * SINTAXE: int rename(const char *_OldFilename, const char *_NewFilename);
 *
 * @param oldname: O nome atual do arquivo (ou o caminho do arquivo) que você deseja renomear
 * ou mover.
 * @param newname: O novo nome do arquivo (ou o novo caminho para o arquivo).
 * @return A função retorna 0 se a operação for bem-sucedida.
 * Se houver um erro ao renomear o arquivo, a função retorna -1.
 *
 * @warning: O nome do arquivo deve ser um caminho completo, incluindo o caminho e o
 * nome do arquivo. Se o nome do arquivo for apenas o nome do arquivo, a função retornará um erro.
 */

int main(int argc, char **argv)
{
    char nome_arquivo[100];
    char novo_nome_arquivo[100];
    FILE *arquivo = NULL;

    // Solicita o nome do arquivo para criar ou abrir
    printf("Digite o nome do arquivo para criar ou abrir (com extensão .txt): ");
    scanf("%s", nome_arquivo);

    // Abre o arquivo em modo de escrita (cria o arquivo ou sobrescreve se já existir)
    arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Solicita ao usuário para digitar o conteúdo do arquivo
    printf("Digite o conteúdo que deseja salvar no arquivo (pressione ENTER para finalizar): ");
    getchar(); // Consumir o caractere '\n' deixado pelo scanf

    char ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        fputc(ch, arquivo);
    }

    // Fecha o arquivo após escrever
    fclose(arquivo);

    // Solicita o novo nome para o arquivo
    printf("\nDigite o novo nome para o arquivo (com extensão .txt): ");
    scanf("%s", novo_nome_arquivo);

    // Renomeia o arquivo utilizando rename()
    if (rename(nome_arquivo, novo_nome_arquivo) == 0)
    {
        printf("Arquivo renomeado com sucesso de '%s' para '%s'.\n", nome_arquivo, novo_nome_arquivo);
    }
    else
    {
        perror("Erro ao renomear o arquivo");
        return 1;
    }

    return 0;
}
