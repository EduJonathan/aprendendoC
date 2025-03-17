#include <stdio.h>

/**
 * remove(): É usada para excluir um arquivo do sistema de arquivos.
 *
 * SINTAXE: int remove(const char *_Filename);
 *
 * @param Filename nome do arquivo que deseja remver
 * @return A função retorna 0 se o arquivo for excluído com sucesso, ou -1 se o
 * arquivo não existir.
 * Se o arquivo for excluído com sucesso, a função retorna 0.
 * Se o arquivo nao existir, a função retorna -1.
 */

int main(int argc, char **argv)
{
    // nome do arquivo
    const char *nome = "remove.txt";

    // tenta abrir o arquivo para escrita
    FILE *file = fopen(nome, "w");

    // Se *file não for NULL, Verificando se arquivo foi aberto
    if (file)
    {
        printf("\nArquivo aberto com sucesso!\n");
        fclose(file);

        // tenta remover o arquivo remove.txt
        printf("\nRetorno: %d\n", remove(nome));
    }
    else
    {
        printf("\nErro ao abrir o arquivo!\n");

        // Ao tentar remover um arquivo que não existe a função retorna o valor -1
        printf("\nRetorno: %d\n", remove(nome));
    }
    return 0;
}
