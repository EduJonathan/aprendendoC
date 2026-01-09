#include <stdio.h>

/**
 * FILE: A estrutura 'FILE' é um tipo especial usado para representar um arquivo.
 * Ela é definida na biblioteca padrão `stdio.h` e é usada para manipular arquivos,
 * permitindo que o programa realize operações como abertura, leitura, gravação
 * e fechamento de arquivos.
 *
 * @note A declaração do tipo 'FILE' não cria o arquivo, mas sim representa a conexão
 * entre o programa e um arquivo específico durante as operações de manipulação.
 * **IMPORTANTE**: Após a manipulação do arquivo, sempre use `fclose()` para garantir
 * que os dados sejam corretamente salvos e os recursos sejam liberados.
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
     * file = fopen("C:\Users\nomeUser\Documents\aprendendoC\1_C\basico\10_files\1_arquivoTXT>"", "w");
     *
     * No linux, seria: file = fopen("/home/usuario/Documents/aprendendoC/C/basico/10_files/1_arquivoTXT/1_file.c", "w");
     *
     * O caminho do arquivo pode ser absoluto ou relativo. Um caminho absoluto especifica
     * a localização completa do arquivo no sistema de arquivos, enquanto um caminho relativo
     * é baseado na localização atual do diretório de trabalho do programa.
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
    char buffer[100] = {0}; // Buffer para armazenar o conteúdo lido

    // Ler do arquivo
    fgets(buffer, sizeof(buffer), file);
    printf("Conteúdo do arquivo : %s", buffer);

    // Fechar o arquivo
    fclose(file);
    return 0;
}
