#include <stdio.h>

/**
 * stdin (Standard Input) e stdout (Standard Output): São fluxos fundamentais em C e outras
 * linguagens, permitindo interação com o usuário e manipulação de dados.
 *
 * STDIN: Usado para receber entrada do usuário (exemplo: teclado). Normalmente utilizado
 * com funções como scanf(), fgets(), getchar().
 *
 * STDOUT: Usado para exibir dados na tela (ou redirecionar para um arquivo).
 * Comumente utilizado com printf(), puts(), e putchar().
 */

int main(int argc, char **argv)
{
    char nome[50];

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin); // Lê entrada do usuário
    printf("Olá, %s", nome);          // Exibe saída na tela

    // Usando stdout para imprimir uma mensagem
    printf("Olá, Mundo!\n");

    // Também podemos usar fputs com stdout diretamente
    fputs("Esse é outro exemplo com fputs.\n", stdout);

    return 0;
}
