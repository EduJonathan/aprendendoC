#include <stdio.h>

/**
 * ferror(): Verifica se ocorreu um erro na última operação de I/O associada ao arquivo.
 * Especialmente útil para depurar problemas ao ler ou escrever em arquivos, pois permite
 * identificar se uma operação falhou e obter informações sobre o tipo de erro que ocorreu.
 *
 * SINTAXE: int feof(FILE *_File);
 *
 * @param _File: Um ponteiro para um objeto FILE que representa o arquivo para o qual
 * você deseja verificar se ocorreu um erro.
 * @return A função retorna um valor diferente de 0 se ocorreu um erro durante a última
 * operação de I/O. Se não houve erro, a função retorna 0.
 *
 * @note A função ferror() é especialmente útil para depurar problemas ao ler ou escrever
 * em arquivos, pois permite identificar se uma operação falhou e obter informações sobre
 * o tipo de erro que ocorreu.
 */

int main(int argc, char **argv)
{
    FILE *arquivo = fopen("dados.bin", "rb"); // Tenta abrir arquivo para leitura

    /* verifica se houve erro ao abrir ou acessar o arquivo. */
    if (!arquivo || ferror(arquivo))
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fclose(arquivo);
    printf("Arquivo lido com sucesso!\n");
    return 0;
}
