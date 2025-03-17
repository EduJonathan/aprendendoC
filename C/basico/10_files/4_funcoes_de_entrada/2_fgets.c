#include <stdio.h>

/**
 * fgets(): Lê uma linha de texto até encontrar um '\n' ou EOF, armazenando-a em uma
 * string e retornando a string lida ou NULL em caso de erro ou fim de arquivo.
 *
 * SINTAXE: char *fgets(char *__restrict__ _Buf, int _MaxCount, FILE *__restrict__ _File);
 *
 * @param _Buf: String que devemos passar para ser lida
 * @param _MaxCount: limite até onde os caracteres devem ser lidos
 * @param _FILE: Variável associada ao arquivo onde a string será lida
 * @return A funcao retorna a string lida ou NULL em caso de erro ou fim de arquivo
 *
 * @note A funcao fgets() pode ser usada para ler dados de um arquivo aberto.
 */

int main(int argc, char **argv)
{
    // Criando o arquivo
    FILE *arquivo = NULL;
    arquivo = fopen("fgets.txt", "w");

    // Verificando se o arquivo será aberto
    if (arquivo == NULL)
    {
        perror("ERRO AO ABRIR O ARQUIVO\n");
        return 1; // Termina o programa se houve erro na abertura do arquivo
    }
    else
    {
        printf("ARQUIVO ABERTO COM SUCESSO\n");
    }

    // Trecho de captura de uma string para o arquivo
    char string[50];
    char *str = string;

    // Lê uma linha do teclado e armazena em str
    printf("ESCREVA ALGO PARA O ARQUIVO: ");
    fgets(str, sizeof(string), stdin);

    // Escreve a string lida no arquivo
    fprintf(arquivo, "%s", str);

    // Fechar o arquivo
    fclose(arquivo);
    printf("Dados escritos no arquivo com sucesso.\n");
    return 0;
}
