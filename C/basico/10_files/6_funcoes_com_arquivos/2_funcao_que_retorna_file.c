#include <stdio.h>

/**
 * @brief Abre um arquivo com o nome especificado no modo especificado.
 *
 * Esta função tenta abrir um arquivo com o nome especificado no modo especificado.
 * Se a operação for bem-sucedida, retorna um ponteiro para o arquivo aberto.
 * Se houver um erro ao abrir o arquivo, imprime uma mensagem de erro e retorna NULL.
 *
 * @param filename Nome do arquivo a ser aberto.
 * @param mode Modo de abertura do arquivo (por exemplo, "r", "w", "a").
 * @return FILE* Ponteiro para o arquivo aberto, ou NULL se houver um erro.
 * @note Esta função utiliza a biblioteca stdio.h para abrir e manipular arquivos.
 * @note A função openFile() pode ser usada para abrir e manipular arquivos.
 */
FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);

    if (file == NULL)
    {
        perror("Erro ao abrir arquivo");
        return NULL; // Retorna NULL em caso de erro
    }

    // Retorna o ponteiro para o arquivo aberto
    return file;
}

int main(int argc, char **argv)
{
    const char *filename = "exemplo.txt"; // Nome do arquivo
    const char *mode = "w";               // Modo de abertura: escrita (cria arquivo se não existir)

    // Chamada da função para abrir o arquivo
    FILE *file = openFile(filename, mode);

    if (file != NULL)
    {
        // Arquivo aberto com sucesso, pode ser utilizado aqui
        fprintf(file, "Este é um exemplo de texto no arquivo.\n");
        fprintf(file, "Segunda linha de texto.\n");

        // Fechar o arquivo após o uso
        fclose(file);
        printf("Arquivo criado e escrito com sucesso.\n");
    }
    else
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    return 0;
}
