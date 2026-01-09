#include <stdio.h>

/**
 * fileno(): converte um ponteiro para um objeto FILE em um descritor de arquivo.
 * Esse descritor pode ser usado em chamadas de sistema de baixo nível, como read, write,
 * e close, que requerem descritores de arquivo em vez de ponteiros FILE.
 *
 * SINTAXE: int fileno(FILE *File);
 *
 * @param File: Um ponteiro para um objeto FILE.
 * @return A função retorna o descritor de arquivo associado ao ponteiro FILE.
 * Se o ponteiro FILE não for válido ou se ocorrer um erro, a função retorna -1 e pode
 * definir a variável errno para indicar o erro.
 *
 * @note A função fileno() pode ser usada para obter o descritor de arquivo de um
 * ponteiro para um objeto FILE, que pode ser usado em chamadas de sistema de baixo
 * nível.
 */

int main(int argc, char **argv)
{
    FILE *arquivo = fopen("dados.bin", "rb");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 1;
    }

    // Obtém descritor do arquivo e retorna o identificador de arquivo que o
    // sistema operacional usa internamente.
    int descritor = fileno(arquivo);
    printf("Descritor do arquivo: %d\n", descritor);

    fclose(arquivo);
    return 0;
}
