#include <stdio.h>
// stander input/output de extensão .h, arquivo que fornece funções para entrada e saída de dados

int main(int argc, char **argv)
{
    // printf(print formatted): Função de saída de texto e dados.
    printf("OLÁ! ");

    printf("este é minha 1º linha de código, meu nome é eduardo e estou programando em C\n");
    // Os dois primeiros printf irão ter uma saída que ocorrerá na mesma linha do
    // terminal, o '\n' é um caractere especial ou caractere de escape que realiza ação
    // de quebra de linha, significa que a próxima função de saída de texto não esteja
    // na mesma linha que as duas primeiras linhas estavam.

    // E por último, temos o puts(put string ou insere string). Seu limite é apenas
    // apresentar textos e também caracteres especiais como '\n' e outros.
    // Para formatação, ele não é tão versátil quanto o printf.
    puts("Texto inserido pela função puts");
    puts("\nHELLO WORLD!");

    /**
     * OUTPUT:
     * OLÁ! este é minha 1º linha de código, meu nome é eduardo e estou programando em C
     * Texto inserido pela função puts
     *
     * HELLO WORLD!
     */
    return 0;
}
