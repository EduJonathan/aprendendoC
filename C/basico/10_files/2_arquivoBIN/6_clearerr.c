#include <stdio.h>

/**
 * clearerr(): limpa os indicadores de erro e de fim de arquivo de um fluxo de arquivo.
 * Isso é útil quando você deseja tentar novamente uma operação de I/O após lidar com um
 * erro ou após o fim do arquivo ter sido alcançado.
 *
 * SINTAXE: void clearerr(FILE *File);
 *
 * @param File: Um ponteiro para um objeto FILE.
 *
 * @note A função clearerr() pode ser usada para limpar os indicadores de erro e de fim
 * de arquivo de um fluxo de arquivo.
 */

int main(int argc, char **argv)
{
    FILE *arquivo = fopen("dados.bin", "rb");

    fgetc(arquivo); // Simula uma leitura
    if (ferror(arquivo))
    {
        printf("Erro encontrado!\n");
    }

    // Limpa erros do fluxo e remove erros associados ao fluxo do arquivo para
    // evitar problemas futuros.
    clearerr(arquivo);
    if (!ferror(arquivo))
    {
        printf("Erro removido!\n");
    }

    fclose(arquivo);
    return 0;
}
