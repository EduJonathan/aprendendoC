#include <stdio.h>

/**
 * fprintf(): Função para escrever dados formatados em um arquivo.
 *
 * SINTAXE: int fprintf(FILE *__stream, const char *__format, ...)
 *
 * @param __strem: arquivo de exibição do conteúdo
 * @param __format: conteúdo a escrever no arquivo
 * @param ...: Argumentos ou parâmetros de uma variável
 * @return A funcao retorna o numero de elementos efetivamente escritos.
 * 
 * @note A função fprintf() pode ser usada para escrever dados formatados em um arquivo.
 */

int main(int argc, char **argv)
{
    // Criando o arquivo
    FILE *arq = NULL;
    arq = fopen("fprint.txt", "w");

    // Verificando se o arquivo será aberto
    const char *arqOpen = (arq == NULL) ? "ERRO AO TENTAR ABRIR O ARQUIVO\n" : "ARQUIVO ABERTO COM SUCESSO\n";
    perror(arqOpen);

    // Exibindo o conteúdo para o arquivo utilizando o fprintf
    fprintf(arq, "%d %f %s | Utilizando o fprintf!", 0, 1.1F, "Eduardo");

    // Fecha o arquivo
    fclose(arq);
    return 0;
}
