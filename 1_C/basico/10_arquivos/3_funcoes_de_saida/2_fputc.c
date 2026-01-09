#include <stdio.h>
#include <string.h>

/**
 * fputc(): Função para ESCREVER um caractere em um arquivo.
 *
 * SINTAXE: int fputc(int _Ch, FILE *_File);
 *
 * @param _Ch: Escrita do conteúdo de caractere
 * @param _File: Arquivo para escrita do conteúdo de caractere
 * @return A função retorna o número de bytes escritos.
 *
 * @note A fputc() escreve um caractere em um arquivo aberto.
 */

int main(int argc, char **argv)
{
    // Criando um arquivo
    FILE *file = fopen("fptuc.txt", "w");

    // Verificando se o arquivo será aberto com sucesso
    if (file == NULL)
    {
        printf("ERROR AO TENTAR ABRIR O ARQUIVO");
        return 1;
    }
    else
    {
        printf("SUCESSO AO ABRIR O ARQUIVO");
    }

    // Insere a quebra de linha ('\n'), o fputchar não escreve no arquivo e sim no terminal
    fputchar('\n');

    // Escrevendo um conjunto de caracteres
    char frase[100] = {0};
    printf("Digite uma frase: ");
    scanf("%99[^\n]", frase);

    // Extraindo o tamanho da string
    size_t tam = strlen(frase);

    // Pecorrendo o tamanho da variável "frase" no arquivo, e escrever no arquivo
    for (int i = 0; i < tam; i++)
    {
        // Pecorre caractere por caractere
        fputc(frase[i], file);
    }

    // Fechando o arquivo
    fclose(file);
    return 0;
}
