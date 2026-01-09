#include <stdio.h>

/**
 * getc(): é uma função em C que é usada para ler um caractere de um arquivo.
 * Geralmente utilizada para ler caracteres de um arquivo apontado por um ponteiro FILE.
 *
 * SINTAXE: int getc(FILE *_File)
 * @param _File Ponteiro para arquivo
 */

int main(int argc, char **argv)
{
    // Criando o arquivo
    FILE *file = NULL;
    file = fopen(__FILE__, "r");
    // __FILE__: Constante pré-definida pelo compilador que contém o nome do arquivo fonte atual.

    // Verificando se o arquivo será aberto com sucesso
    if (file == NULL)
    {
        perror("ERROR AO TENTAR ABRIR O ARQUIVO");
        return 1;
    }
    else
    {
        printf("SUCESSO AO ABRIR O ARQUIVO");
    }

    char c = '\0'; // Variável para armazenar o caractere lido

    do
    {
        c = getc(file);  // Lê um caractere do arquivo apontado por 'file' e armazena em 'c'
        printf("%c", c); // Imprime o caractere lido

        // Continua lendo e imprimindo caracteres até o final do arquivo (EOF) ser alcançado
    } while (c != EOF);

    // A função getc() retorna o caractere lido como um inteiro (int).
    // Se o final do arquivo (EOF) for atingido ou se ocorrer um erro durante a leitura,
    // a função retorna a constante EOF (-1).

    // Fecha o arquivo
    fclose(file);
    return 0;
}
