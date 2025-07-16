#include <stdio.h>
#include <string.h>

/**
 * fseek(): Ajusta a posição de leitura/escrita em um arquivo aberto. Isso é feito movendo
 * o cursor para uma nova posição, especificada em bytes a partir de um local base.
 *
 * SINTAXE: int fseek(FILE *_File, long _Offset, int _Origin);
 *
 * @param _File: Ponteiro para um objeto FILE que identifica o arquivo em que a operação
 * será realizada.
 * @param _Offset: Quantidade de bytes a ser movida a partir do local base especificado por
 * whence(ponto de referência para o deslocamento, que pode ter um dos seguintes valores).
 * SEEK_SET: A posição é relativa ao início do arquivo.
 * SEEK_CUR: A posição é relativa à posição atual do cursor no arquivo.
 * SEEK_END: A posição é relativa ao final do arquivo.
 * Podendo ser valor positivo ou negativo.
 * @param _Origin: O número de elementos a serem lidos.
 * @return Retorno: retorna 0 se a operação for bem-sucedida. Caso contrário,
 * retorna um valor diferente de 0 e define a variável errno para indicar o erro.
 *
 * @note fseek é bastante útil quando você precisa manipular a posição do cursor de
 * forma mais flexível ao trabalhar com arquivos.
 */

int main(int argc, char **argv)
{
    // Abre o arquivo para escrita
    FILE *arquivo = fopen("fseek", "w");

    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        return 1; // Encerra o programa com código de erro 1
    }

    char caracteres = '\0';
    printf("Digite algo (CTRL+c para encerrar): ");

    // Lê caracteres do teclado até EOF e escreve no arquivo
    while ((caracteres = getchar()) != EOF)
    {
        putc(caracteres, arquivo);
    }

    // Fecha o arquivo após a escrita
    fclose(arquivo);

    // Reabre o arquivo para leitura
    arquivo = fopen("fseek", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return 1; // Encerra o programa com código de erro 1
    }

    long n = 0L;
    int ch = 0;

    // Lê o arquivo do início até o final, movendo-se para cada byte
    while (fseek(arquivo, n, SEEK_SET) == 0 && !feof(arquivo))
    {
        // Lê um caractere do arquivo
        ch = fgetc(arquivo);
        if (ch == EOF)
        {
            // Encerra o loop se EOF for encontrado
            break;
        }

        // Exibe o caractere lido e sua posição atual
        printf("\n%3c - %2ld", ch, ftell(arquivo) - 1);

        // Incrementa a posição para o próximo caractere
        n++;
    }

    // Volta o cursor para o início do arquivo
    rewind(arquivo);
    printf("\nString: ");

    // Lê e imprime o conteúdo do arquivo até EOF
    while ((caracteres = fgetc(arquivo)) != EOF)
    {
        printf("%c", caracteres);
    }

    // Fecha o arquivo após a leitura
    fclose(arquivo);
    return 0;
}
