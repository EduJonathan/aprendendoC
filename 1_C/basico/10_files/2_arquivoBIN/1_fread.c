#include <stdio.h>

/**
 * fread(): É utilizada para ler dados de um arquivo aberto.
 *
 * SINTAXE:
 * size_t fread(void *__restrict__ _DstBuf, size_t _ElementSize, size_t _Count, FILE *__restrict__ _File);
 *
 * @param _DstBuf: Um ponteiro para o buffer onde os dados lidos serão armazenados.
 * @param _ElementSize: O tamanho, em bytes, de cada elemento a ser lido.
 * @param _Count: O número de elementos a serem lidos.
 * @param _File: Um ponteiro para o arquivo de onde os dados serão lidos
 * @return Retorno: A função retorna o número de elementos efetivamente lidos. Esse valor
 * pode ser menor do que _Count se ocorrer um erro ou se o fim do arquivo for alcançado.
 *
 * @note A funcao fread() pode ser usada para ler os dados de um arquivo binario.
 */

int main(int argc, char **argv)
{
    // Criando e abrindo o arquivo
    FILE *arquivo = NULL;
    arquivo = fopen("numeros.bin", "rb");

    // Verificando o arquivo
    if (arquivo == NULL)
    {
        perror("Erro");
        return 1;
    }

    // Lendo os 10 números inteiros do arquivo
    int numero[10] = {0};
    size_t nElementos = sizeof(numero) / sizeof(numero[0]);
    size_t numerosLidos = fread(numero, sizeof(int), nElementos, arquivo);

    // Verificando se todos os números foram lidos com sucesso
    if (numerosLidos != 10)
    {
        printf("Erro ao ler os dados do arquivo\n");
        return 1;
    }

    // Imprimindo os numeros
    for (int i = 0; i < nElementos; i++)
    {
        printf("%d ", numero[i]);
    }

    printf("\n");

    // Fechando o arquivo
    fclose(arquivo);
    return 0;
}
