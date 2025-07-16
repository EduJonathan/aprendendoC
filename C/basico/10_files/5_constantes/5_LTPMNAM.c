#include <stdio.h>

/**
 * LTPMNAM: Constante valor define o tamanho máximo do nome de um arquivo temporário.
 * Ele é útil ao criar buffers para armazenar nomes de arquivos temporários gerados
 * com tpmnam(). Ele define quantos caracteres podem estar no nome do arquivo temporário.
 */

int main(int argc, char **argv)
{
    printf("L_tmpnam: %d\n", L_tmpnam);

    char nomeTemp[L_tmpnam] = {0}; // Array para armazenar o nome do arquivo temporário

    // Gerando um nome de arquivo temporário
    tmpnam(nomeTemp);

    printf("Nome do arquivo temporário: %s\n", nomeTemp);

    return 0;
}
