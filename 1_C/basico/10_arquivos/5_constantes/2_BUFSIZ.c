#include <stdio.h>

/**
 * BUFSIZ: É uma constante definida na biblioteca padrão . Ela representa o tamanho do buffer
 * utilizado pelas funções de entrada e saída (I/O), como fopen, fwrite, fread, entre outras.
 * O valor de BUFSIZ pode variar dependendo do sistema operacional e implementação do compilador,
 * mas geralmente é algo em torno de 512 ou 8192 bytes. O uso do buffer melhora o desempenho
 * da leitura e escrita de arquivos, reduzindo a quantidade de chamadas ao sistema para acessar
 * o disco. No entanto, se for necessário um tamanho de buffer específico, o programador pode
 * definir manualmente um buffer adequado em sua aplicação.
 */

int main(int argc, char **argv)
{
    printf("BUFSIZ: %d\n", BUFSIZ);

    if (argc != 3)
    {
        printf("Uso: %s <arquivo_origem> <arquivo_destino>\n", argv[0]);
        return 1;
    }

    FILE *origem = fopen(argv[1], "rb");
    FILE *destino = fopen(argv[2], "wb");

    if (!origem || !destino)
    {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    char buffer[BUFSIZ] = {0}; // Buffer para leitura e escrita de dados
    size_t bytesLidos = 0ull;
    while ((bytesLidos = fread(buffer, 1, BUFSIZ, origem)) > 0)
    {
        fwrite(buffer, 1, bytesLidos, destino);
    }

    fclose(origem);
    fclose(destino);

    printf("Arquivo copiado com sucesso!\n");
    return 0;
}
