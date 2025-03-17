#include <stdio.h>

/**
 * FILE: É uma estrutura usada para representar um arquivo. A declaração do tipo FILE
 * é usada para A manipulação de arquivos em C envolve a abertura, leitura, gravação e
 * fechamento de arquivos. manipulação de arquivos. é usado para representar a conexão
 * entre o programa e um arquivo específico durante essas operações.
 */

/**
 * fopen(): Função para abrir o arquivo
 *
 * SINTAXE: FILE *fopen(const char *__restrict__ _Filename, const char *__restrict__ _Mode)
 * @param _Filename: nome do arquivo
 * @param _Mode: modo de abertura do arquivo
 * @return A função retorna um ponteiro para o arquivo aberto, ou NULL se houver um erro.
 * Se o arquivo for aberto com sucesso, a função retorna um ponteiro para o arquivo aberto.
 * Se houver um erro ao abrir o arquivo, a função retorna NULL.
 */

int main(int argc, char **argv)
{
    // Criando o ponteiro que irá criar o arquivo
    FILE *file = NULL;

    // Abre arquivo para escrita
    file = fopen("exemplo.txt", "w"); // Arquivo sem o caminho especificado

    /**
     * Arquivo com o caminho especificado(Windows)
     * file = fopen("C:\Users\EDUARDO\Documents\aprendendoC\C\basico\10_files\1_arquivoTXT\1_file.c", "w");
     *
     * No linux, seria: file = fopen("./home/Eduardo/Documents/files/arq.py", "w");
     */

    // Verifica se o arquivo não foi aberto com sucesso
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo\n");
        /**
         * PERROR: imprime uma mensagem de erro padrão do sistema caso haja falha na
         * abertura do arquivo. Fornece detalhes adicionais sobre o motivo pelo qual o
         * arquivo não pôde ser aberto.
         */
        return 1;
    }

    // Escrever no arquivo
    fprintf(file, "Hello, File!\n");

    // Fechar o arquivo
    fclose(file);

    // Abrir arquivo para leitura
    file = fopen("exemplo.txt", "r");

    // Verifica se o arquivo irá abrir sem erro
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    // Para que possamos escrever no arquivo
    char buffer[100];

    // Ler do arquivo
    fgets(buffer, sizeof(buffer), file);
    printf("Conteúdo do arquivo : %s", buffer);

    // Fechar o arquivo
    fclose(file);
    return 0;
}
