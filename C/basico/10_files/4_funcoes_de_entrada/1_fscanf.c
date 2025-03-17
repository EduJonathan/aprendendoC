#include <stdio.h>

/**
 * fscanf(): Função para ler dados formatados de um arquivo
 *
 * SINTAXE: int fscanf(FILE *__restrict__ _File, const char *__restrict__ _Format, ...);
 *
 * @param _File Ponteiro para um arquivo
 * @param _Format Para os formatadores
 * @param ... Variáveis para leitura
 * @return A funcao retorna o numero de elementos efetivamente lidos.
 * 
 * @note A funcao fscanf() pode ser usada para ler dados formatados de um arquivo.
 */

int main(int argc, char **argv)
{
    // Criando e abrindo o arquivo em modo de leitura
    FILE *arq = NULL;
    arq = fopen("fscanf.txt", "w");

    // Verificando se o arquivo será aberto
    if (arq == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura.\n");
        return 1; // Encerrar o programa com código de erro
    }

    // Variáveis para utilizar na função fscanf
    int intValue;
    float floatValue;
    char stringValue[50];

    // Ler dados formatados do arquivo
    int result = fscanf(arq, "%d %f %s", &intValue, &floatValue, stringValue);

    if (result == 3)
    {
        // A leitura foi bem-sucedida
        printf("Valores lidos: %d, %.2f, %s\n", intValue, floatValue, stringValue);
    }
    else
    {
        // A leitura falhou
        printf("Erro ao ler dados do arquivo.\n");
    }

    // Fechar o arquivo
    fclose(arq);
    return 0;
}
