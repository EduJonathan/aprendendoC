#include <stdio.h>

/**
 * @brief Função para converter letras minúsculas para maiúsculas em um arquivo
 *
 * @param file - ponteiro para o arquivo a ser processado
 * @return Retorna 0 em caso de sucesso, 1 em caso de erro
 * @note A função toUpperFile() pode ser usada para converter letras minúsculas para maiúsculas
 * em um arquivo
 */
int toUpperFile(FILE *file)
{
    // Verifica se o ponteiro do arquivo é nulo
    if (file == NULL)
    {
        perror("ERRO: arquivo não aberto");
        return 1;
    }
    else
    {
        int caracteres = 0; // Variável para armazenar os caracteres do arquivo

        // Loop para ler e processar cada caractere do arquivo
        while ((caracteres = fgetc(file)) != EOF)
        {
            // Se o caractere estiver entre 'a' e 'z', converte para maiúscula
            if ((caracteres >= 'a') && (caracteres <= 'z'))
            {
                caracteres = caracteres - 32; // Converte para maiúscula
                fseek(file, -1, SEEK_CUR);    // Move o ponteiro de arquivo de volta uma posição
                fputc(caracteres, file);      // Escreve o caractere convertido de volta no arquivo
            }
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    FILE *file = NULL;

    // Verifica se nenhum argumento foi fornecido na linha de comando
    if (argc == 1)
    {
        printf("Argumentos não foram suficientes.\n");
        return 1;
    }
    else if (argc > 1)
    {
        // Abre o arquivo especificado na linha de comando para leitura e escrita
        file = fopen("teste.txt", "r+");

        // Verifica se houve erro ao abrir o arquivo
        if (file == NULL)
        {
            perror("Erro ao abrir arquivo");
            return 1;
        }

        // Chama a função para converter letras minúsculas para maiúsculas no arquivo
        int status = toUpperFile(file);

        // Verifica se a conversão foi bem sucedida
        if (status == 0)
        {
            printf("%s: Conteúdo do arquivo foi convertido com sucesso.\n", argv[1]);
        }
        else
        {
            printf("Falha na conversão.\n");
        }

        // Fecha o arquivo após o processamento
        fclose(file);
    }

    return 0;
}
