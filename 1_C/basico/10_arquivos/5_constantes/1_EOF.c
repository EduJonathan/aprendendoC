#include <stdio.h>

/**
 * EOF: Ou End Of File macro definida na biblioteca padrão de C (<stdio.h>). Essa constante
 * é usada para indicar o fim de um arquivo quando a leitura ou escrita atinge o final.
 * O valor de EOF é geralmente -1.
 */

int main(int argc, char **argv)
{
    FILE *file = NULL;
    char ch = '\0';

    file = fopen("file.txt", "w");
    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Entre com o valor a ser armazenado no arquivo: ");

    while ((ch = getchar()) != EOF)
    {
        putc(ch, file);
        /* CRTL + C no terminal para encerrar a execução do programa. */
    }

    fclose(file);
    return 0;
}
