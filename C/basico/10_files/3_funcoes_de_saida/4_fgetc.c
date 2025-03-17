#include <stdio.h>
#include <stdlib.h>

/**
 * fgetc(): Lê um caractere do arquivo apontado por 'stream' e retorna o caractere lido como
 * um unsigned char convertido para int ou EOF(END OF FILE) em caso de erro ou fim do arquivo.
 *
 * SINTAXE: int fgetc(FILE *_File);
 *
 * @param _File Ponteiro para arquivo
 * @return A funcao retorna o caractere lido ou EOF(end of file) em caso de erro
 * @note A funcao fgetc() pode ser usada para ler dados de um arquivo aberto.
 */

int main(int argc, char **argv)
{
    // Criando o arquivo
    FILE *arq = NULL;
    arq = fopen("fgetc.txt", "r");

    // Verifica se o arquivo foi aberto
    if (arq == NULL)
    {
        perror("Erro na abertura do arquivo\n");
        return 1;
    }

    // Será utilizada para armazenar cada caractere lido do arquivo.
    char c;

    // loop que permite ler e imprimir até 5 caracteres
    for (int i = 0; i < 5; i++)
    {
        c = fgetc(arq);  // Lê um caractere do arquivo apontado por 'arq' e armazena em 'c'
        printf("%c", c); // Imprime o caractere lido
    }

    // Fecha o arquivo
    fclose(arq);
    return 0;
}
