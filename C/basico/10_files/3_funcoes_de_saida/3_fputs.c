#include <stdio.h>
#include <string.h>

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
 * @note A funcao fgets() pode ser usada para ler dados de um arquivo aberto.
 */

/**
 * fputs(): Escreve a string str no arquivo apontado, até encontrar o caractere '\0',
 * retornando um valor não negativo em caso de sucesso ou EOF(end of file) em caso de erro.
 *
 * SINTAXE: int fputs(const char *__restrict__ _Str, FILE *__restrict__ _File);
 *
 * @param _Str: String que devemos passar para ser lida
 * @param _File: variável associada ao arquivo onde a string será lida
 * @return A função retorna um valor não negativo em caso de sucesso ou EOF(end of file)
 * em caso de erro.
 * @note A funcao fputs() pode ser usada para escrever dados em um arquivo aberto.
 */

int main(int argc, char **argv)
{
    // Criando e verificando o arquivo
    FILE *file = NULL;

    // Variavel que irá ser utilizada para Lê e armazenar no arquivo
    char frase[100];

    // Verificando a abertura do arquivo dentro do if
    if ((file = fopen("fputs.txt", "w")) == NULL)
    {
        printf("ERROR AO TENTAR ABRIR O ARQUIVO\n");
        return 1;
    }
    else
    {
        printf("Digite uma frase para ser guardada: ");
        fgets(frase, sizeof(frase), stdin);

        // Escrevendo a string para o arquivo
        fputs(frase, file);

        printf("Arquivo e dados salvos com sucesso\n");
        fclose(file);
    }

    return 0;
}
